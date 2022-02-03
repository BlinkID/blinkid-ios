//
//  MBGlareDetection.h
//  MicroblinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBGlareDetection_h
#define MBGlareDetection_h

@protocol MBGlareDetection

@required

/**
 * Defines if glare detection should be turned on/off.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL detectGlare;

@end

#endif /* MBGlareDetection_h */
