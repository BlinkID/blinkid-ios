//
//  PPUiSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 24/02/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Different options for displaying help
 */
typedef NS_ENUM(NSUInteger, PPHelpDisplayMode) {

    /** Defines that help should never be displayed */
    PPHelpDisplayModeNever,

    /** Defines help should only be displayed on first PhotoPay run */
    PPHelpDisplayModeFirstRun,

    /** Defines help should be displayed on every PhotoPay run */
    PPHelpDisplayModeAlways
};

/**
 * Settings class containing UI information
 */
@interface PPUiSettings : NSObject <NSCopying>

/**
 * If YES, default camera overlay will display Cancel button.
 * Usually, if camera is displayed inside Navigation View Controler, this is reasonable to set to NO.
 *
 * Default: YES.
 */
@property (nonatomic, assign) BOOL showCloseButton;

/**
 * If YES, Overlay View Controller will be autorotated independently of ScanningViewController.
 *
 * Default: NO.
 */
@property (nonatomic, assign) BOOL autorotateOverlay;

/**
 * If YES, OCR results will be passed to the UI callbacks. For you, this means OCR effects will be shown on screen.
 * 
 * Default: YES. Use NO if you care about scanning speed.
 */
@property (nonatomic, assign) BOOL showOcrResults;

/**
 * If default overlay contains textual information, text will be localized to this language
 *
 * Default: nil, because it uses default language of the device
 */
@property (nonatomic, strong) NSString* language;

/**
 * Full path to the sound file which is played when the valid result is scanned.
 *
 * Default: `[[NSBundle mainBundle] pathForResource:@"PPbeep" ofType:@"wav"];`
 */
@property (nonatomic, strong) NSString* soundFilePath;


/**
 * If YES, debug information will be displayed on the information.
 * Debug information displays payslip detection duration and recognition duration.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL displayDebugInfo;

/**
 * If Scanning UI has Help UI available, this enum defines the mode in which the help is displayed.
 *
 * Default: PPHelpDisplayModeFirstRun
 */
@property (nonatomic, assign) PPHelpDisplayMode helpDisplayMode;

/**
 * Designated initializer. Initializes the object with default settings (see above for defaults)
 *
 *  @return object initialized with default values.
 */
- (instancetype)init;

@end
