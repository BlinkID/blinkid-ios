//
//  PPCroIDCombinedRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 04/12/2016.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring Croatian ID Combined Recognizer.
 *
 * Croatian Combined ID recognizer is used for scanning both front and back side of croatian IDs.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPCroIDCombinedRecognizerSettings : PPRecognizerSettings

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
