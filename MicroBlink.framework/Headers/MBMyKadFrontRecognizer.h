//
//  MBMyKadFrontRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBMyKadFrontRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFaceImage.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring My Kad Front Recognizer.
 *
 * My Kad Front recognizer is used for scanning front side of My Kad.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBMyKadFrontRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBFaceImage, MBFullDocumentImageDpi>

MB_INIT

/**
 * My Kad Front recognizer result
 */
@property (nonatomic, strong, readonly) MBMyKadFrontRecognizerResult *result;

/**
 * Defines if army number should be extracted from MyTentera documents with MyKadRecognizer
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL extractArmyNumber;

@end

NS_ASSUME_NONNULL_END
