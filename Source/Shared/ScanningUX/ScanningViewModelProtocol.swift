//
//  ScanningUXViewModelProtocol.swift
//  DocumentVerificationUX
//
//  Created by Jura Skrlec on 19.02.2025..
//

import AVFoundation
import Foundation
import CoreImage
import SwiftUI
import Combine

#if canImport(BlinkIDVerify)
import BlinkIDVerify
#elseif canImport(BlinkID)
import BlinkID
#elseif canImport(BlinkCard)
import BlinkCard
#endif

@MainActor
/// Protocol defining the core functionality required for document scanning view models
protocol ScanningViewModelProtocol: ObservableObject {
    
    associatedtype ScanResult
    associatedtype EventType
    associatedtype ReticleStateMachineType: ReticleStateMachineProtocol
    associatedtype AlertType: AlertTypeProtocol
    
    /// The result of the document scanning process
    var scanningResult: ScanResult? { get set }
    
    var alertType: AlertType? { get set }
    
    /// Region of interest for document detection
    var roi: RegionOfInterest { get set }
    
    /// Camera instance for handling video capture
    var camera: Camera { get }
    
    /// Frame analyzer for processing camera input
    var analyzer: any CameraFrameAnalyzer<CameraFrame, EventType> { get }
    
    /// Current scanning state
    var reticleStateMachine: ReticleStateMachineType { get }
    
    /// Methods that must be implemented
    func analyze() async
    func processAnalyzerResult() async
    func pauseScanning()
    func resumeScanning()
    func restartScanning()
    func licenseErrorAlertDismised()
    func presentAlert()
    func dismissAlert()
    func stopEventHandling()
}

/// Base class containing common scanning functionality
@MainActor
public class ScanningViewModel<T, U, V: ReticleStateMachineProtocol, A: AlertTypeProtocol>: ObservableObject, ScanningViewModelProtocol {
    // - MARK: Core properties
    @Published public var scanningResult: T?
    @Published public var roi: RegionOfInterest = RegionOfInterest()
    public let reticleStateMachine: V
    
    let camera: Camera = Camera()
    let analyzer: any CameraFrameAnalyzer<CameraFrame, U>
    let sessionNumber: Int
    let uxSettings: ScanningUXSettings
    var currentErrorMessage: UxEventPinglet.ErrorMessageType?
    let firstSideFinishedText: String
    let scanFinishedText: String
    
    // MARK: - UI Elements
    // Cancel button
    let cancelImage = Image(systemName: "xmark")
    let cancelLabel = "Cancel"
    let cancelHint = "Cancel scanning procedure"
    
    // Torch button
    @Published var torchImage = Image(systemName: "bolt.slash.fill")
    let torchLabel = "Torch"
    @Published var torchHint = "Turn flashlight on"
    
    @Published public var isTorchOn: Bool = false {
        didSet {
            if uxSettings.allowHapticFeedback {
                UISelectionFeedbackGenerator().selectionChanged()
            }
            camera.isTorchEnabled = isTorchOn
            torchImage = isTorchOn ? Image(systemName: "bolt.fill") : Image(systemName: "bolt.slash.fill")
            torchHint = isTorchOn ? "Turn flashlight on" : "Turn flashlight off"
            if isTorchOn && !isToastVisible {
                isToastVisible = true
            }
        }
    }
    
    @Published public var isToastVisible: Bool = false
    
    // Help button
    let helpImage = Image(systemName: "questionmark.circle.fill")
    let helpLabel = "Help"
    let helpHint = "Open scanning onboarding help"
    @Published var showSheet = false
    
    // MARK: - Alert States
    @Published public var showIntroductionAlert = false {
        didSet {
            if showIntroductionAlert {
                Task {
                    if sessionNumber > 0 {
                        let uxEventPinglet = UxEventPinglet(eventType: .onboardinginfodisplayed)
                        await PingManager.shared.addPinglet(pinglet: uxEventPinglet, sessionNumber: sessionNumber)
                    }

                }

            } else {
                reticleStateMachine.setInitialState()
                startScanning()
            }
        }
    }
    
