//
//  MBCameraReticle.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 07/06/2019.
//

#import "MBSubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A camera reticle that locates at the center of screen and uses circle arc rotation to indicate that
 * the system is active but has not detected an object yet.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBCameraReticle : MBSubview

/** Whether the reticle is currently animating. */
@property(nonatomic) BOOL isAnimating;

/** Whether the reticle is currently detecting. */
@property(nonatomic) BOOL isDetecting;

/** Whether the reticle is currently confirming. */
@property(nonatomic) BOOL isConfirming;

/** Starts animating the reticle. Does nothing if the reticle is already animating. */
- (void)startAnimating;

/** Stops animating the reticle. Does nothing if the reticle is not animating. */
- (void)stopAnimating;

/** Starts animating the detection spinner. Does nothing if the detection is already animating. */
- (void)startDetecting;

/** Stops animating the detection spinner. Does nothing if the detection is not animating. */
- (void)stopDetecting;

/** Stops all animations and remove all layers to reset state to beginning */
- (void)resetAll;

/** Starts animating the reticle. Does nothing if the reticle is already animating. */
- (void)animateArcRotation;

@end

NS_ASSUME_NONNULL_END
