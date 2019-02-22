//
//  MBUnitedArabEmiratesIdFrontRecognizerResult.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 28/05/2018.
//

#import "MBRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of United Arab Emirates ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBUnitedArabEmiratesIdFrontRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult, MBFaceImageResult, MBEncodedFaceImageResult>

MB_INIT_UNAVAILABLE

/**
 * The id Number of the front side of United Arab Emirates ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *idNumber;

/**
 * The name of the front side of United Arab Emirates ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The nationality of the front side of United Arab Emirates ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

@end

NS_ASSUME_NONNULL_END
