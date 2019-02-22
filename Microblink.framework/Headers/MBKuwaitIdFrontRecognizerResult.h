//
//  MBKuwaitIdFrontRecognizerResult.h
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
 * Class representing values obtained when scanning front side of the Kuwait Id
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBKuwaitIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The birth Date of the front side of the Kuroom wait Id owner.
 */
@property (nonatomic, readonly) MBDateResult *birthDate;

/**
 * The civil Id Number of the front side of the Kuwait Id owner.
 */
@property (nonatomic, readonly) NSString *civilIdNumber;

/**
 * The expiry Date of the front side of the Kuwait Id owner.
 */
@property (nonatomic, readonly) MBDateResult *expiryDate;

/**
 * The name of the front side of the Kuwait Id owner.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * The nationality of the front side of the Kuwait Id owner.
 */
@property (nonatomic, readonly) NSString *nationality;

/**
 * The sex of the front side of the Kuwait Id owner.
 */
@property (nonatomic, readonly) NSString *sex;

@end

NS_ASSUME_NONNULL_END
