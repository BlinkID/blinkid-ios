//
//  MBPointDetectorSubview.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 02/05/2018.
//

#import "MBDisplayablePointsDetection.h"

/**
 * Protocol for processing MBDisplayablePointsDetection. Subviews implementing this protocol process and draw points on the screen (e.g. flashing dots)
 */
@protocol MBPointDetectorSubview <NSObject>

/**
 * This method should be called when MBDisplayablePointsDetection is obtained and points need to be drawn/redrawn.
 */
- (void)detectionFinishedWithDisplayablePoints:(MBDisplayablePointsDetection *)displayablePointsDetection;

@end
