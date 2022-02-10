//
//  MBDateResult.h
//  BlinkIdFramework
//
//  Created by DoDo on 07/11/2016.
//  Copyright © 2016 Microblink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBNativeResult.h"

/**
 * This class represents a Date result scanned from the image. It supports obtaining raw NSDates, or raw strings
 * Which are in the same format to the text printed on the image.
 *
 * While converting to NSDate, internally prior knowledge about scanned document is used to use the right format.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDateResult : NSObject <MBNativeResult>

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
@property (nonatomic, readonly, nullable) NSDate *date;

/**
 * Day in month.
 */
@property (nonatomic, readonly, assign) NSInteger day;

/**
 * Month in year.
 */
@property (nonatomic, readonly, assign) NSInteger month;

/**
 * Year of the current date.
 */
@property (nonatomic, readonly, assign) NSInteger year;


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
