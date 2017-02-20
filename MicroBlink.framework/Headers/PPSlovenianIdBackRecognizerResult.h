//
//  PPSlovenianIdBackRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 22/09/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPMrtdRecognizerResult.h"

/**
 * Class representing values obtained when scanning back side of Slovenian ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSlovenianIdBackRecognizerResult : PPMrtdRecognizerResult

/**
 * The address of the Slovenian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The authority of the Slovenian ID.
 */
@property (nonatomic, readonly, nullable) NSString *authority;

/**
 * Date of issue of the Slovenian ID.
 */
@property (nonatomic, readonly, nullable) NSString *dateOfIssue;

@end
