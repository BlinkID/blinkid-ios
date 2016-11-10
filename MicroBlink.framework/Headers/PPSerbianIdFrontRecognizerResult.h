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
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPSerbianIdFrontRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * Returns the issuing date of the Serbian ID.
 * @return the issuing date of the Serbian ID.
 */
- (NSDate* _Nullable) issuingDate;

/**
 * Returns the valid until date of the Serbian ID.
 * @return the valid until date of the Serbian ID.
 */
- (NSDate* _Nullable) validUntil;

@end
