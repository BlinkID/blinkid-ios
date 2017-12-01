## 2.14.0

- Removed `imageDPI` property on `PPTemplatingRecognizerSettings`   

## 2.13.0

- `PPDocumentDetectorResult` does not contain information about screen orientation any more

## 2.12.0

- There is no more option in `PPUsdlRecognizerSettings` to scan 1D barcodes. Previously this setting did nothing - it's OK to just delete the setter call if you use it.
- `PPBlinkOcrRecognizerResult` and `PPBlinkOcrRecognizerSettings` are now deprecated. Use `PPDetectorRecognizerResult` and `PPDetectorRecognizerSettings` for templating or `PPBlinkInputRecognizerResult` and `PPBlinkInputRecognizerSettings` for segment scan

## 2.11.0

- No changes

## 2.10.0

- `PPAztecRecognizerResult` and `PPAztecRecognizerSettings` are now deprecated. Use `PPBarcodeRecognizerResult` and `PPBarcodeRecognizerSettings`
- `PPBarDecoderRecognizerResult` and `PPBarDecoderRecognizerSettings` are now deprecated. Use `PPBarcodeRecognizerResult` and `PPBarcodeRecognizerSettings`
- `PPZXingRecognizerResult` and `PPZXingRecognizerSettings` are now deprecated. Use `PPBarcodeRecognizerResult` and `PPBarcodeRecognizerSettings`
- `extractAddress` property in `PPSlovakIDBackRecognizerSettings` is now removed since previously wasn't used

## 2.9.0

- Since Microblink.framework is a dynamic framework, you also need to **add it to embedded binaries section in General settings of your target.**

- Library size was reduced by removing all unnecessary components. One of the components removed was internal libz library. You now need to **add libz.tbd into "Linked frameworks and binaries" setting.**

- Microblink.framework is a dynamic framework which contains slices for all architectures - device and simulator. If you intend to extract .ipa file for ad hoc distribution, you'll need to preprocess the framework to remove simulator architectures. 

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

- Deprecated `PPHelpDisplayMode`. It still works, but ideally, you should replace it with a custom logic for presenting help inside the application using the SDK.
- Simplified `PPOcrLayout` class (removed properties which were not used). If you used it previously, simply remove that code because it does not provide any value.
- If you're using PPGermanIDMrzRecognizer, it's functionality is now split into two recognizers:
    - one for back side of the new ID (PPGermanIDBackRecognizer)
    - one for front side of the old ID (PPGermanOldIDRecognizer)

## 2.8.0

- If you have problems in naming of the classes with "ID" in the name, we now use uppercase "ID" in all filenames and all class names. Update accordingly. This gets rid of the Clang's warning about the case insensitivity.

- If you're using PPGermanIDMrzRecognizer, it's functionality is now split into two recognizers:
    - one for back side of the new ID (PPGermanIDBackRecognizer)
    - one for front side of the old ID (PPGermanOldIDRecognizer)
    
- Add libz into link binary with libaries. We removed internally used libz library to make the SDK smaller.

## 2.7.1

## 2.7.0

## 2.6.0

- If you're using PPSingaporeIdRecognizer, you should now decide which side of the ID you want to use, and use either PPSingaporeIDBackRecognizer, or PPSingaporeIDFrontRecognizer
- `PPMobileCouponsOcrParserFactory` changed name to `PPTopUpOcrParserFactory`

## 2.5.1

- Default `PPIDCardOverlayViewController` implementation changed. Now it no longer uses viewfinder overlay subview, instead it places an UIImageView in the center of the view, which shows the frame inside which the user should place the document. This improves positioning, and in turn - increases the success rate of the scanning

- Nullability attributes have been fixed. Basically, properties in the result classes are no longer consider nonnull (this was wrong!). You should always consider an option that the result property is nil, which means it doesn't exist at all on the scanned document.

## 2.5.0

- `PPMrtdRecognizerResult` now returns `NSDate` in methods `dateOfBirth` and `dateOfExpiry`. Previously `NSString` was returned and user had to parse the string to get the date. If you want old behaviour, use methods `rawDateOfBirth` and `rawDateOfExpiry` which will return strings in same format as in previous versions.
- this also applies for all recognizer results that inherit `PPMrtdRecognizerResult`
- although `PPDateOcrParser` now returns `PPDateResult` object (which contains both `NSDate` and original `NSString` from which date was parsed), when obtaining parser result via `parserResultForName:` or `parserResultForName:parserGroup:` methods, you will be provided with string just like in previous versions. If you want `NSDate`, you should use methods `specificParsedResultForName:` or `specificParsedResultForName:parserGroup:` and cast `NSObject` they return into `NSDate`.
- all recognizer results (classes that derive `PPRecognizerResult`) now have annotated nullability for their getters. Some of them used to assume non-null, while still returning `nil` sometimes. This has now been corrected and all getters are `_Nullable`

## 2.4.0

- No backwards incompatible changes. See Release notes for new features.

## 2.3.0

- No backwards incompatible changes. See Release notes for new features.

## 2.2.1

- No backwards incompatible changes. See Release notes for new features.

## 2.2.0

- Removed PPOcrEngineOptions property from PPRegexOcrParserFactory and PPRawOcrParserFactory. Replaced property with setter method.

## 2.1.0

- No backwards incompatible changes. See Release notes for new features.

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