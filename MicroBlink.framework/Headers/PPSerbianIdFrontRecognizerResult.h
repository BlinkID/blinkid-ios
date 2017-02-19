//
//  PPSerbianIdFrontRecognizerResult.h
//  BlinkIdFramework
//
//  Created by DoDo on 09/11/2016.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side side of Serbian ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSerbianIdFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * The issuing date of the Serbian ID.
 */
@property (nonatomic, readonly, nullable) NSDate *issuingDate;

/**
 * The valid until date of the Serbian ID.
 */
@property (nonatomic, readonly, nullable) NSDate *validUntil;

@end
