//
//  MBRecognizer.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 21/11/2017.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MBMicroblinkDefines.h"
#import "MBEntity.h"
#import "MBRecognizerResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all recognizers
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBRecognizer : MBEntity

/**
 * Base recognizer result.
 */
@property (nonatomic, readonly, weak) MBRecognizerResult *baseResult;

- (UIInterfaceOrientationMask)getOptimalHudOrientation;

- (NSString *)toJson;

@end

NS_ASSUME_NONNULL_END
