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

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer wrapper for PPDetectorResult
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPDetectorRecognizerResult : PPRecognizerResult

/**
 * Obtians the detector result. The type of the detector result depends on the DetectorSettings used when initializing
 * PPDetectorRecognizer
 *
 *  @return detectorResult
 */
- (PPDetectorResult *)detectorResult;

@end

NS_ASSUME_NONNULL_END
