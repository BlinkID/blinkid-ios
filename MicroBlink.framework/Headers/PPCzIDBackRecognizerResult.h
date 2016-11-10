//
//  PPCzIDBackRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 30/06/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPMrtdRecognizerResult.h"

/**
 * Class representing values obtained when scanning back side of Czech ID
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPCzIDBackRecognizerResult : PPMrtdRecognizerResult

/**
 * Returns the issuing authority of the Czech ID.
 * @return issuing authority of the Czech ID.
 */
- (NSString * _Nullable)authority;

/**
 * Returns the address of the Czech ID owner.
 * @return address of the Czech ID owner.
 */
- (NSString * _Nullable)address;

/**
 * Returns the personal number of the Czech ID owner.
 * @return personal number of the Czech ID owner.
 */
- (NSString * _Nullable)personalNumber;

@end
