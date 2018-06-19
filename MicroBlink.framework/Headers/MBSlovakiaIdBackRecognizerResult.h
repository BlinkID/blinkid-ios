//
//  MBSlovakiaIdBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyMRTDRecognizerResult.h"

#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of Slovak ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSlovakiaIdBackRecognizerResult : MBLegacyMRTDRecognizerResult<NSCopying, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The address of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The surname at birth of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *surnameAtBirth;

/**
 * The place of birth of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * The special remarks of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *specialRemarks;

@end

NS_ASSUME_NONNULL_END