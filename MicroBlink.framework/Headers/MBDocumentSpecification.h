//
//  PPDocument.h
//  BlinkIdFramework
//
//  Created by Jura on 07/01/16.
//  Copyright © 2016 Microblink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Struct which defines a range on the image
 */
typedef struct _MBRange {
    CGFloat start;
    CGFloat stop;
} MBRange;

/**
 * Method which creates a range structure
 */
NS_INLINE MBRange MBMakeRange(CGFloat start, CGFloat stop) {
    MBRange r;
    r.start = start;
    r.stop = stop;
    return r;
}

/**
 * Struct which defines a scale which detector searches on the image
 */
typedef struct _MBScale {
    CGFloat scale;
    CGFloat tolerance;
} MBScale;

/**
 * Method which creates a scale structure
 */
NS_INLINE MBScale MBMakeScale(CGFloat scale, CGFloat tolerance) {
    MBScale r;
    r.scale = scale;
    r.tolerance = tolerance;
    return r;
}

/**
 * Enum of different scanning modes: Landscape, Portrait and Auto(both)
 */
typedef NS_ENUM(NSUInteger, MBScanningMode) {

    /** Detects document in both directions */
    MBScanningModeAuto,

    /** Detects document in landscape direction */
    MBScanningModeLandscape,

    /** Detects document in portrait direction */
    MBScanningModePortrait,
};

/** Presets which can be used to instantiate document specification for a specific document format */
typedef NS_ENUM(NSUInteger, MBDocumentSpecificationPreset) {

    /** Preset for detecting ID1 cards */
    MBDocumentSpecificationId1Card,

    /** Preset for detecting ID2 cards */
    MBDocumentSpecificationId2Card,

    /** Preset for detecting cheques */
    MBDocumentSpecificationCheque,

    /** Preset for detecting A4 documents in portrait */
    MBDocumentSpecificationA4Portrait,

    /** Preset for detecting A4 documents in landscape */
    MBDocumentSpecificationA4Landscape,
    
    /** Preset for detecting vertical ID1 cards */
    MBDocumentSpecificationId1VerticalCard,
    
    /** Preset for detecting vertical ID1 cards */
    MBDocumentSpecificationId2VerticalCard,
};

/**
 * Document class describes a document which is being detected by DocumentDetector.
 * We encurage users to create specifications with one of our presets, if possible.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBDocumentSpecification : NSObject <NSCopying>

/**
 * Use this initializer for specifiying a document format.
 *
 *  @param aspectRatio  Aspect ratio of the document. Calculated as width / height
 *
 *  @return initialized object
 */
- (instancetype)initWithAspectRatio:(CGFloat)aspectRatio physicalSizeInInches:(CGFloat)physicalSizeInInches;


// unavailable initializer
- (instancetype)init NS_UNAVAILABLE;

/**
 * Factory method which creates Document specification based on a preset
 *
 *  @param preset document preset
 *
 *  @return new instance for a given document preset
 */
+ (instancetype)createFromPreset:(MBDocumentSpecificationPreset)preset;

/**
 * Sets scale and scale tolerance that will be used when detecting document in both orientations.
 */
- (void)setPortraitAndLandscapeScale:(MBScale)scale;

/**
 * Maximum angle for document detection
 *
 * Default 25.0
 */
@property (nonatomic, assign) CGFloat maxAngle;

/**
 * Scale and scale tolerance that will be used when detecting document in portrait orientation.
 *
 * Default: MBMakeScale(1.0, 0.0)
 */
@property (nonatomic, assign) MBScale portraitScale;

/**
 * Scale and scale tolerance that will be used when detecting document in landscape orientation.
 *
 * Default: MBMakeScale(1.0, 0.0)
 */
@property (nonatomic, assign) MBScale landscapeScale;

/**
 * Scanning mode that defines in which orientations can this document be detected.
 *
 * Default: PPScanningModeAuto
 */
@property (nonatomic, assign) MBScanningMode scanningMode;

/**
 * Percentage of possible document offset on x axis.
 *
 * Default: MBMakeRange(-1, -1);
 */
@property (nonatomic, assign) MBRange xRange;

/**
 * Percentage of possible document offset on y axis.
 *
 * Default: MBMakeRange(-1, -1);
 */
@property (nonatomic, assign) MBRange yRange;

/**
 * Physical size of document in inches
 */
@property (nonatomic, assign, readonly) CGFloat physicalSizeInInches;

@end

NS_ASSUME_NONNULL_END
