//
//  MBRecognizer.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 21/11/2017.
//

#import <Foundation/Foundation.h>
#import "MBMicroBlinkDefines.h"
#import "MBEntity.h"
#import "MBRecognizerResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all recognizers
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBRecognizer : MBEntity

/**
 * Property which determines if the recognizer is enabled
 *
 *  If YES, recognizer is enabled, and it peroforms recognition on each video frame.
 *
 * Default: YES
 */
@property (nonatomic, getter=isEnabled) BOOL enabled;

/**
 * Base recognizer result.
 */
@property (nonatomic, readonly, weak) MBRecognizerResult *baseResult;

- (UIInterfaceOrientationMask)getOptimalHudOrientation;

@end

NS_ASSUME_NONNULL_END
