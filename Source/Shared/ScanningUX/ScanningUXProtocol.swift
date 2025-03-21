//  Created by Jura Skrlec on 19.02.2025..
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI

@MainActor
/// Protocol defining the core functionality required for document scanning views
protocol ScanningUXProtocol {
    
    associatedtype ScanResult
    associatedtype AlertType: AlertTypeProtocol
    associatedtype UXModel: ScanningViewModel<ScanResult, AlertType>
    associatedtype UXTheme: UXThemeProtocol
    associatedtype ButtonContentView: View
    associatedtype GenericContentView: View
    
    /// ViewModel used in the document scanning process
    var viewModel: UXModel { get }
    
    /// Diameter of scanning reticle
    static var reticleDiameter: Double { get }
    
    /// Theme used for UI customization
    var theme: UXTheme { get }
    
    /// Builder for Reticle
    func ReticleView(reticleState: Binding<ReticleState>) -> AnyView
    
    /// Builder for the cancel button
    func CancelButton() -> ButtonContentView
    
    /// Builder for the torch button
    func TorchButton(image: Image, isOn: Binding<Bool>) -> ButtonContentView
    
    /// Builder for the help button
    func HelpButton() -> ButtonContentView
}

extension ScanningUXProtocol where Self: View {
    static var reticleDiameter: Double { 88.0 }
    
    @ViewBuilder
    func CancelButton() -> ButtonContentView {
        Button {
            viewModel.closeButtonTapped()
        } label: {
            viewModel.cancelImage
                .toolbarButton()
        }
        .accessibilityLabel(viewModel.cancelLabel)
        .accessibilityHint(viewModel.cancelHint)
        .accessibilitySortPriority(3)
        .accessibilityHidden(viewModel.showIntroductionAlert) as! ButtonContentView
    }
    
    @ViewBuilder
    func TorchButton(image: Image, isOn: Binding<Bool>) -> ButtonContentView {
        Button {
            viewModel.isTorchOn.toggle()
        } label: {
            image
                .toolbarButton(isOn: isOn)
        }
        .accessibilityLabel(viewModel.torchLabel)
        .accessibilityHint(viewModel.torchHint)
        .accessibilitySortPriority(2)
        .accessibilityHidden(viewModel.showIntroductionAlert) as! ButtonContentView
    }
    
    @ViewBuilder
    func HelpButton() -> ButtonContentView {
        Button {
            viewModel.helpButtonTapped()
        } label: {
            viewModel.helpImage
                .themeButton(theme: theme)
        }
        .accessibilityLabel(viewModel.helpLabel)
        .accessibilityHint(viewModel.helpHint)
        .accessibilitySortPriority(1)
        .accessibilityHidden(viewModel.showIntroductionAlert) as! ButtonContentView
    }
    
    @ViewBuilder
    func ReticleView(reticleState: Binding<ReticleState>) -> GenericContentView {
        createReticleView(reticleState: reticleState) as! GenericContentView
    }
    
    @ViewBuilder
    func MainView(reticleState: Binding<ReticleState>,
                  isTorchOn: Binding<Bool>,
                  showSheet: Binding<Bool>,
                  showScanningAlert: Binding<Bool>,
                  showLicenseErrorAlert: Binding<Bool>) -> some View {
        createMainView(reticleState: reticleState, isTorchOn: isTorchOn, showSheet: showSheet, showScanningAlert: showScanningAlert, showLicenseErrorAlert: showLicenseErrorAlert) as! GenericContentView
    }
    
