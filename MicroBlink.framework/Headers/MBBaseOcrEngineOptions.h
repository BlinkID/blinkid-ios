//
//  PPBaseOcrEngineOptions.h
//  BlinkInputDev
//
//  Created by Jura Skrlec on 09/08/2017.
//
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Options used for OCR process. These options enable you to customize how some OCR parsers work.
 * For example, you can set character whitelists, character height, supported fonts etc.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBaseOcrEngineOptions : NSObject

/**
 * Maximal chars expected on the image.
 *
 * Setting this value can speed up the OCR processing because all images with more chars than specified will be ignored
 * (becuase in most cases they are noise)
 *
 * Default: 3000
 */
@property (nonatomic, assign) NSUInteger maxCharsExpected;

/**
 * Specifies if the additional image processing which drops the background colors should be performed.
 *
 * Use this if you have black text on color backgrounds.
 * If you have black text on white background, using this is not needed as it slows down processing.
 * If you have color text, don't use it at all because color dropout will remove the text.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL colorDropoutEnabled;

@end

NS_ASSUME_NONNULL_END
