## German payment slip scanning results

### Initializing the scanning of German slips

To initialize the scanning of Austrian slips, use the following intialization code:

```objective-c
- (PPCoordinator*)createCoordinator {

    // Check if photopay is supported
    NSError *error;
    if ([PPCoordinator isScanningUnsupported:&error]) {
        NSString *messageString = [error localizedDescription];
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Warning" message:messageString delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
        [alert show];

        return nil;
    }

    // 1. ******* Instantiate Scanning settings ********/
    PPSettings* settings = [[PPSettings alloc] init];


    // 2. ************* Setup UI Settings **************/

    // Instantiate PhotoPay UI settings. This allows more customization in the initialization process.
    PPPhotoPayUiSettings* photopayUiSettings = [[PPPhotoPayUiSettings alloc] init];
    settings.uiSettings = photopayUiSettings;

    // Use german language
    photopayUiSettings.language = @"de";

    // Help is available so present it just in the first app run
    photopayUiSettings.helpDisplayMode = PPHelpDisplayModeFirstRun;

    // Use Toast messages
    photopayUiSettings.presentToast = YES;

    // Autorotate overlay
    photopayUiSettings.autorotateOverlay = YES;


    // 3. ************* Setup Scan Settings **************/

    // Add recognizer for German payslips
    [settings.scanSettings addRecognizerSettings:[[PPDeSlipRecognizerSettings alloc] init]];

    // Add QR code recognizer for German payslips
    [settings.scanSettings addRecognizerSettings:[[PPDeQrRecognizerSettings alloc] init]];


    // 4. ************* Setup License Settings **************/

    // Set your license key here. This specific key is for demo purposes only!
    settings.licenseSettings.licenseKey = @"5KOE-BTSH-67OL-7F3L-KUAE-SK3G-TEN3-7FNP";

    // Allocate the recognition coordinator object
    PPCoordinator *coordinator = [[PPCoordinator alloc] initWithSettings:settings];
    
    return coordinator;
}

- (IBAction)didTapScan:(id)sender {
    PPCoordinator* coordinator = [self createCoordinator];
    if (coordinator == nil) {
        return;
    }

    // Create camera view controller
    UIViewController *cameraViewController = [coordinator cameraViewControllerWithDelegate:self];

    // present it
    cameraViewController.modalTransitionStyle = UIModalTransitionStyleCrossDissolve;
    [self presentViewController:cameraViewController animated:YES completion:nil];
}
```

### Retrieving results.

Scanning results for Austrian payslips are obtained as instances of two possible classes `PPAusSlipRecognizerResult` (if payment slip was scanned), or `PPAusQrRecognizerResult` (if QR code was scanned). See the header files or sample below for all fields contained in these objects.

```objective-c
- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController
              didOutputResults:(NSArray *)results {

    // find the recognition result and process it

    for (PPRecognizerResult* result in results) {

        if ([result isKindOfClass:[PPDeSlipRecognizerResult class]]) {
            [self processDeSlipRecognizerResult:(PPDeSlipRecognizerResult*)result];
        }
        if ([result isKindOfClass:[PPDeQrRecognizerResult class]]) {
            [self processDeQrRecognizerResult:(PPDeQrRecognizerResult*)result];
        }

        if ([result isKindOfClass:[PPPhotoPayRecognizerResult class]]) {
            PPPhotoPayRecognizerResult* photopayRecognizerResult = (PPPhotoPayRecognizerResult*)result;
            [self processPhotoPayRecognizerResult:photopayRecognizerResult];
            break;
        }
    };
}

- (void)processDeSlipRecognizerResult:(PPDeSlipRecognizerResult*)deSlipResult {

    // Here we log all field in PPDeSlipRecognizerResult object

    NSLog(@"German payment slip results\n");

    NSLog(@"Amount is %@", [deSlipResult amount]);
    NSLog(@"Currency is %@", [deSlipResult currency]);

    NSLog(@"Recipient name is %@", [deSlipResult recipientName]);
    NSLog(@"IBAN is %@", [deSlipResult iban]);
    NSLog(@"Bank code is %@", [deSlipResult bankCode]);
    NSLog(@"Account number is %@", [deSlipResult accountNumber]);
    NSLog(@"Reference number is %@", [deSlipResult referenceNumber]);
    NSLog(@"Payment description is %@", [deSlipResult paymentDescription]);
}

- (void)processDeQrRecognizerResult:(PPDeQrRecognizerResult*)deQrResult {

    // Here we log all field in PPDeQrRecognizerResult object

    NSLog(@"German QR code results\n");

    NSLog(@"Amount is %@", [deQrResult amount]);
    NSLog(@"Currency is %@", [deQrResult currency]);

    NSLog(@"Recipient name is %@", [deQrResult recipientName]);
    NSLog(@"IBAN is %@", [deQrResult iban]);
    NSLog(@"Bank code is %@", [deQrResult bankCode]);
    NSLog(@"Account number is %@", [deQrResult accountNumber]);
    NSLog(@"Reference number is %@", [deQrResult referenceNumber]);
    NSLog(@"Payment description is %@", [deQrResult paymentDescription]);

    NSLog(@"BIC is %@", [deQrResult bic]);
    NSLog(@"Form Type is %@", [deQrResult formType]);
    NSLog(@"Form Version is %@", [deQrResult formVersion]);
    NSLog(@"Form Function is %@", [deQrResult formFunction]);
}
```