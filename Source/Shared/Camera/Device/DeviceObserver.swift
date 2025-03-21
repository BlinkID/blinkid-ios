//
//  DeviceObserver.swift
//  DocumentVerification
//
//  Created by Jura Skrlec on 06.12.2024..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

@preconcurrency import AVFoundation

/// An object that provides an asynchronous stream of capture devices when camera availability changes
final class DeviceObserver: NSObject, Sendable {
    
    private let queue = DispatchQueue.main
    private let notificationCenter: NotificationCenter = NotificationCenter.default
    
    let changes: AsyncStream<AVCaptureDevice?>
    private let continuation: AsyncStream<AVCaptureDevice?>.Continuation

    private let backCameraDiscoverySession: AVCaptureDevice.DiscoverySession

    override init() {
        
        backCameraDiscoverySession = AVCaptureDevice.DiscoverySession(
            deviceTypes: [.builtInTripleCamera, .builtInWideAngleCamera],
            mediaType: .video,
            position: .back
        )
        
        var continuation: AsyncStream<AVCaptureDevice?>.Continuation?
        let stream = AsyncStream<AVCaptureDevice?> { continuation = $0 }
        guard let continuation else {
            fatalError("Failed to create AsyncStream continuation")
        }
        self.changes = stream
        self.continuation = continuation
        
        super.init()
        
        setupNotifications()
        // Send initial camera state
        sendCurrentCameras()
    }
    
    private func setupNotifications() {
        notificationCenter.addObserver(
            self,
            selector: #selector(deviceDidConnect),
            name: .AVCaptureDeviceWasConnected,
            object: nil
        )
        
        notificationCenter.addObserver(
            self,
            selector: #selector(deviceDidDisconnect),
            name: .AVCaptureDeviceWasDisconnected,
            object: nil
        )
    }
    
    
    private func sendCurrentCameras() {
        queue.async { [weak self] in
            if let backCamera = self?.backCameraDiscoverySession.devices.first {
                self?.continuation.yield(backCamera)
            }
        }
    }
    
    @objc private func deviceDidConnect(notification: Notification) {
        sendCurrentCameras()
    }
    
    @objc private func deviceDidDisconnect(notification: Notification) {
        sendCurrentCameras()
    }
    
    deinit {
        notificationCenter.removeObserver(self)
        continuation.finish()
    }
}
