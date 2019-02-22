//
//  MBSerbiaIdFrontRecognizer.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBSerbiaIdFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBSignatureImage.h"
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Serbian ID Front Recognizer.
 *
 * Serbian ID Front recognizer is used for scanning front side of Serbian ID.
 */
MB_CLASS_DEPRECATED_IOS(1.0.0, 4.6.0, "Recognizer is deprecated")
@interface MBSerbiaIdFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBSignatureImage, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Serbian ID Front recognizer result
 */
@property (nonatomic, strong, readonly) MBSerbiaIdFrontRecognizerResult *result;

/**
 *  Defines if issuing date of Serbian ID should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractIssuingDate;

/**
 *  Defines if valid until date of Serbian ID should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractValidUntil;

@end

NS_ASSUME_NONNULL_END
