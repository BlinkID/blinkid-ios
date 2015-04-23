## 0.9.4

- Added support for defining region for scaninng in `PPMrtdRecognizerSettings`

- For example, with this code you can specify bottom 25% of the image will be used for MRZ scanning.

        PPMrtdRecognizerSettings *mrtdSettings = [[PPMrtdRecognizerSettings alloc] init];
        mrtdSettings.mrtdRoi = CGRectMake(0.0, 0.75, 1.0, 0.25);
        [settings.scanSettings addRecognizerSettings:mrtdSettings];
        
        
## 0.9.3

- Added support for scanning UK Driver's license. To scan them, add PPUkdlRecognizerSettings to `settings.scanSettings`

        [settings.scanSettings addRecognizerSettings:[[PPUkdlRecognizerSettings alloc] init]];
        
- To collect UKDL results, look for `PPUkdlRecognizerResult` object in `scanningViewController:didOutputResults:` callback

        for (PPRecognizerResult *result in results) {
                if ([result isKindOfClass:[PPUkdlRecognizerResult class]]) {
                        PPUkdlRecognizerResult* ukdlResult = (PPUkdlRecognizerResult*)result;
                        [self processUkdlResult:ukdlResult scanningViewController:scanningViewController];
                }
        }
        
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