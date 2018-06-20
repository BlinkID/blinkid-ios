//
//  MBMyTenteraRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBMyTenteraRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFaceImage.h"
#import "MBFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring My Tentera Recognizer.
 *
 * My Tentera recognizer is used for scanning My Tentera.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBMyTenteraRecognizer : MBLegacyRecognizer <NSCopying, MBFaceImage, MBFullDocumentImage, MBGlareDetection, MBFullDocumentImageDpi>

MB_INIT

/**
 * My Tentera recognizer result
 */
@property (nonatomic, strong, readonly) MBMyTenteraRecognizerResult *result;

/**
 * Defines if religion should be extracted from MyTentera
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractReligion;

/**
 * Defines if full name and address should be extracted from MyTentera
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFullNameAndAddress;

@end

NS_ASSUME_NONNULL_END
