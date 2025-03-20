//  Created by Toni Krešo on 06.12.2024.. 
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI

struct OnboardingAlertView: View {

    @State private var orientation = UIDevice.current.orientation
    @State private var contentHeight: CGFloat = 40
    private let theme: any UXThemeProtocol
    private let dismiss: () -> Void
    
    init(theme: any UXThemeProtocol, dimiss: @autoclosure @escaping () -> Void) {
        self.theme = theme
        self.dismiss = dimiss
    }
    
    var body: some View {
        VStack(spacing: 0) {
            if isPortrait {
                VStack(alignment: .center) { bodyContent }
                    .padding(.horizontal, 16)
                    .padding(.vertical, 24)
                    .accessibilitySortPriority(2)
            } else {
                HStack(alignment: .center) { bodyContent }
                    .padding(.horizontal, 16)
                    .padding(.vertical, 24)
                    .accessibilitySortPriority(2)
            }
            Divider()
            Button {
                dismiss()
            } label: {
                Text("mb_dialog_done_button".localizedString)
                    .bold()
                    .font(theme.alertButtonFont)
                    .foregroundStyle(theme.alertButtonColor)
                    .frame(maxWidth: .infinity)
            }
            .padding(.vertical, 10)
            .accessibilitySortPriority(1)
        }
        .background(theme.alertBackgroundColor)
        .clipShape(
            RoundedRectangle(cornerRadius: 14.0)
        )
        .padding(50)
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .onRotate { newOrientation in
            orientation = newOrientation
        }
    }
    
    @ViewBuilder
    var bodyContent: some View {
        if !isPortrait {
            image
        }
        
        ScrollView {
            VStack(alignment: isPortrait ? .center : .leading, spacing: 10) {
                titleText
                if isPortrait {
                    image
                }
                descriptionText
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
    }
    
    var isPortrait: Bool {
        orientation.isPortrait || orientation == .unknown || orientation.isFlat
    }
    
    var titleText: some View {
        Text("mb_onboarding_dialog_title".localizedString)
            .bold()
            .font(theme.alertTitleFont)
            .multilineTextAlignment(isPortrait ? .center : .leading)
            .foregroundStyle(theme.alertTitleColor)
            .accessibilitySortPriority(2)
    }
    
    var descriptionText: some View {
        Text("mb_onboarding_dialog_message".localizedString)
            .font(theme.alertDescriptionFont)
            .multilineTextAlignment(isPortrait ? .center : .leading)
            .foregroundStyle(theme.alertDescriptionColor)
            .accessibilitySortPriority(1)
    }
    
    var image: some View {
        Image.allDetailsVisibleImage
            .resizable()
            .scaledToFit()
            .frame(width: 220)
            .accessibilityHidden(true)
    }
}
