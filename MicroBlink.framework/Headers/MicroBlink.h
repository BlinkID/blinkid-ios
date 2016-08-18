//
//  MicroBlink.h
//  MicroBlinkFramework
//
//  Created by Jurica Cerovec on 3/29/12.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#ifndef PhotoPayFramework_MicroBlink_h
#define PhotoPayFramework_MicroBlink_h

// Basic class Attributes
#import "PPMicroBlinkDefines.h"

// Include basic API
#import "PPSettings.h"
#import "PPScanningDelegate.h"
#import "PPCoordinator.h"
#import "PPCameraCoordinator.h"
#import "PPViewControllerFactory.h"

// Include Recognizers in BlinkID
#import "PPBlinkIDRecognizers.h"

// Include Overlay view controller headers
#import "PPIDCardOverlayViewController.h"
#import "PPModernBaseOverlayViewController.h"
#import "PPModernOverlayViewController.h"
#import "PPSegmentScanOverlayViewController.h"
#import "PPTemplatingOverlayViewController.h"
#import "PPBaseBarcodeOverlayViewController.h"
#import "PPBarcodeOverlayViewController.h"

// Include Overlay subview headers
#import "PPModernOcrResultOverlaySubview.h"
#import "PPOcrResultOverlaySubview.h"
#import "PPModernViewfinderOverlaySubview.h"
#import "PPOverlaySubview.h"

#endif
