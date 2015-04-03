# Customizing the Camera Overlay in PhotoPay

This documents describes how to implement Custom UI for scanning screen.

Note: PhotoPay comes with default camera UI which is specifically implemented and tweaked for the best user experience, as well as for best scanning results. Think carefully before deciding to implement Custom UI, consult this documentation to get the idea which features are supported, and contact PhotoPay team for any questions.

## Custom user interface

Overlay View Controller is an abstract class for all overlay views placed on top PhotoPay's Camera View Controller.

It's responsibility is to provide meaningful and useful interface for the user to interact with.
 
Typical actions which need to be allowed to the user are:

- intuitive and meaniningful way to guide the user through scanning process. This is usually done by presenting a "viewfinder" in which the user need to place the scanned object
- a way to cancel the scanining, typically with a "cancel" or "back" button
- a way to power on and off the light (i.e. "torch") button
 
PhotoPay always provides it's own default implementation of the Overlay View Controller for every specific use. Your implementation should closely mimic the default implementation as it's the result of thorough testing with end users. Also, it closely matches the underlying scanning technology. 

For example, the scanning technology usually gives results very fast after the user places the device's camera in the expected way above the scanned object. This means a progress bar for the scan is not particularly useful to the user. The majority of time the user spends on positioning the device's camera correctly. That's just an example which demonstrates careful decision making behind default camera overlay view.

PhotoPay demo project in your development package contain `PPCameraOverlayViewController` class, an example of custom overlay view implementation.

### 1. Initialization
 
To use your custom overlay with PhotoPay's camera view, you must first subclass PPOverlayViewController and implement the overlay behaviour (as described in this document). To present your overlay, you need to and specify it when initializing CameraViewController.

This example places `PPCameraOverlayViewController` overlay on top of the camera screen.
 
```objective-c

PPCameraOverlayViewController *overlayViewController = 
	[[PPCameraOverlayViewController alloc] initWithNibName:@"PPCameraOverlayViewController" bundle:nil];

// Create camera view controller
UIViewController *cameraViewController = 
	[coordinator cameraViewControllerWithDelegate:self overlayViewController:overlayViewController];
```

Note: if you create camera view controller without specifying overlay view, the default overlay implementation will be used:

```objective-c

// Create camera view controller
UIViewController *cameraViewController = 
	[coordinator cameraViewControllerWithDelegate:self];	
```
	
As with any view controller, you are responsible for specifying UI elements and handling their actions. Besides that, there are some requirements for interaction with Camera View Controller. 

### 2. Interaction with Container CameraViewController

CameraViewController is a Container view controller to the PPOverlayViewController instances. For more about Container View Controllers, read official Apple [View Controller Programming Guide].

Also, each instance of PPOverlayViewController and it's subclasses has access to the Container View Controller.

```objective-c

/** 
 Overlay View's delegate object. Responsible for sending messages to PhotoPay's 
 Camera View Controller
 */
@property (nonatomic, assign) id<PPOverlayContainerViewController> containerViewController;
```

#### 2.1 Events received from Container CameraViewController

PPCameraOverlayViewController gets notified by CameraViewController on various scanning events. Here is a list of all events and the methods which get called in turn:

1. Camera view appears and the scanning resumes. This happens when the camera view is opened, or when the app enters foreground with camera view displayed. The method called on this event is

	```objective-c
	- (void)cameraViewControllerDidResumeScanning:(id<PPScanningViewController>)cameraViewController;
	```

2. Camera view disappears and the scanning pauses. This happens when the camera view is closed, or when the app enters background with camera view displayed. The method called on this event is
	
	```objective-c
	- (void)cameraViewControllerDidStopScanning:(id<PPScanningViewController>)cameraViewController;
	```
	
3. Camera view reports the progress of the current OCR/barcode scanning recognition cycle. Note: this is not the actual progress from the moment camera appears. This might not be meaningful for the user in all cases.

	```objective-c
	- (void)cameraViewController:(id<PPScanningViewController>)cameraViewController
			  didPublishProgress:(float)progress;
	```

4. Camera view reports the status of the object detection. Scanning status contain information about whether the scan was successful, whether the user holds the device too far from the object, whether the angles was too high, or the object isn't seen on the camera in it's entirety. If the object was found, the corner points of the object are returned.

	```objective-c
	- (void)cameraViewController:(id<PPScanningViewController>)cameraViewController
				 didFindLocation:(NSArray*)cornerPoints
					  withStatus:(PPDetectionStatus)status;
	```
					  
5. Camera view reports obtained OCR result. Besides the OCR result itself, we get the ID of the result so we can distinguish consecutive results of the same area on the image

	```objective-c
	- (void)cameraViewController:(id<PPScanningViewController>)cameraViewController
			  didObtainOcrResult:(PPOcrResult*)ocrResult
				  withResultName:(NSString*)resultName;
	```
				   
6. Camera view controller started the new recognition cycle. Since recognition is done on video frames, there might be multiple recognition cycles before the scanning completes. Method which is called on this event is:

	```objective-c
	- (void)cameraViewControllerDidStartRecognition:(id<PPScanningViewController>)cameraViewController;
	```
               
