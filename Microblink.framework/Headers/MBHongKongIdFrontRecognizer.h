//
//  MBHongKongIdFrontRecognizer.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBRecognizer.h"
#import "MBHongKongIdFrontRecognizerResult.h"

#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Hong Kong ID Front Recognizer.
 *
 * Hong Kong ID Front recognizer is used for scanning front side of Hong Kong ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBHongKongIdFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Hong Kong ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBHongKongIdFrontRecognizerResult *result;

/**
 * Defines if owner's full name should be extracted from Hong Kong ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFullName;

/**
 * Defines if commercial code should be extracted from Hong Kong ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractCommercialCode;

/**
 * Defines if owner's date of birth should be extracted from Hong Kong ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if card's residential status should be extracted from Hong Kong ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractResidentialStatus;

/**
 * Defines if owner's sex should be extracted from Hong Kong ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if card's date of issue should be extracted from Hong Kong ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

@end

NS_ASSUME_NONNULL_END
