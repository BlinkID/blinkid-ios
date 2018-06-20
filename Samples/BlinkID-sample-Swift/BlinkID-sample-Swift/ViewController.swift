//
//  ViewController.swift
//  BlinkID-sample-Swift
//
//  Created by Dino on 22/12/15.
//  Copyright © 2015 Dino. All rights reserved.
//

import UIKit
import MicroBlink

class ViewController: UIViewController {
    
    var mrtdRecognizer : MBMrtdRecognizer?
    var usdlRecognizer : MBUsdlRecognizer?
    var eudlRecognizer : MBEudlRecognizer?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Valid until: 2018-09-27
        MBMicroblinkSDK.sharedInstance().setLicenseResource("blinkid-swift", withExtension: "txt", inSubdirectory: "License", for: Bundle.main)
    }

    @IBAction func didTapScan(_ sender: AnyObject) {
        
        // To specify we want to perform MRTD (machine readable travel document) recognition, initialize the MRTD recognizer settings
        self.mrtdRecognizer = MBMrtdRecognizer()
        self.mrtdRecognizer?.returnFullDocumentImage = false;
        self.mrtdRecognizer?.allowUnverifiedResults = true;
        
        /** Create usdl recognizer */
        self.usdlRecognizer = MBUsdlRecognizer()

        /** Create eudl recognizer */
        self.eudlRecognizer = MBEudlRecognizer()
        self.eudlRecognizer?.returnFullDocumentImage = true
        
        /** Create barcode settings */
        let settings : MBDocumentOverlaySettings = MBDocumentOverlaySettings()
        
        /** Crate recognizer collection */
        let recognizerList = [self.mrtdRecognizer!, self.usdlRecognizer!, self.eudlRecognizer!]
        let recognizerCollection : MBRecognizerCollection = MBRecognizerCollection(recognizers: recognizerList)
        
        /** Create your overlay view controller */
        let barcodeOverlayViewController : MBDocumentOverlayViewController = MBDocumentOverlayViewController(settings: settings, recognizerCollection: recognizerCollection, delegate: self)
        
        /** Create recognizer view controller with wanted overlay view controller */
        let recognizerRunneViewController : UIViewController = MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: barcodeOverlayViewController)
        
        /** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
        self.present(recognizerRunneViewController, animated: true, completion: nil)
    }
}

extension ViewController: MBDocumentOverlayViewControllerDelegate {
    
    func documentOverlayViewControllerDidFinishScanning(_ documentOverlayViewController: MBDocumentOverlayViewController, state: MBRecognizerResultState) {
        /** This is done on background thread */
        documentOverlayViewController.recognizerRunnerViewController?.pauseScanning()
        
        var message: String = ""
        var title: String = ""
        
        if (self.mrtdRecognizer?.result.resultState == MBRecognizerResultState.valid) {
            title = "MRTD"
            
            // Save the string representation of the code
            message = self.mrtdRecognizer!.result.description
        }
        else if (self.usdlRecognizer?.result.resultState == MBRecognizerResultState.valid) {
            title = "USDL"
            
            // Save the string representation of the code
            message = (self.usdlRecognizer?.result.description)!
        }
        else if (self.eudlRecognizer?.result.resultState == MBRecognizerResultState.valid) {
            title = "EUDL"
            
            // Save the string representation of the code
            message = (self.eudlRecognizer?.result.description)!
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
            documentOverlayViewController.present(alertController, animated: true, completion: nil)
        }
    }
    
    func documentOverlayViewControllerDidTapClose(_ documentOverlayViewController: MBDocumentOverlayViewController) {
        self.dismiss(animated: true, completion: nil)
    }
}



