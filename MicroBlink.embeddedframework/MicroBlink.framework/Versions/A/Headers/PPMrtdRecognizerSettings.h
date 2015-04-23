//
//  PPMrtdRecognizerSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 26/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

@interface PPMrtdRecognizerSettings : PPRecognizerSettings

- (instancetype)init;

/**
 * Region of the image which will be OCR-ed.
 * 
 * Default:
 *  When device is in portrait: (0.0f, 0.52f, 1.0f, 0.18f);
 *  When device is in landscape: (0.15f, 0.535f, 0.7f, 0.315f);
 *
 * If you want to change this, keep in mind:
 *  - it might be a good idea to have different values for portrait and landscape
 *  - larger area means easier positioning of the device above the ID card or passport
 *  - larger area also means slower OCR process (time consumption depends roughly linearly to image size)
 */
@property (nonatomic, assign) CGRect mrtdRoi;

@end
