//
//  VideoOutput.swift
//  DocumentVerification
//
//  Created by Jura Skrlec on 06.12.2024..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

import AVFoundation
import CoreImage

/// Wrapped non Sendable `CMSampleBuffer`
public final class SampleBuffer: @unchecked Sendable {
    public let buffer: CMSampleBuffer
    private let awaiter: DispatchSemaphore

    init(_ buffer: CMSampleBuffer, _ awaiter: DispatchSemaphore) {
        self.buffer = buffer
        self.awaiter = awaiter
    }

    deinit {
        awaiter.signal()
    }
}

final class VideoCapture: OutputService {
    
    /// A value that indicates the current state of stream capture.
    @Published private(set) var captureActivity: CaptureActivity = .idle
    
    // The current capabilities available.
    private(set) var capabilities: CaptureCapabilities = .unknown
    
    /// The capture output type for this service.
    let output = AVCaptureVideoDataOutput()
    
    // An internal alias for the output.
    private var videoOutput: AVCaptureVideoDataOutput { output }
    
    // Stream of wrapped CMSampleBuffer
    var sampleBufferStream: AsyncStream<SampleBuffer> {
        videoCaptureDelegate.stream
    }
    
    // Video capture delegate that handles the buffer stream
    private let videoCaptureDelegate: VideoCaptureDelegate = VideoCaptureDelegate()
    
    init() {
        // Set the delegate to receive frames
        let queue = DispatchQueue(label: "com.camera.videoqueue")
        videoOutput.setSampleBufferDelegate(videoCaptureDelegate, queue: queue)
    }
    
    // MARK: - Update the photo output configuration
    
    /// Reconfigures the photo output and updates the output service's capabilities accordingly.
    ///
    /// The `CaptureService` calls this method whenever you change cameras.
    ///
    func updateConfiguration(for device: AVCaptureDevice) {
        let videoSettings: [String: Any] = [
            kCVPixelBufferPixelFormatTypeKey as String: kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange
        ]
        videoOutput.videoSettings = videoSettings
        videoOutput.alwaysDiscardsLateVideoFrames = true
        
        updateCapabilities(for: device)
    }
    
    private func updateCapabilities(for device: AVCaptureDevice) {
        capabilities = CaptureCapabilities(isTorchSupported: device.isTorchAvailable)
    }
}

private final class VideoCaptureDelegate: NSObject, AVCaptureVideoDataOutputSampleBufferDelegate, @unchecked Sendable {
 
    private var continuation: AsyncStream<SampleBuffer>.Continuation?
    
    deinit {
        self.continuation?.finish()
    }
    
    lazy var stream: AsyncStream<SampleBuffer> = {
        AsyncStream { continuation in
            self.continuation = continuation
        }
    }()
    
    func captureOutput(_ output: AVCaptureOutput, didOutput sampleBuffer: CMSampleBuffer, from connection: AVCaptureConnection) {
        guard CMSampleBufferIsValid(sampleBuffer) else { return }

        // Implementation note:
        // We need a blocking async context to ensure camera preview runs smoothly
        // (AVFoundation detects if this delegate takes too long) and automatically
        // allocates separate buffers for purposes of preview. However, if we just
        // launch the task with captured CMSampleBuffer, AVFoundation will see immediate
        // exit of the delegate function and will try using the same buffer for new frame, but since
        // it's locked due to being in use, this causes camera preview to block.
        //
        //               (2024-10-08) (Nenad Mikša)
        let awaiter = DispatchSemaphore(value: 0)
        if let continuation = continuation {
            continuation.yield(SampleBuffer(sampleBuffer, awaiter))
            awaiter.wait()
        }
    }
}
