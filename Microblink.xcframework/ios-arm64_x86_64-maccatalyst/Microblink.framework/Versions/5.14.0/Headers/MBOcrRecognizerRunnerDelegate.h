//
//  MBOcrRecognizerRunnerDelegate.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 20/12/2017.
//

@class MBRecognizerRunner;
@class MBOcrLayout;

/**
 * Protocol for obtaining ocr results
 */
@protocol MBOcrRecognizerRunnerDelegate <NSObject>
@required

/**
 * Called when Scanning library has MBOcrLayout available and ready to be displayed on UI.
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void)recognizerRunner:(nonnull MBRecognizerRunner *)recognizerRunner
      didObtainOcrResult:(nonnull MBOcrLayout *)ocrResult
          withResultName:(nonnull NSString *)resultName;

@end
