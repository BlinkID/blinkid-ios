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
#import "PPBaseOcrEngineOptions.h"

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
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPOcrCharKey : NSObject

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
- (instancetype)initWithCode:(int)code font:(PPOcrFont)font;

/**
 * Factory method for easier instantiation
 *
 *  @param code Unicode value for the char
 *  @param font Font of the char
 *
 *  @return initialized char key
 */
+ (instancetype)keyWithCode:(int)code font:(PPOcrFont)font;

@end

/**
 * Type of the document which recognizer scans
 */
typedef NS_ENUM(NSUInteger, PPDocumentType) {

    /** Document type for latin documents used with BlinkOCR recognizer */
    PPBlinkOCRDocumentType,

    /** Document type for MICR font */
    PPMicrDocumentType,

    /** Document type for Arabic characters */
    PPArabicDocumentType,

    /** Document type for handwriting */
    PPHandwrittenDocumentType
};

/**
 * Options used for OCR process. These options enable you to customize how some OCR parsers work.
 * For example, you can set character whitelists, character height, supported fonts etc.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPOcrEngineOptions : PPBaseOcrEngineOptions <NSCopying>

/**
 * Creates PPOcrEngineOptions with default settings.
 */
- (instancetype)init;

/**
 * Type of document scanned.
 *
 * Default: PPBlinkOCRDocumentType
 */
@property (nonatomic, assign) PPDocumentType documentType;

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
 * Whitelist of characters used in the OCR process. The set must contain PPOcrCharKey objects.
 *
 * Default: all chars with all fonts.
 */
@property (nonatomic, strong) NSSet<PPOcrCharKey *> *charWhitelist;


@end

NS_ASSUME_NONNULL_END
