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
    
    // Valid until: 2026-07-25
    private let licenseKey = "sRwDAAEkY29tLm1pY3JvYmxpbmsuQmxpbmtJRERvd25sb2FkU2FtcGxlASRjb20ubWljcm9ibGluay5CbGlua0lERG93bmxvYWRTYW1wbGUAIlNbNKYu6bl4/feWqEYbYa13v3s5Lf15sC9RtUXtTuWsH4wNFFrxiAUm7ibF38G44LlxAtzjj/t+aYujbFmKhtcCqUE4Epra44k5wWPr9oFBYXAlyVikLKZXppsXcrknuYtUrKKZ5u6COBnOKiASYJBcZo6H0RIld51ns/0="
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
            let settings = BlinkIDSdkSettings(licenseKey: licenseKey)
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
