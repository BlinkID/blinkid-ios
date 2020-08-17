//
//  Header.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 14/12/2017.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MBCameraSettings.h"

@class MBRecognizerCollection;
@class MBOverlayViewController;
@class MBImage;

/** Block for returning high resolution MBImage photo with capture or still output */
typedef void(^MBCaptureHighResImage)(MBImage * _Nullable highResImage);

NS_ASSUME_NONNULL_BEGIN

/**
 * Protocol for View controllers which present camera and provide scanning features
 */
@protocol MBRecognizerRunnerViewController <NSObject>

/**
 * MBRecognizerRunnerViewController's shouldAutorotate will return this value.
 *
 * Default: NO.
 *
 * Set it to YES if you want scanning view controller to autorotate.
 */
@property (nonatomic) BOOL autorotate;

/**
 * MBRecognizerRunnerViewController's supportedInterfaceOrientations will return this value.
 *
 * Default: UIInterfaceOrientationMaskPortrait.
 */
@property (nonatomic) UIInterfaceOrientationMask supportedOrientations;

/**
 * Pause scanning without dismissing the camera view.
 *
 * If there is camera frame being processed at a time, the processing will finish, but the results of processing
 * will not be returned.
 *
 * NOTE: This method must be called from the background thread
 */
- (void)pauseScanning;

/**
 * Retrieve the current state of scanning.
 *
 * NOTE: This method is always returned on the background thread.
 *
 *  @return YES if scanning is paused. NO if it's in progress
 */
- (BOOL)isScanningPaused;

/**
 * Resumes scanning. Optionally, internal state of recognizers can be reset in the process.
 *
 * If you continue scanning the same object, for example, the same slip, or the same MRTD document, to get result
 * with higher confidence, then pass NO to reset State.
 *
 * If you move to scan another object, for example, another barcode, or another payment slip, then pass YES to reset State.
 *
 * Internal state is used to use the fact that the same object exists on multiple consecutive frames, and using internal
 * state provides better scanning results.
 *
 * NOTE: This method must be called on the background thread.
 *
 *  @param resetState YES if state should be reset.
 */
- (void)resumeScanningAndResetState:(BOOL)resetState;

/**
 * Resumes camera session asynchronously on camera queue. This method is automatically called in viewWillAppear when ScanningViewController enters screen.
 * @param completion block is executed on main queue after camera is resummed
 */
- (void)resumeCamera:(void(^_Nullable)(void))completion;

/**
 * Pauses camera session. This method is automatically called in viewDidDissapear when ScanningViewController exits screen.
 */
- (BOOL)pauseCamera;

/**
 * Retrieve the current state of camera.
 *
 *  @return YES if camera is paused. NO if camera is active
 */
- (BOOL)isCameraPaused;

/**
 * Play scan sound.
 *
 * It uses default scan sound, you can change it by setting your own soundFilePath in MBOverlaySettings.
 */
- (void)playScanSuccessSound;

/**
 * Call to turn on torch without camera overlay
 */
- (void)willSetTorchOn:(BOOL)torchOn;

/**
 * Settings recofiguration
 *
 * NOTE: This method must be called on the background thread.
 */
- (void)resetState;

/**
 * Method with block for getting high resoultion images
 *
 * @warning this is returned from background thread
 */
- (void)captureHighResImage:(MBCaptureHighResImage)highResoulutionImageCaptured;

@end

NS_ASSUME_NONNULL_END

