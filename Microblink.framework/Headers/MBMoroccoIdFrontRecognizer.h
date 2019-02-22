//
//  MBMoroccoIdFrontRecognizer.h
//  MicroblinkDev
//
//  Created by dodo on 24/07/2018.
//

#import "MBRecognizer.h"
#import "MBMoroccoIdFrontRecognizerResult.h"

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
 * Class for configuring Morocco ID Front Recognizer.
 *
 * Morocco ID Front recognizer is used for scanning front side of the Morocco ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMoroccoIdFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBSignatureImage, MBEncodeSignatureImage, MBSignatureImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning front side of Morocco ID
 */
@property (nonatomic, strong, readonly) MBMoroccoIdFrontRecognizerResult *result;

/**
 * Defines if owner's date of birth should be extracted from front side of the Morocco ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if date of expiry should be extracted from front side of the Morocco ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if owner's name should be extracted from front side of the Morocco ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if owner's place of birth should be extracted from front side of the Morocco ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if owner's sex should be extracted from front side of the Morocco ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if owner's surname should be extracted from front side of the Morocco ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

@end

NS_ASSUME_NONNULL_END
