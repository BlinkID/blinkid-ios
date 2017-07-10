//
//  PPCroSlipRecognizerSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 27/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPCroSlipRecognizerSettings : PPRecognizerSettings

@property (nonatomic) BOOL readPayerName;

@property (nonatomic) BOOL readPaymentDescription;

@property (nonatomic) BOOL useSanitization;

@end
