//
//  MBDocumentOverlaySettings.h
//  MicroBlink
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
 * Gets/sets tootlip text that is defines under document view finder
 */
@property(nonatomic, strong) NSString *tooltipText;

/**
 * Gets/sets tooltip visibility
 */
@property(nonatomic, assign) BOOL showTooltip;

@end

NS_ASSUME_NONNULL_END
