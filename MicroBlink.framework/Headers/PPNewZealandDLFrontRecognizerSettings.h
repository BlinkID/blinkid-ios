//
//  PPNewZealandDLFrontRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 02/02/2018.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring New Zealand Driver License Recognizer.
 *
 * New Zealand Driver License recognizer is used for scanning front side of New Zealand Driver License.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPNewZealandDLFrontRecognizerSettings : PPRecognizerSettings

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
 * Defines if owner's first name should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFirstName;

/**
 * Defines if owner's last name should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractLastName;

/**
 * Defines if owner's date of birth should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if card's issue date should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssueDate;

/**
 * Defines if card's expiry date should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractExpiryDate;

/**
 * Defines if owner's donor indicator should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDonorIndicator;

/**
 * Defines if owner's address should be extracted from New Zealand Driver License
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Sets whether face photo from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFacePhoto;

/**
 * Sets whether signature photo of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displaySignaturePhoto;

/**
 * Sets whether full image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFullDocumentImage;

/**
 * Defines if glare detection should be turned on/off for front side of Zealand IDs.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL detectGlare;

@end
