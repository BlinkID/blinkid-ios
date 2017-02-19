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
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPCzIDBackRecognizerResult : PPMrtdRecognizerResult

/**
 * The issuing authority of the Czech ID.
 */
@property (nonatomic, readonly, nullable) NSString *authority;

/**
 * The address of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The personal number of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *personalNumber;

@end
