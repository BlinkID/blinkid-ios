//
//  MBEncodeMrzImage.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 13/06/2018.
//

#ifndef MBEncodeMrzImage_h
#define MBEncodeMrzImage_h

@protocol MBEncodeMrzImage

@required

/**
 * Sets whether MRZ image should be extracted from document and JPEG-encoded.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL encodeMrzImage;

@end


#endif /* MBEncodeMrzImage_h */
