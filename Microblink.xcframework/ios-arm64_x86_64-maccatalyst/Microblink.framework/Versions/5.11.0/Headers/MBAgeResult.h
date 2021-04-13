//
//  MBAgeResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 22/04/2020.
//

#ifndef MBAgeResult_h
#define MBAgeResult_h

#import "MBAgeLimitStatus.h"

@protocol MBAgeResult

@required

/**
 * The current age of the document owner in years. It is calculated difference
 * between now and date of birth. Now is current time on the device.
 * @return current age of the document owner in years or -1 if date of birth is unknown.
*/
@property (nonatomic, readonly) NSInteger age;

/**
 * Calculates whether the document owner is older than the given ageLimit in years or not.
 * Status is calculated by using the date of birth and the current time on the device.
 * @param ageLimit age limit in years
 * @return age limit status for the document owner
*/
- (MBAgeLimitStatus)getAgeLimitStatusFor:(NSInteger)ageLimit;

@end


#endif /* MBAgeResult_h */
