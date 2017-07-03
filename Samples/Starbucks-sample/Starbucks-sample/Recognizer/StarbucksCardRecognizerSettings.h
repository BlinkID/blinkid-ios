//
//  StarbucksCardRecognizerSettings.h
//  Templating-Sample
//
//  Created by Jure Cular on 29/03/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import <MicroBlink/MicroBlink.h>

@interface StarbucksCardRecognizerSettings : PPBlinkOcrRecognizerSettings

- (NSDictionary *)extractMessageFromResult:(PPBlinkOcrRecognizerResult *)result;

@end
