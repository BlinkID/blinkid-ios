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
    private let frontCameraDiscoverySession: AVCaptureDevice.DiscoverySession
    
    // Default to back camera as preferred
    private var preferredPosition: AVCaptureDevice.Position = .back
    
    // This is minimum focus distance for iphone ultra wide camera on older iphones
    private let minimumFocusDistanceInMillimeters = 100
    
    init() {
        backCameraDiscoverySession = AVCaptureDevice.DiscoverySession(deviceTypes: [.builtInTripleCamera, .builtInWideAngleCamera], mediaType: .video, position: .back)
        frontCameraDiscoverySession = AVCaptureDevice.DiscoverySession(deviceTypes: [.builtInWideAngleCamera], mediaType: .video, position: .front)
    }
    
    var backCamera: AVCaptureDevice {
        get throws {
            
            if let tripleCamera = AVCaptureDevice.default(.builtInTripleCamera, for: .video, position: .back) {
                return tripleCamera
            }
            
            if let backCamera = AVCaptureDevice.default(.builtInWideAngleCamera, for: .video, position: .back)  {
                if backCamera.minimumFocusDistance > minimumFocusDistanceInMillimeters {
                    if backCamera.deviceType == .builtInWideAngleCamera {
                        let percentIncrease: CGFloat = CGFloat(backCamera.minimumFocusDistance - minimumFocusDistanceInMillimeters) / CGFloat(minimumFocusDistanceInMillimeters)
                        try backCamera.lockForConfiguration()
                        backCamera.videoZoomFactor = 1.0 + percentIncrease
                        backCamera.unlockForConfiguration()
                    }
                }
                return backCamera
            }
            
            throw CameraError.videoDeviceUnavailable
        }
    }
    
    var frontCamera: AVCaptureDevice {
        get throws {
            if let frontCamera = frontCameraDiscoverySession.devices.first {
                return frontCamera
            }
            throw CameraError.videoDeviceUnavailable
        }
    }
    
    var cameras: [AVCaptureDevice] {
        var cameras: [AVCaptureDevice] = []
        
        if let backCamera = backCameraDiscoverySession.devices.first {
            cameras.append(backCamera)
        }
        
        if let frontCamera = frontCameraDiscoverySession.devices.first {
            cameras.append(frontCamera)
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
}
