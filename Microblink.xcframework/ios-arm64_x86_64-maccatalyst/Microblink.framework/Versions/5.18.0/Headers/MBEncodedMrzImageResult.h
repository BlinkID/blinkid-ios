//
//  MBEncodedMrzImageResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 13/06/2018.
//

#ifndef MBEncodedMrzImageResult_h
#define MBEncodedMrzImageResult_h

@protocol MBEncodedMrzImageResult

@required

/**
 * JPEG-encoded MRZ image from the document if enabled with `MBEncodeMrzImage encodeMrzImage` property.
 */
@property (nonatomic, readonly, nullable) NSData* encodedMrzImage;

@end

#endif /* MBEncodedMrzImageResult_h */
