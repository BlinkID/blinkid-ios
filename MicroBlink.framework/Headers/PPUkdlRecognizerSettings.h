//
//  PPUkdlRecognizerSettings.h
//  BlinkIDFramework
//
//  Created by Jura on 13/04/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring UKDL Recognizer
 *
 * UKDL Recognizer recognizer is used for scanning and parsing the front side of UK Driving licenses
 *
 * @see https://en.wikipedia.org/wiki/Driving_licence_in_the_United_Kingdom
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPUkdlRecognizerSettings : PPRecognizerSettings

/**
 * If YES, document issue date will be extracted
 * Set this to NO if youre not interested in this data to speed up the scanning process!
 *
 * Default: YES.
 */
@property (nonatomic, assign) BOOL extractIssueDate;

/**
 * If YES, document expiry date will be extracted
 * Set this to NO if youre not interested in this data to speed up the scanning process!
 *
 * Default: YES.
 */
@property (nonatomic, assign) BOOL extractExpiryDate;

/**
 * If YES, owner's address will be extracted
 * Set this to NO if youre not interested in this data to speed up the scanning process!
 *
 * Default: YES.
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * If YES, full image of the document will be dewarped and returned via the API.
 *
 * Default: NO.
 */
@property (nonatomic, assign) BOOL showFullDocument;

@end

NS_ASSUME_NONNULL_END
