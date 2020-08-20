//
//  MBDocumentSubview.h
//  PhotoPayFramework
//
//  Created by Jura on 04/02/2017.
//  Copyright © 2017 Microblink Ltd. All rights reserved.
//

#import "MBSubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Overlay subview presenting the viewfinder for scanning ID documents
 *
 * The subview draws a rounded rectangle in the shape of an ID document, in which the user
 * should position the ID (ideal positioning is not required).
 *
 * The rounded rectangle is centered on the screen.
 *
 * The aspect ratio of the document can be set as a parameter
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDocumentSubview : MBSubview

/**
 * Default implementation draws a rectangle with aspect ratio of viewfinderAspectRatio,
 * with corner radius set to 10/360 of the rectangle's width
 * on the center of the view controller
 */
@property (nonatomic) UIView *viewfinderView;

/**
 * Default aspect ratio of the viewfinder, calculated as width / height.
 *
 * By default it's 85.60 / 53.98, which is the dimensions of the ID1 document.
 */
@property (nonatomic) CGFloat viewfinderWidthToHeightRatio;

/**
 * Label displayed below the viewfinder view.
 *
 * By default it shows text @"Position ID card in this Frame";
 */
@property (nonatomic) UILabel *tooltipLabel;

/**
 * Initialize the overlay subview with a given frame
 *
 * @param frame frame for the view
 * @return initialized view
 */
- (instancetype)initWithFrame:(CGRect)frame;

/**
 * Initialize the overlay subview with a given coder
 *
 * @param aDecoder decoder
 * @return initialized view
 */
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder;

@end

NS_ASSUME_NONNULL_END
