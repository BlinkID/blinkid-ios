//
//  ResultsViewController.m
//  Starbucks-sample
//
//  Created by Jure Cular on 29/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "ResultsViewController.h"
#import "UIColor+MBAdditions.h"

@interface ResultsViewController ()

@property (strong, nonatomic) UIButton *closeButton;

@property (strong, nonatomic) UIButton *submitButton;

@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *labelMap;

@end

/* Graphical attributes */

// Distance from bottom of result view to top submit button
static CGFloat const kBottomResultViewToTopSubmitButtonDistance = 20.f;

// Distance from bottom result view to bottom value label
static CGFloat const kBottomResultViewToBottomValueLabelDistance = 15.f;

// Distance from top result view to top value label
static CGFloat const kTopResultViewToTopValueLabelDistance = 15.f;

// Distance from bottom label to top label
static CGFloat const kLabelToLabelDistance = 12.f;

// Distance from leading result view to leading label
static CGFloat const kLeadingResultViewToLeadingLabelDistance = 35.f;

// Distance from trailing result view to trailing label
static CGFloat const kTrailingResultViewToTrailingLabelDistance = 35.f;

// Submit button height
static CGFloat const kSubmitButtonHeight = 44.f;

// Submit button corner radius
static CGFloat const kSubmitButtonCornerRadius = 4.f;

@implementation ResultsViewController

