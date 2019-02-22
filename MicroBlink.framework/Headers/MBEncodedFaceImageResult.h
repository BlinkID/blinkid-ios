//
//  MBEncodedFaceImageResult.h
//  MicroblinkDev
//
//  Created by DoDo on 17/05/2018.
//

#ifndef MBEncodedFaceImageResult_h
#define MBEncodedFaceImageResult_h

@protocol MBEncodedFaceImageResult

@required

/**
 * JPEG-encoded face image from the document if enabled with `MBEncodeFaceImage encodeFaceImage` property.
 */
@property (nonatomic, readonly, nullable) NSData* encodedFaceImage;

@end

#endif /* MBEncodedFaceImageResult_h */
