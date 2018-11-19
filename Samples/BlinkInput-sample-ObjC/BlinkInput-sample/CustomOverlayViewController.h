//
//  CutomViewController.h
//  BlinkInput-sample
//
//  Created by Jura Skrlec on 09/11/2018.
//  Copyright © 2018 MicroBlink. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <MicroBlink/MicroBlink.h>

NS_ASSUME_NONNULL_BEGIN

@interface CustomOverlayViewController : MBCustomOverlayViewController<MBScanningRecognizerRunnerViewControllerDelegate>


+ (CustomOverlayViewController *)initFromStoryBoard;

@end

NS_ASSUME_NONNULL_END
