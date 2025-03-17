//
//  Types.swift
//  DocumentVerification
//
//  Created by Jura Skrlec on 06.12.2024..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

import AVFoundation

// MARK: - Supporting types

/// An enumeration that describes the current status of the camera.
public enum CameraStatus {
    /// The initial status upon creation.
    case unknown
    /// A status that indicates a person disallows access to the camera or microphone.
    case unauthorized
    /// A status that indicates the camera failed to start.
    case failed
    /// A status that indicates the camera is successfully running.
    case running
    /// A status that indicates higher-priority media processing is interrupting the camera.
    case interrupted
    /// A status that indicates the camera is successfully stopped.
    case stopped
}

/// An enumeration of the capture modes that the camera supports.
public enum CaptureMode: String, Identifiable, CaseIterable {
    public var id: Self { self }
    /// A mode that enables getting buffer stream.
    case video
}

/// An enumeration that defines the activity states the capture service supports.
public enum CaptureActivity {
    case idle
}

/// A structure that represents the capture capabilities of `CaptureService` in
/// its current configuration.
struct CaptureCapabilities {
    let isTorchSupported: Bool
    
    init(isTorchSupported: Bool = false) {
        self.isTorchSupported = isTorchSupported
    }
    
    static let unknown = CaptureCapabilities()
}

enum CameraError: Error {
    case videoDeviceUnavailable
    case audioDeviceUnavailable
    case addInputFailed
    case addOutputFailed
    case setupFailed
    case deviceChangeFailed
}

protocol OutputService {
    associatedtype Output: AVCaptureOutput
    var output: Output { get }
    var captureActivity: CaptureActivity { get }
    var capabilities: CaptureCapabilities { get }
    func updateConfiguration(for device: AVCaptureDevice)
    func setVideoOrientation(_ orientation: AVCaptureVideoOrientation)
}

extension OutputService {
    func setVideoOrientation(_ orientation: AVCaptureVideoOrientation) {
        // Set the orientation on the output object's video connection
        guard let connection = output.connection(with: .video) else { return }
        if connection.isVideoOrientationSupported {
            connection.videoOrientation = orientation
        }
    }
    func updateConfiguration(for device: AVCaptureDevice) {}
}
