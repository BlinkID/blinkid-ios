//
//  ViewController.swift
//  pdf417-sample-Swift
//
//  Created by Dino on 17/12/15.
//  Copyright © 2015 Dino. All rights reserved.
//

import UIKit

class ViewController: UIViewController, PPScanDelegate {

    var rawOcrParserId: String = "Raw ocr"
    var priceParserId: String = "Price"

    override func viewDidLoad() {
        super.viewDidLoad()
    }

    private func coordinatorWithError(error: NSErrorPointer) -> PPCoordinator? {

        /** 0. Check if scanning is supported */

        if PPCoordinator.isScanningUnsupportedForCameraType(PPCameraType.Back, error: error) {
            return nil;
        }


        /** 1. Initialize the Scanning settings */

         // Initialize the scanner settings object. This initialize settings with all default values.
        let settings: PPSettings = PPSettings()


        /** 2. Setup the license key */

        // Visit www.microblink.com to get the license key for your app
        settings.licenseSettings.licenseKey = "4ZNLNHRJ-73NI2AZP-TEDJ2EUF-F6MQXA27-UB3BBWNO-PMUHWKD3-FB5SQ6ZI-ONXANUK7"


        /**
         * 3. Set up what is being scanned. See detailed guides for specific use cases.
         * Here's an example for initializing PDF417 scanning
         */

        // To specify we want to perform PDF417 recognition, initialize the PDF417 recognizer settings
        let ocrRecognizerSettings: PPPdf417RecognizerSettings = PPPdf417RecognizerSettings()

        // Add PDF417 Recognizer setting to a list of used recognizer settings
        settings.scanSettings.addRecognizerSettings(ocrRecognizerSettings)

        // To specify we want to perform recognition of other barcode formats, initialize the ZXing recognizer settings
        let zxingRecognizerSettings: PPZXingRecognizerSettings = PPZXingRecognizerSettings()
        zxingRecognizerSettings.scanQR=true // we use just QR code

        // Add ZXingRecognizer setting to a list of used recognizer settings
        settings.scanSettings.addRecognizerSettings(zxingRecognizerSettings)


        /** 4. Initialize the Scanning Coordinator object */

        let coordinator: PPCoordinator = PPCoordinator(settings: settings)

        return coordinator
    }

    @IBAction func didTapScan(sender: AnyObject) {

        /** Instantiate the scanning coordinator */
        let error: NSErrorPointer = nil
        let coordinator:PPCoordinator? = self.coordinatorWithError(error)

        /** If scanning isn't supported, present an error */
        if coordinator == nil {
            let messageString: String = (error.memory?.localizedDescription)!
            UIAlertView(title: "Warning", message: messageString, delegate: nil, cancelButtonTitle: "Ok").show()
            return
        }

        /** Allocate and present the scanning view controller */
        let scanningViewController: UIViewController = coordinator!.cameraViewControllerWithDelegate(self)

        /** You can use other presentation methods as well */
        self.presentViewController(scanningViewController, animated: true, completion: nil)
    }

    @IBAction func didTapScanCustomUI(sender: AnyObject) {
        let error : NSErrorPointer = nil
        let coordinator : PPCoordinator? = self.coordinatorWithError(error)

        if(coordinator == nil) {
            let messageString: String = (error.memory?.localizedDescription)!
            UIAlertView(title: "Warning", message: messageString, delegate: nil, cancelButtonTitle: "Ok").show()
            return
        }

        /** Present the scanning view controller */
        let overlay: PPCameraOverlayViewController = PPCameraOverlayViewController(nibName: "PPCameraOverlayViewController",bundle: nil)
        let scanningViewController: UIViewController = coordinator!.cameraViewControllerWithDelegate(self,overlayViewController: overlay)

        /** You can use other presentation methods as well */
        self.presentViewController(scanningViewController, animated: true, completion: nil)

    }

    func scanningViewControllerUnauthorizedCamera(scanningViewController: UIViewController) {
        // Add any logic which handles UI when app user doesn't allow usage of the phone's camera
    }

    func scanningViewController(scanningViewController: UIViewController, didFindError error: NSError) {
        // Can be ignored. See description of the method
    }

    func scanningViewControllerDidClose(scanningViewController: UIViewController) {

        // As scanning view controller is presented full screen and modally, dismiss it
        self.dismissViewControllerAnimated(true, completion: nil)
    }

    func scanningViewController(scanningViewController: UIViewController?, didOutputResults results: [PPRecognizerResult]) {

        let scanConroller: PPScanningViewController = scanningViewController as! PPScanningViewController

        // Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.

        // first, pause scanning until we process all the results
        scanConroller.pauseScanning()

        var message: String = ""
        var title: String = ""


        // Collect data from the result
        for result in results {
            if(result.isKindOfClass(PPPdf417RecognizerResult)) {
                let pdf417Result: PPPdf417RecognizerResult = result as! PPPdf417RecognizerResult
                title = "PDF417"
                message = pdf417Result.stringUsingGuessedEncoding()
            }
            if(result.isKindOfClass(PPZXingRecognizerSettings)) {
                let zxingResult: PPZXingRecognizerResult = result as! PPZXingRecognizerResult
                title = "QR code"
                message=zxingResult.stringUsingGuessedEncoding()
            }
        }
        // present the alert view with scanned results
        let alertView: UIAlertView = UIAlertView.init(title: title, message: message, delegate: self, cancelButtonTitle: "OK")
        alertView.show()
    }

    // dismiss the scanning view controller when user presses OK.
    func alertView(alertView: UIAlertView, clickedButtonAtIndex buttonIndex: Int) {
        self.dismissViewControllerAnimated(true, completion: nil)
    }
}


