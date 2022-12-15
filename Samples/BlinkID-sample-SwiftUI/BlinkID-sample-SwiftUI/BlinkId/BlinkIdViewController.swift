// Created by Jura Skrlec on 23/12/2020.
// Copyright (c) 2020 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import Foundation
import SwiftUI
import BlinkID

struct BlinkIdViewController: UIViewControllerRepresentable {
    @Environment(\.presentationMode) var presentationMode
    @Binding var showAlert: Bool
    @Binding var blinkIdMultiSideRecognizer: MBBlinkIdMultiSideRecognizer
    class Coordinator: NSObject, MBBlinkIdOverlayViewControllerDelegate {
        
        var parent: BlinkIdViewController
        
        init(_ parent: BlinkIdViewController) {
            self.parent = parent
        }
        
        func blinkIdOverlayViewControllerDidFinishScanning(_ blinkIdOverlayViewController: MBBlinkIdOverlayViewController, state: MBRecognizerResultState) {
            blinkIdOverlayViewController.recognizerRunnerViewController?.pauseScanning()
            
            if state == .valid {
                parent.showAlert = true
            }
        }
        
        func blinkIdOverlayViewControllerDidTapClose(_ blinkIdOverlayViewController: MBBlinkIdOverlayViewController) {
            parent.presentationMode.wrappedValue.dismiss()
        }
    }
    
    func makeCoordinator() -> Coordinator {
        Coordinator(self)
    }
    
    func makeUIViewController(context: Context) -> some UIViewController {
        blinkIdMultiSideRecognizer.returnFullDocumentImage = true

        /** Create settings */
        let settings: MBBlinkIdOverlaySettings = MBBlinkIdOverlaySettings()

        /** Crate recognizer collection */
        let recognizerList = [blinkIdMultiSideRecognizer]
        let recognizerCollection: MBRecognizerCollection = MBRecognizerCollection(recognizers: recognizerList)

        /** Create your overlay view controller */
        let blinkIdOverlayViewController: MBBlinkIdOverlayViewController =
            MBBlinkIdOverlayViewController(settings: settings, recognizerCollection: recognizerCollection, delegate: context.coordinator)

        /** Create recognizer view controller with wanted overlay view controller */
        let recognizerRunneViewController: UIViewController =
            MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: blinkIdOverlayViewController)!
        
        return recognizerRunneViewController
    }
    
    func updateUIViewController(_ uiViewController: UIViewControllerType, context: Context) {
        
    }
    
}
