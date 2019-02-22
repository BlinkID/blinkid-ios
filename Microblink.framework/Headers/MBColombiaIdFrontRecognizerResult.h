//
//  MBColombiaIdFrontRecognizerRecognizerResult.h
//  MicroblinkDev
//
//  Created by dodo on 24/07/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBEncodedSignatureImageResult.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of the Colombia Id
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBColombiaIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult,  MBSignatureImageResult, MBEncodedSignatureImageResult>

MB_INIT_UNAVAILABLE


/**
 * The document Number of the Colombia Id.
 */
@property (nonatomic, readonly) NSString *documentNumber;

/**
 * The first Name of the Colombia Id owner.
 */
@property (nonatomic, readonly) NSString *firstName;

/**
 * The last Name of the Colombia Id owner.
 */
@property (nonatomic, readonly) NSString *lastName;

@end

NS_ASSUME_NONNULL_END
