//
//  MBMoroccoIdBackRecognizer.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 07/08/2018.
//

#import "MBRecognizer.h"
#import "MBMoroccoIdBackRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Morocco ID Back Recognizer.
 *
 * Morocco ID Back recognizer is used for scanning Back side of the Morocco ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMoroccoIdBackRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Back side of Morocco ID
 */
@property (nonatomic, strong, readonly) MBMoroccoIdBackRecognizerResult *result;

/**
 * Defines if owner's address should be extracted from Back side of the Morocco ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if date of expiry should be extracted from Back side of the Morocco ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if father's name should be extracted from Back side of the Morocco ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFathersName;

/**
 * Defines if mother's name should be extracted from Back side of the Morocco ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractMothersName;

/**
 * Defines if owner's sex should be extracted from Back side of the Morocco ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if owner's civil status number should be extracted from Back side of the Morocco ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractCivilStatusNumber;

@end

NS_ASSUME_NONNULL_END
