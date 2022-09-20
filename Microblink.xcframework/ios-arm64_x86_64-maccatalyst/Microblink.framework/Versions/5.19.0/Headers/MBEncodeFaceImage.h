//
//  MBEncodeFaceImage.h
//  MicroblinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBEncodeFaceImage_h
#define MBEncodeFaceImage_h

@protocol MBEncodeFaceImage

@required

/**
 * Sets whether face image should be extracted from document and JPEG-encoded.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL encodeFaceImage;

@end

#endif /* MBEncodeFaceImage_h */
