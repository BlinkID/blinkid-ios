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
final class DeviceObserver: NSObject {
    private let systemPreferredKeyPath = "systemPreferredCamera"
    
    let changes: AsyncStream<AVCaptureDevice>
    private var continuation: AsyncStream<AVCaptureDevice>.Continuation?

    override init() {
        let (changes, continuation) = AsyncStream.makeStream(of: AVCaptureDevice.self)
        self.changes = changes
        self.continuation = continuation
        
        super.init()
        
        AVCaptureDevice.self.addObserver(self, forKeyPath: systemPreferredKeyPath, options: [.new], context: nil)
    }

    deinit {
        continuation?.finish()
        AVCaptureDevice.removeObserver(self, forKeyPath: systemPreferredKeyPath)
    }
    
    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey: Any]?, context: UnsafeMutableRawPointer?) {
        switch keyPath {
        case systemPreferredKeyPath:
            // Update the observer's system-preferred camera value.
            guard let newDevice = change?[.newKey] as? AVCaptureDevice else { return }
            
            continuation?.yield(newDevice)
        default:
            super.observeValue(forKeyPath: keyPath, of: object, change: change, context: context)
        }
    }

}
