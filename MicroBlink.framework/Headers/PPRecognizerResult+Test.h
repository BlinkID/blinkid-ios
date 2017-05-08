//
//  PPRecognizerResult+Test.h
//  PhotoPayFramework
//
//  Created by Jura on 28/02/2017.
//  Copyright © 2017 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerResult.h"

/**
 * Helper methods mostly used in testing of PPRecognizerResult objects
 */
@interface PPRecognizerResult (Test)


/**
 * Method which creates a object representation of NSString objects in recognizer results
 */
+ (NSData *)dataWithString:(NSString *)string;

/**
 * Method which creates a object representation of NSDate objects in recognizer results
 */
+ (PPDateResult *)dateWithDate:(NSDate *)date;

/**
 * Method which creates a object representation of BOOL values in recognizer results
 */
+ (NSNumber *)dataWithBool:(BOOL)value;

/**
 * Helper method which fills in value and type dictionaries based on an given string. It uses dataWithString helper method
 */
+ (void)addString:(NSString *)string
           forKey:(NSString *)key
        valueDict:(NSMutableDictionary *)valueDict
         typeDict:(NSMutableDictionary *)typeDict;

/**
 * Helper method which fills in value and type dictionaries based on an given date object. It uses dateWithDate helper method
 */
+ (void)addDate:(NSDate *)date forKey:(NSString *)key valueDict:(NSMutableDictionary *)valueDict typeDict:(NSMutableDictionary *)typeDict;

/**
 * Helper method which fills in value and type dictionaries based on an given bool value. It uses dataWithBool helper method
 */
+ (void)addBool:(BOOL)value forKey:(NSString *)key valueDict:(NSMutableDictionary *)valueDict typeDict:(NSMutableDictionary *)typeDict;

/**
 * Helper method which fills in value and type dictionaries based on an given NSData object. It directly writes the data object to dictionaries
 */
+ (void)addData:(NSData *)data forKey:(NSString *)key valueDict:(NSMutableDictionary *)valueDict typeDict:(NSMutableDictionary *)typeDict;

@end
