//
//  MBDependentInfo.h
//  BlinkID
//
//  Created by Jura Skrlec on 26.09.2024..
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

@class MBDateResult;
@class MBStringResult;

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBDependentInfo : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * The date of birth of the dependent.
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfBirth;

/**
 * The sex or gender of the dependent.
 */
@property (nonatomic, readonly, nullable) MBStringResult *sex;

/**
 * The document number of the dependent.
 */
@property (nonatomic, readonly, nullable) MBStringResult *documentNumber;

/**
 * The full name of the dependent.
 */
@property (nonatomic, readonly, nullable) MBStringResult *fullName;

/**
 * Flag that indicates if dependent info is empty.
*/
@property (nonatomic, readonly, assign) BOOL empty;

@end

NS_ASSUME_NONNULL_END
