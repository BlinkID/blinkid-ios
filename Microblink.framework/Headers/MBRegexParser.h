//
//  MBRegexParser.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 15/03/2018.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"
#import "MBParser.h"
#import "MBRegexParserResult.h"
#import "MBMicroblinkInitialization.h"
#import "MBBaseOcrEngineOptions.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a parser which parses OCR result according to given regular expression.
 * Regular expression parsing is not performed with java's regex engine. Instead, it is performed
 * with custom regular expression engine which can work with multiple char recognition alternatives
 * (if enabled in MBBaseOcrEngineOptions). Due to differences between parsing normal strings
 * and OCR results, this parser does not support some regex features found in java's regex engine,
 * like back references.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBRegexParser : MBParser <NSCopying>

MB_INIT_UNAVAILABLE

/**
 * Initializes the regex parser
 *
 *  @param regex regular expression pattern for extraction
 */
- (instancetype)initWithRegex:(NSString *)regex NS_DESIGNATED_INITIALIZER;

/**
 * Regex parser result
 */
@property (nonatomic, strong, readonly) MBRegexParserResult *result;

/**
 * Defines regex that will be used to parse OCR data. Note that not all java regex features
 * are available, such as back references and '^' and '$' meta-character. '.' meta-character
 * that represents any character and '^' inside brackets representing all characters except those
 * in brackets are available only if alphabet is defined.
 */
@property (nonatomic, strong) NSString *regex;

/**
 * Enable the usage of algorithm for combining consecutive OCR results between video frames
 * for improving OCR quality. By default this is turned off.
 
 * Note: This option works together only with if instance of {@link com.microblink.entities.ocrengine.legacy.BlinkOCREngineOptions} is given
 * to {@link #setOcrEngineOptions(com.microblink.entities.ocrengine.AbstractOCREngineOptions)}. Otherwise, it will not be
 * enabled and {@link IllegalArgumentException} will be thrown.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL useSieve;

/**
 * If set to YES, regex will not be matched if there is no whitespace before matched string.
 * Whitespace is not returned in parsed result.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL startWithWhitespace;

/**
 * If set to YES, regex will not be matched if there is no whitespace after matched string.
 * Whitespace is not returned in parsed result.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL endWithWhitespace;

/**
 * Sets the OCR engine options used in Regex OCR parser.
 * Returns the OCR engine options used in Regex OCR parser.
 *
 * Default: default instance of MBOcrEngineOptions
 */
@property (nonatomic, strong) MBBaseOcrEngineOptions *ocrEngineOptions;

@end

NS_ASSUME_NONNULL_END
