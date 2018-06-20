//
//  MBColombiaIdFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBColombiaIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBSignatureImage.h"
#import "MBFullDocumentImage.h"

#import "MBFaceImageDpi.h"
#import "MBSignatureImageDpi.h"
#import "MBFullDocumentImageDpi.h"

#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Colombia ID Front Recognizer.
 *
 * Colombia ID Front recognizer is used for scanning front side of Colombia ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBColombiaIdFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBSignatureImage, MBFullDocumentImage, MBFaceImageDpi, MBSignatureImageDpi, MBFullDocumentImageDpi, MBGlareDetection>

MB_INIT

/**
 * Colombia ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBColombiaIdFrontRecognizerResult *result;

/**
 * Defines if owner's first name should be extracted from Colombian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFirstName;

/**
 * Defines if owner's last name should be extracted from Colombian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractLastName;

@end

NS_ASSUME_NONNULL_END
