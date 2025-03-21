//
//  BlinkIDUXView.swift
//  DocumentVerificationUX
//
//  Created by Jura Skrlec on 19.02.2025..
//

import SwiftUI

#if canImport(BlinkIDVerify)
import BlinkIDVerify
#elseif canImport(BlinkID)
import BlinkID
#endif

/// Main scanning view.
/// This view consists of `CameraView` and `Reticle`.
///
/// For `UIEvent` stream, and UX logic, see ``ScanningUXModel``.
public struct BlinkIDUXView: View, ScanningUXProtocol {
    typealias GenericContentView = AnyView
    typealias ButtonContentView = ModifiedContent<Button<AnyView>, AccessibilityAttachmentModifier>?
    typealias ScanResult = BlinkIDScanningResult
    typealias AlertType = BlinkIDScanningAlertType
    typealias UXModel = BlinkIDUXModel

    @ObservedObject var viewModel: BlinkIDUXModel
            
    let theme = BlinkIDTheme.shared
    
    public init(viewModel: BlinkIDUXModel) {
        self.viewModel = viewModel
    }

    public var body: some View {
        MainView(reticleState: $viewModel.reticleState, isTorchOn: $viewModel.isTorchOn, showSheet: $viewModel.showSheet, showScanningAlert: $viewModel.showScanningAlert, showLicenseErrorAlert: $viewModel.showLicenseErrorAlert)
    }
}
