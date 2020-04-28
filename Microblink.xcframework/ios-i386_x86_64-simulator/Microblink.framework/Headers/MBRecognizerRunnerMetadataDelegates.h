// 
// MBRecognizerRunnerMetadataDelegates.h
// 
// AUTOMATICALLY GENERATED SOURCE. DO NOT EDIT!
// 
 
#import "MBDebugRecognizerRunnerDelegate.h"
#import "MBDetectionRecognizerRunnerDelegate.h"
#import "MBOcrRecognizerRunnerDelegate.h"
#import "MBGlareRecognizerRunnerDelegate.h"
#import "MBFirstSideFinishedRecognizerRunnerDelegate.h"
 
#import "MBMicroblinkDefines.h"
#import <Foundation/Foundation.h>
 
/**
 * Class containing all metadata delegates
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBRecognizerRunnerMetadataDelegates : NSObject
 
@property (nonatomic, weak, nullable) id<MBDebugRecognizerRunnerDelegate> debugRecognizerRunnerDelegate;
@property (nonatomic, weak, nullable) id<MBDetectionRecognizerRunnerDelegate> detectionRecognizerRunnerDelegate;
@property (nonatomic, weak, nullable) id<MBOcrRecognizerRunnerDelegate> ocrRecognizerRunnerDelegate;
@property (nonatomic, weak, nullable) id<MBGlareRecognizerRunnerDelegate> glareRecognizerRunnerDelegate;
@property (nonatomic, weak, nullable) id<MBFirstSideFinishedRecognizerRunnerDelegate> firstSideFinishedRecognizerRunnerDelegate;
 
@end
 