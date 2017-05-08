//
//  PPRecognizerResult.h
//  MicroBlinkFramework
//
//  Created by Jura on 04/04/14.
//  Copyright (c) 2015 MicroBlink Ltd.. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PPMicroBlinkDefines.h"
#import "PPQuadrangle.h"
#import "PPDateResult.h"

@class PPResultDataSourceAdapter;
@class PPOcrLayout;
@class PPBarcodeDetailedData;
@class PPDetectorResult;

typedef NS_ENUM(NSUInteger, PPElementType) {
    PPElementTypeNull,
    PPElementTypeBoolean,
    PPElementTypeInt,
    PPElementTypeString,
    PPElementTypeBarcodeData,
    PPElementTypeQuadrangle,
    PPElementTypeDetectorResult,
    PPElementTypeOcr,
    PPElementTypeDateTime,
    PPElementTypeByteArray,
};

/**
 Common superclass for all result classes of MicroBlink scanning library
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPRecognizerResult : NSObject <NSCopying>

- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 * Initializes the result with a dictionary of result elements
 *
 * @param elements dictionary of result elements
 * @param types     dictionary of result element types
 * @return Initialized instance
 */
- (instancetype _Nonnull)initWithElements:(NSMutableDictionary *_Nonnull)elements
                       resultElementTypes:(NSMutableDictionary<NSString *, NSNumber *> *_Nonnull)types NS_DESIGNATED_INITIALIZER;

/**
 * All data obtained in the recotnition phase is contained in this Dictionay as Key-Value pairs.
 *
 * Values can have different types: NSStrings, NSInteger, PPOcrLayouts...
 *
 * @Warning it's abetter idea to use designated getters getStringElement, getOcrLayoutElement, etc.
 *
 * @return NSDictionary with all key-value pairs obtained in the recongition phase.
 */
- (NSDictionary *_Nonnull)getAllElements;

/**
 * Method returns a dictionary with all string elements found as a recognizer results. Dictionary contains NSString objects.
 *
 * Basically, this method performs filtering of  all elements returned by getAllElements method. Just string elements are left in the
 * dictionary.
 *
 *  @return eturns a dictionary with all string elements found as a recognizer results
 */
- (NSDictionary *_Nonnull)getAllStringElements;


/**
 * Method returns a dictionary with all the type information for each key
 *
 * @return A dictionary with type information for each key.
 */
- (NSMutableDictionary<NSString *, NSNumber *> *_Nonnull)getAllElementTypes;

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
- (NSData *_Nullable)getDataElement:(NSString *_Nonnull)key;

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
- (NSString *_Nullable)getStringElementUsingGuessedEncoding:(NSString *_Nonnull)key;

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
- (NSString *_Nullable)getStringElement:(NSString *_Nonnull)key encoding:(NSStringEncoding)encoding;

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
- (NSNumber *_Nullable)getBoolElement:(NSString *_Nonnull)key;

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
- (NSNumber *_Nullable)getIntElement:(NSString *_Nonnull)key;

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
- (PPOcrLayout *_Nullable)getOcrLayoutElement:(NSString *_Nonnull)key;

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
- (PPBarcodeDetailedData *_Nullable)getBarcodeDetailedDataElement:(NSString *_Nonnull)key;

/**
 * Returns a PPQuadrangle* element from allElements dictionary.
 *
 * If element exists and it's a PPQuadrangle, the method will return specified PPQuadrangle* object
 * If element doesn't exist, the method will return nil.
 *
 *  @param key element key
 *
 *  @return PPQuadrangle quadrangle value.
 */
- (PPQuadrangle *_Nullable)getQuadrangleElement:(NSString *_Nonnull)key;

/**
 * Returns a PPDetectorResult element from allElements dictionary
 *
 * If element exists and it's a PPDetectorResult, the method will return specified PPDetectorResult object
 * If element doesn't exist, the method will return nil.
 *
 *  @param key element key
 *
 *  @return PPDetectorResult detector result value
 */
- (PPDetectorResult *_Nullable)getDetectorResultElement:(NSString *_Nonnull)key;


/**
 * Returns a PPDateResult element from allElements dictionary.
 *
 * If element exists and it's a PPDateResult, the method will return specified NSDate object
 * If element doesn't exist, the method will return nil.
 *
 *  @param key element key
 *
 *  @return date result value
 */
- (PPDateResult *_Nullable)getDateResultElement:(NSString *_Nonnull)key;

/**
 * Returns the xml representation of this result
 *
 *  @return xml representation of this result
 */
- (NSString *_Nonnull)xml;

/**
 * Returns the attributed version of description string
 *
 *  @return the attributed version of description string
 */
- (NSAttributedString *_Nonnull)attributedDescription;

/**
 * Returns string representation of NSData object for passing over URLs
 *
 *  @param data input NSData object
 *
 *  @return string representation of NSData object
 */
+ (NSString *_Nonnull)urlStringFromData:(NSData *_Nonnull)data;

@end
