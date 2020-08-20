<p align="center" >
  <img src="https://raw.githubusercontent.com/wiki/blinkid/blinkid-ios/Images/logo-microblink.png" alt="Microblink" title="Microblink">
</p>

[![Travis](https://img.shields.io/travis/BlinkID/blinkid-ios/master.svg?style=flat)](https://travis-ci.org/BlinkID/blinkid-ios)
[![Pod Version](https://img.shields.io/cocoapods/v/PPBlinkID.svg?style=flat)](https://cocoapods.org/pods/PPBlinkID)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/a0b7aa9b6c254e75829a7b4b223ae60f)](https://www.codacy.com/gh/BlinkID/blinkid-ios?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=BlinkID/blinkid-ios&amp;utm_campaign=Badge_Grade)
[![Platform](https://img.shields.io/cocoapods/p/PPBlinkID.svg?style=flat)](https://github.com/BlinkID/blinkid-ios#)

# BlinkID SDK for iOS

BlinkID SDK enables scanning of over 500 international identity documents, including driving licenses, national identity cards, passports, and others. SDK includes:

- Real-time data and document photo extraction using on-device Machine Learning
- Offline, on-device processing for maximum security and privacy
- Front and back side data capture and comparison
- A beautiful and frictionless scanning UX
- Layered API, allowing everything from simple integration to complex UX customizations. 

To quickly integrate the SDK into your app, follow our [Quick Start](#quick-start) guide.

If you'd like to try BlinkID without coding, simply download the free Microblink Vision demo app:

[![Vision App](https://developer.apple.com/app-store/marketing/guidelines/images/badge-example-preferred.png)](https://apps.apple.com/us/app/microblink-vision/id1464662310?ls=1)

<p align="center" >
  <a href="https://www.youtube.com/watch?v=3sEyQLaxLKA" target="_blank">
    <img src="https://raw.githubusercontent.com/wiki/blinkid/blinkid-ios/Images/blinkid-v5.gif" alt="BlinkID SDK">
  </a>
</p>

# Table of contents

- [Requirements](#requirements)
- [Quick Start](#quick-start)
- [Advanced BlinkID integration instructions](#advanced-integration)
	- [Built-in overlay view controllers and overlay subviews](#ui-customizations)
		- [Using `MBBlinkIdOverlayViewController`](#using-blinkid-overlay-viewcontroller)
		- [Custom overlay view controller](#using-custom-overlay-viewcontroller)
	- [Direct processing API](#direct-api-processing)
		- [Using Direct API for `NSString` recognition (parsing)](#direct-api-string-processing)
		- [Understanding DirectAPI's state machine](#understanding-direct-api-state-machine)
		- [Using DirectAPI while `RecognizerRunnerView` is active](#using-direct-api-while-recognizerrunnerview-active)
		- [Using Direct API with combined recognizers](#using-direct-api-with-combined-recognizers)
- [`MBRecognizer` and available recognizers](#recognizer)
- [List of available recognizers](#available-recognizers)
	- [Frame Grabber Recognizer](#frame-grabber-recognizer)
	- [Success Frame Grabber Recognizer](#success-frame-grabber-recognizer)
	- [BlinkID recognizers](#blinkid-recognizers)
		- [Machine Readable Travel Document recognizer](#mrtd-recognizer)
		- [Passport recognizer](#passport-recognizer)
		- [Visa recognizer](#visa-recognizer)
		- [Document face recognizer](#document-face-recognizers)
		- [BlinkID Recognizer](#blink-id-recognizers)
		- [BlinkID Combined Recognizer](#blink-id-combined-recognizers)
- [Localization](#localization)
- [Troubleshooting](#troubleshooting)
	- [Integration problems](#troubleshooting-integration-problems)
	- [SDK problems](#troubleshooting-sdk-problems)
		- [Licencing problems](#troubleshooting-licensing-problems)
		- [Other problems](#troubleshooting-other-problems)
	- [Frequently asked questions and known problems](#troubleshooting-faq)
- [Size Report](#size-report)
- [Additional info](#info)


# <a name="requirements"></a> Requirements

SDK package contains Microblink framework and one or more sample apps which demonstrate framework integration. The framework can be deployed in iOS 8.0 or later, iPhone 4S or newer and iPad 2 or newer.

SDK performs significantly better when the images obtained from the camera are focused. Because of that, the SDK can have lower performance on iPad 2 and iPod Touch 4th gen devices, which [don't have camera with autofocus](http://www.adweek.com/socialtimes/ipad-2-rear-camera-has-tap-for-auto-exposure-not-auto-focus/12536).  
# <a name="quick-start"></a> Quick Start

## Getting started with BlinkID SDK

This Quick Start guide will get you up and performing OCR scanning as quickly as possible. All steps described in this guide are required for the integration.

This guide closely follows the BlinkID-Sample app in the Samples folder of this repository. We highly recommend you try to run the sample app. The sample app should compile and run on your device, and in the iOS Simulator. 

The source code of the sample app can be used as the reference during the integration.

### 1. Initial integration steps

#### Using CocoaPods

- Since the libraries are stored on [Git Large File Storage](https://git-lfs.github.com), you need to install git-lfs by running these commands:
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
platform :ios, '8.0'
target 'Your-App-Name' do
    pod 'PPBlinkID', '~> 5.7.1'
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

- Since the libraries are stored on [Git Large File Storage](https://git-lfs.github.com), you need to install git-lfs by running these commands:
```shell
brew install git-lfs
git lfs install
```

- **Be sure to restart your console after installing Git LFS**

- To clone, run the following shell command:

```shell
git clone git@github.com:BlinkID/blinkid-ios.git
```

- Copy Microblink.xcframework to your project folder.

- In your Xcode project, open the Project navigator. Drag the Microblink.xcframework file to your project, ideally in the Frameworks group, together with other frameworks you're using. When asked, choose "Create groups", instead of the "Create folder references" option.

![Adding Microblink.xcframework to your project](https://user-images.githubusercontent.com/1635933/89505694-535a1680-d7ca-11ea-8c65-678f158acae9.png)

- Since Microblink.xcframework is a dynamic framework, you also need to add it to embedded binaries section in General settings of your target and choose option `Embed & Sign`.

![Adding Microblink.xcframework to embedded binaries](https://user-images.githubusercontent.com/1635933/89793425-238e7400-db26-11ea-9556-6eedeb6dcc95.png)

- Include the additional frameworks and libraries into your project in the "Linked frameworks and libraries" section of your target settings. 

    - libc++.tbd
    - libiconv.tbd
    - libz.tbd
    
![Adding Apple frameworks to your project](https://user-images.githubusercontent.com/26868155/65599813-f7feab80-df9e-11e9-9612-e285641b272c.png)
    
### 2. Referencing header file
    
In files in which you want to use scanning functionality place import directive.

Swift

```swift
import Microblink
```

Objective-C

```objective-c
#import <Microblink/Microblink.h>
```
    
### 3. Initiating the scanning process
    
To initiate the scanning process, first decide where in your app you want to add scanning functionality. Usually, users of the scanning library have a button which, when tapped, starts the scanning process. Initialization code is then placed in touch handler for that button. Here we're listing the initialization code as it looks in a touch handler method.

Swift

```swift
class ViewController: UIViewController, MBBlinkIdOverlayViewControllerDelegate  {
    
    var blinkIdRecognizer : MBBlinkIdRecognizer?

    override func viewDidLoad() {
        super.viewDidLoad()

        MBMicroblinkSDK.shared().setLicenseResource("blinkid-license", withExtension: "txt", inSubdirectory: "", for: Bundle.main)
    }

    @IBAction func didTapScan(_ sender: AnyObject) {
        
        /** Create BlinkID recognizer */
        self.blinkIdRecognizer = MBBlinkIdRecognizer()
        
        /** Create BlinkID settings */
        let settings : MBBlinkIdOverlaySettings = MBBlinkIdOverlaySettings()
        
        /** Crate recognizer collection */
        let recognizerList = [self.blinkIdRecognizer!]
        let recognizerCollection : MBRecognizerCollection = MBRecognizerCollection(recognizers: recognizerList)
        
        /** Create your overlay view controller */
        let blinkIdOverlayViewController : MBBlinkIdOverlayViewController = MBBlinkIdOverlayViewController(settings: settings, recognizerCollection: recognizerCollection, delegate: self)
        
        /** Create recognizer view controller with wanted overlay view controller */
        let recognizerRunneViewController : UIViewController = MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: blinkIdOverlayViewController)
        
        /** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
        self.present(recognizerRunneViewController, animated: true, completion: nil)
    }
}
```

Objective-C

```objective-c
@interface ViewController () <MBBlinkIdOverlayViewControllerDelegate>

@property (nonatomic, strong) MBBlinkIdRecognizer *blinkIdRecognizer;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [MBMicroblinkSDK.sharedInstance setLicenseResource:@"blinkid-license" withExtension:@"txt" inSubdirectory:@"" for:Bundle.main];
}


- (IBAction)didTapScan:(id)sender {

    /** Create BlinkID recognizer */
    self.blinkIdRecognizer = [[MBBlinkIdRecognizer alloc] init];
    
     /** Create BlinkID settings */
    MBBlinkIdOverlaySettings* settings = [[MBBlinkIdOverlaySettings alloc] init];

    /** Create recognizer collection */
    MBRecognizerCollection *recognizerCollection = [[MBRecognizerCollection alloc] initWithRecognizers:@[self.blinkIdRecognizer]];
    
    /** Create your overlay view controller */
    MBBlinkIdOverlayViewController *blinkIdOverlayViewController = [[MBBlinkIdOverlayViewController alloc] initWithSettings:settings recognizerCollection:recognizerCollection delegate:self];

    /** Create recognizer view controller with wanted overlay view controller */
    UIViewController<MBRecognizerRunnerViewController>* recognizerRunnerViewController = [MBViewControllerFactory recognizerRunnerViewControllerWithOverlayViewController:blinkIdOverlayViewController];
    
    /** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
    [self presentViewController:recognizerRunnerViewController animated:YES completion:nil];

}

@end
```
    
### 4. License key

A valid license key is required to initalize scanning. You can generate a free trial license key, after you register, at [Microblink developer dashboard](https://microblink.com/login).

You can include the license key in your app by passing a string or a file with license key. 
**Note** that you need to set the license key before intializing scanning. Ideally in `AppDelegate` or `viewDidLoad` before initializing any recognizers.

#### License key as string
You can pass the license key as a string, the following way:

Swift

```swift
MBMicroblinkSDK.shared().setLicenseKey("LICENSE-KEY")
```

Objective-C

```objective-c
[[MBMicroblinkSDK sharedInstance] setLicenseKey:@"LICENSE-KEY"];
```

#### License key as file
Or you can include the license key, with the code below. Please make sure that the file that contains the license key is included in your project and is copied during **Copy Bundle Resources** build phase.

Swift

```swift
MBMicroblinkSDK.shared().setLicenseResource("license-key-file", withExtension: "txt", inSubdirectory: "directory-to-license-key", for: Bundle.main)
```

Objective-C

```objective-c
[[MBMicroblinkSDK sharedInstance] setLicenseResource:@"license-key-file" withExtension:@"txt" inSubdirectory:@"" forBundle:[NSBundle mainBundle]];
```

If the licence is invalid or expired then the methods above will throw an **exception**.

### 5. Registering for scanning events
    
In the previous step, you instantiated [`MBBlinkIdOverlayViewController`](http://blinkid.github.io/blinkid-ios//Classes/MBBlinkIdOverlayViewController.html) object with a delegate object. This object gets notified on certain events in scanning lifecycle. In this example we set it to `self`. The protocol which the delegate has to implement is [`MBBlinkIdOverlayViewControllerDelegate`](http://blinkid.github.io/blinkid-ios//Protocols/MBBlinkIdOverlayViewControllerDelegate.html) protocol. It is necessary to conform to that protocol. We will discuss more about protocols in [Advanced integration section](#advanced-integration). You can use the following default implementation of the protocol to get you started.

Swift

```swift
func blinkIdOverlayViewControllerDidFinishScanning(_ blinkIdOverlayViewController: MBBlinkIdOverlayViewController, state: MBRecognizerResultState) {

    // this is done on background thread
    // check for valid state
    if state == .valid {

        // first, pause scanning until we process all the results
        blinkIdOverlayViewController.recognizerRunnerViewController?.pauseScanning()

        DispatchQueue.main.async(execute: {() -> Void in
            // All UI interaction needs to be done on main thread
        })
    }
}

func blinkIdOverlayViewControllerDidTapClose(_ blinkIdOverlayViewController: MBBlinkIdOverlayViewController) {
    // Your action on cancel 
}
```
    
Objective-C

```objective-c  
- (void)blinkIdOverlayViewControllerDidFinishScanning:(MBBlinkIdOverlayViewController *)blinkIdOverlayViewController state:(MBRecognizerResultState)state {
    
    // this is done on background thread
    // check for valid state
    if (state == MBRecognizerResultStateValid) {
        
        // first, pause scanning until we process all the results
        [blinkIdOverlayViewController.recognizerRunnerViewController pauseScanning];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            // All UI interaction needs to be done on main thread
        });
    }
}

- (void)blinkIdOverlayViewControllerDidTapClose:(nonnull MBBlinkIdOverlayViewController *)blinkIdOverlayViewController {
    // Your action on cancel 
}
```

# <a name="advanced-integration"></a> Advanced BlinkID integration instructions
This section covers more advanced details of BlinkID integration.

1. [First part](#ui-customizations) will cover the possible customizations when using UI provided by the SDK.
2. [Second part](#using-document-overlay-viewcontroller) will describe how to embed [`MBRecognizerRunnerViewController's delegates`](http://blinkid.github.io/blinkid-ios/Protocols.html) into your `UIViewController` with the goal of creating a custom UI for scanning, while still using camera management capabilites of the SDK.
3. [Third part](#direct-api-processing) will describe how to use the [`MBRecognizerRunner`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerRunner.html) (Direct API) for recognition directly from `UIImage` without the need of camera or to recognize camera frames that are obtained by custom camera management.
4. [Fourth part](#recognizer) will describe recognizer concept and available recognizers.


## <a name="ui-customizations"></a> Built-in overlay view controllers and overlay subviews

Within BlinkID SDK there are several built-in overlay view controllers and scanning subview overlays that you can use to perform scanning. 
### <a name="using-blinkid-overlay-viewcontroller"></a> Using `MBBlinkIdOverlayViewController`

[`MBBlinkIdOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkIdOverlayViewController.html) implements new UI for scanning identity documents, which is optimally designed to be used with new [`MBBlinkIdRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkIdRecognizer.html) and [`MBBlinkIdCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkIdCombinedRecognizer.html). The new [`MBBlinkIdOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkIdOverlayViewController.html) implements several new features:
* clear indication for searching phase, when BlinkID is searching for an ID document
* clear progress indication, when BlinkID is busy with OCR and data extraction
* clear message when the document is not supported
* visual indications when the user needs to place the document closer to the camera
* when [`MBBlinkIdCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkIdCombinedRecognizer.html) is used, visual indication that the data from the front side of the document doesn't match the data on the back side of the document.

The new UI allows the user to scan the document at an any angle, in any orientation. We recommend forcing landscape orientation if you scan barcodes on the back side, because in that orientation success rate will be higher. 
To force the UI in landscape mode, use the following instructions:

Swift
```swift
let settings = MBBlinkIdOverlaySettings()
settings.autorotateOverlay = true
settings.supportedOrientations = UIInterfaceOrientationMask.landscape
```

Objective-C
```objective-c
MBBlinkIdOverlaySettings *settings = [[MBBlinkIdOverlaySettings alloc] init];
settings.autorotateOverlay = YES;
settings.supportedOrientations = UIInterfaceOrientationMaskLandscape;
```

It has [`MBBlinkIdOverlayViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBBlinkIdOverlayViewControllerDelegate.html) delegate which can be used out-of-the-box to perform scanning using the default UI. Here is an example how to use and initialize [`MBBlinkIdOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkIdOverlayViewController.html):

Swift
```swift
/** Create your overlay view controller */
let blinkIdOverlayViewController : MBBlinkIdOverlayViewController = MBBlinkIdOverlayViewController(settings: blinkIdSettings, recognizerCollection: recognizerCollection, delegate: self)

/** Create recognizer view controller with wanted overlay view controller */
let recognizerRunneViewController : UIViewController = MBViewControllerFactory.recognizerRunnerViewController(withOverlayViewController: blinkIdOverlayViewController)

/** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
self.present(recognizerRunneViewController, animated: true, completion: nil)
```

Objective-C
```objective-c
MBBlinkIdOverlayViewController *overlayVC = [[MBBlinkIdOverlayViewController alloc] initWithSettings:settings recognizerCollection: recognizerCollection delegate:self];
UIViewController<MBRecognizerRunnerViewController>* recognizerRunnerViewController = [MBViewControllerFactory recognizerRunnerViewControllerWithOverlayViewController:overlayVC];

/** Present the recognizer runner view controller. You can use other presentation methods as well (instead of presentViewController) */
[self presentViewController:recognizerRunnerViewController animated:YES completion:nil];
```

As you can see, when initializing [`MBBlinkIdOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkIdOverlayViewController.html), we are sending delegate property as `self`. To get results, we need to conform to [`MBBlinkIdOverlayViewControllerDelegate`](http://blinkid.github.io/blinkid-ios/Protocols/MBBlinkIdOverlayViewControllerDelegate.html) protocol.

### <a name="using-custom-overlay-viewcontroller"></a> Custom overlay view controller

Please check our Samples for custom implementation of overlay view controller.

Overlay View Controller is an abstract class for all overlay views.

It's responsibility is to provide meaningful and useful interface for the user to interact with.
 
Typical actions which need to be allowed to the user are:

- intuitive and meaniningful way to guide the user through scanning process. This is usually done by presenting a "viewfinder" in which the user need to place the scanned object
- a way to cancel the scanning, typically with a "cancel" or "back" button
- a way to power on and off the light (i.e. "torch") button
 
BlinkID SDK always provides it's own default implementation of the Overlay View Controller for every specific use. Your implementation should closely mimic the default implementation as it's the result of thorough testing with end users. Also, it closely matches the underlying scanning technology. 

For example, the scanning technology usually gives results very fast after the user places the device's camera in the expected way above the scanned object. This means a progress bar for the scan is not particularly useful to the user. The majority of time the user spends on positioning the device's camera correctly. That's just an example which demonstrates careful decision making behind default camera overlay view.

### 1. Subclassing
 
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

### 3. Initialization
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
    recognizer = MBBlinkIdCombinedRecognizer()
    recognizers.append(recognizer!)
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
    
    self.recognizer = [[MBBlinkIdCombinedRecognizer alloc] init];
    
    [recognizers addObject: self.recognizer];
    
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


### <a name="understanding-direct-api-state-machine"></a> Understanding DirectAPI's state machine

DirectAPI's `RecognizerRunner` singleton is a state machine that can be in one of 3 states: `OFFLINE`, `READY` and `WORKING`.

- When you obtain the reference to `RecognizerRunner` singleton, it will be in `OFFLINE` state.
- You can initialize `RecognizerRunner` by calling [`init`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerRunner.html#/c:objc(cs)MBRecognizerRunner(im)initWithRecognizerCollection:) method. If you call `initialize` method while `RecognizerRunner` is not in `OFFLINE` state, you will get `IllegalStateException`.
- After successful initialization, `RecognizerRunner` will move to `READY` state. Now you can call any of the `recognize*` methods.
- When starting recognition with any of the `recognize*` methods, `RecognizerRunner` will move to `WORKING` state. If you attempt to call these methods while `RecognizerRunner` is not in `READY` state, you will get `IllegalStateException`
- Recognition is performed on background thread so it is safe to call all `RecognizerRunner's` methods from UI thread
- When recognition is finished, `RecognizerRunner` first moves back to `READY` state and then calls the `recognizerRunner(_ :, didFinishScanningWith:)` method of the provided `MBScanningRecognizerRunnerDelegate`.
- Please note that `MBScanningRecognizerRunnerDelegate's` `recognizerRunner(_ :, didFinishScanningWith:)` method will be called on background processing thread, so make sure you do not perform UI operations in this callback. Also note that until the `recognizerRunner(_ :, didFinishScanningWith:)` method completes, `RecognizerRunner` will not perform recognition of another image or string, even if any of the `recognize*` methods have been called just after transitioning to `READY` state. This is to ensure that results of the recognizers associated with `RecognizerRunner` are not modified while possibly being used within `recognizerRunner(_ :, didFinishScanningWith:)` method.
- By calling `resetState` method, `RecognizerRunner` singleton will release all its internal resources. Note that even after calling `resetState` you might receive `recognizerRunner(_ :, didFinishScanningWith:)` event if there was work in progress when `resetState` was called.
- `resetState` method can be called from any `RecognizerRunner` singleton's state


### <a name="using-direct-api-while-recognizerrunnerview-active"></a> Using DirectAPI while `RecognizerRunnerView` is active
Both `RecognizerRunnerView` and `RecognizerRunner` use the same internal singleton that manages native code. This singleton handles initialization and termination of native library and propagating recognizers to native library. It is possible to use `RecognizerRunnerView` and `RecognizerRunner` together, as internal singleton will make sure correct synchronization and correct recognition settings are used. If you run into problems while using `RecognizerRunner` in combination with `RecognizerRunnerView`, let us know!

### <a name="using-direct-api-with-combined-recognizers"></a> Using Direct API with combined recognizers
When you are using combined recognizer and images of both document sides are required, you need to call `RecognizerRunner.recognize*` multiple times. Call it first with the images of the first side of the document, until it is read, and then with the images of the second side. The combined recognizer automatically switches to second side scanning, after it has successfully read the first side. To be notified when the first side scanning is completed, you have to set the `MBFirstSideFinishedRecognizerRunnerDelegate` through `MBRecognizerRunnerMetadataDelegates`. If you don't need that information, e.g. when you have only one image for each document side, don't set the `MBFirstSideFinishedRecognizerRunnerDelegate` and check the RecognitionSuccessType in `MBScanningRecognizerRunnerDelegate.recognizerRunner(_ :, didFinishScanningWith:)`, after the second side image has been processed.
# <a name="recognizer"></a> `MBRecognizer` and available recognizers

## The `MBRecognizer` concept

The [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) is the basic unit of processing within the SDK. Its main purpose is to process the image and extract meaningful information from it. As you will see [later](#available-recognizers), the SDK has lots of different [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) objects that have various purposes.

Each [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) has a [`MBRecognizerResult`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerResult.html) object, which contains the data that was extracted from the image. The [`MBRecognizerResult`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizerResult.html) object is a member of corresponding [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) object its lifetime is bound to the lifetime of its parent [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) object. If you need your `MBRecognizerResult` object to outlive its parent [`MBRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBRecognizer.html) object, you must make a copy of it by calling its method `copy`.

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

## <a name="blinkid-recognizers"></a> BlinkID recognizers

Unless stated otherwise for concrete recognizer, **single side BlinkID recognizes** from this list can be used in any context, but they work best with the [`MBDocumentOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentOverlayViewController.html), which has UI best suited for document scanning. 

**Combined recognizers** should be used with [`MBDocumentVerificationOverlayViewController`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentVerificationOverlayViewController.html) which manages scanning of multiple document sides in the single camera opening and guides the user through the scanning process. Some combined recognizers support scanning of multiple document types, but only one document type can be scanned at a time.

### <a name="mrtd-recognizer"></a> Machine Readable Travel Document recognizer
The [`MBMrtdRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBMrtdRecognizer.html) is used for scanning and data extraction from the Machine Readable Zone (MRZ) of the various Machine Readable Travel Documents (MRTDs) like ID cards and passports. This recognizer is not bound to the specific country, but it can be configured to only return data that match some criteria defined by the [`MBMrzFilter`](http://blinkid.github.io/blinkid-ios/Classes/MBMrzFilter.html).

You can find information about usage context at the beginning of [this section](#-blinkid_recognizers).

### Machine Readable Travel Document combined recognizer
The [`MBMrtdCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBMrtdCombinedRecognizer.html) scans Machine Readable Zone (MRZ) after scanning the full document image and face image (usually MRZ is on the back side and face image is on the front side of the document). Internally, it uses [MBDocumentFaceRecognizer](#document-face-recognizer) for obtaining full document image and face image as the first step and then [MBMrtdRecognizer](#mrtd-recognizer) for scanning the MRZ.

You can find information about usage context at the beginning of [this section](#-blinkid_recognizers).

### <a name="passport-recognizer"></a> Passport recognizer
The [`MBPassportRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBPassportRecognizer.html) is used for scanning and data extraction from the Machine Readable Zone (MRZ) of the various passport documents. This recognizer also returns face image from the passport.

You can find information about usage context at the beginning of [this section](#-blinkid_recognizers).

### <a name="visa-recognizer"></a> Visa recognizer
The [`MBVisaRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBVisaRecognizer.html) is used for scanning and data extraction from the Machine Readable Zone (MRZ) of the various visa documents. This recognizer also returns face image from the visa document.

You can find information about usage context at the beginning of [this section](#-blinkid_recognizers).

### AAMVA standard barcode recognizer (USA, Canada, Nigeria)
The [`MBUsdlRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBUsdlRecognizer.html) is used for scanning PDF417 barcode from USA ID cards and driver’s licence, Canadian ID cards and driving licence, and Nigerian driving licence.

You can find information about usage context at the beginning of [this section](#-blinkid_recognizers).

### AAMVA standard combined recognizer (USA, Canada, Nigeria)
The [`MBUsdlCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBUsdlCombinedRecognizer.html) first scans the front side of the document to obtain the full document image and face image. It then scans PDF417 barcode from the back side of AAMVA standard documents. This includes USA ID cards and driver’s licence, Canadian ID cards and driving licence, and Nigerian driving licence.
Internally, it uses [MBDocumentFaceRecognizer](#document-face-recognizer) for obtaining full document image and face image as the first step and then [MBUsdlRecognizer](http://blinkid.github.io/blinkid-ios/Classes/MBUsdlCombinedRecognizer.html) for scanning the PDF417 barcode.

You can find information about usage context at the beginning of [this section](#-blinkid_recognizers).

### <a name="document-face-recognizers"></a> Document face recognizer
The [`MBDocumentFaceRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBDocumentFaceRecognizer.html) is a special type of recognizer that only returns face image and full document image of the scanned document. It does not extract document fields like first name, last name, etc. This generic recognizer can be used to obtain document images in cases when specific support for some document type is not available.

You can find information about usage context at the beginning of [this section](#-blinkid_recognizers).

### <a name="blink-id-recognizers"></a> BlinkID Recognizer
The [`MBBlinkIdRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkIdRecognizer.html) scans and extracts data from the front side of the supported document. 
You can find the list of the currently supported documents [`here`](https://github.com/BlinkID/blinkid-ios/tree/master/documentation/BlinkIDRecognizer.md).
We will continue expanding this recognizer by adding support for new document types in the future. Star this repo to stay updated.

### <a name="blink-id-combined-recognizers"></a> BlinkID Combined Recognizer
Use [`MBBlinkIdCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkIdCombinedRecognizer.html) for scanning both sides of the supported document. First, it scans and extracts data from the front, then scans and extracts data from the barcode on the back, and finally, combines results from both sides. The [`BlinkIDCombinedRecognizer`](http://blinkid.github.io/blinkid-ios/Classes/MBBlinkIdCombinedRecognizer.html) also performs data matching and returns a flag if the extracted data captured from the front side matches the data from the barcode on the back.
You can find the list of the currently supported documents [`here`](https://github.com/BlinkID/blinkid-ios/tree/master/documentation/BlinkIDRecognizer.md).
We will continue expanding this recognizer by adding support for new document types in the future. Star this repo to stay updated.

# <a name="localization"></a> Localization

The SDK is localized on following languages: Arabic, Chinese simplified, Chinese traditional, Croatian, Czech, Dutch, Filipino, French, German, Hebrew, Hungarian, Indonesian, Italian, Malay, Portuguese, Romanian, Slovak, Slovenian, Spanish, Thai, Vietnamese.

If you would like us to support additional languages or report incorrect translation, please contact us at [help.microblink.com](http://help.microblink.com).

If you want to add additional languages yourself or change existing translations, you need to set `customLocalizationFileName` property on [`MBMicroblinkApp`](http://blinkid.github.io/blinkid-ios/Classes/MBMicroblinkApp.html) object to your strings file name.

For example, let's say that we want to change text "Scan the front side of a document" to "Scan the front side" in BlinkID sample project. This would be the steps:
* Find the translation key in en.strings file inside Microblink.framework
* Add a new file MyTranslations.strings to the project by using "Strings File" template
* With MyTranslations.string open, in File inspector tap "Localize..." button and select English
* Add the translation key "blinkid_generic_message" and the value "Scan the front side" to MyTranslations.strings
* Finally in AppDelegate.swift in method `application(_:, didFinishLaunchingWithOptions:)` add `MBMicroblinkApp.instance()?.customLocalizationFileName = "MyTranslations"`

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
* please stress out that you are reporting problem related to iOS version of BlinkID SDK
* if unsure about the problem, you should also provide excerpt from console containing licence error

### <a name="troubleshooting-other-problems"></a> Other problems

If you are having problems with scanning certain items, undesired behaviour on specific device(s), crashes inside BlinkID SDK or anything unmentioned, please do as follows:
	
* Contact us at [help.microblink.com](http://help.microblink.com) describing your problem and provide following information:
	* log file obtained in previous step
	* high resolution scan/photo of the item that you are trying to scan
	* information about device that you are using
	* please stress out that you are reporting problem related to iOS version of BlinkID SDK

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

### Disable logging

Logging can be disabled by calling `disableMicroblinkLogging` method on [`MBLogger`](http://blinkid.github.io/blinkid-ios/docs/Classes/MBLogger.html) instance.
# <a name="size-report"></a> Size Report

We are delivering complete size report of our BlinkID SDK based on our BlinkID-sample-Swift sample project. You can check that [here](https://github.com/BlinkID/blinkid-ios/tree/master/size-report).
# <a name="info"></a> Additional info

Complete API reference can be found [here](http://blinkid.github.io/blinkid-ios/index.html). 

For any other questions, feel free to contact us at [help.microblink.com](http://help.microblink.com).