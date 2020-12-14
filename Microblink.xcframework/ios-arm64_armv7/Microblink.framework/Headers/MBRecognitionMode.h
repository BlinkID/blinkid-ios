//
//  MBRecognitionMode.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 11/08/2020.
//

#ifndef MBRecognitionMode_h
#define MBRecognitionMode_h

/**
* MBRecognitionMode enum defines possible recognition modes by BlinkID(Combined)Recognizer.
*/
typedef NS_ENUM(NSInteger, MBRecognitionMode) {

    /** No recognition performed. */
    MBRecognitionModeNone,

    /** Recognition of mrz document (does not include visa and passport) */
    MBRecognitionModeMrzId,

    /** Recognition of visa mrz. */
    MBRecognitionModeMrzVisa,

    /** Recognition of passport mrz. */
    MBRecognitionModeMrzPassport,

    /** Recognition of documents that have face photo on the front. */
    MBRecognitionModePhotoId,

    /** Detailed document recognition. */
    MBRecognitionModeFullRecognition
};

#endif /* MBRecognitionMode_h */
