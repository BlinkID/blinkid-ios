//
//  CustomOverlay.swift
//  pdf417-sample-Swift
//
//  Created by Dino Gustin on 06/03/2018.
//  Copyright © 2018 Dino. All rights reserved.
//

import MicroBlink

class CustomOverlay: MBCustomOverlayViewController, MBScanningRecognizerRunnerViewControllerDelegate {
    
    static func initFromStoryboardWith() -> CustomOverlay {
        let customOverlay: CustomOverlay = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "CustomOverlay") as! CustomOverlay
        return customOverlay
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        super.scanningRecognizerRunnerViewControllerDelegate = self;
    }
    
    func recognizerRunnerViewController(_ recognizerRunnerViewController: UIViewController & MBRecognizerRunnerViewController, didFinishScanningWith state: MBRecognizerResultState) {
        /** This is done on background thread */
        if state == MBRecognizerResultState.valid {
            recognizerRunnerViewController.pauseScanning();
            
            DispatchQueue.main.async {
                
                var message: String = ""
                var title: String = ""
                
                for recognizer in self.recognizerCollection.recognizerList {
                    if ( recognizer.baseResult?.resultState == MBRecognizerResultState.valid ) {
                        if recognizer is MBBarcodeRecognizer {
                            let barcodeRecognizer = recognizer as? MBBarcodeRecognizer
                            title = "QR Code"
                            message = (barcodeRecognizer?.result.stringData!)!
                        }
                        else if recognizer is MBPdf417Recognizer {
                            let pdf417Recognizer = recognizer as? MBPdf417Recognizer
                            title = "PDF417"
                            message = (pdf417Recognizer?.result.stringData!)!
                        }
                    }
                }
                
                let alertController: UIAlertController = UIAlertController.init(title: title, message: message, preferredStyle: UIAlertController.Style.alert)
                
                let okAction: UIAlertAction = UIAlertAction.init(title: "OK", style: UIAlertAction.Style.default,
                                                                 handler: { (action) -> Void in
                                                                    self.dismiss(animated: true, completion: nil)
                })
                alertController.addAction(okAction)
                self.present(alertController, animated: true, completion: nil)
            }
        }
    }

    @IBAction func didTapClose(_ sender: Any) {
        self.recognizerRunnerViewController?.overlayViewControllerWillCloseCamera(self);
        self.dismiss(animated: true, completion: nil);
    }
    
}
