//
//  MBOcrLayout.h
//  MicroblinkFramework
//
//  Created by Jura on 01/02/14.
//  Copyright (c) 2015 Microblink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

#import "MBOcrFont.h"

#import "MBMicroblinkDefines.h"

@class MBOcrBlock;
@class MBOcrLine;
@class MBOcrChar;
@class MBPosition;
@class MBCharWithVariants;

NS_ASSUME_NONNULL_BEGIN

/**
 * Class describing the layour of the document on which the OCR was preformed.
 *
 * Ocr Layout contains one or mode OcrBlocks, each of which contains one or more OcrLines,
 * Each of which contains one or more OcrChars.
 *
 * Ocr layout coordinates and boxes are given in the coordinate system of the image
 * on which the OCR was performed
 *
 * @see MBOcrBlock
 * @see MBOcrLine
 * @see MBOcrChar
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBOcrLayout : NSObject

/**
 * Bounding box of the layout. Given in the coordinate system of the image on which OCR was performed.
 */
@property (nonatomic) CGRect box;

/**
 * Ocr blocks of the layout
 */
@property (nonatomic) NSArray<MBOcrBlock *> *blocks;

/**
 * Tranformation matrix which transforms the coordinate system in which the OCR layout is given
 * (i.e. coordinate system of the image) to the coordinate system of the device screen.
 *
 * Tranform can be invalid (if there's no camera UI to which it can be calculated). This can be checked with
 * transformInvalid property.
 */
@property (nonatomic) CGAffineTransform transform;

/**
 * YES if transform is not valid (e.g, there's no UI to which it can be calculated. NO otherwise.
 */
@property (nonatomic) BOOL transformInvalid;

/**
 * Position of layout on the image, in the coordinate system of the image
 */
@property (nonatomic) MBPosition *position;

/**
 * OCR layout was recognized from flipped image
 */
@property (nonatomic) BOOL flipped;

- (instancetype)init NS_UNAVAILABLE;

/**
 * Initializer from blocks and transformation
 *
 *  @param ocrBlocks ocr blocks
 *  @param transform transform from the image to device screen
 *
 *  @return initialized ocr layout
 */
- (instancetype)initWithOcrBlocks:(NSArray<MBOcrBlock *> *)ocrBlocks
                        transform:(CGAffineTransform)transform
                              box:(CGRect)box
                          flipped:(BOOL)flipped NS_DESIGNATED_INITIALIZER;

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
 * @see MBOcrLine
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBOcrBlock : NSObject

/**
 * Ocr lines of the block
 */
@property (nonatomic) NSArray<MBOcrLine *> *lines;

/**
 * Position of the block on the image, in the coordinate system of the image
 */
@property (nonatomic) MBPosition *position;

/**
 * Please use designated initializer.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Initializer from lines
 *
 *  @param ocrLines ocr lines
 *  @param position position of the block on image
 *
 *  @return initialized ocr block
 */
- (instancetype)initWithOcrLines:(NSArray<MBOcrLine *> *)ocrLines position:(MBPosition *)position NS_DESIGNATED_INITIALIZER;

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
 * @see MBOcrChar
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBOcrLine : NSObject

/**
 * Ocr chars of the line
 */
@property (nonatomic) NSArray<MBCharWithVariants *> *chars;

/**
 * Position of the line on the image, in the coordinate system of the image
 */
@property (nonatomic) MBPosition *position;

/**
 * Please use designated initializer.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Initializer from chars
 *
 *  @param ocrChars ocr chars
 *  @param position position of the line on image
 *
 *  @return initialized ocr line
 */
- (instancetype)initWithOcrChars:(NSArray<MBCharWithVariants *> *)ocrChars position:(MBPosition *)position NS_DESIGNATED_INITIALIZER;

/**
 * Helper method which returna a simple string representation of the ocr line
 *
 *  @return ocr line converted to string
 */
- (NSString *)string;

@end

MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCharWithVariants : NSObject

/**
 * Character that was recognised
 */
@property (nonatomic) MBOcrChar * character;

/**
 * Alternative characters which are possible instead of this character.
 *
 * In the list of characters, each char (unicode value), can appear multiple times, each time with different font.
 * This means variant is uniquely defined with a combination of value and font properties.
 *
 * Each variant has quality property set, so you can use it to verify other options.
 *
 * @Warning If you use variants, please note you need to take font into account.
 */
@property (nonatomic) NSSet *variants;

- (instancetype)init NS_UNAVAILABLE;

/**
 * Initializer for a CharWithVariant
 *
 *  @param character Character with all recognition information (value, font, position, etc.)
 *
 *  @return initialized char with zero variants
 */
- (instancetype)initWithValue:(MBOcrChar *)character NS_DESIGNATED_INITIALIZER;

@end

/**
 * Class representing an individual OCR character obtained in the OCR process.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBOcrChar : NSObject

/**
 * Unicode value of the char
 */
@property (nonatomic) unichar value;

/**
 * Position of the char on the image, in the coordinate system of the image
 */
@property (nonatomic) MBPosition *position;

/**
 * Height of the char
 */
@property (nonatomic) CGFloat height;

/**
 * YES if char is uncertain
 */
@property (nonatomic, getter=isUncertain) BOOL uncertain;

/**
 * Integer value representing OCR quality of the char
 */
@property (nonatomic) NSInteger quality;

/**
 * Font of the character
 */
@property (nonatomic) MBOcrFont font;

- (instancetype)init NS_UNAVAILABLE;

/**
 * Initializer for a char
 *
 *  @param value    unicode value
 *  @param position position on the image
 *  @param height   height of the char
 *
 *  @return initialized char
 */
- (instancetype)initWithValue:(unichar)value position:(MBPosition *)position height:(CGFloat)height NS_DESIGNATED_INITIALIZER;

@end

/**
 * Class representing a position on the image. It's given as a box, with
 * sides aligned to the sides of the image.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBPosition : NSObject

/**
 * Upper left corner
 */
@property (nonatomic) CGPoint ul;

/**
 * Upper right corner
 */
@property (nonatomic) CGPoint ur;

/**
 * Lower left corner
 */
@property (nonatomic) CGPoint ll;

/**
 * Lower right corner
 */
@property (nonatomic) CGPoint lr;

- (instancetype)init NS_UNAVAILABLE;

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
- (instancetype)initWithUpperLeft:(CGPoint)ul upperRight:(CGPoint)ur lowerLeft:(CGPoint)ll lowerRight:(CGPoint)lr NS_DESIGNATED_INITIALIZER;

/**
 * Creates a position with offset to a current position. Offset is added.
 *
 *  @param offset Offset by which new position is displaced from the current one.
 *      It's specified with CGPoint, where x value defines x offset, and y value defines y offset
 *
 *  @return position with offset
 */
- (MBPosition *)positionWithOffset:(CGPoint)offset;

/**
 * Helper method converting Position to CGRect
 *
 *  @return Position converted to CGRect
 */
- (CGRect)rect;

/**
 * Helper method calculating the center of the Position
 *
 *  @return center of the position.
 */
- (CGPoint)center;

/**
 * Helper method calculating the height of the position
 *
 *  @return height of the position
 */
- (CGFloat)height;

@end

NS_ASSUME_NONNULL_END
