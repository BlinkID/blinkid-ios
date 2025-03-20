// Created by Toni Krešo on 07.03.2025.. 
// Copyright (c) 2025 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import SwiftUI

@main
struct BlinkIDSampleApp: App {
    var body: some Scene {
        WindowGroup {
            ContentView()
                .environmentObject(BlinkIDViewModel())
        }
    }
}
