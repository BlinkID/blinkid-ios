//
//  PPDocument.h
//  BlinkIdFramework
//
//  Created by Jura on 07/01/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PPDocumentDecodingInfo.h"

NS_ASSUME_NONNULL_BEGIN

struct DocumentImpl;
typedef struct DocumentImpl DocumentImpl;

/**
 * Struct which defines a range on the image
 */
typedef struct _PPRange {
    CGFloat start;
    CGFloat stop;
} PPRange;

/**
 * Method which creates a range structure
 */
NS_INLINE PPRange PPMakeRange(CGFloat start, CGFloat stop) {
    PPRange r;
    r.start = start;
    r.stop = stop;
    return r;
}

/**
 * Struct which defines a scale which detector searches on the image
 */
typedef struct _PPScale {
    CGFloat scale;
    CGFloat tolerance;
} PPScale;

/**
 * Method which creates a scale structure
 */
NS_INLINE PPScale PPMakeScale(CGFloat scale, CGFloat tolerance) {
    PPScale r;
    r.scale = scale;
    r.tolerance = tolerance;
    return r;
}

/**
 * Enum of different scanning modes: Landscape, Portrait and Auto(both)
 */
typedef NS_ENUM(NSUInteger, PPScanningMode) {

    /** Detects document in both directions */
    PPScanningModeAuto,

    /** Detects document in landscape direction */
    PPScanningModeLandscape,

    /** Detects document in portrait direction */
    PPScanningModePortrait,
};

/** Presets which can be used to instantiate document specification for a specific document format */
typedef NS_ENUM(NSUInteger, PPDocumentPreset) {

    /** Preset for detecting ID cards */
    PPDocumentPresetId1Card,

    /** Preset for detecting cheques */
    PPDocumentPresetCheque,

    /** Preset for detecting A4 documents in portrait */
    PPDocumentPresetA4Portrait,

    /** Preset for detecting A4 documents in landscape */
    PPDocumentPresetA4Landscape,
};

/**
 * Document class describes a document which is being detected by DocumentDetector.
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPDocumentSpecification : NSObject<NSCopying>

// internal implementation
@property (nonatomic, readonly, assign) DocumentImpl *documentImpl;

/**
 * Use this initializer for specifiying a document format.
 *
 *  @param aspectRatio  Aspect ratio of the document. Calculated as width / height
 *  @param decodingInfo Decoding info for the document
 *
 *  @return initialized object
 */
- (instancetype)initWithAspectRatio:(CGFloat)aspectRatio
                       decodingInfo:(PPDocumentDecodingInfo *)decodingInfo;

// used for internal initialization
- (instancetype)initWithDocument:(DocumentImpl *)documentImpl NS_DESIGNATED_INITIALIZER;

// unavailable initializer
- (instancetype)init NS_UNAVAILABLE;

/**
 * Factory method which creates Document specification based on a preset
 *
 *  @param preset document preset
 *
 *  @return new instance for a given document preset
 */
+ (instancetype)newFromPreset:(PPDocumentPreset)preset;

/**
 * Sets scale and scale tolerance that will be used when detecting document in both orientations.
 */
- (void)setPortraitAndLandscapeScale:(PPScale)scale;

/**
 * Sets the decoding information
 *
 *  @param decodingInfo decoding information
 */
- (void)setDecodingInfo:(PPDocumentDecodingInfo *)decodingInfo;

/**
 * Maximum angle for document detection
 *
 * Default 25.0
 */
@property (nonatomic, assign) CGFloat maxAngle;

/**
 * Scale and scale tolerance that will be used when detecting document in portrait orientation.
 *
 * Default: PPMakeScale(1.0, 0.0)
 */
@property (nonatomic, assign) PPScale portraitScale;

/**
 * Scale and scale tolerance that will be used when detecting document in landscape orientation.
 *
 * Default: PPMakeScale(1.0, 0.0)
 */
@property (nonatomic, assign) PPScale landscapeScale;

/**
 * Scanning mode that defines in which orientations can this document be detected.
 *
 * Default: PPScanningModeAuto
 */
@property (nonatomic, assign) PPScanningMode scanningMode;

/**
 * Percentage of possible document offset on x axis.
 *
 * Default: PPMakeRange(-1, -1);
 */
@property (nonatomic, assign) PPRange xRange;

/**
 * Percentage of possible document offset on y axis.
 *
 * Default: PPMakeRange(-1, -1);
 */
@property (nonatomic, assign) PPRange yRange;

@end

NS_ASSUME_NONNULL_END