7. Camera view controller ended the recognition cycle with a certain Scanning result. The scanning result cannot be considered as valid, sometimes here are received objects which contain only partial scanning information. Use this method only if you need UI update on this event (although this is unnecessary in many cases). If you're interested in valid data, use cameraViewController:didOutputResult: method.

	```objective-c
	- (void)cameraViewController:(id<PPScanningViewController>)cameraViewController 
	didFinishRecognitionWithResult:(id)result;
	```

8. Camera view controller ended the recognition cycle with a list of results. The scanning results can be considered as valid, meaning it can be presented to the user for inspection. Also, note that the actual result will be passed to your PPPhotoPayDelegate object.

	```objective-c
	- (void)cameraViewController:(id<PPScanningViewController>)cameraViewController
				didOutputResults:(NSArray*)results;
	```

9. UIViewController's method called when a rotation to a given interface orientation is about to happen

	```objective-c
	- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
                                	duration:(NSTimeInterval)duration;
    ```

10. UIViewController's method called immediately after the rotation from a given interface orientation happened

	```objective-c
	- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation;
	```

11. UIViewController's method called inside an animation block. Any changes you make to your UIView's inside this method will be animated

	```objective-c
	- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
                                             duration:(NSTimeInterval)duration;
    ```

#### 2.2 Notifications passed to Container CameraViewController

Overlay View Controller also needs to notify CameraViewController on certain events. Those are events specified by `PPOverlayContainerViewController` protocol. 

Notification sent when Overlay View Controller wants to close camera, for example, by pressing Cancel button.

```objective-c
- (void)overlayViewControllerWillCloseCamera:(PPOverlayViewController*)overlayViewController;
```

Overlay View Controller should ask it's delegete if it's necessary to display Torch (Light) button. Torch button is not necessary if the device doesn't support torch mode (e.g. iPad devices).

```objective-c
- (BOOL)overlayViewControllerShouldDisplayTorch:(PPOverlayViewController*)overlayViewController;
```

Overlay View Controller must notify it's delegete to set the torch mode to On or Off

```objective-c
- (void)overlayViewController:(id)overlayViewController
				 willSetTorch:(BOOL)isTorchOn;
```
                 	 
#### 2.3 Other information getters in `PPOverlayContainerViewController`
                 	 
Overlay View Controller should know if it's presented modally or on navigation view controller. Use this method to ask if it's necessary to display Cancel button. (When on navigation view controller, button back is presented by default). This method replaced old method overlayViewControllerShouldDisplayCancel.
	
```objective-c
- (BOOL)isPresentedModally;
```

Overlay View Controller can ask it's delegete about the status of Torch

```objective-c
- (BOOL)isTorchOn;
```

Overlay View Controller can get Video Capture Preview Layer object from it's delegete.

```objective-c
- (AVCaptureVideoPreviewLayer*)getPreviewLayer;
```

### 3. Handling orientation changes

Overlay View Controller supports a mechanism which can rotate the UI independently of Camera View Controller. This makes crating the interface in which the Camera View Controller doesn't rotate, while the overlay on top of does, which eliminates awkward camera preview rotation. This approach is similar to Apple's implementation of the Camera App. 

In general, there are two options for handling orientation changes. 

1. In your view hierarchy, you keep the Camera View Controller orientation fixed, while the overlay rotates.

	This approach is used when Camera View Controller is presented as a modal view in full screen presentation style. It makes the camera preview stay in fixed orientation, and only your overlay rotates.

	You can easily define which interface orientations are supported in your Overlay View Controller by implementing the following method and returning your desired orientation mask:

	```objective-c
	- (NSUInteger)supportedInterfaceOrientations {
		return UIInterfaceOrientationMaskLandscape;
	}	
	```

2. In your view hierarchy, Camera View Controller auto-rotates as a whole. 

	Camera View Controller can rotate if pushed on a rotatable UINavigationController, presented in UIPageViewController, or presented modally in PageSheet or FormSheet presentation styles.

	In this case, overlay should not rotate independently of Camera View Controller. Disable overlay autorotation by initializing `PPCoordinator` object with the following setting:

	```objective-c
	[coordinatorSettings setValue:@(NO) forKey:kPPOverlayShouldAutorotate];
	```

## Steps for providing custom Camera Overlay View

1. Create a subclass of `PPOverlayViewController`. You can use XIB for user interface, or create UI from code.

2. See if there are any events received from `CameraViewController` which you need to handle for your UI hierarchy

3. Implement your view hierarchy. 

	If you have a Cancel button in your view, don't forget to call `overlayViewControllerWillCloseCamera:` method on overlay's delegate object when cancel is pressed. 

	If you have Torch button, dont forget to check if Torch should be displayed by using `overlayViewControllerShouldDisplayTorch:` method, and to report new torch state with `overlayViewController:willSetTorch:` method. 

4. Handle orientation changes

[View Controller Programming Guide]:https://developer.apple.com/library/ios/featuredarticles/ViewControllerPGforiPhoneOS/CreatingCustomContainerViewControllers/CreatingCustomContainerViewControllers.html