// Created by Toni Krešo on 13.01.2025.. 
// Copyright (c) 2025 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import AVFoundation
import SwiftUI
import BlinkIDVerifyUX

struct CustomUIScanningView: View {
    @Environment(\.presentationMode) var presentationMode
    @ObservedObject private var viewModel: CustomScanningViewModel
    
    init(viewModel: CustomScanningViewModel) {
        self.viewModel = viewModel
    }

    var body: some View {
        ZStack {
            CameraView(camera: viewModel.camera)
                .ignoresSafeArea()
                .statusBarHidden()
                .task {
                    await viewModel.camera.start()
                    await viewModel.analyze()
                }
                .onDisappear {
                    viewModel.stopEventHandling()
                    Task {
                        await viewModel.camera.stop()
                    }
                }
            
            VStack {
                HStack {
                    Button {
                        viewModel.closeButtonTapped()
                    } label: {
                        Image(systemName: "xmark")
                            .resizable()
                            .renderingMode(.template)
                            .foregroundColor(Color.white)
                            .frame(width: 20, height: 20)
                    }
                    .padding(EdgeInsets(top: 20, leading: 20, bottom: 0, trailing: 0))

                    Spacer()
                }

                Spacer()
                
                Text(viewModel.instructionText)
                    .font(.system(size: 20))
                    .foregroundColor(Color.white)
                    .padding()
                    .background(Color.gray)
                    .clipShape(.capsule)
                
                Spacer()
            }
        }
    }
}
