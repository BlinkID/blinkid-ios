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
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPSlovenianIdBackRecognizerResult : PPMrtdRecognizerResult

/**
 * Returns the address of the Slovenian ID owner.
 * @return the address of the Slovenian ID owner.
 */
- (NSString * _Nullable)address;

/**
 * Returns the authority of the Slovenian ID.
 * @return the authority of the Slovenian ID.
 */
- (NSString * _Nullable)authority;

/**
 * Returns date of issue of the Slovenian ID.
 * @return date of issue of the Slovenian ID.
 */
- (NSString * _Nullable)dateOfIssue;

@end
