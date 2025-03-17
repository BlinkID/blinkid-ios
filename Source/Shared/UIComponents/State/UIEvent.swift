//  Created by Toni Krešo on 13.11.2024..
//  Copyright (c) Microblink. All rights reserved.
//  This code is provided for use as-is and may not be copied, modified, or redistributed.
//

/// Events that represent different states and user guidance during document scanning.
public enum UIEvent: Equatable, Sendable {
    /// Request to scan a specific side of the document
    case requestDocumentSide(side: DocumentSide)
    
    /// Indicates the wrong side of the document is being presented
    case wrongSide
    
    /// Camera image is too blurry for accurate document detection
    case blur
    
    /// Light reflection is interfering with document capture
    case glare
    
    /// Part of document is occluded
    case occlusion
    
    /// Document is not parallel to the camera plane
    case tilt
    
    /// Document is too close to the camera
    case tooClose
    
    /// Document is too far from the camera
    case tooFar
    
    /// Document is positioned too close to the screen edges
    case tooCloseToEdge
    
    /// Document is partially outside the camera frame
    case notFullyVisible
}
