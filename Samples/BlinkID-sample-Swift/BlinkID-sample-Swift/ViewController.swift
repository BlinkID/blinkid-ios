//
//  ViewController.swift
//  BlinkID-sample-Swift
//
//  Created by Dino on 22/12/15.
//  Copyright © 2015 Dino. All rights reserved.
//

import UIKit
import MicroBlink

class ViewController: UIViewController, PPScanningDelegate {

    /**
     * Method allocates and initializes the Scanning coordinator object.
     * Coordinator is initialized with settings for scanning
     * Modify this method to include only those recognizer settings you need. This will give you optimal performance
     *
     *  @param error Error object, if scanning isn't supported
     *
     *  @return initialized coordinator
     */
    func coordinatorWithError(error: NSErrorPointer) -> PPCameraCoordinator? {

        /** 0. Check if scanning is supported */

        if (PPCameraCoordinator.isScanningUnsupported(for: PPCameraType.back, error: error)) {
            return nil;
        }


        /** 1. Initialize the Scanning settings */

         // Initialize the scanner settings object. This initialize settings with all default values.
        let settings: PPSettings = PPSettings()


        /** 2. Setup the license key */

        // Visit www.microblink.com to get the license key for your app
        settings.licenseSettings.licenseKey = "Q3MUZMW7-RLAQ3GGN-RV5POQX7-K6QZMUGK-QGSWZUHQ-ZHDRPRQQ-HY5BYJCP-G5A7LMI4"
        // License key is valid temporarily until 2017-05-01


        /**
        * 3. Set up what is being scanned. See detailed guides for specific use cases.
        * Remove undesired recognizers (added below) for optimal performance.
        */

        do { // Remove this if you're not using MRTD recognition

            // To specify we want to perform MRTD (machine readable travel document) recognition, initialize the MRTD recognizer settings
            let mrtdRecognizerSettings = PPMrtdRecognizerSettings()

            /** You can modify the properties of mrtdRecognizerSettings to suit your use-case */

            // tell the library to get full image of the document. Setting this to YES makes sense just if
            // settings.metadataSettings.dewarpedImage = YES, otherwise it wastes CPU time.
            mrtdRecognizerSettings.dewarpFullDocument = false;

            // Add MRTD Recognizer setting to a list of used recognizer settings
            settings.scanSettings.add(mrtdRecognizerSettings)
        }

        do { // Remove this if you're not using USDL recognition

            // To specify we want to perform USDL (US Driver's license) recognition, initialize the USDL recognizer settings
            let usdlRecognizerSettings = PPUsdlRecognizerSettings()

            /** You can modify the properties of usdlRecognizerSettings to suit your use-case */

            // Add USDL Recognizer setting to a list of used recognizer settings
            settings.scanSettings.add(usdlRecognizerSettings)
        }

        do { // Remove this if you're not using UKDL recognition

            // To specify we want to perform UKDL (UK Driver's license) recognition, initialize the UKDL recognizer settings
            let eudlRecognizerSettings = PPEudlRecognizerSettings()

            /** You can modify the properties of ukdlRecognizerSettings to suit your use-case */

            // If you want to save the image of the UKDL, set this to YES
            eudlRecognizerSettings.showFullDocument = true;

            // Add UKDL Recognizer setting to a list of used recognizer settings
            settings.scanSettings.add(eudlRecognizerSettings)
        }

        do { // Remove this if you're not using MyKad recognition

            // To specify we want to perform MyKad recognition, initialize the MyKad recognizer settings
            let myKadRecognizerSettings = PPMyKadRecognizerSettings()
            
            /** You can modify the properties of myKadRecognizerSettings to suit your use-case */
            
            // Add UKDL Recognizer setting to a list of used recognizer settings
            settings.scanSettings.add(myKadRecognizerSettings)
        }

        // DISABLE this if you don't need to store images to improve performance!
        settings.metadataSettings.dewarpedImage = true

        /** 4. Initialize the Scanning Coordinator object */

        let coordinator: PPCameraCoordinator = PPCameraCoordinator(settings: settings, delegate: nil)

        return coordinator
    }

