//
//  MBMrzImage.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 13/06/2018.
//

#ifndef MBMrzImage_h
#define MBMrzImage_h

@protocol MBMrzImage

@required

/**
 * Sets whether MRZ image from ID card should be extracted
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL returnMrzImage;

@end

#endif /* MBMrzImage_h */
