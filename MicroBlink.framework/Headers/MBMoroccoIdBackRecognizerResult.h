//
//  MBMoroccoIdBackRecognizerResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 07/08/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of the Morocco ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMoroccoIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The date of expiry of the Morocco ID.
 */
@property (nonatomic, readonly) MBDateResult *dateOfExpiry;

/**
 * The document number of the Morocco ID.
 */
@property (nonatomic, readonly) NSString *documentNumber;

/**
 * The father's name of the Morocco ID owner.
 */
@property (nonatomic, readonly) NSString *fathersName MB_PROPERTY_DEPRECATED;

/**
 * The mother's name of the Morocco ID owner.
 */
@property (nonatomic, readonly) NSString *mothersName MB_PROPERTY_DEPRECATED;

/**
 * The sex of the Morocco ID owner.
 */
@property (nonatomic, readonly) NSString *sex;

/**
 * The address of the Morocco ID owner.
 */
@property (nonatomic, readonly) NSString *address;

/**
 * The civil status number of the Morocco ID owner.
 */
@property (nonatomic, readonly) NSString *civilStatusNumber;

@end

NS_ASSUME_NONNULL_END

