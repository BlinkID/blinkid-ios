//
//  PPOcrResult.h
//  PhotoPayFramework
//
//  Created by Jura on 01/02/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

@class PPOcrBlock;
@class PPOcrLine;
@class PPOcrChar;
@class PPPosition;

@interface PPOcrResult : NSObject

@property (nonatomic, assign) CGRect box;

@property (nonatomic, strong) NSArray* blocks;

@property (nonatomic, assign) CGAffineTransform transform;

- (id)initWithOcrBlocks:(NSArray *)ocrBlocks transform:(CGAffineTransform)transform;

- (id)initWithOcrBlocks:(NSArray*)ocrBlocks;

- (NSString*)string;

@end

@interface PPOcrBlock : NSObject

@property (nonatomic, strong) NSArray* lines;

- (id)initWithOcrLines:(NSArray*)ocrLines;

- (NSString*)string;

@end

@interface PPOcrLine : NSObject

@property (nonatomic, strong) NSArray* chars;

- (id)initWithOcrChars:(NSArray*)ocrChars;

- (NSString*)string;

@end

@interface PPOcrChar : NSObject

@property (nonatomic, assign) unichar value;

@property (nonatomic, retain) PPPosition* position;

@property (nonatomic, assign) CGFloat height;

@property (nonatomic, assign, getter = isBold) BOOL bold;

@property (nonatomic, assign, getter = isItalic) BOOL italic;

@property (nonatomic, assign, getter = isUncertain) BOOL uncertain;

@property (nonatomic, assign) NSInteger quality;

- (id)initWithValue:(unichar)value
           position:(PPPosition*)position
             height:(CGFloat)height;

@end

@interface PPPosition : NSObject

@property (nonatomic, assign) CGPoint ul;
@property (nonatomic, assign) CGPoint ur;
@property (nonatomic, assign) CGPoint ll;
@property (nonatomic, assign) CGPoint lr;

- (id)initWithUpperLeft:(CGPoint)ul
             upperRight:(CGPoint)ur
              lowerLeft:(CGPoint)ll
             lowerRight:(CGPoint)lr;

- (PPPosition*)allocPositionWithOffset:(CGPoint)offset;

- (CGRect)rect;

- (CGPoint)center;

- (CGFloat)height;

@end
