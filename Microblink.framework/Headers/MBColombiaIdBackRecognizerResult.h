//
//  MBColombiaIdBackRecognizerRecognizerResult.h
//  MicroblinkDev
//
//  Created by dodo on 24/07/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of the Colombia Id
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBColombiaIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE


/**
 * The birth Date of the Colombia Id owner.
 */
@property (nonatomic, readonly) MBDateResult *birthDate;

/**
 * The blood Group of the Colombia Id owner.
 */
@property (nonatomic, readonly) NSString *bloodGroup MB_PROPERTY_DEPRECATED;

/**
 * The document Number Colombia Id owner.
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

/**
 * The sex of the Colombia Id owner.
 */
@property (nonatomic, readonly) NSString *sex;

/**
 * The fingerprint of the Colombian ID owner.
 */
@property (nonatomic, readonly, nullable) NSData *fingerprint;

@end

NS_ASSUME_NONNULL_END
