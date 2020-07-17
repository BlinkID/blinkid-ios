//
//  MBMrtdSpecification.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 18/10/2017.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/** Presets which can be used to instantiate mrtd specification for a specific mrtd format */
typedef NS_ENUM(NSInteger, MBMrtdSpecificationPreset) {
    
    /** Preset for detecting TD1 cards */
    MBMrtdSpecificationTd1,
    
    /** Preset for detecting TD2 cards */
    MBMrtdSpecificationTd2,
    
    /** Preset for detecting TD3 cards */
    MBMrtdSpecificationTd3,
    
};

/**
 * Mrtd class describes a document which is being detected by MrtdDetector.
 * We encurage users to create specifications with one of our presets, if possible.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBMrtdSpecification : NSObject <NSCopying>

- (instancetype)init NS_UNAVAILABLE;

/**
 * Factory method which creates MRTD specification based on a preset
 *
 *  @param preset mrtd preset
 *
 *  @return new instance for a given mrtd preset
 */
+ (instancetype)createFromPreset:(MBMrtdSpecificationPreset)preset;

@end

NS_ASSUME_NONNULL_END
