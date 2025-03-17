//
//  CameraView.swift
//  DocumentVerificationUX
//
//  Created by Jura Skrlec on 09.12.2024..
//

import SwiftUI
import AVFoundation

@MainActor
public struct CameraView<Camera: CameraModel>: PlatformView {
    
    @Environment(\.verticalSizeClass) var verticalSizeClass
    @Environment(\.horizontalSizeClass) var horizontalSizeClass
    
    @State var camera: Camera
    
    @State private var tapLocation: CGPoint = .zero
    @State private var tapOpacity: Double = 0
    
    public init(camera: Camera) {
        self.camera = camera
    }
    
    public var body: some View {
        ZStack {
            CameraPreview(source: camera.previewSource)
                .overlay(
                    Circle()
                        .stroke(Color.white.opacity(tapOpacity), lineWidth: 2)
                        .frame(width: 60, height: 60)
                        .position(tapLocation)
                )
                .onTapGesture { location in
                    tapLocation = location
                    tapOpacity = 0.7
                    
                    Task {
                        await camera.focusAndExpose(at: location)
                        
                        withAnimation(.easeOut(duration: 0.5)) {
                            tapOpacity = 0
                        }
                    }
                }
        }
    }
}
