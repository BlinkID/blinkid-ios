//
//  MBDocumentFaceRecognizerRecognizer.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 18/06/2018.
//

/**
 * Enumeration of all supported document types for MBDocumentFaceRecognizer
 */
typedef NS_ENUM(NSUInteger, MBDocumentFaceDetectorType) {
    
    /** Uses document detector for TD1 size identity cards */
    MBDocumentFaceDetectorTypeTD1 = 0,
    
    /** Uses document detector for TD2 size identity cards  */
    MBDocumentFaceDetectorTypeTD2,
    
    /** Uses MRTD detector for detecting documents with MRZ */
    MBDocumentFaceDetectorTypePassportsAndVisas,
};
