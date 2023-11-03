//
//  MBErrorReticle.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 10/06/2019.
//

#import "MBSubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A camera reticle detection that locates at the center of screen and uses circular rotation to indicate that
 * the system is active and has detected object.
 */
MB_CLASS_AVAILABLE_IOS(13.0) MB_FINAL
@interface MBErrorReticle : MBSubview

/** Custom tint color used for tinting reticleImage. Ignored if white. */
@property(nonatomic, strong) UIColor *errorColor;
/**
 * Custom reticle image. Shown instead of default circle.
 * Content mode: center.
 * Size: 88 x 88.
 * Default: nil
 */
@property(nonatomic, strong) UIImage *errorReticleImage;

@end

NS_ASSUME_NONNULL_END
