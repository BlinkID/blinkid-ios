//
//  MBFrameRecognitionRecognizerRunnerViewControllerDelegate.h
//  BlinkShowcaseDev
//
//  Created by Jura Skrlec on 02/12/2020.
//

#ifndef MBFrameRecognitionRecognizerRunnerViewControllerDelegate_h
#define MBFrameRecognitionRecognizerRunnerViewControllerDelegate_h

#import "MBRecognizerResult.h"

@protocol MBRecognizerRunnerViewController;

/**
 * Protocol for obtaining frame recognition
 */
@protocol MBFrameRecognitionRecognizerRunnerViewControllerDelegate <NSObject>
@required
/**
 * Scanning library did output frame with state
 *
 *  @param recognizerRunnerViewController scanningViewController Scanning view controller responsible for scanning
 *  @param state                  state of scanning
 */
- (void)recognizerRunnerViewControllerDidFinishFrameRecognition:(nonnull UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewController state:(MBRecognizerResultState)state;

@end

#endif /* MBFrameRecognitionRecognizerRunnerViewControllerDelegate_h */
