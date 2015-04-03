//
//  PPOcrLayout.h
//  MicroBlinkFramework
//
//  Created by Jura on 01/02/14.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

@class PPOcrBlock;
@class PPOcrLine;
@class PPOcrChar;
@class PPPosition;

/**
 * Class describing the layour of the document on which the OCR was preformed.
 *
 * Ocr Layout contains one or mode OcrBlocks, each of which contains one or more OcrLines,
 * Each of which contains one or more OcrChars.
 *
 * Ocr layout coordinates and boxes are given in the coordinate system of the image 
 * on which the OCR was performed
 *
 * @see PPOcrBlock
 * @see PPOcrLine
 * @see PPOcrChar
 */
@interface PPOcrLayout : NSObject

/**
 * Bounding box of the layout. Given in the coordinate system of the image on which OCR was performed.
 */
@property (nonatomic, assign) CGRect box;

/**
 * Ocr blocks of the layout
 */
@property (nonatomic, strong) NSArray *blocks;

/**
 * Tranformation matrix which transforms the coordinate system in which the OCR layout is given 
 * (i.e. coordinate system of the image) to the coordinate system of the device screen.
 */
@property (nonatomic, assign) CGAffineTransform transform;

/**
 * Initializer from blocks and transformation
 *
 *  @param ocrBlocks ocr blocks
 *  @param transform transform from the image to device screen
 *
 *  @return initialized ocr layout
 */
- (instancetype)initWithOcrBlocks:(NSArray *)ocrBlocks transform:(CGAffineTransform)transform;

/**
 * Initializer from blocks
 *
 *  @param ocrBlocks ocr blocks
 *
 *  @return initialized ocr layout
 */
- (instancetype)initWithOcrBlocks:(NSArray *)ocrBlocks;

/**
 * Helper method which returna a simple string representation of the ocr layout
 *
 *  @return ocr layout converted to string
 */
- (NSString *)string;

@end

/**
 * Class representing an Ocr Block. Block consists of one or more Ocr Lines.
 *
 * @see PPOcrLine
 */
@interface PPOcrBlock : NSObject

/**
 * Ocr lines of the block
 */
@property (nonatomic, strong) NSArray *lines;

/**
 * Initializer from lines
 *
 *  @param ocrLines ocr lines
 *
 *  @return initialized ocr block
 */
- (instancetype)initWithOcrLines:(NSArray *)ocrLines;

/**
 * Helper method which returna a simple string representation of the ocr block
 *
 *  @return ocr block converted to string
 */
- (NSString *)string;

@end

/**
 * Class representing an Ocr line. line consists of one or more Ocr chars
 *
 * @see PPOcrChar
 */
@interface PPOcrLine : NSObject

/**
 * Ocr chars of the line
 */
@property (nonatomic, strong) NSArray *chars;

/**
 * Initializer from chars
 *
 *  @param ocrChars ocr chars
 *
 *  @return initialized ocr line
 */
- (instancetype)initWithOcrChars:(NSArray *)ocrChars;

/**
 * Helper method which returna a simple string representation of the ocr line
 *
 *  @return ocr line converted to string
 */
- (NSString *)string;

@end

/**
 * Class representing an individual OCR character obtained in the OCR process.
 */
@interface PPOcrChar : NSObject

/**
 * Unicode value of the char
 */
@property (nonatomic, assign) unichar value;

/**
 * Position of the char on the image, in the coordinate system of the image
 */
@property (nonatomic, retain) PPPosition *position;

/**
 * Height of the char
 */
@property (nonatomic, assign) CGFloat height;

/**
 * YES if font is bold
 */
@property (nonatomic, assign, getter = isBold) BOOL bold;

/**
 * YES if font is italic
 */
@property (nonatomic, assign, getter = isItalic) BOOL italic;

/**
 * YES if char is uncertain
 */
@property (nonatomic, assign, getter = isUncertain) BOOL uncertain;

/**
 * Integer value representing OCR quality of the char
 */
@property (nonatomic, assign) NSInteger quality;

/**
 * Initializer for a char
 *
 *  @param value    unicide value
 *  @param position position on the image
 *  @param height   height of the char
 *
 *  @return initialized char
 */
- (instancetype)initWithValue:(unichar)value
                     position:(PPPosition *)position
                       height:(CGFloat)height;

@end

/**
 * Class representing a position on the image. It's given as a box, with 
 * sides aligned to the sides of the image.
 */
@interface PPPosition : NSObject

/**
 * Upper left corner
 */
@property (nonatomic, assign) CGPoint ul;

/**
 * Upper right corner
 */
@property (nonatomic, assign) CGPoint ur;

/**
 * Lower left corner
 */
@property (nonatomic, assign) CGPoint ll;

/**
 * Lower right corner
 */
@property (nonatomic, assign) CGPoint lr;

/**
 * Initializer
 *
 *  @param ul upper left corner
 *  @param ur upper right corner
 *  @param ll lower left cornder
 *  @param lr lower right corner
 *
 *  @return initialized position
 */
- (instancetype)initWithUpperLeft:(CGPoint)ul
                       upperRight:(CGPoint)ur
                        lowerLeft:(CGPoint)ll
                       lowerRight:(CGPoint)lr;

/**
 * Creates a position with offset to a current position. Offset is added.
 *
 *  @param offset
 *
 *  @return position with offset
 */
- (PPPosition *)positionWithOffset:(CGPoint)offset;

/**
 * Helper method converting Position to CGRect
 *
 *  @return CGRect
 */
- (CGRect)rect;

/**
 * Helper method calculating the center of the Position
 *
 *  @return center
 */
- (CGPoint)center;

/**
 * Helper method calcualting the height of the position
 *
 *  @return height
 */
- (CGFloat)height;

@end
