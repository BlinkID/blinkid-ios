//
//  MBNewZealandDlFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBNewZealandDlFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBSignatureImage.h"
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring New Zealand DL Front Recognizer.
 *
 * New Zealand DL Front recognizer is used for scanning front side of New Zealand DL.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBNewZealandDlFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBSignatureImage, MBFullDocumentImage, MBGlareDetection>

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
@property (nonatomic, assign) BOOL extractIssueDate;

/**
 * Defines if card's expiry date should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractExpiryDate;

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
