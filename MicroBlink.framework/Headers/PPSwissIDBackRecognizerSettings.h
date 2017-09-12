//
//  PPSwissIDBackRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 04/08/2017.
//
//

#import "PPRecognizerSettings.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring Swiss Back ID Recognizer.
 *
 * Swiss Back ID recognizer is used for scanning back side of Swiss ID. It always extracts
 * MRZ zone and address of ID holder while extracting other elements is optional.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSwissIDBackRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of face image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

/**
 * Defines if issuing authority of Swiss ID should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuingAuthority;

/**
 * Defines if date of issue of Swiss ID should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if date of expiry of Swiss ID should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if place of origin of Swiss ID holder should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfOrigin;

/**
 * Defines if height of Swiss ID holder should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractHeight;

/**
 * Defines if sex of Swiss ID folder should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Sets whether full document image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL displayFullDocumentImage;

/**
 * Defines if glare detection should be turned on/off for back side of Swiss IDs.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL detectGlare;

@end

NS_ASSUME_NONNULL_END
