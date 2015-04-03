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

struct RecognitionResultImpl;
typedef struct RecognitionResultImpl RecognitionResultImpl;

/**
 Abstract result of pdf417.mobi library
 */
@interface PPRecognizerResult : NSObject <NSCopying>

/**
 * Private implementation
 */
@property (nonatomic, assign) RecognitionResultImpl *recognitionResult;

/**
 Designated initializer
 
 Requires the type property
 */
- (instancetype)initWithRecognitionResult:(struct RecognitionResultImpl *)recognitionResult;

/**
 * Raw result elements given in key value pairs.
 * Valus can have different types: NSStrings, NSIntegere, PPOcrLayouts...
 * Watch out if you want to use this property directly.
 * Or use designated getters getString, getOcrLayout, etc.
 */
- (NSDictionary *)getAllElements;

/**
 * Returns a NSString* element from resultElements list.
 * If element exists and it's a string, the method will return specified NSString* object
 *
 * If element doesn't exist, the method will return nil.
 *
 *  @param key element key
 *
 *  @return NSString value.
 */
- (NSString *)getStringElement:(NSString *)key;

/**
 * Returns a PPOcrLayout* element from resultElements list.
 * If element exists and it's a OcrLayout, the method will return specified PPOcrLayout* object
 *
 * If element doesn't exist, the method will return nil.
 *
 *  @param key element key
 *
 *  @return PPOcrLayout value.
 */
- (PPOcrLayout *)getOcrLayoutElement:(NSString *)key;

/**
 Returns the xml representation of this result
 */
- (NSString*)xml;

/**
 Returns the attributed version of description string
 */
- (NSAttributedString*)attributedDescription;

/**
 Convenience method for simple display of result inside UITableView
 */
- (PPResultDataSourceAdapter*)getAdapter;

@end
