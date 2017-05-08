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
 * Settings class for configuring German New ID Back side Recognizer.
 *
 * German New ID Back side recognizer is used for scanning back side of new German ID card.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPGermanIDBackRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)ID_FULL_DOCUMENT;

/**
 * If eye color should be extracted, set this to YES
 *
 * Default: YES
 */
@property (nonatomic) BOOL extractEyeColour;

/**
 * If height should be extracted, set this to YES
 *
 * Default: YES
 */
@property (nonatomic) BOOL extractHeight;

/**
 * If date of issue should be extracted, set this to YES
 *
 * Default: YES
 */
@property (nonatomic) BOOL extractDateOfIssue;

/**
 * If authority should be extracted, set this to YES
 *
 * Default: YES
 */
@property (nonatomic) BOOL extractAuthority;

/**
 * The full document photo should be extracted, set this to YES
 *
 * Default: NO
 */
@property (nonatomic) BOOL returnFullDocumentPhoto;


@end

NS_ASSUME_NONNULL_END
