//
//  DetectionStatus.h
//  PhotoPayFramework
//
//  Created by Jurica Cerovec on 5/12/13.
//  Copyright (c) 2013 MicroBlink Ltd. All rights reserved.
//

#ifndef PhotoPayFramework_DetectionStatus_h
#define PhotoPayFramework_DetectionStatus_h

/**
 * Status of the object detection in MicroBlink SDK
 */
typedef NS_ENUM(NSInteger, PPDetectionStatus) {

    /** Object was successfuly detected. */
    PPDetectionStatusSuccess            = 1<<0,

    /** Object was not detected */
    PPDetectionStatusFail               = 1<<1,

    /** Object was successfully detected, but the camera was too far above the object for processing */
    PPDetectionStatusCameraTooHigh      = 1<<2,

    /** Object was successfully detected, but the perspective angle of camera is too high */
    PPDetectionStatusCameraAtAngle      = 1<<3,

    /** Object was successfully detected, but the object is rotated and not aligned to the camera edges */
    PPDetectionStatusCameraRotated      = 1<<4,

    /** QR code was successfully detected */
    PPDetectionStatusQRSuccess          = 1<<6,

    /** PDF417 barcode was successfully detected */
    PPDetectionStatusPdf417Success      = 1<<7,

    /** Object was successfully detected using a fallback algorithm */
    PPDetectionStatusFallbackSuccess    = 1<<8,

    /** Object was detected, but is only partially visible on screen */
    PPDetectionStatusPartialForm        = 1<<9,

    /** Object was successfully detected, but the camera is too near to the object for processing */
    PPDetectionStatusCameraTooNear      = 1<<10,
};

// Ignore unused method warning
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wall"

/**
 * Method converts PPDetectionStatus value to NSString
 *
 *  @param status Detection status value for which NSString is required
 *
 *  @return NSString value for PPDetectionStatus value
 */
static NSString* stringFromDetectionStatus(PPDetectionStatus status) {

    NSString* defaultString =  @"Detection status: ";
    NSString* res = [NSString stringWithString:defaultString];

    if (status & PPDetectionStatusSuccess) {
        res = [res stringByAppendingString:@"Success\n"];
    }
    if (status & PPDetectionStatusFail) {
        res = [res stringByAppendingString:@"Fail\n"];
    }
    if (status & PPDetectionStatusCameraTooHigh) {
        res = [res stringByAppendingString:@"Camera too high\n"];
    }
    if (status & PPDetectionStatusCameraAtAngle) {
        res = [res stringByAppendingString:@"Camera at angle\n"];
    }
    if (status & PPDetectionStatusCameraRotated) {
        res = [res stringByAppendingString:@"Camera rotated\n"];
    }
    if (status & PPDetectionStatusQRSuccess) {
        res = [res stringByAppendingString:@"QR success\n"];
    }
    if (status & PPDetectionStatusPdf417Success) {
        res = [res stringByAppendingString:@"PDF417 success\n"];
    }
    if (status & PPDetectionStatusFallbackSuccess) {
        res = [res stringByAppendingString:@"Fallback sucess\n"];
    }
    if (status & PPDetectionStatusPartialForm) {
        res = [res stringByAppendingString:@"Partial form\n"];
    }
    if ([res length] == [defaultString length]) {
        res = @"No value!";
    }
    
    return res;
}

#pragma clang diagnostic pop

#endif
