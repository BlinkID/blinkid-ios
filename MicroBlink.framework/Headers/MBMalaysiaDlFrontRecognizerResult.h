//
//  MBMalaysiaDlFrontRecognizerResult.h
//  MicroblinkDev
//
//  Created by juraskrlec on 20/09/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of the Malaysia Dl
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMalaysiaDlFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The city of the front side of the Malaysia Dl owner.
 */
@property (nonatomic, readonly) NSString *city;

/**
 * The dl Class of the front side of the Malaysia Dl owner.
 */
@property (nonatomic, readonly) NSString *dlClass;

/**
 * The full Address of the front side of the Malaysia Dl owner.
 */
@property (nonatomic, readonly) NSString *fullAddress;

/**
 * The identity Number of the front side of the Malaysia Dl owner.
 */
@property (nonatomic, readonly) NSString *identityNumber;

/**
 * The name of the front side of the Malaysia Dl owner.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * The nationality of the front side of the Malaysia Dl owner.
 */
@property (nonatomic, readonly) NSString *nationality;

/**
 * The owner State of the front side of the Malaysia Dl owner.
 */
@property (nonatomic, readonly) NSString *ownerState;

/**
 * The street of the front side of the Malaysia Dl owner.
 */
@property (nonatomic, readonly) NSString *street;

/**
 * The valid From of the front side of the Malaysia Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *validFrom;

/**
 * The valid Until of the front side of the Malaysia Dl owner.
 */
@property (nonatomic, readonly) MBDateResult *validUntil;

/**
 * The zipcode of the front side of the Malaysia Dl owner.
 */
@property (nonatomic, readonly) NSString *zipcode;

@end

NS_ASSUME_NONNULL_END
