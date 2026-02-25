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

import UIKit

final class BlinkIDUXTranslator {
    
    private var backSideDispatched: Bool = false
    private var barcodeDispatched: Bool = false
    private var passportDispatched: Bool = false
    private var barcodeStepNeeded: Bool = false
    private var reticleLocked: Bool = false
    private var barcodeTimerTask: Task<Void, Never>?
    
    func translate(frameProcessResult: FrameProcessResult, scanningSettings: ScanningSettings) -> [UIEvent] {
        var events: [UIEvent] = []
        
        if frameProcessResult.processResult?.resultCompleteness.scanningStatus == .sideScanned && (!backSideDispatched && !passportDispatched) {
            
            if let inputImageAnalysisResult = frameProcessResult.processResult?.inputImageAnalysisResult, inputImageAnalysisResult.documentClassInfo.documentType == .passport {
                passportDispatched = true
                if [Country.usa, Country.india].contains(inputImageAnalysisResult.documentClassInfo.country) {
                    events.append(.requestDocumentSide(side: .passportBarcode))
                } else {
                    events.append(.requestDocumentSide(side: .passport(getPassportOrientation(inputImageAnalysisResult.documentRotation))))
                }
                
            }
            else {
                backSideDispatched = true
                events.append(.requestDocumentSide(side: .back))
            }
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
            if passportDispatched, let inputImageAnalysisResult = frameProcessResult.processResult?.inputImageAnalysisResult {
                if [Country.usa, Country.india].contains(inputImageAnalysisResult.documentClassInfo.country) {
                    events.append(.wrongSidePassportWithBarcode)
                } else {
                    events.append(.wrongSidePassport(passportOrientation: getPassportOrientation(inputImageAnalysisResult.documentRotation)))
                }
            }
            else {
                events.append(.wrongSide)
            }
            
        case .imageReturnFailed:
            if let processResult = frameProcessResult.processResult {
                if processResult.inputImageAnalysisResult.imageExtractionFailures.contains(.face) {
                    events.append(.facePhotoNotFullyVisible)
                }
            }
        case .mandatoryFieldMissing, .invalidCharactersFound, .mrzParsingFailed:
            events.append(.notFullyVisible)
        default:
            break
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
        
        if frameProcessResult.processResult?.inputImageAnalysisResult.blurDetectionStatus == .detected && scanningSettings.skipImagesWithBlur {
            events.append(.blur)
        }
        if frameProcessResult.processResult?.inputImageAnalysisResult.glareDetectionStatus == .detected && scanningSettings.skipImagesWithGlare {
            events.append(.glare)
        }
        if frameProcessResult.processResult?.inputImageAnalysisResult.documentHandOcclusionStatus == .detected && scanningSettings.skipImagesOccludedByHand {
            events.append(.occlusion)
        }
        if frameProcessResult.processResult?.inputImageAnalysisResult.documentLightingStatus == .tooDark && scanningSettings.skipImagesWithInadequateLightingConditions {
            events.append(.tooDark)
        }
        if frameProcessResult.processResult?.inputImageAnalysisResult.documentLightingStatus == .tooBright && scanningSettings.skipImagesWithInadequateLightingConditions {
            events.append(.tooBright)
        }
        
        return events
    }
    
    func resetState() {
        passportDispatched = false
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
    
    private func getPassportOrientation(_ documentRotation: DocumentRotation) -> PassportOrientation {
        let currentOrientation = UIDevice.current.orientation
        let isPortrait = currentOrientation.isPortrait || currentOrientation == .unknown
        let isFlat = currentOrientation.isFlat
        if isPortrait {
            if documentRotation == .zero {
                return PassportOrientation.right90
            }
            if documentRotation == .upsideDown {
                return PassportOrientation.left90
            }
        }
        else if isFlat {
            return PassportOrientation.none
        }
        else {
            if currentOrientation.isLandscape {
                if documentRotation == .zero {
                    return PassportOrientation.none
                }
                else if documentRotation == .clockwise90 {
                    if currentOrientation == .landscapeLeft {
                        return PassportOrientation.right90
                    }
                    else if currentOrientation == .landscapeRight {
                        return PassportOrientation.right90
                    }
                }
                else if documentRotation == .counterClockwise90 {
                    if currentOrientation == .landscapeLeft {
                        return PassportOrientation.left90
                    }
                    else if currentOrientation == .landscapeRight {
                        return PassportOrientation.right90
                    }
                }
                else if documentRotation == .upsideDown {
                    return PassportOrientation.none
                }
            }
        }
        
        return PassportOrientation.none
    }
}

