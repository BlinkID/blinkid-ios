//
//  PPGermanIdMrzRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by Dino on 22/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring German ID MRZ Recognizer.
 *
 * German ID MRZ recognizer is used for scanning back side of German ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPGermanIdMrzRecognizerSettings : PPRecognizerSettings

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
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains MRZ.
 * This image will be sent to scan delegate during recognition process if displaying of MRZ image
 * is enabled via displayMrzImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)MRZ_IMAGE;

/**
 * Defines if owner's eye color should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractEyeColor;

/**
 * Defines if owner's height should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractEyeHeight;

/**
 * Defines if owner's date of issue should be extracted from German ID
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
 * Defines if owner's address should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Sets whether MRZ image from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL displayMrzImage;

/**
 * Sets whether face image from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL displayFaceImage;

/**
 * Sets whether signature image from ID card should be sent to didOutputMetadata method of scanDelegate object.
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

@end

NS_ASSUME_NONNULL_END
