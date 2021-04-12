//
//  MBFaceImage.h
//  MicroblinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBFaceImage_h
#define MBFaceImage_h

@protocol MBFaceImage

@required

/**
 * Sets whether face image from ID card should be extracted
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL returnFaceImage;

@end

#endif /* MBFaceImage_h */
