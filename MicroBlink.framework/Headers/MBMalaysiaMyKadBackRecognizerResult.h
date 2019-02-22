//
//  MBMalaysiaMyKadBackRecognizerResult.h
//  MicroblinkDev
//
//  Created by Dino Gustin on 12/06/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN 

/**
 * Class representing values obtained when scanning back side of MyKad
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMalaysiaMyKadBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE


/**
 * The Extended NRIC of the MyKad owner.
 */
@property (nonatomic, readonly) NSString *extendedNric MB_PROPERTY_DEPRECATED;

/**
 * The NRIC of the MyKad owner.
 */
@property (nonatomic, readonly) NSString *nric;

/**
 * The old NRIC of the MyKad owner.
 */
@property (nonatomic, readonly) NSString *oldNric;

/**
 * The Date Of Birth of the MyKad owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

@end

NS_ASSUME_NONNULL_END
