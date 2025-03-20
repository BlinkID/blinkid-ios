//
//  Color.swift
//  DocumentVerificationUX
//
//  Created by Jura Skrlec on 16.01.2025..
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI

public enum MicroblinkColor: String {
    case secondary = "verify_secondary"
    case primary = "verify_primary"
    case tooltipBackground = "verify_tooltip_background"
    case helpBackground = "verify_help_background"
    case background = "verify_background"
}

extension Color {
    public init(_ mbColor: MicroblinkColor) {
        self.init(mbColor.rawValue, bundle: Bundle.frameworkBundle)
    }
    
    static let mbSecondary = Color(MicroblinkColor.secondary)
    static let mbPrimary = Color(MicroblinkColor.primary)
    static let mbTooltipBackground = Color(MicroblinkColor.tooltipBackground)
    static let mbHelpBackground = Color(MicroblinkColor.helpBackground)
    static let mbBackground = Color(MicroblinkColor.background)
}
