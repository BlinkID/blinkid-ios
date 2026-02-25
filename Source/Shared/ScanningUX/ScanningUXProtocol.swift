//  Created by Jura Skrlec on 19.02.2025..
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI

#if canImport(BlinkIDVerify)
import BlinkIDVerify
#elseif canImport(BlinkID)
import BlinkID
#elseif canImport(BlinkCard)
import BlinkCard
#endif

@MainActor
/// Protocol defining the core functionality required for document scanning views
protocol ScanningUXProtocol {
    
    associatedtype ScanResult
    associatedtype AlertType: AlertTypeProtocol
    associatedtype EventType
    associatedtype ReticleStateMachineType: ReticleStateMachineProtocol
    associatedtype UXModel: ScanningViewModel<ScanResult, EventType, ReticleStateMachineType, AlertType>
    associatedtype UXTheme: UXThemeProtocol
    associatedtype GenericContentView: View
    associatedtype OnboardingStepType: OnboardingStepProtocol
    
    /// ViewModel used in the document scanning process
    var viewModel: UXModel { get }
    
    /// Diameter of scanning reticle
    static var reticleDiameter: Double { get }
    
    /// Theme used for UI customization
    var theme: UXTheme { get }
    
    /// Builder for Reticle
    func ReticleView(reticleStateMachine: ReticleStateMachineType) -> GenericContentView
    
    /// Builder for whole view
    func MainView(reticleStateMachine: ReticleStateMachineType,
                  isTorchOn: Binding<Bool>,
                  showToast: Binding<Bool>,
                  showSheet: Binding<Bool>,
                  showLicenseErrorAlert: Binding<Bool>,
                  onboardingAlertTitle: String,
                  onboardingAlertDescription: String,
                  onboardingAlertImage: Image,
                  timeoutAlertDescription: String,
                  flashlightWarningMessage: String) -> GenericContentView
    
    /// Builder for the cancel button
    func CancelButton() -> GenericContentView
    
    /// Builder for the torch button
    func TorchButton(image: Image, isOn: Binding<Bool>) -> GenericContentView
    
    /// Builder for the help button
    func HelpButton() -> GenericContentView
}

extension ScanningUXProtocol where Self: View {
    static var reticleDiameter: Double { 88.0 }
    
    @ViewBuilder
    func CancelButton() -> GenericContentView {
        AnyView(
            Button {
                viewModel.closeButtonTapped()
            } label: {
                viewModel.cancelImage
                    .toolbarButton()
            }
                .accessibilityLabel(viewModel.cancelLabel)
                .accessibilityHint(viewModel.cancelHint)
                .accessibilitySortPriority(3)
                .accessibilityHidden(viewModel.showIntroductionAlert)
        ) as! GenericContentView
    }
    
    @ViewBuilder
    func TorchButton(image: Image, isOn: Binding<Bool>) -> GenericContentView {
        AnyView(
            Button {
                viewModel.isTorchOn.toggle()
            } label: {
                image
                    .toolbarButton(isOn: isOn)
            }
                .accessibilityLabel(viewModel.torchLabel)
                .accessibilityHint(viewModel.torchHint)
                .accessibilitySortPriority(2)
                .accessibilityHidden(viewModel.showIntroductionAlert)
        ) as! GenericContentView
    }
    
    @ViewBuilder
    func HelpButton() -> GenericContentView {
        AnyView(
            Button {
                viewModel.helpButtonTapped()
            } label: {
                viewModel.helpImage
                    .themeButton(theme: theme)
            }
                .accessibilityLabel(viewModel.helpLabel)
                .accessibilityHint(viewModel.helpHint)
                .accessibilitySortPriority(1)
                .accessibilityHidden(viewModel.showIntroductionAlert)
        ) as! GenericContentView
    }
    
    @ViewBuilder
    func ReticleView(reticleStateMachine: ReticleStateMachineType) -> GenericContentView {
        createReticleView(reticleStateMachine: reticleStateMachine) as! GenericContentView
    }
    
