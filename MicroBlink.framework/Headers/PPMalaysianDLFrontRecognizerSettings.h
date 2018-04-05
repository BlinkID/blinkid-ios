//
//  PPMalaysianDLFrontRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 29/03/2018.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Malaysian DL Front Recognizer.
 *
 * Malaysian DL Front recognizer is used for scanning front side of Malaysian DL.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPMalaysianDLFrontRecognizerSettings : PPRecognizerSettings

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
 * Defines if owner's name should be extracted from Malaysian DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if owner's nationality should be extracted from Malaysian DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if owner's class should be extracted from Malaysian DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractClass;

/**
 * Defines if owner's valid from should be extracted from Malaysian DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidFrom;

/**
 * Defines if owner's valid until should be extracted from Malaysian DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidUntil;

/**
 * Defines if owner's address should be extracted from Malaysian DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Sets whether full document image from Malaysian DL should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFullDocumentImage;

/**
 * Sets whether face image from Malaysian DL should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFaceImage;


/**
* Defines if glare detection should be turned on/off for front side of Malaysian DL.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL detectGlare;

@end
