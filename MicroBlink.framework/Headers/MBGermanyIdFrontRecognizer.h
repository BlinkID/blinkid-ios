//
//  MBGermanyIdFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBGermanyIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBSignatureImage.h"
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring German ID Front Recognizer.
 *
 * German ID Front recognizer is used for scanning front side of German ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyIdFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBSignatureImage, MBFullDocumentImage, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * German ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBGermanyIdFrontRecognizerResult *result;

/**
 * Defines if owner's first names should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractGivenNames;

/**
 * Defines if owner's surname should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

/**
 * Defines if owner's place of birth should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if owner's nationality should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if date of expiry should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if CAN number should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractCanNumber;

/**
 * Defines if document number should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDocumentNumber;

@end

NS_ASSUME_NONNULL_END
