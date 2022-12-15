//
//  MBEncodeSignatureImage.h
//  MicroblinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBEncodeSignatureImage_h
#define MBEncodeSignatureImage_h

@protocol MBEncodeSignatureImage

@required

/**
 * Sets whether image of signature on document should be extracted and JPEG-encoded.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL encodeSignatureImage;

@end


#endif /* MBEncodeSignatureImage_h */
