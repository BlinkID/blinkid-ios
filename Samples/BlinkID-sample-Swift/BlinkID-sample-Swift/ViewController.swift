//
//  ViewController.swift
//  BlinkID-sample-Swift
//
//  Created by Dino on 22/12/15.
//  Copyright © 2015 Dino. All rights reserved.
//

import UIKit
import Microblink

class ViewController: UIViewController {

    var blinkIdRecognizer: MBBlinkIdCombinedRecognizer?

    override func viewDidLoad() {
        super.viewDidLoad()
        // Valid until: 2022-11-19
        MBMicroblinkSDK.shared().setLicenseResource("blinkid-license", withExtension: "txt", inSubdirectory: "", for: Bundle.main) { (_) in
        }
    }

    @IBAction func didTapScan(_ sender: AnyObject) {

        /** Create BlinkID recognizer */
        self.blinkIdRecognizer = MBBlinkIdCombinedRecognizer()
        self.blinkIdRecognizer?.returnFullDocumentImage = true

        /** Create settings */
        let settings: MBBlinkIdOverlaySettings = MBBlinkIdOverlaySettings()

        /** Crate recognizer collection */
        let recognizerList = [self.blinkIdRecognizer!]
        let recognizerCollection: MBRecognizerCollection = MBRecognizerCollection(recognizers: recognizerList)

        /** Create your overlay view controller */
        let blinkIdOverlayViewController: MBBlinkIdOverlayViewController =
            MBBlinkIdOverlayViewController(settings: settings, recognizerCollection: recognizerCollection, delegate: self)

        /** Create recognizer view controller with wanted overlay view controller */
        guard let recognizerRunneViewController: UIViewController =
            MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: blinkIdOverlayViewController) else {
                return
        }
        recognizerRunneViewController.modalPresentationStyle = .fullScreen

        /** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
        self.present(recognizerRunneViewController, animated: true, completion: nil)
    }

    @IBAction func didTapCustomUI(_ sender: Any) {

        /** Create BlinkID recognizer */
        self.blinkIdRecognizer = MBBlinkIdCombinedRecognizer()

        /** Crate recognizer collection */
        let recognizerList = [self.blinkIdRecognizer!]
        let recognizerCollection: MBRecognizerCollection = MBRecognizerCollection(recognizers: recognizerList)

        /** Create your overlay view controller */
        let customOverlayViewController: CustomOverlay = CustomOverlay.initFromStoryboard()

        /** This has to be called for custom controller */
        customOverlayViewController.reconfigureRecognizers(recognizerCollection)

        /** Create recognizer view controller with wanted overlay view controller */
        guard let recognizerRunneViewController: UIViewController =
            MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: customOverlayViewController) else {
                return
        }

        recognizerRunneViewController.modalPresentationStyle = .fullScreen

        /** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
        self.present(recognizerRunneViewController, animated: true, completion: nil)
    }
}

extension ViewController: MBBlinkIdOverlayViewControllerDelegate {

    func blinkIdOverlayViewControllerDidFinishScanning(_ blinkIdOverlayViewController: MBBlinkIdOverlayViewController, state: MBRecognizerResultState) {
        /** This is done on background thread */
        blinkIdOverlayViewController.recognizerRunnerViewController?.pauseScanning()

        var message: String = ""
        var title: String = ""

        if self.blinkIdRecognizer?.result.resultState == MBRecognizerResultState.valid {
            title = "BlinkID"

            let fullDocumentImage: UIImage! = self.blinkIdRecognizer?.result.fullDocumentFrontImage?.image
            print("Got BlinkID image with width: \(fullDocumentImage.size.width), height: \(fullDocumentImage.size.height)")

            // Save the string representation of the code
            message = self.blinkIdRecognizer!.result.description

            /** Needs to be called on main thread beacuse everything prior is on background thread */
            DispatchQueue.main.async {
                // present the alert view with scanned results

                let alertController: UIAlertController = UIAlertController.init(title: title, message: message, preferredStyle: UIAlertController.Style.alert)

                let okAction: UIAlertAction = UIAlertAction.init(title: "OK", style: UIAlertAction.Style.default,
                                                                 handler: { (_) -> Void in
                                                                    self.dismiss(animated: true, completion: nil)
                })
                alertController.addAction(okAction)
                blinkIdOverlayViewController.present(alertController, animated: true, completion: nil)
            }
        }
    }

    func blinkIdOverlayViewControllerDidTapClose(_ blinkIdOverlayViewController: MBBlinkIdOverlayViewController) {
        self.dismiss(animated: true, completion: nil)
    }
}
