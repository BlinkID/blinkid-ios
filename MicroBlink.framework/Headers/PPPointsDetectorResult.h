//
//  PPPointsDetectorResult.h
//  BlinkIdFramework
//
//  Created by Dino on 21/03/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPDetectorResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Result of the detection of a point detector. Point Detectors are used for QR and similar barcodes
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPPointsDetectorResult : PPDetectorResult

/**
 * Coordinates of points (CGPoint) of a detected object.
 */
@property (nonatomic) NSArray *points;

@end

NS_ASSUME_NONNULL_END
