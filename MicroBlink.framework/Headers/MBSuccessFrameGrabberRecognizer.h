//
//  MBSuccessFrameGrabberRecognizer.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 22/12/2017.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBRecognizer.h"
#import "MBSuccessFrameGrabberRecognizerResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A recognizer that can returns success frame.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBSuccessFrameGrabberRecognizer : MBRecognizer<NSCopying>

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRecognizer:(MBRecognizer *)recognizer NS_SWIFT_NAME(init(recognizer:)) NS_DESIGNATED_INITIALIZER;

/**
 * SuccessFrameGrabber recognizer results
 */
@property (nonatomic, strong, readonly) MBSuccessFrameGrabberRecognizerResult *result;

/**
 * Slave recognizer that is wrapped with SuccessFrameGrabber
 */
@property (nonatomic, strong, readonly) MBRecognizer *slaveRecognizer;

@end

NS_ASSUME_NONNULL_END
