//
//  MBFirstSideFinishedRecognizerRunnerDelegate.h
//  MicroblinkDev
//
//  Created by DoDo on 24/04/2018.
//

#ifndef MBFirstSideFinishedRecognizerRunnerDelegate_h
#define MBFirstSideFinishedRecognizerRunnerDelegate_h

@class MBRecognizerRunner;

@protocol MBFirstSideFinishedRecognizerRunnerDelegate <NSObject>
@required

/**
 * Called when scanning library finishes performing recognition of the first side of the document.
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void) recognizerRunnerDidFinishRecognitionOfFirstSide:(nonnull MBRecognizerRunner *)recognizerRunner;

@end

#endif /* MBFirstSideFinishedRecognizerRunnerDelegate_h */
