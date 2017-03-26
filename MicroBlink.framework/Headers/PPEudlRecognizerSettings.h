//
//  PPEudlRecognizerSettings.h
//  BlinkIDFramework
//
//  Created by Jura on 13/04/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"
#import "PPEudlCountry.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring EUDL Recognizer.
 *
 * EUDL Recognizer is used for scanning and parsing the front side of EU Driving licenses:
 * @see https://en.wikipedia.org/wiki/Driving_licence_in_the_United_Kingdom
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPEudlRecognizerSettings : PPRecognizerSettings

/**
 * Initializes the recognizer with PPEudlCountryAny
 */
- (instancetype)init;

/**
 * Initializes the recognizer for desired country.
 */
- (instancetype)initWithEudlCountry:(PPEudlCountry)country NS_DESIGNATED_INITIALIZER;

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via showFullDocument property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

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

/**
 * Country of scanning Eudl. The default value of PPEudlCountryAny will scan all supported driver's licenses.
 *
 * Default: PPEudlCountryAny
 */
@property (nonatomic, assign) PPEudlCountry country;

@end

NS_ASSUME_NONNULL_END
