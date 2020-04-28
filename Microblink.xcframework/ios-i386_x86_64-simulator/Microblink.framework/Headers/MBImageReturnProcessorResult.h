//
//  MBImageReturnProcessorResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 23/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBProcessorResult.h"

@class MBImage;

NS_ASSUME_NONNULL_BEGIN

/**
 * Processor that will simply save given image.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBImageReturnProcessorResult : MBProcessorResult <NSCopying>

MB_INIT_UNAVAILABLE

/**
 * Returns the raw image saved by the processor. If no image was saved by processor, returns null.
 * NOTE: Internal buffers of the returned image are valid as long as Result object (this) is alive.
 */
@property (nonatomic, strong, readonly, nullable) MBImage *rawImage;

/**
 * JPEG-encoded image or nil, depending on whether image encoding was enabled.
 */
@property (nonatomic, strong, readonly, nullable) NSData *encodedImage;

@end

NS_ASSUME_NONNULL_END