- (instancetype)initWithLabelsMap:(NSDictionary<NSString *, NSString *> *)labelsMap {
    self = [super init];
    if (self) {
        _labelMap = labelsMap;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor MB_shadowColor];

    self.closeButton = [[UIButton alloc] init];
    [self.closeButton setTitle:@"Close" forState:UIControlStateNormal];
    [self.closeButton setTintColor:[UIColor whiteColor]];
    self.closeButton.titleLabel.font = [UIFont systemFontOfSize:17.0f weight:UIFontWeightRegular];
    [self.closeButton addTarget:self action:@selector(didTapCloseButton:) forControlEvents:UIControlEventTouchUpInside];

    [self.view addSubview:self.closeButton];

    // Set closeButton constraints
    [self.closeButton setTranslatesAutoresizingMaskIntoConstraints:NO];
    [self.closeButton.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor constant:20.f].active = YES;
    [self.closeButton.topAnchor constraintEqualToAnchor:self.view.topAnchor constant:32.f].active = YES;

    self.submitButton = [[UIButton alloc] init];
    self.submitButton.backgroundColor = [UIColor MB_emeraldColor];
    [self.submitButton setTitle:@"SUBMIT" forState:UIControlStateNormal];
    self.submitButton.tintColor = [UIColor whiteColor];
    self.submitButton.titleLabel.font = [UIFont systemFontOfSize:16.0f weight:UIFontWeightRegular];
    self.submitButton.layer.cornerRadius = kSubmitButtonCornerRadius;
    [self.submitButton addTarget:self action:@selector(didTapSubmitButton:) forControlEvents:UIControlEventTouchUpInside];

    [self.view addSubview:self.submitButton];

    // Set submitButton constraints
    [self.submitButton setTranslatesAutoresizingMaskIntoConstraints:NO];
    [self.submitButton.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor constant:20.f].active = YES;
    [self.submitButton.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor constant:-20.f].active = YES;
    [self.submitButton.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor constant:-20.f].active = YES;
    [self.submitButton.heightAnchor constraintEqualToConstant:kSubmitButtonHeight].active = YES;


    if (self.labelMap.count == 0) {
        [self.submitButton.heightAnchor constraintEqualToConstant:44.f].active = YES;
        return;
    }

    UIView *resultContainerView = [[UIView alloc] init];
    resultContainerView.backgroundColor = [UIColor whiteColor];
    resultContainerView.layer.cornerRadius = 12.f;

    [self.view addSubview:resultContainerView];

    [resultContainerView setTranslatesAutoresizingMaskIntoConstraints:NO];

    [resultContainerView.widthAnchor constraintEqualToAnchor:self.submitButton.widthAnchor constant:0.f].active = YES;
    [resultContainerView.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor constant:0.f].active = YES;

    [resultContainerView.bottomAnchor constraintEqualToAnchor:self.submitButton.topAnchor
                                                     constant:-kBottomResultViewToTopSubmitButtonDistance]
        .active = YES;

    UIFont *labelKeyFont = [UIFont systemFontOfSize:14.f weight:UIFontWeightRegular];
    UIFont *labelValueFont = [UIFont systemFontOfSize:18.f weight:UIFontWeightRegular];

    UIColor *labelKeyColor = [UIColor MB_purpleyGreyColor];
    UIColor *labelValueColor = [UIColor MB_slateGreyColor];

    NSArray *keyArray = [self.labelMap allKeys];

    CGFloat height = 0;

    UILabel *lastLabel = nil;
    for (int i = 0; i < keyArray.count; ++i) {
        NSString *key = keyArray[i];
        NSString *value = [self.labelMap objectForKey:key];

        UILabel *labelValue = [self createLabelWithFont:labelValueFont andTextColor:labelValueColor andText:value];
        [resultContainerView addSubview:labelValue];

        [labelValue.leadingAnchor constraintEqualToAnchor:resultContainerView.leadingAnchor
                                                 constant:kLeadingResultViewToLeadingLabelDistance]
            .active = YES;
        [labelValue.trailingAnchor constraintEqualToAnchor:resultContainerView.trailingAnchor
                                                  constant:-kTrailingResultViewToTrailingLabelDistance]
            .active = YES;

        CGSize neededValueSize = [labelValue sizeThatFits:CGSizeMake(CGFLOAT_MAX, CGFLOAT_MAX)];

        if (i == 0) {
            [labelValue.bottomAnchor constraintEqualToAnchor:resultContainerView.bottomAnchor
                                                    constant:-kBottomResultViewToBottomValueLabelDistance]
                .active = YES;
            height += neededValueSize.height + kBottomResultViewToBottomValueLabelDistance;
        } else {
            [labelValue.bottomAnchor constraintEqualToAnchor:lastLabel.topAnchor constant:-kLabelToLabelDistance].active = YES;
            height += kLabelToLabelDistance + neededValueSize.height;
        }

        UILabel *labelKey = [self createLabelWithFont:labelKeyFont andTextColor:labelKeyColor andText:key];
        [resultContainerView addSubview:labelKey];

        [labelKey.bottomAnchor constraintEqualToAnchor:labelValue.topAnchor constant:-kLabelToLabelDistance].active = YES;
        [labelKey.leadingAnchor constraintEqualToAnchor:resultContainerView.leadingAnchor constant:kLeadingResultViewToLeadingLabelDistance]
            .active = YES;
        [labelKey.trailingAnchor constraintEqualToAnchor:resultContainerView.trailingAnchor
                                                constant:-kTrailingResultViewToTrailingLabelDistance]
            .active = YES;

        CGSize neededKeySize = [labelKey sizeThatFits:CGSizeMake(CGFLOAT_MAX, CGFLOAT_MAX)];
        height += kLabelToLabelDistance + neededKeySize.height;

        lastLabel = labelKey;
    }

    [lastLabel.topAnchor constraintEqualToAnchor:resultContainerView.topAnchor constant:kTopResultViewToTopValueLabelDistance].active = YES;
    height += kTopResultViewToTopValueLabelDistance;

    [resultContainerView.heightAnchor constraintEqualToConstant:height];
}

- (UILabel *)createLabelWithFont:(UIFont *)font andTextColor:(UIColor *)color andText:(NSString *)text {
    UILabel *label = [[UILabel alloc] init];
    [label setTranslatesAutoresizingMaskIntoConstraints:NO];
    label.text = text;
    label.font = font;
    label.textAlignment = NSTextAlignmentCenter;
    label.numberOfLines = 0;
    label.textColor = color;
    return label;
}

#pragma mark - Action

- (void)didTapCloseButton:(UIButton *)sender {
    [self.delegate didTapCloseButton:self];
}

- (void)didTapSubmitButton:(UIButton *)sender {
    [self.delegate didTapSubmitButton:self];
}

@end
