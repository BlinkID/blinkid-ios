//
//  ViewController.swift
//  pdf417-sample-Swift
//
//  Created by Dino on 17/12/15.
//  Copyright © 2015 Dino. All rights reserved.
//

import UIKit
import MicroBlink

class ViewController: UIViewController, PPScanningDelegate {

    override func viewDidLoad() {
        super.viewDidLoad()
    }

    /**
     * Method allocates and initializes the Scanning coordinator object.
     * Coordinator is initialized with settings for scanning
     * Modify this method to include only those recognizer settings you need. This will give you optimal performance
     *
     *  @param error Error object, if scanning isn't supported
     *
     *  @return initialized coordinator
     */
    private func coordinatorWithError(error: NSErrorPointer) -> PPCameraCoordinator? {

        /** 0. Check if scanning is supported */

        if PPCameraCoordinator.isScanningUnsupported(for: PPCameraType.back, error: error) {
            return nil;
        }


        /** 1. Initialize the Scanning settings */

         // Initialize the scanner settings object. This initialize settings with all default values.
        let settings: PPSettings = PPSettings()


        /** 2. Setup the license key */

        // Visit www.microblink.com to get the license key for your app
        settings.licenseSettings.licenseKey = "3R66F4P2-OMIURML5-VZTO6STD-ETVQPPGI-EXNJDSJQ-SHETBEOJ-GCI4TED3-EB7GYKCO"


        /**
         * 3. Set up what is being scanned. See detailed guides for specific use cases.
         * Remove undesired recognizers (added below) for optimal performance.
         */

        // Remove this code if you don't need to scan Pdf417
        do {
            // To specify we want to perform PDF417 recognition, initialize the PDF417 recognizer settings
            let ocrRecognizerSettings: PPPdf417RecognizerSettings = PPPdf417RecognizerSettings()

            /** You can modify the properties of pdf417RecognizerSettings to suit your use-case */

            // Add PDF417 Recognizer setting to a list of used recognizer settings
            settings.scanSettings.add(ocrRecognizerSettings)
        }

        // Remove this code if you don't need to scan QR codes
        do {
            // To specify we want to perform recognition of other barcode formats, initialize the ZXing recognizer settings
            let zxingRecognizerSettings: PPZXingRecognizerSettings = PPZXingRecognizerSettings()


            /** You can modify the properties of zxingRecognizerSettings to suit your use-case (i.e. add other types of barcodes like QR, Aztec or EAN)*/
            zxingRecognizerSettings.scanQR=true // we use just QR code

            // Add ZXingRecognizer setting to a list of used recognizer settings
            settings.scanSettings.add(zxingRecognizerSettings)
        }


        /** 4. Initialize the Scanning Coordinator object */

        let coordinator: PPCameraCoordinator = PPCameraCoordinator(settings: settings)

        return coordinator
    }

    @IBAction func didTapScan(_ sender: AnyObject) {

        /** Instantiate the scanning coordinator */
        let error: NSErrorPointer = nil
        let coordinator  = self.coordinatorWithError(error: error)

        /** If scanning isn't supported, present an error */
        if coordinator == nil {
            let messageString: String = (error!.pointee?.localizedDescription)!
            UIAlertView(title: "Warning", message: messageString, delegate: nil, cancelButtonTitle: "Ok").show()
            return
        }

        /** Create new scanning view controller */
        let scanningViewController: UIViewController = PPViewControllerFactory.cameraViewController(with: self, coordinator: coordinator!, error: nil)

        /** Present the scanning view controller. You can use other presentation methods as well (instead of presentViewController) */
        self.present(scanningViewController, animated: true, completion: nil)
    }

    @IBAction func didTapScanCustomUI(_ sender: AnyObject) {
        let error : NSErrorPointer = nil
        let coordinator = self.coordinatorWithError(error: error)

        if(coordinator == nil) {
            let messageString: String = (error!.pointee?.localizedDescription)!
            UIAlertView(title: "Warning", message: messageString, delegate: nil, cancelButtonTitle: "Ok").show()
            return
        }

        /** Init scanning view controller custom overlay */
        let overlay: PPCameraOverlayViewController = PPCameraOverlayViewController(nibName: "PPCameraOverlayViewController",bundle: nil)
        /** Create new scanning view controller with desired custom overlay */
        let scanningViewController: UIViewController = PPViewControllerFactory.cameraViewController(with: self, overlayViewController: overlay, coordinator: coordinator!, error: nil);

        /** Present the scanning view controller. You can use other presentation methods as well (instead of presentViewController) */
        self.present(scanningViewController, animated: true, completion: nil)

    }

    func scanningViewControllerUnauthorizedCamera(_ scanningViewController: UIViewController) {
        // Add any logic which handles UI when app user doesn't allow usage of the phone's camera
    }

    func scanningViewController(_ scanningViewController: UIViewController, didFindError error: Error) {
        // Can be ignored. See description of the method
    }

    func scanningViewControllerDidClose(_ scanningViewController: UIViewController) {

        // As scanning view controller is presented full screen and modally, dismiss it
        self.dismiss(animated: true, completion: nil)
    }

    func scanningViewController(_ scanningViewController: UIViewController?, didOutputResults results: [PPRecognizerResult]) {

        let scanConroller: PPScanningViewController = scanningViewController as! PPScanningViewController

        /**
         * Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.
         * Each member of results array will represent one result for a single processed image
         * Usually there will be only one result. Multiple results are possible when there are 2 or more detected objects on a single image (i.e. pdf417 and QR code side by side)
         */

        // first, pause scanning until we process all the results
        scanConroller.pauseScanning()

        var message: String = ""
        var title: String = ""


        // Collect data from the result
        for result in results {
            if(result is PPZXingRecognizerResult) {
                /** One of QR code was detected */

                let zxingResult = result as! PPZXingRecognizerResult

                title = "QR code"

                // Save the string representation of the code
                message = zxingResult.stringUsingGuessedEncoding()!
            }
            if(result is PPPdf417RecognizerResult) {
                /** Pdf417 code was detected */

                let pdf417Result = result as! PPPdf417RecognizerResult

                title = "PDF417"

                // Save the string representation of the code
                message = pdf417Result.stringUsingGuessedEncoding()!
            }
        }
        // present the alert view with scanned results
        
        let alertController: UIAlertController = UIAlertController.init(title: title, message: message, preferredStyle: UIAlertControllerStyle.alert)
        
        let okAction: UIAlertAction = UIAlertAction.init(title: "OK", style: UIAlertActionStyle.default,
                                                         handler: { (action) -> Void in
                                                            self.dismiss(animated: true, completion: nil)
        })
        alertController.addAction(okAction)
        scanningViewController?.present(alertController, animated: true, completion: nil)
    }

    // dismiss the scanning view controller when user presses OK.
    func alertView(alertView: UIAlertView, clickedButtonAtIndex buttonIndex: Int) {
        self.dismiss(animated: true, completion: nil)
    }
}


