//
//  MBGermanyIdBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyMRTDRecognizerResult.h"

#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of German ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyIdBackRecognizerResult : MBLegacyMRTDRecognizerResult<NSCopying, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * Eye colour
 */
@property (nonatomic, readonly, nullable) NSString *eyeColour;

/**
 * Height in cm
 */
@property (nonatomic, readonly, nullable) NSString *height;

/**
 * Raw date of issue, as written on the ID
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfIssue;

/**
 * Date of issue
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * Issuing authority of the ID
 */
@property (nonatomic, readonly, nullable) NSString *authority;

/**
 * Full address
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * ZIP code
 */
@property (nonatomic, readonly, nullable) NSString *addressZipCode;

/**
 * City
 */
@property (nonatomic, readonly, nullable) NSString *addressCity;

/**
 * Stret name in single line
 */
@property (nonatomic, readonly, nullable) NSString *addressStreet;

/**
 * House number
 */
@property (nonatomic, readonly, nullable) NSString *addressHouseNumber;

@end

NS_ASSUME_NONNULL_END
