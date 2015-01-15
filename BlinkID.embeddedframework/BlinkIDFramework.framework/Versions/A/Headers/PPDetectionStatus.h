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
 * Detection status enum.
 * Used in UI.
 */
typedef enum _PPDetectionStatus {
    PPDetectionStatusSuccess 			= 1<<0, // Payment form detected
    PPDetectionStatusFail 				= 1<<1, // Detection failed, form not detected
    PPDetectionStatusCameraTooHigh      = 1<<2, // Form detected, but the camera is too far above the payment form
    PPDetectionStatusCameraAtAngle      = 1<<3, // Form detected, but the perspective angle of camera is too high
    PPDetectionStatusCameraRotated      = 1<<4, // Form detected, but the payment form is rotated and not aligned to the camera edges
    PPDetectionStatusQRSuccess          = 1<<6, // QR code detected
    PPDetectionStatusPdf417Success      = 1<<7, // PDF417 code detected
    PPDetectionStatusFallbackSuccess    = 1<<8, // Detection from fallback
    PPDetectionStatusPartialForm        = 1<<9  // Form detected, but only partially visible on screen
} PPDetectionStatus;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wall"

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
