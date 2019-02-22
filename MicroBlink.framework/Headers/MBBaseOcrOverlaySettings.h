//
//  MBBaseOcrOverlaySettings.h
//  Microblink
//
//  Created by Dino Gustin on 04/05/2018.
//

#import "MBBaseOverlaySettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class containing UI information
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBaseOcrOverlaySettings : MBBaseOverlaySettings

/**
 * Property that enables showing of flashing dots over characters being scanned.
 *
 * Default: YES
 */
@property (nonatomic) BOOL showOcrDots;

@end

NS_ASSUME_NONNULL_END
