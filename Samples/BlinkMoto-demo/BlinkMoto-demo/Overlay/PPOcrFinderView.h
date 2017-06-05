//
//  PPOcrFinderView.h
//  BlinkMoto-demo
//
//  Created by Jura Skrlec on 02/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PPOcrFinderViewDelegate;

@interface PPOcrFinderView : UIView

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

@property (nonatomic, weak) IBOutlet id<PPOcrFinderViewDelegate> delegate;

@property (nonatomic, readonly) CGRect scanningRegion;
@property (nonatomic, readonly) CGRect motionEstimationRegion;
@property (nonatomic, readonly) UIInterfaceOrientation scanningOrientation;

- (void)initViewfinder;

- (void)setScanningOrientation:(UIInterfaceOrientation)scanningOrientation animated:(BOOL)animated;

@end

@protocol PPOcrFinderViewDelegate <NSObject>

- (void)viewfinderViewUpdatedScanningRegion:(PPOcrFinderView *)viewfinderView;
- (BOOL)viewfinderViewIsScanningPaused:(PPOcrFinderView *)viewfinderView;

@end
