//
//  ViewExtensions.swift
//  DocumentVerificationUX
//
//  Created by Jura Skrlec on 09.12.2024..
//

import SwiftUI
import AVFoundation

@MainActor
protocol PlatformView: View {
    var verticalSizeClass: UserInterfaceSizeClass? { get }
    var horizontalSizeClass: UserInterfaceSizeClass? { get }
    var isRegularSize: Bool { get }
    var isCompactSize: Bool { get }
}

extension PlatformView {
    var isRegularSize: Bool { horizontalSizeClass == .regular && verticalSizeClass == .regular }
    var isCompactSize: Bool { horizontalSizeClass == .compact || verticalSizeClass == .compact }
}

extension AVCaptureVideoOrientation {
    func toImageOrientation() -> Image.Orientation {
        switch self {
        case .portrait:
            return .leftMirrored
        case .portraitUpsideDown:
            return .rightMirrored
        case .landscapeRight:
            return .downMirrored
        case .landscapeLeft:
            return .upMirrored
        @unknown default:
            return .leftMirrored
        }
    }
}
