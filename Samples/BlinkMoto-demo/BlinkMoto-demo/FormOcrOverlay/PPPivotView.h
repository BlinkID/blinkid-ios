//
//  PPPivotView.h
//  BlinkOCR
//
//  Created by Jura on 01/03/15.
//  Copyright (c) 2015 PhotoPay. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PPPivotViewDelegate;

@interface PPPivotView : UIView

/**
 * Array of NSString* objects which should be presented in Pivot view
 */
@property(nonatomic, strong) NSArray *titles;

/**
 * Font used in Pivot view control
 */
@property(nonatomic, strong) UIFont *font;

/**
 * Margin bewteen elements in Pivot view.
 * Default is 30.f
 */
@property(nonatomic, assign) CGFloat marginBetweenElements;

/**
 * Margin between the edge of the UIView and first (and last) elements
 * Default is 20.f
 */
@property(nonatomic, assign) CGFloat borderMargin;

/**
 * Duration for move animation.
 * Default: 0.4f;
 */
@property(nonatomic, assign) CGFloat moveAnimationDuration;

/**
 * Delegate which gets notified on move events.
 */
@property(nonatomic, weak) id<PPPivotViewDelegate> delegate;

/**
 * If yes, Pivot view will be centered.
 */
@property(nonatomic, assign) BOOL centered;

/**
 * After initializing the Pivot View and setting the titles property, the caller needs to call
 * update method to set up the View hierarchy.
 */
- (void)update;

/**
 * Initiates move to the next element
 * Delegate methods will be called.
 */
- (void)moveForward;

/**
 * Initiates move to the previous element.
 * Delegate methods will be called.
 */
- (void)moveBackward;

@end

/**
 * If the user of the PivotView want's to be notified on pivot move events, it can implement this
 * protocol.
 */
@protocol PPPivotViewDelegate <NSObject>

/**
 * Called before the move animation will appear
 *
 *  @param pivotView current pivot view
 *  @param index     new index which will be selected
 */
- (void)pivotView:(PPPivotView *)pivotView willSelectIndex:(NSUInteger)index;

/**
 * Called after the move aniamtion is over
 *
 *  @param pivotView current pivot view
 *  @param index     new index which will be selected
 */
- (void)pivotView:(PPPivotView *)pivotView didSelectIndex:(NSUInteger)index;

@end
