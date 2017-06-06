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

@property (nonatomic) UILabel *message;
@property (nonatomic) UILabel *resultMessage;

@property (nonatomic) UIButton *cancelButton;
@property (nonatomic) UIButton *repeatButton;
@property (nonatomic) UIButton *acceptButton;

@property (nonatomic) NSLayoutConstraint *acceptButtonConstraintWidth;
@property (nonatomic) NSLayoutConstraint *repeatButtonConstraintWidth;
@property (nonatomic) NSLayoutConstraint *cancelButtonConstraintWidth;

@property (nonatomic) UIImageView *resultImageView;

@property (nonatomic) UIView *shadeTop;
@property (nonatomic) UIView *shadeBottom;
@property (nonatomic) UIView *shadeLeft;
@property (nonatomic) UIView *shadeRight;

@property (nonatomic, readonly) UIView *viewfinder;


- (void)initViewfinder;

- (void)initViewfinderForPortrait;
- (void)initViewfinderForLandscape;

- (void)setButtonsSizeToFitText;
- (void)setOcrResultSucces:(BOOL)succes withResult:(NSString *)result andImage:(UIImage *)resultImage;
- (void)resetScanningState;
- (void)setTranslation:(NSDictionary *)translation;

- (NSString *)getScanningResult;

@end

@protocol PPOcrFinderViewDelegate <NSObject>

- (BOOL)viewfinderViewIsScanningPaused:(PPOcrFinderView *)viewfinderView;

- (void)viewfinderViewDidTapCancelButton:(UIButton *)sender;
- (void)viewfinderViewDidTapRepeatButton:(UIButton *)sender;
- (void)viewfinderViewDidTapAcceptButton:(UIButton *)sender;

@end
