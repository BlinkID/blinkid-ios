//
//  PPSwissIDBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 04/08/2017.
//
//

#import "PPMrtdRecognizerResult.h"

/**
 * Result of scanning with Swiss ID Back side recognizer
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSwissIDBackRecognizerResult : PPMrtdRecognizerResult

/**
 * The address of the Swiss ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *placeOfOrigin;

/**
 * The address of the Swiss ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *height;

/**
 * The issuing authority of Swiss ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The document date of issue of the Swiss ID in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDocumentDateOfIssue;

/**
 * The document date of issue of the Swiss ID.
 */
@property (nonatomic, readonly, nullable) NSDate *documentDateOfIssue;

/**
 * The document date of issue of the Swiss ID in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDocumentDateOfExpiry;

/**
 * The document date of issue of the Swiss ID.
 */
@property (nonatomic, readonly, nullable) NSDate *documentDateOfExpiry;

/**
 * The address of the Swiss ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

@end
