//
//  MBCzechiaIdBackRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBCzechiaIdBackRecognizerResult.h"

#import <Foundation/Foundation.h>
#import "MBFullDocumentImage.h"
#import "MBGlareDetection.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Cz ID Back Recognizer.
 *
 * Cz ID Back recognizer is used for scanning back side of Cz ID.
 */
PP_CLASS_AVAILABLE_IOS(8.0)
@interface MBCzechiaIdBackRecognizer : MBLegacyRecognizer <NSCopying, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Cz ID Back recognizer result
 */
@property (nonatomic, strong, readonly) MBCzechiaIdBackRecognizerResult *result;

/**
 * Defines if citizenship of Czech ID authority should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAuthority;

/**
 * Defines if address of Czech ID owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPermanentStay;

/**
 * Defines if personal number should be extracted from Czech ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPersonalNumber;

@end

NS_ASSUME_NONNULL_END
