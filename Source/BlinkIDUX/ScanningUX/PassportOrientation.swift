//  Created by Toni Krešo on 19.02.2026..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

/// Represents passport rotation orientation depending on View interface and a document card rotation property.
///
/// See ``DocumentRotation``.
public enum PassportOrientation: Sendable, Equatable {
    case none
    case left90
    case right90
}
