// Created by Toni Krešo on 20.3.2025.. 
// Copyright (c) 2025 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import SwiftUI
import Combine
import BlinkID
import BlinkIDUX

enum UIState {
    case loading
    case home
    case scanBuiltin(BlinkIDUXModel)
    case scanCustom(CustomScanningViewModel)
    case error(String)
    case success(BlinkIDScanningResult)
}

@MainActor
final class BlinkIDViewModel: ObservableObject {
    private let licenseKey = "sRwDAAEcY29tLm1pY3JvYmxpbmsuQmxpbmtJRFNhbXBsZQEcY29tLm1pY3JvYmxpbmsuQmxpbmtJRFNhbXBsZWj+oX2cWh3W7GjcROfR/6UlqgyxP19kNIR0tLK4dPggw61pCbTryszv0SSKlpPZgGk5CBYMziyc1fR4tKWC0OElHemI4riASu/ufYjATSHv2a6yqNjspIL/DJKMncMAwTcVRZDjOR0="
    private var sdkInstance: BlinkIDSdk?
    private var cancellables = Set<AnyCancellable>()
    @Published var state: UIState = .loading
    
    init() {
        Task {
            await initializeSdk()
        }
    }
    
    func initializeSdk() async {
        do {
            let settings = BlinkIDSdkSettings(licenseKey: licenseKey, downloadResources: false, bundleURL: Bundle.main.bundleURL)
            sdkInstance = try await BlinkIDSdk.createBlinkIDSdk(withSettings: settings)
        } catch {
            state = .error(error.localizedDescription)
        }
        state = .home
    }
    
    func performScan(customScan: Bool = false) async {
        guard let sdkInstance = sdkInstance
        else {
            state = .error("Failed to perform scan due to missing sdk")
            return
        }
        
        if let analyzer = try? await BlinkIDAnalyzer(sdk: sdkInstance, blinkIdSessionSettings: BlinkIDSessionSettings(scanningSettings: ScanningSettings(croppedImageSettings: CroppedImageSettings(returnDocumentImage: true, returnFaceImage: true))), eventStream: BlinkIDEventStream()) {
            if customScan {
                let scanningUxModel = CustomScanningViewModel(analyzer: analyzer)
                scanningUxModel.$scanningResult
                    .sink { [weak self] scanningResult in
                        if let scanningResult = scanningResult {
                            self?.state = .success(scanningResult)
                        } else {
                            self?.state = .home
                        }
                    }
                    .store(in: &cancellables)
                
                state = .scanCustom(scanningUxModel)
            } else {
                let scanningUxModel = BlinkIDUXModel(analyzer: analyzer)
                scanningUxModel.$result
                    .sink { [weak self] scanningResultState in
                        if let scanningResultState {
                            if let scanningResult = scanningResultState.scanningResult {
                                self?.state = .success(scanningResult)
                            }
                            else {
                                self?.state = .home
                            }
                        }
                    }
                    .store(in: &cancellables)
                
                state = .scanBuiltin(scanningUxModel)
            }
        }
    }
}
