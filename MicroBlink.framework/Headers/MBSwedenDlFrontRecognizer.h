//
//  MBSwedenDlFrontRecognizer.h
//  MicroblinkDev
//
//  Created by DoDo on 16/06/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBSwedenDlFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBFaceImage.h"
#import "MBSignatureImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Sweden Dl Front Recognizer.
 *
 * Sweden Dl Front recognizer is used for scanning front side of Sweden Dl.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBSwedenDlFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBFaceImage, MBSignatureImage, MBFullDocumentImageDpi, MBGlareDetection>

MB_INIT

/**
 * Sweden Dl Front recognizer result
 */
@property (nonatomic, strong, readonly) MBSwedenDlFrontRecognizerResult *result;

/**
 * Defines if owner's surname should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

/**
 * Defines if owner's name should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if owner's date of birth should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if date of issue should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if date of expiry should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if issuing agency should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuingAgency;

/**
 * Defines if reference number should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractReferenceNumber;

/**
 * Defines iflicence categories should be extracted from Sweden DL
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL extractLicenceCategories;

@end

NS_ASSUME_NONNULL_END
