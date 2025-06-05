//
//  BlinkIDUXModel.swift
//  DocumentVerificationUX
//
//  Created by Jura Skrlec on 19.02.2025..
//

import AVFoundation
import Foundation
import CoreImage
import Combine
import SwiftUI

#if canImport(BlinkIDVerify)
import BlinkIDVerify
#elseif canImport(BlinkID)
import BlinkID
#endif

/// A view model that manages the user experience flow for document scanning.
/// Handles camera preview, document detection, user guidance, and scanning state transitions.
@MainActor
public final class BlinkIDUXModel: ScanningViewModel<BlinkIDScanningResult, BlinkIDScanningAlertType> {
    
    /// The result of the document verification capture process.
    /// Contains the captured document images and associated data.
    @Published public var result: BlinkIDResultState?
    
    // MARK: - Passport Animation Properties
    @Published var showPassportAnimation: Bool = false
    @Published var isPassportAnimating: Bool = false
    @Published var passportFromAnimationImage = Image.passportBottomImage
    @Published var passportToAnimationImage = Image.passportTopImage
    @Published var passportHighlightAnimationImage = Image.passportHighlightImage
    
    @Published var topImageOpacity: Double
    @Published var bottomImageOpacity: Double
    @Published var highlightOffset: CGFloat
    
    let passportBeginAnimationAlpha: Double = 0.4
    let passportEndAnimationAlpha: Double = 1.0
    let passportAnimationDuration: Double = 2.0
    let passportRelativeDuration: Double = 0.5

    var passportOrientation: PassportOrientation?
    var isDocumentPassport: Bool {
        return passportOrientation != nil
    }
    
    var passportHighlightDistance: CGFloat = 0
    
    private var cancellables = Set<AnyCancellable>()
    
    public override init(analyzer: any CameraFrameAnalyzer<CameraFrame, UIEvent>, shouldShowIntroductionAlert: Bool = true, showHelpButton: Bool = true) {
        
        self.topImageOpacity = passportBeginAnimationAlpha
        self.bottomImageOpacity = passportEndAnimationAlpha
        self.highlightOffset = 0
        self.passportOrientation = nil
        
        super.init(analyzer: analyzer, shouldShowIntroductionAlert: shouldShowIntroductionAlert, showHelpButton: showHelpButton)
        
        startEventHandling()
        camera.$status
            .sink { [weak self] _ in
                self?.objectWillChange.send()
            }
            .store(in: &cancellables)
    }
    
    // MARK: - Protocol Implementation
    
    public override func analyze() async {
        Task {
            await processAnalyzerResult()
        }

        for await frame in await camera.sampleBuffer {
            await analyzer.analyze(image: CameraFrame(buffer: MBSampleBufferWrapper(cmSampleBuffer: frame.buffer), roi: roi, orientation: camera.orientation.toCameraFrameVideoOrientation()))
        }
    }
    
    public override func processAnalyzerResult() async {
        let result = await analyzer.result()
        if let scanningResult = result as? ScanningResult<BlinkIDScanningResult, BlinkIDScanningAlertType> {
            switch scanningResult {
            case .completed(let scanningResult):
                await finishScan()
                self.result = BlinkIDResultState(scanningResult: scanningResult)
            case .interrupted(let alertType):
                self.alertType = alertType
                showScanningAlert = true
            case .cancelled:
                showLicenseErrorAlert = true
            case .ended:
                self.result = BlinkIDResultState(scanningResult: nil)
            }
        }
    }
    
    public override func licenseErrorAlertDismised() {
        result = BlinkIDResultState(scanningResult: nil)
    }
    
    public override func scanningDidCancel() {
        super.scanningDidCancel()
        result = BlinkIDResultState(scanningResult: nil)
    }
    
    public override func timeoutAlertDismised() {
        reticleState = .front
        topImageOpacity = passportBeginAnimationAlpha
        bottomImageOpacity = passportEndAnimationAlpha
        highlightOffset = 0
        passportOrientation = nil
        restartScanning()
        Task {
            await self.analyze()
        }
    }
    
