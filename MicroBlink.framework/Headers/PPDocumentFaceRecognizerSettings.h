//
//  PPDocumentFaceRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 21/01/2017.
//  Copyright © 2017 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

typedef NS_ENUM(NSInteger, PPDocumentFaceDetectorType) {

    /** Uses document detector for TD1 size identity cards */
    PPDocumentFaceDetectorTypeTD1 = 0,

    /** Uses document detector for TD2 size identity cards  */
    PPDocumentFaceDetectorTypeTD2,

    /** Uses MRTD detector for detecting documents with MRZ */
    PPDocumentFaceDetectorTypePassportsAndVisas,
};

/**
 * Settings class for configuring DocumentFace Recognizer.
 *
 * DocumentFace Recognizer recognizers ID documents which contain Face image.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPDocumentFaceRecognizerSettings : PPRecognizerSettings

/**
 * Sets whether full image of ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic) BOOL showFullDocument;


/**
 * Sets which format of the document should the recognizer look for.
 *  @see PPDocumentFaceDetectorType
 *
 * Default: PPDocumentFaceDetectorTypeTD1
 */
@property (nonatomic) PPDocumentFaceDetectorType documentType;


@end
