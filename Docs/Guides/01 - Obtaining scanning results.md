# Obtaining scanning results

In this guide you will find out how to tell the scanning library **what** you want to scan, and how to collect subsequent **scanning results**. This guide assumes you completed Getting started guide.

While performing the initial integration in Getting started guide, you completed three important steps: 
- a) initializing the scanning settings (step 3. in Getting started)
- b) presenting the Scanning view controller (end of step 3.)
- c) registering for scanning events (step 4.) 

In step a) you define **what** you want to scan. With step b) you **start the scanning process**. In step c) you **handle scanning results**.

Let's look at this in more details.

### 1. Initializing the scanning settings.

When initializing the scanning settings, you also define **what** you want to scan. This is specified with `PPRecognizerSettings` objects.

To see this in more detail, here's the example from Getting started guide:

```objective-c
// 1. To specify we want to perform OCR recognition, initialize the OCR recognizer settings
PPOcrRecognizerSettings *ocrRecognizerSettings = [[PPOcrRecognizerSettings alloc] init];

// 2. We want raw OCR parsing included
[ocrRecognizerSettings addOcrParser:[[PPRawOcrParserFactory alloc] init] name:@"Raw ocr"];

// 3. Add the recognizer setting to a list of used recognizer
[settings.scanSettings addRecognizerSettings:ocrRecognizerSettings];
```

First we initialized `PPOcrRecognizerSettings` settings object.

Then we customized the `PPOcrRecognizerSettings` and specified that Raw ocr parser should be used in the recognizer. This is specific to `PPOcrRecognizerSettings` object, and different `PPRecognizerSettings` have different customization options.

At last, we added the settings to `PPSettings scanSettings` array.  Existence of `PPOcrRecognizerSettings` in `PPSettings scanSettings` will tell the scanning library it should use `PPOcrRecognizer` object in the scanning phase.

> For each type of object you want to scan on camera images (e.g. PDF417 barcode, Croatian payment slip, Regular OCR text, etc.), you need to instantiate the appropriate `PPRecognizerSettings` object. After initialization and optional setup, you should add `PPRecognizerSettings` to `PPSettings scanSettings`.

Depending on what you want to scan on the images, you will want to use different `PPRecognizerSettings` objects. For a complete list of available `PPRecognizerSettings` and subclasses, see the last section of this document.

### 2. Presenting the Scanning view controller

When Scanning view controller becomes visible on the screen, camera capture starts, and recognition begins. Video frames are collected one by one, and sent to all `PPRecognizers` defined in the previous step. 

The way Scanning view controller is presented doesn't affect the scanning behaviour. Scanning view controller can be presented in many different ways:

1. Presented over the current view controller using `presentViewController:animated:completion:`
2. Presented on a navigation view controller using `pushViewController:animated:`
3. As a child view controller in existing VC using `addChildViewController:`
4. And others, e.g using `UITabBarController`, `UIPageViewController`, and so on.

All options for presenting the Scanning view controller are possible. What matters is that when Scanning view controller becomes visible, in `viewDidAppear:` method, scanning from the device's camera begins. Consequently, when Scanning view controller is being closed, in `viewWillAppear:`, scanning stops.

Scanning view controller is created using factory method:

```objective-c
UIViewController<PPScanningViewController>* scanningViewController = [coordinator cameraViewControllerWithDelegate:self];
```

Delegate object set in this call needs to define callback methods which will be notified with different scanning events.

### 3. Registering for scanning events

Delegate object passed to cameraViewControllerWithDelegate: method will be called with different scanning events (For a detailed description see guide 02 - Communicating with the scanner). Here we're concerned with obtaining scanning results.

Scanning results are passed to a callback method:

```objective-c
- (void)scanningViewController:(UIViewController<PPScanningViewController>*)scanningViewController
              didOutputResults:(NSArray*)results; 
```

Scanning library can output one or more `PPRecognizerResult` objects, all of which are contained in the `NSArray` results. In this callback you are responsible for handling the results.

`PPRecognizerResult` class hierarchy closely follows `PPRecognizerSettings` hierarchy. This means if you initialized the scanning library with `PPOcrRecognizerSettings` settings object, you will get `PPOcrRecognizerResult` result object (note the same name prefix). If you used `PPCroSlipRecognizerSettings`, you will get `PPCroSlipRecognizerResult`, and so on.

Use the `isKindOfClass:` method to determine the exact type of the results, like in the following example:

```objective-c
if ([result isKindOfClass:[PPCroSlipRecognizerSettings class]]) {
	PPCroSlipRecognizerSettings *croSlipRecognizerResult = (PPCroSlipRecognizerSettings*)result;
	NSLog(@"%@", [croSlipRecognizerResult amount])
}
```

When you know the exact type of the result, use it's properties and methods to collect the information you're interested in.

> The type of the RecognizerResult object obtained always matches the type of the RecognizerSettings object you used while intializing the scanning library.

### 4. Available `PPRecognizerSettings` and `PPRecognizerResult` classes

MicroBlink's scanning library allows many different Recognizers to be used in the scanning process. Here we have listed them grouped by use cases.

| Documentation file                        | RecognizerSettings            | RecognizerResult               |
|:------------------------------------------|:-----------------------------:|:------------------------------:|
| **01a - BlinkOCR results**                                                                                || 
|                                           | PPOcrRecognizerSettings       | PPOcrRecognizerResult          |
| **01b - PhotoPay Germany results**                                                                        ||                                
|                                           | PPDeSlipRecognizerSettings    | PPDeSlipRecognizerResult       |
|                                           | PPDeQrRecognizerSettings      | PPDeQrRecognizerResult         |
| **01c - PhotoPay Croatia results**                                                                        ||                                
|                                           | PPCroSlipRecognizerSettings   | PPCroSlipRecognizerResult      |
|                                           | PPCroPdf417RecognizerSettings | PPCroPdf417RecognizerResult    |
|                                           | PPCroQrRecognizerSettings     | PPCroQrRecognizerResult        |
| **01b - PhotoPay Austria results**                                                                        ||                                
|                                           | PPAusSlipRecognizerSettings   | PPAusSlipRecognizerResult      |
|                                           | PPAusQrRecognizerSettings     | PPAusQrRecognizerResult        |
| **01e - PhotoPay Slovenia results**                                                                       ||                                       
|                                           | PPSloSlipRecognizerSettings   | PPSloSlipRecognizerResult      |