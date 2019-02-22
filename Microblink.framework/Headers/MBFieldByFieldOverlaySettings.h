//
//  MBFieldByFieldUISettings.h
//  Microblink
//
//  Created by Dino Gustin on 04/05/2018.
//

#import "MBOverlaySettings.h"
#import "MBScanElement.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class containing UI information
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBFieldByFieldOverlaySettings : MBOverlaySettings

/**
 * Designated initializer for settings.
 */
- (instancetype)initWithScanElements:(NSArray<MBScanElement *> *)scanElements NS_DESIGNATED_INITIALIZER;

MB_INIT_UNAVAILABLE;

/**
 * Array of MBScanElement objects which defines which Elements are scanned.
 */
@property(nonatomic, strong, readonly) NSArray<MBScanElement *> *scanElements;

/**
 * Property that enables showing of flashing dots over characters being scanned.
 *
 * Default: YES
 */
@property (nonatomic) BOOL showOcrDots;

/**
 * Property that enables outputting images of sucessful scans for each element scanned.
 *
 * Default: NO
 */
@property (nonatomic) BOOL outputSuccessfulImages;

/**
 * Number of times same parse result needs to be outputted to be considered valid
 *
 * Default: 3
 */
@property(nonatomic) NSUInteger consecutiveScanThreshold;

/**
 * Background color of successful scan result
 */
@property(nonatomic) UIColor *scanResultViewColor;

/**
 * Returns/sets next button description text that is shown above next button
 * when there are still scanning elements left to be scanned
 *
 * Default: string defined by "field_by_field_next_button_description"
 * key in strings file in Microblink.bundle
 */
@property(nonatomic, strong) NSString *nextButtonDescriptionText;

/**
 * Returns/sets next button description text that is shown above next button
 * when there are no scanning elements left to be scanned
 *
 * Default: string defined by "field_by_field_last_next_button_description"
 * key in strings file in Microblink.bundle
 */
@property(nonatomic, strong) NSString *nextButtonLastDescriptionText;

@end

NS_ASSUME_NONNULL_END
