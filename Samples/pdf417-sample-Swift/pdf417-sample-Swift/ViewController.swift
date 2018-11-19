//
//  ViewController.swift
//  pdf417-sample-Swift
//
//  Created by Dino on 17/12/15.
//  Copyright © 2015 Dino. All rights reserved.
//

import UIKit
import MicroBlink

class ViewController: UIViewController {
    
    var pdf417Recognizer : MBPdf417Recognizer?
    var barcodeRecognizer : MBBarcodeRecognizer?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Valid until: 2019-02-07
        MBMicroblinkSDK.sharedInstance().setLicenseResource("blinkid-license", withExtension: "txt", inSubdirectory: "", for: Bundle.main)
    }
    
    @IBAction func didTapCustomUI(_ sender: Any) {
        
        /** Create barcode recognizer */
        self.barcodeRecognizer = MBBarcodeRecognizer()
        self.barcodeRecognizer?.scanQrCode = true
        
        self.pdf417Recognizer = MBPdf417Recognizer()
        
        /** Crate recognizer collection */
        let recognizerList = [self.barcodeRecognizer!, self.pdf417Recognizer!]
        let recognizerCollection : MBRecognizerCollection = MBRecognizerCollection(recognizers: recognizerList)
        
        /** Create your overlay view controller */
        let customOverlayViewController : CustomOverlay = CustomOverlay.initFromStoryboardWith()
        
        /** This has to be called for custom controller */
        customOverlayViewController.reconfigureRecognizers(recognizerCollection)
        
        /** Create recognizer view controller with wanted overlay view controller */
        let recognizerRunneViewController : UIViewController = MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: customOverlayViewController)
        
        /** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
        self.present(recognizerRunneViewController, animated: true, completion: nil)
    }
    @IBAction func didTapScan(_ sender: AnyObject) {
        
        /** Create barcode recognizer */
        self.barcodeRecognizer = MBBarcodeRecognizer()
        self.barcodeRecognizer?.scanQrCode = true
        
        self.pdf417Recognizer = MBPdf417Recognizer()
        
        /** Create barcode settings */
        let settings : MBBarcodeOverlaySettings = MBBarcodeOverlaySettings()
        
        /** Crate recognizer collection */
        let recognizerList = [self.barcodeRecognizer!, self.pdf417Recognizer!]
        let recognizerCollection : MBRecognizerCollection = MBRecognizerCollection(recognizers: recognizerList)
        
        /** Create your overlay view controller */
        let barcodeOverlayViewController : MBBarcodeOverlayViewController = MBBarcodeOverlayViewController(settings: settings, recognizerCollection: recognizerCollection, delegate: self)
        
        /** Create recognizer view controller with wanted overlay view controller */
        let recognizerRunneViewController : UIViewController = MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: barcodeOverlayViewController)
        
        /** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
        self.present(recognizerRunneViewController, animated: true, completion: nil)
    }
}

extension ViewController: MBBarcodeOverlayViewControllerDelegate {
    
    func barcodeOverlayViewControllerDidFinishScanning(_ barcodeOverlayViewController: MBBarcodeOverlayViewController, state: MBRecognizerResultState) {
        /** This is done on background thread */
        barcodeOverlayViewController.recognizerRunnerViewController?.pauseScanning()
        
        var message: String = ""
        var title: String = ""
        
        if (self.barcodeRecognizer!.result.resultState == MBRecognizerResultState.valid) {
            title = "QR Code"
            
            // Save the string representation of the code
            message = self.barcodeRecognizer!.result.stringData!
        }
        else if (self.pdf417Recognizer!.result.resultState == MBRecognizerResultState.valid) {
            title = "PDF417"
            
            // Save the string representation of the code
            message = self.pdf417Recognizer!.result.stringData!
        }
        
        /** Needs to be called on main thread beacuse everything prior is on background thread */
        DispatchQueue.main.async {
            // present the alert view with scanned results
            
            let alertController: UIAlertController = UIAlertController.init(title: title, message: message, preferredStyle: UIAlertControllerStyle.alert)
            
            let okAction: UIAlertAction = UIAlertAction.init(title: "OK", style: UIAlertActionStyle.default,
                                                             handler: { (action) -> Void in
                                                                self.dismiss(animated: true, completion: nil)
            })
            alertController.addAction(okAction)
            barcodeOverlayViewController.present(alertController, animated: true, completion: nil)
        }
    }
    
    func barcodeOverlayViewControllerDidTapClose(_ barcodeOverlayViewController: MBBarcodeOverlayViewController) {
        self.dismiss(animated: true, completion: nil)
    }
}

