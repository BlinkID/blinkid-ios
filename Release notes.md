## 2.14.0

- Updates and additions
    - added support for reading back side of new Australian Driver's licence for state Victoria - use `PPAustraliaDLBackRecognizerSettings` and `PPAustraliaDLBackRecognizerResult`
    - added support for reading front side of Indonesian ID - use `PPIndonesianIDFrontRecognizerSettings` and `PPIndonesianIDFrontRecognizerSettings`
    - added support for Malaysian visa with document code TS - use `PPMrtdRecognizerSettings` and `PPMrtdRecognizerResult`
    - added support for setting DPI for full document images returned by `PPMrtdRecognizerSettings`, `PPAustraliaDLBackRecognizerSettings`, `PPAustraliaDLFrontRecognizerSettings` and `PPEudlRecognizerSettings`:
        - use `fullDocumentImageDPI` on the corresponding recognizer settings

- Minor API changes
    - removed `imageDPI` property on `PPTemplatingRecognizerSettings`        

- Improvements in ID scanning performance:
    - improved reading of Malaysian MyKad address        

## 2.13.0

- Updates and additions
    - added support for scanning front and back side of Polish ID - use `PPPolishIDFrontRecognizerSettings`, `PolishIDBackRecognizerSettings` and `PPPolishIDCombinedRecognizerSettings`
    - new document specification presets in `PPDocumentPreset` enum:  `PPDocumentPresetId1VerticalCard` and  `PPDocumentPresetId2VerticalCard` - use `[PPDocumentSpecification newFromPreset]` method to create document specification for detector
    - `PPEudlRecognizer` can return face image from the driver's license
    - warning for time limited license keys when using provided activities, custom UI integration or Direct API:
        - the goal is to prevent unintentional publishing of application to production with the demo license key that will expire
        - warning toast can be disabled by using `showLicenseKeyTimeLimitedWarning` property on `PPUiSettings`
    - added `PPMrtdSpecification` and method `setMrtdSpecifications` on `PPMrtdDetectorSettings`
        - setting `PPMrtdSpecification` on `PPMrtdDetectorSettings` will return results only for specified MRTD Documents
        - `PPMrtdSpecification` can be created using `PPMrtdPreset`: `PPMrtdPresetTd1, PPMrtdPresetTd2, PPMrtdPresetTd3`

- Minor API changes
    - `PPDocumentDetectorResult` does not contain information about screen orientation any more

- Improvements in ID scanning performance:
    - improved face detection in `DocumentFaceRecognizer`: stable detection is required to prevent returning of blurred images
    - improved reading of Malaysian `MyKad` documents:
    - improved reading and parsing of address fields: previously recognizer was unable to read some documents because of the expected address format
    - improved reading of Malaysian visas and work permits
    - better reading of dates on Australian Driver's Licence

## 2.12.0

- Updates and additions
    - Added Australian Driver Licence Recognizer `PPAustraliaDLFrontRecognizerResult` and `PPAustraliaDLFrontRecognizerSettings` for state Victoria
    - Added Swiss ID Back Recognizer `PPSwissIDBackRecognizerResult` and `PPSwissIDBackRecognizerSettings`
    - Added Swiss ID Front Recognizer `PPSwissIDFrontRecognizerResult` and `PPSwissIDFrontRecognizerSettings`
    - Added reading of mirrored QR codes
    - Added `PPMrzFilter` protocol and delegate `mrzFilter` on `PPMrtdRecognizerSettings`
        - Determines whether document should be processed or it is filtered out, based on its MRZ (Machine Readable Zone)
    - Introduced `GlareDetector` which is by default used in all recognizers whose settings implement `GlareDetectorOptions`:
        - When glare is detected, OCR will not be performed on the affected document position to prevent errors in the extracted data
        - If the glare detector is used and obtaining of glare metadata is enabled in `MetadataSettings`
        - Glare detector can be disabled by using `detectGlare` property on the recognizer settings
    - Added `PPQuadDetectorResultWithSize` which inherits existing `PPQuadDetectorResult`
        - It's subclasses are `PPDocumentDetectorResult` and `PPMrtdDetectorResult`
        - Returns information about physical size (height) in inches of the detected location when physical size is known

