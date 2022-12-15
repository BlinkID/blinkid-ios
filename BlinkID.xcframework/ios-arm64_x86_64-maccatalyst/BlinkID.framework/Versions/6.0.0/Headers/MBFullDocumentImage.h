//
//  MBFullDocumentImage.h
//  MicroblinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBFullDocumentImage_h
#define MBFullDocumentImage_h

@protocol MBFullDocumentImage

@required

/**
 * Sets whether full document image of ID card should be extracted.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL returnFullDocumentImage;

@end

#endif /* MBFullDocumentImage_h */
