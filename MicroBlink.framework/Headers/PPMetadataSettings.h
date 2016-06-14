//
//  PPMetadataSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 25/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PPMicroBlinkDefines.h"

#import "PPMetadata.h"
#import "PPImageMetadata.h"
#import "PPTextMetadata.h"

NS_ASSUME_NONNULL_BEGIN

@class PPDebugMetadata;

/**
 * Settings class containing information which metadata is captured in the scanning process
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPMetadataSettings : NSObject <NSCopying>

/**
 * If YES, currently processed video frame will be captured.
 * TODO: tell which type exactly
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL currentFrame;

/**
 * If YES, image on which scan gave valid scaning result will be saved
 * TODO: tell which type exactly
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL successfulFrame;

/**
 * If YES, dewarped images in the recognition process will be saved
 * TODO: tell which type exactly
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL dewarpedImage;

/**
 * If not nil, this object will tell which debug metadata should be saved
 *
 * Default: instance obtained using PPDebugMetadata init method.
 */
@property (nonatomic, strong) PPDebugMetadata* debugMetadata;

/**
 * Designated initializer. Initializes the object with default settings (see above for defaults)
 *
 *  @return object initialized with default values.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end

@interface PPDebugMetadata : NSObject <NSCopying>

/**
 * If YES, image whichs shows debug information about document detection will be saved
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL debugDetectionFrame;

/**
 * If YES, image which is used as an input for the OCR will be saved
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL debugOcrInputFrame;

/**
 * If YES, images with dewarped elements will be saved
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL debugDewarpedElements;

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
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
