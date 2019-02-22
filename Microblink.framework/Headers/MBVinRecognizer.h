//
//  MBVinRecognizer.h
//  Microblink
//
//  Created by Dino Gustin on 23/04/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBRecognizer.h"
#import "MBVinRecognizerResult.h"
#import "MBMicroblinkInitialization.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer that can perform recognition of VINs (Vehicle Identification Number).
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBVinRecognizer : MBRecognizer<NSCopying>

MB_INIT

/**
 * Vin recognizer result
 */
@property (nonatomic, strong, readonly) MBVinRecognizerResult *result;

@end

NS_ASSUME_NONNULL_END
