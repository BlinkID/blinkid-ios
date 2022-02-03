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
    
    /** Object was successfuly detected. */
    MBDetectionStatusSuccess = 1 << 0,
    
    /** Object was not detected */
    MBDetectionStatusFail = 1 << 1,
    
    /** Object was successfully detected, but the camera was too far above the object for processing */
    MBDetectionStatusCameraTooHigh = 1 << 2,
    
    /** Object was successfully detected, but the perspective angle of camera is too high */
    MBDetectionStatusCameraAtAngle = 1 << 3,
    
    /** Object was successfully detected, but the object is rotated and not aligned to the camera edges */
    MBDetectionStatusCameraRotated = 1 << 4,
    
    /** QR code was successfully detected */
    MBDetectionStatusQRSuccess = 1 << 6,
    
    /** PDF417 barcode was successfully detected */
    MBDetectionStatusPdf417Success = 1 << 7,
    
    /** Object was successfully detected using a fallback algorithm */
    MBDetectionStatusFallbackSuccess = 1 << 8,
    
    /** Object was detected, but is only partially visible on screen */
    MBDetectionStatusPartialForm = 1 << 9,
    
    /** Object was successfully detected, but the camera is too near to the object for processing */
    MBDetectionStatusCameraTooNear = 1 << 10,
    
    /** Document detected, but document is too close to the edge of the frame */
    MBDetectionStatusDocumentTooCloseToEdge = 1 << 11,
};
