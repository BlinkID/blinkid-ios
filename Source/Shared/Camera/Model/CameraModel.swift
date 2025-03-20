//
//  CameraModel.swift
//  DocumentVerification
//
//  Created by Jura Skrlec on 06.12.2024..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

import SwiftUI
import AVFoundation

/// A protocol that represents the model for the camera.
@MainActor
public protocol CameraModel: AnyObject {
    
    /// Provides the current status of the camera.
    var status: CameraStatus { get }

    /// The source of video content for a camera preview.
    var previewSource: any PreviewSource { get }
    
    /// A Boolean value that indicates whether the camera is currently switching capture modes.
    var isSwitchingModes: Bool { get }
    
    /// Starts the camera capture pipeline.
    func start() async
    
    /// Stops the camera capture pipeline.
    func stop() async

    /// Performs a one-time automatic focus and exposure operation.
    func focusAndExpose(at point: CGPoint) async
    
    /// An error if the camera encountered a problem.
    var error: (any Error)? { get }
    
    /// A Boolean that indicates whether the camera supports torch.
    var isTorchSupported: Bool { get }
    
    /// A Boolean value that indicates whether camera enables torch.
    var isTorchEnabled: Bool { get set }
    
    /// An enum of current video orientation.
    var orientation: AVCaptureVideoOrientation { get }
    
    /// The async stream of ``SampleBuffer``
    /// ``SampleBuffer`` is a immutable wrapper over `CMSampleBuffer`.
    var sampleBuffer: AsyncStream<SampleBuffer> { get async }
    
}
