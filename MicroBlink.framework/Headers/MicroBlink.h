//
//  MicroBlink.h
//  MicroBlinkFramework
//
//  Created by Dino Gustin on 06/06/18.
//  Copyright (c) 2012 MicroBlink Ltd. All rights reserved.
//

// Include Common API
#import "MBMicroblinkApp.h"
#import "MBViewControllerFactory.h"
#import "MBMicroblinkSDK.h"
#import "MBException.h"
#import "MBImage.h"

// Settings
#import "MBCameraSettings.h"

// Delegates
#import "MBRecognizerRunnerViewControllerMetadataDelegates.h"
#import "MBRecognizerRunnerViewControllerDelegate.h"
#import "MBScanningRecognizerRunnerViewControllerDelegate.h"

// Overlay delegates
#import "MBBarcodeOverlayViewControllerDelegate.h"
#import "MBDocumentOverlayViewControllerDelegate.h"
#import "MBDocumentVerificationOverlayViewControllerDelegate.h"

#import "MBRecognizerRunner.h"
#import "MBRecognizerRunnerMetadataDelegates.h"
#import "MBScanningRecognizerRunnerDelegate.h"

// Frame Grabbers
#import "MBFrameGrabberRecognizer.h"
#import "MBSuccessFrameGrabberRecognizer.h"
#import "MBSuccessFrameGrabberRecognizerResult.h"

/*  UI  */
// Overlays
#import "MBBarcodeOverlayViewController.h"
#import "MBBarcodeOverlaySettings.h"

#import "MBFieldByFieldOverlayViewController.h"

#import "MBCustomOverlayViewController.h"

#import "MBBaseOcrOverlaySettings.h"
#import "MBDocumentOverlaySettings.h"

// Overlay subviews
#import "MBDotsSubview.h"
#import "MBDotsResultSubview.h"
#import "MBModernViewfinderSubview.h"
#import "MBTapToFocusSubview.h"
#import "MBOcrResultSubview.h"
#import "MBResultSubview.h"
#import "MBOcrLayoutSubview.h"
#import "MBDocumentSubview.h"
#import "MBDocumentVerificationSubview.h"
#import "MBDocumentVerificationInstructionsSubview.h"

#import "MBEntities.h"
#import "MBUIComponents.h"
#import "MBMetadata.h"
