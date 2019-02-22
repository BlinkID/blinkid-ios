//
//  MBSignatureImageResult.h
//  MicroblinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBSignatureImageResult_h
#define MBSignatureImageResult_h

#import "MBImage.h"

@protocol MBSignatureImageResult

@required

/**
 * image of the signature if enabled with `MBSignatureImage returnSignatureImage` property.
 */
@property (nonatomic, readonly, nullable) MBImage* signatureImage;

@end

#endif /* MBSignatureImageResult_h */
