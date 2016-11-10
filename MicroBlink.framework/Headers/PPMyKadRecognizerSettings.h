//
//  PPMyKadRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 16/12/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring MyKad Recognizer
 *
 * MyKadRecognizer is used for recognizing and extracing data from Malaysian ID documents which is compulsory ID document in Malaysia. 
 * Recognizer reads all the contents on the front side of the ID document.
 *
 * @see https://en.wikipedia.org/wiki/Malaysian_identity_card
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPMyKadRecognizerSettings : PPRecognizerSettings

/**
 * Sets whether full document image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL showFullDocument;

/**
 * Sets whether face image from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property ( nonatomic, assign ) BOOL showFaceImage;

@end

NS_ASSUME_NONNULL_END
