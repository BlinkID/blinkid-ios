//
//  MBQuadDetectorSubview.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 02/05/2018.
//

#import "MBDisplayableQuadDetection.h"

/**
 * Protocol for processing MBDisplayableQuadDetection. Subviews implementing this protocol process and draw quad on the screen (e.g. viewfinder drawing document outlining)
 */
@protocol MBQuadDetectorSubview <NSObject>

/**
 * This method should be called when MBDisplayableQuadDetection is obtained and quad need to be drawn/redrawn.
 */
- (void)detectionFinishedWithDisplayableQuad:(MBDisplayableQuadDetection *)displayableQuadDetection;

@end
