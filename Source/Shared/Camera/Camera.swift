//
//  Camera.swift
//  DocumentVerification
//
//  Created by Jura Skrlec on 06.12.2024..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

import SwiftUI
import os.log
import AVFoundation
@preconcurrency import Combine

#if canImport(BlinkIDVerify)
import BlinkIDVerify
#elseif canImport(BlinkID)
import BlinkID
#elseif canImport(BlinkCard)
import BlinkCard
#endif

/// An object that provides the interface to the features of the camera.
public final class Camera: CameraModel {
    
    /// An enum indicating preffered camera position
    public enum CameraPosition: Equatable {
        case back
        case front
    }
    
    /// Set/get preffered camera on init
    public var preferredCamera: CameraPosition = .back {
        didSet {
            Task {
                await captureService.setPreferredCamera(preferredCamera)
            }
        }
    }
    
    /// The current status of the camera, such as unauthorized, running, or failed.
    @Published public private(set) var status = CameraStatus.unknown
    
    /// An error that indicates the details of an error during photo or movie capture.
    public private(set) var error: (any Error)?
    
    /// A Boolean value that indicates whether the camera is currently switching capture modes.
    public private(set) var isSwitchingModes = false
    
    /// An enum of current video orientation.
    public private(set) var orientation: AVCaptureVideoOrientation = .initialOrientation {
        didSet {
            guard orientation != oldValue else { return }
            
            Task {
                await sendConditionsPinglet(sessionNumber: self.sessionNumber)
            }
        }
    }
    
    /// An object that manages the app's capture functionality.
    public let captureService: CaptureService = CaptureService()
    
    /// An object that provides the connection between the capture session and the video preview layer.
    public var previewSource: any PreviewSource { captureService.previewSource }
    
    private var cancellables = Set<AnyCancellable>()
    
    /// A Boolean that indicates whether the camera supports torch.
    public private(set) var isTorchSupported: Bool = true
    
    var sessionNumber: Int = 0
    
