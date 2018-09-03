//
//  MBCyprusIdBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by juraskrlec on 21/08/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of the Cyprus Id
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCyprusIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The date Of Birth of the back side of the Cyprus Id owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
 * The sex of the back side of the Cyprus Id owner.
 */
@property (nonatomic, readonly) NSString *sex;

@end

NS_ASSUME_NONNULL_END
