//
//  MBNoUpScalingDewarpPolicy.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 21/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBDewarpPolicy.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * No upscaling dewarp policy. Dewarp height will be calculated in a way
 * that no part of image will be up-scaled. However, if dewarp height
 * calculated in this way is larger than value defined by maxAllowedDewarpHeight,
 * then maxAllowedDewarpHeight will be used for dewarp height, effectively scaling
 * down the image.
 *
 * This policy is usually best for processor groups that use DEEP OCR,
 * hologram detection or NN-based classification.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBNoUpScalingDewarpPolicy : MBDewarpPolicy

/**
 * Default max allowed dewarp height used when using default constructor.
 */
- (instancetype)init;

/**
 * @param maxAllowedDewarpHeight Max allowed dewarp height.
 */
- (instancetype)initWithMaxAllowedDewarpHeight:(NSUInteger)maxAllowedDewarpHeight NS_DESIGNATED_INITIALIZER;

/**
 * Returns the max allowed dewarp height as specified by this policy.
 *
 * Default: 400
 */
@property (nonatomic, assign, readonly) NSUInteger maxAllowedDewarpHeight;

@end

NS_ASSUME_NONNULL_END
