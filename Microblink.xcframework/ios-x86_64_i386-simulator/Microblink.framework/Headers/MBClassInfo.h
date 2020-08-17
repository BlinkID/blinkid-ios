//
//  MBClassInfo.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 09/10/2019.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBClassInfoTypes.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBClassInfo : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * The document country.
 */
@property (nonatomic, readonly, assign) MBCountry country;

/**
 * The document region.
 */
@property (nonatomic, readonly, assign) MBRegion region;

/**
 * The type of the scanned document.
 */
@property (nonatomic, readonly, assign) MBType type;

@end

NS_ASSUME_NONNULL_END
