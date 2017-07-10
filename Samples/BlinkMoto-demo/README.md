## How to add VIN scanning and License plate scanning to your app

1) Add MicroBlink.framework & MicroBlink bundle to your project according to the instructions on blinkid-ios github repository
2) Locate BlinkMoto sample app here: https://github.com/BlinkID/blinkid-ios/tree/feature/moto/Samples/BlinkMoto-demo
3) Add source code from ForOcrOverlay folder to your project
4) Add source code from OcrHelp folder to your project
5) Add MBParsers.h and .m files
6) Add a button handler which initiates scanning
7) Object which starts the scanning should:
- implement `PPFormOcrOverlayViewControllerDelegate` (next step will show the contents of these methods)
- add a property 

```objective-c
@property (nonatomic) NSMutableArray *scanElements;
```
And initialize it with  `self.scanElements = [[MBParsers getParsers] mutableCopy];`

8) In button handler implementation add the implementation such as


```objective-c
#pragma mark - Button handlers

- (IBAction)buttonScanDidTap:(id)sender {
    PPCameraCoordinator *coordinator = [self createCordinator];
    [self presentFormScannerWithCoordinator:coordinator];

    [self hideResultsButton:YES];
}

- (IBAction)buttonResultsDidTap:(id)sender {

    PPResultPageViewController *resultPageViewController = [PPResultPageViewController allocFromStoryboard];

    resultPageViewController.scanElements = self.scanElements;

    [self.navigationController pushViewController:resultPageViewController animated:YES];
}

#pragma mark - Scanning

- (PPCameraCoordinator *)createCordinator {

    NSError *error;

    if ([PPCameraCoordinator isScanningUnsupportedForCameraType:PPCameraTypeBack error:&error]) {
        NSString *messageString = [error localizedDescription];
        [[[UIAlertView alloc] initWithTitle:@"Warning"
                                    message:messageString
                                   delegate:nil
                          cancelButtonTitle:@"OK"
                          otherButtonTitles:nil, nil] show];
        return nil;
    }

    PPSettings *settings = [[PPSettings alloc] init];
    settings.licenseSettings.licenseKey = @LICENSE_KEY;
    PPCameraCoordinator *coordinator = [[PPCameraCoordinator alloc] initWithSettings:settings];
    return coordinator;
}


- (void)presentFormScannerWithCoordinator:(PPCameraCoordinator *)coordinator {

    if (coordinator == nil) {
        return;
    }

    if (self.scanElements.count > 0) {
        PPFormOcrOverlayViewController *overlayViewController =
            [PPFormOcrOverlayViewController allocFromNibName:@"PPFormOcrOverlayViewController"];

        overlayViewController.scanElements = self.scanElements;
        overlayViewController.coordinator = coordinator;
        overlayViewController.delegate = self;

        UIViewController<PPScanningViewController> *scanningViewController =
            [PPViewControllerFactory cameraViewControllerWithDelegate:nil
                                                overlayViewController:overlayViewController
                                                          coordinator:coordinator
                                                                error:nil];

        [self presentViewController:scanningViewController animated:YES completion:nil];

    } else {
        UIAlertView *theAlert = [[UIAlertView alloc] initWithTitle:@"No Scan Elements Present"
                                                           message:@"Tap Settings to add Scan Elements"
                                                          delegate:self
                                                 cancelButtonTitle:@"OK"
                                                 otherButtonTitles:nil];
        [theAlert show];
    }
}

#pragma mark - PPFormOcrOverlayViewControllerDelegate

- (void)formOcrOverlayViewControllerWillClose:(PPFormOcrOverlayViewController *)vc {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)formOcrOverlayViewController:(PPFormOcrOverlayViewController *)vc didFinishScanningWithElements:(NSArray *)scanElements {

    [self dismissViewControllerAnimated:YES
                             completion:^(void) {
                                 ;
                             }];

    [self hideResultsButton:NO];

    // We don't do anything with the results in this demo
    // This demo shows the results if the user presses results button

    // results are shared in self.scanElements array
}
```

Results are saved in  `self.scanElements` array. Each element has the following properties.

```objective-c
/**
 * YES if the value was scanned, NO otherwise.
 * Note: Both scanned and edited cannot be set to YES.
 */
@property (nonatomic, assign) BOOL scanned;

/**
 * YES if the value was manually edited, NO otherwise.
 * Note: Both scanned and edited cannot be set to YES.
 */
@property (nonatomic, assign) BOOL edited;

/**
 * Actual value for this element
 */
@property (nonatomic, strong) NSString *value;
```

## License key

This implementation assumes license key si defined as a macro

```objective-c
settings.licenseSettings.licenseKey = @LICENSE_KEY;
```

You can add the license key in build settings in Preprocessor macros, such as

```
LICENSE_KEY='"XEZAY472-DTKR3JVM-ITIDM6OR-K5XRWXRS-KQAWQIBI-MMICIYYQ-ERRRBBFR-DA34JGNK"'
```

Or you can set the key in code:

```objective-c
settings.licenseSettings.licenseKey = @"XEZAY472-DTKR3JVM-ITIDM6OR-K5XRWXRS-KQAWQIBI-MMICIYYQ-ERRRBBFR-DA34JGNK";
```

## Important:

For production software, it's important to understand the implementation details behind ForOcrOverlay group of classes.