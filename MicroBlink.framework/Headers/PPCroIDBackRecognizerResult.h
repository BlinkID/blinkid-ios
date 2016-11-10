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
 *
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPCroIDBackRecognizerResult : PPMrtdRecognizerResult

/**
 * Returns the address of the Croatian ID owner.
 *
 * @return the address of the Croatian ID owner.
 */
- (NSString * _Nullable)address;

/**
 * Returns the issuing authority of Croatian ID.
 *
 * @return the issuing authority of Croatian ID.
 */
- (NSString * _Nullable)issuingAuthority;

/**
 * Returns the document date of issue of the Croatian ID.
 *
 * @return the document date of issue of the Croatian ID.
 */
- (NSString * _Nullable)documentDateOfIssue;

@end
