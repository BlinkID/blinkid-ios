//  Created by Toni Krešo on 17.09.2025..
//  Copyright (c) Microblink. All rights reserved.
//  Modifications are allowed under the terms of the license for files located in the UX/UI lib folder.
//

import Foundation

public struct ScanningUXSettings {
    /// Determines if alert will be shown when scanning start.
    let showIntroductionAlert: Bool
    
    /// Determines if help button for raising an onboarding sheet will be shown.
    let showHelpButton: Bool
    
    /// The preferred camera position to use when capturing document.
    /// This value represents the user’s choice of front or back camera.
    /// The system determines the actual physical camera device.
    let preferredCameraPosition: Camera.CameraPosition
    
    /// Determines whether haptic feedback is played for scanning-related events.
    ///
    /// When enabled, haptic responses are generated during scanning activities,
    /// such as detection updates or user interactions (e.g., toggling the flashlight).
    /// When disabled, no haptic feedback is produced.
    let allowHapticFeedback: Bool
    
    public init(showIntroductionAlert: Bool = true, showHelpButton: Bool = true, preferredCameraPosition: Camera.CameraPosition = .back, allowHapticFeedback: Bool = true) {
        self.showIntroductionAlert = showIntroductionAlert
        self.showHelpButton = showHelpButton
        self.preferredCameraPosition = preferredCameraPosition
        self.allowHapticFeedback = allowHapticFeedback
    }
}
