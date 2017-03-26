//
//  PPSlovakIdBackRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by Dino on 22/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Slovakian Back ID Recognizer.
 *
 * Slovakian Back ID recognizer is used for scanning back side of Slovakian ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSlovakIdBackRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

/**
 * Defines if owner's address should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if owner's surname at birth should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurnameAtBirth;

/**
 * Defines if owner's place of birth should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if owner's special remarks should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSpecialRemarks;

/**
 * Sets whether full image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFullDocumentImage;

@end

