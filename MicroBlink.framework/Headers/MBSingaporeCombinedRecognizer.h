//
//  MBSingaporeCombinedRecognizer.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBRecognizer.h"
#import "MBSingaporeCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBDigitalSignature.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Singapore ID Combined Recognizer.
 *
 * Singapore ID Combined recognizer is used for scanning both front and back side of Singapore ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBSingaporeCombinedRecognizer : MBRecognizer <NSCopying, MBCombinedRecognizer, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBGlareDetection, MBDigitalSignature, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Singapore ID Combined recognizer result
 */
@property (nonatomic, strong, readonly) MBSingaporeCombinedRecognizerResult* result;

/**
 *  Defines if name of Singaporean ID card owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractName;

/**
 *  Defines if race of Singaporean ID card owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractRace;

/**
 *  Defines if date of birth of Singaporean ID card owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractDateOfBirth;

/**
 *  Defines if sex of Singaporean ID card owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractSex;

/**
 *  Defines if country/place of birth of Singaporean ID card owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractCountryOfBirth;

/**
 * Defines if owner's address should be extracted from back side of the Singapore Id
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if owner's address change date should be extracted from back side of the Singapore Id
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL extractAddressChangeDate;

/**
 * Defines if owner's blood type should be extracted from back side of the Singapore Id
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractBloodGroup;

/**
 * Defines if owner's date of issue should be extracted from back side of the Singapore Id
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

@end

NS_ASSUME_NONNULL_END
