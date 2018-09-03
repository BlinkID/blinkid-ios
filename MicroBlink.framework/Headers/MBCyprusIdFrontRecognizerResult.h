//
//  MBCyprusIdFrontRecognizerResult.h
//  MicroBlinkDev
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
 * Class representing values obtained when scanning front side of the Cyprus Id
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCyprusIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The document Number of the front side of the Cyprus Id owner.
 */
@property (nonatomic, readonly) NSString *documentNumber;

/**
 * The id Number of the front side of the Cyprus Id owner.
 */
@property (nonatomic, readonly) NSString *idNumber;

/**
 * The name of the front side of the Cyprus Id owner.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * The surname of the front side of the Cyprus Id owner.
 */
@property (nonatomic, readonly) NSString *surname;

@end

NS_ASSUME_NONNULL_END