    @IBAction func didTapScan(_ sender: AnyObject) {

        /** Instantiate the scanning coordinator */
        let error: NSErrorPointer = nil
        let coordinator = self.coordinatorWithError(error: error)

        /** If scanning isn't supported, present an error */
        if coordinator == nil {
            let messageString: String = (error!.pointee?.localizedDescription) ?? ""
            UIAlertView(title: "Warning", message: messageString, delegate: nil, cancelButtonTitle: "Ok").show()
            return
        }

        /** Allocate and present the scanning view controller */
        let scanningViewController: UIViewController = PPViewControllerFactory.cameraViewController(with: self, coordinator: coordinator!, error: nil)

        /** Allow autorotation - if it makes sense for your use case */
        let scanController = scanningViewController as! PPScanningViewController
        scanController.autorotate = true
        scanController.supportedOrientations = UIInterfaceOrientationMask.all

        /** You can use other presentation methods as well */
        self.present(scanningViewController, animated: true, completion: nil)
    }

    func scanningViewControllerUnauthorizedCamera(_ scanningViewController: UIViewController) {
        // Add any logic which handles UI when app user doesn't allow usage of the phone's camera
    }

    func scanningViewController(scanningViewController: UIViewController, didFindError error: NSError) {
        // Can be ignored. See description of the method
    }
    
    public func scanningViewController(_ scanningViewController: UIViewController, didFindError error: Error) {
        // Can be ignored
    }

    func scanningViewControllerDidClose(_ scanningViewController: UIViewController) {
        // As scanning view controller is presented full screen and modally, dismiss it
        self.dismiss(animated: true, completion: nil)
    }
    

    func scanningViewController(_ scanningViewController: UIViewController?, didOutputResults results: [PPRecognizerResult]) {

        // return if we don't have any results
        if (results.count == 0) {
            return
        }

        let scanController = scanningViewController as! PPScanningViewController

        /**
         * Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.
         * Each member of results array will represent one result for a single processed image
         * Usually there will be only one result. Multiple results are possible when there are 2 or more detected objects on a single image (i.e. pdf417 and QR code side by side)
         */

        // first, pause scanning until we process all the results
        scanController.pauseScanning()

        var message = ""
        var title = ""

        // Collect data from the result
        for result in results {

            title = "Scan result"
            message = result.description

            if (result is PPMrtdRecognizerResult) {
                /** MRTD was detected */
                let mrtdResult = result as! PPMrtdRecognizerResult
                title = "MRTD"
                message = mrtdResult.description
            }
            if (result is PPUsdlRecognizerResult) {
                /** US drivers license was detected */
                let usdlResult = result as! PPUsdlRecognizerResult
                title = "USDL"
                message = usdlResult.description
            }
            if (result is PPEudlRecognizerResult) {
                /** EU drivers license was detected */
                let eudlResult = result as! PPEudlRecognizerResult
                title = "EUDL"
                message = eudlResult.description
            }
            if (result is PPMyKadRecognizerResult) {
                /** MyKad was detected */
                let myKadResult = result as! PPMyKadRecognizerResult
                title = "MyKad"
                message = myKadResult.description
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

    func scanningViewController(_ scanningViewController: UIViewController?, didOutputMetadata metadata: PPMetadata) {
        
        if (metadata is PPImageMetadata) {

            let result: PPImageMetadata = metadata as! PPImageMetadata

            let image: UIImage = result.image()

            print("result \(image)")

            if (result.name == PPEudlRecognizerSettings.full_DOCUMENT_IMAGE()) {
                print("This image is EUDL full document");
            } else if (result.name == PPMrtdRecognizerSettings.full_DOCUMENT_IMAGE()) {
                print("This image is full Machine readable travel document");
            } else if (result.name == PPMrtdRecognizerSettings.mrz_IMAGE()) {
                print("This image is Machine readable zone");
            } else if (result.name == PPMyKadRecognizerSettings.full_DOCUMENT_IMAGE()) {
                print("This image is full MyKad");
            }
        }
    }

    // dismiss the scanning view controller when user presses OK.
    
    func alertView(alertView: UIAlertView, clickedButtonAtIndex buttonIndex: Int) {
        self.dismiss(animated: true, completion: nil)
    }
}


