//
//  MBCzechiaIdBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyMRTDRecognizerResult.h"

#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of Cz ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCzechiaIdBackRecognizerResult : MBLegacyMRTDRecognizerResult<NSCopying, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The issuing authority of the Czech ID.
 */
@property (nonatomic, readonly, nullable) NSString *authority;

/**
 * The address of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *permanentStay;

/**
 * The personal number of the Czech ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *personalNumber;

@end

NS_ASSUME_NONNULL_END
