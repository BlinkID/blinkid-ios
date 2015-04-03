//
//  PPMetadataSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 25/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PPMetadata.h"
#import "PPImageMetadata.h"
#import "PPTextMetadata.h"

/**
 * Settings class containing information which metadata is captured in the scanning process
 */
@interface PPMetadataSettings : NSObject <NSCopying>

/**
 * If YES, currently processed video frame will be captured.
 * TODO: tell which type exactly
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL currentVideoFrame;

/**
 * If YES, image on which scan gave valid scaning result will be saved
 * TODO: tell which type exactly
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL successfulScanFrame;

/**
 * If YES, current video frame, together with frame quality estimation value will be saved
 * TODO: tell which type exactly
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL frameQuality;

/**
 * If YES, grayscale version of the currently processed frame will be captured
 * TODO: tell which type exactly
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL grayscaleFrame;

/**
 * If YES, color dropped version of the currently processed frame will be captured
 * TODO: tell which type exactly
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL colorDroppedFrame;

/**
 * If YES, dewarped images in the recognition process will be saved
 * TODO: tell which type exactly
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL dewarpedImage;

/**
 * If YES, detection image in the recognition processed will be saved
 * TODO: tell which type exactly
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL detectionImage;

/**
 * If YES, OCR data in xml form will be saved
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL ocrData;

/**
 * If YES, Recognition data in xml form will be saved
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL recognitionData;

/**
 * If YES, device data in xml form will be saved
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL deviceData;

/**
 * Designated initializer. Initializes the object with default settings (see above for defaults)
 *
 *  @return object initialized with default values.
 */
- (instancetype)init;

@end
