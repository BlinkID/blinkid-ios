//
//  MBSingaporeCombinedRecognizerResult.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBDigitalSignatureResult.h"

#import "MBCombinedRecognizerResult.h"
#import "MBCombinedFullDocumentImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning both front and back side of Czech ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSingaporeCombinedRecognizerResult : MBRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBDigitalSignatureResult, MBCombinedFullDocumentImageResult, MBEncodedCombinedFullDocumentImageResult, MBFaceImageResult, MBEncodedFaceImageResult>

MB_INIT_UNAVAILABLE

/**
 * The identity card number of the Singaporean ID card.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The name of the Singaporean ID card owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The race of the Singaporean ID card owner.
 */
@property (nonatomic, readonly, nullable) NSString *race;

/**
 * The sex of the Singaporean ID card owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The date of birth of the Singaporean ID card owner.
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfBirth;

/**
 * The country/place of birth of the Singaporean ID card owner.
 */
@property (nonatomic, readonly, nullable) NSString *countryOfBirth;

/**
 * The address of the back side of the Singapore Id owner.
 */
@property (nonatomic, readonly) NSString *address;

/**
 * The address Change Date of the back side of the Singapore Id owner.
 */
@property (nonatomic, readonly) MBDateResult *addressChangeDate;

/**
 * The blood Type of the back side of the Singapore Id owner.
 */
@property (nonatomic, readonly) NSString *bloodGroup;

/**
 * The date Of Issue of the back side of the Singapore Id owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

@end

NS_ASSUME_NONNULL_END
