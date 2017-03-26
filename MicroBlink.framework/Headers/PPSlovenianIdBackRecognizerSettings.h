//
//  PPSlovenianIdBackRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by Dino on 22/09/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Slovenian Back ID Recognizer.
 *
 * Slovenian Back ID recognizer is used for scanning back side of Slovenian ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSlovenianIdBackRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

/**
 *  Defines if issuing authority of Slovenian ID should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractAuthority;

/**
 *  Defines if date of issue of Slovenian ID should be extracted
 *
 *  Default: YES
 */
@property (nonatomic) BOOL extractDateOfIssue;

/**
 * Sets whether full document image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL displayFullDocumentImage;

@end
