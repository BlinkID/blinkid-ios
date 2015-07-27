//
//  PPRecognizerResult.h
//  MicroBlinkFramework
//
//  Created by Jura on 04/04/14.
//  Copyright (c) 2015 MicroBlink ČLtd.. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PPResultDataSourceAdapter;
@class PPOcrLayout;
@class PPBarcodeDetailedData;

struct RecognitionResultImpl;
typedef struct RecognitionResultImpl RecognitionResultImpl;

/**
 Common superclass for all result classes of MicroBlink scanning library
 */
@interface PPRecognizerResult : NSObject <NSCopying>

@property (nonatomic, assign) RecognitionResultImpl *recognitionResult;

- (instancetype)initWithRecognitionResult:(struct RecognitionResultImpl *)recognitionResult;

/**
 * All data obtained in the recotnition phase is contained in this Dictionay as Key-Value pairs.
 *
 * Values can have different types: NSStrings, NSInteger, PPOcrLayouts...
 * 
 * @Warning it's abetter idea to use designated getters getStringElement, getOcrLayoutElement, etc.
 *
 * @return NSDictionary with all key-value pairs obtained in the recongition phase.
 */
- (NSDictionary *)getAllElements;

/**
 * Method returns a dictionary with all string elements found as a recognizer results. Dictionary contains NSString objects.
 *
 * Basically, this method performs filtering of  all elements returned by getAllElements method. Just string elements are left in the dictionary.
 *
 *  @return eturns a dictionary with all string elements found as a recognizer results
 */
- (NSDictionary *)getAllStringElements;

/**
 * Returns NSData* element from allElements dictionary.
 *
 * If element exists and it's a NSData, the method will return NSData* object
 * If element doesn't exist, the method will return nil.
 *
 *  @param key element key
 *
 *  @return NSData value.
 */
- (NSData *)getDataElement:(NSString *)key;

/**
 * Returns a NSString* element from allElements dictionary using guessed encoding.
 *
 * If element exists and it's a string, the method will return specified NSString* object
 * If element doesn't exist, the method will return nil.
 *
 *  @param key element key
 *
 *  @return NSString value.
 */
- (NSString *)getStringElementUsingGuessedEncoding:(NSString *)key;

/**
 * Returns a NSString* element from allElements dictionary, using a given encoding.
 *
 * If element exists and it's a string, the method will return specified NSString* object, using specified encoding.
 * If element doesn't exist, the method will return nil.
 *
 *  @param key      element key
 *  @param encoding The encoding for the returned string.
 *
 *  @return String created from data property, using given encoding
 */
- (NSString *)getStringElement:(NSString *)key
                      encoding:(NSStringEncoding)encoding;

/**
 * Returns a NSNumber containing a BOOL element from allElements dictionary.
 *
 * If elements exists and it's a bool, the method will return specified BOOL value inside NSNumber object.
 * If element doesn't exist or not a bool, the method will return nil.
 *
 *  @param key element key
 *
 *  @return NSNumber with bool
 */
- (NSNumber *)getBoolElement:(NSString *)key;

/**
 * Returns a NSNumber containing a int element from allElements dictionary.
 *
 * If elements exists and it's an int, the method will return specified int value inside NSNumber object.
 * If element doesn't exist or not an int, the method will return nil.
 *
 *  @param key element key
 *
 *  @return NSNumber with int
 */
- (NSNumber *)getIntElement:(NSString *)key;

/**
 * Returns a PPOcrLayout* element from allElements dictionary.
 *
 * If element exists and it's a OcrLayout, the method will return specified PPOcrLayout* object
 * If element doesn't exist, the method will return nil.
 *
 *  @param key element key
 *
 *  @return PPOcrLayout value.
 */
- (PPOcrLayout *)getOcrLayoutElement:(NSString *)key;

/**
 * Returns PPBarcodeDetailedData* element from allElements dictionary..
 *
 * If element exists and it's a PPBarcodeDetailedData, the method will return it.
 * If element doesn't exist, the method will return nil
 *
 *  @param key element key
 *
 *  @return PPBarcodeDetailedData value
 */
- (PPBarcodeDetailedData *)getBarcodeDetailedDataElement:(NSString *)key;

/**
 * Returns the xml representation of this result
 *
 *  @return xml representation of this result
 */
- (NSString*)xml;

/**
 * Returns the attributed version of description string
 *
 *  @return the attributed version of description string
 */
- (NSAttributedString*)attributedDescription;

/**
 * Convenience method for simple display of result inside UITableView
 *
 *  @return PPResultDataSourceAdapter object
 */
- (PPResultDataSourceAdapter*)getAdapter;

/**
 * Returns string representation of NSData object for passing over URLs
 *
 *  @param data input NSData object
 *
 *  @return string representation of NSData object
 */
+ (NSString *)urlStringFromData:(NSData *)data;

@end
