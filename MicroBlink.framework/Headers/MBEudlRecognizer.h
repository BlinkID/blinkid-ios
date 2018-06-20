//
//  MBEudlRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 28/05/2018.
//

#import "MBRecognizer.h"
#import "MBEudlRecognizerResult.h"

#import "MBFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring EU Driver License Recognizer.
 *
 * EU Driver License recognizer is used for scanning EU Driver License.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBEudlRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBFullDocumentImageDpi>

MB_INIT

/**
 * EU Driver License recognizer result
 */
@property (nonatomic, strong, readonly) MBEudlRecognizerResult *result;

/**
 * Defines if owner's date of issue should be extracted from EU Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if owner's date of expiry should be extracted from EU Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if owner's personal number should be extracted from EU Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPersonalNumber;

/**
 * Defines if owner's issuing authority should be extracted from EU Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuingAuthority;

/**
 * Defines if owner's address should be extracted from EU Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Country of scanning Eudl. The default value of MBEudlCountryAny will scan all supported driver's licenses.
 *
 * Default: MBEudlCountryAny
 */
@property (nonatomic, assign) MBEudlCountry country;

@end

NS_ASSUME_NONNULL_END
