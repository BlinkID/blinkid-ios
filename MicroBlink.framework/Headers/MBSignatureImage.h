//
//  MBSignatureImage.h
//  MicroblinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBSignatureImage_h
#define MBSignatureImage_h

@protocol MBSignatureImage

@required

/**
 * Sets whether signature image from ID card should be extracted.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL returnSignatureImage;

@end

#endif /* MBSignatureImage_h */
