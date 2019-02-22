//
//  MBAustriaPassportRecognizer.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 11/06/2018.
//

#import "MBRecognizer.h"
#import "MBAustriaPassportRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBSignatureImage.h"
#import "MBEncodeSignatureImage.h"
#import "MBSignatureImageDpi.h"
#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Austrian Passport Recognizer.
 *
 * Austrian Passport recognizer is used for scanning Austrian Passport.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBAustriaPassportRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBSignatureImage, MBEncodeSignatureImage, MBSignatureImageDpi, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Austrian Passport
 */
@property (nonatomic, strong, readonly) MBAustriaPassportRecognizerResult *result;

/**
 * Defines if owner's surname should be extracted from Austrian Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

/**
 * Defines if owner's given name should be extracted from Austrian Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractGivenName;

/**
 * Defines if owner's nationality should be extracted from Austrian Passport
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if owner's place of birth should be extracted from Austrian Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if date of issue should be extracted from Austrian Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if issuing authority should be extracted from Austrian Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuingAuthority;

/**
 * Defines if owner's height should be extracted from Austrian Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractHeight;

/**
 * Defines if owner's sex should be extracted from Austrian Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if passport number should be extracted from Austrian Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPassportNumber;

/**
 * Defines if owner's date of birth should be extracted from Austrian Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if date of expiry should be extracted from Austrian Passport
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

@end

NS_ASSUME_NONNULL_END
