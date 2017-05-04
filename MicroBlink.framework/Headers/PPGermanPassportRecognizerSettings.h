//
//  PPGermanIDFrontRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by Dino on 22/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring German ID Front Recognizer.
 *
 * German ID Front recognizer is used for scanning front side of German ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPGermanPassportRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains face.
 * This image will be sent to scan delegate during recognition process if displaying of face image
 * is enabled via displayFaceImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)ID_FACE;

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
 * Defines if owner's surname should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

/**
 * Defines if owner's name should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if owner's nationality should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if owner's place of birth should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if date of issue should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if authority should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAuthority;

/**
 * Sets whether face image from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL returnFacePhoto;

/**
 * Sets whether signature image from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL returnSignaturePhoto;

/**
 * Sets whether full document image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL returnFullDocumentPhoto;

@end

NS_ASSUME_NONNULL_END
