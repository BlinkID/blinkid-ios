//
//  MBCombinedFullDocumentImageResult.h
//  MicroblinkDev
//
//  Created by DoDo on 17/05/2018.
//

#ifndef MBCombinedFullDocumentImageResult_h
#define MBCombinedFullDocumentImageResult_h

#import "MBImage.h"

@protocol MBCombinedFullDocumentImageResult

@required

/**
 * front side image of the document if enabled with `MBFullDocumentImage returnFullDocumentImage` property.
 */
@property (nonatomic, readonly, nullable) MBImage* fullDocumentFrontImage;

/**
 * back side image of the document if enabled with `MBFullDocumentImage returnFullDocumentImage` property.
 */
@property (nonatomic, readonly, nullable) MBImage* fullDocumentBackImage;

@end

#endif /* MBCombinedFullDocumentImageResult_h */
