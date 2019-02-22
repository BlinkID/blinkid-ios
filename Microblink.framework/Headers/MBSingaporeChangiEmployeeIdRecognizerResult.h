//
//  MBSingaporeChangiEmployeeIdRecognizerResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 07/08/2018.
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
@interface MBSingaporeChangiEmployeeIdRecognizerResult : MBRecognizerResult<NSCopying, MBFaceImageResult, MBEncodedFaceImageResult, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE
/**
 * The date of expiry of Singapore Changi employee ID.
 */
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
 * The document number of the Singapore Changi employee ID.
 */
@property (nonatomic, readonly) NSString *documentNumber;

/**
 * The name of the Singapore Changi employee ID owner.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * TThe company name of the Singapore Changi employee ID owner.
 */
@property (nonatomic, readonly) NSString *companyName;

@end

NS_ASSUME_NONNULL_END
