//
//  MBTapToFocusSubview.h
//  BlinkOcrFramework
//
//  Created by Jura on 18/09/16.
//  Copyright © 2016 Microblink Ltd. All rights reserved.
//

#import "MBSubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Overlay subview presenting the effect which happens when the user taps to focus
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBTapToFocusSubview : MBSubview
/**
 * Designated initializer 
 *
 * @param frame - exact frame of the view
 */
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (void)willFocusAtPoint:(CGPoint)point;

@end

NS_ASSUME_NONNULL_END
