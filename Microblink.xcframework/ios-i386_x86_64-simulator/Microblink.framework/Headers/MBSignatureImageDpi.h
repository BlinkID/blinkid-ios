//
//  MBSignatureImageDpi.h
//  MicroblinkDev
//
//  Created by DoDo on 19/06/2018.
//

#ifndef MBSignatureImageDpi_h
#define MBSignatureImageDpi_h

@protocol MBSignatureImageDpi

@required

/**
 * Property for setting DPI for signature images
 * Valid ranges are [100,400]. Setting DPI out of valid ranges throws an exception
 *
 * Default: 250
 */
@property (nonatomic, assign) NSUInteger signatureImageDpi;

@end


#endif /* MBSignatureImageDpi_h */
