//
//  PPResult.h
//  BlinkIdFramework
//
//  Created by DoDo on 07/11/2016.
//  Copyright © 2016 Microblink Ltd. All rights reserved.
//

#ifndef PPResult_h
#define PPResult_h

#import "Foundation/Foundation.h"

@protocol MBNativeResult

/**
 * Returns the native object containing the result. For example, for MBDateResult, this method
 * will return NSDate object.
 */
- (NSObject *_Nullable)nativeResult;

/**
 * Returns the string version of the result. For example, for MBDateResult, this method
 * will return original string from which date was parsed (same as MBDateResult's originalDateString property}.
 */
- (NSString *_Nullable)stringResult;

@end

#endif /* PPResult_h */
