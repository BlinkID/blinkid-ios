//
//  PPAusIDBackRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by Dino on 30/06/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Austrian Back ID Recognizer.
 *
 * Austrian Back ID recognizer is used for scanning back side of Austrian ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPAusIDBackRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

/**
 * Sets whether full image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFullDocumentImage;

/**
 * Defines if issuing authority should be extracted from Austrian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuingAuthority;

/**
 * Defines if owner's name should be extracted from Austrian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPrincipalResidence;

/**
 * Defines ifdate of issue should be extracted from Austrian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if owner's height should be extracted from Austrian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractHeight;

/**
 * Defines if glare detection should be turned on/off for front side of Austrian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL detectGlare;

@end
