//
//  MBNewZealandDlFrontRecognizer.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBRecognizer.h"
#import "MBNewZealandDlFrontRecognizerResult.h"

#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBSignatureImage.h"
#import "MBEncodeSignatureImage.h"
#import "MBSignatureImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring New Zealand DL Front Recognizer.
 *
 * New Zealand DL Front recognizer is used for scanning front side of New Zealand DL.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBNewZealandDlFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBSignatureImage, MBEncodeSignatureImage, MBSignatureImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * New Zealand DL Front recognizer result
 */
@property (nonatomic, strong, readonly) MBNewZealandDlFrontRecognizerResult *result;

/**
 * Defines if owner's first name should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFirstNames;

/**
 * Defines if owner's last name should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

/**
 * Defines if owner's date of birth should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if card's issue date should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if card's expiry date should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if owner's donor indicator should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDonorIndicator;

/**
 * Defines if owner's address should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

@end

NS_ASSUME_NONNULL_END
