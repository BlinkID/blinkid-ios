//
//  PPPivotView.m
//  BlinkOCR
//
//  Created by Jura on 01/03/15.
//  Copyright (c) 2015 PhotoPay. All rights reserved.
//

#import "PPPivotView.h"

@interface PPPivotView ()

@property(nonatomic, strong) UIView *container;

@property(nonatomic, strong) NSMutableArray *elementOffsets;

@property(nonatomic, strong) NSMutableArray *labels;

@property(nonatomic, assign) CGFloat width;

@property(nonatomic, assign) NSUInteger selectedLabelIndex;

@property(nonatomic, assign) CGFloat deselectedAlpha;

@end

@implementation PPPivotView

#pragma mark - Setup

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        _font = [UIFont systemFontOfSize:32.f];
        _marginBetweenElements = 30.f;
        _borderMargin = 20.0f;
        _selectedLabelIndex = 0;
        _moveAnimationDuration = 0.4f;
        _deselectedAlpha = 0.4f;

        // change the size of the view dynamically
        self.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;

        // For handling tap
        UITapGestureRecognizer *tapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTap:)];
        [self addGestureRecognizer:tapRecognizer];

        // For handling swipe left
        UISwipeGestureRecognizer *swipeLeftRecognizer = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(handleSwipeLeft:)];
        swipeLeftRecognizer.direction = UISwipeGestureRecognizerDirectionLeft;

        [self addGestureRecognizer:swipeLeftRecognizer];

        // For handling swipe right
        UISwipeGestureRecognizer *swipeRightRecognizer = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(handleSwipeRight:)];
        swipeRightRecognizer.direction = UISwipeGestureRecognizerDirectionRight;

        [self addGestureRecognizer:swipeRightRecognizer];
    }
    return self;
}

- (void)allocLabels {

    self.labels = [[NSMutableArray alloc] initWithCapacity:self.titles.count];

    for (NSString *title in self.titles) {

        UILabel *label = [[UILabel alloc] init];

        label.text = title;
        label.textColor = [UIColor whiteColor];
        label.alpha = self.deselectedAlpha;
        label.font = self.font;

        [label sizeToFit];

        [self.labels addObject:label];
    }

    ((UILabel *)[[self labels] objectAtIndex:self.selectedLabelIndex]).alpha = 1.0f;
}

- (CGFloat)leftBorderMargin {
    if (self.centered) {
        return (self.frame.size.width - ((UILabel *)[self.labels firstObject]).frame.size.width) / 2;
    } else {
        return self.borderMargin;
    }
}

- (CGFloat)rightBorderMargin {
    if (self.centered) {
        return (self.frame.size.width - ((UILabel *)[self.labels lastObject]).frame.size.width) / 2;
    } else {
        return self.borderMargin;
    }
}

- (void)layoutLabels {

    self.elementOffsets = [[NSMutableArray alloc] initWithCapacity:self.labels.count];
    CGFloat offset = [self leftBorderMargin];

    for (UILabel *label in self.labels) {
        label.center = CGPointMake(offset + label.frame.size.width / 2, self.frame.size.height / 2);

        [self.elementOffsets addObject:@(offset)];

        offset += label.frame.size.width + self.marginBetweenElements;
    }

    if (self.labels.count > 1) {
        offset -= self.marginBetweenElements;
    }

    self.width = offset + [self rightBorderMargin];
}

- (void)layoutSubviews {
    [super layoutSubviews];

    // call layout labels because pivot container height might have changed
    [self layoutLabels];
}

- (void)update {

    // remove old container
    [self.container removeFromSuperview];

    // alloc new buttons
    [self allocLabels];

    // layout buttons
    [self layoutLabels];

    // create new container
    self.container = [[UIView alloc] initWithFrame:CGRectMake(0.f, 0.f, self.width, self.bounds.size.height)];

    // add new buttons to container
    for (UILabel *label in self.labels) {
        [self.container addSubview:label];
    }

    // add container to self
    [self addSubview:self.container];
}

#pragma mark - Moving through the Pivot view