- Minor API changes
    - `PPBlinkOcrRecognizerResult` and `PPBlinkOcrRecognizerSettings` are now deprecated. Use `PPDetectorRecognizerResult` and `PPDetectorRecognizerSettings` for templating or `PPBlinkInputRecognizerResult` and `PPBlinkInputRecognizerSettings` for segment scan
    - removed option to scan 1D Code39 and Code128 barcodes on US Driver's licenses that contain those barcodes alongside PDF417 barcode

- Bugfixes:
    - Fixed crash which sometimes happened while scanning MRTD documents
    - Fixed returning valid data for MRZ based recognizers when not all fields outside MRZ have been scanned
    - Fixed crash in QR code which happened periodically in all recognizers
    - Fixed autorotation of overlay view controller 
    - Fixed scanning return result type of `PPDetectorRecognizerSettings` when initialized with `PPMrtdDetectorSettings` - returning `PPMrtdDetectorResult`

- Improvements in ID scanning performance:
    - Date parsing improvements
    - Better extraction of fields on back side of the Croatian ID card
    - Improved reading of issuing authority on Croatian ID back side
    - Improved USDLRecognizer - added support for new USDL standard

## 2.11.0

- Updates and additions
    - Added Austrian Passport Recognizer `PPAusPassportRecognizerResult` and `PPAusPassportRecognizerSettings`
    - Added Swiss Passport Recognizer `PPSwissPassportRecognizerResult` and `PPSwissPassportRecognizerSettings`
    - Added support for scanning MRZ on Mexican voters card
    - Added support for reading Croatian ID with permanent DateOfExpiry in `PPCroIDFrontRecognizerResult` and `PPCroIDCombinedRecognizerResult` with BOOL property `isDocumentDateOfExpiryPermanent`
    - Added combining data from MRZ and fields in Austrian passport through `PPAusIDCombinedRecognizerResult` and `PPAusIDCombinedRecognizerSettings`

- Bugfixes:
    - Fixed crash which sometimes happened while scanning MRTD documents

- Improvements in ID scanning performance:
    - Improved scanning of IKad addresses
    - Improved reading of Croatian ID Address field
    - Improved reading of Croatian ID IssuedBy field 

## 2.10.0

