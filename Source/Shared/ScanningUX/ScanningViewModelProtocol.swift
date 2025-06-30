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
#endif

@MainActor
/// Protocol defining the core functionality required for document scanning view models
protocol ScanningViewModelProtocol: ObservableObject {
    
    associatedtype ScanResult
    associatedtype AlertType
    
    /// The result of the document scanning process
    var scanningResult: ScanResult? { get set }
    
    var alertType: AlertType? { get set }
    
    /// Region of interest for document detection
    var roi: RegionOfInterest { get set }
    
    /// Camera instance for handling video capture
    var camera: Camera { get }
    
    /// Frame analyzer for processing camera input
    var analyzer: any CameraFrameAnalyzer<CameraFrame, UIEvent> { get }
    
    /// Current scanning state
    var reticleState: ReticleState { get set }
    
    /// Methods that must be implemented
    func analyze() async
    func processAnalyzerResult() async
    func pauseScanning()
    func resumeScanning()
    func restartScanning()
    func scanningDidCancel()
    func licenseErrorAlertDismised()
    func presentAlert()
    func dismissAlert()
    func stopEventHandling()
}

/// Base class containing common scanning functionality
@MainActor
public class ScanningViewModel<T, U>: ObservableObject, ScanningViewModelProtocol {
        
    // - MARK: Core properties
    @Published public var scanningResult: T?
    @Published public var alertType: U?
    @Published public var roi: RegionOfInterest = RegionOfInterest()
    @Published public var reticleState: ReticleState = .front
    
    let camera: Camera = Camera()
    let analyzer: any CameraFrameAnalyzer<CameraFrame, UIEvent>
    
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
    
    // Introduction alert
    let shouldShowIntroductionAlert: Bool
    
    // Onboarding sheet
    let showHelpButton: Bool
    
    // MARK: - Alert States
    @Published public var showIntroductionAlert = false {
        didSet {
            if showIntroductionAlert {
                pauseScanning()
            } else {
                setReticleState(.front, force: true)
                UIAccessibility.post(notification: .screenChanged, argument: ReticleState.front.text)
                resumeScanning()
            }
        }
    }
    
    @Published var showScanningAlert: Bool = false {
        didSet {
            if showScanningAlert {
                pauseScanning()
            }
            else {
                timeoutAlertDismised()
            }
        }
    }
    
