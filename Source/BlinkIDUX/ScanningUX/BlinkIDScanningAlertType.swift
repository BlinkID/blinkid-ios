//  Created by Toni Krešo on 24.02.2025..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

#if canImport(BlinkIDVerify)
import BlinkIDVerify
#elseif canImport(BlinkID)
import BlinkID
#endif

/// Scanning alert type
public enum BlinkIDScanningAlertType: Int, Sendable, AlertTypeProtocol {
    public var id: Int { rawValue }
    
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
    
    public var buttonTitle: String {
        switch self {
        case .timeout, .disallowedClass:
            return "mb_recognition_timeout_dialog_retry_button".localizedString
        }
    }
    
    public var pingletAlertType: UxEventPinglet.AlertType {
        switch self {
        case .timeout:
            return .steptimeout
        case .disallowedClass:
            return .documentclassnotallowed
        }
    }
}
