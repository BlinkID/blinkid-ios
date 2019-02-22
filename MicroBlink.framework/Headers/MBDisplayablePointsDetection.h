//
//  MBDisplayablePointsDetection.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 19/12/2017.
//

#import "MBDisplayableDetection.h"
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Result of the detection of a point detector. Point Detectors are used for QR and similar barcodes
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDisplayablePointsDetection : MBDisplayableDetection

/**
 * Coordinates of points (CGPoint) of a detected object.
 */
@property (nonatomic) NSArray *points;

@end

NS_ASSUME_NONNULL_END
