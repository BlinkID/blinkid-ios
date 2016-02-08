//
//  PPCameraSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 23/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import "PPMicroBlinkDefines.h"

/**
 * Camera resolution preset
 */
typedef NS_ENUM(NSUInteger, PPCameraPreset) {

    /** 480p video will always be used */
    PPCameraPreset480p,

    /** 720p video will always be used */
    PPCameraPreset720p,

    /** The library will calculate optimal resolution based on the use case and device used */
    PPCameraPresetOptimal,

    /** Device's maximal video resolution will be used. */
    PPCameraPresetMax,

    /** Device's photo preview resolution will be used */
    PPCameraPresetPhoto,
};

/**
 * Camera type
 */
typedef NS_ENUM(NSUInteger, PPCameraType) {

    /** Back facing camera */
    PPCameraTypeBack,

    /** Front facing camera */
    PPCameraTypeFront
};

/**
 * Camera autofocus restricion mode
 */
typedef NS_ENUM(NSUInteger, PPCameraAutofocusRestriction) {

    /** Default. Indicates that the autofocus system should not restrict the focus range. */
    PPCameraAutofocusRestrictionNone,

    /** Indicates that the autofocus system should restrict the focus range for subject matter that is near to the camera. */
    PPCameraAutofocusRestrictionNear,

    /** Indicates that the autofocus system should restrict the focus range for subject matter that is far from the camera. */
    PPCameraAutofocusRestrictionFar,
};

/**
 * Settings class containing parameters for camera capture
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPCameraSettings : NSObject <NSCopying>

/**
 * Camera preset. With this property you can set the resolution of the camera
 * 
 * Default: PPCameraPresetOptimal
 */
@property (nonatomic, assign) PPCameraPreset cameraPreset;

/**
 * Camera type. You can choose between front and back facing.
 * 
 * Default: PPCameraTypeBack
 */
@property (nonatomic, assign) PPCameraType cameraType;

/**
 * Interval between forcing two camera focuses. If <= 0, forced focuses arent performed
 * and only continuous autofocus mode will be used.
 * 
 * Default
 *  - 10.0f for BlinkID and BlinkOCR product
 *  - 3.2f for PhotoPay product
 *  - 5.0f for Pdf417 product
 *  - 0.0f for PhotoMath product
 */
@property (nonatomic, assign) NSTimeInterval autofocusInterval;

/**
 * Range restriction for camera autofocus.
 *
 * Default: PPCameraAutofocusRestrictionNone
 */
@property (nonatomic, assign) PPCameraAutofocusRestriction cameraAutofocusRestriction;

/**
 * Gravity of Camera preview on screen.
 *
 * Default: AVLayerVideoGravityResizeAspectFill
 */
@property (nonatomic, weak) NSString *videoGravity;

/**
 * Point against which the autofocus will be performed
 *
 * Default (0.5f, 0.5f) - middle of the screen.
 */
@property (nonatomic, assign) CGPoint focusPoint;

/**
 * Designated initializer. Initializes the object with default settings (see above for defaults)
 *
 *  @return object initialized with default values.
 */
- (instancetype)init;

/**
 * Returns an optimal AVFoundation session preset based on cameraPreset value.
 *
 * @return optimal AVFoundation session preset
 */
- (NSString *)calcSessionPreset;

/**
 * Returns an optimal AVFoundation autofocus range restriction value based on cameraAutofocusRestriction.
 *
 * @return optimal AVFoundation autofocus range restriction
 */
- (AVCaptureAutoFocusRangeRestriction)calcAutofocusRangeRestriction;

@end
