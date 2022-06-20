//
//  Header.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 20/12/2017.
//

#import "MBRecognizerResult.h"

@class MBRecognizerRunner;

NS_ASSUME_NONNULL_BEGIN

/**
 * Protocol for obtaining scanning results
 */
@protocol MBScanningRecognizerRunnerDelegate <NSObject>
@required
/**
 * Scanning library did output scanning results
 *
 * Depending on how you want to treat the result, you might want to
 * dismiss the scanningViewController here.
 *
 * This method is the default way for getting access to results of scanning.
 *
 * Note:
 * - there may be 0, 1, or more than one scanning results.
 * - each scanning result belongs to a common MBRecognizerResult type
 * - handle different types differently
 * - this method is called on background processing thread. Make sure that you dispatch all your UI API calls to main thread.
 *
 *  @param recognizerRunner recognizerRunner Scanning view controller responsible for scanning
 *  @param state                  state of scanning
 *
 *
 */

- (void)recognizerRunner:(nonnull MBRecognizerRunner *)recognizerRunner didFinishScanningWithState:(MBRecognizerResultState)state;

@end

NS_ASSUME_NONNULL_END
