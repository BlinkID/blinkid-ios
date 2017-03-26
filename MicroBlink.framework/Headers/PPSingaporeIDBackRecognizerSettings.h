//
//  PPSingaporeIDBackRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by DoDo on 21/12/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Singapore ID Recognizer.
 *
 * Singapore ID recognizer is used for scanning Singapore ID.
 * This recognizer can scan both front and back side of the ID but the results of scanning will be different as
 * some fields are not present on both sides
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSingaporeIDBackRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

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
 * Sets whether full image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFullDocumentImage;

@end
