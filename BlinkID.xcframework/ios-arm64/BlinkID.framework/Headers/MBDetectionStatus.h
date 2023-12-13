//
//  MBDetectionStatus.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 08/12/2017.
//

/**
 * Status of the object detection in Microblink SDK
 */
typedef NS_OPTIONS(NSInteger, MBDetectionStatus) {
    
    /** Detection has failed. */
    MBDetectionStatusFailed,
    
    /** Document has been detected. */
    MBDetectionStatusSuccess,
    
    /** Document has been detected but the camera is too far from the document. */
    MBDetectionStatusCameraTooFar,
    
    /** Document has been detected but the camera is too close to the document. */
    MBDetectionStatusCameraTooClose,
    
    /** Document has been detected but the camera’s angle is too steep. */
    MBDetectionStatusCameraAngleTooSteep,
    
    /** Document has been detected but the document is too close to the camera edge. */
    MBDetectionStatusDocumentTooCloseToCameraEdge,
    
    /** Only part of the document is visible. */
    MBDetectionStatusDocumentPartiallyVisible,
    
    /** Fallback detection was successful (PhotoPay specific). */
    MBDetectionStatusFallbackSuccess
};
