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
    
    /** Object was not detected */
    MBDetectionStatusFail,
    
    /** Object was successfuly detected. */
    MBDetectionStatusSuccess,
    
    /** Object was successfully detected, but the camera was too far above the object for processing */
    MBDetectionStatusCameraTooHigh,
    
    /** Object was successfully detected using a fallback algorithm */
    MBDetectionStatusFallbackSuccess,
    
    /** Object was detected, but is only partially visible on screen */
    MBDetectionStatusPartialForm,

    /** Object was successfully detected, but the perspective angle of camera is too high */
    MBDetectionStatusCameraAtAngle,
    
    /** Object was successfully detected, but the camera is too near to the object for processing */
    MBDetectionStatusCameraTooNear,
    
    /** Document detected, but document is too close to the edge of the frame */
    MBDetectionStatusDocumentTooCloseToEdge,
};
