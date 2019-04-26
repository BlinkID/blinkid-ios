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
        // Valid until: 2019-07-03
        MBMicroblinkSDK.sharedInstance().setLicenseResource("blinkid-license", withExtension: "txt", inSubdirectory: "", for: Bundle.main)
    }

    @IBAction func didTapScan(_ sender: AnyObject) {
        
        // To specify we want to perform MRTD (machine readable travel document) recognition, initialize the MRTD recognizer settings
        self.mrtdRecognizer = MBMrtdRecognizer()
        self.mrtdRecognizer?.returnFullDocumentImage = true;
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
            
            let fullDocumentImage: UIImage! = self.mrtdRecognizer?.result.fullDocumentImage?.image
            print("Got MRTD image with width: \(fullDocumentImage.size.width), height: \(fullDocumentImage.size.height)")
            
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
            
            let fullDocumentImage: UIImage! = self.eudlRecognizer?.result.fullDocumentImage?.image
            print("Got EUDL image with width: \(fullDocumentImage.size.width), height: \(fullDocumentImage.size.height)")
            
            // Save the string representation of the code
            message = (self.eudlRecognizer?.result.description)!
        }
        
        /** Needs to be called on main thread beacuse everything prior is on background thread */
        DispatchQueue.main.async {
            // present the alert view with scanned results
            
            let alertController: UIAlertController = UIAlertController.init(title: title, message: message, preferredStyle: UIAlertController.Style.alert)
            
            let okAction: UIAlertAction = UIAlertAction.init(title: "OK", style: UIAlertAction.Style.default,
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



