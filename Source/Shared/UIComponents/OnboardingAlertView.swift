//  Created by Toni Krešo on 06.12.2024.. 
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI

struct OnboardingAlertView: View {
    @Environment(\.horizontalSizeClass) var horizontalSizeClass
    @Environment(\.verticalSizeClass) var verticalSizeClass
    @State private var contentHeight: CGFloat = 40
    
    private let theme: any UXThemeProtocol
    private let title: String
    private let message: String
    private let image: Image
    private let dismiss: () -> Void
    
    init(theme: any UXThemeProtocol, title: String, message: String, image: Image, dismiss: @autoclosure @escaping () -> Void) {
        self.theme = theme
        self.title = title
        self.message = message
        self.image = image
        self.dismiss = dismiss
    }
    
    var body: some View {
        VStack(spacing: 0) {
            if isPortrait {
                VStack(alignment: .center) { bodyContent }
                    .padding(.horizontal, 16)
                    .padding(.vertical, 24)
                    .accessibilitySortPriority(6)
            } else {
                HStack(alignment: .center) { bodyContent }
                    .padding(.horizontal, 16)
                    .padding(.vertical, 24)
                    .accessibilitySortPriority(6)
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
            .accessibilitySortPriority(5)
        }
        .background(theme.alertBackgroundColor)
        .clipShape(
            RoundedRectangle(cornerRadius: 14.0)
        )
        .padding(50)
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .onAppear {
            UIAccessibility.post(notification: .screenChanged, argument: titleText)
        }
    }
    
    @ViewBuilder
    var bodyContent: some View {
        if !isPortrait {
            alertImage
        }
        
        ScrollView {
            VStack(alignment: isPortrait ? .center : .leading, spacing: 10) {
                titleText
                if isPortrait {
                    alertImage
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
        horizontalSizeClass == .compact && verticalSizeClass == .regular
    }
    
    var titleText: some View {
        Text(title.localizedString)
            .bold()
            .font(theme.alertTitleFont)
            .multilineTextAlignment(isPortrait ? .center : .leading)
            .foregroundStyle(theme.alertTitleColor)
            .accessibilitySortPriority(2)
            .accessibilityHeading(.h1)
    }
    
    var descriptionText: some View {
        Text(message.localizedString)
            .font(theme.alertDescriptionFont)
            .multilineTextAlignment(isPortrait ? .center : .leading)
            .foregroundStyle(theme.alertDescriptionColor)
            .accessibilitySortPriority(1)
    }
    
    var alertImage: some View {
        image
            .resizable()
            .scaledToFit()
            .frame(width: 220)
            .accessibilityHidden(true)
    }
}
