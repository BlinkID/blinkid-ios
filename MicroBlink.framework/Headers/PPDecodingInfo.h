//
//  PPDecodingInfo.h
//  BlinkIdFramework
//
//  Created by Jura on 09/01/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PPMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Object describing a part of the document which is being processed (decoded) in the recognition process.
 * Decoding info defines which part of the detected document is being processed (location property). In the processing
 * stage, this part of the image is being dewarped to a standardized resolution, and the height of the dewarped image
 * is also defined in this object (dewarpedHeight)
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPDecodingInfo : NSObject

/**
 * Location of the decoded element on the detected document.
 *
 * For example, if the whole document should be decoded, then location should be set to CGRectMake(0.0, 0.0, 1.0, 1.0);
 * If just the upper left quarter of the image should be decoded, location sholud be set to CGRectMake(0.0, 0.0, 0.25, 0.25);
 */
@property (nonatomic, assign) CGRect location;

/**
 * Part of the origin image defined with location property, in the processing stage is being dewarped to a standardized resolution.
 * Dewarped height defines the height of that image.
 *
 * For example, ID documents are usually dewarped to a height of 750 pixels.
 */
@property (nonatomic, assign) CGFloat dewarpedHeight;

/**
 * Unique identifier of the entry.
 */
@property (nonatomic, strong) NSString *uniqueId;

/**
 * Constructor which initializes decoding info entry. Specifies location of the entry, and dewarped height.
 *
 *  @param location       location of the decoding info entry on the detected document.
 *  @param dewarpedHeight height of the dewarped image
 *  @param uniqueId     identifier of the entry
 *
 *  @return initialized object.
 */
- (instancetype)initWithLocation:(CGRect)location
                  dewarpedHeight:(CGFloat)dewarpedHeight
                        uniqueId:(NSString *)uniqueId NS_DESIGNATED_INITIALIZER;

/**
 * Please use designated initializer.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
