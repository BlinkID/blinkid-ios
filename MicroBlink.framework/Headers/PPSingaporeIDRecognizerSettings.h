//
//  PPSingaporeIDRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by Dino on 30/06/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Singapore ID Recognizer
 *
 * Singapore ID recognizer is used for scanning Singapore ID.
 * This recognizer can scan both front and back side of the ID but the results of scanning will be different as
 * some fields are not present on both sides
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPSingaporeIDRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains face.
 * This image will be sent to scan delegate during recognition process if displaying of face image
 * is enabled via displayFaceImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
@property (nonatomic, readonly) NSString* ID_FACE;

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
@property (nonatomic, readonly) NSString* FULL_DOCUMENT_IMAGE;

/**
 *  Defines if race of Singapore ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractRace;

/**
 *  Defines if date of birth of Singapore ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractDateOfBirth;

/**
 *  Defines if sex of Singapore ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractSex;

/**
 *  Defines if country of birth of Singapore ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractCountryOfBirth;

/**
 *  Defines if blood group of Singapore ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractBloodGroup;

/**
 *  Defines if date of issue of Singapore ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractDateOfIssue;

/**
 * Sets whether portrait image from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayPortraitImage;

/**
 * Sets whether full image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFullDocumentImage;

@end