    // License error alert
    @Published var showLicenseErrorAlert: Bool = false {
        didSet {
            if showLicenseErrorAlert {
                pauseScanning()
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
    @Published var cardImage = Image.frontIdImage
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
    private var lastReticleStateChange: TimeInterval = Date().timeIntervalSince1970
    private var eventCounter: [ReticleState: Int] = [:]
    private var reticleStateIsInterruptible = false
    private var lastPassportErrorOrientation: PassportOrientation = .none
    var inactiveState: ReticleState = .front
    
    let stateCountingDuration: TimeInterval = 1.5
    
    let showDemoOverlayImage: Bool
    let showProductionOverlayImage: Bool
    
    /// Initializes a new scanning UX model with the specified document analyzer.
    /// - Parameter analyzer: The analyzer responsible for processing camera frames and detecting documents.
    /// - Parameter shouldShowIntroductionAlert: Whether introduction alert will be shown on appear
    public init(analyzer: any CameraFrameAnalyzer<CameraFrame, UIEvent>, shouldShowIntroductionAlert: Bool = false, showHelpButton: Bool = false) {
        self.analyzer = analyzer
        self.shouldShowIntroductionAlert = shouldShowIntroductionAlert
        self.showHelpButton = showHelpButton
        self.showDemoOverlayImage = UXLicenseProviderBridge.shared.showDemoOverlay
        self.showProductionOverlayImage = UXLicenseProviderBridge.shared.showProductionOverlay
    }
    
    deinit {
        hideTooltipTimer?.invalidate()
    }
    
    // - MARK: - Protocol Implementation
    
    public func analyze() async {
        fatalError("analyze() must be implemented by subclasses")
    }
    
    public func processAnalyzerResult() async {
        fatalError("awaitAnalyzerResult() must be implemented by subclasses")
    }
    
    public func licenseErrorAlertDismised() {
        fatalError("licenseErrorAlertDismised() must be implemented by subclasses")
    }
    
    public func timeoutAlertDismised() {
        fatalError("timeoutAlertDismised() must be implemented by subclasses")
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
    }
    
    public func pauseScanning() {
        Task {
            await analyzer.pause()
        }
    }
    
    public func resumeScanning() {
        startTooltipTimer()
        Task {
            await analyzer.resume()
            await camera.start()
        }
    }
    
    public func restartScanning() {
        Task {
            try await analyzer.restart()
            setReticleState(.front, force: true)
            await camera.start()
        }
    }
    
    public func scanningDidCancel() {
         scanningResult = nil
    }
    
    // MARK: - Common Methods
    
    func closeButtonTapped() {
        fatalError("closeButtonTapped() must be implemented by subclasses")
    }
    
    func helpButtonTapped() {
        pauseScanning()
        showSheet.toggle()
    }
    
    func calculateRemainingTime(stateDuration: Double? = nil) -> Double {
        let currentTime = Date().timeIntervalSince1970
        let elapsedTime = currentTime - lastReticleStateChange
        
        if reticleStateIsInterruptible,
           let stateDuration = stateDuration {
            return stateDuration - elapsedTime
        } else {
            return reticleState.duration - elapsedTime
        }
        
    }
    
    func setReticleState(_ state: ReticleState, force: Bool = false) {
        let currentTime = Date().timeIntervalSince1970
        
        let timeLeft = calculateRemainingTime()
        guard timeLeft < 0 || force else {
            if timeLeft <= stateCountingDuration {
                eventCounter[state, default: 0] += 1
            }
            return
        }
        
        let newState: ReticleState
        
        if !force,
           let (mostFrequentState, _) = eventCounter.max(by: { $0.value < $1.value }) {
            
            if mostFrequentState == .error("mb_scanning_wrong_page_top") {
                lastPassportErrorOrientation = .none
            } else if mostFrequentState == .error("mb_scanning_wrong_page_left") {
                lastPassportErrorOrientation = .left90
            } else if mostFrequentState == .error("mb_scanning_wrong_page_right") {
                lastPassportErrorOrientation = .right90
            }
            
            if case .passport(_) = mostFrequentState {
                switch lastPassportErrorOrientation {
                case .none:
                    newState = .passport("mb_top_page_instructions".localizedString)
                case .left90:
                    newState = .passport("mb_left_page_instructions".localizedString)
                case .right90:
                    newState = .passport("mb_right_page_instructions".localizedString)
                }
            } else {
                newState = mostFrequentState
            }
        } else {
            newState = state
        }
        
        reticleState = newState
        reticleStateIsInterruptible = !force
        
        switch reticleState {
        case .front, .back, .barcode, .passport(_), .inactiveWithMessage(_):
            inactiveState = reticleState
        case .flip, .inactive, .error(_), .detecting:
            break
        }
        
        lastReticleStateChange = currentTime
        eventCounter.removeAll()
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
                showTooltipTimer = Timer.scheduledTimer(timeInterval: interval, target: self, selector: #selector(showTooltipInvoked), userInfo: nil, repeats: false)
                RunLoop.current.add(showTooltipTimer!, forMode: .common)
            }
        }
        
    }
    
    @MainActor
    @objc private func showTooltipInvoked() {
        showTooltip = true
    }
    
    /// Cancels the tooltip timer and hides the tooltip
    func cancelTooltipTimer() {
        showTooltipTimer?.invalidate()
        showTooltipTimer = nil
        showTooltip = false
    }
    
    private func startHideTooltipTimer() {
        hideTooltipTimer = Timer.scheduledTimer(timeInterval: 5.0, target: self, selector: #selector(hideTooltipInvoked), userInfo: nil, repeats: false)
        RunLoop.current.add(hideTooltipTimer!, forMode: .common)
    }
    
    @objc private func hideTooltipInvoked() {
        showTooltip = false
    }
}
