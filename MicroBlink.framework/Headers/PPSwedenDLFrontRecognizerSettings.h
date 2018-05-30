//
//  PPSwedenDLFrontRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 29/05/2018.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Sweden DL Front Recognizer.
 *
 * Sweden DL Front recognizer is used for scanning front side of Sweden DL.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSwedenDLFrontRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains face.
 * This image will be sent to scan delegate during recognition process if displaying of face image
 * is enabled via displayFaceImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)ID_FACE;

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains signature.
 * This image will be sent to scan delegate during recognition process if displaying of signature image
 * is enabled via displaySignatureImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)ID_SIGNATURE;

/**
 * Defines if owner's surname should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurname;

/**
 * Defines if owner's name should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if owner's date of birth should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if date of issue should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if date of expiry should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if issuing agency should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuingAgency;

/**
 * Defines if reference number should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractReferenceNumber;

/**
 * Defines iflicence categories should be extracted from Sweden DL
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractLicenceCategories;

/**
 * Sets whether full document image from Sweden DL should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFullDocumentImage;

/**
 * Sets whether face image from Sweden DL should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFaceImage;

/**
 * Sets whether signature image from Sweden DL should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displaySignatureImage;


/**
* Defines if glare detection should be turned on/off for front side of Sweden DL.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL detectGlare;

@end