- Updates and additions:
    - Added Barcode Recognizer `PPBarcodeRecognizerResult` and `PPBarcodeRecognizerSettings`
    - Deprecated `PPAztecRecognizerResult` and `PPAztecRecognizerSettings`. Use Barcode Recognizer
    - Deprecated `PPBarDecoderRecognizerResult` and `PPBarDecoderRecognizerSettings`. Use Barcode Recognizer
    - Deprecated `PPZXingRecognizerResult` and `PPZXingRecognizerSettings`. Use Barcode Recognizer
    - Added creation of customized build of framework. If your final app size is too large, you can create a customised build of MicroBlink.framework and MicroBlink.bundle which will contain only features and resources that you really need. You can see detailed explanation at [Creating customized build of BlinkID SDK](https://github.com/BlinkID/blinkid-ios/wiki/Creating-customized-build)
    - Added US Driver's license Combined Recognizer `PPUsdlCombinedRecognizerResult` and `PPUsdlCombinedRecognizerSettings` 
    - Added Austrian ID Combined Recognizer `PPAusIDCombinedRecognizerResult` and `PPAusIDCombinedRecognizerSettings`
    - Added Czech ID Combined Recognizer `PPCzIDCombinedRecognizerResult` and `PPCzIDCombinedRecognizerSettings`
    - Added Serbian ID Combined Recognizer `PPSerbianIDCombinedRecognizerResult` and `PPSerbianIDCombinedRecognizerSettings`
    - Added Singapore ID Combined Recognizer `PPSingaporeIDCombinedRecognizerResult` and `PPSingaporeIDCombinedRecognizerSettings`
    - Added Slovakian ID Combined Recognizer `PPSlovakIDCombinedRecognizerResult` and `PPSlovakIDCombinedRecognizerSettings`
    - Added Slovenian ID Combined Recognizer `PPSlovenianIDCombinedRecognizerResult` and `PPSlovenianIDCombinedRecognizerSettings`
    - Added MRTD Combined Recognizer `PPMrtdCombinedRecognizerResult` and `PPMrtdCombinedRecognizerSettings`
    - Added VIN Recognizer `PPVinRecognizerResult` and `PPVinRecognizerSettings`
    - Added `nonMRZNationality` and `nonMRZSex` properties to Romanian ID Recognizer for getting sex and nationality outside MRZ
    - Added support for long addresses and employer names for iKad
    - `extractAddress` property in `PPSlovakIDBackRecognizerSettings` is now removed since previously wasn't used
    - Added `extractDocumentNumber` property in `PPSlovakIDFrontRecognizerSettings` for defining if issuing document number should be extracted from Slovakian ID 
    - Added to Slovakian ID Combined Settings options properties:
        - `extractSex`
        - `extractNationality`
        - `extractDateOfBirth`
        - `extractDateOfExpiry`
        - `extractDateOfIssue`
        - `extractIssuedBy`
        - `extractDocumentNumber`
        - `extractSurnameAtBirth`
        - `extractPlaceOfBirth`
        - `extractSpecialRemarks`

- Bugfixes:
    - Fixed reading positions of ID elements on Slovakian ID card
    - Fixed reading positions of ID elements on Singapore ID card

- Improvements in ID scanning performance:
    - Always read personal number field on front side of Slovakian ID card
    - Improved reading precision of address, place of birth, last name and issuing authority on Slovakian ID card
    - Improved reading of name and blood type on Singapore ID card
    - Improved reading of pdf417 barcodes having width:height bar aspect ratio less than 2:1

## 2.9.0

- Updates and additions:
    - Microblink.framework is now a dynamic framework. The change is introduced because of the following reasons:
        - isolation of code
        - smaller binary size - roughly 38%
    - Improved Screen shown when Camera permission is not granted:
        - fixed crash which happened on tap anywhere on screen
        - close button can now be removed (for example, if the scanning screen is inside `UINavigationController` instance)
        - Header is now public so you can instantiate that class if needed
    - Updated PPUiSettings with new features:
        - flag `showStatusBar` which you can use to show or hide status bar on camera screen 
        - flag `showCloseButton` which you can use to show or hide close button on camera screen. By default it's presented, but when inside `UINavigationController` it should be hidden
        - flat `showTorchButton` which you can use to show or hide torch button on camera screen.
    - Deprecated `PPHelpDisplayMode`. You should replace it with a custom logic for presenting help inside the application using the SDK.
    - Renamed internal extension method with namespace so that they don't interfere with third party libraries
    - Added standard tap to focus overlay subview in all default OverlayViewControllers. Also added it as a public header.
    - PPScanningViewController now has a simple method to turn on torch
    - Simplified `PPOcrLayout` class (removed properties which were not used)
    - Updated PPTopUpOcrParserFactory with new feature:
        - flag `returnCodeWithoutPrefix` which does not return *digits* prefix and # at the end of scanned ussd code
    - Updated PPMrtdRecognizerSettings with new feature:
        - flag `allowUnverifiedResults` which allow obtaining results with incorrect check digits

- Bugfixes:
    - Fixed case sensitivity in class & file naming
    - Fixed issue which sometimes caused scanning not to be started when the user is asked for camera permission (first run of the app)
    - Fixed rare crash which Camera paused label UI being updated on background thread
    - Fixed incorrect handling of camera mirror when using front facing camera
    - Fixed crash which sometimes happened when presenting help screens (if `PPHelpDisplayModeAlways` or `PPHelpDisplayModeFirstRun` were used)

 - Improvements in ID scanning performance:
     - added PPGermanIDCombinedRecognizer which enables reading of all data contained on German passports, old and new IDs 
     - Improvements in MRTD scanning:
        - WSA (World Goverment of World Citizens) added as valid country code when parsing MRZ 
    - Added option of encoding images of MRZ and full document in Machine readable travel documents and encoding of images in DocumentFaceRecognizer
    - Handling names containing dashes and extra long names inside combined recognizers     
    
## 2.8.0

- Improvements in iOS SDK: 
    - Reduced library size by more than 20%
    - Fixed case sensitivity in class & file naming
    - ID result classes which have Date fields now return both parsed `NSDate` and raw `NSString`
- Improvements in scanning:
    - TopUp scanning improvements
    - Restructured German ID recognizers into:
        - GermanIDFrontRecognizer, for scanning front side of the new German ID
        - GermanIDBackRecognizer, for scanning back side of the new German ID
        - GermanOldIDRecognizer, for scanning front side of the old German ID
        - GermanPassportRecognizer, for scanning front side of the German Passport
    - Splitting address on new German IDs to ZIP code, city, street and house number
    - Added name and surname dictionaries for the German ID front side recognizer which improves the scanning performance
    - MyKadRecognizer now knows how to split address to street, ZIP code, city and state
    - Improved CroIDCombinedRecognizer, which can scan both sides of the ID consecutively 
    - Added support for polish IBAN without PL prefix in PPIbanParser
    - Improvements in CroID scanning, use multiple scans to boost confidence
- Improvements in Samples:
    - Added MicroBlinkDynamic sample which packages our static library into a dynamic framework
    - Added libz to all samples to prevent linker errors (caused by slimming down the SDK)

## 2.7.1

- Fixed wrong Assertion which didn't allow usage of custom Resources bundle. 
- Fixed internal bug which caused crashes if `PPCoordinator applySettings` was called with the same Recognizer settings (this is a very rare use case)
- Added working license key in pdf417-sample for Aztec scanning

## 2.7.0

- Added Romanian ID Front recognizer for scanning Romanian IDs.
- Added SimCardRecognizer for scanning barcodes on Sim Cards
- Added AztecRecognizer with state of the art Aztec barcode reading. This can be used for scanning digital boarding passes, train tickets, and many more use cases.
- Added play success sound method to `PPScanningViewController` protocol
- Added designated initializers to all `PPOcrParserFactory` objects
- Added ID2 preset for creating DocumentSpecifications
- Improved getters for image names which are used to get Images of the ID documents
    - they are now static methods instead of instance properties
- Improved `MRTDRecognizer` with better support for Arab MRZ
- Improved TopUpParser
    - Added Generic parsing in TopUpOcrParser
- Updated `CroatianIDFrontSideRecognizer`: returning sex as written on front side of a document
- Fixed issue with Direct API which disabled processing
- Fixed issue with blurred camera display when `PPCoordinator` instance was reused between consecutive scanning sessions
- Fixed crashed which happened when multiple instances of `PPCoordinator` were used simultaneously (one being terminated and one starting recognition). This most commonly happened when after scanning session, a new view controller was pushed to a Navigation View Controller, when the user repeated the procedure a number of times (five or more).
- Updated sample apps:
    - Updated Detector-sample to use frame quality so that dewarped images are the sharpest
    - Updated BlinkID-sample and BlinkID-Swift-sample with easier obtaining of dewarped images
    - Updated DirectAPI-sample with support for OCR in all device orientations
    - Updated pdf417-sample with support for Aztec scanning
    - Added AutodetectID-sample which uses DocumentFace recognizer
- Internal switch to new build system using cmake. This allows faster deployments and easier updates in the future. 

## 2.6.0

- Added CroIDCombined recognizer which can scan both sides consecutively
- Added DocumentFace recognizer which can be used to get the image of the ID document which contains a face
- Added FaceDetector feature which can now be used in DetectorRecognizer.
- Added support for extracting place of birth on old German IDs
- Added property allowResultForEveryFrame in PPScanSettings which can be used when using Direct API to force calling didOutputResults: callback for every frame
- Added feature to enable frame quality estimation when using Direct API (by exposing property estimateFrameQuality)
- Added support for scanning IBAN from Georgia in IbanParser
- Added logging of the SDK name when the license key is invalid for easier troubleshooting
- Added Belgian account number check to IBAN parser
- Added scaling of the default viewfinder in ID scanning overlay view
- Added a property which you can use to set a custom location for resources. For example, if you would like to avoid using Microblink.bundle as resources bundle, you can set a different one in PPSettings object.
- Improved quality of German ID address recognition
- Updated - Singapore ID recognizer has now split in two recognizers - one for front and one for back side
- Fixed Date of Birth scanning issue in MyKad Recognizer
- Fixed MRTD returning payment data with verified = false when mrtdSettings.allowUnverified(false)
- Fixed bug in MRTD recognizer where mrtd image were not returned although scanning was successful
- Fixed crash when Single dispatch queue was used for processing
- Fixed frame quality issue in PPimageMetadata. Previously it was always nan if used after image getter.
- Fixed Torch button on default camera overlays. Previously it never changed state after it was turned on.
- Fixed help display mode "First run", which previously didn't work
- Fixed crash when the user tapped anywhere on the view controller presented when camera permission wasn't allowed
- Fixed warning message when language is set to something other than @en, @de and @fr and @cro
- Fixed crash on start in swift if custom UI was used to handle detector results
- Fixed a problem which caused internal recognizer state not to be reset when using the scanner for the second time with the same PPCoordinator instance
- Fixed ocrLayout getter in PPBlinkOcrRecognizer which previously returned nil
- Fixed an issue which caused camera settings to be reset each time PPCoordinator's applySettings method was called. This issue manifested, for example, by automatically turning off torch after successful scan in SegmentScan.
- Fixed redundant log warnings in setting language ("Trying to set language to nil, returning") and Camera manager ("Should not have been observing autofocus")

## 2.5.1

- Updated default overlay UI for ID scanning
- Fixed nullability annotations in result classes. Now, wherever the `nil`value is allowed, it means no data exists on the scanned document. If an empty string `@""` is returned, this means the field exist, but it's empty. 
- Croatian ID scanning now uses dictionary for issuing authority for higher accuracy
- Improved generic Amount and IBAN parsers

## 2.5.0
- US Driver's Licence:
    - fixed parsing of Virgin Islands DL
    - added support for Arkansas DL
    - added support for new South Carolina DL
- Malaysian ID:
    - added support for returning face image
    - fixed wrong parsing of birth date
    - added support for scanning Malaysian iKad documents
- `PPDateOcrParser` returns result as `NSDate` object and as original date `NSString`
- added methods `specificParsedResultForName:` and `specificParsedResultForName:parserGroup:` to `PPTemplatingRecognizerResult` (`PPBlinkOcrRecognizerResult `) which returns specific parser results, e.g. `NSDate` for `PPDateOcrParser`
- added support for scanning front and back side of Serbian ID cards
- improved IBAN parser
- `PPMrtdRecognizerResult` now returns date of expiry and date of birth as `NSDate` instead of `NSString`
- all recognizer results (classes that derive `PPRecognizerResult`) now have annotated nullability for their getters. Some of them used to assume non-null, while still returning `nil` sometimes. This has now been corrected and all getters are `_Nullable`

## 2.4.0

- iOS updates:
	- Aded Slovenian ID recognizer
	- Added parser for mobile coupons
	- Added frame quality property to PPImageMetadata
- iOS bugfixes:
	- Fixed issue where Templating API wasn't working as expected on some devices.

## 2.3.0

- iOS updates:
	- Added German ID recognizer
	- Added Slovakian ID recognizer
	- Improved performance of Croatian ID recognizer

## 2.2.1

- iOS fixes:
	- Fixed problems with string localizations
	
## 2.2.1

- iOS fixes:
	- CFBundleSUpportedPlatforms removed from Info.plist files
	- Applying affine transformation to `PPQuadrangle` now correctly assigns points.
	- When using both Direct API and `PPCameraCoordinator`, scanning results will now be correctly outputted to `PPCoordinatorDelegate` and `PPScanningDelegate` respectively
	- Fixed crashes related to camera permissions and added dummy view when camera permission is disabled
	- Fixed issues related to topLayoutGuide on iOS6
	- Improved performance of CroID recognizers
	- USDL elements can now be separated by \r
	- Improved performance of Date parser

## 2.2.0

- iOS updates:
	- Added recognizer for Singapore ID
	- Added recognizer for Austrian ID
	- Added recognizer for Czech ID
	
- iOS bugfixes:
	- PPOcrEngineOptions are now applyed correctly when set

## 2.1.0

- iOS updates:

	- Added option to mirror camera frames in 'PPCameraSettings'
	- Added VIN parser
	
- iOS bugfixes
	- Fixed deadlock when 'processImage:' is called from main thread

## 2.0.0

- BlinkID now includes BlinkOCR and all it's features

- iOS updates:

	- Implemented `PPCameraCoordinator`. `PPCameraCoordinator` assumes the role of `PPCoordinator` from previous versions while new `PPCoordinator` is used for Direct API (image processing without camera out management).
	- Increased speed of scanning for barcode type recognizers.
	- Implemented `PPImage`. When using Direct API you can wrap `UIImage` and `CMSampleBufferRef` into `PPImage` to ensure optimal performance.
	- Improved performance of Direct API. In addition, you can now use Direct API with your own camera management without any performance drawbacks.
	- Added method `isCameraPaused` to `PPScanningViewController`.
	- Added option to fllip input images upside down for processing with `cameraFlipped` property of `PPCameraSettings`.
	- Implemented `PPViewControllerFactory` for managing creation of `PPScanningViewController` objects.
	- `PPImageMetadata` now contains `PPImageMetadataType` property, which describes which image type was outputted.

- Implemented templating API

    - Templating API allows creation of custom document scanners, linking specific parsers to specific locations on detected documents
	
- iOS bugfixes:
	- New Direct API fixed possible deadlocks when sending large amounts of data

## 1.4.0

- iOS bugfixes:

    - Fixed possible deadlock in some cases when MRTD documents are scanned.
    - Fixed issue with OCR speed on arm7 devices when Accelerate framework was used.
    - Fixed incorrect returning of Address and License number in UKDL scanning.
    
- iOS updates:
    
    - PPOverlayViewController changed the way Overlay Subviews are added to the view hierarchy. Instead of calling `addOverlaySubview:` (which automatically added a view to view hierarachy), you now need to call `registerOverlaySubview:` (which registers subview for scanning events), and manually add subview to view hierarchy using `addSubview:` method. This change gives you more flexibility for adding views and managing autolayout and autoresizing masks.

    - Localization Macros MB_LOCALIZED and MB_LOCALIZED_FORMAT can now be overriden in your app to provide completely custom localization mechanisms.
    
    - Dramatically increased OCR engine initialization speed

    - Increased speed of scanning cancellation when Cancel button is pressed.
    
- ID scanning improvements

    - Added EUDL recognizer (replaced UKDL recognizer). EUDL is capable of automatically detecting various EU Drivers licenses. Currently it works only on German and UK DLs.
    - Fixed issue with 0 and O misclassifications in MRTD recognition
    - Added support for Austrian MRTD ID documents

- Internal changes:

    - Implementeded Templating API for easier implementation of new document types
    - Implemented Face detection
    - Implemented support for Eastern Arabic numeral characters

## 1.3.0

- Added better integration for Swift

    - Added Nullability Attributes
    - Added modulemap file
    - Added sample app in Swift
        
- Added recognizers for scanning barcodes

    - for scanning PDF417 barcodes, use PPPdf417Recognizer
    - for scanning Code128 and Code39 barcodes, use PPBarDecoderRecognizer
    - for scanning QR codes, and other barcode types, use PPZxingRecognizer
        
- Refactored `PPMetadataSettings` 

    - Added debug metadata settings for debugging payslip detection and image processing
    - `successfulScanFrame` renamed to `successfulFrame`
    - `currentVideoFrame` renamed to `currentFrame`
    
- Exposed `PPModernViewfinderOverlaySubview` overlay subview class in public headers. This enables you to more easily recreate default overlay UI in your custom Overlay view controllers.

- Added *Detector API*, a completely new feature which enables you to detect various document types on images. Detector API allows two types of document detections

    - MRTD detection (based on OCR line detection, for MRTD documents like passports, visas, ...)
    - Document Detection (based on edge detection, for ID cards, plastic cards, credit cards, ...)
    
- in `PPCoordinator`, renamed method `isScanningUnsupported:` to `isScanningUnsupportedForCameraType:error:`. This was introduced to provide more granularity in checking if scanning is supported.

- Fixed issues in obtaining images in scanning, most notably in MyKad scanning.

- Fixed issues with Direct API processing of UIImages in some orientations

- Fixed issues with scanning MRZ lines on arm7 devices.

## 1.2.0

- Added recognition of Malysian ID cards (MyKads). To use MyKad recognition initialize the scanning library using `PPMyKadRecognizerSettings`

- Improvements in UK drivers license recognition. BlinkID is now tested on many more UKDL samples and yields much higher recognition rate.

- Improvements in MRTD recognition. Errors such as '0' and 'O' confusions should no longer happen. Improved MRTD document detection algorithm, which now makes old "fixed" recognition redundant. Because of that, the feature to define `mrtdRoi` is now removed.

- Added feature to obtain cropped and trimmed image of the whole MRTD document.

- Fixed several issues in USDL parsing
        - implemented special cases for barcodes which don't have keys according to the AAMVA version written in the barcode
        - implemented heuristics for extraction of firstName, middleName, lastName, address, and other fields, if they can be determined based on the other fields.

- Bugfixes and tweaks in camera management code
        - fixed potential deadlock when multiple instances of `PPCoordinator` objects are instantiated.
        - exiting from the scanning when user presses "cancel" button is now faster

- Renamed `PPUkdlRecognizerResult`'s property `ownerAdress` to `ownerAddress` (fixed typo)

## 1.1.0

- `PPMrtdRecognizerSettings` now sets `detectMachineReadableZonePosition` to YES by default. This means MRZ detection will work by default, meaning you no longer need to position the ID card precisely inside the frame shown in the UI.

- Added full support for parsing MRTD documents according to [ICAO Document 9303](http://www.icao.int/Security/mrtd/pages/Document9303.aspx) standard)

- Added support for scanning VISAs, and Belgian ID documents.

- `PPMrtdRecognizerSettings` now has a new settings `allowUnparsedResults` (default: NO), which you can use to get raw OCR results of the MRZ text, even if BlinkID parsing didn't manage to parse the text (this can happen since MRZ isn't always formatted according to [ICAO Document 9303](http://www.icao.int/Security/mrtd/pages/Document9303.aspx) standard)

    - When YES, `MrtdRecognizerResult` will be returned with `isParsed` property set to NO, and with `rawOcrLayout` property set to the `PPOcrLayout` object which was the result of the OCR process.

    - You should be careful when this property is set to YES, since obtained `OcrLayout` can contain OCR errors (for example (0 <-> O, 2 <-> Z, etc.). If you set this to YES, then you need to perform your own parsing and error correction.

    - If you set this to YES, we suggest the following approach in your result callback
         - obtain mrtdResult
         - if [mrtdResult isParsed]
             - present result and return
        - else if mrtdResult can be parsed with your custom parsing algorithm
             - present your custom results and return
        - else continue scanning since MRTD result cannot be parsed at all

- Improved video frame quality detection: now only the sharpest and the most focused frames are being processed. This improves quality of the results, but at a slight expense of processing time

- Frame quality estimation can now be enabled using `PPScanSettings frameQualityEstimationMode` property:
    - when set to `PPFrameQualityEstimationModeOn`, frame quality estimation is always enabled
    - when set to `PPFrameQualityEstimationModeOff`, frame quality estimation is always disabled
    - when set to `PPFrameQualityEstimationModeDefault`, frame quality estimation is enabled internally, if the SDK determines it makes sense

- iOS 9 introduced new app multitasking features Split View and Slide Over. When the scanner is on screen and one of those features are used, iOS automatically pauses the Camera (this behaviour is default as of iOS 9 beta 5). This SDK version introduces new setting in `PPUISettings` class, called `cameraPausedView`, where you can define the `UIView` which is presented centered on screen when this happens.

- Known issue on iOS 9: if you use Autorotate overlay feature (`settings.uiSetttings.autorotateOverlay`), present `PPScanningViewController` as a modal view controller, and support Split View iOS 9 feature, then autorotation of camera overlays isn't correct. The best way is to opt-out of Split View feature, and wait for SDK fix when iOS 9 comes out of beta.

- `PPScanningViewController` methods `pauseScanning`, `isScanningPaused`, and `resumeScanningAndResetState:` should now be called only from Main thread, and they are effective immediately. E.g., if `pauseScanning` is called and there is a video frame being processed, result of processing of that frame will be discarded, if `resumeScanningAndResetState:` isn't called in the meantime.

- Added support for `PPCameraPresetPhoto` camera preset. Use this if you need the same zoom level as in iOS Camera app. The resolution for video feed when using this preset is the same as devices screen resolution.

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
