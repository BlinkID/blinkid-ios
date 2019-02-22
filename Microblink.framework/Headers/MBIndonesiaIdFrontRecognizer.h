//
//  MBIndonesiaIdFrontRecognizer.h
//  MicroblinkDev
//
//  Created by juraskrlec on 25/09/2018.
//

#import "MBRecognizer.h"
#import "MBIndonesiaIdFrontRecognizerResult.h"

#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBSignatureImage.h"
#import "MBEncodeSignatureImage.h"
#import "MBSignatureImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer which can scan front side of Indonesian national ID cards.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBIndonesiaIdFrontRecognizer : MBRecognizer <NSCopying, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBSignatureImage, MBEncodeSignatureImage, MBSignatureImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Indonesia Id Front Recognizer
 */
@property (nonatomic, strong, readonly) MBIndonesiaIdFrontRecognizerResult *result;

/**
 * Defines if address of Indonesian ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if blood type of Indonesian ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractBloodType;

/**
 * Defines if citizenship of Indonesian ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractCitizenship;

/**
 * Defines if city of Indonesian ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractCity;

/**
 * Defines if date of expiry of Indonesian ID card should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if district of Indonesian ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDistrict;

/**
 * Defines if Kel/Desa of Indonesian ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractKelDesa;

/**
 * Defines if marital status of Indonesian ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractMaritalStatus;

/**
 * Defines if name of Indonesian ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if occupation of Indonesian ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractOccupation;

/**
 * Defines if place of birth of Indonesian ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if religion of Indonesian ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractReligion;

/**
 * Defines if RT number of Indonesian ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractRt;

/**
 * Defines if RW number of Indonesian ID owner should be extracted.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractRw;

@end

NS_ASSUME_NONNULL_END
