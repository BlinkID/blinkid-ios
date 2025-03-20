// Created by Toni Krešo on 13.01.2025.. 
// Copyright (c) 2025 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import SwiftUI
import BlinkIDVerify

struct CaptureResultView : View {
    @EnvironmentObject private var viewModel: BlinkIDVerifyViewModel
    private let captureResult: BlinkIDVerifyCaptureResult

    init(captureResult: BlinkIDVerifyCaptureResult) {
        self.captureResult = captureResult
    }

    var body: some View {
        ScrollView {
            VStack(
                alignment: HorizontalAlignment.center,
                spacing: 10.0
            ) {
                if let frontFrame = captureResult.frontCameraFrameJpeg?.uiImage {
                    Text("Front camera frame:")
                    Image(uiImage: frontFrame)
                        .resizable()
                        .aspectRatio(contentMode: .fit)
                }
                if let backFrame = captureResult.backCameraFrameJpeg?.uiImage {
                    Text("Back camera frame:")
                    Image(uiImage: backFrame)
                        .resizable()
                        .aspectRatio(contentMode: .fit)
                }
                if let barcodeCameraFrame = captureResult.barcodeCameraFrameJpeg?.uiImage {
                    Text("Barcode camera frame:")
                    Image(uiImage: barcodeCameraFrame)
                        .resizable()
                        .aspectRatio(contentMode: .fit)
                }
                Button("Process these images on server") {
                    viewModel.processOnServer(result: captureResult)
                }

                Button("Cancel") {
                    viewModel.state = .home
                }
            }
        }
    }
}
