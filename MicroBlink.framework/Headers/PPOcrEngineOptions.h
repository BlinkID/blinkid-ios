//
//  PPOcrEngineOptions.h
//  BlinkOcrFramework
//
//  Created by Jura on 30/04/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PPOcrFont.h"
#import "PPMicroBlinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing a char in specific font.
 *
 * @example char 'k' in font Arial
 *  
 *     PPOcrCharKey* key = [[PPOcrCharKey alloc] initWithCode:'k' font:PP_OCR_FONT_ARIAL];
 *
 * @example char 'ü' in any font
 *  
 *     PPOcrCharKey* key = [[PPOcrCharKey alloc] initWithCode:'ü' font:PP_OCR_FONT_ANY];
 *
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPOcrCharKey : NSObject

/**
 * Unicode value of the char. For example, for char 'k', you can use either 'k' or 107.
 */
@property (nonatomic, assign) int code;

/**
 * Font of the char. Can be specific (for example PP_OCR_FONT_ARIAL), or any font (PP_OCR_FONT_ANY), which is the same
 * as specifying the same char code with all supported fonts.
 */
@property (nonatomic, assign) PPOcrFont font;

/**
 * Initializer which specifies the code and font of the char.
 *
 *  @param code Unicode value for the char
 *  @param font Font of the char
 *
 *  @return initialized char key
 */
- (instancetype)initWithCode:(int)code
                        font:(PPOcrFont)font;

/**
 * Factory method for easier instantiation
 *
 *  @param code Unicode value for the char
 *  @param font Font of the char
 *
 *  @return initialized char key
 */
+ (instancetype)keyWithCode:(int)code
                       font:(PPOcrFont)font;

@end

typedef struct OcrEngineOptionsImpl OcrEngineOptionsImpl;

/**
 * Options used for OCR process
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPOcrEngineOptions : NSObject <NSCopying>

/**
 * Internal implementation
 */
@property (nonatomic, readonly, assign) OcrEngineOptionsImpl* options;

/**
 * Minimal height of the line of text given in pixels. All chars smaller than this value will be ignored.
 *
 * Setting the minimal line height can reduce the noise in OCR results.
 *
 * Default: 15
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
 * Default: YES
 */
@property (nonatomic, assign) BOOL colorDropoutEnabled;

/**
 * Specifies if the image processing is performed on image 
 *
 * By default it's set to true.
 * Disable it only if you perform your own image processing.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL imageProcessingEnabled;

/**
 * Specifies if line grouping (collecting adjacent chars into lines) is enabled.
 *
 * Since grouping works perfectly well when the lines are parallel to the image edges, 
 * the only reason why you would like to set this to NO is to develop your own grouping method, when lines
 * are slanted on the image.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL lineGroupingEnabled;

/**
 * Whitelist of characters used in the OCR process. The set must contain PPOcrCharKey objects.
 *
 * Default: all chars with all fonts.
 */
@property (nonatomic, strong) NSSet* charWhitelist;


@end

NS_ASSUME_NONNULL_END