    @Published public var alertType: A? = nil {
        didSet {
            guard let alertType else {
                timeoutAlertDismised()
                return
            }
            pauseScanning()
            Task {
                let type: UxEventPinglet.AlertType = alertType.pingletAlertType
                
                if sessionNumber > 0 {
                    let uxEventPinglet = UxEventPinglet(eventType: .alertdisplayed, alertType: type)
                    await PingManager.shared.addPinglet(pinglet: uxEventPinglet, sessionNumber: sessionNumber)
                }
            }
            if uxSettings.allowHapticFeedback {
                UINotificationFeedbackGenerator().notificationOccurred(.error)
            }
        }
    }
    
    // License error alert
    @Published var showLicenseErrorAlert: Bool = false {
        didSet {
            if showLicenseErrorAlert {
                pauseScanning()
                Task {
                    if sessionNumber > 0 {
                        let uxEventPinglet = UxEventPinglet(eventType: .alertdisplayed, alertType: .invalidlicensekey)
                        await PingManager.shared.addPinglet(pinglet: uxEventPinglet, sessionNumber: sessionNumber)
                    }

                }
                if uxSettings.allowHapticFeedback {
                    UINotificationFeedbackGenerator().notificationOccurred(.error)
                }
            } else {
                licenseErrorAlertDismised()
            }
        }
    }
    
    // MARK: - Tooltip
    @Published var showTooltip: Bool = false {
        didSet {
            if showTooltip {
                startHideTooltipTimer()
                Task {
                    if sessionNumber > 0 {
                        let uxEventPinglet = UxEventPinglet(eventType: .helptooltipdisplayed)
                        await PingManager.shared.addPinglet(pinglet: uxEventPinglet, sessionNumber: sessionNumber)
                    }

                }

            }
            else {
                hideTooltipTimer?.invalidate()
            }
        }
    }
    private var hideTooltipTimer: Timer?
    private var showTooltipTimer: Timer?
    
    // MARK: - Animation Properties
    @Published var showCardImage: Bool = false
    @Published var cardImage: Image?
    @Published var flipCardDegrees: Double = 180.0
    @Published var flipCardScale: Double = 1.0
    let flipCardDuration = 1.0
    
    @Published var showSuccessImage: Bool = false
    @Published var successImage = Image.checkmarkImage
    @Published var successImageScale: Double = 0.0
    let successImageAnimationDuration = 0.586
    
    @Published var showRippleView: Bool = false
    @Published var rippleViewScale: Double = 0.0
    @Published var rippleViewOpacity: Double = 1.0
    let rippleViewAnimationDuration = 0.45
    
    var eventHandlingTask: Task<Void, Never>?
    
    let showDemoOverlayImage: Bool
    let showProductionOverlayImage: Bool
    
    /// Initializes a new scanning UX model with the specified document analyzer.
    /// - Parameter analyzer: The analyzer responsible for processing camera frames and detecting documents.
    /// - Parameter uxSettings: Settings used for scanning.
    /// - Parameter sessionNumber: Number of current session.
    public init(analyzer: any CameraFrameAnalyzer<CameraFrame, U>, uxSettings: ScanningUXSettings = ScanningUXSettings(), reticleStateMachine: V, firstSideFinishedText: String, scanFinishedText: String) {
        self.analyzer = analyzer
        self.uxSettings = uxSettings
        self.showDemoOverlayImage = UXLicenseProviderBridge.shared.showDemoOverlay
        self.showProductionOverlayImage = UXLicenseProviderBridge.shared.showProductionOverlay
        self.sessionNumber = analyzer.sessionNumber
        self.camera.preferredCamera = uxSettings.preferredCameraPosition
        self.reticleStateMachine = reticleStateMachine
        self.firstSideFinishedText = firstSideFinishedText
        self.scanFinishedText = scanFinishedText
    }
    
    deinit {
        showTooltipTimer?.invalidate()
        hideTooltipTimer?.invalidate()
    }
    
    // - MARK: - Protocol Implementation
    
