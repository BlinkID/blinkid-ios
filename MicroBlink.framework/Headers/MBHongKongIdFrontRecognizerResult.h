//
//  MBHongKongIdFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Hong Kong ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBHongKongIdFrontRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFaceImageResult, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The full name of the Hong Kong ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *fullName;

/**
 * The commerical Code of the Hong Kong ID.
 */
@property (nonatomic, readonly, nullable) NSString *commercialCode;

/**
 * The date of birth of the Hong Kong ID ownder.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The sex of the Hong Kong ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The issue date of the Hong Kong ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The document number of the Hong Kong card.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

@end

NS_ASSUME_NONNULL_END
