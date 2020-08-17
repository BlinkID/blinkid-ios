//
//  MBGlareStatusSubview.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 14/09/2017.
//
//

#import "MBSubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Overlay subview presenting the status of glare detection.
 * The subview is presented as translucent view with detection status label in the center of ID Card View Finder View
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBGlareStatusSubview : MBSubview

@property (nonatomic) UILabel *label;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

- (void)glareDetectionFinishedWithResult:(BOOL)glareFound;

@end

NS_ASSUME_NONNULL_END
