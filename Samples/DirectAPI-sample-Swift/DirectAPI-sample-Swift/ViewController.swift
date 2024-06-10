//
//  ViewController.swift
//  DirectAPI-sample-Swift
//
//  Created by Jura Skrlec on 10/05/2018.
//  Copyright © 2018 Microblink. All rights reserved.
//

import UIKit
import BlinkID
import MobileCoreServices

class ViewController: UIViewController, UINavigationControllerDelegate {
    
    private var recognizerRunner: MBRecognizerRunner?
    private var blinkIdSingleSideRecognizer: MBBlinkIdSingleSideRecognizer?
    private let serialQueue = DispatchQueue(label: "com.microblink.DirectAPI-sample-swift")

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Valid until: 2024-10-10
        MBMicroblinkSDK.shared().setLicenseResource("blinkid-license", withExtension: "txt", inSubdirectory: "", for: Bundle.main) { (_) in
        }
        
        setupRecognizerRunner()
    }

    @IBAction func openImagePicker(_ sender: Any) {
        openImagePicker()
    }
    
    private func openImagePicker() {
        let imagePicker = UIImagePickerController()
        imagePicker.sourceType = .photoLibrary
        
        // Displays a control that allows the user to choose only photos
        imagePicker.mediaTypes = [kUTTypeImage as String]
        
        // set delegate
        imagePicker.delegate = self
        present(imagePicker, animated: true) {() -> Void in }
    }
    
    private func setupRecognizerRunner() {
        var recognizers = [MBRecognizer]()
        blinkIdSingleSideRecognizer = MBBlinkIdSingleSideRecognizer()
        recognizers.append(blinkIdSingleSideRecognizer!)
        let recognizerCollection = MBRecognizerCollection(recognizers: recognizers)
        recognizerRunner = MBRecognizerRunner(recognizerCollection: recognizerCollection)
        recognizerRunner?.scanningRecognizerRunnerDelegate = self
    }
    
    private func processImageRunner(_ originalImage: UIImage?) {
        var image: MBImage? = nil
        if let anImage = originalImage {
            image = MBImage(uiImage: anImage)
        }
        image?.cameraFrame = false
        image?.orientation = MBProcessingOrientation.left

        
        serialQueue.async {
            self.recognizerRunner?.processImage(image!)
        }
    }
}


// MARK: - UIImagePickerControllerDelegate
extension ViewController: UIImagePickerControllerDelegate {
    
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [UIImagePickerController.InfoKey : Any]) {
        let mediaType = info[UIImagePickerController.InfoKey.mediaType] as? String
        
        if CFStringCompare(mediaType as CFString?, kUTTypeImage, CFStringCompareFlags(rawValue: 9)) == .compareEqualTo {
            let originalImage = info[UIImagePickerController.InfoKey.originalImage] as? UIImage
            processImageRunner(originalImage)
        }
        
        picker.dismiss(animated: true, completion: nil)
    }
    
    func imagePickerControllerDidCancel(_ picker: UIImagePickerController) {
        dismiss(animated: true, completion: nil)
    }
}

// MARK: - MBScanningRecognizerRunnerDelegate
extension ViewController: MBScanningRecognizerRunnerDelegate {
    
    func recognizerRunner(_ recognizerRunner: MBRecognizerRunner, didFinishScanningWith state: MBRecognizerResultState) {
        DispatchQueue.main.async {
            if state != .valid {
                let alertController = UIAlertController(title: "Error", message: "Result state is not valid. Please try again.", preferredStyle: .alert)
                alertController.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
                self.present(alertController, animated: true) {() -> Void in }
                return
            }
            
            let message = self.blinkIdSingleSideRecognizer?.result.description
            let alertController = UIAlertController(title: "BlinkID", message: message, preferredStyle: .alert)
            let okAction = UIAlertAction(title: "OK", style: .default, handler: {(_ action: UIAlertAction) -> Void in
                self.dismiss(animated: true) {() -> Void in }
            })
            alertController.addAction(okAction)
            self.present(alertController, animated: true) {() -> Void in }
        }
    }
}
