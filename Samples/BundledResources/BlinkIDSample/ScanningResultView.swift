// Created by Toni Krešo on 20.3.2025.. 
// Copyright (c) 2025 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import SwiftUI
import BlinkID

struct ScanningResultView : View {
    @EnvironmentObject private var viewModel: BlinkIDViewModel
    private let scanningResult: BlinkIDScanningResult

    init(scanningResult: BlinkIDScanningResult) {
        self.scanningResult = scanningResult
    }

    var body: some View {
        List {
            if let firstFrame = scanningResult.getDocumentImage(scanningSide: .first),
               let uiImage = firstFrame.uiImage {
                Text("First camera frame:")
                Image(uiImage: uiImage)
                    .resizable()
                    .aspectRatio(contentMode: .fit)
            }
            if let secondFrame = scanningResult.getDocumentImage(scanningSide: .second),
               let uiImage = secondFrame.uiImage  {
                Text("Second camera frame:")
                Image(uiImage: uiImage)
                    .resizable()
                    .aspectRatio(contentMode: .fit)
            }
            if let faceImage = scanningResult.getFaceImage(),
               let uiImage = faceImage.uiImage  {
                Text("Face image:")
                Image(uiImage: uiImage)
                    .resizable()
                    .aspectRatio(contentMode: .fit)
            }
            if let firstName = scanningResult.firstName?.value {
                Text("First name: \(firstName)")
            }
            if let lastName = scanningResult.lastName?.value {
                Text("Last name: \(lastName)")
            }
            if let fullName = scanningResult.fullName?.value {
                Text("Full name: \(fullName)")
            }
            if let address = scanningResult.address?.value {
                Text("Address: \(address)")
            }
            if let documentNumber = scanningResult.documentNumber?.value {
                Text("Document Number: \(documentNumber)")
            }
            
            Button("Cancel") {
                viewModel.state = .home
            }
        }
    }
}
