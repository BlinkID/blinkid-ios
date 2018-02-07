//
//  PPMyKadRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 16/12/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring MyKad Recognizer.
 *
 * MyKadRecognizer is used for recognizing and extracing data from Malaysian ID documents which is compulsory ID document in Malaysia.
 * Recognizer reads all the contents on the front side of the ID document.
 *
 * @see https://en.wikipedia.org/wiki/Malaysian_identity_card
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPMyKadFrontRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains face.
 * This image will be sent to scan delegate during recognition process if displaying of face image
 * is enabled via showFaceImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)ID_FACE;

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via showFullDocument property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

/**
 * Defines if army number should be extracted from MyTentera documents with MyKadRecognizer
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL extractArmyNumber;

/**
 * Sets whether full document image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL showFullDocument;

/**
 * Sets whether face image from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL showFaceImage;

/**
 * Property got setting DPI for full document images
 * Valid ranges are [100,400]. Setting DPI out of valid ranges throws an exception
 *
 * Default: 250.0
 */
@property (nonatomic, assign) NSUInteger fullDocumentImageDPI;

@end

NS_ASSUME_NONNULL_END
