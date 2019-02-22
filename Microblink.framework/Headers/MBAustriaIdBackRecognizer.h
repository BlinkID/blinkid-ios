//
//  MBAustriaIdBackRecognizer.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 11/06/2018.
//

#import "MBRecognizer.h"
#import "MBAustriaIdBackRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Austrian ID Back Recognizer.
 *
 * Austrian ID Back recognizer is used for scanning back side of Austrian ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBAustriaIdBackRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning back of the Austrian ID
 */
@property (nonatomic, strong, readonly) MBAustriaIdBackRecognizerResult *result;

/**
 * Defines if issuing authority should be extracted from back side of Austrian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuingAuthority;

/**
 * Defines if date of issuance should be extracted from back side of Austrian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssuance;

/**
 * Defines if owner's place of birth should be extracted from back side of Austrian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if owner's principal residence should be extracted from back side of Austrian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPrincipalResidence;

/**
 * Defines if owner's height should be extracted from back side of Austrian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractHeight;

@end

NS_ASSUME_NONNULL_END
