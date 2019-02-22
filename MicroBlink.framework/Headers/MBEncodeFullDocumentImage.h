//
//  MBEncodeFullDocumentImage.h
//  MicroblinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBEncodeFullDocumentImage_h
#define MBEncodeFullDocumentImage_h

@protocol MBEncodeFullDocumentImage

@required

/**
 * Sets whether full document image should be extracted and JPEG-encoded.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL encodeFullDocumentImage;

@end

#endif /* MBEncodeFullDocumentImage_h */
