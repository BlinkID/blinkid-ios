//
//  ViewController.swift
//  Templating-sample-swift
//
//  Created by Jura Skrlec on 10/05/2018.
//  Copyright © 2018 Microblink. All rights reserved.
//

import UIKit
import MicroBlink

class ViewController: UIViewController {
    
    var croatianIDFrontTemplateRecognizer: MBCroatianIDFrontTemplateRecognizer?

    @IBAction func scanButtonTapped(_ sender: Any) {
        
        croatianIDFrontTemplateRecognizer = MBCroatianIDFrontTemplateRecognizer()
        let settings = MBBarcodeOverlaySettings()
        var recognizers = [MBRecognizer]()
        recognizers.append((croatianIDFrontTemplateRecognizer?.detectorRecognizer)!)
        /** Create recognizer collection */
        let recognizerCollection = MBRecognizerCollection(recognizers: recognizers)
        let overlayVC = MBBarcodeOverlayViewController(settings: settings, recognizerCollection: recognizerCollection, delegate: self)
        let recognizerRunnerViewController: (UIViewController & MBRecognizerRunnerViewController)? = MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: overlayVC)
        
        self.present(recognizerRunnerViewController!, animated: true, completion: nil)
    }
}

extension ViewController: MBBarcodeOverlayViewControllerDelegate {
    
    func barcodeOverlayViewControllerDidFinishScanning(_ barcodeOverlayViewController: MBBarcodeOverlayViewController, state: MBRecognizerResultState) {
        
        if state == MBRecognizerResultState.valid {
            barcodeOverlayViewController.recognizerRunnerViewController?.pauseScanning()
            
            DispatchQueue.main.async(execute: {() -> Void in
                let alert = UIAlertController(title: "Croatian ID Front", message: self.croatianIDFrontTemplateRecognizer?.resultDescription(), preferredStyle: .alert)
                let defaultAction = UIAlertAction(title: "OK", style: .default, handler: {(_ action: UIAlertAction?) -> Void in
                    barcodeOverlayViewController.dismiss(animated: true) {() -> Void in }
                })
                alert.addAction(defaultAction)
                barcodeOverlayViewController.present(alert, animated: true) {() -> Void in }
            })
        }
    }
    
    func barcodeOverlayViewControllerDidTapClose(_ barcodeOverlayViewController: MBBarcodeOverlayViewController) {
        self.dismiss(animated: true, completion: nil)
    }
}

