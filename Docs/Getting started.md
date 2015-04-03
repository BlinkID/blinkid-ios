# Getting started

This Quick Start guide will get you up and performing scanning as quickly as possible. The same steps are performed for all scanning use cases in MicroBlink's scanning products: BlinkOCR, BlinkID, BlinkBarcode and PhotoPay. Steps described in this guide are required for the integration.

Before you get started, we highly recommend you try to run our sample apps given in the SDK package. The sample apps should compile and run on your device, or in the iOS Simulator. On device, you should be able to perform basic scanning functionality. The source code can be used as the reference during the integration.

### 1. Initial integration steps

- In your Xcode project, open the Project navigator. Drag the MicroBlink.embeddedframework to your project, ideally in the Frameworks group, together with other frameworks you're using. The MicroBlink framework consists of library, headers, and resources - everything it needs to function properly.

- Include the additional frameworks and libraries into your project:
	
	- AVFoundation
	- AudioToolbox
	- CoreMedia
	- libc++.dylib
	- libiconv.dylib
	
### 2. Referencing header file
	
In files in which you want to use scanning functionality (or in on your \<project\>-Prefix.pch file), place import directive.

```objective-c

#import <MicroBlink/MicroBlink.h>
```
	
### 3. Initializing the scanning library
	
To initialize the scanning library, first decide where in your app you want to add scanning functionality. Usually, users of the scanning library have a button which, when tapped, starts the scanning process. Initialization code is then placed in touch handler for that button. Here we're listing the initialization code as it looks in a touch handler method.

```objective-c
- (IBAction)didTapScan:(id)sender {

	/** 0. Check if scanning is supported */
	
	NSError *error;
	if ([PPCoordinator isScanningUnsupported:&error]) {
		NSString *messageString = [error localizedDescription];
		[[[UIAlertView alloc] initWithTitle:@"Warning" message:messageString delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil] show];
		return;
	}


	/** 1. Initialize the Scanning settings */
	
	// Initialize the scanner settings object. This initialize settings with all default values.
	PPSettings *settings = [[PPSettings alloc] init];


	/** 2. Setup the license key */
	
	// To obtain the license key, contact us at help.microblink.com with the bundle-id of your app
	settings.licenseSettings.licenseKey = @"NHF2-TG3T-OS5T-FVRY-CN6R-OTIA-FMRP-TOZL";


	/** 3. Set up what is being scanned. See detailed guides for specific use cases. Here's an example for initializing raw OCR scanning. */
	
	// To specify we want to perform OCR recognition, initialize the OCR recognizer settings
	PPOcrRecognizerSettings *ocrRecognizerSettings = [[PPOcrRecognizerSettings alloc] init];

	// We want raw OCR parsing
	[ocrRecognizerSettings addOcrParser:[[PPRawOcrParserFactory alloc] init] name:self.rawOcrParserId];

	// We want to parse prices from raw OCR result as well
	[ocrRecognizerSettings addOcrParser:[[PPPriceOcrParserFactory alloc] init] name:self.priceParserId];

	// Add the recognizer setting to a list of used recognizer
	[settings.scanSettings addRecognizerSettings:ocrRecognizerSettings];
	
	
	/** 4. Initialize the Scanning Coordinator object */

	PPCoordinator *coordinator = [[PPCoordinator alloc] initWithSettings:settings];


	/** 5. Initialize the scanning view controller with the delegate object */
	UIViewController<PPScanningViewController>* scanningViewController = [coordinator cameraViewControllerWithDelegate:self];


	/** 6 Present it full screen. The way VC is presented defines the way it's being dismissed in scanningViewControllerDidClose: */
	
	// You can use other presentation methods as well
	[self presentViewController:scanningViewController animated:YES completion:nil];
}
```
	
### 4. Registering for scanning events
	
In the previous step, you had to create `PPScanningViewController` with a delegate object. This object gets notified on certain events in scanning lifecycle. In this example we set it to `self`. The protocol which the delegate has to implement is `PPScanDelegate` protocol. You can use the following default implementation of the protocol to get you started.
	
```objective-c	
- (void)scanningViewControllerUnauthorizedCamera:(UIViewController<PPScanningViewController> *)scanningViewController {
	// Add any logic which handles UI when app user doesn't allow usage of the phone's camera
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController
				  didFindError:(NSError *)error {
	// Can be ignored. See description of the method
}

- (void)scanningViewControllerDidClose:(UIViewController<PPScanningViewController> *)scanningViewController {

	// As scanning view controller is presented full screen and modally, dismiss it
	[self dismissViewControllerAnimated:YES completion:nil];
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController
			  didOutputResults:(NSArray *)results {
	
	// Here you process scanning results. Scanning results are given in the array of PPBaseResult objects.

	for (PPBaseResult* result in results) {
		// Perform your logic here
	};
}
```
	
### 5. Additional remarks 
	
With this performed, you've successfully integrated the scanning functionality in your app. 

For next steps, you will want to:
- initialize the scanner to scan the exact data you need (barcodes, ID cards, payment slips, etc.)
- collect scanning results. 

For this, see the following guide: 02 - Obtaining scanning results.

If you need additional help, contact us directly at help.microblink.com.