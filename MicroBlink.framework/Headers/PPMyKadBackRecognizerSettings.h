//
//  PPMyKadBackRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 21/12/2017.
//

#import "PPRecognizerSettings.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring Malaysian MyKad Back Recognizer.
 *
 * Malaysian MyKad Back recognizer is used for scanning front side of Malaysian MyKad Back.
 */
PP_CLASS_AVAILABLE_IOS(6.0)

@interface PPMyKadBackRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains signature.
 * This image will be sent to scan delegate during recognition process if displaying of face image
 * is enabled via displaySignatureImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)ID_SIGNATURE;

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

/**
 * Sets whether face image from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL displaySignatureImage;

/**
 * Sets whether full document image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL displayFullDocumentImage;

/**
 * Defines if glare detection should be turned on/off for Malaysian MyKad Back.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL detectGlare;

/**
 * Property got setting DPI for full document images
 * Valid ranges are [100,400]. Setting DPI out of valid ranges throws an exception
 *
 * Default: 250.0
 */
@property (nonatomic, assign) NSUInteger fullDocumentImageDPI;

@end

NS_ASSUME_NONNULL_END
