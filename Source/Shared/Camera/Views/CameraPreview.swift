//
//  CameraPreview.swift
//  DocumentVerification
//
//  Created by Jura Skrlec on 06.12.2024..
//

import SwiftUI
@preconcurrency import AVFoundation

public struct CameraPreview: UIViewRepresentable {
    
    private let source: any PreviewSource
    private let videoGravity: AVLayerVideoGravity
    
    public init(source: any PreviewSource, videoGravity: AVLayerVideoGravity = .resizeAspectFill) {
        self.source = source
        self.videoGravity = videoGravity
    }
    
    public func makeUIView(context: Context) -> PreviewView {
        let preview = PreviewView()
        // Connect the preview layer to the capture session.
        preview.videoGravity = videoGravity
        source.connect(to: preview)
        return preview
    }
    
    public func updateUIView(_ previewView: PreviewView, context: Context) {
        previewView.videoGravity = videoGravity
    }
    
    /// A class that presents the captured content.
    ///
    /// This class owns the `AVCaptureVideoPreviewLayer` that presents the captured content.
    ///
    public class PreviewView: UIView, PreviewTarget {
        
        init() {
            super.init(frame: .zero)
    #if targetEnvironment(simulator)
            // The capture APIs require running on a real device. If running
            // in Simulator, display a static image to represent the video feed.
            let imageView = UIImageView(frame: UIScreen.main.bounds)
            imageView.image = UIImage(systemName: "camera")     
            imageView.contentMode = .scaleAspectFill
            imageView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
            addSubview(imageView)
    #endif
        }
        
        required init?(coder: NSCoder) {
            fatalError("init(coder:) has not been implemented")
        }
        
        // Use the preview layer as the view's backing layer.
        public override class var layerClass: AnyClass {
            AVCaptureVideoPreviewLayer.self
        }
        
        var previewLayer: AVCaptureVideoPreviewLayer {
            layer as! AVCaptureVideoPreviewLayer
        }
        
        public var videoGravity: AVLayerVideoGravity = .resizeAspectFill {
            didSet {
                previewLayer.videoGravity = videoGravity
            }
        }
        
        nonisolated public func setSession(_ session: AVCaptureSession) {
            // Connects the session with the preview layer, which allows the layer
            // to provide a live view of the captured content.
            Task { @MainActor in
                previewLayer.session = session
            }
        }
    }
}

/// A protocol that enables a preview source to connect to a preview target.
///
/// The SDK provides an instance of this type to the client tier so it can connect
/// the capture session to the `PreviewView` view. It uses these protocols
/// to prevent explicitly exposing the capture objects to the UI layer.
///
public protocol PreviewSource: Sendable {
    // Connects a preview destination to this source.
    func connect(to target: any PreviewTarget)
}

/// A protocol that passes the app's capture session to the `CameraPreview` view.
public protocol PreviewTarget {
    // Sets the capture session on the destination.
    func setSession(_ session: AVCaptureSession)
}

/// The app's default `PreviewSource` implementation.
struct DefaultPreviewSource: PreviewSource {
    
    private let session: AVCaptureSession
    
    init(session: AVCaptureSession) {
        self.session = session
    }
    
    func connect(to target: any PreviewTarget) {
        target.setSession(session)
    }
}
