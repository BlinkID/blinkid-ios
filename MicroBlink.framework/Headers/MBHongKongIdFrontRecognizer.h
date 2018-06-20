//
//  MBHongKongIdFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBHongKongIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Hong Kong ID Front Recognizer.
 *
 * Hong Kong ID Front recognizer is used for scanning front side of Hong Kong ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBHongKongIdFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBFullDocumentImage, MBGlareDetection>

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
