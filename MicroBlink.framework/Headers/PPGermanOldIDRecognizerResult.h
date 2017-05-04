//
//  PPGermanIdMrzRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 22/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPMrtdRecognizerResult.h"

/**
 * Class representing values obtained when scanning MRZ of German ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPGermanOldIDRecognizerResult : PPMrtdRecognizerResult

/**
 * The place of birth on the German ID
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;


@end
