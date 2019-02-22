//
//  MBDocumentOverlaySettings.h
//  Microblink
//
//  Created by Dino Gustin on 04/05/2018.
//

#import "MBBaseOcrOverlaySettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class containing UI information
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDocumentOverlaySettings : MBBaseOcrOverlaySettings

/**
 * Gets/sets tootlip text that is defines under document view finder.
 *
 * Default: string defined by "photopay_id_position_tooltip"
 * key in strings file in Microblink.bundle
 */
@property(nonatomic, strong) NSString *tooltipText;

/**
 * Returns/sets glare status message that is shown if glare detection is turned on
 * and it is shown if glare is detected.
 *
 * Default: string defined by "photopay_glare_status"
 * key in strings file in Microblink.bundle
 */
@property(nonatomic, strong) NSString *glareStatusMessage;

/**
 * Gets/sets tooltip visibility
 */
@property(nonatomic, assign) BOOL showTooltip;

/**
 * Gets/sets capturing of high resolution image
 *
 * Default: NO
 */
@property(nonatomic, assign) BOOL captureHighResImage;

@end

NS_ASSUME_NONNULL_END
