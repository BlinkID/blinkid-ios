//
//  PPSlovakIdBackRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 22/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPMrtdRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Slovak ID
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPSlovakIdBackRecognizerResult : PPMrtdRecognizerResult

/**
 * Returns the address of the Slovakian ID owner.
 * @return the address of the Slovakian ID owner.
 */
- (NSString * _Nullable)address;

/**
 * Returns the surname at birth of the Slovakian ID owner.
 * @return the surname at birth of the Slovakian ID owner.
 */
- (NSString * _Nullable)surnameAtBirth;

/**
 * Returns the place of birth of the Slovakian ID owner.
 * @return the place of birth of the Slovakian ID owner.
 */
- (NSString * _Nullable)placeOfBirth;

/**
 * Returns the special remarks of the Slovakian ID owner.
 * @return the special remarks of the Slovakian ID owner.
 */
- (NSString * _Nullable)specialRemarks;

@end
