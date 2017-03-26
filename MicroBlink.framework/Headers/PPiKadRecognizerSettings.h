//
//  PPiKadRecognizerSettings.h
//  PhotoPayFramework
//
//  Created by Dino on 28/09/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring Malaysian iKad Recognizer.
 *
 * Malaysian iKad recognizer is used for scanning front side of Malaysian iKad.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPiKadRecognizerSettings : PPRecognizerSettings

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
 * Defines if owner's sector should be extracted from iKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSector;

/**
 * Defines if owner's employer should be extracted from iKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractEmployer;

/**
 * Defines if owner's address should be extracted from iKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if owner's passport number should be extracted from iKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPassportNumber;

/**
 * Defines if expiry date should be extracted from iKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractExpiryDate;

/**
 * Defines if date of expiry should be extracted from iKad
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if owner's sex should be extracted from iKad
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
@property (nonatomic, assign) BOOL displayFaceImage;

/**
 * Sets whether full document image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL displayFullDocumentImage;

@end

NS_ASSUME_NONNULL_END
