//
//  PPDateResult.h
//  BlinkIdFramework
//
//  Created by DoDo on 07/11/2016.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PPMicroBlinkDefines.h"
#import "PPNativeResult.h"

/**
 * This class represents a Date result scanned from the image. It supports obtaining raw NSDates, or raw strings
 * Which are in the same format to the text printed on the image.
 *
 * While converting to NSDate, internally prior knowledge about scanned document is used to use the right format.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPDateResult : NSObject <PPNativeResult>

// Unavailable
- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 * Designated initializer
 *
 * @param day day of month
 * @param month month of year
 * @param year gregorian calendar
 * @param originalDateString original string which describes that result, e.g "23.4.1988."
 *
 * @return initialized value
 */
- (instancetype _Nonnull)initWithDay:(NSInteger)day
                               month:(NSInteger)month
                                year:(NSInteger)year
                  originalDateString:(NSString *_Nullable)originalDateString NS_DESIGNATED_INITIALIZER;


/**
 * The original string used to create the date result
 */
@property (nonatomic, readonly, nullable) NSString *originalDateString;


/**
 * NSDate object which represents the same date as this result
 */
@property (nonatomic, readonly, nonnull) NSDate *date;


/**
 * Factory method
 *
 * @param day day of month
 * @param month month of year
 * @param year gregorian calendar
 * @param originalDateString original string which describes that result, e.g "23.4.1988."
 *
 * @return initialized value
 */
+ (instancetype _Nonnull)dateResultWithDay:(NSInteger)day
                                     month:(NSInteger)month
                                      year:(NSInteger)year
                        originalDateString:(NSString *_Nullable)originalDateString;

@end
