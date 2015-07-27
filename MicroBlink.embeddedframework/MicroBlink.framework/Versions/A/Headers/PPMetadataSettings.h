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
 * If YES, image which is used as an input for the OCR will be saved
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL ocrInputImage;

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
