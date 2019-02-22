//
//  MBMrzImageDpi.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 17/12/2018.
//

#ifndef MBMrzImageDpi_h
#define MBMrzImageDpi_h

@protocol MBMrzImageDpi

@required

/**
 * Property for setting DPI for mrz images
 * Valid ranges are [100,400]. Setting DPI out of valid ranges throws an exception
 *
 * Default: 250
 */
@property (nonatomic, assign) NSUInteger mrzImageDpi;

@end


#endif /* MBMrzImageDpi_h */
