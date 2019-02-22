//
//  MBScanElement.h
//
//  Created by Jura on 02/03/15.
//  Copyright (c) 2015 PhotoPay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MBParser.h"
#import "MBMicroblinkInitialization.h"
#import "MBImage.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The easiest way to UI for Ocr scanning is by specifying the MBScanElements.
 *
 * Each MBScanElement knows
 *  - it's name and Parser factory - which are needed for actual parsing
 *  - localized Title and Tooltip - which are needed in the UI
 *  - scanning region - percentage of screen used in scanning the element
 *  - information whether the element was scanned or edited
 *  - actual value of the element, used in business logic after the scannig
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBScanElement : NSObject

/**
 * Designated initializer, defines the unique identifier for this canned element, and Parser factory for it.
 *
 *  @param identifier unique ID for this scan element
 *  @param parser    parser which knows how to scan this element
 *
 *  @return initialized instance
 */
- (instancetype)initWithIdentifier:(NSString *)identifier parser:(MBParser *)parser NS_DESIGNATED_INITIALIZER;

MB_INIT_UNAVAILABLE;

/**
 * Unique name of the element
 */
@property(nonatomic, strong, readonly) NSString *identifier;

/**
 * Parser object which is reponsible scanning the text.
 */
@property(nonatomic, strong, readonly) MBParser *parser;

/**
 * Localized title (used in the Pivot control)
 */
@property(nonatomic, strong) NSString *localizedTitle;

/**
 * Localized tooltip (used in the tooltip label above the viewfinder)
 */
@property(nonatomic, strong) NSString *localizedTooltip;

/**
 * Keyboard type used when editing
 */
@property(nonatomic, assign) UIKeyboardType keyboardType;

/**
 * Localized initial UITextField text (used in field segment scanning text fields)
 */
@property(nonatomic) NSString *localizedTextfieldText;

/**
 * YES if the value was scanned, NO otherwise.
 * Note: Both scanned and edited cannot be set to YES.
 */
@property(nonatomic, assign) BOOL scanned;

/**
 * YES if the value was manually edited, NO otherwise.
 * Note: Both scanned and edited cannot be set to YES.
 */
@property(nonatomic, assign) BOOL edited;

/**
 * Actual value for this element
 */
@property(nonatomic, strong) NSString *value;

/**
 * Width of scanning region used in UI. Values are between 0.0 and 1.0 where 1.0 is whole screen width and 0.5 is half width.
 */
@property(nonatomic) float scanningRegionWidth;

/**
 * Height of scanning region used in UI. Values are between 0.0 and 1.0 where 1.0 is whole screen height and 0.5 is half height.
 */
@property(nonatomic) float scanningRegionHeight;

/**
 * Image of the scanned element.
 *
 * Images will NOT be outputted unless outputSuccessfulImages is enabled on MBFieldByFieldOverlaySettings.
 */
@property(nonatomic) MBImage *successfulScanImage;

@end

NS_ASSUME_NONNULL_END
