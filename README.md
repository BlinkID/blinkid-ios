<p align="center" >
  <img src="https://raw.githubusercontent.com/wiki/blinkid/blinkid-ios/Images/logo-microblink.png" alt="MicroBlink" title="MicroBlink">
</p>

[![Build Status](https://travis-ci.org/BlinkID/blinkid-ios.png)](https://travis-ci.org/BlinkID/blinkid-ios.png)
[![Pod Version](http://img.shields.io/cocoapods/v/PPBlinkID.svg?style=flat)](http://cocoadocs.org/docsets/PPBlinkID/)

# BlinkID SDK for ID scanning

BlinkID SDK is a delightful component for quick and easy scanning of ID cards, passports and drivers licenses. The SDK is powered with [MicroBlink's](http://www.microblink.com) industry-proven and world leading OCR and barcode scanning technology, and offers:

- integrated camera management
- layered API, allowing everything from simple integration to complex UX customizations.
- lightweight and no internet connection required
- enteprise-level security standards
- data parsing from ID barcode standards

BlinkID is a part of family of SDKs developed by [MicroBlink](http://www.microblink.com) for optical text recognition, barcode scanning, ID document scanning and many others. 

<p align="center" >
  <a href="https://www.youtube.com/watch?v=3sEyQLaxLKA" target="_blank">
    <img src="https://raw.githubusercontent.com/wiki/blinkid/blinkid-ios/Images/blinkid.gif" alt="BlinkID SDK">
  </a>
</p>

# Table of contents

- [Requirements](#requirements)
- [Quick Start](#quick-start)
- [Advanced BlinkID integration instructions](#advanced-integration)
	- [Built-in overlay view controllers and overlay subviews](#ui-customizations)
		- [Using `MBBarcodeOverlayViewController`](#using-pdf417-overlay-viewcontroller)
		- [Using `MBFieldByFieldOverlayViewController`](#using-fieldbyfield-overlay-viewcontroller)
		- [Using `MBBlinkCardOverlayViewController`](#using-blinkcard-overlay-viewcontroller)
		- [Using `MBDocumentOverlayViewController`](#using-blinkinput-overlay-viewcontroller)
		- [Using `MBDocumentVerificationOverlayViewController`](#using-blinkid-overlay-viewcontroller)
		- [Custom overlay view controller](#using-custom-overlay-viewcontroller)
	- [Direct processing API](#direct-api-processing)
		- [Using Direct API for `NSString` recognition (parsing)](#direct-api-string-processing)
- [`MBRecognizer` and available recognizers](#recognizer)
- [List of available recognizers](#available-recognizers)
	- [Frame Grabber Recognizer](#frame-grabber-recognizer)
	- [Success Frame Grabber Recognizer](#success-frame-grabber-recognizer)
	- [PDF417 recognizer](#pdf417-recognizer)
	- [Barcode recognizer](#barcode-recognizer)
	- [BlinkInput recognizer](#blinkinput-recognizer)
	- [Detector recognizer](#detector-recognizer)
	- [BlinkCard recognizers ](#blinkcard-recognizers)
		- [Payment / Debit card combined recognizer](#payment-card-recognizers)
		- [Elite Payment / Debit card combined recognizer](#elite-payment-card-recognizers)
	- [BlinkID recognizers](#blinkid-recognizers)
		- [Machine Readable Travel Document recognizer](#mrtd-recognizer)
		- [Document face recognizer](#document-face-recognizers)
		- [Austria](#austria)
		- [Australia](#australia)
		- [Brunei](#brunei)
		- [Colombia](#colombia)
		- [Croatia](#croatia)
		- [Cyprus](#cyprus)
		- [Czechia](#czechia)
		- [European Driver License](#eudl)
		- [Egypt](#egypt)
		- [Germany](#germany)
		- [Hong Kong](#hong-kong)
		- [Indonesia](#indonesia)
		- [Ireland](#ireland)
		- [Italy](#italy)
		- [Jordan](#jordan)
		- [Kuwait](#kuwait)
		- [Malaysia](#malaysia)
		- [Mexico](#mexico)
		- [Morocco](#morocco)
		- [New Zealand](#new-zealand)
		- [Passport](#passport)
		- [Poland](#poland)
		- [Romania](#romania)
		- [Serbia](#serbia)
		- [Singapore](#singapore)
		- [Slovakia](#slovakia)
		- [Slovenia](#slovenia)
		- [Spain](#spain)
		- [Sweden](#sweden)
		- [Switzerland](#switzerland)
		- [United Arab Emirates](#uae)
		- [United States](#us)
- [`MBProcessor` and `MBParser`](#processors-and-parsers)
	- [The `MBProcessor` concept](#processor-concept)
		- [Image Return Processor](#image-processors)
		- [Parser Group Processor](#parser-group-processor)
	- [The `MBParser` concept](#parser-concept)
		- [Amount Parser](#amount-parser)
		- [Date Parser](#date-parser)
		- [Email Parser](#email-parser)
		- [IBAN Parser](#iban-parser)
		- [License Plates Parser](#license-plate-parser)
		- [Raw Parser](#raw-parser)
		- [Regex Parser](#regex-parser)
		- [TopUp Parser](#topup-parser)
		- [VIN (*Vehicle Identification Number*) Parser](#vin-parser)
- [Scanning generic documents with Templating API](#templating-api)
	- [Defining how document should be detected](#defining-document-detection)
	- [Defining how fields of interest should be extracted](#defining-field-extraction)
		- [The `MBProcessorGroup` component](#processor-group)
		- [List of available dewarp policies](#dewarp-policy-list)
		- [The `MBTemplatingClass` component](#templating-class)
		- [Implementing the `MBTemplatingClassifier`](#implementing-templating-classifier)
- [The `MBDetector` concept](#detector-concept)
	- [List of available detectors](#detector-list)
		- [Document Detector](#document-detector)
		- [MRTD Detector](#mrtd-detector)
- [Troubleshooting](#troubleshooting)
	- [Integration problems](#troubleshooting-integration-problems)
	- [SDK problems](#troubleshooting-sdk-problems)
		- [Licencing problems](#troubleshooting-licensing-problems)
		- [Other problems](#troubleshooting-other-problems)
	- [Frequently asked questions and known problems](#troubleshooting-faq)
- [Additional info](#info)


# <a name="requirements"></a> Requirements

SDK package contains Microblink framework and one or more sample apps which demonstrate framework integration. The framework can be deployed in iOS 8.0 or later, iPhone 4S or newer and iPad 2 or newer.

SDK performs significantly better when the images obtained from the camera are focused. Because of that, the SDK can have lower performance on iPad 2 and iPod Touch 4th gen devices, which [don't have camera with autofocus](http://www.adweek.com/socialtimes/ipad-2-rear-camera-has-tap-for-auto-exposure-not-auto-focus/12536). 
 
# <a name="quick-start"></a> Quick Start

## Getting started with BlinkID SDK

This Quick Start guide will get you up and performing OCR scanning as quickly as possible. All steps described in this guide are required for the integration.

This guide sets up basic Raw OCR parsing and price parsing at the same time. It closely follows the BlinkOCR-sample app. We highly recommend you try to run the sample app. The sample app should compile and run on your device, and in the iOS Simulator. 

The source code of the sample app can be used as the reference during the integration.

### 1. Initial integration steps

#### Using CocoaPods

- If you wish to use version v1.2.0 or above, you need to install [Git Large File Storage](https://git-lfs.github.com) by running these comamnds:
```shell
brew install git-lfs
git lfs install
```

- **Be sure to restart your console after installing Git LFS**
- **Note:** if you already did try adding SDK using cocoapods and it's not working, first install the git-lfs and then clear you cocoapods cache. This should be sufficient to force cocoapods to clone BlinkID SDK, if it still doesn't work, try deinitializing your pods and installing them again.
- Project dependencies to be managed by CocoaPods are specified in a file called `Podfile`. Create this file in the same directory as your Xcode project (`.xcodeproj`) file.

- If you don't have podfile initialized run the following in your project directory.
```
pod init
```

- Copy and paste the following lines into the TextEdit window:  

```ruby
platform :ios, '9.0'
target 'Your-App-Name' do
    pod 'PPBlinkID', '~> 4.9.0'
end
```

- Install the dependencies in your project:

```shell 
$ pod install
``` 

- From now on, be sure to always open the generated Xcode workspace (`.xcworkspace`) instead of the project file when building your project:

```shell 
open <YourProjectName>.xcworkspace
```
   
#### Integration without CocoaPods


-[Download](https://github.com/BlinkID/blinkid-ios/releases) latest release (Download .zip or .tar.gz file starting with BlinkID. DO NOT download Source Code as GitHub does not fully support Git LFS)

OR

Clone this git repository:

- If you wish to clone version v1.4.0 or above, you need to install [Git Large File Storage](https://git-lfs.github.com) by running these comamnds:
```shell
brew install git-lfs
git lfs install
```

- **Be sure to restart your console after installing Git LFS**

- To clone, run the following shell command:

```shell
git clone git@github.com:BlinkID/blinkid-ios.git
```

- Copy Microblink.framework and Microblink.bundle to your project folder.

- In your Xcode project, open the Project navigator. Drag the Microblink.framework and Microblink.bundle files to your project, ideally in the Frameworks group, together with other frameworks you're using. When asked, choose "Create groups", instead of the "Create folder references" option.

![Adding Microblink.embedded framework to your project](https://raw.githubusercontent.com/wiki/blinkocr/blinkocr-ios/Images/01%20-%20Add%20Framework.jpg)

- Since Microblink.framework is a dynamic framework, you also need to add it to embedded binaries section in General settings of your target.

![Adding Microblink.framework to embedded binaries](https://raw.githubusercontent.com/wiki/blinkocr/blinkocr-ios/Images/03%20-%20Embed%20Binaries.png)

- Include the additional frameworks and libraries into your project in the "Linked frameworks and libraries" section of your target settings. 

    - AudioToolbox.framework
    - AVFoundation.framework
    - CoreMedia.framework
    - libc++.tbd
    - libiconv.tbd
    - libz.tbd
    
![Adding Apple frameworks to your project](https://raw.githubusercontent.com/wiki/blinkocr/blinkocr-ios/Images/02%20-%20Add%20Libraries.jpg)
    
### 2. Referencing header file
    
In files in which you want to use scanning functionality place import directive.

Swift

```swift
import MicroBlink
```

Objective-C

```objective-c
#import <MicroBlink/MicroBlink.h>
```
    
### 3. Initiating the scanning process
    
To initiate the scanning process, first decide where in your app you want to add scanning functionality. Usually, users of the scanning library have a button which, when tapped, starts the scanning process. Initialization code is then placed in touch handler for that button. Here we're listing the initialization code as it looks in a touch handler method.

Also, for initialization purposes, the ViewController which initiates the scan have private properties for [`MBRawParser`](http://blinkid.github.io/blinkid-ios/Classes/MBRawParser.html), [`MBParserGroupProcessor`](http://blinkid.github.io/blinkid-ios//Classes/MBParserGroupProcessor.html) and [`MBBlinkInputRecognizer`](http://blinkid.github.io/blinkid-ios//Classes/MBBlinkInputRecognizer.html), so we know how to obtain result.

Swift

```swift
class ViewController: UIViewController, MBDocumentOverlayViewControllerDelegate  {
    
    var rawParser: MBRawParser?
    var parserGroupProcessor: MBParserGroupProcessor?
    var blinkInputRecognizer: MBBlinkInputRecognizer?

    override func viewDidLoad() {
        super.viewDidLoad()
    }

    @IBAction func didTapScan(_ sender: AnyObject) {
        
        let settings = MBDocumentOverlaySettings()
        rawParser = MBRawParser()
        parserGroupProcessor = MBParserGroupProcessor(parsers: [rawParser!])
        blinkInputRecognizer = MBBlinkInputRecognizer(processors: [parserGroupProcessor!])
        
        let recognizerList = [self.blinkInputRecognizer!]
        let recognizerCollection = MBRecognizerCollection(recognizers: recognizerList)
        
        /** Create your overlay view controller */
        let documentOverlayViewController = MBDocumentOverlayViewController(settings: settings, recognizerCollection: recognizerCollection, delegate: self)
        
        /** Create recognizer view controller with wanted overlay view controller */
        let recognizerRunnerViewController: UIViewController = MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: documentOverlayViewController)
        
        /** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
        present(recognizerRunnerViewController!, animated: true, completion: nil)
    }
}
```

Objective-C

```objective-c
@interface ViewController () <MBDocumentOverlayViewControllerDelegate>

@property (nonatomic, strong) MBRawParser *rawParser;
@property (nonatomic, strong) MBParserGroupProcessor *parserGroupProcessor;
@property (nonatomic, strong) MBBlinkInputRecognizer *blinkInputRecognizer;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}


- (IBAction)didTapScan:(id)sender {
    
    MBDocumentOverlaySettings* settings = [[MBDocumentOverlaySettings alloc] init];

    self.rawParser = [[MBRawParser alloc] init];
    self.parserGroupProcessor = [[MBParserGroupProcessor alloc] initWithParsers:@[self.rawParser]];
    self.blinkInputRecognizer = [[MBBlinkInputRecognizer alloc] initWithProcessors:@[self.parserGroupProcessor]];

    /** Create recognizer collection */
    MBRecognizerCollection *recognizerCollection = [[MBRecognizerCollection alloc] initWithRecognizers:@[self.blinkInputRecognizer]];
    
    MBDocumentOverlayViewController *overlayVC = [[MBDocumentOverlayViewController alloc] initWithSettings:settings recognizerCollection:recognizerCollection delegate:self];
    UIViewController<MBRecognizerRunnerViewController>* recognizerRunnerViewController = [MBViewControllerFactory recognizerRunnerViewControllerWithOverlayViewController:overlayVC];
    
    /** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
    [self presentViewController:recognizerRunnerViewController animated:YES completion:nil];

}

@end
```
    
### 4. License key

A valid license key is required to initalize scanning. You can generate a free demo license key, after you register, at [Microblink developer dashboard](https://microblink.com/login).

You can include the license key in your app by passing a string or a file with license key. 
**Note** that you need to set the license key before intializing scanning. Ideally in `AppDelegate` or `viewDidLoad` before initializing any recognizers.

#### License key as string
You can pass the license key as a string, the following way:

Swift

```swift
MBMicroblinkSDK.sharedInstance().setLicenseKey("LICENSE-KEY")
```

Objective-C

```objective-c
[[MBMicroblinkSDK sharedInstance] setLicenseKey:@"LICENSE-KEY"];
```

#### License key as file
Or you can include the license key, with the code below. Please make sure that the file that contains the license key is included in your project and is copied during **Copy Bundle Resources** build phase.

Swift

```swift
MBMicroblinkSDK.sharedInstance().setLicenseResource("license-key-file", withExtension: "txt", inSubdirectory: "directory-to-license-key", for: Bundle.main)
```

Objective-C

```objective-c
[[MBMicroblinkSDK sharedInstance] setLicenseResource:@"license-key-file" withExtension:@"txt" inSubdirectory:@"" forBundle:[NSBundle mainBundle]];
```

### 5. Registering for scanning events
    
In the previous step, you instantiated [`MBDocumentOverlayViewController`](http://blinkid.github.io/blinkid-ios//Classes/MBDocumentOverlayViewController.html) object with a delegate object. This object gets notified on certain events in scanning lifecycle. In this example we set it to `self`. The protocol which the delegate has to implement is [`MBDocumentOverlayViewControllerDelegate`](http://blinkid.github.io/blinkid-ios//Protocols/MBDocumentOverlayViewControllerDelegate.html) protocol. It is necessary to conform to that protocol. We will discuss more about protocols in [Advanced integration section](#advanced-integration). You can use the following default implementation of the protocol to get you started.

Swift

```swift
func documentOverlayViewControllerDidFinishScanning(_ documentOverlayViewController: MBDocumentOverlayViewController, state: MBRecognizerResultState) {

    // this is done on background thread
    // check for valid state
    if state == .valid {

        // first, pause scanning until we process all the results
        documentOverlayViewController.recognizerRunnerViewController?.pauseScanning()

        DispatchQueue.main.async(execute: {() -> Void in
            // All UI interaction needs to be done on main thread
        })
    }
}

func documentOverlayViewControllerDidTapClose(_ documentOverlayViewController: MBDocumentOverlayViewController) {
    // Your action on cancel 
}
```
    
Objective-C

```objective-c  
- (void)documentOverlayViewControllerDidFinishScanning:(MBDocumentOverlayViewController *)documentOverlayViewController state:(MBRecognizerResultState)state {
    
    // this is done on background thread
    // check for valid state
    if (state == MBRecognizerResultStateValid) {
        
        // first, pause scanning until we process all the results
        [documentOverlayViewController.recognizerRunnerViewController pauseScanning];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            // All UI interaction needs to be done on main thread
        });
    }
}

- (void)documentOverlayViewControllerDidTapClose:(MBDocumentOverlayViewController *)documentOverlayViewController {
    // Your action on cancel 
}
```

# <a name="advanced-integration"></a> Advanced BlinkID integration instructions
This section covers more advanced details of BlinkInput integration.

1. [First part](#ui-customizations) will cover the possible customizations when using UI provided by the SDK.
2. [Second part](#custom-overyal-view-controller) will describe how to embed [`MBRecognizerRunnerViewController's delegates`](http://blinkid.github.io/blinkid-ios/Protocols.html) into your `UIViewController` with the goal of creating a custom UI for scanning, while still using camera management capabilites of the SDK.
3. [Third part](#direct-processing-api) will describe how to use the [`MBRecognizerRunner`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerRunner.html) (Direct API) for recognition directly from `UIImage` without the need of camera or to recognize camera frames that are obtained by custom camera management.
4. [Fourth part](#recognizer) will describe recognizer concept and available recognizers.


## <a name="ui-customizations"></a> Built-in overlay view controllers and overlay subviews

Within BlinkID SDK there are several built-in overlay view controllers and scanning subview overlays that you can use to perform scanning. 
### <a name="using-pdf417-overlay-viewcontroller"></a> Using `MBBarcodeOverlayViewController`

[`MBBarcodeOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBBarcodeOverlayViewController.html) is overlay view controller best suited for performing scanning of various barcodes. It has [`MBBarcodeOverlayViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBBarcodeOverlayViewControllerDelegate.html) delegate which can be used out-of-the-box to perform scanning using the default UI. Here is an example how to use and initialize [`MBBarcodeOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBBarcodeOverlayViewController.html):

Swift
```swift
/** Create your overlay view controller */
let barcodeOverlayViewController : MBBarcodeOverlayViewController = MBBarcodeOverlayViewController(settings: barcodeSettings, recognizerCollection: recognizerCollection, delegate: self)

/** Create recognizer view controller with wanted overlay view controller */
let recognizerRunneViewController : UIViewController = MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: barcodeOverlayViewController)

/** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
self.present(recognizerRunneViewController, animated: true, completion: nil)
```

Objective-C
```objective-c
MBBarcodeOverlayViewController *overlayVC = [[MBBarcodeOverlayViewController alloc] initWithSettings:settings recognizerCollection: recognizerCollection delegate:self];
UIViewController<MBRecognizerRunnerViewController>* recognizerRunnerViewController = [MBViewControllerFactory recognizerRunnerViewControllerWithOverlayViewController:overlayVC];

/** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
[self presentViewController:recognizerRunnerViewController animated:YES completion:nil];
```

As you can see, when initializing [`MBBarcodeOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBBarcodeOverlayViewController.html), we are sending delegate property as `self`. To get results, we need to conform to [`MBBarcodeOverlayViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBBarcodeOverlayViewControllerDelegate.html) protocol.
### <a name="using-fieldbyfield-overlay-viewcontroller"></a> Using `MBFieldByFieldOverlayViewController`

[`MBFieldByFieldOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBFieldByFieldOverlayViewController.html) is overlay view controller best suited for performing scanning of various payment slips and barcodes with field of view. It has [`MBFieldByFieldOverlayViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBFieldByFieldOverlayViewControllerDelegate.html) delegate which can be used out-of-the-box to perform scanning using the default UI. Here is an example how to use and initialize [`MBFieldByFieldOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBFieldByFieldOverlayViewController.html):

Swift
```swift
/** Create your overlay view controller */
let fieldByFieldOverlayViewController : MBFieldByFieldOverlayViewController = MBFieldByFieldOverlayViewController(settings: fieldByFieldOverlaySettings, recognizerCollection: recognizerCollection, delegate: self)

/** Create recognizer view controller with wanted overlay view controller */
let recognizerRunneViewController : UIViewController = MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: fieldByFieldOverlayViewController)

/** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
self.present(recognizerRunneViewController, animated: true, completion: nil)
```

Objective-C
```objective-c
MBFieldByFieldOverlayViewController *overlayVC = [[MBFieldByFieldOverlayViewController alloc] initWithSettings:settings recognizerCollection: recognizerCollection delegate:self];
UIViewController<MBRecognizerRunnerViewController>* recognizerRunnerViewController = [MBViewControllerFactory recognizerRunnerViewControllerWithOverlayViewController:overlayVC];

/** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
[self presentViewController:recognizerRunnerViewController animated:YES completion:nil];
```

As you can see, when initializing [`MBFieldByFieldOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBFieldByFieldOverlayViewController.html), we are sending delegate property as `self`. To get results, we need to conform to [`MBFieldByFieldOverlayViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBFieldByFieldOverlayViewControllerDelegate.html) protocol.
### <a name="using-blinkcard-overlay-viewcontroller"></a> Using `MBBlinkCardOverlayViewController`

[`MBBlinkCardOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkCardOverlayViewController.html) is overlay view controller best suited for performing scanning of payment cards for both front and back side. It has [`MBBlinkCardOverlayViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBBlinkCardOverlayViewControllerDelegate.html) delegate which can be used out-of-the-box to perform scanning using the default UI. Here is an example how to use and initialize [`MBBlinkCardOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkCardOverlayViewController.html):

Swift

```swift
/** Create your overlay view controller */
let blinkCardViewController : MBBlinkCardOverlayViewController = MBBlinkCardOverlayViewController(settings: blinkCardSettings, recognizerCollection: recognizerCollection, delegate: self)

/** Create recognizer view controller with wanted overlay view controller */
let recognizerRunneViewController : UIViewController = MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: blinkCardViewController)

/** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
self.present(recognizerRunneViewController, animated: true, completion: nil)
```

Objective-C

```objective-c
MBDocumentVerificationOverlayViewController *overlayVC = [[MBBlinkCardOverlayViewController alloc] initWithSettings:settings recognizerCollection: recognizerCollection delegate:self];
UIViewController<MBRecognizerRunnerViewController>* recognizerRunnerViewController = [MBViewControllerFactory recognizerRunnerViewControllerWithOverlayViewController:overlayVC];

/** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
[self presentViewController:recognizerRunnerViewController animated:YES completion:nil];
```

As you can see, when initializing [`MBDocumentVerificationOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentVerificationOverlayViewController.html), we are sending delegate property as `self`. To get results, we need to conform to [`MBDocumentVerificationOverlayViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBDocumentVerificationOverlayViewControllerDelegate.html) protocol.
### <a name="using-blinkinput-overlay-viewcontroller"></a> Using `MBDocumentOverlayViewController`

[`MBDocumentOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentOverlayViewController.html) is overlay view controller best suited for performing scanning of various document cards. It has [`MBDocumentOverlayViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBDocumentOverlayViewControllerDelegate.html) delegate which can be used out-of-the-box to perform scanning using the default UI. Here is an example how to use and initialize [`MBDocumentOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentOverlayViewController.html):

Swift
```swift
/** Create your overlay view controller */
let documentOverlayViewController : MBDocumentOverlayViewController = MBDocumentOverlayViewController(settings: documentSettings, recognizerCollection: recognizerCollection, delegate: self)

/** Create recognizer view controller with wanted overlay view controller */
let recognizerRunneViewController : UIViewController = MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: documentOverlayViewController)

/** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
self.present(recognizerRunneViewController, animated: true, completion: nil)
```

Objective-C
```objective-c
MBDocumentOverlayViewController *overlayVC = [[MBDocumentOverlayViewController alloc] initWithSettings:settings recognizerCollection: recognizerCollection delegate:self];
UIViewController<MBRecognizerRunnerViewController>* recognizerRunnerViewController = [MBViewControllerFactory recognizerRunnerViewControllerWithOverlayViewController:overlayVC];

/** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
[self presentViewController:recognizerRunnerViewController animated:YES completion:nil];
```

As you can see, when initializing [`MBDocumentOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentOverlayViewController.html), we are sending delegate property as `self`. To get results, we need to conform to [`MBDocumentOverlayViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBDocumentOverlayViewControllerDelegate.html) protocol.

### <a name="using-blinkid-overlay-viewcontroller"></a> Using `MBDocumentVerificationOverlayViewController`

[`MBDocumentVerificationOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentVerificationOverlayViewController.html) is overlay view controller best suited for performing scanning of various document for both front and back side. It has [`MBDocumentVerificationOverlayViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBDocumentVerificationOverlayViewControllerDelegate.html) delegate which can be used out-of-the-box to perform scanning using the default UI. Here is an example how to use and initialize [`MBDocumentVerificationOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentVerificationOverlayViewController.html):

Swift
```swift
/** Create your overlay view controller */
let documentOverlayViewController : MBDocumentVerificationOverlayViewController = MBDocumentVerificationOverlayViewController(settings: documentVerificationSettings, recognizerCollection: recognizerCollection, delegate: self)

/** Create recognizer view controller with wanted overlay view controller */
let recognizerRunneViewController : UIViewController = MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: documentOverlayViewController)

/** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
self.present(recognizerRunneViewController, animated: true, completion: nil)
```

Objective-C
```objective-c
MBDocumentVerificationOverlayViewController *overlayVC = [[MBDocumentVerificationOverlayViewController alloc] initWithSettings:settings recognizerCollection: recognizerCollection delegate:self];
UIViewController<MBRecognizerRunnerViewController>* recognizerRunnerViewController = [MBViewControllerFactory recognizerRunnerViewControllerWithOverlayViewController:overlayVC];

/** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
[self presentViewController:recognizerRunnerViewController animated:YES completion:nil];
```

As you can see, when initializing [`MBDocumentVerificationOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentVerificationOverlayViewController.html), we are sending delegate property as `self`. To get results, we need to conform to [`MBDocumentVerificationOverlayViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBDocumentVerificationOverlayViewControllerDelegate.html) protocol.
### <a name="using-custom-overlay-viewcontroller"></a> Custom overlay view controller

Please check our pdf417-sample-Swift for custom implementation of overlay view controller.

Overlay View Controller is an abstract class for all overlay views.

It's responsibility is to provide meaningful and useful interface for the user to interact with.
 
Typical actions which need to be allowed to the user are:

- intuitive and meaniningful way to guide the user through scanning process. This is usually done by presenting a "viewfinder" in which the user need to place the scanned object
- a way to cancel the scanning, typically with a "cancel" or "back" button
- a way to power on and off the light (i.e. "torch") button
 
BlinkID SDK always provides it's own default implementation of the Overlay View Controller for every specific use. Your implementation should closely mimic the default implementation as it's the result of thorough testing with end users. Also, it closely matches the underlying scanning technology. 

For example, the scanning technology usually gives results very fast after the user places the device's camera in the expected way above the scanned object. This means a progress bar for the scan is not particularly useful to the user. The majority of time the user spends on positioning the device's camera correctly. That's just an example which demonstrates careful decision making behind default camera overlay view.

### 1. Initialization
 
To use your custom overlay with Microblink's camera view, you must first subclass [`MBCustomOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBCustomOverlayViewController.html) and implement the overlay behaviour conforming wanted protocols.

### 2. Protocols

There are five [`MBRecognizerRunnerViewController`](http://blinkid.github.io/blinkid-ios/Protocols/MBRecognizerRunnerViewController.html) protocols and one overlay protocol [`MBOverlayViewControllerInterface`](http://blinkid.github.io/blinkid-ios/Protocols/MBOverlayViewControllerInterface.html).

Five `RecognizerRunnerView` protocols are:
- [`MBScanningRecognizerRunnerViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBScanningRecognizerRunnerViewControllerDelegate.html)
- [`MBDetectionRecognizerRunnerViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBDetectionRecognizerRunnerViewControllerDelegate.html)
- [`MBOcrRecognizerRunnerViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBOcrRecognizerRunnerViewControllerDelegate.html)
- [`MBDebugRecognizerRunnerViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBDebugRecognizerRunnerViewControllerDelegate.html)
- [`MBRecognizerRunnerViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBRecognizerRunnerViewControllerDelegate.html)

In `viewDidLoad`, other protocol conformation can be done and it's done on `recognizerRunnerViewController` property of [`MBOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBOverlayViewController.html), for example:

Swift and Objective-C
```swift
self.scanningRecognizerRunnerViewControllerDelegate = self;
```

### 3. Overlay subviews
The SDK contains various subviews you can use to notify users of the state of scanning. If you want to use built-in implementation we recommend to use [`MBModernViewfinderSubview`](http://blinkid.github.io/blinkid-ios/Classes/MBModernViewfinderSubview.html). In can be initialized in `viewDidLoad` method:

Swift
```swift
viewfinderSubview = MBModernViewfinderSubview()
viewfinderSubview.frame = view.frame
viewfinderSubview.moveable = true
view.addSubview(viewfinderSubview)
```

Objective-C
```objective-c
self.viewfinderSubview = [[MBModernViewfinderSubview alloc] init];
self.viewfinderSubview.frame = self.view.frame;
self.viewfinderSubview.delegate = self.overlaySubviewsDelegate;
self.viewfinderSubview.moveable = YES;
[self.view addSubview:self.viewfinderSubview];
```

To use this subview you'll need to implement `MBDetectionRecognizerRunnerViewControllerDelegate`(http://blinkid.github.io/blinkid-ios/Protocols/MBDetectionRecognizerRunnerViewControllerDelegate.html) then in the `-recognizerRunnerViewController:didFinishDetectionWithDisplayableQuad:` notify subview of detection changes.

Swift
```swift
func recognizerRunnerViewController(_ recognizerRunnerViewController: Any!, didFinishDetectionWithDisplayableQuad displayableQuad: MBDisplayableQuadDetection) {
    viewfinderSubview.detectionFinished(withDisplayableQuad: displayableQuad)
}
```
Objective-C
```objective-c
- (void)recognizerRunnerViewController: (nonnull UIViewController<MBRecognizerRunnerViewController> *) recognizerRunnerViewController didFinishDetectionWithDisplayableQuad: (nonnull MBDisplayableQuadDetection *)displayableQuad {
    [self.viewfinderSubview detectionFinishedWithDisplayableQuad:displayableQuad];
}
```

### 4. Initialization
In [Quick Start](#quick-start) guide it is shown how to use a default overlay view controller. You can now swap default view controller with your implementation of `CustomOverlayViewController`

Swift
```swift
let recognizerRunnerViewController : UIViewController = MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: CustomOverlayViewController)
```

Objective-C
```objective-c
UIViewController<MBRecognizerRunnerViewController>* recognizerRunnerViewController = [MBViewControllerFactory recognizerRunnerViewControllerWithOverlayViewController:CustomOverlayViewController];
```


## <a name="direct-api-processing"></a> Direct processing API

This guide will in short present you how to process UIImage objects with BlinkID SDK, without starting the camera video capture.

With this feature you can solve various use cases like:
	- recognizing text on images in Camera roll
	- taking full resolution photo and sending it to processing
	- scanning barcodes on images in e-mail etc.

DirectAPI-sample demo app here will present UIImagePickerController for taking full resolution photos, and then process it with Microblink SDK to get scanning results using Direct processing API.

Direct processing API is handled with [`MBRecognizerRunner`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerRunner.html). That is a class that handles processing of images. It also has protocols as [`MBRecognizerRunnerViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerRunnerViewController.html).
Developer can choose which protocol to conform:

- [`MBScanningRecognizerRunnerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBScanningRecognizerRunnerDelegate.html)
- [`MBDetectionRecognizerRunnerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBDetectionRecognizerRunnerDelegate.html)
- [`MBDebugRecognizerRunnerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBDebugRecognizerRunnerDelegate.html)
- [`MBOcrRecognizerRunnerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBOcrRecognizerRunnerDelegate.html)

In example, we are conforming to [`MBScanningRecognizerRunnerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBScanningRecognizerRunnerDelegate.html) protocol.

To initiate the scanning process, first decide where in your app you want to add scanning functionality. Usually, users of the scanning library have a button which, when tapped, starts the scanning process. Initialization code is then placed in touch handler for that button. Here we're listing the initialization code as it looks in a touch handler method.

Swift
```swift
func setupRecognizerRunner() {
    var recognizers = [MBRecognizer]()
    pdf417Recognizer = MBPdf417Recognizer()
    recognizers.append(pdf417Recognizer!)
    let recognizerCollection = MBRecognizerCollection(recognizers: recognizers)
    recognizerRunner = MBRecognizerRunner(recognizerCollection: recognizerCollection)
    recognizerRunner?.scanningRecognizerRunnerDelegate = self
}

func processImageRunner(_ originalImage: UIImage) {
    var image: MBImage? = nil
    if let anImage = originalImage {
        image = MBImage(uiImage: anImage)
    }
    image?.cameraFrame = true
    image?.orientation = MBProcessingOrientation.left
    let _serialQueue = DispatchQueue(label: "com.microblink.DirectAPI-sample-swift")
    _serialQueue.async(execute: {() -> Void in
        self.recognizerRunner?.processImage(image!)
    })
}

func recognizerRunner(_ recognizerRunner: MBRecognizerRunner, didFinishScanningWith state: MBRecognizerResultState) {
    if blinkInputRecognizer.result.resultState == MBRecognizerResultStateValid {
        // Handle result
    }
}
```

Objective-C
```objective-c
- (void)setupRecognizerRunner {
    NSMutableArray<MBRecognizer *> *recognizers = [[NSMutableArray alloc] init];
    
    self.blinkInputRecognizer = [[MBBlinkInputRecognizer alloc] init];
    
    [recognizers addObject:self.blinkInputRecognizer];
    
    MBRecognizerCollection *recognizerCollection = [[MBRecognizerCollection alloc] initWithRecognizers:recognizers];
    
    self.recognizerRunner = [[MBRecognizerRunner alloc] initWithRecognizerCollection:recognizerCollection];
    self.recognizerRunner.scanningRecognizerRunnerDelegate = self;
}

- (void)processImageRunner:(UIImage *)originalImage {
    MBImage *image = [MBImage imageWithUIImage:originalImage];
    image.cameraFrame = YES;
    image.orientation = MBProcessingOrientationLeft;
    dispatch_queue_t _serialQueue = dispatch_queue_create("com.microblink.DirectAPI-sample", DISPATCH_QUEUE_SERIAL);
    dispatch_async(_serialQueue, ^{
        [self.recognizerRunner processImage:image];
    });
}

#pragma mark - MBScanningRecognizerRunnerDelegate
- (void)recognizerRunner:(nonnull MBRecognizerRunner *)recognizerRunner didFinishScanningWithState:(MBRecognizerResultState)state {
    if (self.blinkInputRecognizer.result.resultState == MBRecognizerResultStateValid) {
        // Handle result
    }
}
```

Now you've seen how to implement the Direct processing API.

In essence, this API consists of two steps:

- Initialization of the scanner.
- Call of `- (void)processImage:(MBImage *)image;` method for each UIImage or CMSampleBufferRef you have.


### <a name="direct-api-string-processing"></a> Using Direct API for `NSString` recognition (parsing)

Some recognizers support recognition from `NSString`. They can be used through Direct API to parse given `NSString` and return data just like when they are used on an input image. When recognition is performed on `NSString`, there is no need for the OCR. Input `NSString` is used in the same way as the OCR output is used when image is being recognized. 
Recognition from `String` can be performed in the same way as recognition from image. 
The only difference is that user should call `- (void)processString:(NSString *)string;` on [`MBRecognizerRunner`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerRunner.html).

# <a name="recognizer"></a> `MBRecognizer` and available recognizers

## The `MBRecognizer` concept

The [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) is the basic unit of processing within the SDK. Its main purpose is to process the image and extract meaningful information from it. As you will see [later](#available-recognizers), the SDK has lots of different [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects that have various purposes.

Each [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) has a [`MBRecognizerResult`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerResult.html) object, which contains the data that was extracted from the image. The [`MBRecognizerResult`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerResult.html) object is a member of corresponding [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) object its lifetime is bound to the lifetime of its parent [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) object. If you need your `MBRecognizerRecognizer` object to outlive its parent [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) object, you must make a copy of it by calling its method `copy`.

While [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) object works, it changes its internal state and its result. The [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) object's [`MBRecognizerResult`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerResult.html) always starts in `Empty` state. When corresponding [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) object performs the recognition of given image, its [`MBRecognizerResult`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerResult.html) can either stay in `Empty` state (in case [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html)failed to perform recognition), move to `Uncertain` state (in case [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) performed the recognition, but not all mandatory information was extracted) or move to `Valid` state (in case [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) performed recognition and all mandatory information was successfully extracted from the image).

As soon as one [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) object's [`MBRecognizerResult`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerResult.html) within [`MBRecognizerCollection`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerCollection.html) given to `MBRecognizerRunner` or `MBRecognizerRunnerViewController` changes to `Valid` state, the `onScanningFinished` callback will be invoked on same thread that performs the background processing and you will have the opportunity to inspect each of your [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects' [`MBRecognizerResult`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerResult.html) to see which one has moved to `Valid` state.

As soon as `onScanningFinished` method ends, the `MBRecognizerRunnerViewController` will continue processing new camera frames with same [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects, unless `paused`. Continuation of processing or `reset` recognition will modify or reset all [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects's [`MBRecognizerResult`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerResult.html). When using built-in activities, as soon as `onScanningFinished` is invoked, built-in activity pauses the `MBRecognizerRunnerViewController` and starts finishing the activity, while saving the [`MBRecognizerCollection`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerCollection.html) with active [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html).

## `MBRecognizerCollection` concept

The [`MBRecognizerCollection`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerCollection.html) is is wrapper around [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects that has array of [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects that can be used to give [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects to `MBRecognizerRunner` or `MBRecognizerRunnerViewController` for processing.

The [`MBRecognizerCollection`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerCollection.html) is always constructed with array `[[MBRecognizerCollection alloc] initWithRecognizers:recognizers]` of [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects that need to be prepared for recognition (i.e. their properties must be tweaked already). 

The [`MBRecognizerCollection`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerCollection.html) manages a chain of [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects within the recognition process. When a new image arrives, it is processed by the first [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) in chain, then by the second and so on, iterating until a [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) object's [`MBRecognizerResult`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerResult.html) changes its state to `Valid` or all of the [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects in chain were invoked (none getting a `Valid` result state).

You cannot change the order of the [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects within the chain - no matter the order in which you give [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects to [`MBRecognizerCollection`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerCollection.html), they are internally ordered in a way that provides best possible performance and accuracy. Also, in order for SDK to be able to order [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects in recognition chain in a best way possible, it is not allowed to have multiple instances of [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects of the same type within the chain. Attempting to do so will crash your application.

# <a name="available-recognizers"></a> List of available recognizers

This section will give a list of all [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects that are available within BlinkID SDK, their purpose and recommendations how they should be used to get best performance and user experience.

## <a name="frame-grabber-recognizer"></a> Frame Grabber Recognizer

The [`MBFrameGrabberRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBFrameGrabberRecognizer.html) is the simplest recognizer in SDK, as it does not perform any processing on the given image, instead it just returns that image back to its `onFrameAvailable`. Its result never changes state from empty.

This recognizer is best for easy capturing of camera frames with `MBRecognizerRunnerViewController`. Note that [`MBImage`](http://blinkid.github.io/blinkid-ios/Classes/MBImage.html) sent to `onFrameAvailable` are temporary and their internal buffers all valid only until the `onFrameAvailable` method is executing - as soon as method ends, all internal buffers of [`MBImage`](http://blinkid.github.io/blinkid-ios/Classes/MBImage.html) object are disposed. If you need to store [`MBImage`](http://blinkid.github.io/blinkid-ios/Classes/MBImage.html) object for later use, you must create a copy of it by calling `copy`.

## <a name="success-frame-grabber-recognizer"></a> Success Frame Grabber Recognizer

The [`MBSuccessFrameGrabberRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSuccessFrameGrabberRecognizer.html) is a special `MBecognizer` that wraps some other [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) and impersonates it while processing the image. However, when the [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) being impersonated changes its [`MBRecognizerResult`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerResult.html) into `Valid` state, the [`MBSuccessFrameGrabberRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSuccessFrameGrabberRecognizer.html) captures the image and saves it into its own [`MBSuccessFrameGrabberRecognizerResult`](http://blinkid.github.io/blinkid-ios/Classes/MBSuccessFrameGrabberRecognizerResult.html) object.

Since [`MBSuccessFrameGrabberRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSuccessFrameGrabberRecognizer.html)  impersonates its slave [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) object, it is not possible to give both concrete [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) object and `MBSuccessFrameGrabberRecognizer` that wraps it to same `MBRecognizerCollection` - doing so will have the same result as if you have given two instances of same [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) type to the [`MBRecognizerCollection`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerCollection.html) - it will crash your application.

This recognizer is best for use cases when you need to capture the exact image that was being processed by some other [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) object at the time its [`MBRecognizerResult`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerResult.html) became `Valid`. When that happens, `MBSuccessFrameGrabberRecognizer's` `MBSuccessFrameGrabberRecognizerResult` will also become `Valid` and will contain described image.

## <a name="pdf417-recognizer"></a> PDF417 recognizer

The [`MBPdf417Recognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBPdf417Recognizer.html) is recognizer specialised for scanning [PDF417 2D barcodes](https://en.wikipedia.org/wiki/PDF417). This recognizer can recognize only PDF417 2D barcodes - for recognition of other barcodes, please refer to [BarcodeRecognizer](#barcode-recognizer).

This recognizer can be used in any overlay view controller, but it works best with the [`MBBarcodeOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBBarcodeOverlayViewController.html), which has UI best suited for barcode scanning.

## <a name="barcode-recognizer"></a> Barcode recognizer

The [`MBBarcodeRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBarcodeRecognizer.html) is recognizer specialised for scanning various types of barcodes. This recognizer should be your first choice when scanning barcodes as it supports lots of barcode symbologies, including the [PDF417 2D barcodes](https://en.wikipedia.org/wiki/PDF417), thus making [PDF417 recognizer](#pdf417-recognizer) possibly redundant, which was kept only for its simplicity.

You can enable multiple barcode symbologies within this recognizer, however keep in mind that enabling more barcode symbologies affect scanning performance - the more barcode symbologies are enabled, the slower the overall recognition performance. Also, keep in mind that some simple barcode symbologies that lack proper redundancy, such as [Code 39](https://en.wikipedia.org/wiki/Code_39), can be recognized within more complex barcodes, especially 2D barcodes, like [PDF417](https://en.wikipedia.org/wiki/PDF417).

This recognizer can be used in any overlay view controller, but it works best with the [`MBBarcodeOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBBarcodeOverlayViewController.html), which has UI best suited for barcode scanning.
## <a name="blinkinput-recognizer"></a> BlinkInput recognizer

The [`MBBlinkInputRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkInputRecognizer.html) is generic OCR recognizer used for scanning segments which enables specifying `MBProcessors` that will be used for scanning. Most commonly used `MBProcessor` within this recognizer is [`MBParserGroupProcessor`](http://blinkid.github.io/blinkid-ios/Classes/MBParserGroupProcessor.html)) that activates all `MBParsers` in the group to extract data of interest from the OCR result.

This recognizer can be used in any context. It is used internally in the implementation of the provided [`MBFieldByFieldOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBFieldByFieldOverlayViewController.html).

`MBProcessors` are explained in [The Processor concept](#processor-concept) section and you can find more about `MBParsers` in [The Parser concept](#parser-concept) section.

## <a name="detector-recognizer"></a> Detector recognizer

The [`MBDetectorRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBDetectorRecognizer.html) is recognizer for scanning generic documents using custom `MBDetector`. You can find more about `Detector` in [The Detector concept](#detector-concept) section. `MBDetectorRecognizer` can be used simply for document detection and obtaining its image. The more interesting use case is data extraction from the custom document type. `MBDetectorRecognizer` performs document detection and can be configured to extract fields of interest from the scanned document by using **Templating API**. You can find more about Templating API in [this](#detector-templating) section.
## <a name="blinkcard-recognizers"></a> BlinkCard recognizers 
Payment card recognizers are used to scan payment cards.

### <a name="payment-card-recognizers"></a> Payment / Debit card combined recognizer
The [`MBBlinkCardRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkCardRecognizer.html)is used for scanning the [front and back side of Payment / Debit card](https://en.wikipedia.org/wiki/Payment_card).

### <a name="elite-payment-card-recognizers"></a> Elite Payment / Debit card combined recognizer
The [`MBBlinkCardEliteRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkCardEliteRecognizer.html) scans back side of elite Payment / Debit card after scanning the front side and combines data from both sides.
## <a name="blinkid-recognizers"></a> BlinkID recognizers

Unless stated otherwise for concrete recognizer, **single side BlinkID recognizes** from this list can be used in any context, but they work best with the [`MBDocumentOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentOverlayViewController.html), which has UI best suited for document scanning. 

**Combined recognizers** should be used with [`MBDocumentVerificationOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentVerificationOverlayViewController.html) which manages scanning of multiple document sides in the single camera opening and guides the user through the scanning process. Some combined recognizers support scanning of multiple document types, but only one document type can be scanned at a time.

### <a name="mrtd-recognizer"></a> Machine Readable Travel Document recognizer
The [`MBMrtdRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBMrtdRecognizer.html) is used for scanning and data extraction from the Machine Readable Zone (MRZ) of the various Machine Readable Travel Documents (MRTDs) like ID cards and passports. This recognizer is not bound to the specific country, but it can be configured to only return data that match some criteria defined by the [`MrzFilter`](http://blinkid.github.io/blinkid-ios/Classes/MrzFilter.html).

The `MBMrtdRecognizer` can also be configured to extract additional fields of interest from the scanned document, which are not part of the Machine Readable Zone, by using **Templating API**. You can find more about Templating API in [this](#mrtd-templating) section.

You can find information about usage context at the beginning of [this section](#blinkid_recognizers).

### Machine Readable Travel Document combined recognizer
The [`MBMrtdCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBMrtdCombinedRecognizer.html) scans Machine Readable Zone (MRZ) after scanning the full document image and face image (usually MRZ is on the back side and face image is on the front side of the document). Internally, it uses [MBDocumentFaceRecognizer](#document-face-recognizer) for obtaining full document image and face image as the first step and then [MBMrtdRecognizer](#mrtd-recognizer) for scanning the MRZ.

You can find information about usage context at the beginning of [this section](#blinkid_recognizers).

### US / Canada driver's license barcode recognizer
The [`MBUsdlRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBUsdlRecognizer.html) is used for scanning PDF417 barcode from the US / Canada driver's license.

You can find information about usage context at the beginning of [this section](#blinkid_recognizers).

### US / Canada driver's license combined recognizer
The [`MBUsdlCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBUsdlCombinedRecognizer.html) scans PDF417 barcode from the back side of US / Canada driver's license after scanning the full document image and face image from the front side. Internally, it uses [MBDocumentFaceRecognizer](#document-face-recognizer) for obtaining full document image and face image as the first step and then [MBUsdlRecognizer](#us) for scanning the PDF417 barcode.

You can find information about usage context at the beginning of [this section](#blinkid_recognizers).

### EU Driver's License recognizer
The [`MBEudlRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBEudlRecognizer.html) is used for scanning front side of European Union driver's licenses. Currently, driver's licenses from these countries are supported:

- Austria
- Germany
- United Kingdom

You can find information about usage context at the beginning of [this section](#blinkid_recognizers).

### <a name="document-face-recognizers"></a> Document face recognizer
The [`MBDocumentFaceRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentFaceRecognizer.html) is a special type of recognizer that only returns face image and full document image of the scanned document. It does not extract document fields like first name, last name, etc. This generic recognizer can be used to obtain document images in cases when specific support for some document type is not available.

You can find information about usage context at the beginning of [this section](#blinkid_recognizers).

## BlinkID recognizers by countries

### <a name="austria"></a> Austria

The [`MBAustriaIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBAustriaIdFrontRecognizer.html) is recognizer specialised for scanning front side of Austrian ID.

The [`MBAustriaIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBAustriaIdBackRecognizer.html) is recognizer specialised for scanning back side of Austrian ID.

The [`MBAustriaPassportRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBAustriaPassportRecognizer.html) is recognizer specialised for scanning Austrian Passports.

The [`MBAustriaCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBAustriaCombinedRecognizer.html) is recognizer specialised for scanning both front and back side of Austrian ID.

The [`MBAustriaDlFrontRecognizerResult`](http://blinkid.github.io/blinkid-ios/Classes/MBAustriaDlFrontRecognizerResult.html) is recognizer specialised for scanning front side of Austrian Driver's License.

### <a name="australia"></a> Australia

The [`MBAustraliaDlFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBAustraliaDlFrontRecognizer.html) is recognizer specialised for scanning front side of Australian Driver's License.

The [`MBAustraliaDlBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBAustraliaDlBackRecognizer.html) is recognizer specialised for scanning back side of Australian Driver's License.

### <a name="brunei"></a> Brunei

The [`MBBruneiIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBruneiIdFrontRecognizer.html) is recognizer specialised for scanning front side of Brunei ID.

The [`MBBruneiIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBruneiIdBackRecognizer.html) is recognizer specialised for scanning front side of Brunei ID.

The [`MBBruneiResidencePermitFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBruneiResidencePermitBackRecognizer.html) is recognizer specialised for scanning back side of Brunei Residence Permit.

The [`MBBruneiResidencePermitBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBruneiResidencePermitBackRecognizer.html) is recognizer specialised for scanning back side of Brunei Residence Permit.

The [`MBBruneiTemporaryResidencePermitFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBruneiTemporaryResidencePermitBackRecognizer.html) is recognizer specialised for scanning back side of Brunei Residence Permit.

The [`MBBruneiTemporaryResidencePermitBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBruneiTemporaryResidencePermitBackRecognizer.html) is recognizer specialised for scanning back side of Brunei Residence Permit.

The [`MBBruneiMilitaryIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBruneiMilitaryIdBackRecognizer.html) is recognizer specialised for scanning back side of Brunei Military ID.

The [`MBBruneiMilitaryIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBruneiMilitaryIdFrontRecognizer.html) is recognizer specialised for scanning front side of Brunei Military ID.

### <a name="colombia"></a> Colombia

The [`MBColombiaIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBColombiaIdFrontRecognizer.html) is recognizer specialised for scanning front side of Colombian ID.

The [`MBColombiaIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBColombiaIdBackRecognizer.html) is recognizer specialised for scanning back side of Colombian ID.

The [`MBColombiaDlFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBColombiaDlFrontRecognizer.html) is recognizer specialised for scanning front side Colombian Driver's License.

### <a name="croatia"></a> Croatia

The [`MBCroatiaIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBCroatiaIdFrontRecognizer.html) is recognizer specialised for scanning front side of Croatian ID. It always extracts
identity card number, first and last name of ID holder while extracting other elements is optional.

The [`MBCroatiaIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBCroatiaIdBackRecognizer.html) is recognizer specialised for scanning back side of Croatian ID. It always extracts
MRZ zone and address of ID holder while extracting other elements is optional.

The [`MBCroatiaCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBCroatiaCombinedRecognizer.html) is recognizer specialised for scanning both front and back side of Croatian ID.

### <a name="cyprus"></a> Cyprus

The [`MBCyprusIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBCyprusIdFrontRecognizer.html) is recognizer specialised for scanning front side of Cyprus ID issued after 2015.

The [`MBCyprusIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBCyprusIdBackRecognizer.html) is recognizer specialised for scanning back side of Cyprus ID issued after 2015.

The [`MBCyprusOldIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBCyprusOldIdFrontRecognizer.html) is recognizer specialised for scanning front side of Cyprus ID.

The [`MBCyprusOldIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBCyprusOldIdFrontRecognizer.html) is recognizer specialised for scanning back side of Cyprus ID.

### <a name="czechia"></a> Czechia

The [`MBCzechiaIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBCzechiaIdFrontRecognizer.html) is recognizer specialised for scanning front side of Czech ID.

The [`MBCzechiaIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBackIdBackRecognizer.html) is recognizer specialised for scanning back side of Czech ID.

The [`MBCzechiaCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBCzechiaCombinedRecognizer.html) is recognizer specialised for scanning both front and back side of Czech ID.

### <a name="eudl"></a> European Driver License

The [`MBEudlRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBEudlRecognizer.html) is recognizer specialised for scanning EU Driver License. Supported countries are Austria, Germany, United Kingdom and any (generic) EU driver license. List can be found in [`MBEudlCountry`](http://blinkid.github.io/blinkid-ios/Enums/MBEudlCountry.html)

### <a name="egypt"></a> Egypt

The [`MBEgyptIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBEgyptIdFrontRecognizer.html) is recognizer specialised for scanning front side of Egypt ID.

### <a name="germany"></a> Germany

The [`MBGermanyIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBGermanyIdFrontRecognizer.html) is recognizer specialised for scanning front side of German ID.

The [`MBGermanyIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBGermanyIdBackRecognizer.html) is recognizer specialised for scanning back side of German ID.

The [`MBGermanyCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBGermanyCombinedRecognizer.html) is recognizer specialised for scanning both front and back side of German ID.

The [`MBGermanOldIDRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBGermanOldIDRecognizer.html) is recognizer specialised for scanning old German ID.

The [`MBGermanyPassportRecognizer.h`](http://blinkid.github.io/blinkid-ios/Classes/MBGermanyPassportRecognizer.h.html) is recognizer specialised for scanning German Passports.

The [`MBGermanyDlFrontRecognizerResult.h`](http://blinkid.github.io/blinkid-ios/Classes/MBGermanyDlFrontRecognizerResult.h.html) is recognizer specialised for scanning back side of German Driver's License with B10 support.

The [`MBGermanyDlBackRecognizerResult.h`](http://blinkid.github.io/blinkid-ios/Classes/MBGermanyDlBackRecognizerResult.h.html) is recognizer specialised for scanning back side of German Driver's License with B10 support.

### <a name="hong-kong"></a> Hong Kong

The [`MBHongKongIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBHongKongIdFrontRecognizer.html) is recognizer specialised for scanning front side of Hong Kong ID.

### <a name="indonesia"></a> Indonesia

The [`MBIndonesiaIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBIndonesiaIdFrontRecognizer.html) is recognizer specialised for scanning front side of Indonesian ID.

### <a name="ireland"></a> Ireland

The [`MBIrelandDlFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBIrelandDlFrontRecognizer.html) is recognizer specialised for scanning front side of Irish Driver's License.

### <a name="italy"></a> Italy

The [`MBItalyDlFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBItalyDlFrontRecognizer.html) is recognizer specialised for scanning front side of Italian Driver's License.

### <a name="jordan"></a> Jordan

The [`MBJordanIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBJordanIdFrontRecognizer.html) is recognizer specialised for scanning front side of Jordan ID.

The [`MBJordanIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBJordanIdBackRecognizer.html) is recognizer specialised for scanning back side of Jordan ID.

The [`MBJordanCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBJordanCombinedRecognizer.html) is recognizer specialised for scanning both front and back side of Jordan ID.

### <a name="kuwait"></a> Kuwait

The [`MBKuwaitIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBKuwaitIdFrontRecognizer.html) is recognizer specialised for scanning front side of Kuwait ID.

The [`MBKuwaitIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBKuwaitIdBackRecognizer.html) is recognizer specialised for scanning back side of Kuwait ID.

### <a name="malaysia"></a> Malaysia

The [`MBMalaysiaDlFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBMalaysiaDlFrontRecognizer.html) is recognizer specialised for scanning Malaysian Driver's License.

The [`MBMalaysiaMyKadFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBMalaysiaMyKadFrontRecognizer.html) is recognizer specialised for scanning front side of MyKad.

The [`MBMalaysiaMyKadBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBMalaysiaMyKadBackRecognizer.html) is recognizer specialised for scanning back side of MyKad.

The [`MBMalaysiaMyTenteraFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBMalaysiaMyTenteraFrontRecognizer.html) is recognizer specialised for scanning MyTentera.

The [`MBMalaysiaIkadFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBMalaysiaIkadFrontRecognizer.html) is recognizer specialised for scanning iKad.

The [`MBMalaysiaMyPrFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBMalaysiaMyPrFrontRecognizer.html) is recognizer specialised for scanning MyPR.

The [`MBMalaysiaMyKasFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBMalaysiaMyKasFrontRecognizer.html) is recognizer specialised for scanning MyKAS.

### <a name="mexico"></a> Mexico

The [`MBMexicoVoterIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBMexicoVoterIdFrontRecognizer.html) is recognizer specialised for scanning front side of Mexican Voter ID card.

### <a name="morocco"></a> Morocco

The [`MBMoroccoIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBMoroccoIdFrontRecognizer.html) is recognizer specialised for scanning front side of Morocco ID.

The [`MBMoroccoIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBMoroccoIdBackRecognizer.html) is recognizer specialised for scanning back side of Morocco ID.

### <a name="new-zealand"></a> New Zealand

The [`MBNewZealandDlFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBNewZealandDlFrontRecognizer.html) is recognizer specialised for scanning front side of New Zealand Driver's License.

### <a name="passport"></a> Passport

The [`MBPassportRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBPassportRecognizer.html) is recognizer which can scan all passports with MRZ.

### <a name="poland"></a> Poland

The [`MBPolandIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBPolandIdFrontRecognizer.html) is recognizer specialised for scanning front side of Polish ID.

The [`MBPolandIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBPolandIdBackRecognizer.html) is recognizer specialised for scanning back side of Polish ID.

The [`MBPolandCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBPolandCombinedRecognizer.html) is recognizer specialised for scanning both front and back side of Polish ID.

### <a name="romania"></a> Romania

The [`MBRomaniaIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRomaniaIdFrontRecognizer.html) is recognizer specialised for scanning front side of Romanian ID.

### <a name="serbia"></a> Serbia

The [`MBSerbiaIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSerbiaIdFrontRecognizer.html) is recognizer specialised for scanning front side of Serbian ID.

The [`MBSerbiaIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSerbiaIdBackRecognizer.html) is recognizer specialised for scanning back side of Serbian ID.

The [`MBSerbiaCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSerbiaCombinedRecognizer.html) is recognizer specialised for scanning both front and back side of Serbian ID.

### <a name="singapore"></a> Singapore

The [`MBSingaporeIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSingaporeIdFrontRecognizer.html) is recognizer specialised for scanning front side of Singapore ID.

The [`MBSingaporeIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSingaporeIdBackRecognizer.html) is recognizer specialised for scanning back side of Singapore ID.

The [`MBSingaporeCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSingaporeCombinedRecognizer.html) is recognizer specialised for scanning both front and back side of Singapore ID.

The [`MBSingaporeDlFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSingaporeDlFrontRecognizer.html) is recognizer specialised for scanning front side Singapore Driver's License.

The [`MBSingaporeChangiEmployeeIdRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSingaporeChangiEmployeeIdRecognizer.html) is recognizer specialised for scanning Singapore Changi Employee ID.

### <a name="slovakia"></a> Slovakia

The [`MBSlovakiaIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSlovakiaIdFrontRecognizer.html) is recognizer specialised for scanning front side of Slovakian ID.

The [`MBSlovakiaIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSlovakiaIdBackRecognizer.html) is recognizer specialised for scanning back side of Slovakian ID.

The [`MBSlovakiaCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSlovakiaCombinedRecognizer.html) is recognizer specialised for scanning both front and back side of Slovakian ID.

### <a name="slovenia"></a> Slovenia

The [`MBSloveniaIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSloveniaIdFrontRecognizer.html) is recognizer specialised for scanning front side of Slovenian ID.

The [`MBSloveniaIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSloveniaIdBackRecognizer.html) is recognizer specialised for scanning back side of Slovenian ID.

The [`MBSloveniaCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSloveniaCombinedRecognizer.html) is recognizer specialised for scanning both front and back side of Slovenian ID.

### <a name="spain"></a> Spain

The [`MBSpainDlFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSpainDlFrontRecognizer.html) is recognizer specialised for scanning front side Spanish Driver's License.

### <a name="sweden"></a> Sweden

The [`MBSwedenDlFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSwedenDlFrontRecognizer.html) is recognizer specialised for scanning front side Swedish Driver's License.

### <a name="switzerland"></a> Switzerland

The [`MBSwitzerlandIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSwitzerlandIdFrontRecognizer.html) is recognizer specialised for scanning front side of Swiss ID.

The [`MBSwitzerlandIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSwitzerlandIdBackRecognizer.html) is recognizer specialised for scanning back side of Swiss ID.

The [`MBSwitzerlandPassportRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSwitzerlandIdBackRecognizer.html) is recognizer specialised for scanning of Swiss Passports.

The [`MBSwitzerlandDlFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBSwitzerlandDlFrontRecognizer.html) is recognizer specialised for scanning front side Swiss Driver's License.

### <a name="uae"></a> United Arab Emirates

The [`MBUnitedArabEmiratesIdFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBUnitedArabEmiratesIdFrontRecognizer.html) is recognizer specialised for scanning front side of UAE ID.

The [`MBUnitedArabEmiratesIdBackRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBUnitedArabEmiratesIdBackRecognizer.html) is recognizer specialised for scanning back side of UAE ID.

The [`MBUnitedArabEmiratesDlFrontRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBUnitedArabEmiratesDlFrontRecognizer.html) is recognizer specialised for scanning front side UAE Driver's License.

### <a name="us"></a> United States

The [`MBUsdlRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBUsdlRecognizer.html) is recognizer specialised for scanning back side of US Driver's License.

The [`MBUsdlCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBUsdlCombinedRecognizer.html) is recognizer specialised for scanning both front and back side of US Driver's License.

# <a name="processors-and-parsers"></a> `MBProcessor` and `MBParser`

The `MBProcessors` and `MBParsers` are standard processing units within *BlinkID* SDK used for data extraction from the input images. Unlike the [`MBRecognizer`](#recognizer-concept), `MBProcessor` and `MBParser` are not stand-alone processing units. `MBProcessor` is always used within `MBRecognizer` and `MBParser` is used within appropriate `MBProcessor` to extract data from the OCR result.

## <a name="processor-concept"></a> The `MBProcessor` concept

`MBProcessor` is a processing unit used within some `Recognizer` which supports processors. It process the input image prepared by the enclosing `Recognizer` in the way that is characteristic to the implementation of the concrete `MBProcessor`.

`MBProcessor` architecture is similar to `MBRecognizer` architecture described in [The Recognizer concept](#recognizer-concept) section. Each instance also has associated inner `MBRecognizerResult` object whose lifetime is bound to the lifetime of its parent `MBProcessor` object and it is updated while `MBProcessor` works. If you need your `MBRecognizerResult` object to outlive its parent `MBProcessor` object, you must make a copy of it by calling its method `copy`.

It also has its internal state and while it is in the *working state* during recognition process, it is not allowed to tweak `MBProcessor` object's properties.

To support common use cases, there are several different `MBProcessor` implementations available. They are listed in the next section.

##  <a name="available-processors"></a> List of available processors

This section will give a list of `MBProcessor` types that are available within *BlinkID* SDK and their purpose.

### <a name="image-processors"></a> Image Return Processor

The [`MBImageReturnProcessor`](http://blinkid.github.io/blinkid-ios/Classes/MBImageReturnProcessor.html) is used for obtaining input images. It simply saves the input image and makes it available after the scanning is done.

The appearance of the input image depends on the context in which `MBImageReturnProcessor` is used. For example, when it is used within [`MBBlinkInputRecognizer`](#blinkinput-recognizer), simply the raw image of the scanning region is processed. When it is used within the [`Templating API`](#detector-templating), input image is dewarped (cropped and rotated).
 
The image is returned as the raw [`MBImage`](http://blinkid.github.io/blinkid-ios/Classes/MBImage.html) type. Also, processor can be configured to [encode saved image to JPEG](http://blinkid.github.io/blinkid-ios/Classes/MBImageReturnProcessor.html).

### <a name="parser-group-processor"></a> Parser Group Processor


The [`MBParserGroupProcessor`](http://blinkid.github.io/blinkid-ios/Classes/MBParserGroupProcessor.html) is the type of the processor that performs the OCR (*Optical Character Recognition*) on the input image and lets all the parsers within the group to extract data from the OCR result. The concept of `MBParser` is described in [the next](#parser-concept) section.

Before performing the OCR, the best possible OCR engine options are calculated by combining engine options needed by each `MBParser` from the group. For example, if one parser expects and produces result from uppercase characters and other parser extracts data from digits, both uppercase characters and digits must be added to the list of allowed characters that can appear in the OCR result. This is a simplified explanation because OCR engine options contain many parameters which are combined by the `MBParserGroupProcessor`.

Because of that, if multiple parsers and multiple parser group processors are used during the scan, it is very important to group parsers carefully.

Let's see this on an example: assume that we have two parsers at our disposal: `MBAmountParser` and `MBEmailParser`. `MBAmountParser` knows how to extract amount's from OCR result and requires from OCR only to recognize digits, periods and commas and ignore letters. On the other hand, `MBEmailParser` knows how to extract e-mails from OCR result and requires from OCR to recognize letters, digits, '@' characters and periods, but not commas. 

If we put both `MBAmountParser` and `MBEmailParser` into the same `MBParserGroupProcessor`, the merged OCR engine settings will require recognition of all letters, all digits, '@' character, both period and comma. Such OCR result will contain all characters for `MBEmailParser` to properly parse e-mail, but might confuse `MBAmountParser` if OCR misclassifies some characters into digits.

If we put `MBAmountParser` in one `MBParserGroupProcessor` and `MBEmailParser` in another `MBParserGroupProcessor`, OCR will be performed for each parser group independently, thus preventing the `MBAmountParser` confusion, but two OCR passes of the image will be performed, which can have a performance impact.

`MBParserGroupProcessor` is most commonly used `MBProcessor`. It is used whenever the OCR is needed. After the OCR is performed and all parsers are run, parsed results can be obtained through parser objects that are enclosed in the group. `MBParserGroupProcessor` instance also has associated inner `MBParserGroupProcessorResult` whose state is updated during processing and its property [`ocrLayout`](http://blinkid.github.io/blinkid-ios/Classes/MBParserGroupProcessor.html) can be used to obtain the raw [`MBOcrLayout`](http://blinkid.github.io/blinkid-ios/Classes/MBOcrLayout.html) that was used for parsing data.

Take note that `MBOcrLayout` is available only if it is allowed by the *BlinkID* SDK license key. `MBOcrLayout` structure contains information about all recognized characters and their positions on the image. To prevent someone to abuse that, obtaining of the `MBOcrLayout` structure is allowed only by the premium license keys.

## <a name="parser-concept"></a> The `MBParser` concept

`MBParser` is a class of objects that are used to extract structured data from the raw OCR result. It must be used within `MBParserGroupProcessor` which is responsible for performing the OCR, so `MBParser` is not stand-alone processing unit.

Like [`MBRecognizer`](#recognizer-concept) and all other processing units, each `MBParser` instance has associated inner `MBRecognizerResult` object whose lifetime is bound to the lifetime of its parent `MBParser` object and it is updated while `MBParser` works. When parsing is done `MBParserResult` can be used for obtaining extracted data. If you need your `MBParserResult` object to outlive its parent `MBParser` object, you must make a copy of it by calling its method `copy`.

It also has its internal state and while it is in the *working state* during recognition process, it is not allowed to tweak `MBParser` object's properties.

There are a lot of different `MBParsers` for extracting most common fields which appear on various documents. Also, most of them can be adjusted for specific use cases. For all other custom data fields, there is `RegexParser` available which can be configured with the arbitrary regular expression.

##  <a name="available-parsers"></a> List of available parsers

### <a name="amount-parser"></a> Amount Parser

[`MBAmountParser`](http://blinkid.github.io/blinkid-ios/Classes/MBAmountParser.html) is used for extracting amounts from the OCR result.

### <a name="date-parser"></a> Date Parser

[`MBDateParser`](http://blinkid.github.io/blinkid-ios/Classes/MBDateParser.html) is used for extracting dates in various formats from the OCR result.

### <a name="email-parser"></a> Email Parser

[`MBEmailParser`](http://blinkid.github.io/blinkid-ios/Classes/MBEmailParser.html) is used for extracting e-mail addresses from the OCR result.

### <a name="iban-parser"></a> IBAN Parser

[`MBIbanParser`](http://blinkid.github.io/blinkid-ios/Classes/MBIbanParser.html) is used for extracting IBAN (*International Bank Account Number*) from the OCR result.

### <a name="license-plate-parser"></a> License Plates Parser

[`MBLicensePlatesParser`](http://blinkid.github.io/blinkid-ios/Classes/MBLicensePlatesParser.html) is used for extracting license plate content from the OCR result.

### <a name="raw-parser"></a> Raw Parser

[`MBRawParser`](http://blinkid.github.io/blinkid-ios/Classes/MBRawParser.html) is used for obtaining string version of raw OCR result, without performing any smart parsing operations.

### <a name="regex-parser"></a> Regex Parser

[`MBRegexParser`](http://blinkid.github.io/blinkid-ios/Classes/MBRegexParser.html) is used for extracting OCR result content which is in accordance with the given regular expression. Regular expression parsing is not performed with java's regex engine. Instead, it is performed with custom regular expression engine.

### <a name="topup-parser"></a> TopUp Parser

[`MBTopUpParser`](http://blinkid.github.io/blinkid-ios/Classes/MBTopUpParser.html) is used for extracting TopUp (mobile phone coupon) codes from the OCR result. There exists [`TopUpPreset`](http://blinkid.github.io/blinkid-ios/Enums/MBTopUpPreset.html) enum with presets for most common vendors. Method `- (void)setTopUpPreset:(MBTopUpPreset)topUpPreset` can be used to configure parser to only return codes with the appropriate format defined by the used preset. 

### <a name="vin-parser"></a> VIN (*Vehicle Identification Number*) Parser

[`MBVinParser`](http://blinkid.github.io/blinkid-ios/Classes/MBVinParser.html) is used for extracting VIN (*Vehicle Identification Number*) from the OCR result.

# <a name="templating-api"></a> Scanning generic documents with Templating API

This section discusses the setting up of `MBDetectorRecognizer` for scanning templated documents. Please check `Templating-sample` sample app for source code examples.

Templated document is any document which is defined by its template. Template contains the information about how the document should be detected, i.e. found on the camera scene and information about which part of the document contains which useful information.

## <a name="defining-document-detection"></a> Defining how document should be detected

Before performing OCR of the document, _BlinkID_ first needs to find its location on a camera scene. In order to perform detection, you need to define [MBDetector](#detector-concept). 

You have to set concrete `MBDetector` when instantiating the `MBDetectorRecognizer` as a parameter to its constructor.

You can find out more information about detectors that can be used in section [List of available detectors](#detector-list). The most commonly used detector is [`MBDocumentDetector`](#document-detector).

## <a name="defining-field-extraction"></a> Defining how fields of interest should be extracted

`MBDetector` produces its result which contains document location. After the document has been detected, all further processing is done on the detected part of the input image.

There may be one or more variants of the same document type, for example for some document there may be old and new version and both of them must be supported. Because of that, for implementing support for each document, one or multiple templating classes are used. `MBTemplatingClass` is described in [The Templating Class component](#templating-class) section.

`MBTemplatingClass` holds all needed information and components for processing its class of documents. Templating classes are processed in chain, one by one. On first class for which the data is successfully extracted, the chain is terminated and recognition results are returned. For each input image processing is done in the following way:

1. Classification `MBProcessorGroups` are run on the defined locations to extract data. `MBProcessorGroup` is used to define the location of interest on the detected document and `MBProcessors` that will extract data from that location. You can find more about `MBProcessorGroup` in the [next section](#processor-group).

2. `MBTemplatingClassifier` is run with the data extracted by the classification processor groups to decide whether the currently scanned document belongs to the current class or not. Its [classify](http://blinkid.github.io/blinkid-ios/Protocols/MBTemplatingClassifier.html) method  simply returns `YES/true` or `NO/false`. If the classifier returns `NO/false`, recognition is moved to the next class in the chain, if it exists. You can find more about `MBTemplatingClassifier` in [this](#implementing-templating-classifier) section.

3. If the `MBTemplatingClassifier` has decided that currently scanned document belongs to the current class, non-classification `MBProcessorGroups` are run to extract other fields of interest.

### <a name="processor-group"></a> The `MBProcessorGroup` component

In templating API [`MBProcessorGroup`](http://blinkid.github.io/blinkid-ios/Classes/MBProcessorGroup.html) is used to define the location of the field of interest on the detected document and how that location should be processed by setting following parameters in its constructor:

1. Location coordinates relative to document detection which are passed as [`Rectangle`] object.

2. `MBDewarpPolicy` which determines the resulting image chunk for processing. You can find a description of each `MBDewarpPolicy`, its purpose and recommendations when it should be used to get the best results in [List of available dewarp policies](#dewarp-policy-list) section.

3. Collection of processors that will be executed on the prepared chunk of the image for current document location. You can find more information about processors in [The Processor concept](#processor-concept) section.

### <a name="dewarp-policy-list"></a> List of available dewarp policies

Concrete `MBDewarpPolicy` defines how specific location of interest should be dewarped (cropped and rotated). It determines the height and width of the resulting dewarped image in pixels. Here is the list of available dewarp policies with linked doc for more information:

- [`MBFixedDewarpPolicy`](http://blinkid.github.io/blinkid-ios/Classes/MBFixedDewarpPolicy.html)
    - defines the exact height of the dewarped image in pixels
    - **usually the best policy for processor groups that use a legacy OCR engine**

- [`MBDPIBasedDewarpPolicy`](http://blinkid.github.io/blinkid-ios/Classes/MBDPIBasedDewarpPolicy.html):
    - defines the desired DPI (*Dots Per Inch*)
    - the height of the dewarped image will be calculated based on the actual physical size of the document provided by the used detector and chosen DPI
    - **usually the best policy for processor groups that prepare location's raw image for output**
 
- [`MBNoUpScalingDewarpPolicy`](http://blinkid.github.io/blinkid-ios/Classes/MBNoUpScalingDewarpPolicy.html): 
    - defines the maximal allowed height of the dewarped image in pixels
    - the height of the dewarped image will be calculated in a way that no part of the image will be up-scaled
    - if the height of the resulting image is larger than maximal allowed, then the maximal allowed height will be used as actual height, which effectively scales down the image
    - **usually the best policy for processors that use neural networks, for example,  DEEP OCR, hologram detection or NN-based classification**

### <a name="templating-class"></a> The `MBTemplatingClass` component

[`MBTemplatingClass`](http://blinkid.github.io/blinkid-ios/Classes/MBTemplatingClass.html) enables implementing support for a specific class of documents that should be scanned with templating API. Final implementation of the templating recognizer consists of one or more templating classes, one class for each version of the document.

`MBTemplatingClass` contains two collections of `MBProcessorGroups` and a `MBTemplatingClassifier`.

The two collections of processor groups within `MBTemplatingClass` are:

1. The classification processor groups which are set by using the [`- (void)setClassificationProcessorGroups:(nonnull NSArray<__kindof MBProcessorGroup *> *)processorGroups`] method. `MBProcessorGroups` from this collection will be executed before classification, which means that they are always executed when processing comes to this class.

2. The non-classification processor groups which are set by using the [`- (void)setNonClassificationProcessorGroups:(nonnull NSArray<__kindof MBProcessorGroup *> *)processorGroups`]method. `MBProcessorGroups` from this collection will be executed after classification if the classification has been positive.

A component which decides whether the scanned document belongs to the current class is [`MBTemplatingClass`](http://blinkid.github.io/blinkid-ios/Classes/MBTemplatingClass.html). It can be set by using the `- (void)setTemplatingClassifier:(nullable id<MBTemplatingClassifier>)templatingClassifier` method. If it is not set, non-classification processor groups will not be executed. Instructions for implementing the `MBTemplatingClassifier` are given in the [next section](#implementing-templating-classifier).

### <a name="implementing-templating-classifier"></a> Implementing the `MBTemplatingClassifier`

Each concrete templating classifier implements the [`MBTemplatingClassifier`](http://blinkid.github.io/blinkid-ios/Protocols/MBTemplatingClassifier.html) interface, which requires to implement its `classify` method that is invoked while evaluating associated `MBTemplatingClass`.

Classification decision should be made based on the processing result which is returned by one or more processing units contained in the collection of the classification processor groups. As described in [The ProcessorGroup component](#processor-group) section, each processor group contains one or more `MBProcessors`. [There are different `MBProcessors`](#processor-list) which may enclose smaller processing units, for example, [`MBParserGroupProcessor`](#parser-group-processor) maintains the group of [`MBParsers`](#parser-concept). Result from each of the processing units in that hierarchy can be used for classification. In most cases `MBParser` result is used to determine whether some data in the expected format exists on the specified location.

To be able to retrieve results from the various processing units that are needed for classification, their instances must be available when `classify` method is called.

## Obtaining recognition results

When recognition is done, results can be obtained through processing units instances, such as: `MBProcessors`, `MBParsers`, etc. which are used for configuring the `MBTemplatingRecognizer` and later for processing the input image.

# <a name="detector-concept"></a> The `MBDetector` concept

[`MBDetector`](http://blinkid.github.io/blinkid-ios/Classes/MBDetector.html) is a processing unit used within some `MBRecognizer` which supports detectors, such as [`MBDetectorRecognizer`](#detector-recognizer). Concrete `MBDetector` knows how to find the certain object on the input image. `MBRecognizer` can use it to perform object detection prior to performing further recognition of detected object's contents.

`MBDetector` architecture is similar to `MBRecognizer` architecture described in [The Recognizer concept](#recognizer-concept) section. Each instance also has associated inner `MBRecognizerResult` object whose lifetime is bound to the lifetime of its parent `MBDetector` object and it is updated while `MBDetector` works. If you need your `MBRecognizerResult` object to outlive its parent `MBDetector` object, you must make a copy of it by calling its `copy` method.

It also has its internal state and while it is in the *working state* during recognition process, it is not allowed to tweak `MBDetector` object's properties.

When detection is performed on the input image, each `MBDetector` in its associated `MBDetectorResult` object holds the following information:

- [`MBDetectionCode`](http://blinkid.github.io/blinkid-ios/Enums/MBDetectionCode.html) that indicates the type of the detection.

- [`MBDetectionStatus`](http://blinkid.github.io/blinkid-ios/Enums/MBDetectionStatus.html) that represents the status of the detection.

- each concrete detector returns additional information specific to the detector type


To support common use cases, there are several different `MBDetector` implementations available. They are listed in the next section.

## <a name="detector-list"></a> List of available detectors

### <a name="document-detector"></a> Document Detector

[`MBDocumentDetector`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentDetector.html) is used to detect card documents, cheques, A4-sized documents, receipts and much more.

It accepts one or more `MBDocumentSpecifications`. [`MBDocumentSpecification`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentSpecification.html) represents a specification of the document that should be detected by using edge detection algorithm and predefined aspect ratio.

For the most commonly used document formats, there is a helper method  `+ (instancetype)createFromPreset:(MBDocumentSpecificationPreset)preset` which creates and initializes the document specification based on the given [`MBDocumentSpecificationPreset`](http://blinkid.github.io/blinkid-ios/Enums/MBDocumentSpecificationPreset.html).

For the list of all available configuration methods see [`MBDocumentDetector`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentDetector.html) doc, and for available result content see [`MBDocumentDetectorResult`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentDetectorResult.html) doc.


### <a name="mrtd-detector"></a> MRTD Detector

[`MBMrtdDetector`](http://blinkid.github.io/blinkid-ios/Classes/MBMrtdDetector.html) is used to perform detection of *Machine Readable Travel Documents (MRTD)*.

Method `- (void)setMrtdSpecifications:(NSArray<__kindof MBMrtdSpecification *> *)mrtdSpecifications` can be used to define which MRTD documents should be detectable. It accepts the array of `MBMrtdSpecification`. [`MBMrtdSpecification`](http://blinkid.github.io/blinkid-ios/Classes/MBMrtdSpecification.html) represents specification of MRTD that should be detected. It can be created from the [`MBMrtdSpecificationPreset`](http://blinkid.github.io/blinkid-ios/Enums/MBMrtdSpecificationPreset.html) by using `+ (instancetype)createFromPreset:(MBMrtdSpecificationPreset)preset` method.

If `MBMrtdSpecifications` are not set, all supported MRTD formats will be detectable.

For the list of all available configuration methods see [`MBMrtdDetector`](http://blinkid.github.io/blinkid-ios/Classes/MBMrtdDetector.html) doc, and for available result content see [`MBMrtdDetectorResult`](http://blinkid.github.io/blinkid-ios/Classes/MBMrtdDetectorResult.html) doc.

# Creating customized build of BlinkID SDK

If your final app size is too large, you can create a customised build of _MicroBlink.framework_ and _MicroBlink.bundle_ which will contain only features and resources that you really need.

In order to create customised build of BlinkID SDK, you first need to download the static distribution of BlinkID SDK. A valid production licence key is required in order to gain access to the download link of BlinkID SDK static distribution. Once you have a valid production licence key, please contact our [support team](http://help.microblink.com) and ask them to provide you with the download link. After they give you access to the static distribution of BlinkID SDK, you will be able to download it from you account at [MicroBlink Developer Dashboard](https://www.microblink.com/login).

The static distribution of BlinkID SDK is a large zip file (several hundred megabytes) which contains static libraries of BlinkID SDK's native code, all assets and resources and a script which will create the customised build for you.

### Prerequisites for creating customised build

In order to create customised build of BlinkID SDK, you will need following tools:

- XCode and latest iOS SDK
- CMake - you can install it from Homebrew with `brew install cmake`, or you can download it from [official page](https://cmake.org/download/)
	- please note that command-line version of CMake is required, so if you have downloaded CMake from official page, make sure you install command-line support as well

### Steps for creating customised build

1. Obtain the static distribution of BlinkID SDK by [contacting us](http://help.microblink.com)
2. Download the zip from link that you will be provided
3. Unzip the file into an empty folder
4. Edit the file `enabled-features.cmake`
	- you should enable only features that you need to use by setting appropriate variables to `ON`. 
	- the list of all possible feature variables can be found in `features.cmake` 
		- for each `feature_option` command, first parameter defines the feature variable, and the second is the description of the feature, i.e. what it provides. Other parameters are information for script to work correctly.
	- you should not edit any file except `enabled-features.cmake` (except if instructed so by our support team) to ensure creation of customised build works well
5. Open terminal and navigate to folder with zip's contents.
6. Execute command `./create-custom-build.sh` and select whether you want static or dynamic frameowk.
	- when asked, enter `s` to build static framework or `d` to build dynamic framework
7. After several minutes (depedending of CPU speed of your computer), customised build will appear in the `Release` folder. Use that bundle and framework in your app instead of default one.

#### Warning:

Attempt to use feature within your app which was not enabled in customised build will cause a linker error when linking against the customised framework.

### Troubleshooting:

#### Getting `unrecognized selector sent to instance` when using customised static framework, while everything works OK with dynamic framework

This happens when your app has not been linked with `-ObjC` flag against static framework. The problem is related to using Objective C categories within static library which are thrown away by linker. You can see more information in [official Apple documentation](https://developer.apple.com/library/content/qa/qa1490/_index.html).

#### App crashing when scanning starts with log message _Failed to load resource XX. The program will now crash._

This means that a required resource was not packaged into final app. This usually indicates a bug in our script that makes the customised build. Please [contact us](http://help.microblink.com) and send your version of `enabled-features.cmake` and crash log.

#### CMake error while running script.

You probably have a typo in `enabled-features.cmake`. CMake is very sensitive language and will throw an non-understandable error if you have a typo or invoke any of its commands with wrong number of parameters.

#### Linker error while running the script.

This sometimes happens when XCode's link time optimizer runs out of memory. Usually running the script again solves the problem. Please reboot your Mac if this keeps happening.

#### Keeping only `FEATURE_MRTD` creates rather large `MicroBlink.bundle`

`FEATURE_MRTD` marks the _MRTD recognizer_. However, _MRTD recognizer_ can also be used in _Templating API_ mode where non-MRZ data can be scanned. To perform OCR of non-MRZ data, a rather large OCR model must be used, which supports all fonts. If you only plan to scan MRZ part of the document, you can edit the `features.cmake` in following way:

- find the following line:

```
feature_resources( FEATURE_MRTD model_mrtd model_general_blink_ocr model_micr model_arabic )
```

- keep only `model_mrtd` in the list, i.e. modify the line so that it will be like this:

```
feature_resources( FEATURE_MRTD model_mrtd )
```

This will keep only support for reading MRZ zone in OCR - you will not be able to scan non-MRZ data with such configuration using _MRTD recognizer_, however you will reduce the `MicroBlink.bundle` and then final app size by more than 4MB.

##### More information about OCR models in `FEATURE_MRTD`

- `model_mrtd` is OCR model for performing OCR of MRZ zone
- `model_arabic` is OCR model for performing OCR of digits used in arabic languages - text scanning is not supported
- `model_micr` is OCR model for performing OCR of [Magnetic Ink Characters](https://en.wikipedia.org/wiki/Magnetic_ink_character_recognition)
- `model_general_blink_ocr` is OCR model for performing general-purpose OCR. This model is usually required for performing OCR of non-MRZ text on documents.

# <a name="troubleshooting"></a> Troubleshooting

## <a name="troubleshooting-integration-problems"></a> Integration problems

In case of problems with integration of the SDK, first make sure that you have tried integrating it into XCode by following [integration instructions](#quick-start).

If you have followed [XCode integration instructions](#quick-start) and are still having integration problems, please contact us at [help.microblink.com](http://help.microblink.com).

## <a name="troubleshooting-sdk-problems"></a> SDK problems

In case of problems with using the SDK, you should do as follows:

### <a name="troubleshooting-licensing-problems"></a> Licencing problems

If you are getting "invalid licence key" error or having other licence-related problems (e.g. some feature is not enabled that should be or there is a watermark on top of camera), first check the console. All licence-related problems are logged to error log so it is easy to determine what went wrong.

When you have determine what is the licence-relate problem or you simply do not understand the log, you should contact us [help.microblink.com](http://help.microblink.com). When contacting us, please make sure you provide following information:

* exact Bundle ID of your app (from your `info.plist` file)
* licence that is causing problems
* please stress out that you are reporting problem related to iOS version of PDF417.mobi SDK
* if unsure about the problem, you should also provide excerpt from console containing licence error

### <a name="troubleshooting-other-problems"></a> Other problems

If you are having problems with scanning certain items, undesired behaviour on specific device(s), crashes inside PDF417.mobi SDK or anything unmentioned, please do as follows:
	
* Contact us at [help.microblink.com](http://help.microblink.com) describing your problem and provide following information:
	* log file obtained in previous step
	* high resolution scan/photo of the item that you are trying to scan
	* information about device that you are using
	* please stress out that you are reporting problem related to iOS version of PDF417.mobi SDK

## <a name="troubleshooting-faq"></a> Frequently asked questions and known problems
Here is a list of frequently asked questions and solutions for them and also a list of known problems in the SDK and how to work around them.

#### In demo everything worked, but after switching to production license I get `NSError` with `MBMicroblinkSDKRecognizerErrorDomain` and `MBRecognizerFailedToInitalize` code as soon as I construct specific [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/docs/Classes/MBRecognizer.html) object

Each license key contains information about which features are allowed to use and which are not. This `NSError` indicates that your production license does not allow using of specific `MBRecognizer` object. You should contact [support](http://help.microblink.com) to check if provided licence is OK and that it really contains all features that you have purchased.

#### I get `NSError` with `MBMicroblinkSDKRecognizerErrorDomain` and `MBRecognizerFailedToInitalize` code with trial license key

Whenever you construct any [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/docs/Classes/MBRecognizer.html) object or, a check whether license allows using that object will be performed. If license is not set prior constructing that object, you will get `NSError` with `MBMicroblinkSDKRecognizerErrorDomain` and `MBRecognizerFailedToInitalize` code. We recommend setting license as early as possible in your app.

#### Undefined Symbols on Architecture armv7

Make sure you link your app with iconv and Accelerate frameworks as shown in [Quick start](#quick-start). 
If you are using Cocoapods, please be sure that you've installed `git-lfs` prior to installing pods. If you are still getting this error, go to project folder and execute command `git-lfs pull`.

#### In my `didFinish` callback I have the result inside my `MBRecognizer`, but when scanning activity finishes, the result is gone

This usually happens when using [`MBRecognizerRunnerViewController`](http://blinkid.github.io/blinkid-ios/docs/Classes/MBRecognizerRunnerViewController.html) and forgetting to pause the [`MBRecognizerRunnerViewController`](http://blinkid.github.io/blinkid-ios/docs/Classes/MBRecognizerRunnerViewController.html) in your `didFinish` callback. Then, as soon as `didFinish` happens, the result is mutated or reset by additional processing that `MBRecognizer` performs in the time between end of your `didFinish` callback and actual finishing of the scanning activity. For more information about statefulness of the `MBRecognizer` objects, check [this section](#recognizer-concept).

#### Unsupported architectures when submitting app to App Store

Microblink.framework is a dynamic framework which contains slices for all architectures - device and simulator. If you intend to extract .ipa file for ad hoc distribution, you'll need to preprocess the framework to remove simulator architectures. 

Ideal solution is to add a build phase after embed frameworks build phase, which strips unused slices from embedded frameworks.

Build step is based on the one provided here: http://ikennd.ac/blog/2015/02/stripping-unwanted-architectures-from-dynamic-libraries-in-xcode/

```shell
APP_PATH="${TARGET_BUILD_DIR}/${WRAPPER_NAME}"

# This script loops through the frameworks embedded in the application and
# removes unused architectures.
find "$APP_PATH" -name '*.framework' -type d | while read -r FRAMEWORK
do
FRAMEWORK_EXECUTABLE_NAME=$(defaults read "$FRAMEWORK/Info.plist" CFBundleExecutable)
FRAMEWORK_EXECUTABLE_PATH="$FRAMEWORK/$FRAMEWORK_EXECUTABLE_NAME"
echo "Executable is $FRAMEWORK_EXECUTABLE_PATH"

EXTRACTED_ARCHS=()

for ARCH in $ARCHS
do
echo "Extracting $ARCH from $FRAMEWORK_EXECUTABLE_NAME"
lipo -extract "$ARCH" "$FRAMEWORK_EXECUTABLE_PATH" -o "$FRAMEWORK_EXECUTABLE_PATH-$ARCH"
EXTRACTED_ARCHS+=("$FRAMEWORK_EXECUTABLE_PATH-$ARCH")
done

echo "Merging extracted architectures: ${ARCHS}"
lipo -o "$FRAMEWORK_EXECUTABLE_PATH-merged" -create "${EXTRACTED_ARCHS[@]}"
rm "${EXTRACTED_ARCHS[@]}"

echo "Replacing original executable with thinned version"
rm "$FRAMEWORK_EXECUTABLE_PATH"
mv "$FRAMEWORK_EXECUTABLE_PATH-merged" "$FRAMEWORK_EXECUTABLE_PATH"

done
```

# <a name="info"></a> Additional info

Complete API reference can be found [here](http://blinkid.github.io/blinkid-ios/index.html). 

For any other questions, feel free to contact us at [help.microblink.com](http://help.microblink.com).