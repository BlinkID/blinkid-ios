## 2.0.0

- `PPCameraCoordinator` now assumes the role of `PPCoordinator`. If you do not use your own camera management or Direct API you can rename all instances of `PPCoordinator` to `PPCameraCoordinator`
- `PPCoordinator` method `cameraViewControllerWithDelegate:` has been removed. To create `PPScanningViewControllers` you can now use `[PPViewControllerFactory cameraViewControllerWithDelegate: coordinator: error:]`
- Direct API is now located in `PPCoordinator`. To process image use 'processImage:' method and be sure to set 'PPCoordinatorDelegate' when creating 'PPCoordinator' to recieve scanning results and events. You can se processing image roi and processing orientation on 'PPImage' object.
- Methods of 'PPOverlayContainerViewController' protocol should now be called after camera view has appeared.

## 1.4.0

- If you implement custom camera UI and handle `cameraViewController:didFindLocation:withStatus`, this method was changed to `cameraViewController:didFinishDetectionWithResult:`. `PPDetectorResult` object now contains all information previosusly passed to this method. Simply update the code to use the new method signature. Verify the exact type of the passed detectorResult object, cast it to this class, and use provided getters to obtain all information.

- PPOverlayViewController changed the way Overlay Subviews are added to the view hierarchy. Instead of calling `addOverlaySubview:` (which automatically added a view to view hierarachy), you now need to call `registerOverlaySubview:` (which registers subview for scanning events), and manually add subview to view hierarchy using `addSubview:` method. This change gives you more flexibility for adding views and managing autolayout and autoresizing masks. So, replace all calls to (assuming self is a `PPOverlayViewController` instance)

```objective-c
[self addOverlaySubview:subview];
```

with 
```objective-c
[self registerOverlaySubview:subview];
[self.view addSubview:subview];
```
- If you use DetectorRecognizer, designated initializer of `PPDocumentDecodingInfoEntry` objects changed. Instead of `initWithLocation:dewarpedHeight:` use `initWithLocation:dewarpedHeight:uniqueId:`. As Unique ID pass any unique string which you'll use to identify the decoding info object.

- Localization Macros MB_LOCALIZED and MB_LOCALIZED_FORMAT can now be overriden in your app to provide completely custom localization mechanisms.

## 1.3.0

- Remove the old .embeddedframework package completely from your project

- Add new .framework and .bundle package to your project. Verify that Framework search path really contains a path to the .framework folder.

- replace all occurrences of `PPCoordinator`'s method `isScanningUnsupported:` to `isScanningUnsupportedForCameraType:error:`. If you use Back facing camera, use `PPCameraTypeBack`, otherwise `PPCameraTypeFront`.

- Rename `PPMetadataSettings` properties 
    - `successfulScanFrame` rename to `successfulFrame`
    - `currentVideoFrame` rename to `currentFrame`

## 1.2.0

- You can now enable Bitcode support in your project.

- If you used `mrtdRoi` and `detectMachineReadbleZonePosition`, just delete the lines of code where you used them. MRTD is now automatically detected

- Renamed `PPUkdlRecognizerResult`'s property `ownerAdress` to `ownerAddress` (fixed typo)

- You now need to link your app with `Accelerate.framework` system library. This is due to new optimizations in character recognition.

## 1.1.0

- No backwards incompatible changes. See Release notes for new features.

## 1.0.1

- No backwards incompatible changes

### Transition to 1.0.0

- If you're using direct API, just delete all calls to `PPCoordinator initializeRecognizers` and `PPCoordinator terminateRecognizers`. These calls are now performed internally

- `rotatedImage` property of `PPImageMetadata` no longer exists. Use `image` property instead, it correctly handles rotation.

- `PPApp` class is no longer a part of the API. 

- `PPMetadataSettings` was cleaned up - use the alternative names provided listed in the header file. 

## 0.9.6

- No backwards incompatible changes

## 0.9.5

- No backwards incompatible changes

## 0.9.4

- No backwards incompatible changes

### Transition to 0.9.3

- This version uses a new license key format. If you had a license key generated prior to v0.9.3, contact us so we can regenerate the lincense key for you.

- UK Driver's license support added. To scan them, add PPUkdlRecognizerSettings to `settings.scanSettings`

```objective-c
[settings.scanSettings addRecognizerSettings:[[PPUkdlRecognizerSettings alloc] init]];
```
  
- To collect UKDL results, look for `PPUkdlRecognizerResult` object in `scanningViewController:didOutputResults:` callback

```objective-c
for (PPRecognizerResult *result in results) {
        if ([result isKindOfClass:[PPUkdlRecognizerResult class]]) {
                PPUkdlRecognizerResult* ukdlResult = (PPUkdlRecognizerResult*)result;
                [self processUkdlResult:ukdlResult scanningViewController:scanningViewController];
        }
}
```

- `PPCoordinator` class now exposes fewer public methods and properties.

### Transition to 0.9.2

- Classes representing scanning results were renamed. Renaming was performed to match naming convention of `PPRecognizerSettings` hierarcy: now each `PPRecognizerSettings` class has it's matching `PPRecognizerResult`. Replace all existing references to old class names with the new ones:

	- `PPBaseResult` was renamed to `PPRecognizerResult`. 
	
- `PPOcrResult` (class representing a result of the OCR process, with individual characters, lines and blocks), was renamed to `PPOcrLayout`. Name change was introduced to further distinguish the class from `PPRecognizerResult` classes.

- Remove all references to `updateScanningRegion` method since it's now being called automatically in `setScanningRegion setter`.

### Transition to 0.9.1

- Framework was renamed to MicroBlink.embeddedframework. Remove the existing .embeddedframwork package from your project, and drag&drop MicroBlink.embeddedframework in the project explored of your Xcode project.

- If necessary, after the update, modify your framework search path so that it points to the  MicroBlink.embeddedframework folder.

- Main header of the framework was renamed to `<MicroBlink/Microblink.h>`. Change all references to previous header with the new one.

- method `[PPCoordinator isPhotoPaySupported]` was renamed to `[PPCoordinator isScanningSupported]`. Change all occurances of the method name.