//
//  MBAustraliaDlBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of Australia DL
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBAustraliaDlBackRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The last name of the Australian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The licence number of the Australian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *licenceNumber;

/**
 * The address of the Australian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The document date of expiry of the Australian DL in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDocumentDateOfExpiry;

/**
 * The document date of expiry of the Australian DL
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

@end

NS_ASSUME_NONNULL_END
