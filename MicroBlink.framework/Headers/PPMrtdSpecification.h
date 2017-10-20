//
//  PPMrtdSpecification.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 18/10/2017.
//

#import <Foundation/Foundation.h>
#import "PPDecodingInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Enum of different detection code types
 */
typedef NS_ENUM(NSUInteger, PPMrtdDetectionCodeType) {
    
    /**
     * MRZ - Machine Readable Zone
     * MRTD - Machine Readable Travel Document (Full Card)
     *
     * TD1 - Three Machine Readable Lines with 30 characters each
     * TD2 - Two Machine Readable Lines with 36 characters each
     * TD3 - Two Machine Readable Lines with 44 characters each
     */
    
    PPMrtdDetectionCodeTypeMrzTd1,
    PPMrtdDetectionCodeTypeMrzTd2,
    PPMrtdDetectionCodeTypeMrzTd3,
    PPMrtdDetectionCodeTypeMrtdTd1,
    PPMrtdDetectionCodeTypeMrtdTd2,
    PPMrtdDetectionCodeTypeMrtdTd3
};

/** Presets which can be used to instantiate mrtd specification for a specific mrtd format */
typedef NS_ENUM(NSUInteger, PPMrtdPreset) {
    
    /** Preset for detecting TD1 cards */
    PPMrtdPresetTd1,
    
    /** Preset for detecting TD2 cards */
    PPMrtdPresetTd2,
    
    /** Preset for detecting TD3 cards */
    PPMrtdPresetTd3,
    
};

/**
 * Mrtd class describes a document which is being detected by MrtdDetector.
 * We encurage users to create specifications with one of our presets, if possible.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPMrtdSpecification : NSObject <NSCopying>

/**
 * Use this initializer for specifiying a mrtd format.
 *
 *  @param mrtdDetectionCodeType Type of detection code of Mrz/Mrtd
 *  @param physicalSizeInInches Pyshical size in inches of Mrz/Mrtd
 *  @return initialized object
 */
- (instancetype)initWithMrtdDetectionCode:(PPMrtdDetectionCodeType)mrtdDetectionCodeType decodingInfo:(NSArray<PPDecodingInfo *> *)decodingInfoArray physicalSizeInInches:(CGFloat)physicalSizeInInches;


// unavailable initializer
- (instancetype)init NS_UNAVAILABLE;

/**
 * Factory method which creates MRTD specification based on a preset
 *
 *  @param preset mrtd preset
 *
 *  @return new instance for a given mrtd preset
 */
+ (instancetype)newFromPreset:(PPMrtdPreset)preset;

/**
 * Sets the decoding information
 *
 *  @param decodingInfoArray decoding information
 */
- (void)setDecodingInfo:(NSArray<PPDecodingInfo *> *)decodingInfoArray;

/**
 * Detection code that defines MRTD Detector Type.
 *
 */
@property (nonatomic, assign, readonly) PPMrtdDetectionCodeType mrtdDetectionCodeType;

/**
 * Physical size of document in inches
 */
@property (nonatomic, assign, readonly) CGFloat physicalSizeInInches;

@end

NS_ASSUME_NONNULL_END
