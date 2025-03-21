//  Created by Toni Krešo on 22.11.2024.. 
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import SwiftUI

enum OnboardingStep: Int, CaseIterable, Identifiable {
    case allFieldsVisible, harshLight, keepStill
    
    var id: Int { rawValue }
    
    var image: Image {
        switch self {
        case .allFieldsVisible:
            return Image.allFieldsVisibleImage
        case .harshLight:
            return Image.harshLightImage
        case .keepStill:
            return Image.keepStillImage
        }
    }
    
    var title: String {
        switch self {
        case .allFieldsVisible:
            return "mb_help_screen_title1"
        case .harshLight:
            return "mb_help_screen_title2"
        case .keepStill:
            return "mb_help_screen_title3"
        }
    }
    
    var description: String {
        switch self {
        case .allFieldsVisible:
            return "mb_help_screen_msg1"
        case .harshLight:
            return "mb_help_screen_msg2"
        case .keepStill:
            return "mb_help_screen_msg3"
        }
    }
}
