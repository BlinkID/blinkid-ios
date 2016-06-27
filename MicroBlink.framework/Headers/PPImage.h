//
//  PPImage.h
//  BlinkIdFramework
//
//  Created by Dino on 25/02/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "Foundation/Foundation.h"
#import "CoreMedia/CoreMedia.h"
#import "PPMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Enum which describes text orientation on an image.
 */
typedef NS_ENUM(NSUInteger, PPProcessingOrientation){
    /** Text oriented same as picture */
    PPProcessingOrientationUp,
    /** Text is rotated 90 degrees clockwise */
    PPProcessingOrientationRight,
    /** Text is upside down */
    PPProcessingOrientationDown,
    /** Text is rotated 90 degrees counterclockwise */
    PPProcessingOrientationLeft,
};

/**
 * Object which represents an image.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPImage : NSObject

/**
 * UIImage of wrapped image.
 * If this PPImage wasn't created with UIImage, UIImage will be created with first access of this property.
 */
@property (nonatomic, readonly) UIImage *image;

/** 
 * Region of the image used for scanning, where the whole image is specified with CGRectMake(0.0, 0.0, 1.0, 1.0).
 */
@property (nonatomic) CGRect roi;

/**
 * Processing orientation of image. This is used in OCR where you can specify character orientation.
 *
 * Default: PPProcessingOrientationUp
 */
@property (nonatomic) PPProcessingOrientation orientation;

/**
 * Tells whether camera input images should be mirrored horizontally before processing
 *
 * Default: NO
 */
@property (nonatomic) BOOL mirroredHorizontally;

/**
 * Tells whether camera input images should be mirrored vertically before processing
 *
 * Default: NO
 */
@property (nonatomic) BOOL mirroredVertically;

/**
 *  Property which tells if this frame is a camera or a single photo frame.
 *  This is important for image processing.
 *
 *  Default: YES
 */
@property (nonatomic) BOOL cameraFrame;

/**
 * Creates PPImage around UIImage.
 */
+ (instancetype)imageWithUIImage:(UIImage *)image;

/**
 * Creates PPImage around CVImageBufferRef.
 */
+ (instancetype)imageWithCmSampleBuffer:(CMSampleBufferRef)buffer;

@end

NS_ASSUME_NONNULL_END
