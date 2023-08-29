//
//  MBCameraFrames.h
//  BlinkShowcaseDev
//
//  Created by Mijo Gracanin on 04.04.2022..
//

#ifndef MBCameraFrames_h
#define MBCameraFrames_h

@protocol MBCameraFrames

@required

/**
 * Configure the recognizer to save the raw camera frames.
 * This significantly increases memory consumption.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL saveCameraFrames;

@end

#endif /* MBCameraFrames_h */
