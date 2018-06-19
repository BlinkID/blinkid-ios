//
//  MBSingaporeCombinedRecognizerResult.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBMicroBlinkDefines.h"
#import "MBLegacyRecognizerResult.h"

#import "MBCombinedRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBDigitalSignatureResult.h"
#import "MBCombinedFullDocumentImageResult.h"

#import "MBEncodedFaceImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning both front and back side of Czech ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSingaporeCombinedRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBFaceImageResult, MBCombinedFullDocumentImageResult, MBDigitalSignatureResult, MBEncodedFaceImageResult, MBEncodedCombinedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The first name of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The name of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The blood group of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *bloodGroup;

/**
 * The sex of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The country of birth of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *countryOfBirth;

/**
 * The race of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *race;

/**
 * The identity card number of Singapore ID.
 */
@property (nonatomic, readonly, nullable) NSString *cardNumber;


/**
 * The date of birth of Singapore ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The date of issue of Singapore ID owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

@end

NS_ASSUME_NONNULL_END
