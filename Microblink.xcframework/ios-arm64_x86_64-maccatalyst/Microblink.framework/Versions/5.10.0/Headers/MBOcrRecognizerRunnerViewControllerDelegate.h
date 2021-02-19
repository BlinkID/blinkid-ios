//
//  MBOcrRecognizerRunnerViewDelegate.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 18/12/2017.
//

#import <Foundation/Foundation.h>

@class MBOcrLayout;
@protocol MBRecognizerRunnerViewController;

/**
 * Protocol for obtaining ocr results
 */
@protocol MBOcrRecognizerRunnerViewControllerDelegate <NSObject>
@required

/**
 * Called when scanning library has MBOcrLayout ready to be displayed on UI.
 * NOTE: This method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 */
- (void)recognizerRunnerViewController:(nonnull UIViewController<MBRecognizerRunnerViewController> *)recognizerRunnerViewController
                    didObtainOcrResult:(nonnull MBOcrLayout *)ocrResult
                        withResultName:(nonnull NSString *)resultName;

@end
