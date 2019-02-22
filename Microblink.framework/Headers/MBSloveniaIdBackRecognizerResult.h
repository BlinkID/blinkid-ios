//
//  MBSloveniaIdBackRecognizerResult.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyMRTDRecognizerResult.h"

#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of Slovenian ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSloveniaIdBackRecognizerResult : MBLegacyMRTDRecognizerResult<NSCopying, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The address of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The authority of the Slovenian ID.
 */
@property (nonatomic, readonly, nullable) NSString *authority;

/**
 * Date of issue of the Slovenian ID in dd.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfIssue;

/**
 * Date of issue of the Slovenian ID.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

@end

NS_ASSUME_NONNULL_END
