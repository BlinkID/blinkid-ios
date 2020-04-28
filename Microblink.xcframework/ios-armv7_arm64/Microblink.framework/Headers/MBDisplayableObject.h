//
//  MBDisplayableObject.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 08/12/2017.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents any object that can be displayed on screen in terms of drawing.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDisplayableObject : NSObject
/**
 * Tranformation matrix which transforms the coordinate system in which the OCR layout is given
 * (i.e. coordinate system of the image) to the coordinate system of the device screen.
 */
@property (nonatomic, assign) CGAffineTransform transform;

@end

NS_ASSUME_NONNULL_END

