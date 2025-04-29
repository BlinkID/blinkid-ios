//
//  UXTheme.swift
//  DocumentVerificationUX
//
//  Created by Jura Skrlec on 19.02.2025..
//

import SwiftUI

public protocol UXThemeProtocol {
    
    // Alert Theme
    var alertTitleColor: Color { get }
    var alertTitleFont: Font { get }
    var alertDescriptionColor: Color { get }
    var alertDescriptionFont: Font { get }
    var alertButtonColor: Color { get }
    var alertButtonFont: Font { get }
    var alertBackgroundColor: Color { get }
    
    // Onboarding Sheet Theme
    var onboardingSheetTitleColor: Color { get }
    var onboardingSheetTitleFont: Font { get }
    var onboardingSheetDescriptionColor: Color { get }
    var onboardingSheetDescriptionFont: Font { get }
    var onboardingSheetButtonColor: Color { get }
    var onboardingSheetButtonFont: Font { get }
    var onboardingSheetPageIndicatorColor: Color { get }
    var onboardingSheetBackgroundColor: Color { get }
    
    // Reticle Theme
    var reticleTooltipFont: Font { get }
    
    // Help Button Theme
    var helpButtonForegroundColor: Color { get }
    var helpButtonBackgroundColor: Color { get }
    
    // Need Help Button Tooltip
    var helpButtonTooltipForegroundColor: Color { get }
    var helpButtonTooltipBackgroundColor: Color { get }
    
    // Toast
    var toastBackgroundColor: Color { get }
}
