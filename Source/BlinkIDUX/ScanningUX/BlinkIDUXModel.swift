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
public final class BlinkIDUXModel: ScanningViewModel<BlinkIDScanningResult, UIEvent, ReticleStateMachine, BlinkIDScanningAlertType> {
    
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
    
    public init(analyzer: any CameraFrameAnalyzer<CameraFrame, UIEvent>, uxSettings: ScanningUXSettings = ScanningUXSettings()) {
        self.topImageOpacity = passportBeginAnimationAlpha
        self.bottomImageOpacity = passportEndAnimationAlpha
        self.highlightOffset = 0
        self.passportOrientation = nil
        super.init(analyzer: analyzer, uxSettings: uxSettings, reticleStateMachine: ReticleStateMachine(), firstSideFinishedText: "mb_accessibility_success_first_side_scanned".localizedString, scanFinishedText: "mb_accessibility_success_document_scanned".localizedString)
        
        startEventHandling()
        camera.$status
            .sink { [weak self] _ in
                self?.objectWillChange.send()
            }
            .store(in: &cancellables)
    }
    
    // MARK: - Protocol Implementation
    
    public override func processAnalyzerResult() async {
        let result = await analyzer.result()
        if let scanningResult = result as? ScanningResult<BlinkIDScanningResult, BlinkIDScanningAlertType> {
            switch scanningResult {
            case .completed(let scanningResult):
                await finishScan()
                self.result = BlinkIDResultState(scanningResult: scanningResult)
            case .interrupted(let alertType):
                self.alertType = alertType
            case .cancelled:
                showLicenseErrorAlert = true
            case .ended:
                self.result = BlinkIDResultState(scanningResult: nil)
            }
        }
    }
    
    public override func timeoutAlertDismised() {
        super.timeoutAlertDismised()
        
        topImageOpacity = passportBeginAnimationAlpha
        bottomImageOpacity = passportEndAnimationAlpha
        highlightOffset = 0
        passportOrientation = nil
    }
    
    // - MARK: - Handle UIEvents

    private func startEventHandling() {
        eventHandlingTask = Task {
            for await events in await analyzer.events.stream {
                if events.contains(.requestDocumentSide(side: .back)) {
                    firstSideScanned(frontFlipImage: Image.frontIdImage, backFlipImage: Image.backIdImage, flipState: .flip, nextState: .back)
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
                else if events.contains(.requestDocumentSide(side: .passportBarcode)) {
                    passportWithBarcodeSideScanned()
                    cancelTooltipTimer()
                }
                else if events.contains(.requestDocumentSide(side: .barcode)) {
                    self.setReticleState(.barcode, force: true)
                    startTooltipTimer()
                } else if events.contains(.wrongSide) {
                    self.setReticleState(.error("mb_scanning_wrong_side"))
                    self.trackErrorMessage(.flipside)
                } else if events.contains(.wrongSidePassportWithBarcode) {
                    self.setReticleState(.error("mb_instructions_scan_barcode_last_page"))
                    self.trackErrorMessage(.flipside)
                } else if events.contains(.wrongSidePassport(passportOrientation: .none)) {
                    self.setReticleState(.error("mb_scanning_wrong_page_top"))
                    self.trackErrorMessage(.flipside)
                }
                else if events.contains(.wrongSidePassport(passportOrientation: .left90)) {
                    self.setReticleState(.error("mb_scanning_wrong_page_left"))
                    self.trackErrorMessage(.flipside)
                }
                else if events.contains(.wrongSidePassport(passportOrientation: .right90)) {
                    self.setReticleState(.error("mb_scanning_wrong_page_right"))
                    self.trackErrorMessage(.flipside)
                }
                else if events.contains(.tooClose) {
                    self.setReticleState(.error("mb_move_farther"))
                    self.trackErrorMessage(.movefarther)
                } else if events.contains(.tooFar) {
                    self.setReticleState(.error("mb_move_closer"))
                    self.trackErrorMessage(.movecloser)
                } else if events.contains(.tooCloseToEdge) {
                    self.setReticleState(.error("mb_move_farther"))
                    self.trackErrorMessage(.movefromedge)
                } else if events.contains(.tilt) {
                    self.setReticleState(.error("mb_keep_document_parallel"))
                    self.trackErrorMessage(.aligndocument)
                } else if events.contains(.glare) {
                    self.setReticleState(.error("mb_glare_detected"))
                    self.trackErrorMessage(.eliminateglare)
                } else if events.contains(.blur) {
                    self.setReticleState(.error("mb_blur_detected"))
                    self.trackErrorMessage(.eliminateblur)
                } else if events.contains(.notFullyVisible) {
                    self.setReticleState(.error("mb_document_not_fully_visible"))
                    self.trackErrorMessage(.keepvisible)
                } else if events.contains(.occlusion) {
                    self.setReticleState(.error("mb_document_not_fully_visible"))
                    self.trackErrorMessage(.keepvisible)
                } else if events.contains(.tooDark) {
                    self.setReticleState(.error("mb_increase_lighting_intensity"))
                    self.trackErrorMessage(.increaselighting)
                } else if events.contains(.tooBright) {
                    self.setReticleState(.error("mb_decrease_lighting_intensity"))
                    self.trackErrorMessage(.decreaselighting)
                } else if events.contains(.facePhotoNotFullyVisible) {
                    self.setReticleState(.error("mb_face_photo_not_fully_visible"))
                    self.trackErrorMessage(.keepvisible)
                } else {
                    self.setReticleState(reticleStateMachine.fallbackState)
                }
            }
        }
    }
        
    private func passportSideScanned(_ orientation: PassportOrientation) {
        pauseScanning()

        let remainingTime = reticleStateMachine.calculateRemainingTime(stateDuration: 1.0)

        if remainingTime > 0 {
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
    
    private func passportWithBarcodeSideScanned() {
        pauseScanning()

        let remainingTime = reticleStateMachine.calculateRemainingTime(stateDuration: 1.0)

        if remainingTime > 0 {
            Timer.scheduledTimer(withTimeInterval: remainingTime, repeats: false) { [weak self] _ in
                Task {
                    await self?.animateFirstSidePassportWithBarcodeScanned()
                }
            }
        } else {
            Task {
                await animateFirstSidePassportWithBarcodeScanned()
            }
        }
    }
    
    // - MARK: Animations
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
    
    private func animateFirstSidePassportWithBarcodeScanned() async {
        showSuccessImage = true
        
        withAnimation(.easeOutExpo(duration: successImageAnimationDuration)) {
            successImageScale = 1.0
        }

        try? await Task.sleep(for: .seconds(successImageAnimationDuration))

        withAnimation(.linear(duration: 0.2)) {
            showSuccessImage = false
        }
        
        resumeScanning()
        setReticleState(.passport("mb_instructions_scan_barcode_last_page".localizedString), force: true)
    }
}
