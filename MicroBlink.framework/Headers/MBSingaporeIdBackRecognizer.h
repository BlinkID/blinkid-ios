//
//  MBSingaporeIdBackRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBSingaporeIdBackRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Singapore ID Back Recognizer.
 *
 * Singapore ID Back recognizer is used for scanning back side of Singapore ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBSingaporeIdBackRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Singapore ID Back recognizer result
 */
@property (nonatomic, strong, readonly) MBSingaporeIdBackRecognizerResult *result;

/**
 *  Defines if blood group of Singapore ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractBloodGroup;

/**
 *  Defines if date of issue of Singapore ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractDateOfIssue;

@end

NS_ASSUME_NONNULL_END
