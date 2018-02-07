//
//  PPUnitedArabEmiratesIDBackRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 05/02/2018.
//

#import "PPRecognizerSettings.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring United Arab Emirates ID Front Recognizer.
 *
 * United Arab Emirates ID Front recognizer is used for scanning front side of UAE ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPUnitedArabEmiratesIDBackRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of face image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

/**
 * Sets whether full document image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL displayFullDocumentImage;

/**
 * Defines if glare detection should be turned on/off for front side of UAE IDs.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL detectGlare;

@end

NS_ASSUME_NONNULL_END
