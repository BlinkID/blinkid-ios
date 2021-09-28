//
//  MBDocumentImageMoireStatus.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 29/05/2020.
//

#ifndef MBImageAnalysisDetectionStatus_h
#define MBImageAnalysisDetectionStatus_h

/**
* MBImageAnalysisDetectionStatus  enum defines possible states of detection.
*/
typedef NS_ENUM(NSInteger, MBImageAnalysisDetectionStatus) {

    // // Detection was not performed
    MBImageAnalysisDetectionStatusNotAvailable = 0,

    // Not detected on input image
    MBImageAnalysisDetectionStatusNotDetected,

    // Detected on input image
    MBImageAnalysisDetectionStatusDetected
};

#endif /* MBDocumentImageMoireStatus_h */
