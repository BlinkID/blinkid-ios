//
//  ViewController.swift
//  DirectAPI-sample-Swift
//
//  Created by Jura Skrlec on 10/05/2018.
//  Copyright © 2018 Microblink. All rights reserved.
//

import UIKit
import MicroBlink
import MobileCoreServices

class ViewController: UIViewController, UIImagePickerControllerDelegate, UINavigationControllerDelegate, MBScanningRecognizerRunnerDelegate {
    
    var recognizerRunner: MBRecognizerRunner?
    var pdf417Recognizer: MBPdf417Recognizer?

    override func viewDidLoad() {
        super.viewDidLoad()
        
        setupRecognizerRunner()
    }

    @IBAction func openImagePicker(_ sender: Any) {
        
        let imagePicker = UIImagePickerController()
        imagePicker.sourceType = .camera
        imagePicker.cameraDevice = .rear
        
        // Displays a control that allows the user to choose only photos
        imagePicker.mediaTypes = [kUTTypeImage as String]
        
        // Hides the controls for moving & scaling pictures, or for trimming movies.
        imagePicker.allowsEditing = false
        
        // Shows default camera control overlay over camera preview.
        imagePicker.showsCameraControls = true
        
        // set delegate
        imagePicker.delegate = self
        present(imagePicker, animated: true) {() -> Void in }
        
    }
    
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [String : Any]) {
        let mediaType = info[UIImagePickerControllerMediaType] as? String
        // Handle a still image capture
        if CFStringCompare(mediaType as CFString?, kUTTypeImage, CFStringCompareFlags(rawValue: 0)) == .compareEqualTo {
            let originalImage = info[UIImagePickerControllerOriginalImage] as? UIImage
            processImageRunner(originalImage)
        }
        picker.dismiss(animated: true) {() -> Void in }
    }
    
    func setupRecognizerRunner() {
        var recognizers = [MBRecognizer]()
        pdf417Recognizer = MBPdf417Recognizer()
        recognizers.append(pdf417Recognizer!)
        let recognizerCollection = MBRecognizerCollection(recognizers: recognizers)
        recognizerRunner = MBRecognizerRunner(recognizerCollection: recognizerCollection)
        recognizerRunner?.scanningRecognizerRunnerDelegate = self
    }
    
    func processImageRunner(_ originalImage: UIImage?) {
        var image: MBImage? = nil
        if let anImage = originalImage {
            image = MBImage(uiImage: anImage)
        }
        image?.cameraFrame = true
        image?.orientation = MBProcessingOrientation.left
        let _serialQueue = DispatchQueue(label: "com.microblink.DirectAPI-sample-swift")
        _serialQueue.async(execute: {() -> Void in
            self.recognizerRunner?.processImage(image!)
        })
    }
    
    func recognizerRunner(_ recognizerRunner: MBRecognizerRunner, didFinishScanningWith state: MBRecognizerResultState) {
        DispatchQueue.main.async(execute: {() -> Void in
            let title = "PDF417"
            // Save the string representation of the code
            let message = self.pdf417Recognizer?.result.stringData!
            let alertController = UIAlertController(title: title, message: message, preferredStyle: .alert)
            let okAction = UIAlertAction(title: "OK", style: .default, handler: {(_ action: UIAlertAction) -> Void in
                self.dismiss(animated: true) {() -> Void in }
            })
            alertController.addAction(okAction)
            self.present(alertController, animated: true) {() -> Void in }
        })
    }
}

