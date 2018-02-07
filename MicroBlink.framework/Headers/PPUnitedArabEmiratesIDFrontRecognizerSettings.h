//
//  PPUnitedArabEmiratesIDFrontRecognizerSettings.h
//  MicroBlink
//
//  Created by Dino Gustin on 05/02/2018.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring UAE Front ID Recognizer.
 *
 * UAE ID recognizer is used for scanning front side of UAE ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPUnitedArabEmiratesIDFrontRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains face.
 * This image will be sent to scan delegate during recognition process if displaying of face image
 * is enabled via displayFaceImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)ID_FACE;

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

/**
 * Defines if owner's name should be extracted from UAE ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if owner's nationality name should be extracted from UAE ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Sets whether face photo from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFacePhoto;

/**
 * Sets whether full image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFullDocumentImage;

/**
 * Defines if glare detection should be turned on/off for front side of Colombian IDs.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL detectGlare;

@end
