//
//  MBDocumentImageMoireStatus.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 29/05/2020.
//

#ifndef MBDocumentImageMoireStatus_h
#define MBDocumentImageMoireStatus_h

/**
* DocumentImageMoireStatus enum defines possible states of Moire pattern detection.
*/
typedef NS_ENUM(NSUInteger, MBDocumentImageMoireStatus) {

    // Detection of Moire patterns was not performed
    MBDocumentImageMoireStatusNotAvailable = 0,

    // Moire pattern not detected on input image
    MBDocumentImageMoireStatusNotDetected,

    // Moire pattern detected on input image
    MBDocumentImageMoireStatusDetected
};

#endif /* MBDocumentImageMoireStatus_h */
