## 6.6.0

### IDBarcodeRecognizer
- `MBIdBarcodeRecognizer` is now deprecated as it is no longer maintained and all of its functionalities are available with `MBBlinkIdSingleSideRecognizer` and `MBBlinkIdMultiSideRecognizer`
    -  To achieve the same `IDBarcodeRecognizer` behavior with the BlinkID generic recognizers, the `RecognitionModeFilter` must be limited to only the `BarcodeId` recognition mode:
    ```
        self.blinkIdRecognizer = MBBlinkIdSingleSideRecognizer()
        
        let recognitionModeFilter = MBRecognitionModeFilter()
        recognitionModeFilter.enableFullDocumentRecognition = false
        recognitionModeFilter.enableMrzId = false
        recognitionModeFilter.enableMrzVisa = false
        recognitionModeFilter.enableMrzPassport = false
        recognitionModeFilter.enablePhotoId = false
        recognitionModeFilter.enableBarcodeId = true
        
        self.blinkIdRecognizer?.recognitionModeFilter = recognitionModeFilter
     ```
    - The results are obtained by directly using the `result` or `barcodeResult` property from the recognizer result:
    
     ```
        let result = self.blinkIdRecognizer?.result
        let firstName = result?.firstName
        //or
        let barcodeResult = self.blinkIdRecognizer?.result.barcodeResult
        let barcodeFirstName = barcodeResult?.firstName
    ```

## 6.5.1

- No changes

## 6.5.0

- No changes

## 6.4.0

- No changes

## 6.3.0

- No changes

## 6.2.1

- No changes

## 6.2.0

- No changes

## 6.1.2

- No changes

## 6.1.1

- No changes

## 6.1.0

## Breaking changes
### Made `BlinkIdMultiSideRecognizerDelegate` and `BlinkIdSingleSideRecognizerDelegate` methods non-optional
- If you implemented only some of the methods present in one (or both) of these delegates but would like to keep default behaviour with the remaining methods you can use our default methods found on an instance of `BlinkIdOverlayViewController`

## 6.0.0

## Breaking changes
### Renamed the framework
- The framework's name changed from Microblink to BlinkID
    - You can replace occurrences of Microblink with BlinkID (e.g. change `import Microblink` to `import BlinkID`)
​
### Renaming of recognizers
- One very important change came when it comes to using BlinkID recognizers - they have been renamed to make them more understandable for new developers and users:
	- Basic single-sided recognizer, which used to be named `BlinkIdRecognizer`, is now called __BlinkIdSingleSideRecognizer__, and should be used for scanning one-sided documents or if you wish to capture only the front side of it
	- More advanced recognizer, which used to be named `BlinkIdCombinedRecognizer`, is now called __BlinkIdMultiSideRecognizer__, and should be used for scanning the documents which have information that you want to extract on more than one side
    - All other classes, protocols and APIs, referenced from `BlinkIdSingleSideRecognizer` or `BlinkIdMultiSideRecognizer`, were renamed in simmilar fashion:
        - `BlinkIdRecognizerResult` become `BlinkIdSingleSideRecognizerResult`
        - `BlinkIdRecognizerDelegate` become `BlinkIdSingleSideRecognizerDelegate`
        - `BlinkIdCombinedRecognizerResult` become `BlinkIdMultiSideRecognizerResult`
        - `BlinkIdCombinedRecognizerDelegate` become `BlinkIdMultiSideRecognizerDelegate`
        - `onCombinedImageAvailable:` become `onMultiSideImageAvailable:`
        - `onCombinedDocumentSupportStatus:` become `onMultiSideDocumentSupportStatus:`
        - `combinedClassInfoFilter:` become `multiSideClassInfoFilter:`
        - `onCombinedBarcodeScanningStarted` become `onMultiSideBarcodeScanningStarted:`
​
### Other API changes
- We introduced new classes: `MBStringResult`, `MBDate`, and `MBDateResult` in order to support multiple alphabets. If a recognizer supports multiple alphabets, its result class (e.g., `BlinkIdSingleSideRecognizerResult`, `BlinkIdMultiSideRecognizerResult`) will return `MBStringResult` for APIs that previously returned `NSString`
- If a recognizer doesn't support multiple alphabets, it now returns `Date` for APIs that previously returned `DateResult`
- `DataMatchDetailedInfo` class is removed and replaced by `DataMatchResult`
​
### Minimum supported SDK version
- iOS deployment target is now set to `13.0`, meaning that devices like iPhone 6 / 6 Plus or iPad mini 3 are no longer supported by BlinkID SDK.

