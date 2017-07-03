//
//  ResultsViewController.h
//  Starbucks-sample
//
//  Created by Jure Cular on 29/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ResultsViewControllerDelegate;

@interface ResultsViewController : UIViewController

- (instancetype)initWithLabelsMap:(NSDictionary<NSString *, NSString *> *)labelsMap;

@property (weak, nonatomic) UIViewController<ResultsViewControllerDelegate> *delegate;

@end

@protocol ResultsViewControllerDelegate <NSObject>

- (void)didTapSubmitButton:(ResultsViewController *)viewController;

- (void)didTapCloseButton:(ResultsViewController *)viewController;

@end
