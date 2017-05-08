//
//  PPTapToFocusOverlaySubview.h
//  BlinkOcrFramework
//
//  Created by Jura on 18/09/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPOverlaySubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Overlay subview presenting the effect which happens when the user taps to focus
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPTapToFocusOverlaySubview : PPOverlaySubview

/**
 * Designated initializer 
 *
 * @param frame - exact frame of the view
 */
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
