//
//  MBFirstSideFinishedRecognizerRunnerViewControllerDelegate.h
//  MicroblinkDev
//
//  Created by DoDo on 24/04/2018.
//

#ifndef MBFirstSideFinishedRecognizerRunnerViewControllerDelegate_h
#define MBFirstSideFinishedRecognizerRunnerViewControllerDelegate_h

#import <Foundation/Foundation.h>

@protocol MBRecognizerRunnerViewController;

@protocol MBFirstSideFinishedRecognizerRunnerViewControllerDelegate <NSObject>
@required

/**
 * Called when scanning library finishes performing recognition of the first side of the document.
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void) recognizerRunnerViewControllerDidFinishRecognitionOfFirstSide:(nonnull UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewController;

@end

#endif /* MBFirstSideFinishedRecognizerRunnerViewControllerDelegate_h */
