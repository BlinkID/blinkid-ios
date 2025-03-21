//  Created by Toni Krešo on 22.11.2024.. 
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI

struct OnboardingSheetView: View {
    @Environment(\.presentationMode) var presentationMode
    @State var selected: Int = 0
    private let theme: any UXThemeProtocol
    
    init(theme: any UXThemeProtocol) {
        self.theme = theme
    }
    
    var body: some View {
        VStack {
            HStack {
                Button {
                    decreaseStep()
                } label: {
                    Text(selected == 0 ? "mb_close".localizedString : "mb_dialog_back_button".localizedString)
                        .font(theme.onboardingSheetButtonFont)
                        .foregroundStyle(theme.onboardingSheetButtonColor)
                }
                .accessibilitySortPriority(3)
                Spacer()
                Button {
                    increaseStep()
                } label: {
                    Text(selected == OnboardingStep.allCases.count - 1 ? "mb_dialog_done_button".localizedString : "mb_dialog_next_button".localizedString)
                        .bold()
                        .font(theme.onboardingSheetButtonFont)
                        .foregroundStyle(theme.onboardingSheetButtonColor)
                }
                .accessibilitySortPriority(2)
            }
            Divider()
                .padding(.horizontal, -20)
            TabView(selection: $selected) {
                ForEach(OnboardingStep.allCases) { onboardingStep in
                    TabItemView(theme: self.theme, onboardingStep: onboardingStep)
                        .tag(onboardingStep.rawValue)
                }
            }
            .accessibilitySortPriority(4)
            .tabViewStyle(.page(indexDisplayMode: .never))
            
            Spacer()
            
            PageControlView(currentPage: $selected, numberOfPages: OnboardingStep.allCases.count, currentPageIndicatorColor: UIColor(theme.onboardingSheetPageIndicatorColor), pageIndicatorColor: UIColor(theme.onboardingSheetPageIndicatorColor).withAlphaComponent(0.5))
                .accessibilitySortPriority(1)
        }
        .padding(20)
        .background {
            theme.onboardingSheetBackgroundColor.ignoresSafeArea()
        }
    }
    
    private func increaseStep() {
        guard selected < OnboardingStep.allCases.count - 1
        else {
            presentationMode.wrappedValue.dismiss()
            return
        }
        
        withAnimation {
            selected += 1
        }
    }
    
    private func decreaseStep() {
        guard selected > 0
        else {
            presentationMode.wrappedValue.dismiss()
            return
        }
        withAnimation {
            selected -= 1
        }
    }
}

struct TabItemView: View {
    let onboardingStep: OnboardingStep
    @State private var orientation = UIDevice.current.orientation
    @State private var contentHeight: CGFloat = 40
    private let theme: any UXThemeProtocol
    
    init(theme: any UXThemeProtocol, onboardingStep: OnboardingStep) {
        self.theme = theme
        self.onboardingStep = onboardingStep
    }
    
    var body: some View {
        Group {
            if orientation.isPortrait || orientation == .unknown || orientation.isFlat {
                VStack(spacing: 30) { bodyContent }
            } else {
                HStack(alignment: .center, spacing: 30) { bodyContent }
            }
        }
        .padding()
        .onRotate { newOrientation in
            orientation = newOrientation
        }
    }
    
    var bodyContent: Group< some View > {
        Group {
            onboardingStep.image
                .resizable()
                .scaledToFit()
                .frame(width: 220)
                .accessibilityHidden(true)
            ScrollView {
                VStack(alignment:.leading, spacing: 16) {
                    Text(onboardingStep.title.localizedString)
                        .bold()
                        .font(theme.onboardingSheetTitleFont)
                        .foregroundStyle(theme.onboardingSheetTitleColor)
                        .accessibilitySortPriority(2)
                    Text(onboardingStep.description.localizedString)
                        .font(theme.onboardingSheetDescriptionFont)
                        .foregroundStyle(theme.onboardingSheetDescriptionColor)
                        .accessibilitySortPriority(1)
                }
                .overlay(
                    GeometryReader { geo in
                        Color.clear.preference(key: HeightPreferenceKey.self, value: geo.size.height)
                    })
            }
            .frame(maxHeight: contentHeight, alignment: .center)
            .onPreferenceChange(HeightPreferenceKey.self) {
                contentHeight = $0
            }
            Spacer()
        }
    }
}

struct HeightPreferenceKey: PreferenceKey {
    typealias Value = CGFloat
    static var defaultValue: CGFloat = 40
    static func reduce(value: inout CGFloat, nextValue: () -> CGFloat) {
        value = nextValue()
    }
}

struct DeviceRotationViewModifier: ViewModifier {
    let action: (UIDeviceOrientation) -> Void

    func body(content: Content) -> some View {
        content
            .onReceive(NotificationCenter.default.publisher(for: UIDevice.orientationDidChangeNotification)) { _ in
                action(UIDevice.current.orientation)
            }
    }
}

extension View {
    func onRotate(perform action: @escaping (UIDeviceOrientation) -> Void) -> some View {
        self.modifier(DeviceRotationViewModifier(action: action))
    }
}
