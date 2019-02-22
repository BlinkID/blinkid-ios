//
//  MBRomaniaIdFrontRecognizer.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBRomaniaIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Romanian ID Front Recognizer.
 *
 * Romanian ID Front recognizer is used for scanning front side of Romanian ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBRomaniaIdFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Romanian ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBRomaniaIdFrontRecognizerResult *result;

/**
 * Defines if owner's first name should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFirstName;

/**
 * Defines if owner's last name should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractLastName;

/**
 * Defines if the place of birth should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if the owner's address should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if the issued ny data should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuedBy;

/**
 * Defines if the valid from date should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidFrom;

/**
 * Defines if the valid until date should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidUntil;

/**
 * Defines if the owner's sex information should be extracted from the ID
 * from non-MRZ part of the ID.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNonMRZSex;

@end

NS_ASSUME_NONNULL_END
