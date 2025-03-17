//
//  CaptureService.swift
//  DocumentVerification
//
//  Created by Jura Skrlec on 06.12.2024..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

import Foundation
import Combine
import UIKit
import os.log
@preconcurrency import AVFoundation

/// An actor that manages the capture pipeline, which includes the capture session, device inputs, and capture outputs.
actor CaptureService {
    /// A value that indicates whether the capture service is idle.
    @Published private(set) var captureActivity: CaptureActivity = .idle
    /// A value that indicates the current capture capabilities of the service.
    @Published private(set) var captureCapabilities = CaptureCapabilities.unknown
    /// A Boolean value that indicates whether a higher priority event, like receiving a phone call, interrupts the session.
    @Published private(set) var isInterrupted = false
    /// A Boolean value that indicates whether the user enables torch.
    @Published var isTorchEnabled = false
    
    /// A type that connects a preview destination with the capture session.
    nonisolated let previewSource: any PreviewSource
    
    // The app's capture session.
    private let captureSession = AVCaptureSession()
    
    // An object that manages the video capture behavior.
    private let videoCapture: VideoCapture = VideoCapture()
    
    // The video input for the currently selected device camera.
    private var activeVideoInput: AVCaptureDeviceInput?
    
    // The mode of capture, stream. Defaults to video.
    private(set) var captureMode = CaptureMode.video
    
    // An object the service uses to retrieve capture devices.
    private let deviceLookup = DeviceLookup()
    
    // An object that monitors the state of the system-preferred camera.
    private let systemPreferredCamera = DeviceObserver()
    
    // An internal collection of output services.
    private var outputServices: [any OutputService] { [videoCapture] }
    
    // A Boolean value that indicates whether the actor finished its required configuration.
    private var isSetUp = false
    
    // Task for monitoring system preferred camera
    private var monitorTask: Task<Void, Never>?
    
    // Task for subject area change notification observing
    private var subjectAreaChangeTask: Task<Void, Never>?
    
    // Task for AVCaptureSession.wasInterruptedNotification observing
    private var wasInterruptedNotificationTask: Task<Void, Never>?
    
    // Task for AVCaptureSession.interruptionEndedNotification observing
    private var interruptionEndedNotificationTask: Task<Void, Never>?
    
    // Task for AVCaptureSession.runtimeErrorNotification observing
    private var runtimeErrorNotificationTask: Task<Void, Never>?
    
    init() {
        // Create a source object to connect the preview view with the capture session.
        previewSource = DefaultPreviewSource(session: captureSession)
    }
    
    // MARK: - Authorization
    /// A Boolean value that indicates whether a person authorizes the app to use
    /// device cameras. If they haven't previously authorized the
    /// app, querying this property prompts them for authorization.
    var isAuthorized: Bool {
        get async {
            let status = AVCaptureDevice.authorizationStatus(for: .video)
            // Determine whether a person previously authorized camera access.
            var isAuthorized = status == .authorized
            // If the system hasn't determined their authorization status,
            // explicitly prompt them for approval.
            if status == .notDetermined {
                isAuthorized = await AVCaptureDevice.requestAccess(for: .video)
            }
            return isAuthorized
        }
    }
    
    // MARK: - Capture session life cycle
    func start() async throws {
        // Exit early if not authorized or the session is already running.
        guard await isAuthorized, !captureSession.isRunning else { return }
        // Configure the session and start it.
        try setUpSession()
        captureSession.startRunning()
    }
    
    func stop() async throws {
        // Exit early if not authorized or the session is already running.
        guard await isAuthorized, captureSession.isRunning else { return }
        captureSession.stopRunning()
        stopTasks()
        isSetUp = false
    }
    
    // MARK: - Capture setup
    // Performs the initial capture session configuration.
    private func setUpSession() throws {
        // Return early if already set up.
        guard !isSetUp else { return }

        // Observe internal state and notifications.
        observeOutputServices()
        observeNotifications()
        
        do {
            // Retrieve the default camera.
            let defaultCamera = try deviceLookup.defaultCamera

            // Add inputs for the default camera devices.
            activeVideoInput = try addInput(for: defaultCamera)

            // Configure the session for video capture by default.
            captureSession.sessionPreset = .hd1920x1080
            try addOutput(videoCapture.output)
            
            // Monitor the system-preferred camera state.
            monitorSystemPreferredCamera()
            
            // Configure a rotation coordinator for the default video device.
            // Observe changes to the default camera's subject area.
            observeSubjectAreaChanges(of: defaultCamera)
            // Update the service's advertised capabilities.
            updateCaptureCapabilities()
            
            isSetUp = true
        } catch {
            throw CameraError.setupFailed
        }
    }
    
    // Adds an input to the capture session to connect the specified capture device.
    @discardableResult
    private func addInput(for device: AVCaptureDevice) throws -> AVCaptureDeviceInput {
        let input = try AVCaptureDeviceInput(device: device)
        if captureSession.canAddInput(input) {
            captureSession.addInput(input)
        } else {
            throw CameraError.addInputFailed
        }
        return input
    }
    
    // Adds an output to the capture session to connect the specified capture device, if allowed.
    private func addOutput(_ output: AVCaptureOutput) throws {
        if captureSession.canAddOutput(output) {
            captureSession.addOutput(output)
        } else {
            throw CameraError.addOutputFailed
        }
    }
    
    // The device for the active video input.
    private var currentDevice: AVCaptureDevice {
        guard let device = activeVideoInput?.device else {
            fatalError("No device found for current video input.")
        }
        return device
    }
    
    // MARK: - Capture mode selection
    
    /// Changes the mode of capture, which can be `photo` or `video`.
    ///
    /// - Parameter `captureMode`: The capture mode to enable.
    func setCaptureMode(_ captureMode: CaptureMode) throws {
        // Update the internal capture mode value before performing the session configuration.
        self.captureMode = captureMode
        
        // Change the configuration atomically.
        captureSession.beginConfiguration()
        defer { captureSession.commitConfiguration() }
        
        // Configure the capture session for the selected capture mode.
        switch captureMode {
        case .video:
            captureSession.sessionPreset = .high
            try addOutput(videoCapture.output)
        }

        // Update the advertised capabilities after reconfiguration.
        updateCaptureCapabilities()
    }
    
    // Changes the device the service uses for video capture.
    private func changeCaptureDevice(to device: AVCaptureDevice) {
        // The service must have a valid video input prior to calling this method.
        guard let currentInput = activeVideoInput else { fatalError() }
        
        // Bracket the following configuration in a begin/commit configuration pair.
        captureSession.beginConfiguration()
        defer { captureSession.commitConfiguration() }
        
        // Remove the existing video input before attempting to connect a new one.
        captureSession.removeInput(currentInput)
        do {
            // Attempt to connect a new input and device to the capture session.
            activeVideoInput = try addInput(for: device)
            // Register for device observations.
            observeSubjectAreaChanges(of: device)
            // Update the service's advertised capabilities.
            updateCaptureCapabilities()
        } catch {
            // Reconnect the existing camera on failure.
            captureSession.addInput(currentInput)
        }
    }
    
    /// Monitors changes to the system's preferred camera selection.
    private func monitorSystemPreferredCamera() {
        monitorTask?.cancel()
        monitorTask = Task {
            // An object monitors changes to camera deivce observer (CDO) value.
            for await camera in systemPreferredCamera.changes {
                // If the CDO isn't the currently selected camera, attempt to change to that device.
                if let camera, currentDevice != camera {
                    logger.debug("Switching camera selection to the system-preferred camera.")
                    changeCaptureDevice(to: camera)
                }
            }
        }
    }
    
    private func stopTasks() {
        monitorTask?.cancel()
        subjectAreaChangeTask?.cancel()
        wasInterruptedNotificationTask?.cancel()
        interruptionEndedNotificationTask?.cancel()
        runtimeErrorNotificationTask?.cancel()
    }
    
    func updatePreviewOrientation(_ orientation: AVCaptureVideoOrientation) {
        let previewLayer = videoPreviewLayer
        Task { @MainActor in
            previewLayer.connection?.videoOrientation = orientation
        }
    }

    private func updateCaptureOrientation(_ orientation: AVCaptureVideoOrientation) {
        // Update the orientation for all output services.
        outputServices.forEach { $0.setVideoOrientation(orientation) }
    }
    
    private var videoPreviewLayer: AVCaptureVideoPreviewLayer {
        // Access the capture session's connected preview layer.
        guard let previewLayer = captureSession.connections.compactMap({ $0.videoPreviewLayer }).first else {
            fatalError("The app is misconfigured. The capture session should have a connection to a preview layer.")
        }
        return previewLayer
    }
    
    // MARK: - Automatic focus and exposure
    
    /// Performs a one-time automatic focus and expose operation.
    ///
    /// The app calls this method as the result of a person tapping on the preview area.
    func focusAndExpose(at point: CGPoint) {
        // The point this call receives is in view-space coordinates. Convert this point to device coordinates.
        let devicePoint = videoPreviewLayer.captureDevicePointConverted(fromLayerPoint: point)
        do {
            // Perform a user-initiated focus and expose.
            try focusAndExpose(at: devicePoint, isUserInitiated: true)
        } catch {
            logger.debug("Unable to perform focus and exposure operation. \(error)")
        }
    }
    
    // Observe notifications of type `subjectAreaDidChangeNotification` for the specified device.
    private func observeSubjectAreaChanges(of device: AVCaptureDevice) {
        // Cancel the previous observation task.
        subjectAreaChangeTask?.cancel()
        subjectAreaChangeTask = Task {
            // Signal true when this notification occurs.
            for await _ in NotificationCenter.default.notifications(named: AVCaptureDevice.subjectAreaDidChangeNotification, object: device).compactMap({ _ in true }) {
                // Perform a system-initiated focus and expose.
                try? focusAndExpose(at: CGPoint(x: 0.5, y: 0.5), isUserInitiated: false)
            }
        }
    }
    
    private func focusAndExpose(at devicePoint: CGPoint, isUserInitiated: Bool) throws {
        // Configure the current device.
        let device = currentDevice
        
        // The following mode and point of interest configuration requires obtaining an exclusive lock on the device.
        try device.lockForConfiguration()
        
        let focusMode = isUserInitiated ? AVCaptureDevice.FocusMode.autoFocus : .continuousAutoFocus
        if device.isFocusPointOfInterestSupported && device.isFocusModeSupported(focusMode) {
            device.focusPointOfInterest = devicePoint
            device.focusMode = focusMode
        }
        
        let exposureMode = isUserInitiated ? AVCaptureDevice.ExposureMode.autoExpose : .continuousAutoExposure
        if device.isExposurePointOfInterestSupported && device.isExposureModeSupported(exposureMode) {
            device.exposurePointOfInterest = devicePoint
            device.exposureMode = exposureMode
        }
        // Enable subject-area change monitoring when performing a user-initiated automatic focus and exposure operation.
        // If this method enables change monitoring, when the device's subject area changes, the app calls this method a
        // second time and resets the device to continuous automatic focus and exposure.
        device.isSubjectAreaChangeMonitoringEnabled = isUserInitiated
        
        // Release the lock.
        device.unlockForConfiguration()
    }
    
    // MARK: - Torch
    
    /// Sets whether the SDK enables torch.
    func setTorchEnabled(_ isEnabled: Bool) {
        // Bracket the following configuration in a begin/commit configuration pair.
        captureSession.beginConfiguration()
        defer { captureSession.commitConfiguration() }
        do {
            // If the current device has a torch.
            if currentDevice.hasTorch {
                try currentDevice.lockForConfiguration()
                currentDevice.torchMode = isEnabled ? .on : .off
                currentDevice.unlockForConfiguration()
                isTorchEnabled = isEnabled ? true : false
            }
        } catch {
            logger.error("Unable to obtain lock on device and can't enable torch.")
        }
    }
    
    // MARK: - Sample buffer
    /// Wrapped `CMSampleBuffer` stream.
    var sampleBufferStream: AsyncStream<SampleBuffer> {
        videoCapture.sampleBufferStream
    }
    
    // MARK: - Internal state management
    /// Updates the state of the actor to ensure its advertised capabilities are accurate.
    
    private func updateCaptureCapabilities() {
        // Update the output service configuration.
        outputServices.forEach { $0.updateConfiguration(for: currentDevice) }
        // Set the capture service's capabilities for the selected mode.
        switch captureMode {
        case .video:
            captureCapabilities = videoCapture.capabilities
        }
    }
    
    /// Merge the `captureActivity` values of the photo and movie capture services,
    /// and assign the value to the actor's property.`
    private func observeOutputServices() {
        videoCapture.$captureActivity.assign(to: &$captureActivity)
    }

    /// Observe capture-related notifications.
    private func observeNotifications() {
        // Handle capture session interruption
        wasInterruptedNotificationTask?.cancel()
        wasInterruptedNotificationTask = Task {
            let notifications = NotificationCenter.default
                .notifications(named: AVCaptureSession.wasInterruptedNotification)
                .compactMap { notification -> AVCaptureSession.InterruptionReason? in
                    guard let rawValue = (notification.userInfo?[AVCaptureSessionInterruptionReasonKey] as? NSNumber)?.intValue else {
                        return nil
                    }
                    return AVCaptureSession.InterruptionReason(rawValue: rawValue)
                }
            
            for await reason in notifications {
                isInterrupted = [.audioDeviceInUseByAnotherClient, .videoDeviceInUseByAnotherClient].contains(reason)
            }
        }
        
        // Handle interruption ended
        interruptionEndedNotificationTask?.cancel()
        interruptionEndedNotificationTask = Task {
            let notifications = NotificationCenter.default
                .notifications(named: AVCaptureSession.interruptionEndedNotification)
                .map { _ in () } // Transform to Void to avoid Sendable issues
            
            for await _ in notifications {
                isInterrupted = false
            }
        }
        
        // Handle runtime errors
        runtimeErrorNotificationTask?.cancel()
        runtimeErrorNotificationTask = Task {
            let notifications = NotificationCenter.default
                .notifications(named: AVCaptureSession.runtimeErrorNotification)
                .compactMap { notification -> AVError? in
                    return notification.userInfo?[AVCaptureSessionErrorKey] as? AVError
                }
            
            for await error in notifications {
                if error.code == .mediaServicesWereReset {
                    if !captureSession.isRunning {
                        captureSession.startRunning()
                    }
                }
            }
        }
    }
}

fileprivate let logger = Logger(subsystem: "com.microblink.camera", category: "CaptureService")
