//
//  MBIkadRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBIkadRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring iKad Recognizer.
 *
 * iKad recognizer is used for scanning iKad.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBIkadRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBFullDocumentImage, MBGlareDetection, MBFullDocumentImageDpi>

MB_INIT

/**
 * i Kad recognizer result
 */
@property (nonatomic, strong, readonly) MBIkadRecognizerResult *result;

/**
 * Defines if owner's sector should be extracted from iKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSector;

/**
 * Defines if owner's employer should be extracted from iKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractEmployer;

/**
 * Defines if owner's address should be extracted from iKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if owner's faculty address should be extracted from iKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFacultyAddress;

/**
 * Defines if owner's passport number should be extracted from iKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPassportNumber;

/**
 * Defines if expiry date should be extracted from iKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractExpiryDate;

/**
 * Defines if date of expiry should be extracted from iKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if owner's sex should be extracted from iKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

@end

NS_ASSUME_NONNULL_END
