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
    
    // MARK: - Alert States
    @Published public var showIntroductionAlert = false {
        didSet {
            if showIntroductionAlert {
                pauseScanning()
            } else {
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
    var timer: Timer?
    private var lastReticleStateChange: TimeInterval = Date().timeIntervalSince1970
    
    let showDemoOverlayImage: Bool
    let showProductionOverlayImage: Bool
    
    /// Initializes a new scanning UX model with the specified document analyzer.
    /// - Parameter analyzer: The analyzer responsible for processing camera frames and detecting documents.
    /// - Parameter shouldShowIntroductionAlert: Whether introduction alert will be shown on appear
    public init(analyzer: any CameraFrameAnalyzer<CameraFrame, UIEvent>, shouldShowIntroductionAlert: Bool = false) {
        self.analyzer = analyzer
        self.shouldShowIntroductionAlert = shouldShowIntroductionAlert
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
        startTooltipTimer()
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
    
    func calculateRemainingTime() -> Double {
        let currentTime = Date().timeIntervalSince1970
        let elapsedTime = currentTime - lastReticleStateChange
        return reticleState.duration - elapsedTime
    }
    
    func setReticleState(_ state: ReticleState, force: Bool = false) {
        let currentTime = Date().timeIntervalSince1970
        guard (currentTime - lastReticleStateChange >= self.reticleState.duration) || force else { return }
        
        timer?.invalidate()
        
        lastReticleStateChange = currentTime
        reticleState = state
        
        if state.shouldExpire {
            timer = Timer.scheduledTimer(withTimeInterval: state.duration, repeats: false) { [weak self] _ in
                Task {
                    await self?.setReticleState(.detecting)
                }
            }
        }
    }
    
    // MARK: - Tooltip Management
    
    func startTooltipTimer() {
        showTooltipTimer?.invalidate()
        showTooltip = false
        showTooltipTimer = Timer.scheduledTimer(timeInterval: 8.0, target: self, selector: #selector(showTooltipInvoked), userInfo: nil, repeats: false)
        RunLoop.current.add(showTooltipTimer!, forMode: .common)
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
        hideTooltipTimer = Timer.scheduledTimer(timeInterval: 3.0, target: self, selector: #selector(hideTooltipInvoked), userInfo: nil, repeats: false)
        RunLoop.current.add(hideTooltipTimer!, forMode: .common)
    }
    
    @objc private func hideTooltipInvoked() {
        showTooltip = false
    }
}
