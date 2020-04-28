//
//  MBAgeLimitStatus.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 22/04/2020.
//

#ifndef MBAgeLimitStatus_h
#define MBAgeLimitStatus_h

typedef NS_ENUM(NSUInteger, MBAgeLimitStatus) {

    /** Status cannot be determined. When date of birth is not known. */
    MBAgeLimitStatusNotAvailable,

    /** Document owner age is less than the given age limit. */
    MBAgeLimitStatusBelowAgeLimit,

    /** Document owner age is greater than the given age limit. */
    MBAgeLimitStatusOverAgeLimit
};

#endif /* MBAgeLimitStatus_h */
