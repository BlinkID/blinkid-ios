//
//  MBAustriaIdBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 11/06/2018.
//

#import "MBRecognizerResult.h"
#import "MBMrzResult.h"
#import "MBFullDocumentImageResult.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of Austrian ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBAustriaIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The mrz on the back side of Austrian ID.
 */
@property (nonatomic, readonly) MBMrzResult *mrzResult;

/**
 * The Document Number of Austrian ID.
 */
@property (nonatomic, readonly) NSString *documentNumber;

/**
 * The Issuing Authority of Austrian ID.
 */
@property (nonatomic, readonly) NSString *issuingAuthority;

/**
 * The Place Of Birth of Austrian ID owner.
 */
@property (nonatomic, readonly) NSString *placeOfBirth;

/**
 * The Principal Residence of Austrian ID owner.
 */
@property (nonatomic, readonly) NSString *principalResidence;

/**
 * The Height of Austrian ID owner.
 */
@property (nonatomic, readonly) NSString *height;

/**
 * The Date Of Issuance of Austrian ID.
 */
@property (nonatomic, readonly) MBDateResult *dateOfIssuance;

/**
 * The Eye Colour of Austrian ID owner.
 */
@property (nonatomic, readonly) NSString *eyeColour;

@end

NS_ASSUME_NONNULL_END
