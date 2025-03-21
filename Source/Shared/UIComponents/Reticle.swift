//  Created by Toni Krešo on 06.11.2024.. 
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI

private extension Path {
    mutating func rotate(to degrees: Double, rect: CGRect, radius: Double) {
        self.move(to: CGPoint(x: rect.midX + radius * cos(degrees), y: rect.midY + radius * sin(degrees)))
    }
}

private extension Double {
    var toRadian: Double {
        self * .pi / 180.0
    }
}

struct DetectingArcRing: Shape {
    let radius: Double
    
    func path(in rect: CGRect) -> Path {
        var path = Path()
        path.addArc(center: CGPoint(x: rect.midX, y: rect.midY), radius: radius, startAngle: Angle(degrees: 0.0), endAngle: Angle(degrees: 50.0), clockwise: false)
        
        return path
    }
}

struct ArcRing: Shape {
    let clockwise: Bool = true
    let radius: Double

    func path(in rect: CGRect) -> Path {
        var path = Path()
        path.addArc(center: CGPoint(x: rect.midX, y: rect.midY), radius: radius, startAngle: Angle(degrees: 340), endAngle: Angle(degrees: 20), clockwise: false)
        path.rotate(to: 70.0.toRadian, rect: rect, radius: radius)
        path.addArc(center: CGPoint(x: rect.midX, y: rect.midY), radius: radius, startAngle: Angle(degrees: 70.0), endAngle: Angle(degrees: 110.0), clockwise: false)
        path.rotate(to: 160.0.toRadian, rect: rect, radius: radius)
        path.addArc(center: CGPoint(x: rect.midX, y: rect.midY), radius: radius, startAngle: Angle(degrees: 160), endAngle: Angle(degrees: 200), clockwise: false)
        path.rotate(to: 250.0.toRadian, rect: rect, radius: radius)
        path.addArc(center: CGPoint(x: rect.midX, y: rect.midY), radius: radius, startAngle: Angle(degrees: 250.0), endAngle: Angle(degrees: 290.0), clockwise: false)
        
        
        return path
    }
}

extension Animation {
    public static func easeOutExpo(duration: TimeInterval) -> Animation {
        Animation.timingCurve(0.19, 1.0, 0.22, 1.0, duration: duration)
    }
}

struct Reticle: View {
    private let blurDiameter: Double
    private let dashDiameter: Double
    private let lineWidth: Double = 3.0
    @State private var rotation: Angle = .degrees(0)
    @State private var percentage: CGFloat = .zero
    @State private var detectingRotation: Angle = .degrees(0)
    @State private var detectingPercentage: CGFloat = .zero
    @State private var detectingArcPercentage: CGFloat = .zero
    @Binding private var state: ReticleState
    
    private let appearAnimation: Animation = .easeOut(duration: 1.0).delay(0.2)
    private let rotationAnimation: Animation = .easeOutExpo(duration: 1.13)
        .repeatForever(autoreverses: false)
        .delay(1.5)
    private let detectionAppearAnimation: Animation = .easeOutExpo(duration: 0.55)
    private let detectionArcAppearAnimation: Animation = .linear(duration: 0.55).delay(0.55)
    private let detectingRotationAnimation: Animation = .linear(duration: 0.55)
        .repeatForever(autoreverses: false)
        .delay(0.55)
    
    init(diameter: Double, reticleState: Binding<ReticleState>) {
        self.blurDiameter = diameter
        self.dashDiameter = diameter * 0.5
        self._state = reticleState
    }
    
    var body: some View {
        ZStack {
            switch state {
            case .front, .back, .barcode:
                grayBlurView
                ArcRing(radius: dashDiameter / 2)
                    .trim(from: 0.0, to: percentage)
                    .stroke(Color.white.opacity(0.5), lineWidth: lineWidth)
                    .frame(width: dashDiameter, height: dashDiameter)
                    .rotationEffect(rotation)
                    .onAppear {
                        withAnimation(appearAnimation) {
                            percentage = 1.0
                            rotation = .degrees(180.0)
                        }
                        withAnimation(rotationAnimation) {
                            rotation = .degrees(360.0)
                        }
                    }
                    .onDisappear {
                        percentage = 0.0
                        rotation = .degrees(0.0)
                    }
                centerDot
            case .detecting:
                grayBlurView
                Circle()
                    .trim(from: 0.0, to: detectingPercentage)
                    .stroke(Color.white.opacity(0.5), lineWidth: lineWidth)
                    .frame(width: dashDiameter, height: dashDiameter)
                DetectingArcRing(radius: dashDiameter / 2)
                    .trim(from: 0.0, to: detectingArcPercentage)
                    .stroke(Color.white, lineWidth: lineWidth)
                    .frame(width: dashDiameter, height: dashDiameter)
                    .rotationEffect(detectingRotation)
                    .onAppear {
                        withAnimation(detectionAppearAnimation) {
                            detectingPercentage = 1.0
                        }
                        withAnimation(detectionArcAppearAnimation) {
                            detectingArcPercentage = 1.0
                        }
                        withAnimation(detectingRotationAnimation) {
                            detectingRotation = .degrees(360.0)
                        }
                    }
                    .onDisappear {
                        detectingPercentage = 0.0
                        detectingArcPercentage = 0.0
                        detectingRotation = .degrees(0)
                    }
                centerDot
            case .error(_):
                redBlurView
                Circle()
                    .stroke(Color.white.opacity(0.5), lineWidth: lineWidth)
                    .frame(width: dashDiameter, height: dashDiameter)
                centerDot
            case .inactive, .flip:
                EmptyView()
            }
            
        }
    }
    
    var centerDot: some View {
        Circle()
            .fill(Color.white)
            .frame(width: 4.0, height: 4.0)
    }
    
    var grayBlurView: some View {
        BlurView(style: .systemUltraThinMaterialDark)
            .frame(width: blurDiameter, height: blurDiameter)
            .clipShape(.circle)
    }
    
    var redBlurView: some View {
        BlurView(style: .light)
            .frame(width: blurDiameter, height: blurDiameter)
            .background(Color(red: 1.0, green: 0.18, blue: 0.33, opacity: 0.4))
            .clipShape(.circle)
    }
}
