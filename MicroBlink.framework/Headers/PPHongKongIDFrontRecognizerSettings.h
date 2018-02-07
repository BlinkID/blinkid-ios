//
//  PPHongKongIDFrontRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 05/02/2018.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Hong Kong ID Front Recognizer.
 *
 * Hong Kong ID Front recognizer is used for scanning front side of the Hong Kong ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPHongKongIDFrontRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains face.
 * This image will be sent to scan delegate during recognition process if displaying of face image
 * is enabled via displayFaceImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)ID_FACE;

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

/**
 * Defines if owner's full name should be extracted from Hong Kong ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractFullName;

/**
 * Defines if commercial code should be extracted from Hong Kong ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractCommercialCode;

/**
 * Defines if owner's date of birth should be extracted from Hong Kong ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

/*
 * Defines if owner's sex should be extracted from Hong Kong ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if card's issue date should be extracted from Hong Kong ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractIssueDate;

/**
 * Sets whether face photo from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFacePhoto;

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
