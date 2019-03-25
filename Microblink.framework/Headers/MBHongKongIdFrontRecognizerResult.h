//
//  MBHongKongIdFrontRecognizerResult.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Hong Kong ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBHongKongIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

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
@property (nonatomic, readonly, nullable) MBDateResult *dateOfBirth;

/**
 * The sex of the Hong Kong ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The issue date of the Hong Kong ID owner.
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfIssue;

/**
 * The document number of the Hong Kong card.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The residential status of the Hong Kong ID.
 */
@property (nonatomic, readonly, nullable) NSString *residentialStatus;

@end

NS_ASSUME_NONNULL_END
