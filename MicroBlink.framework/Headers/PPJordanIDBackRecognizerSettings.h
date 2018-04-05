//
//  PPJordanIDBackRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 23/03/2018.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Jordan ID Back Recognizer.
 *
 * Jordan ID Back recognizer is used for scanning back side of Jordan ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPJordanIDBackRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains full document.
 * This image will be sent to scan delegate during recognition process if displaying of full document image
 * is enabled via displayFullDocumentImage property and receiving of dewarpedImage in MetadataSettings is enabled.
 */
+ (NSString *)FULL_DOCUMENT_IMAGE;

/**
 * Sets whether full document image from Jordan ID should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL displayFullDocumentImage;


/**
* Defines if glare detection should be turned on/off for back side of Jordan ID.
*
* Default: YES
*/
@property (nonatomic, assign) BOOL detectGlare;

@end
