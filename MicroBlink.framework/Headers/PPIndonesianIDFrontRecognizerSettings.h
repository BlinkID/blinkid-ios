//
//  PPIndonesianIDFrontRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 30/11/2017.
//
#import "PPRecognizerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class for configuring Asutralian Front DL Recognizer.
 *
 * Australian Front ID recognizer is used for scanning front side of Indonesian ID. It always extracts
 * identity card number, first and last name of ID holder while extracting other elements is optional.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPIndonesianIDFrontRecognizerSettings : PPRecognizerSettings

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
 *  Defines if city of Indonesian ID owner should be extracted
 *
 *  Default: YES
 */
@property (nonatomic, assign) BOOL extractCity;

/**
 * Defines if name of Indonesian ID owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if place of birth of Indonesian ID owner should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractPlaceOfBirth;

/**
 * Defines if blood type should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractBloodType;

/**
 * Defines if address should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if rt should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractRT;

/**
 * Defines if rw should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractRW;

/**
 * Defines if keldesa should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractKelDesa;

/**
 * Defines if district should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDistrict;

/**
 * Defines if religion should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractReligion;

/**
 * Defines if marital status should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractMaritalStatus;

/**
 * Defines if work should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractWork;

/**
 * Defines if citizenship should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractCitizenship;

/**
 * Defines if valid until should be extracted from Indonesian ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractValidUntil;

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
