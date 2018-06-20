//
//  MBBarcodeUISettings.h
//  MicroBlink
//
//  Created by Dino Gustin on 04/05/2018.
//

#import "MBBaseOverlaySettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class containing UI information
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBarcodeOverlaySettings : MBBaseOverlaySettings

@property (nonatomic, assign) BOOL displayBarcodeDots;

@property (nonatomic, assign) BOOL displayViewfinder;

@end

NS_ASSUME_NONNULL_END
