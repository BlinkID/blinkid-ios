//
//  MBSingaporeIdBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of Singapore ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSingaporeIdBackRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The identity card number of the Singapore ID.
 */
@property (nonatomic, readonly, nullable) NSString *cardNumber;

/**
 * The blood group of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *bloodGroup;

/**
 * The date of issue of the Singapore ID in dd-MM-yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfIssue;

/**
 * The date of issue of the Singapore ID.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The address of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

@end

NS_ASSUME_NONNULL_END
