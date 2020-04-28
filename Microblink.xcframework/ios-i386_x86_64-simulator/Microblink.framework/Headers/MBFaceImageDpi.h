//
//  MBFaceImageDpi.h
//  MicroblinkDev
//
//  Created by DoDo on 19/06/2018.
//

#ifndef MBFaceImageDpi_h
#define MBFaceImageDpi_h

@protocol MBFaceImageDpi

@required

/**
 * Property for setting DPI for face images
 * Valid ranges are [100,400]. Setting DPI out of valid ranges throws an exception
 *
 * Default: 250
 */
@property (nonatomic, assign) NSUInteger faceImageDpi;

@end


#endif /* MBFaceImageDpi_h */
