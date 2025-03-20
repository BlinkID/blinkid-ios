//
//  ViewModifiers.swift
//  DocumentVerificationUX
//
//  Created by Jura Skrlec on 12.12.2024..
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI

struct ToolbarButton: ViewModifier {
    @Binding var isOn: Bool
    
    func body(content: Content) -> some View {
        content
            .font(.title3)
            .foregroundStyle(isOn ? Color.mbTooltipBackground : .white)
            .bold()
            .padding(8)
            .background {
                Circle()
                    .fill()
                    .foregroundStyle(isOn ? .white : Color.mbTooltipBackground)
            }
            .padding(4)
    }
}

struct ThemeButton: ViewModifier {
    let theme: any UXThemeProtocol
    
    func body(content: Content) -> some View {
        content
            .font(.largeTitle)
            .imageScale(.medium)
            .symbolRenderingMode(.palette)
            .foregroundStyle(theme.helpButtonForegroundColor, theme.helpButtonBackgroundColor)
    }
}

extension View {
    func toolbarButton(isOn: Binding<Bool> = Binding.constant(false)) -> some View {
        modifier(ToolbarButton(isOn: isOn))
    }
    
    func themeButton(theme: any UXThemeProtocol) -> some View {
        modifier(ThemeButton(theme: theme))
    }
}
