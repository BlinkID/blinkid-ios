//
//  MBUnitedArabEmiratesDlFrontRecognizerResult.h
//  MicroblinkDev
//
//  Created by juraskrlec on 21/08/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of the United Arab Emirates Dl
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBUnitedArabEmiratesDlFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The date Of Birth of the front side of the United Arab Emirates Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
 * The expiry Date of the front side of the United Arab Emirates Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *expiryDate;

/**
 * The issue Date of the front side of the United Arab Emirates Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *issueDate;

/**
 * The license Number of the front side of the United Arab Emirates Dl owner.
 */
@property (nonatomic, readonly) NSString *licenseNumber;

/**
 * The licensing Authority of the front side of the United Arab Emirates Dl owner.
 */
@property (nonatomic, readonly) NSString *licensingAuthority;

/**
 * The name of the front side of the United Arab Emirates Dl owner.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * The nationality of the front side of the United Arab Emirates Dl owner.
 */
@property (nonatomic, readonly) NSString *nationality;

/**
 * The place Of Issue of the front side of the United Arab Emirates Dl owner.
 */
@property (nonatomic, readonly) NSString *placeOfIssue;

@end

NS_ASSUME_NONNULL_END
