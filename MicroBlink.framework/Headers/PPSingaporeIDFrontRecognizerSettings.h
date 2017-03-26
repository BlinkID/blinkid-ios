//
//  PPSingaporeIDFrontRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by DoDo on 21/12/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Singapore ID front side Recognizer.
 *
 * Singapore ID recognizer is used for scanning front side of Singapore ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSingaporeIDFrontRecognizerSettings : PPRecognizerSettings

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
