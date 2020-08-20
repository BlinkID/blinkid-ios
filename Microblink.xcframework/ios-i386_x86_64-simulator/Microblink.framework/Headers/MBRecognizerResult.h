//
//  MBRecognizerResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 22/11/2017.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

/**
 * Enumeration of posibble recognizer result state
 */
typedef NS_ENUM(NSInteger, MBRecognizerResultState) {
    
    /**
     *  Empty
     */
    MBRecognizerResultStateEmpty,
    
    /**
     *  Uncertain
     */
    MBRecognizerResultStateUncertain,
    
    /**
     *  Valid
     */
    MBRecognizerResultStateValid,

};

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all recognizer results
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBRecognizerResult : NSObject

MB_INIT_UNAVAILABLE

@property (nonatomic, assign, readonly) MBRecognizerResultState resultState;

@end

NS_ASSUME_NONNULL_END
