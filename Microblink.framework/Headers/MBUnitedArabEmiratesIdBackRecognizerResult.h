//
//  MBUnitedArabEmiratesIdBackRecognizerResult.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 28/05/2018.
//

#import "MBRecognizerResult.h"
#import "MBMrzResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of United Arab Emirates ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBUnitedArabEmiratesIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The mrz of the back side of United Arab Emirates ID owner.
 */
@property (nonatomic, readonly) MBMrzResult *mrzResult;

@end

NS_ASSUME_NONNULL_END
