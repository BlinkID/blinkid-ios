// Created by Jura Skrlec on 23/12/2020.
// Copyright (c) 2020 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import SwiftUI
import BlinkID

struct ContentView: View {
    @State private var showingBlinkIdViewController = false
    @State private var showBlinkIdResult = false
    @State private var blinkIdMultiSideRecognizer: MBBlinkIdMultiSideRecognizer = MBBlinkIdMultiSideRecognizer()
    var body: some View {
        VStack {
            Button("Scan") {
                self.showingBlinkIdViewController = true
            }
        }
        .fullScreenCover(isPresented: $showingBlinkIdViewController) {
            BlinkIdViewController(showAlert: $showBlinkIdResult, blinkIdMultiSideRecognizer: $blinkIdMultiSideRecognizer)
                .alert(isPresented: $showBlinkIdResult) { () -> Alert in
                    let alert = Alert(title: Text("BlinkId Results"),
                                      message: Text(self.blinkIdMultiSideRecognizer.result.description),
                                      dismissButton: .default(Text("Ok"),
                                      action: {
                        self.showingBlinkIdViewController.toggle()
                    }))
                    return alert
                }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
