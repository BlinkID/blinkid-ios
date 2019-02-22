//
//  MBOcrEngineOptions.h
//  BlinkOcrFramework
//
//  Created by Jura on 30/04/15.
//  Copyright (c) 2015 Microblink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MBOcrFont.h"
#import "MBMicroblinkDefines.h"
#import "MBBaseOcrEngineOptions.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing a char in specific font.
 *
 * @example char 'k' in font Arial
 *
 *     MBOcrCharKey* key = [[MBOcrCharKey alloc] initWithCode:'k' font:MB_OCR_FONT_ARIAL];
 *
 * @example char 'ü' in any font
 *
 *     MBOcrCharKey* key = [[MBOcrCharKey alloc] initWithCode:'ü' font:MB_OCR_FONT_ANY];
 *
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBOcrCharKey : NSObject

/**
 * Unicode value of the char. For example, for char 'k', you can use either 'k' or 107.
 */
@property (nonatomic, assign) int code;

/**
 * Font of the char. Can be specific (for example MB_OCR_FONT_ARIAL), or any font (MB_OCR_FONT_ANY), which is the same
 * as specifying the same char code with all supported fonts.
 */
@property (nonatomic, assign) MBOcrFont font;

/**
 * Initializer which specifies the code and font of the char.
 *
 *  @param code Unicode value for the char
 *  @param font Font of the char
 *
 *  @return initialized char key
 */
- (instancetype)initWithCode:(int)code font:(MBOcrFont)font;

/**
 * Factory method for easier instantiation
 *
 *  @param code Unicode value for the char
 *  @param font Font of the char
 *
 *  @return initialized char key
 */
+ (instancetype)keyWithCode:(int)code font:(MBOcrFont)font;

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
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBOcrEngineOptions : MBBaseOcrEngineOptions <NSCopying>

/**
 * Creates MBOcrEngineOptions with default settings.
 */
- (instancetype)init;

/**
 * Type of document scanned.
 *
 * Default: PPBlinkOCRDocumentType
 */
@property (nonatomic, assign) PPDocumentType documentType;

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
 * Specifies if the image processing is performed on image
 *
 * By default it's set to true.
 * Disable it only if you perform your own image processing.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL imageProcessingEnabled;

/**
 * Whitelist of characters used in the OCR process. The set must contain MBOcrCharKey objects.
 *
 * Default: all chars with all fonts.
 */
@property (nonatomic, strong) NSSet<MBOcrCharKey *> *charWhitelist;


@end

NS_ASSUME_NONNULL_END