    @ViewBuilder
    func MainView(reticleStateMachine: ReticleStateMachineType,
                  isTorchOn: Binding<Bool>,
                  showToast: Binding<Bool>,
                  showSheet: Binding<Bool>,
                  showLicenseErrorAlert: Binding<Bool>,
                  onboardingAlertTitle: String,
                  onboardingAlertDescription: String,
                  onboardingAlertImage: Image,
                  timeoutAlertDescription: String,
                  flashlightWarningMessage: String) -> GenericContentView {
        createMainView(reticleStateMachine: reticleStateMachine, isTorchOn: isTorchOn, showToast: showToast, showSheet: showSheet, showLicenseErrorAlert: showLicenseErrorAlert, onboardingAlertTitle: onboardingAlertTitle, onboardingAlertDescription: onboardingAlertDescription, onboardingAlertImage: onboardingAlertImage, timeoutAlertDescription: timeoutAlertDescription, flashlightWarningMessage: flashlightWarningMessage) as! GenericContentView
    }
    
    @ViewBuilder
    private func createMainView(reticleStateMachine: ReticleStateMachineType,
                                isTorchOn: Binding<Bool>,
                                showToast: Binding<Bool>,
                                showSheet: Binding<Bool>,
                                showLicenseErrorAlert: Binding<Bool>,
                                onboardingAlertTitle: String,
                                onboardingAlertDescription: String,
                                onboardingAlertImage: Image,
                                timeoutAlertDescription: String,
                                flashlightWarningMessage: String) -> some View {
        
        AnyView(
            Group {
                if viewModel.camera.status == .unauthorized {
                    CameraPermissionView()
                } else {
                    GeometryReader { geometry in
                        ZStack {
                            CameraView(camera: viewModel.camera)
                                .statusBarHidden(true)
                                .ignoresSafeArea()
                                .zIndex(1)
                            /// - Note: zIndex is necessary because, without it, the OnboardingAlertView does not animate when disappearing
                            ///                                                          (27.6.2025. Toni Kreso)
                            
                            if viewModel.showDemoOverlayImage {
                                VStack {
                                    Spacer()
                                    Image.demoOverlayImage
                                        .offset(y: -Self.reticleDiameter)
                                        .accessibilityHidden(true)
                                    Spacer()
                                }
                                .frame(maxHeight: .infinity)
                                .zIndex(2)
                            }
                            
                            if viewModel.showProductionOverlayImage {
                                VStack {
                                    Spacer()
                                    Image.productionOverlayImage
                                        .accessibilityHidden(true)
                                }
                                .zIndex(3)
                            }
                            
                            VStack(spacing: 8) {
                                Spacer()
                                ReticleView(reticleStateMachine: reticleStateMachine)
                                Spacer()
                            }
                            .offset(y: Self.reticleDiameter / 2)
                            .zIndex(4)
                            
                            VStack {
                                HStack {
                                    CancelButton()
                                    Spacer()
                                    if viewModel.camera.isTorchSupported {
                                        TorchButton(image: viewModel.torchImage, isOn: isTorchOn)
                                    }
                                }
                                Spacer()
                                if viewModel.uxSettings.showHelpButton {
                                    HelpButton(
                                        showTooltip: viewModel.showTooltip,
                                        tooltipText: "mb_need_help_tooltip".localizedString
                                    )
                                }
                            }
                            .disabled(viewModel.showIntroductionAlert)
                            .padding()
                            .zIndex(5)
                            
                            if viewModel.showIntroductionAlert {
                                ZStack {
                                    Color.black.opacity(0.5)
                                        .ignoresSafeArea()
                                        .accessibilityHidden(true)
                                    OnboardingAlertView(theme: self.theme,
                                                        title: onboardingAlertTitle,
                                                        message: onboardingAlertDescription,
                                                        image: onboardingAlertImage,
                                                        dismiss: viewModel.dismissAlert())
                                }
                                .transition(.opacity)
                                .zIndex(6)
                            }
                                
                        }
                    }
                    .onChange(of: reticleStateMachine.reticleState) { newValue in
                        if let text = newValue.text?.localizedString {
                            UIAccessibility.post(notification: .announcement, argument: text)
                        }
                    }
                    .sheet(isPresented: showSheet) {
                        OnboardingSheetView<OnboardingStepType>(theme: self.theme, sessionNumber: viewModel.sessionNumber)
                            .presentationDetents([.height(600)])
                            .interactiveDismissDisabled()
                            .onAppear {
                                viewModel.pauseScanning()
                                Task {
                                    if viewModel.sessionNumber > 0 {
                                        let uxEventPinglet = UxEventPinglet(eventType: .helpopened)
                                        await PingManager.shared.addPinglet(pinglet: uxEventPinglet, sessionNumber: viewModel.sessionNumber)
                                    }
                                }

                            }
                            .onDisappear {
                                viewModel.resumeScanning()
                                viewModel.startTooltipTimer()
                                
                                Task {
                                    if viewModel.sessionNumber > 0 {
                                        let uxEventPinglet = UxEventPinglet(eventType: .helpclosed)
                                        await PingManager.shared.addPinglet(pinglet: uxEventPinglet, sessionNumber: viewModel.sessionNumber)
                                    }

                                }

                            }
                    }
                    .alert(
                        item: Binding(
                            get: { viewModel.alertType },
                            set: { viewModel.alertType = $0 }
                        )
                    ) { alert in
                        Alert(
                            title: Text(alert.title),
                            message: Text(alert.description),
                            dismissButton: .default(Text(alert.buttonTitle))
                        )
                    }
                    .alert("mb_license_locked".localizedString, isPresented: showLicenseErrorAlert) {
                        Button("mb_close".localizedString, role: .cancel) { }
                    }
                    .onTapGesture(count: 2) {
                        viewModel.showTooltip.toggle()
                    }
                    .toast(isShowing: showToast, message: flashlightWarningMessage.localizedString, duration: 3, backgroundColor: self.theme.toastBackgroundColor)
                }
            }
            .task {
                // Start the capture pipeline.
                await viewModel.camera.checkAuthorization(sessionNumber: viewModel.sessionNumber)
                await viewModel.camera.sendConditionsPinglet(sessionNumber: viewModel.sessionNumber)
                await viewModel.camera.sendCameraStartPinglet(sessionNumber: viewModel.sessionNumber)
                await viewModel.camera.start()
                if viewModel.uxSettings.showIntroductionAlert {
                    viewModel.presentAlert()
                } else {
                    viewModel.startScanning()
                }
            }
            .onDisappear {
                viewModel.stopEventHandling()
                viewModel.camera.stopRotationCoordinator()
                Task { @MainActor in
                    await viewModel.camera.stop()
                }
            }
            .onReceive(NotificationCenter.default.publisher(for: UIApplication.willResignActiveNotification)) { _ in
                viewModel.pauseScanning()
            }
            .onReceive(NotificationCenter.default.publisher(for: UIApplication.didBecomeActiveNotification)) { _ in
                viewModel.resumeScanning()
            }
        )
    }
    
