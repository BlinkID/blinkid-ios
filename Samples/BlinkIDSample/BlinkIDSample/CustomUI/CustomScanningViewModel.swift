// Created by Toni Krešo on 13.01.2025.. 
// Copyright (c) 2025 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import AVFoundation
import Foundation
import BlinkIDVerify
import BlinkIDVerifyUX

@MainActor
public final class CustomScanningViewModel: ObservableObject {
  
    let camera: Camera = Camera()
    let analyzer: CameraFrameAnalyzer
    @Published var instructionText: String = "Scan the front side"
    @Published public var captureResult: BlinkIDVerifyCaptureResult?
    @Published public var roi: RegionOfInterest = RegionOfInterest()
    private var paused = false
    
    private var eventHandlingTask: Task<Void, Never>?
    
    public init(analyzer: CameraFrameAnalyzer) {
        self.analyzer = analyzer
        startEventHandling()
    }

    func pauseScanning() {
        Task {
            await analyzer.cancel()
        }
    }

    func setInstructionText(text: String) {
        instructionText = text
    }
    
    func closeButtonTapped() {
        pauseScanning()
        captureResult = nil
    }
    
    // - MARK: Analyze
    public func analyze() async {
        Task {
            let result = await analyzer.result()
            switch result {
            case .completed(let captureResult):
               self.captureResult = captureResult as? BlinkIDVerifyCaptureResult
            case .cancelled, .timeout:
                break
            case .none:
                break
            }
        }
        
        for await frame in await camera.sampleBuffer {
            await analyzer.analyze(image: CameraFrame(buffer: MBSampleBufferWrapper(cmSampleBuffer: frame.buffer), roi: roi, orientation: camera.orientation.toCameraFrameVideoOrientation()))
        }
    }
    
    private func startEventHandling() {
        eventHandlingTask = Task {
            for await events in await analyzer.events.stream {
                if events.contains(.requestDocumentSide(side: .back)) {
                    instructionText = "Scan the back side"
                } else if events.contains(.requestDocumentSide(side: .barcode)) {
                    instructionText = "Scan the barcode"
                } else if events.contains(.wrongSide) {
                    instructionText = "Flip the document"
                } else if events.contains(.tooClose) {
                    instructionText = "Move farther"
                } else if events.contains(.tooFar) {
                    instructionText = "Move closer"
                } else if events.contains(.tooCloseToEdge) {
                    instructionText = "Move farther"
                } else if events.contains(.tilt) {
                    instructionText = "Keep document parallel with the phone"
                } else if events.contains(.blur) {
                    instructionText = "Keep document and phone still"
                } else if events.contains(.glare) {
                    instructionText = "Tilt or move document to remove reflection"
                } else if events.contains(.notFullyVisible) {
                    instructionText = "Keep document fully visible"
                }
            }
        }
    }
    
    func stopEventHandling() {
        eventHandlingTask?.cancel()
    }
}
