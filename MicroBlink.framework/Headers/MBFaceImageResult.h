//
//  MBFaceImageResult.h
//  MicroblinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBFaceImageResult_h
#define MBFaceImageResult_h

#import "MBImage.h"

@protocol MBFaceImageResult

@required

/**
 * face image from the document if enabled with `MBFaceImage returnFaceImage` property.
 */
@property (nonatomic, readonly, nullable) MBImage* faceImage;

@end

#endif /* MBFaceImageResult_h */
