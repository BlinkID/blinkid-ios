//
//  MBFullDocumentImageResult.h
//  MicroblinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBFullDocumentImageResult_h
#define MBFullDocumentImageResult_h

#import "MBImage.h"

@protocol MBFullDocumentImageResult

@required

/**
 * full document image if enabled with `MBFullDocumentImage returnFullDocumentImage` property.
 */
@property (nonatomic, readonly, nullable) MBImage* fullDocumentImage;

@end

#endif /* MBFullDocumentImageResult_h */