    public init() {
        //
        Task {
            await captureService.sendCameraHardwareInfoPinglet()
        }
    }
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }
    
    // MARK: - Starting the camera
    /// Start the camera and begin the stream of data.
    public func start() async {
        // Verify that the person authorizes the app to use device cameras and microphones.
        guard await captureService.isAuthorized else {
            status = .unauthorized
            return
        }
        do {
            // Start the capture service to start the flow of data.
            try await captureService.start()
            observeState()
            createRotationCoordinator()
            status = .running
        } catch {
            logger.error("Failed to start capture service. \(error)")
            status = .failed
        }
    }
    
    // ADR 15 Camera permission check
    public func checkAuthorization(sessionNumber: Int) async {
        self.sessionNumber = sessionNumber
        let status = AVCaptureDevice.authorizationStatus(for: .video)
        let cameraInputInfoPinglet = CameraPermissionPinglet(eventType: .camerapermissioncheck, cameraPermissionGranted: status == .authorized)
        await PingManager.shared.addPinglet(pinglet: cameraInputInfoPinglet, sessionNumber: sessionNumber)
        if status == .notDetermined {
            let cameraInputInfoPingletRequestt = CameraPermissionPinglet(eventType: .camerapermissionrequest)
            await PingManager.shared.addPinglet(pinglet: cameraInputInfoPingletRequestt, sessionNumber: sessionNumber)
            let isAuthorized = await AVCaptureDevice.requestAccess(for: .video)
            let cameraInputInfoPingletResponse = CameraPermissionPinglet(eventType: .camerapermissionuserresponse, cameraPermissionGranted: isAuthorized)
            await PingManager.shared.addPinglet(pinglet: cameraInputInfoPingletResponse, sessionNumber: sessionNumber)
        }
        
        Task {
            await PingManager.shared.sendPinglets()
        }
    }
    
    public func stop() async {
        
        status = .stopped
        
        if sessionNumber > 0 {
            let uxEventPinglet = UxEventPinglet(eventType: .cameraclosed)
            await PingManager.shared.addPinglet(pinglet: uxEventPinglet, sessionNumber: sessionNumber)
        }

        // Verify that the person authorizes the app to use device cameras.
        guard await captureService.isAuthorized else {
            status = .unauthorized
            return
        }
        do {
            // Stop the capture service to stop the flow of data.
            try await captureService.stop()
            status = .stopped
            
            // ADR 15 - Camera screen closed
            Task {
                await PingManager.shared.sendPinglets()
            }
            
            
        } catch {
            logger.error("Failed to stop capture service. \(error)")
            status = .failed
        }
    }
    
    /// Performs a focus and expose operation at the specified screen point.
    public func focusAndExpose(at point: CGPoint) async {
        await captureService.focusAndExpose(at: point)
    }
    
    // MARK: - Sample buffer stream
    /// A AsyncStream of wrapped `CMSampleBuffer`
    public var sampleBuffer: AsyncStream<SampleBuffer> {
        get async {
            await captureService.sampleBufferStream
        }
    }
    
    // MARK: - Changing modes
    /// A value that indicates the mode of capture for the camera.
    var captureMode = CaptureMode.video {
        didSet {
            Task {
                isSwitchingModes = true
                defer { isSwitchingModes = false }
                // Update the configuration of the capture service for the new mode.
                try? await captureService.setCaptureMode(.video)
            }
        }
    }
    
    // MARK: - Torch
    /// A Boolean value that indicates whether camera enables torch.
    public var isTorchEnabled: Bool = false {
        didSet {
            Task {
                if sessionNumber == 0 {
                    return
                }
                await captureService.setTorchEnabled(isTorchEnabled)
                let scanningConditionsPinglet = ScanningConditionsPinglet(
                    updateType: .flashlightstate, flashlightOn: isTorchEnabled)
                await PingManager.shared.addPinglet(pinglet: scanningConditionsPinglet, sessionNumber: sessionNumber)
            }
        }
    }
    
    // MARK: - Orientation changes
    
    /// `RotationCoordinator` is only available for iOS 17, so to fallback to iOS 15, we will do it here on the main thread.
    /// `UIDevice` is on @MainActor.
    private func createRotationCoordinator() {
        // Set up orientation notification observer
        NotificationCenter.default.addObserver(
            self,
            selector: #selector(deviceOrientationChanged),
            name: UIDevice.orientationDidChangeNotification,
            object: nil
        )
        
        // Enable device orientation notifications
        UIDevice.current.beginGeneratingDeviceOrientationNotifications()
        // Set initial orientation
        updateVideoOrientation(initial: true)
    }
    
    @objc private func deviceOrientationChanged() {
        updateVideoOrientation()
    }
    
    public func stopRotationCoordinator() {
        UIDevice.current.endGeneratingDeviceOrientationNotifications()
        NotificationCenter.default.removeObserver(self)
    }
    
    private func updateVideoOrientation(initial: Bool = false) {
        if !initial {
            let deviceOrientation = UIDevice.current.orientation
            
            guard let interfaceOrientation = deviceOrientation.interfaceOrientationMask,
                  interfaceOrientation.isSupported else {
                return
            }
            
            guard !deviceOrientation.isFlat else {
                return
            }
            
            guard UIDevice.current.userInterfaceIdiom == .pad || deviceOrientation != .portraitUpsideDown else {
                return
            }
            
            guard let videoOrientation = deviceOrientation.captureVideoOrientation else {
                return
            }
            
            orientation = videoOrientation
        }
        
        // Check status before updating preview to avoid the crash
        guard status != .stopped && status != .unauthorized && status != .failed else {
            return
        }
        
        // Update preview layer orientation using existing method
        Task {
            await captureService.updatePreviewOrientation(orientation)
        }
    }
    
    // MARK: - Internal state observations
    
    // Set up camera's state observations.
    private func observeState() {
        Task {
            await captureService.$captureCapabilities
                .sink { [weak self] capabilities in
                    self?.isTorchSupported = capabilities.isTorchSupported
                }
                .store(in: &cancellables)
        }
    }
}

fileprivate let logger = Logger(subsystem: "com.microblink.camera", category: "Camera")

extension UIDeviceOrientation {
    var interfaceOrientationMask: UIInterfaceOrientationMask? {
        switch self {
        case .portrait: return .portrait
        case .portraitUpsideDown: return .portraitUpsideDown
        case .landscapeLeft: return .landscapeRight
        case .landscapeRight: return .landscapeLeft
        default: return nil
        }
    }
    
    var captureVideoOrientation: AVCaptureVideoOrientation? {
        switch self {
        case .portrait:
            return .portrait
        case .portraitUpsideDown:
            return .portraitUpsideDown
        case .landscapeLeft:
            return .landscapeRight
        case .landscapeRight:
            return .landscapeLeft
        case .faceUp, .faceDown, .unknown:
            return nil
        default:
            return nil
        }
    }
}

