//
//  PPFaceDetectorResult.h
//  PhotoPayFramework
//
//  Created by Dino on 13/04/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPDetectorResult.h"
#import "PPQuadrangle.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Result of the Face detector
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPFaceDetectorResult : PPDetectorResult

/**
 * All locations where faces are found on the image. Can be more than one.
 * The first is the best candidate.
 */
@property (nonatomic) NSArray<PPQuadrangle *> *faceLocations;

@end

NS_ASSUME_NONNULL_END