    override func closeButtonTapped() {
        Task {
            await self.analyzer.end()
        }
        result = BlinkIDResultState(scanningResult: nil)
    }
    
    // - MARK: - Handle UIEvents

    private func startEventHandling() {
        eventHandlingTask = Task {
            for await events in await analyzer.events.stream {
                if events.contains(.requestDocumentSide(side: .back)) {
                    firstSideScanned()
                    cancelTooltipTimer()
                }
                else if events.contains(.requestDocumentSide(side: .passport(.none))) {
                    passportSideScanned(.none)
                    cancelTooltipTimer()
                }
                else if events.contains(.requestDocumentSide(side: .passport(.right90))) {
                    passportSideScanned(.right90)
                    cancelTooltipTimer()
                }
                else if events.contains(.requestDocumentSide(side: .passport(.left90))) {
                    passportSideScanned(.left90)
                    cancelTooltipTimer()
                }
                else if events.contains(.requestDocumentSide(side: .barcode)) {
                    self.setReticleState(.barcode, force: true)
                } else if events.contains(.wrongSide) {
                    self.setReticleState(.error("mb_scanning_wrong_side"))
                } else if events.contains(.wrongSidePassport(passportOrientation: .none)) {
                    self.setReticleState(.error("mb_scanning_wrong_page_top"))
                }
                else if events.contains(.wrongSidePassport(passportOrientation: .left90)) {
                    self.setReticleState(.error("mb_scanning_wrong_page_left"))
                }
                else if events.contains(.wrongSidePassport(passportOrientation: .right90)) {
                    self.setReticleState(.error("mb_scanning_wrong_page_right"))
                }
                else if events.contains(.tooClose) {
                    self.setReticleState(.error("mb_move_farther"))
                } else if events.contains(.tooFar) {
                    self.setReticleState(.error("mb_move_closer"))
                } else if events.contains(.tooCloseToEdge) {
                    self.setReticleState(.error("mb_document_too_close_to_edge"))
                } else if events.contains(.tilt) {
                    self.setReticleState(.error("mb_keep_document_parallel"))
                } else if events.contains(.glare) {
                    self.setReticleState(.error("mb_glare_detected"))
                } else if events.contains(.blur) {
                    self.setReticleState(.error("mb_blur_detected"))
                } else if events.contains(.notFullyVisible) {
                    self.setReticleState(.error("mb_document_not_fully_visible"))
                } else if events.contains(.occlusion) {
                    self.setReticleState(.error("mb_document_not_fully_visible"))
                } else if events.contains(.tooDark) {
                    self.setReticleState(.error("mb_increase_lighting_intensity"))
                } else if events.contains(.tooBright) {
                    self.setReticleState(.error("mb_decrease_lighting_intensity"))
                } else if events.contains(.facePhotoNotFullyVisible) {
                    self.setReticleState(.error("mb_face_photo_not_fully_visible"))
                }
            }
        }
    }
    
    private func firstSideScanned() {
        pauseScanning()

        let remainingTime = calculateRemainingTime()

        if remainingTime > 0 {
            timer?.invalidate()
            Timer.scheduledTimer(withTimeInterval: remainingTime, repeats: false) { [weak self] _ in
                Task {
                    await self?.animateFirstSideScanned()
                }
            }
        } else {
            Task {
                await animateFirstSideScanned()
            }
        }
    }
    
    private func passportSideScanned(_ orientation: PassportOrientation) {
        pauseScanning()

        let remainingTime = calculateRemainingTime()

        if remainingTime > 0 {
            timer?.invalidate()
            Timer.scheduledTimer(withTimeInterval: remainingTime, repeats: false) { [weak self] _ in
                Task {
                    await self?.animateFirstSidePassportScanned(orientation)
                }
            }
        } else {
            Task {
                await animateFirstSidePassportScanned(orientation)
            }
        }
    }
    
    // - MARK: Animations

