//
//  MBIndonesiaIdFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBIndonesiaIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBSignatureImage.h"
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Indonesian ID Front Recognizer.
 *
 * Indonesian ID Front recognizer is used for scanning front side of Indonesian ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBIndonesiaIdFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBSignatureImage, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Indonesian ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBIndonesiaIdFrontRecognizerResult *result;

/**
 *  Defines if city of Indonesian ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic, assign) BOOL extractCity;

/**
 * Defines if name of Indonesian ID owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if place of birth of Indonesian ID owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if blood type should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractBloodType;

/**
 * Defines if address should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if rt should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractRt;

/**
 * Defines if rw should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractRw;

/**
 * Defines if keldesa should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractKelDesa;

/**
 * Defines if district should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDistrict;

/**
 * Defines if religion should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractReligion;

/**
 * Defines if marital status should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractMaritalStatus;

/**
 * Defines if occupation should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractOccupation;

/**
 * Defines if citizenship should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractCitizenship;

/**
 * Defines if valid until should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidUntil;

@end

NS_ASSUME_NONNULL_END
