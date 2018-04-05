//
//  PPEgyptIDFrontRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 27/03/2018.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Egypt ID Front Recognizer.
 *
 * Egypt ID Front recognizer is used for scanning front side of Egypt ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPEgyptIDFrontRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains face.
 * This image will be sent to scan delegate during recognition process if displaying of face image
 * is enabled via displayFaceImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)ID_FACE;

/**
 * Defines if owner's national number should be extracted from Egypt ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationalNumber;

/**
 * Sets whether full document image from Egypt ID should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFullDocumentImage;

/**
 * Sets whether face image from Egypt ID should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFaceImage;


/**
* Defines if glare detection should be turned on/off for front side of Egypt ID.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL detectGlare;

@end
