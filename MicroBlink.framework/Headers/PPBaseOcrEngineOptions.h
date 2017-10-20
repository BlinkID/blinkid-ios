//
//  PPBaseOcrEngineOptions.h
//  BlinkInputDev
//
//  Created by Jura Skrlec on 09/08/2017.
//
//

#import <Foundation/Foundation.h>

#import "PPMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Options used for OCR process. These options enable you to customize how some OCR parsers work.
 * For example, you can set character whitelists, character height, supported fonts etc.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPBaseOcrEngineOptions : NSObject

/**
 * Minimal height of the line of text given in pixels. All chars smaller than this value will be ignored.
 *
 * Setting the minimal line height can reduce the noise in OCR results.
 *
 * Default: 10
 */
@property (nonatomic, assign) NSUInteger minimalLineHeight;

/**
 * Maximal height of the line of text given in pixels.
 *
 * Setting the maximal line height can reduce the noise in OCR results.
 *
 * Default: 200
 */
@property (nonatomic, assign) NSUInteger maximalLineHeight;

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
