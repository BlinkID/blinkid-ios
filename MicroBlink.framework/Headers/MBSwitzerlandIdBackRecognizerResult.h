//
//  MBSwitzerlandIdBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyMRTDRecognizerResult.h"

#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of Swiss ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSwitzerlandIdBackRecognizerResult : MBLegacyMRTDRecognizerResult<NSCopying, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

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
@property (nonatomic, readonly, nullable) NSString *authority;

/**
 * The document date of issue of the Swiss ID in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDocumentDateOfIssue;

/**
 * The document date of issue of the Swiss ID.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The document date of issue of the Swiss ID in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDocumentDateOfExpiry;

/**
 * The document date of issue of the Swiss ID.
 */
@property (nonatomic, readonly, nullable) NSDate *nonMrzDateOfExpiry;

/**
 * The address of the Swiss ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nonMrzSex;

@end

NS_ASSUME_NONNULL_END
