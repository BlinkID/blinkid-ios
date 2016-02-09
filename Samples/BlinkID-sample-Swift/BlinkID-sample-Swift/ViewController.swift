//
//  ViewController.swift
//  BlinkID-sample-Swift
//
//  Created by Dino on 22/12/15.
//  Copyright © 2015 Dino. All rights reserved.
//

import UIKit
import MicroBlink

class ViewController: UIViewController, PPScanDelegate {

    func coordinatorWithError(error: NSErrorPointer) -> PPCoordinator? {

        /** 0. Check if scanning is supported */

        if (PPCoordinator.isScanningUnsupportedForCameraType(PPCameraType.Back, error: error)) {
            return nil;
        }


        /** 1. Initialize the Scanning settings */

         // Initialize the scanner settings object. This initialize settings with all default values.
        let settings: PPSettings = PPSettings()


        /** 2. Setup the license key */

        // Visit www.microblink.com to get the license key for your app
        settings.licenseSettings.licenseKey = "N7E2CVWA-53NU6P42-4R5PPORH-EG4IDJLM-2DYMTRYX-YYID4OQ4-QQGZRDLH-PL22BO5S"


        /**
        * 3. Set up what is being scanned. See detailed guides for specific use cases.
        * Here's an example for initializing MRTD and USDL scanning
        */

        // To specify we want to perform MRTD (machine readable travel document) recognition, initialize the MRTD recognizer settings
        let mrtdRecognizerSettings = PPMrtdRecognizerSettings()

        // Add MRTD Recognizer setting to a list of used recognizer settings
        settings.scanSettings.addRecognizerSettings(mrtdRecognizerSettings)

        // To specify we want to perform USDL (US Driver's license) recognition, initialize the USDL recognizer settings
        let usdlRecognizerSettings = PPUsdlRecognizerSettings()

        // Add USDL Recognizer setting to a list of used recognizer settings
        settings.scanSettings.addRecognizerSettings(usdlRecognizerSettings)


        /** 4. Initialize the Scanning Coordinator object */

        let coordinator: PPCoordinator = PPCoordinator(settings: settings)

        return coordinator
    }

    @IBAction func didTapScan(sender: AnyObject) {

        /** Instantiate the scanning coordinator */
        let error: NSErrorPointer = nil
        let coordinator:PPCoordinator?=self.coordinatorWithError(error)

        /** If scanning isn't supported, present an error */
        if coordinator == nil {
            let messageString: String = (error.memory?.localizedDescription) ?? ""
            UIAlertView(title: "Warning", message: messageString, delegate: nil, cancelButtonTitle: "Ok").show()
            return
        }

        /** Allocate and present the scanning view controller */
        let scanningViewController: UIViewController = coordinator!.cameraViewControllerWithDelegate(self)

        /** You can use other presentation methods as well */
        self.presentViewController(scanningViewController, animated: true, completion: nil)
    }

    func scanningViewControllerUnauthorizedCamera(scanningViewController: UIViewController) {

    }

    func scanningViewController(scanningViewController: UIViewController, didFindError error: NSError) {

    }

    func scanningViewControllerDidClose(scanningViewController: UIViewController) {
        self.dismissViewControllerAnimated(true, completion: nil)
    }

    func scanningViewController(scanningViewController: UIViewController?, didOutputResults results: [PPRecognizerResult]) {

        let scanConroller = scanningViewController as! PPScanningViewController

        // Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.

        // first, pause scanning until we process all the results
        scanConroller.pauseScanning()

        var message = ""
        var title = ""

        // Collect data from the result
        for result in results {
            if(result.isKindOfClass(PPMrtdRecognizerResult)) {
                let mrtdResult = result as! PPMrtdRecognizerResult
                title = "MRTD"
                message = mrtdResult.description
            }
            if(result.isKindOfClass(PPUsdlRecognizerResult)) {
                let usdlResult = result as! PPUsdlRecognizerResult
                title = "USDL"
                message = usdlResult.description
            }
        }

        //present the alert view with scanned results
        let alertView = UIAlertView(title: title, message: message, delegate: self, cancelButtonTitle: "OK")
        alertView.show()
    }

    // dismiss the scanning view controller when user presses OK.
    
    func alertView(alertView: UIAlertView, clickedButtonAtIndex buttonIndex: Int) {
        self.dismissViewControllerAnimated(true, completion: nil)
    }
}


