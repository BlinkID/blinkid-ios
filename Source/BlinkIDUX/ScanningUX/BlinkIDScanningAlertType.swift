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
            return "Scan unsuccessful"
        case .disallowedClass:
            return "Document not accepted"
        }
    }
    
    public var description: String {
        switch self {
        case .timeout:
            return "Unable to read the document. Please try again."
        case .disallowedClass:
            return "Try scanning a different document."
        }
    }
}
