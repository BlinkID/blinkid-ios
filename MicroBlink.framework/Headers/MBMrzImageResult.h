//
//  MBMrzImageResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 13/06/2018.
//

#ifndef MBMrzImageResult_h
#define MBMrzImageResult_h

#import "MBImage.h"

@protocol MBMrzImageResult

@required

/**
 * face image from the document if enabled with `MBMrzImage returnMrzImage` property.
 */
@property (nonatomic, readonly, nullable) MBImage* mrzImage;

@end



#endif /* MBMrzImageResult_h */
