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
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSlovakIdBackRecognizerResult : PPMrtdRecognizerResult

/**
 * The address of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The surname at birth of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *surnameAtBirth;

/**
 * The place of birth of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * The special remarks of the Slovakian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *specialRemarks;

@end
