// 
// MBRecognizerRunnerViewControllerMetadataDelegates.h
// 
// AUTOMATICALLY GENERATED SOURCE. DO NOT EDIT!
// 
 
#import "MBDebugRecognizerRunnerViewControllerDelegate.h"
#import "MBDetectionRecognizerRunnerViewControllerDelegate.h"
#import "MBOcrRecognizerRunnerViewControllerDelegate.h"
#import "MBGlareRecognizerRunnerViewControllerDelegate.h"
#import "MBFirstSideFinishedRecognizerRunnerViewControllerDelegate.h"
 
#import "MBMicroblinkDefines.h"
#import <Foundation/Foundation.h>
 
/**
 * Class containing all metadata delegates
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBRecognizerRunnerViewControllerMetadataDelegates : NSObject
 
@property (nonatomic, weak, nullable) id<MBDebugRecognizerRunnerViewControllerDelegate> debugRecognizerRunnerViewControllerDelegate;
@property (nonatomic, weak, nullable) id<MBDetectionRecognizerRunnerViewControllerDelegate> detectionRecognizerRunnerViewControllerDelegate;
@property (nonatomic, weak, nullable) id<MBOcrRecognizerRunnerViewControllerDelegate> ocrRecognizerRunnerViewControllerDelegate;
@property (nonatomic, weak, nullable) id<MBGlareRecognizerRunnerViewControllerDelegate> glareRecognizerRunnerViewControllerDelegate;
@property (nonatomic, weak, nullable) id<MBFirstSideFinishedRecognizerRunnerViewControllerDelegate> firstSideFinishedRecognizerRunnerViewControllerDelegate;
 
@end
 