    @ViewBuilder
    private func createMainView(reticleState: Binding<ReticleState>,
                                isTorchOn: Binding<Bool>,
                                showSheet: Binding<Bool>,
                                showScanningAlert: Binding<Bool>,
                                showLicenseErrorAlert: Binding<Bool>) -> some View {
        Group {
            if viewModel.camera.status == .unauthorized {
                CameraPermissionView()
            } else {
                GeometryReader { geometry in
                    ZStack {
                        CameraView(camera: viewModel.camera)
                            .statusBarHidden(true)
                            .ignoresSafeArea()
                        VStack(spacing: 8) {
                            ReticleView(reticleState: reticleState)
                            Spacer()
                        }
                        .offset(y: geometry.size.height / 2 - Self.reticleDiameter / 2)
                        VStack {
                            HStack {
                                CancelButton()
                                Spacer()
                                if viewModel.camera.isTorchSupported {
                                    TorchButton(image: viewModel.torchImage, isOn: isTorchOn)
                                }
                            }
                            Spacer()
                            HStack {
                                Spacer()
                                HelpButton()
                            }
                        }
                        .disabled(viewModel.showIntroductionAlert)
                        .padding()
                        
                        if viewModel.showIntroductionAlert {
                            OnboardingAlertView(theme: self.theme,
                                                dimiss: viewModel.dismissAlert())
                            .transition(.move(edge: .bottom))
                        }
                    }
                }
                .onChange(of: viewModel.reticleState) { newValue in
                    if let text = newValue.text {
                        UIAccessibility.post(notification: .announcement, argument: text)
                    }
                }
                .sheet(isPresented: showSheet) {
                    OnboardingSheetView(theme: self.theme)
                        .presentationDetents([.height(600)])
                        .onAppear {
                            viewModel.pauseScanning()
                        }
                        .onDisappear {
                            viewModel.resumeScanning()
                        }
                }
                .alert(isPresented: showScanningAlert) {
                    Alert(
                        title: Text("mb_recognition_timeout_dialog_title".localizedString),
                        message: Text("mb_recognition_timeout_dialog_message".localizedString),
                        dismissButton: .default(Text("mb_recognition_timeout_dialog_retry_button".localizedString))
                    )
                }
                .alert("mb_license_locked".localizedString, isPresented: showLicenseErrorAlert) {
                    Button("mb_close".localizedString, role: .cancel) { }
                }
            }
        }
        .task {
            // Start the capture pipeline.
            await viewModel.camera.start()
            await viewModel.analyze()
            print("Starting")
        }
        .onAppear {
            if viewModel.shouldShowIntroductionAlert {
                viewModel.presentAlert()
            } else {
                UIAccessibility.post(notification: .screenChanged, argument: ReticleState.front.text)
            }
        }
            .onDisappear {
                viewModel.stopEventHandling()
                viewModel.camera.stopRotationCoordinator()
                Task { @MainActor in
                    await viewModel.camera.stop()
                }
            }
    }
    
    @ViewBuilder
    private func createReticleView(reticleState: Binding<ReticleState>) -> some View {
        ZStack {
            Reticle(diameter: Self.reticleDiameter, reticleState: reticleState)
            if viewModel.showCardImage {
                viewModel.cardImage
                    .resizable()
                    .scaledToFit()
                    .frame(height: 60)
                    .rotation3DEffect(.degrees(viewModel.flipCardDegrees), axis: (x: 0, y: 1, z: 0))
                    .scaleEffect(viewModel.flipCardScale)
            }
            if viewModel.showRippleView {
                Circle()
                    .fill(.white)
                    .frame(height: Self.reticleDiameter)
                    .scaleEffect(viewModel.rippleViewScale)
                    .opacity(viewModel.rippleViewOpacity)
            }
            if viewModel.showSuccessImage {
                viewModel.successImage
                    .resizable()
                    .scaledToFit()
                    .frame(height: Self.reticleDiameter)
                    .symbolRenderingMode(.palette)
                    .foregroundStyle(.black, .white)
                    .scaleEffect(viewModel.successImageScale)
            }
        }
        .frame(height: 100)
        if let text = viewModel.reticleState.text?.localizedString {
            MessageContainer(theme: self.theme, text: text)
                .accessibilityHidden(true)
        }
    }
}
