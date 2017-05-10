//
//  PPBlinkOcrHelpViewController.h
//  BlinkOCR-sample
//
//  Created by Jura on 10/03/15.
//  Copyright (c) 2015 MicroBlink. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PPBlinkOcrHelpViewControllerDelegate;

@interface PPBlinkOcrHelpViewController : UIViewController

@property (unsafe_unretained, nonatomic) IBOutlet UIButton *closeButton;

@property (nonatomic, assign) id<PPBlinkOcrHelpViewControllerDelegate> delegate;

- (IBAction)didTapClose:(id)sender;

+ (instancetype)allocFromStoryboardWithName:(NSString *)storyboardName;

@end

@protocol PPBlinkOcrHelpViewControllerDelegate <NSObject>

- (void)blinkOcrHelpViewControllerDelegateWillClose:(PPBlinkOcrHelpViewController *)viewController;

@end
