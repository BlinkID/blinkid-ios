//
//  MBBlinkCardOverlaySettings.h
//  MicroBlink
//
//  Created by Jura on 31/01/2019.
//

#import "MBBaseOcrOverlaySettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class containing UI information for BlinkCard
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBlinkCardOverlaySettings : MBBaseOcrOverlaySettings

/**
 * Returns/sets glare status message that is shown if glare detection is turned on
 * and it is shown if glare is detected.
 *
 * Default: string defined by "photopay_glare_status"
 * key in strings file in Microblink.bundle
 */
@property(nonatomic, strong) NSString *glareStatusMessage;

@end

NS_ASSUME_NONNULL_END
