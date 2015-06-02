## Direct processing API

This guide will in short present you how to process UIImage objects with MicroBlink SDK, without starting the camera video capture. 

With this you can solve various use cases like:
- recognizing text on images in Camera roll
- taking full resolution photo and sending it to processing
- scanning barcodes on images in e-mail
- etc.

This guide will be essentially the same as Getting started guide. The difference will be that the demo here will present UIImagePickerController for taking full resolution photos, and then process it with MicroBlink SDK to get scanning results.

### 1. Initial integration steps

The same as in Getting started guide.

### 2. Referencing header file

The same as in Getting started guide.

### 3. Initializing the scanning library
	
To initialize the scanning library, first decide where in your app you want to add scanning functionality. Usually, users of the scanning library have a button which, when tapped, starts the scanning process. Initialization code is then placed in touch handler for that button. Here we're listing the initialization code as it looks in a touch handler method.

```objective-c
- (IBAction)takePhoto:(id)sender {
    NSLog(@"Take photo!");

    // Check if scanning is supported
    NSError *error;
    if ([PPCoordinator isScanningUnsupported:&error]) {
        NSString *messageString = [error localizedDescription];
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Warning"
                                                        message:messageString
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil, nil];
        [alert show];
        return;
    }

    /** 1. Initialize the Scanning settings */

    // Initialize the scanner settings object. This initialize settings with all default values.
    PPSettings *settings = [[PPSettings alloc] init];


    /** 2. Setup the license key */
    settings.licenseSettings.licenseKey = @"License key";


    /** 3. Set up what is being scanned. See detailed guides for specific use cases. */
    
    // We're leaving this empty in this guide so you can use RecognizerSettings which you need.
    // [settings.scanSettings addRecognizerSettings:ocrRecognizerSettings];

    // get coordinator
    self.coordinator = [[PPCoordinator alloc] initWithSettings:settings];
    
    // Most important method. Uninitialized recognizers won't scan anything. 
    // Also, it's important to terminate recognizers once the scanning is complete to free the resources.
    [self.coordinator initializeRecognizers];

    // Initialize UI for taking photos
    UIImagePickerController *cameraUI = [[UIImagePickerController alloc] init];

    // Use rear camera
    cameraUI.sourceType = UIImagePickerControllerSourceTypeCamera;
    cameraUI.cameraDevice = UIImagePickerControllerCameraDeviceRear;

    // Displays a control that allows the user to choose only photos
    cameraUI.mediaTypes = [[NSArray alloc] initWithObjects: (NSString *)kUTTypeImage, nil];

    // Hides the controls for moving & scaling pictures, or for trimming movies.
    cameraUI.allowsEditing = NO;

    // Shows default camera control overlay over camera preview.
    // TODO: set this to NO and provide custom overlay
    cameraUI.showsCameraControls = YES;

    // set delegate
    cameraUI.delegate = self;

    // Show view
    [self presentViewController:cameraUI animated:YES completion:nil];
}

#pragma mark - UIImagePickerControllerDelegate

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info {
    NSString *mediaType = [info objectForKey: UIImagePickerControllerMediaType];

    // Handle a still image capture
    if (CFStringCompare((CFStringRef) mediaType, kUTTypeImage, 0) == kCFCompareEqualTo) {
        UIImage *originalImage = (UIImage *)[info objectForKey: UIImagePickerControllerOriginalImage];

        // the actual processing method
        [self.coordinator processImage:originalImage
                        scanningRegion:CGRectMake(0.0, 0.0, 1.0, 1.0)
                              delegate:self];
    }

    [self dismissViewControllerAnimated:YES completion:nil];
}
```

### 4. Registering for scanning events

The same as in Getting started guide.

### 5. Terminating the library

When your scanning is complete, don't forget to call 

```objective-c
[self.coordinator terminateRecognizers];
```


### Conclusion

Now you've seen how to implement the Direct processing API.

In essence, this API consists of:

1) Initialization of the scanner. 
2) Call of `[self.coordinator initializeRecognizers]`
3) Call of `processImage:scanningRegion:delegate` method for each `UIImage` you have.
4) Call of `[self.coordinator terminateRecognizers]` when all the processing is finished.