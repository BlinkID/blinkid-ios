//
//  MBProcessorGroup.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 21/03/2018.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "MBMicroblinkInitialization.h"
#import "MBMicroblinkDefines.h"

@class MBDewarpPolicy;
@class MBProcessor;

NS_ASSUME_NONNULL_BEGIN

/**
 * Class that represents a group of processors that will be executed on same dewarped image.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBProcessorGroup : NSObject

MB_INIT_UNAVAILABLE

/**
 * Constructor for MBProcessorGroup.
 *
 * @param processingLocation Position in detected location that should be processed. Expressed as relative rectangle with respect to detected rectangle.
 * @param dewarpPolicy       Dewarp policy that will mandate how the perspective correction will be performed.
 * @param processors         Processors that will be executed on given processing location after perspective has been corrected.
 */
- (instancetype)initWithProcessingLocation:(CGRect)processingLocation dewarpPolicy:(nonnull MBDewarpPolicy *)dewarpPolicy andProcessors:(nonnull NSArray<__kindof MBProcessor *> *)processors NS_DESIGNATED_INITIALIZER;

/**
 * Processors that are members of the processor group
 */
@property (nonatomic, strong, readonly) NSArray<__kindof MBProcessor *> *processors;

@end

NS_ASSUME_NONNULL_END
