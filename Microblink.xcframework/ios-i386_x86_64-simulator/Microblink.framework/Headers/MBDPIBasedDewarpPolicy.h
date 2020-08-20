//
//  MBDPIBasedDewarpPolicy.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 21/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBDewarpPolicy.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * DPI based dewarp policy. Dewarp height will be calculated based on
 * actual physical size provided by the MBQuadWithSizeDetector
 * and requested DPI (dots per inch).
 *
 * This policy is usually best for processor groups that prepare
 * image for output (e.g. MBImageReturnProcessor).
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBDPIBasedDewarpPolicy : MBDewarpPolicy

/**
 * Default DPI that will be used with default constructor.
 */
- (instancetype)init;

/**
 * @param desiredDPI Desired DPI (dots per inch)
 */
- (instancetype)initWithDesiredDPI:(NSUInteger)desiredDPI NS_DESIGNATED_INITIALIZER;

/**
 * Returns the desired DPI as defined by this policy.
 *
 * Default: 250
 */
@property (nonatomic, assign, readonly) NSUInteger desiredDPI;

@end

NS_ASSUME_NONNULL_END
