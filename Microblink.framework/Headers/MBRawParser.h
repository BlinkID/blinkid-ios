//
//  MBRawParser.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 14/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBParser.h"
#import "MBRawParserResult.h"
#import "MBMicroblinkInitialization.h"
#import "MBBaseOcrEngineOptions.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * MBRawParser that simply returns the string version of raw OCR result, without performing
 * any smart parsing operations.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBRawParser : MBParser <NSCopying>

MB_INIT

/**
 * License plates parser result
 */
@property (nonatomic, strong, readonly) MBRawParserResult *result;

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
 * Sets the OCR engine options used in Regex OCR parser.
 * Returns the OCR engine options used in Regex OCR parser.
 *
 * Default: default instance of MBOcrEngineOptions
 */
@property (nonatomic, strong) MBBaseOcrEngineOptions *ocrEngineOptions;

@end

NS_ASSUME_NONNULL_END
