// Created by Toni Krešo on 11.04.2025.. 
// Copyright (c) 2025 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import Foundation
import SwiftUI
import BlinkID

enum UIState {
    case loading
    case home
    case error(String)
    case success(BlinkIDScanningResult)
}

@MainActor
class ViewModel: ObservableObject {
    private let licenseKey = "sRwDAAEeY29tLm1pY3JvYmxpbmsuRGlyZWN0QVBJU2FtcGxlAR5jb20ubWljcm9ibGluay5EaXJlY3RBUElTYW1wbGX/c3VjhKeTdEv812pbS0L9490I8Sy//rntnHZhN2lfPlUY+0u/+IxKMYO5WQP99pRMN13qfc9EBHSEvYytqTWuhhEywjqCQn5ZSLbw2INpWYYdKra+Dp+y4R2yLkrbyNxWgVGy/o24S/GDSjJ5xhWsuwwIgmP1Fu5E9nsQ+7o="
    private var blinkIDsdk: BlinkIDSdk? = nil
    @Published var state: UIState = .loading
    
    init() {
        Task {
            await initializeSdk()
        }
    }
    
    func initializeSdk() async {
        do {
            let settings = BlinkIDSdkSettings(licenseKey: licenseKey)
            blinkIDsdk = try await BlinkIDSdk.createBlinkIDSdk(withSettings: settings)
        } catch {
            state = .error(error.localizedDescription)
        }
        state = .home
    }
    
    func processImages() async {
        state = .loading
        
        guard let blinkIDsdk = blinkIDsdk
        else {
            state = .error("Failed to perform scan due to missing sdk")
            return
        }
        
        if let session = try? await blinkIDsdk.createScanningSession(sessionSettings: BlinkIDSessionSettings(inputImageSource: .photo, scanningSettings: ScanningSettings(croppedImageSettings: CroppedImageSettings(returnDocumentImage: true, returnFaceImage: true)))) {
            guard let frontUIImage = UIImage(named: "front"),
                  let backUIImage = UIImage(named: "back")
            else { return }
            
            let frontFrameProcessResult = await session.process(inputImage: InputImage(uiImage: frontUIImage))
            if let processResult = frontFrameProcessResult.processResult {
                debugPrint("Processing status Frist: \(processResult)")
            }
            
            
            let backFrameProcessResult = await session.process(inputImage: InputImage(uiImage: backUIImage))
            if let processResult = backFrameProcessResult.processResult {
                debugPrint("Processing status Second: \(processResult)")
            }
            
            let finalResult = await session.getResult()

            debugPrint("final Result: \(finalResult)")
            
            state = .success(finalResult)
        }
        
        
    }
}
