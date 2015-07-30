## 1.0.1

- Added support for several new special cases of US Driver Licenses in USDL recognizer. 

- Disabled Bitcode in Sample apps so that they are buildable with XCode 7 (Bitcode support in the framework coming soon!)

- Added library dependencies in podspec without which the app after integration couldn't be built 

## 1.0.0

- Changes in Direct processing API
    - You are no longer required to call `PPCoordinator initializeRecognizers` and `PPCoordinator terminateRecognizers`.
    - Instead, `initializeRecognizers` is called lazily on first call of `processImage` method. 
    - `terminateRecognizers` is called automatically in `PPCoordinator` destructor 
    
- Added support for autorotation of `PPScanningViewController`. To support autorotation, use `PPScanningViewController`'s new properties `autorotate` and `supportedOrientations`

- Added `didOutputMetadata:` callback method to `PPOverlayViewControllers`

- Fixed bug which caused Overlay events to be called when direct API is used. Direct API now only reports events to `PPScanDelegate` instance.

- Fixed bug which caused image property of `PPImageMetadata` not take the image orientation into account

- `PPMetadataSettings` cleanup

- `PPApp` class no longer part of public API

## 0.9.6

- US passport scanning now has less confusions between characters 0 and O
- Fixes for French passport format
- Fixed timeout bug which manifested between consecutive scans

## 0.9.5

- Added Direct processing API

## 0.9.4

- Added support for defining region for scaninng in `PPMrtdRecognizerSettings`

- For example, with this code you can specify bottom 25% of the image will be used for MRZ scanning.

```objective-c
PPMrtdRecognizerSettings *mrtdSettings = [[PPMrtdRecognizerSettings alloc] init];
mrtdSettings.mrtdRoi = CGRectMake(0.0, 0.75, 1.0, 0.25);
[settings.scanSettings addRecognizerSettings:mrtdSettings];
```
        
        
## 0.9.3

- Added support for scanning UK Driver's license. To scan them, add PPUkdlRecognizerSettings to `settings.scanSettings`

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
        
- License key format is now changed. If you use license keys generated pior to this version, please contact us so we can generate you a new license key

- Methods and properties in `PPCoordinator` class which were not meant to be part of the public API are now hidden.

## 0.9.2

- Naming changes in API (see Transition guide)
	- `PPBaseResult` renamed to `PPRecognizerResult`
	- `PPBaseResult` subclasses renamed accordingly
	- `PPOcrResult` renamed to `PPOcrLayout`

- Each `PPRecognizerResult` now has implemented `description` method for easier debugging

- Fixed orientation handling for case when overlay autorotates.

- Scanning region is now a property of Scanning view controller, and overlay view controller now delegates to this property.

## 0.9.1

- API consolidation, Bugfixes and improvements

## 0.9.0

- Initial documentation added
	
## 0.6.0

- Initial USDL and MRZ scanning