    func analyze() async {
        
        await camera.captureService.sendCameraInputInfoPinglet(sessionNumber: sessionNumber)
        
        Task {
            await processAnalyzerResult()
        }

        for await frame in await camera.sampleBuffer {
            await analyzer.analyze(image: CameraFrame(buffer: MBSampleBufferWrapper(cmSampleBuffer: frame.buffer), roi: roi, orientation: camera.orientation.toCameraFrameVideoOrientation()))
        }
    }
    
    public func processAnalyzerResult() async {
        fatalError("awaitAnalyzerResult() must be implemented by subclasses")
    }
    
    public func licenseErrorAlertDismised() {
        Task {
            await self.analyzer.end()
        }
    }
    
    public func timeoutAlertDismised() {
        reticleStateMachine.setInitialState()
        restartScanning()
        Task {
            await self.analyze()
        }
    }
    
    public func presentAlert() {
        withAnimation {
            showIntroductionAlert = true
        }
    }
    
    public func dismissAlert() {
        withAnimation {
            showIntroductionAlert = false
        }
    }
    
    public func stopEventHandling() {
        eventHandlingTask?.cancel()
        eventHandlingTask = nil
    }
    
    public func startScanning() {
        startTooltipTimer()
        Task {
            await analyze()
        }
    }
    
    public func pauseScanning() {
        Task {
            await analyzer.pause()
        }
    }
    
    public func resumeScanning() {
        guard !showSheet && !showIntroductionAlert && !showLicenseErrorAlert && alertType == nil else {
            return
        }
        
        startTooltipTimer()
        Task {
            await analyzer.resume()
            await camera.start()
        }
    }
    
    public func restartScanning() {
        Task {
            try await analyzer.restart()
            reticleStateMachine.setInitialState()
            await camera.start()
        }
    }
    
    // MARK: - Common Methods
    
    func closeButtonTapped() {
        Task {
            if sessionNumber > 0 {
                let uxEventPinglet = UxEventPinglet(eventType: .closebuttonclicked)
                await PingManager.shared.addPinglet(pinglet: uxEventPinglet, sessionNumber: sessionNumber)
            }
            await self.analyzer.end()
        }
    }
    
    func helpButtonTapped() {
        pauseScanning()
        showSheet.toggle()
    }
    
    func setReticleState(_ state: V.ReticleStateType, force: Bool = false) {
        let stateChanged = reticleStateMachine.nextState(state: state, force: force)
        guard stateChanged else { return }

        if reticleStateMachine.reticleState.isErrorState {
            if uxSettings.allowHapticFeedback {
                UINotificationFeedbackGenerator().notificationOccurred(.warning)
            }
        }
    }
    
    // MARK: - Tooltip Management
    
    func startTooltipTimer() {
        showTooltipTimer?.invalidate()
        showTooltip = false
        
        Task {
            var interval = await analyzer.stepTimeoutDuration / 2.0
            
            if interval <= 0 {
                interval = 8.0
            }
            
            await MainActor.run {
                showTooltipTimer = Timer.scheduledTimer(withTimeInterval: interval, repeats: false, block: { [weak self] _ in
                    Task {
                        await self?.showTooltipInvoked()
                    }
                })
                RunLoop.current.add(showTooltipTimer!, forMode: .common)
            }
        }
    }
    
    @MainActor
    private func showTooltipInvoked() {
        showTooltip = true
    }
    
    /// Cancels the tooltip timer and hides the tooltip
    func cancelTooltipTimer() {
        showTooltipTimer?.invalidate()
        showTooltipTimer = nil
        showTooltip = false
    }
    
    @MainActor
    private func startHideTooltipTimer() {
        hideTooltipTimer = Timer.scheduledTimer(withTimeInterval: 5.0, repeats: false, block: { [weak self] _ in
            Task {
                await self?.hideTooltipInvoked()
            }
        })
        RunLoop.current.add(hideTooltipTimer!, forMode: .common)
    }
    
    @MainActor
    private func hideTooltipInvoked() {
        showTooltip = false
    }
    
