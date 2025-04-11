// Created by Toni Krešo on 10.04.2025.. 
// Copyright (c) 2025 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import SwiftUI

struct ContentView: View {
    @EnvironmentObject var viewModel: ViewModel
    
    var body: some View {
        switch viewModel.state {
        case .loading:
            ProgressView()
                .progressViewStyle(.circular)
        case .home:
            HomeScreen()
        case .error(let error):
            Text(error)
        case .success(let scanningResult):
            ScanningResultView(scanningResult: scanningResult)
        }
    }
    
    @ViewBuilder
    private func HomeScreen() -> some View {
        Button {
            Task {
                await viewModel.processImages()
            }
        } label: {
            Text("Process images")
        }
    }
}
