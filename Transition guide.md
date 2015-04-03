### Transition to 0.9.2

- Classes representing scanning results were renamed. Renaming was performed to match naming convention of `PPRecognizerSettings` hierarcy: now each `PPRecognizerSettings` class has it's matching `PPRecognizerResult`. Replace all existing references to old class names with the new ones:

	- `PPBaseResult` was renamed to `PPRecognizerResult`. 

	- `PPOcrScanResult` was renamed to `PPOcrRecognizerResult`, this is the result of a recognizer whose settings are given with `PPOcrRecognizerSettings.`

	- `PPCroResult` renamed to `PPCroRecognizerResult`. This is a common superclass to `PPCroSlipRecognizerResult`, `PPCroPdf417RecognizerResult` and `PPCroQrRecognizerResult`.

	- `PPCroSlipResult` renamed to `PPCroSlipRecognizerResult`, this is the result of a recognizer whose settings are given with `PPCroSlipRecognizerSettings.`

	- `PPCroBarcodeResult` renamed to `PPCroPdf417RecognizerResult`, this is the result of a recognizer whose settings are given with `PPCroPdf417RecognizerSettings.`

	- Introduced `PPCroQrRecognizerResult`, this is the result of a recognizer whose settings are given with `PPCroQrRecognizerSettings.`
	
- `PPOcrResult` (class representing a result of the OCR process, with individual characters, lines and blocks), was renamed to `PPOcrLayout`. Name change was introduced to further distinguish the class from `PPRecognizerResult` classes.

- Remove all references to `updateScanningRegion` method since it's now being called automatically in `setScanningRegion setter`.

### Transition to 0.9.1

- Framework was renamed to MicroBlink.embeddedframework. Remove the existing .embeddedframwork package from your project, and drag&drop MicroBlink.embeddedframework in the project explored of your Xcode project.

- If necessary, after the update, modify your framework search path so that it points to the  MicroBlink.embeddedframework folder.

- Main header of the framework was renamed to `<MicroBlink/Microblink.h>`. Change all references to previous header with the new one.

- method `[PPCoordinator isPhotoPaySupported]` was renamed to `[PPCoordinator isScanningSupported]`. Change all occurances of the method name.