    func trackErrorMessage(_ messageType: UxEventPinglet.ErrorMessageType) {
        Task {
            if currentErrorMessage == messageType { return }
            currentErrorMessage = messageType
            if sessionNumber <= 0 { return }
            let uxEventPinglet = UxEventPinglet(eventType: .errormessage, errorMessageType: messageType)
            await PingManager.shared.addPinglet(pinglet: uxEventPinglet, sessionNumber: sessionNumber)
        }
    }
    
    func firstSideScanned(frontFlipImage: Image, backFlipImage: Image, flipState: V.ReticleStateType, nextState: V.ReticleStateType) {
        pauseScanning()

        let remainingTime = reticleStateMachine.calculateRemainingTime(stateDuration: 1.0)

        if remainingTime > 0 {
            Timer.scheduledTimer(withTimeInterval: remainingTime, repeats: false) { [weak self] _ in
                Task {
                    await self?.animateFirstSideScanned(frontFlipImage: frontFlipImage, backFlipImage: backFlipImage, flipState: flipState, nextState: nextState)
                }
            }
        } else {
            Task {
                await animateFirstSideScanned(frontFlipImage: frontFlipImage, backFlipImage: backFlipImage, flipState: flipState, nextState: nextState)
            }
        }
    }
    
    // - MARK: Animations

    private func animateFirstSideScanned(frontFlipImage: Image, backFlipImage: Image, flipState: V.ReticleStateType, nextState: V.ReticleStateType) async {
        if uxSettings.allowHapticFeedback {
            UINotificationFeedbackGenerator().notificationOccurred(.success)
        }
        cardImage = frontFlipImage
        UIAccessibility.post(notification: .announcement, argument: firstSideFinishedText)
        showSuccessImage = true
        setReticleState(ReticleStateMachineType.ReticleStateType.inactiveState, force: true)

        withAnimation(.easeOutExpo(duration: successImageAnimationDuration)) {
            successImageScale = 1.0
        }

        try? await Task.sleep(for: .seconds(successImageAnimationDuration))

        withAnimation(.linear(duration: 0.2)) {
            showSuccessImage = false
        }

        try? await Task.sleep(for: .seconds(0.2))

        // Reset and prepare for card flip
        successImageScale = 0.0
        setReticleState(flipState, force: true)
        showCardImage = true

        withAnimation(.easeIn(duration: flipCardDuration/2)) {
            flipCardScale = 0.9
        }

        withAnimation(.easeInOut(duration: flipCardDuration)) {
            flipCardDegrees = 0.0
        }

        try? await Task.sleep(for: .seconds(flipCardDuration/2))

        cardImage = backFlipImage

        withAnimation(.easeOut(duration: flipCardDuration/2)) {
            flipCardScale = 1.0
        }

        try? await Task.sleep(for: .seconds(flipCardDuration/2 + 0.2))

        showCardImage = false
        flipCardDegrees = 180.0
        resumeScanning()
        setReticleState(nextState, force: true)
    }
    
    private func animateSuccess() async {
        if uxSettings.allowHapticFeedback {
            UINotificationFeedbackGenerator().notificationOccurred(.success)
        }
        showSuccessImage = true
        UIAccessibility.post(notification: .announcement, argument: scanFinishedText)
        self.setReticleState(ReticleStateMachineType.ReticleStateType.inactiveState, force: true)
        withAnimation(.easeOutExpo(duration: successImageAnimationDuration)) {
            successImageScale = 1.0
        }

        self.showRippleView = true
        withAnimation(.easeOut(duration: rippleViewAnimationDuration)) {
            self.rippleViewScale = 10.0
            self.rippleViewOpacity = 0.0
        }
        
        try? await Task.sleep(for: .seconds(max(successImageAnimationDuration, rippleViewAnimationDuration)))
    }
    
    /// Completes the scanning process.
    /// Stops frame analysis and triggers success animations.
    public func finishScan() async {
        pauseScanning()
        
        let remainingTime = reticleStateMachine.calculateRemainingTime(stateDuration: 1.0)
        
        currentErrorMessage = nil
        
        if remainingTime > 0 {
            try? await Task.sleep(for: .seconds(remainingTime))
            await animateSuccess()
        } else {
            await animateSuccess()
        }
    }
}
