//
//  BlinkIDUXTranslator.swift
//  DocumentVerificationUX
//
//  Created by Jura Skrlec on 19.02.2025..
//

#if canImport(BlinkIDVerify)
import BlinkIDVerify
#elseif canImport(BlinkID)
import BlinkID
#endif

final class BlinkIDUXTranslator {
    
    private var backSideDispatched: Bool = false
    private var barcodeDispatched: Bool = false
    private var barcodeStepNeeded: Bool = false
    private var reticleLocked: Bool = false
    private var barcodeTimerTask: Task<Void, Never>?
    
    func translate(frameProcessResult: FrameProcessResult, session: BlinkIDSession) -> [UIEvent] {
        var events: [UIEvent] = []
        
        if frameProcessResult.processResult?.resultCompleteness.scanningStatus == .sideScanned && !backSideDispatched {
            backSideDispatched = true
            events.append(.requestDocumentSide(side: .back))
        }
        
        if frameProcessResult.processResult?.inputImageAnalysisResult.processingStatus == .barcodeRecognitionFailed && !barcodeDispatched && backSideDispatched {
            reticleLocked = true
            if barcodeTimerTask == nil {
                startBarcodeScanTimer()
            }
            if barcodeStepNeeded {
                barcodeDispatched = true
                events.append(.requestDocumentSide(side: .barcode))
            }
        }
        
        guard !reticleLocked else {
            return events
        }
        
        switch frameProcessResult.processResult?.inputImageAnalysisResult.processingStatus {
        case .scanningWrongSide, .awaitingOtherSide:
            events.append(.wrongSide)
        case .success, .detectionFailed:
            break
        default:
            events.append(.notFullyVisible)
        }
        
        switch frameProcessResult.processResult?.inputImageAnalysisResult.documentDetectionStatus {
        case .cameraTooFar:
            events.append(.tooFar)
        case .cameraTooClose:
            events.append(.tooClose)
        case .cameraAngleTooSteep:
            events.append(.tilt)
        case .documentTooCloseToCameraEdge:
            events.append(.tooCloseToEdge)
        case .documentPartiallyVisible:
            events.append(.notFullyVisible)
        default:
            break
        }
        
        if frameProcessResult.processResult?.inputImageAnalysisResult.blurDetectionStatus == .detected {
            events.append(.blur)
        }
        if frameProcessResult.processResult?.inputImageAnalysisResult.glareDetectionStatus == .detected {
            events.append(.glare)
        }
        if frameProcessResult.processResult?.inputImageAnalysisResult.documentHandOcclusionStatus == .detected {
            events.append(.occlusion)
        }
        
        return events
    }
    
    func resetState() {
        backSideDispatched = false
        barcodeDispatched = false
        barcodeStepNeeded = false
        reticleLocked = false
        barcodeTimerTask?.cancel()
        barcodeTimerTask = nil
    }
    
    private func startBarcodeScanTimer() {
        barcodeTimerTask = Task { [weak self] in
            try? await Task.sleep(nanoseconds: UInt64(3.0 * 1_000_000_000))
            if !Task.isCancelled {
                self?.barcodeStepNeeded = true
            }
        }
    }
}