- (void)animateOldSelection:(UILabel *)oldSelection newSelection:(UILabel *)newSelection completion:(void (^)(BOOL finished))completion {

    [UIView animateWithDuration:self.moveAnimationDuration / 2.f
        delay:0.0
        options:UIViewAnimationOptionCurveEaseIn
        animations:^{
          oldSelection.alpha = self.deselectedAlpha;
        }
        completion:^(BOOL finished) {
          [UIView animateWithDuration:self.moveAnimationDuration / 2.f
                                delay:0.0
                              options:UIViewAnimationOptionCurveEaseOut
                           animations:^{
                             newSelection.alpha = 1.0f;
                           }
                           completion:completion];
        }];
}

- (void)animateMoveForOffset:(CGFloat)offset completion:(void (^)(BOOL finished))completion {

    [UIView animateWithDuration:self.moveAnimationDuration
                     animations:^{
                       self.container.center = CGPointMake(self.container.center.x - offset, self.container.center.y);
                     }
                     completion:completion];
}

- (void)moveForward {

    if (self.selectedLabelIndex == self.titles.count - 1) {
        return;
    }

    self.userInteractionEnabled = NO;

    [self animateMoveForOffset:[self moveOffsetFromStart:self.selectedLabelIndex toEnd:self.selectedLabelIndex + 1] completion:nil];

    [self.delegate pivotView:self willSelectIndex:self.selectedLabelIndex + 1];

    [self animateOldSelection:[self labelForIndex:self.selectedLabelIndex]
                 newSelection:[self labelForIndex:self.selectedLabelIndex + 1]
                   completion:^(BOOL finished) {
                     self.userInteractionEnabled = YES;
                     self.selectedLabelIndex++;
                     [self.delegate pivotView:self didSelectIndex:self.selectedLabelIndex];
                   }];
}

- (void)moveBackward {

    if (self.selectedLabelIndex == 0) {
        return;
    }

    self.userInteractionEnabled = NO;

    [self animateMoveForOffset:[self moveOffsetFromStart:self.selectedLabelIndex toEnd:self.selectedLabelIndex - 1] completion:nil];

    [self.delegate pivotView:self willSelectIndex:self.selectedLabelIndex - 1];

    [self animateOldSelection:[self labelForIndex:self.selectedLabelIndex]
                 newSelection:[self labelForIndex:self.selectedLabelIndex - 1]
                   completion:^(BOOL finished) {
                     self.userInteractionEnabled = YES;
                     self.selectedLabelIndex--;
                     [self.delegate pivotView:self didSelectIndex:self.selectedLabelIndex];
                   }];
}

#pragma mark - User interaction

- (void)handleTap:(UITapGestureRecognizer *)recognizer {
    CGPoint location = [recognizer locationInView:recognizer.view];

    BOOL tappedForward = (location.x > [self labelForIndex:self.selectedLabelIndex].center.x + self.container.frame.origin.x);

    if (tappedForward) {
        [self moveForward];
    } else {
        [self moveBackward];
    }
}

- (void)handleSwipeLeft:(UISwipeGestureRecognizer *)recognizer {
    [self moveForward];
}

- (void)handleSwipeRight:(UISwipeGestureRecognizer *)recognizer {
    [self moveBackward];
}

#pragma mark - Helpers

- (UILabel *)labelForIndex:(NSUInteger)index {
    return (UILabel *)[self.labels objectAtIndex:index];
}

- (CGFloat)moveOffsetFromStart:(NSUInteger)start toEnd:(NSUInteger)end {
    if (self.centered) {
        CGFloat x1 = ((UILabel *)[self.labels objectAtIndex:end]).center.x;
        CGFloat x2 = ((UILabel *)[self.labels objectAtIndex:start]).center.x;
        return x1 - x2;
    } else {
        CGFloat unit = (self.container.bounds.size.width - self.bounds.size.width) / (self.titles.count - 1);
        return (unit < 0.0f) ? 0.0f : ((int)end - (int)start) * unit;
    }
}

@end
