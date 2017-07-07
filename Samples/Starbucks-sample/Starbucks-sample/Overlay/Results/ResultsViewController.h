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

@property (weak, nonatomic) UIViewController<ResultsViewControllerDelegate> *delegate;


- (instancetype)initWithLabelsMap:(NSDictionary<NSString *, NSString *> *)labelsMap NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

@protocol ResultsViewControllerDelegate <NSObject>

- (void)didTapSubmitButton:(ResultsViewController *)viewController;

- (void)didTapCloseButton:(ResultsViewController *)viewController;

@end
