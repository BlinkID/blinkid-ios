//
//  MBImageExtensionFactors.h
//  MicroblinkDev
//
//  Created by Dino on 19/06/2018.
//

#import <CoreGraphics/CoreGraphics.h>

/**
 * Struct which describes image extension factors. Each factors denotes by what percentage is image extended.
 * For example, value of top = 0.3f means that top side of the image is extended by 30% of cards height,
 * while value of right = 1.3f means that the right side of the image is extended by 120% of the cards width.
 */
typedef struct _MBImageExtensionFactors {
    CGFloat top;
    CGFloat right;
    CGFloat bottom;
    CGFloat left;
} MBImageExtensionFactors;

/**
 * Method which creates a image extension factors structure
 */
NS_INLINE MBImageExtensionFactors MBMakeImageExtensionFactors(CGFloat top, CGFloat right, CGFloat bottom, CGFloat left) {
    MBImageExtensionFactors factors;
    factors.top = top;
    factors.right = right;
    factors.bottom = bottom;
    factors.left = left;
    return factors;
}