​
## Improvements
​
### Scanning in less steps
- In *BlinkID v6.0.0* we added convenience API which enables scanning in less steps.
​
#####Example in Swift:
```swift
let recognizerRunneViewController = MBViewControllerFactory.recognizerRunnerViewController(
            withResult: { result in
                if result.resultState != .valid {
                    return
                }
                print(result.description)
        },
            closeButtonTapped: {
                dismiss(animated: true, completion: nil)
        })

present(recognizerRunneViewController, animated: true, completion: nil)
```
- It is recommended to check the result status as shown in order to avoid crashes before doing something with the result itself.
​
​
###Added onboarding screens
- New onboarding screens have been added to the SDK, providing the users with a small tutorial on how to scan properly; this will potentially improve the successful scan rate.
- Onboarding consists of two parts:
	- Introduction dialog - appears as soon as the user starts the scanning process in the shape of an overlay dialog with an instruction image and an instruction text, which can be dismissed by a press of a button
	- Onboarding dialog - appears at a press of an onboarding help button, a small FAB located in the bottom right corner, which has an additional tooltip with a "Need help?" text which is shown after a timeout or a tap on the screen
- By default, both the introduction and onboarding dialogs are set to show, and onboarding button tooltip delay is set to 12 seconds. These settings can be manually altered by configuring `BlinkIdUISettings` which are used as a parameter when the scanning function is called.
- Example - setting introduction dialog, onboarding dialog visibility, and tooltip delay time:
​
```swift
var blinkIdUISettings = BlinkIdUISettings(recognizerBundle)
blinkIdUISettings.showIntroductionDialog = false    // set to true by default
blinkIdUISettings.showOnboardingInfo = true         // set to true by default
blinkIdUISettings.onboardingButtonTooltipDelay = 8  // set to 12 by default (in seconds)
```
- Onboarding help button will only be shown if the onboarding dialog is set to true

## 5.20.1

- No changes

## 5.20.0

- No changes

## 5.19.0

- No changes

## 5.18.0

- No changes

## 5.17.0

- No changes

## 5.16.1

- No changes

## 5.16.0

- No changes

## 5.15.2

- No changes

## 5.15.1

### Changes to all Recognizers
- Added `toSignedJson` API
- Removed `toJson` API
- Removed `DigitalSignature*` protocols

## 5.15.0

- No changes

## 5.14.0

- No changes

## 5.13.0

- No changes

## 5.12.0

- No changes

## 5.11.0

### Minor API changes:

- Renamed MicroblinkApp `instance` to `sharedInstance` (Objective C) / `shared` (Swift)

## 5.10.0

### New features:

* We have full support for Apple Silicon!

### Framework formats and architectures:

* Use `.xcframework` as we now have full Apple Silicon and Intel support.
* We are still supporting `fat binary .framework` format, but we’ve removed simulator slices from it.

### Carthage:

* Carthage still doesn't support `binary .xcframework`, so there is no support for simulator slices anymore.

### Minor API changes:

- We've replaced `Using time-limited license!` warning with `Using trial license!` warning. The warning message is displayed when using a trial license key. To disable it, use `showTrialLicenseWarning` on `MBCMicroblinkSDK`.

## 5.9.0

### Major API changes:

- We've added an error callback when setting license keys on `MBMicroblinkSDK`
	- You will be getting error callback containing the reason why you could not unlock the SDK - see `MBLicenseError`

### Minor API changes:

- Swift:
	- All `unsigned integers` are now `Int`

### Note on ARM Macs

- We are supporting `ARM64 Device` slice through our `.xcframework` format.
- We are still working on supporting the `ARM64 Simulator` slice for newly released ARM Macs. We will update our SDK with `ARM64 Simulator` support as soon as it’s out.

### iOS Version support change:

-  We are no longer supporting **iOS 8**.

### Cocapods support change:

- We are updating our Cocoapods with `.xcframework` format from now on. Please download [Cocoapods 1.10.0](https://github.com/CocoaPods/CocoaPods/releases/tag/1.10.0) or newer to use our SDK.

### Known issues:

- SDK crashes on armv7 devices if bitcode is enabled. We are working on it.

## 5.8.0

### Deprecated recognizers
* We have deprecated following recognizers:
	* `MBDocumentFaceRecognizer`
	* `MBMrtdRecognizer`
		* **Use `MBBlinkIdRecognizer` instead**
	* `MBMrtdCombinedRecognizer`
	* `MBPassportRecognizer`
	* `MBVisaRecognizer`
		* **Use `MBBlinkIdRecognizer` or `MBBlinkIdCombinedRecongizer` instead**
	* `MBUsdlRecognizer`
		* **Use `MBIdBarcodeRecognizer` instead**

### Major API change:
* We added `errorCallback` on `MBMicroblinkSDK` methods which needs to be implemented for properly setting up the license key.

## 5.7.1

- No changes

## 5.7.0

### Minor API changes:

- We have made some changes to the **MBBlinkIdRecognizer** and **MBBlinkIdCombinedRecognizer**:
	- We renamed `MBDocumentImageMoireStatus` to `MBImageAnalysisDetectionStatus`.
	- We grouped the `conditions` member from the results with the `MBDriverLicenseDetailedInfo` structure.
- We renamed `MBRecogitionMode` to `MBRecognitionDebugMode` in `MBRecognizerCollection`.
- Swift:
	- We renamed all `sharedInstance` to `shared`.
	- All enums are now `Int`.

## 5.6.0

- We moved `MBBlinkIdRecognizerResult` members `colorStatus` and `moireStatus` to the result's `imageAnalysisResult` (`frontImageAnalysisResult` and `backImageAnalysisResult` in `MBBlinkIDCombinedRecognizerResult`).
- We moved all resources inside framework, we are not shipping `Microblink.bundle` anymore

## 5.5.0

- No changes

## 5.4.1

- No changes

## 5.4.0

- No changes

## 5.3.0

- No changes

## 5.2.0

- No changes

## 5.1.1

- Minor API changes:
    - `MBBlinkIdRecognizer` and `MBBlinkIdCombinedRecognizer`
        - methods `setDewarpedImageDelegate` and `setClassifierDelegate` are now 
            properties `dewarpedImageDelegate` and `classifierDelegate`

## 5.1.0

- No changes

## 5.0.2

- Minor API changes:
    - methods `pauseScanning` and `resumeScanningAndResetState` in `MBRecognizerRunnerViewController` do not return anymore `BOOL`
        - use `isScanningPaused` to check if scanning is paused

## 5.0.1

- No changes

## 5.0.0

- Major API changes:

    - removed all country specific recognizers

    - `MBBlinkIdRecognizer` and `MBBlinkIdCombinedRecognizer` are recognizers that classify and extract data from all country specific recognizers available in 4.x.x versions

    - not country specific recognizers that are staying are:
        - `MBPassportRecognizer`
        - `MBVisaRecognizer`
        - `MBDocumentFaceRecognizer`
        - `MBMrtdRecognizer`
        - `MBMrtdCombinedRecognizer`
        - `MBUsdlRecognizer`
        - `MBUsdlCombinedRecognizer`

    - parsers and detectors are removed from this version onward

    - Swift Module has been renamed from `MicroBlink` to `Microblink`

        - this will cause Swift project to crash at compile time so please do `import Microblink` from now on

## 4.11.0

- Minor API changes:
    - `MBDocumentFaceRecognizer` - removed the `tryBothOrientations` option (improved scan in all directions is enabled by default)

## 4.10.0

- No changes

## 4.9.1

- No changes

## 4.9.0

- Minor API changes:
    - `partialRecognitionTimeout` in `MBRecognizerCollection` default value has been changed to **0** which means no timeout will be reported in which partial scanning results will be returned to the user

## 4.8.0

- Minor API changes:
    - all recognizers for Serbia have been removed from this version

    - fields that are *not* deprecated anymore:

        - Sweden DL - reference number
        - Ireland DL - driver number
        - Malaysia iKad - passport number
        - Hong Kong ID - commercial code

    - deprecated recocgnizer methods (they have been replaced with properties):

        - `MBUsdlRecognizerResult`:

            - `getField:(MBUsdlKeys)usdlKey`
            - `optionalElements`

    - added new recognizer properties:

        - `MBUsdlRecognizerResult`:
            - `firstName`
            - `lastName`
            - `fullName`
            - `address`
            - `dateOfBirth`
            - `dateOfIssue`
            - `dateOfExpiry`
            - `documentNumber`
            - `sex`
            - `restrictions`
            - `endorsements`
            - `vehicleClass`

        - `MBMrzResult`:
            - `sanitizedOpt1`
            - `sanitizedOpt2`
            - `sanitizedNationality`
            - `sanitizedIssuer`

    - renamed properties in `MBCzechiaCombinedRecognizerResult`:
        - `lastName` to `surname`
        - `firstName` to `givenNames`
        - `identityCardNumber` to `documentNumber`
        - `address` to `permanentStay`
        - `issuingAuthority` to `autohority`
        - `personalIdentificationNumber` to `personalNumber`

    - renamed properties in `MBGermanyCombinedRecognizerResult`:
        - `lastName` to `surname`
        - `firstName` to `givenNames`
        - `identityCardNumber` to `documentNumber`
        - `issuingAuthority` to `autohority`
        - `eyeColour` to `colourOfEyes`

    - renamed properties in `MBJordanCombinedRecognizerResult`:
        - `issuer` to `issuedBy`

    - renamed properties in `MBSlovakiaCombinedRecognizerResult`:
        - `identityCardNumber` to `documentNumber`
        - `issuingAuthority` to `issuedBy`
        - `personalIdentificationNumber` to `personalNumber`

    - renamed properties in `MBRomaniaIdFrontRecognizerResult`:
        - `lastName` to `surname`
        - `identityCardNumber` to `documentNumber`
        - `nonMrzNationality` to `nationality`
        - `nonMrzSex` to `sex`
        - `validFrom` to `dateOfIssue`
        - `validUntil` to `dateOfExpiry`
        - `cardNumber` is now part of `MrzResult` as `documentNumber`

    - renamed properties in `MBSloveniaCombinedRecognizerResult`:
        - `lastName` to `surname`
        - `firstName` to `givenNames`
        - `identityCardNumber` to `documentNumber`
        - `address` to `permanentStay`
        - `issuingAuthority` to `administrativeUnit`
        - `personalIdentificationNumber` to `pin`
        - `citizenship` to `nationality`

    - renamed properties in `MBSloveniaIdBackRecognizerResult`:
        - `issuingAuthority` to `administrativeUnit`

    - renamed properties in `MBPolandCombinedRecognizerResult`:
        - `issuer` to `issuedBy`

    - removed properties in `MBRomaniaIdFrontRecognizer`:
        - `idSeries`
        - `cnp`
        
## 4.7.0

- Minor API changes:
    - `MBPolandIdBackRecognizerResult` has property `mrzResult` that contains the results

    - removed mrz image extraction from `MBMrtdRecognizer` and `mrzImage` property in `MBMrtdRecognizerResult`

    - removed mrz image extraction from `MBMrtdCombinedRecognizer` and `mrzImage` property in `MBMrtdCombinedRecognizerResult`

    - removed glare detection from `MBMrtdCombinedRecognizer`

    - `MBPaymentCardFrontRecognizer`, `MBPaymentCardBackRecognizer` and `MBPaymentCardCombinedRecognizer` have been replaced with `MBBlinkCardRecognizer`
        - `MBBlinkCardRecognizer` is equivalent to `MBPaymentCardCombinedRecognizer`, to scan only front side set `extractCVV` to `false`

    - `MBElitePaymentCardFrontRecognizer`, `MBElitePaymentCardBackRecognizer` and `MBElitePaymentCardCombinedRecognizer` have been replaced with `MBBlinkCardEliteRecognizer`
        - `MBBlinkCardEliteRecognizer` is equivalent to `MBElitePaymentCardCombinedRecognizer`

## 4.6.0

- Minor API changes

    - removed `sex` and `signatureImage` properties from `MBMalaysiaMyKadBackRecognizer`

    - renamed properties in `MBCroatiaCombinedRecognizerResult`:
        - `identityCardNumber` to `documentNumber`
        - `address` to `residence`
        - `issuingAuthority` to `issuedBy`
        - `personalIdentificationNumber` to `oib`
        - `nonResident` to `documentForNonResident`

    - removed `mrzImage` from `MBMrtdCombinedRecognizer` and `MBMrtdCombinedRecognizerResult`

    - renamed properties in `MBAustraliaDlFrontRecognizerResult`:
        - `name` to `fullName`
        - `dateOfExpiry` to `licenceExpiry`

    - renamed `eyeColour` to `colourOfEyes` in `MBGermanyIdBackRecognizerResult`

    - recognizers that are deprecated:
        - `MBSerbiaIdBackRecognizer` and `MBSerbiaIdBackRecognizerResult`
        - `MBSerbiaIdFrontRecognizer` and `MBSerbiaIdFrontRecognizerResult`
        - `MBSerbiaCombinedRecognizer` and `MBSerbiaCombinedRecognizerResult`

    - all properties that are deprecated for recognizers:
        - `MBHongKongIdFrontRecognizerResult`:
            - `commercialCode`

        - `MBIndonesiaIdFrontRecognizerResult`:
            - `bloodType`
            - `district`
            - `kelDesa`
            - `rt`
            - `rw`

        - `MBNewZealandDlFrontRecognizerResult`:
            - `donorIndicator`
            - `cardVersion`

        - `MBMalaysiaMyKadBackRecognizerResult`:
            - `extendedNric`

        - `MBMexicoVoterIdFrontRecognizerResult`:
            - `electorKey`

        - `MBIrelandDlFrontRecognizerResult`:
            - `driverNumber`

        - `MBSwedenDlFrontRecognizerResult`:
            - `referenceNumber`

        - `MBMalaysiaIkadFrontRecognizerResult`:
            - `passportNumber`

        - `MBAustriaIdBackRecognizerResult`:
            - `principalResidence`
            - `height`
            - `eyeColour`

        - `MBAustriaPassportRecognizerResult`:
            - `height`

        - `MBGermanyIdBackRecognizerResult`:
            - `colourOfEyes`
            - `height`

        - `MBSwitzerlandIdBackRecognizerResult`:
            - `height`

        - `MBSwitzerlandPassportRecognizerResult`:
            - `height`

        - `MBSingaporeIdBackRecognizerResult`:
            - `bloodGroup`

        - `MBColombiaIdBackRecognizerResult`:
            - `bloodGroup`

        - `MBSwitzerlandPassportRecognizerResult`:
            - `height`

        - `MBPolandIdFrontRecognizerResult`:
            - `familyName`
            - `parentsGivenNames`

        - `MBMoroccoIdBackRecognizerResult`:
            - `fathersName`
            - `mothersName`

        - `MBRomaniaIdFrontRecognizerResult`:
            - `parentNames`

## 4.5.0

- Minor API changes
    - renamed `MBIkadRecognizer` to `MBMalaysiaIkadFrontRecognizer` and  methods in recognizer and its `Result`:
        - `expiryDate` to `dateOfExpiry`
        - `sex ` to `gender`

    - renamed `MBMyKadFrontRecogniezer` to `MBMalaysiaMyKadFrontRecognizer` and  methods in recognizer and its `Result`:
        - `ownerFullName ` to `fullName`
        - `ownerAddress ` to `fullAddress`
        - `addressStreet ` to `street`
        - `ownerAddressZipCode ` to `zipcode`
        - `ownerAddressCity ` to `city`
        - `ownerAddressState ` to `ownerState`
        - `ownerBirthDate ` to `birthDate`
        - `ownerSex ` to `sex`
        - `ownerReligion ` to `religion`
        - `nricNumber ` to `nric`

    - `MBMalaysiaMyKadFrontRecognizer` does not extract `armyNumber` anymore, use `MBMalaysiaMyTenteraFrontRecognizer` for scanning `MyTentera`

    - `MBMrtdRecognizer`: 
        - method `saveImageDPI` which has been used to set DPI for full document and MRZ image is replaced with methods `fullDocumentImageDpi` and `mrzImageDpi`

    - renamed methods in `MBSwitzerlandIdBackRecognizer` and its `Result`: 
        - `nonMrzDateOfExpiry` to `dateOfExpiry`
        - `nonMrzSex` to `sex`

    - renamed methods in `MBSwitzerlandPassportRecognizer` and its `Result`:
        - `placeOfBirth` to `placeOfOrigin`
        - `nonMrzDateOfBirth` to `dateOfBirth`
        - `nonMrzDateOfExpiry` to `dateOfExpiry`
        - `nonMrzSex` to `sex`

## 4.4.0

- Minor API changes
    - renamed `MBMyTenteraRecognizer` to `MBMalaysiaMyTenteraFrontRecognizer`

    - renamed `MBMyTenteraRecognizerResult` to `MBMalaysiaMyTenteraFrontRecognizerResult` and properties
        - `nricNumber` to `nric`
        - `ownerAddress` to `fullAddress`
        - `ownerAddressCity` to `city`
        - `ownerAddressState` to `ownerState`
        - `ownerAddressZipCode` to `zipcode`
        - `ownerAddressStreet` to `street`
        - `ownerBirthDate` to `birthDate` and it is now of type `MBDateResult`
        - `ownerFullName` to `fullName`
        - `ownerReligion` to `religion`
        - `ownerSex` to `sex`

    - renamed properties in `MBGermanyIdFrontRecognizerResult`
        - `firstName` to `givenNames`
        - `lastName` to `surname`
        - `dateOfBirth` adn `dateOfExpiry` are now of type `MBDateResult`

## 4.3.0

- Minor API changes
    - renamed properties in `MBMalaysiaDlFrontRecognizerResult`:
        - `state` to `ownerState`
        - `zipCode` to `zipcode`

    - renamed properties in `MBIndonesiaIdFrontRecognizerResult`:
        - `validUntil` to `dateOfExpiry`
        - `validUntilPermanent` to `dateOfExpiryPermanent`

    - renamed property in `MBSingaporeIdFrontRecognizerResult`:
        - `bloodType` to `bloodGroup`

    - renamed property in `MBSingaporeCombinedRecognizerREsult`:
        - `bloodType` to `bloodGroup`

## 4.2.0

- Minor API changes
    - Renamed properties in `MBCroatiaIdBackRecognizerResult`:
        - `address` to `residence`
        - `documentForNonResident` to `isDocumentForNonResident`
        - `issuingAuthority` to `issuedBy`
        - MRZ fields are available through `MBMrzResult` which can be obtained by using property `mrzResult`

    - Renamed properties in `MBSingaporeIdFrontRecognizerResult`:
        - `cardNumber` to `identityCardNumber`

    - Renamed properties in `MBSingaporeCombinedRecognizerResult`:
        - `cardNumber` to `identityCardNumber`
        - `bloodGroup` to `bloodType`

    - `isScanningUnsupportedForCameraType:` is now class method of `MBMicroblinkSDK`    

## 4.1.0

- Minor API changes

    - `identityCardNumber` property has been renamed to `documentNumber` on `MBCroatiaIdFrontRecognizerResult`

## 4.0.1

- No changes

## 4.0.0
Please check [README](README.md) and updated demo applications for more information, but the gist of it is:
  - `PPScanningViewController` has been renamed to `MBRecognizerRunnerViewController` and `MBCoordinator` to `MBRecognizerRunner`
  - `PPBarcodeOverlayViewController` has been renamed to `MBBarcodeOverlayViewController`
  - previously internal `MBRecognizer` objects are not internal anymore - instead of having opaque `MBRecognizerSettings` and `MBRecognizerResult` objects, you now have stateful `MBRecognizer` object that contains its `MBResult` within and mutates it while performing recognition. For more information, see [README](README.md) and updated demo applications
  - introduced `MBFieldByFieldOverlayViewController` that can be used for easy integration of the *field-by-field scanning* feature (previously known as *segment scan*)
  - introduced `MBDocumentVerificationController` that can be used for easy integration of *ID verification scanning* feature (previously available only in [BlinkID AppStore app](https://itunes.apple.com/us/app/blinkid/id1258136557?mt=8)
  - introduced `MBProcessor` concept. For more information, check updated code samples, [README](README.md) and [this blog post](https://microblink.com/blog/major-change-of-the-api-and-in-the-license-key-formats)

New licence format, which is not backward compatible. Full details are given in [README](README.md) and in updated applications, but the gist of it is:
    
  - licence can now be provided with either file, byte array or base64-encoded bytes

## 2.18.2

  - No changes

## 2.18.1

  - No changes

## 2.18.0

  - No changes

## 2.17.3

  - No changes

## 2.17.2

  - No changes

## 2.17.1

  - No changes

## 2.17.0

  - No changes

## 2.16.1

  - No changes

## 2.16.0

  - No changes

## 2.15.0

  - Renamed `PPMyKadRecognizerSettings` and `PPMyKadRecognizerResult` to `PPMyKadFrontRecognizerSettings` and `PPMyKadFrontRecognizerResult`

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