    private func animateFirstSideScanned() async {
        showSuccessImage = true
        setReticleState(.inactive, force: true)

        withAnimation(.easeOutExpo(duration: successImageAnimationDuration)) {
            successImageScale = 1.0
        }

        try? await Task.sleep(for: .seconds(successImageAnimationDuration))

        withAnimation(.linear(duration: 0.2)) {
            showSuccessImage = false
        }

        try? await Task.sleep(for: .seconds(0.2))

        // Reset and prepare for card flip
        successImageScale = 0.0
        setReticleState(.flip, force: true)
        showCardImage = true

        withAnimation(.easeIn(duration: flipCardDuration/2)) {
            flipCardScale = 0.9
        }

        withAnimation(.easeInOut(duration: flipCardDuration)) {
            flipCardDegrees = 0.0
        }

        try? await Task.sleep(for: .seconds(flipCardDuration/2))

        cardImage = Image.backIdImage

        withAnimation(.easeOut(duration: flipCardDuration/2)) {
            flipCardScale = 1.0
        }

        try? await Task.sleep(for: .seconds(flipCardDuration/2 + 0.2))

        showCardImage = false
        cardImage = Image.frontIdImage
        flipCardDegrees = 180.0
        resumeScanning()
        setReticleState(.back, force: true)
    }
    
    private func animateSuccess() async {
        showSuccessImage = true
        self.setReticleState(.inactive, force: true)

        withAnimation(.easeOutExpo(duration: successImageAnimationDuration)) {
            successImageScale = 1.0
        }

        self.showRippleView = true
        withAnimation(.easeOut(duration: rippleViewAnimationDuration)) {
            self.rippleViewScale = 10.0
            self.rippleViewOpacity = 0.0
        }
        
        try? await Task.sleep(for: .seconds(max(successImageAnimationDuration, rippleViewAnimationDuration)))
    }
    
    /// Completes the scanning process.
    /// Stops frame analysis and triggers success animations.
    public func finishScan() async {
        pauseScanning()
        
        let remainingTime = calculateRemainingTime()
        
        if remainingTime > 0 {
            try? await Task.sleep(for: .seconds(remainingTime))
            await animateSuccess()
        } else {
            await animateSuccess()
        }
    }
    
    // Passport
    
    private func animateFirstSidePassportScanned(_ orientation: PassportOrientation) async {
        showSuccessImage = true
        passportOrientation = orientation
        switch orientation {
        case .none:
            setReticleState(.inactiveWithMessage("mb_instructions_turn_page_top".localizedString), force: true)
        case .left90:
            setReticleState(.inactiveWithMessage("mb_instructions_turn_page_left".localizedString), force: true)
        case .right90:
            setReticleState(.inactiveWithMessage("mb_instructions_turn_page_right".localizedString), force: true)
        }
        
        withAnimation(.easeOutExpo(duration: successImageAnimationDuration)) {
            successImageScale = 1.0
        }

        try? await Task.sleep(for: .seconds(successImageAnimationDuration))

        withAnimation(.linear(duration: 0.2)) {
            showSuccessImage = false
        }

        try? await Task.sleep(for: .seconds(0.2))
        
        showPassportAnimation = true
        isPassportAnimating = true
        
        // Wait for first part to complete
        try? await Task.sleep(for: .seconds(passportAnimationDuration * passportRelativeDuration))
        
        // Second part - change opacities
        withAnimation(.easeInOut(duration: passportAnimationDuration * passportRelativeDuration)) {
            self.topImageOpacity = self.passportEndAnimationAlpha
            self.bottomImageOpacity = self.passportBeginAnimationAlpha
        }
        
        // Wait for second part plus delay
        try? await Task.sleep(for: .seconds(passportAnimationDuration * passportRelativeDuration + 2.0))
        
        showPassportAnimation = false
        
        resumeScanning()
        switch orientation {
        case .none:
            setReticleState(.passport("mb_top_page_instructions".localizedString), force: true)
        case .left90:
            setReticleState(.passport("mb_left_page_instructions".localizedString), force: true)
        case .right90:
            setReticleState(.passport("mb_right_page_instructions".localizedString), force: true)
        }
    }
}
