//
//  DeviceLookup.swift
//  DocumentVerification
//
//  Created by Jura Skrlec on 06.12.2024..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

import AVFoundation
import Combine

/// An object that retrieves camera.
final class DeviceLookup {
    
    private let backCameraDiscoverySession: AVCaptureDevice.DiscoverySession
    
    // Default to back camera as preferred
    private var preferredPosition: AVCaptureDevice.Position = .back
    
    // This is minimum focus distance for iphone ultra wide camera on older iphones
    private let minimumFocusDistanceInMillimeters = 100
    
    init() {
        backCameraDiscoverySession = AVCaptureDevice.DiscoverySession(deviceTypes: [.builtInTripleCamera, .builtInWideAngleCamera], mediaType: .video, position: .back)
    }
    
    /// Returns the preferred camera for the host system.
    var defaultCamera: AVCaptureDevice {
        get throws {
            
            if hasTripleCamera(),
                let tripleCamera = AVCaptureDevice.default(.builtInTripleCamera, for: .video, position: preferredPosition) {
                return tripleCamera
            }
            
            // Try to get the device for the preferred position
            if let videoDevice = AVCaptureDevice.default(.builtInWideAngleCamera,
                                                       for: .video,
                                                       position: preferredPosition) {
                
                // Check for minimum focus distance
                // We need to ensure if the minimum focus distance is changed for new iphones, we have a solution out of the box
                if videoDevice.minimumFocusDistance > minimumFocusDistanceInMillimeters {
                    let percentIncrease: CGFloat = CGFloat(videoDevice.minimumFocusDistance - minimumFocusDistanceInMillimeters) / CGFloat(minimumFocusDistanceInMillimeters)
                    try videoDevice.lockForConfiguration()
                    videoDevice.videoZoomFactor = 1.0 + percentIncrease
                    videoDevice.unlockForConfiguration()
                }
                return videoDevice
            }
            
            // Fallback to any available camera if preferred position is not available
            if let anyCamera = cameras.first {
                return anyCamera
            }
            
            throw CameraError.videoDeviceUnavailable
        }
    }
    
    var cameras: [AVCaptureDevice] {
        // Populate the cameras array with the available cameras.
        var cameras: [AVCaptureDevice] = []
        if let backCamera = backCameraDiscoverySession.devices.first {
            cameras.append(backCamera)
        }

#if !targetEnvironment(simulator)
        if cameras.isEmpty {
            fatalError("No camera devices are found on this system.")
        }
#endif
        return cameras
    }
    
    /// Updates the preferred camera position
    func setPreferredPosition(_ position: AVCaptureDevice.Position) {
        preferredPosition = position
    }
    
    /// Checks if the current device has a triple camera (Pro iPhone)
    func hasTripleCamera() -> Bool {
        return AVCaptureDevice.default(.builtInTripleCamera, for: .video, position: .back) != nil
    }
}
