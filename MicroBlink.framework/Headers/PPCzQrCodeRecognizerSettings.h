//
//  PPCzQRCodeRecognizerSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 24/03/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPCzQrCodeRecognizerSettings : PPRecognizerSettings

@property (nonatomic, assign) BOOL useSlowerThoroughScan;

@end
