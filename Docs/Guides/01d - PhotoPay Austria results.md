## Austrian payment slip scanning results

### Initializing the scanning of Austrian slips

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

    // Add recognizer for Austrian payslips
    [settings.scanSettings addRecognizerSettings:[[PPAusSlipRecognizerSettings alloc] init]];

    // Add QR code recognizer for Austrian payslips
    [settings.scanSettings addRecognizerSettings:[[PPAusQrRecognizerSettings alloc] init]];


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

        if ([result isKindOfClass:[PPAusSlipRecognizerResult class]]) {
            [self processAusSlipRecognizerResult:(PPAusSlipRecognizerResult*)result];
        }
        if ([result isKindOfClass:[PPAusQrRecognizerResult class]]) {
            [self processAusQrRecognizerResult:(PPAusQrRecognizerResult*)result];
        }
    };
}

- (void)processAusSlipRecognizerResult:(PPAusSlipRecognizerResult*)ausSlipResult {

    // Here we log all field in PPAusSlipRecognizerResult object

    NSLog(@"Austrian payment slip results\n");

    NSLog(@"Amount is %@", [ausSlipResult amount]);
    NSLog(@"Currency is %@", [ausSlipResult currency]);

    NSLog(@"Recipient name is %@", [ausSlipResult recipientName]);
    NSLog(@"IBAN is %@", [ausSlipResult iban]);
    NSLog(@"Bank code is %@", [ausSlipResult bankCode]);
    NSLog(@"Account number is %@", [ausSlipResult accountNumber]);
    NSLog(@"BIC is %@", [ausSlipResult bic]);
    NSLog(@"Reference number is %@", [ausSlipResult referenceNumber]);
    NSLog(@"Payment description is %@", [ausSlipResult paymentDescription]);
    
    NSLog(@"Customer Data is %@", [ausSlipResult customerData]);
    NSLog(@"Contract account is %@", [ausSlipResult contractAccount]);
    NSLog(@"Tax Number is %@", [ausSlipResult taxNumber]);

    NSLog(@"Document type is %d", (int)[ausSlipResult documentType]);

    NSLog(@"Belegnummer is %@", [ausSlipResult belegNummer]);
    NSLog(@"Prufziffer is %@", [ausSlipResult prufziffer]);
}

- (void)processAusQrRecognizerResult:(PPAusQrRecognizerResult*)ausQrResult {

    // Here we log all field in PPAusQrRecognizerResult object

    NSLog(@"Austrian QR code results\n");

    NSLog(@"Amount is %@", [ausQrResult amount]);
    NSLog(@"Currency is %@", [ausQrResult currency]);

    NSLog(@"Recipient name is %@", [ausQrResult recipientName]);
    NSLog(@"IBAN is %@", [ausQrResult iban]);
    NSLog(@"Bank code is %@", [ausQrResult bankCode]);
    NSLog(@"Account number is %@", [ausQrResult accountNumber]);
    NSLog(@"BIC is %@", [ausQrResult bic]);
    NSLog(@"Reference number is %@", [ausQrResult referenceNumber]);
    NSLog(@"Payment description is %@", [ausQrResult paymentDescription]);

    NSLog(@"Display data is %@", [ausQrResult displayData]);
    NSLog(@"Purpose code is %@", [ausQrResult purposeCode]);
}
```