//
//  PPCroIDBackRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Boris Trubic on 05/05/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPMrtdRecognizerResult.h"

/**
 * Result of scanning with Croatian ID Back side recognizer
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPCroIDBackRecognizerResult : PPMrtdRecognizerResult

/**
 * The address of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The issuing authority of Croatian ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The document date of issue of the Croatian ID.
 */
@property (nonatomic, readonly, nullable) NSString *documentDateOfIssue;

@end
