//
//  PPSlovakIDCombinedRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 19/06/2017.
//
//

#import "PPCombinedRecognizerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring German ID Combined Recognizer.
 *
 * German Combined ID recognizer is used for scanning both front and back side of german IDs.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSlovakIDCombinedRecognizerSettings : PPCombinedRecognizerSettings

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
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document front side.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE_FRONT;

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document back side.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE_BACK;

/**
 * Defines if owner's sex should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if owner's nationality should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractNationality;

/**
 * Defines if owner's date of birth should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/**
 * Defines if ID's date of expiry should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfExpiry;

/**
 * Defines if ID's date of issue should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

/**
 * Defines if issuing authority should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssuedBy;

/**
 * Defines if issuing document number should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDocumentNumber;

/**
 * Defines if owner's surname at birth should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSurnameAtBirth;

/**
 * Defines if owner's place of birth should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if owner's special remarks should be extracted from Slovakian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSpecialRemarks;

/**
 * Sets whether face image from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL returnFacePhoto;

/**
 * Sets whether face photo should be encoded in the result object returned by didOutputResult:
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL encodeFacePhoto;

/**
 * Sets whether signature image from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL returnSignaturePhoto;

/**
 * Sets whether signature image should be encoded in the result object returned by didOutputResult:
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL encodeSignaturePhoto;

/**
 * Sets whether full document image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL returnFullDocumentPhoto;

/**
 * Sets whether full document image should be encoded in the result object returned by didOutputResult:
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL encodeFullDocumentPhoto;

@end

NS_ASSUME_NONNULL_END
