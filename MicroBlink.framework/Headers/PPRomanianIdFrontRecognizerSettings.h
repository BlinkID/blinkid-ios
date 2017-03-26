//
//  PPRomanianIdFrontRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 22/03/17.
//  Copyright © 2017 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Romanian Front ID Recognizer
 *
 * Romanian Front ID recognizer is used for scanning front side of Czech ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPRomanianIdFrontRecognizerSettings : PPRecognizerSettings

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
 * Defines if owner's first name should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFirstName;

/**
 * Defines if owner's last name should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractLastName;

/**
 * Defines if the place of birth should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if the owner's address should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if the issued ny data should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuedBy;

/**
 * Defines if the valid from date should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidFrom;

/**
 * Defines if the valid until date should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidUntil;

/**
 * Defines if the owner's sex information should be extracted from the ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Sets whether face image from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL displayFacePhoto;

/**
 * Sets whether full document image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL displayFullDocumentImage;

/**
 * Sets whether face image from the ID card should be encoded in the result sent to didOutputResults method of scanDelegate object.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL encodeFacePhoto;

/**
 * Sets whether full document image of ID card should be encoded in the result sent to didOutputResults method of scanDelegate object.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL encodeFullDocumentImage;

@end