    @ViewBuilder
    func HelpButton(showTooltip: Bool, tooltipText: String) -> some View {
        HStack {
            Spacer()
            ZStack(alignment: .bottomTrailing) {
                if showTooltip {
                    VStack(spacing: 0) {
                        ToolTipView(message: tooltipText, foregroundColor: self.theme.helpButtonTooltipForegroundColor, backgroundColor: self.theme.helpButtonTooltipBackgroundColor)
                            .offset(x: -8, y: -45) // Adjust this value to control the spacing between tooltip and button
                            .accessibilityHidden(true)
                    }
                    .animation(.easeInOut(duration: 0.2), value: showTooltip)
                }
                HelpButton()
            }
        }
    }
    
    @ViewBuilder
    private func createReticleView(reticleStateMachine: ReticleStateMachineType) -> some View {
        AnyView(
            Group {
                ZStack {
                    Reticle<ReticleStateMachineType>(diameter: Self.reticleDiameter, reticleStateMachine: reticleStateMachine)
                    if viewModel.showCardImage,
                       let cardImage = viewModel.cardImage {
                        cardImage
                            .resizable()
                            .scaledToFit()
                            .frame(height: 60)
                            .rotation3DEffect(.degrees(viewModel.flipCardDegrees), axis: (x: 0, y: 1, z: 0))
                            .scaleEffect(viewModel.flipCardScale)
                            .accessibilityHidden(true)
                    }
                    if viewModel.showRippleView {
                        Circle()
                            .fill(.white)
                            .frame(height: Self.reticleDiameter)
                            .scaleEffect(viewModel.rippleViewScale)
                            .opacity(viewModel.rippleViewOpacity)
                            .accessibilityHidden(true)
                    }
                    if viewModel.showSuccessImage {
                        viewModel.successImage
                            .resizable()
                            .scaledToFit()
                            .frame(height: Self.reticleDiameter)
                            .symbolRenderingMode(.palette)
                            .foregroundStyle(.black, .white)
                            .scaleEffect(viewModel.successImageScale)
                            .accessibilityHidden(true)
                    }
                }
                .frame(height: 100)
                MessageContainer<ReticleStateMachineType>(theme: self.theme, stateMachine: viewModel.reticleStateMachine)
            }
        )
    }
}
