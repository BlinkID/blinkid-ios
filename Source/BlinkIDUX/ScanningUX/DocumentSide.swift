//  Created by Toni Krešo on 19.02.2026..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

/// Represents different sides of a document during the scanning process.
public enum DocumentSide: Sendable, Equatable {
    /// Front side of the document
    case front
    /// Back side of the document
    case back
    /// Barcode region of the document
    case barcode
    /// Document is passport
    case passport(PassportOrientation)
    /// Barcode from last page of passports
    case passportBarcode
}
