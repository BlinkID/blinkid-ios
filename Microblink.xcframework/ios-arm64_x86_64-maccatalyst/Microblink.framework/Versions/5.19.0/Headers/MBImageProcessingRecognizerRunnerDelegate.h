//
//  MBImageProcessingDelegate.h
//  Microblink
//
//  Created by DoDo on 07/05/2018.
//

@class MBRecognizerRunner;
@class MBImage;

@protocol MBImageProcessingRecognizerRunnerDelegate <NSObject>
@required

/**
 * Called when MBRecognizerRunner finishes processing given image.
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void) recognizerRunner:(nonnull MBRecognizerRunner *)recognizerRunner didFinishProcessingImage:(nonnull MBImage *)image;

@end
