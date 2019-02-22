//
//  MBVinRecognizerResult.h
//  Microblink
//
//  Created by Dino Gustin on 23/04/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBRecognizerResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer that can perform recognition of VINs (Vehicle Identification Number).
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBVinRecognizerResult : MBRecognizerResult<NSCopying>

MB_INIT_UNAVAILABLE

/**
 * Returns the recognized VIN or empty string if recognition failed.
 */

@property (nonatomic, nullable, strong, readonly) NSString *vin;

@end

NS_ASSUME_NONNULL_END
