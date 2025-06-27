//  Created by Toni Krešo on 24.02.2025..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

/// Scanning alert type
public enum BlinkIDScanningAlertType: Sendable, AlertTypeProtocol {
    /// Scanning session timed out.
    case timeout
    /// Class was filtered out with ClassFilter.
    case disallowedClass
    
    public var title: String {
        switch self {
        case .timeout:
            return "mb_recognition_timeout_dialog_title".localizedString
        case .disallowedClass:
            return "mb_document_class_filtered_dialog_title".localizedString
        }
    }
    
    public var description: String {
        switch self {
        case .timeout:
            return "mb_recognition_timeout_dialog_message".localizedString
        case .disallowedClass:
            return "mb_document_class_filtered_dialog_message".localizedString
        }
    }
}
