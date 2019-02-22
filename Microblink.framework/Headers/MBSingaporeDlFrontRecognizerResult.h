//
//  MBSingaporeDlFrontRecognizerResult.h
//  MicroblinkDev
//
//  Created by dodo on 25/07/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of the Singapore Driver's License
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSingaporeDlFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE


/**
 * The birth Date of the Singapore DL owner.
 */
@property (nonatomic, readonly) MBDateResult *birthDate;

/**
 * The issue date of the Singapore DL.
 */
@property (nonatomic, readonly) MBDateResult *issueDate;

/**
 * The licence Number of the Singapore DL.
 */
@property (nonatomic, readonly) NSString *licenceNumber;

/**
 * The name of the Singapore DL owner.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * The valid till of the Singapore DL.
 */
@property (nonatomic, readonly) MBDateResult *validTill;

@end

NS_ASSUME_NONNULL_END
