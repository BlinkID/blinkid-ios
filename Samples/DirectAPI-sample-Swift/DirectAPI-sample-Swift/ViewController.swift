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
    private var blinkIdMultiSideRecognizer: MBBlinkIdMultiSideRecognizer?
    private var imagePickerController: UIImagePickerController?
    private var overlayLabel = UILabel(frame: .zero)
    private let serialQueue = DispatchQueue(label: "com.microblink.DirectAPI-sample-swift")

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Valid until: 2023-4-14
        MBMicroblinkSDK.shared().setLicenseResource("blinkid-license", withExtension: "txt", inSubdirectory: "", for: Bundle.main) { (_) in
        }
        
        setupRecognizerRunner()
        overlayLabel.text = "Scan the front side"
        overlayLabel.textColor = .white
    }

    @IBAction func openImagePicker(_ sender: Any) {
        openImagePicker()
    }
    
    private func openImagePicker() {
        let imagePicker = UIImagePickerController()
        imagePicker.sourceType = .camera
        imagePicker.cameraDevice = .rear

        addOverlayLabel(toImagePicker: imagePicker)
        
        // Displays a control that allows the user to choose only photos
        imagePicker.mediaTypes = [kUTTypeImage as String]
        
        // Hides the controls for moving & scaling pictures, or for trimming movies.
        imagePicker.allowsEditing = false
        
        // Shows default camera control overlay over camera preview.
        imagePicker.showsCameraControls = true
        
        // set delegate
        imagePicker.delegate = self
        present(imagePicker, animated: true) {() -> Void in }
        imagePickerController = imagePicker
    }
    
    private func setupRecognizerRunner() {
        var recognizers = [MBRecognizer]()
        blinkIdMultiSideRecognizer = MBBlinkIdMultiSideRecognizer()
        recognizers.append(blinkIdMultiSideRecognizer!)
        let recognizerCollection = MBRecognizerCollection(recognizers: recognizers)
        recognizerRunner = MBRecognizerRunner(recognizerCollection: recognizerCollection)
        recognizerRunner?.scanningRecognizerRunnerDelegate = self
        recognizerRunner?.metadataDelegates.firstSideFinishedRecognizerRunnerDelegate = self
    }
    
    private func processImageRunner(_ originalImage: UIImage?) {
        var image: MBImage? = nil
        if let anImage = originalImage {
            image = MBImage(uiImage: anImage)
        }
        image?.cameraFrame = false
        image?.orientation = MBProcessingOrientation.left

        
        serialQueue.async(execute: {() -> Void in
            self.recognizerRunner?.processImage(image!)
        })
    }
    
    private func addOverlayLabel(toImagePicker imagePicker: UIImagePickerController) {
        overlayLabel.frame = imagePicker.cameraOverlayView!.frame
        overlayLabel.textAlignment = .center
        imagePicker.cameraOverlayView = overlayLabel
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
        serialQueue.async {
            self.recognizerRunner?.resetState()
        }

        dismiss(animated: true, completion: nil)
        overlayLabel.text = "Scan the front side"
    }
}


// MARK: - MBFirstSideFinishedRecognizerRunnerDelegate
extension ViewController: MBFirstSideFinishedRecognizerRunnerDelegate {
    
    func recognizerRunnerDidFinishRecognition(ofFirstSide recognizerRunner: MBRecognizerRunner) {
        DispatchQueue.main.async {
            self.overlayLabel.text = "Scan the back side"
            self.openImagePicker()
        }
    }
}


// MARK: - MBScanningRecognizerRunnerDelegate
extension ViewController: MBScanningRecognizerRunnerDelegate {
    
    func recognizerRunner(_ recognizerRunner: MBRecognizerRunner, didFinishScanningWith state: MBRecognizerResultState) {
        DispatchQueue.main.async(execute: {() -> Void in
            if state != .valid {
                self.openImagePicker()
                return
            }
            
            let title = "BlinkID"
            // Save the string representation of the code
            print(state.rawValue)
            let message = self.blinkIdMultiSideRecognizer?.result.description
            let alertController = UIAlertController(title: title, message: message, preferredStyle: .alert)
            let okAction = UIAlertAction(title: "OK", style: .default, handler: {(_ action: UIAlertAction) -> Void in
                self.dismiss(animated: true) {() -> Void in }
            })
            alertController.addAction(okAction)
            self.present(alertController, animated: true) {() -> Void in }
            
            self.overlayLabel.text = "Scan the front side"
        })
    }
}
