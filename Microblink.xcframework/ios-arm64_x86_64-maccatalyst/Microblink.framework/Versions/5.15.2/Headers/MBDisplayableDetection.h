//
//  MBDisplayableDetection.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 08/12/2017.
//

#import "MBDisplayableObject.h"
#import "MBDetectionStatus.h"

#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a detection that can be displayed on screen.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDisplayableDetection : MBDisplayableObject

/**
 * Initializes the displayable detection with matrix
 *
 *  @return initialized object
 */
- (instancetype)initWithDetectionStatus:(MBDetectionStatus)status NS_DESIGNATED_INITIALIZER;

/**
 * Please use designated initializer.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Detection status which describes the status of detection
 */
@property (nonatomic, assign, readonly) MBDetectionStatus detectionStatus;

@end

NS_ASSUME_NONNULL_END
