//
//  MBDateResult.h
//  BlinkIdFramework
//
//  Created by DoDo on 07/11/2016.
//
// Copyright (c) 2022 Microblink Ltd. All rights reserved.
// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBNativeResult.h"

@class MBStringResult;

/**
 * This class represents a Date result scanned from the image. It supports obtaining raw NSDates, or raw strings
 * Which are in the same format to the text printed on the image.
 *
 * While converting to NSDate, internally prior knowledge about scanned document is used to use the right format.
 */
MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBDateResult : NSObject <MBNativeResult>

// Unavailable
- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 * Designated initializer
 *
 * @param day day of month
 * @param month month of year
 * @param year gregorian calendar
 * @param originalDateStringResult contains original string which describes that result, e.g "23.4.1988." for every supported alphabet
 * @param isFilledByDomainKnowledge indicates that date is filled by our internal domain knowledge
 *
 * @return initialized value
 */
- (instancetype _Nonnull)initWithDay:(NSInteger)day
                               month:(NSInteger)month
                                year:(NSInteger)year
            originalDateStringResult:(MBStringResult *_Nullable)originalDateStringResult
           isFilledByDomainKnowledge:(BOOL)isFilledByDomainKnowledge NS_DESIGNATED_INITIALIZER;


/**
 * The original string used to create the date result
 */
@property (nonatomic, readonly, nullable) MBStringResult *originalDateStringResult;


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
 * Indicates that date does not appear on the document but is filled by our internal domain knowledge.
 *
 * @return true if the date is filled by our internal domain knowledge
 */
@property (nonatomic, readonly) BOOL isFilledByDomainKnowledge;

/**
 * Factory method
 *
 * @param day day of month
 * @param month month of year
 * @param year gregorian calendar
 * @param originalDateStringResult contains original string which describes that result, e.g "23.4.1988." for every supported alphabet
 * @param isFilledByDomainKnowledge indicates that date is filled by our internal domain knowledge
 *
 * @return initialized value
 */
+ (instancetype _Nonnull)dateResultWithDay:(NSInteger)day
                                     month:(NSInteger)month
                                      year:(NSInteger)year
                  originalDateStringResult:(MBStringResult *_Nullable)originalDateStringResult
                 isFilledByDomainKnowledge:(BOOL)isFilledByDomainKnowledge;

@end
