//
//  PPDetectorRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Jura on 06/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerResult.h"

#import "PPDetectorResult.h"
#import "PPQuadDetectorResult.h"
#import "PPDocumentDetectorResult.h"
#import "PPMrtdDetectorResult.h"
#import "PPMultiDetectorResult.h"
#import "PPPointsDetectorResult.h"
#import "PPFaceDetectorResult.h"

/**
 * Recognizer wrapper for PPDetectorResult
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPDetectorRecognizerResult : PPRecognizerResult

/**
 * The detector result. The type of the detector result depends on the DetectorSettings used when initializing
 * PPDetectorRecognizer
 */
@property (nonatomic, readonly, nullable) PPDetectorResult *detectorResult;


@end
