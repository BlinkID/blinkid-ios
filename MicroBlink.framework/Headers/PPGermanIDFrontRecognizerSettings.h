//
//  PPGermanIDFrontRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by Dino on 22/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Struct which describes image extension factors. Each factors denotes by what percentage is image extended.
 * For example, value of top = 0.3f means that top side of the image is extended by 30% of cards height,
 * while value of right = 1.3f means that the right side of the image is extended by 120% of the cards width.
 */
typedef struct _PPImageExtensionFactors {
    CGFloat top;
    CGFloat right;
    CGFloat bottom;
    CGFloat left;
} PPImageExtensionFactors;

/**
 * Method which creates a image extension factors structure
 */
NS_INLINE PPImageExtensionFactors PPMakeImageExtensionFactors(CGFloat top, CGFloat right, CGFloat bottom, CGFloat left) {
    PPImageExtensionFactors factors;
    factors.top = top;
    factors.right = right;
    factors.bottom = bottom;
    factors.left = left;
    return factors;
}

/**
 * Settings class for configuring German ID Front Recognizer.
 *
 * German ID Front recognizer is used for scanning front side of German ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPGermanIDFrontRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains face.
 * This image will be sent to scan delegate during recognition process if displaying of face image
 * is enabled via displayFaceImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)ID_FACE;

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains signature.
 * This image will be sent to scan delegate during recognition process if displaying of face image
 * is enabled via displaySignatureImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)ID_SIGNATURE;

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

/**
 * Defines if owner's first name should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFirstName;

/**
 * Defines if owner's last name should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractLastName;

/**
 * Defines if owner's place of birth should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if owner's nationality should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if date of expiry should be extracted from German ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Image extension factors for full document image.
 *
 * @see PPImageExtensionFactors
 * Default: {0.0f, 0.0f, 0.0f, 0.0f}
 */
@property (nonatomic, assign) PPImageExtensionFactors imageExtensionFactors;

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

/**
 * Defines if glare detection should be turned on/off for front side of German IDs.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL detectGlare;

@end

NS_ASSUME_NONNULL_END
