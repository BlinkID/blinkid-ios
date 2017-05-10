//
//  PPScanResultView.h
//  BlinkOCR
//
//  Created by Jura on 01/03/15.
//  Copyright (c) 2015 PhotoPay. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 * View responsible for displaying scannng result
 */
@interface PPScanResultView : UIView

/**
 * Text field which can be used to manually edit the text
 */
@property(weak, nonatomic) IBOutlet UITextField *textField;

/**
 * Animates the display of scan result view.
 *
 * Animation emerges from the point "point", and moves to the frame specified by "bounds" and "center".
 * Animation duration is specified by animationDuration, and completion block by "completion"
 *
 *  @param startCenter             emerging point of the animation (center of given view)
 *  @param end            final view frame of the aniamtion
 *  @param animationDuration duration of the animation
 *  @param completion        completion block
 */
- (void)animateShowFromViewCenter:(UIView *)startCenter
                          toFrame:(UIView *)end
                animationDuration:(NSTimeInterval)animationDuration
                       completion:(void (^)(BOOL finished))completion;

/**
 * Animates the hiding of the scan result view
 *
 *  @param endCenter             vanishing point of the animation (center of given view)
 *  @param animationDuration duration of the animation
 *  @param completion        completion block
 */
- (void)animateHideToViewCenter:(UIView *)endCenter animationDuration:(NSTimeInterval)animationDuration completion:(void (^)(BOOL finished))completion;

/**
 * Used for easier instantiation from Nib file
 *
 *  @param nibName Name of the nib file
 *
 *  @return Scan result view instance
 */
+ (instancetype)allocFromNibName:(NSString *)nibName;

@property (weak, nonatomic) IBOutlet UILabel *labelResultTitle;

@end
