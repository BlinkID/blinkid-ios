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
 * If YES, full image of the document will be dewarped and returned via the API.
 *
 * Default: NO.
 */
@property (nonatomic, assign) BOOL showFullDocument;

@end

NS_ASSUME_NONNULL_END
