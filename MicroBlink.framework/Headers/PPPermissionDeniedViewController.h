//
//  PPPermissionDeniedViewController.h
//  PhotoPayFramework
//
//  Created by Dino on 16/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PPMicroBlinkDefines.h"

@protocol PPPermissionDeniedDelegate;

PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPPermissionDeniedViewController : UIViewController

@property (nonatomic) id<PPPermissionDeniedDelegate> delegate;

@property (nonatomic, assign) BOOL hideCancelButton;

@end

@protocol PPPermissionDeniedDelegate <NSObject>

- (void)userDidTapCancel:(PPPermissionDeniedViewController *)viewController;

@end
