//
//  PPSingaporeIDBackRecognizerResult.h
//  BlinkIdFramework
//
//  Created by DoDo on 21/12/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

/**
 * Class representing values obtained when scanning Singapore ID.
 * Both front and back side can be scanned but the results will be different for each side
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPSingaporeIDBackRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * The identity card number of the Singapore ID.
 */
@property (nonatomic, readonly, nullable) NSString *identityCardNumber;

/**
 * The blood group of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *bloodGroup;

/**
 * The date of issue of the Singapore ID.
 */
@property (nonatomic, readonly, nullable) NSString *dateOfIssue;

/**
 * The address of the Singapore ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

@end