extension UIInterfaceOrientation {
    var interfaceOrientationMask: UIInterfaceOrientationMask? {
        switch self {
        case .portrait: return .portrait
        case .portraitUpsideDown: return .portraitUpsideDown
        case .landscapeLeft: return .landscapeLeft
        case .landscapeRight: return .landscapeRight
        default: return nil
        }
    }
    
    var captureVideoOrientation: AVCaptureVideoOrientation? {
        switch self {
        case .portrait: return .portrait
        case .portraitUpsideDown: return .portraitUpsideDown
        case .landscapeLeft: return .landscapeLeft
        case .landscapeRight: return .landscapeRight
        default: return nil
        }
    }
}

extension AVCaptureVideoOrientation {
    /// - Note: this is added because we need to find the initial orientation when starting camera scanning.
    ///         Simply picking .portrait is not enough since supported interface orientations do not need to contain it.
    ///         In iOS 17 we can use RotationCoordinator for this.
    ///                                                          (4.6.2025. Toni Kreso)
    static var initialOrientation: AVCaptureVideoOrientation {
        if let windowScene = UIApplication.shared.connectedScenes.first as? UIWindowScene {
            let interfaceOrientation = windowScene.interfaceOrientation
            let interfaceMask = interfaceOrientation.interfaceOrientationMask
            
            if let interfaceMask = interfaceMask,
               interfaceMask.isSupported,
               let videoOrientation = interfaceOrientation.captureVideoOrientation {
                return videoOrientation
            }
        }

        let supported = UIInterfaceOrientationMask.supportedOrientationsFromPlist

        if supported.contains(.portrait) {
            return .portrait
        } else if supported.contains(.landscapeLeft) {
            return .landscapeLeft
        } else if supported.contains(.landscapeRight) {
            return .landscapeRight
        } else if supported.contains(.portraitUpsideDown) {
            return .portraitUpsideDown
        }

        return .portrait
    }
}

extension UIInterfaceOrientationMask {
    static var supportedOrientationsFromPlist: UIInterfaceOrientationMask {
        guard let rawList = Bundle.main.object(forInfoDictionaryKey: "UISupportedInterfaceOrientations") as? [String] else {
            return []
        }
        
        return rawList.reduce([]) { result, key in
            switch key {
            case "UIInterfaceOrientationPortrait":
                return result.union(.portrait)
            case "UIInterfaceOrientationPortraitUpsideDown":
                return result.union(.portraitUpsideDown)
            case "UIInterfaceOrientationLandscapeLeft":
                return result.union(.landscapeLeft)
            case "UIInterfaceOrientationLandscapeRight":
                return result.union(.landscapeRight)
            default:
                return result
            }
        }
    }
    
    var isSupported: Bool {
        return Self.supportedOrientationsFromPlist.contains(self)
    }
}

// - MARK: Ping extension
extension ScanningConditionsPinglet.DeviceOrientation {
    static func fromAVCaptureVideoOrientation(_ orientation: AVCaptureVideoOrientation) -> Self {
        switch orientation {
        case .portrait:
            return .portrait
        case .portraitUpsideDown:
            return .portraitupside
        case .landscapeRight:
            return .landscaperight
        case .landscapeLeft:
            return .landscapeleft
        @unknown default:
            fatalError("Unknown AVCaptureVideoOrientation: \(orientation)")
        }
    }
}

extension Camera {
    func sendConditionsPinglet(sessionNumber: Int) async {
        if sessionNumber == 0 {
            return
        }
        let scanningConditionsPinglet = ScanningConditionsPinglet(
            updateType: .deviceorientation,
            deviceOrientation: ScanningConditionsPinglet.DeviceOrientation.fromAVCaptureVideoOrientation(orientation))
        await PingManager.shared.addPinglet(pinglet: scanningConditionsPinglet, sessionNumber: sessionNumber)
    }
    
    func sendCameraStartPinglet(sessionNumber: Int) async {
        if sessionNumber == 0 {
            return
        }
        let uxEventPinglet = UxEventPinglet(eventType: .camerastarted)
        await PingManager.shared.addPinglet(pinglet: uxEventPinglet, sessionNumber: sessionNumber)
    }
}
