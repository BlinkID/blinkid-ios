//
//  MBMicroblinkDefines.h
//  MicroblinkDev
//
//  Created by DoDo on 12/04/2018.
//

#ifndef MBMicroblinkDefines_h
#define MBMicroblinkDefines_h

#import "PPMicroblinkDefines.h"
#import "MBMicroblinkInitialization.h"
#import "AvailabilityMacros.h"

#if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
# define MB_FINAL __attribute__((objc_subclassing_restricted))
#else
# define MB_FINAL
#endif

#define MB_CLASS_AVAILABLE_IOS PP_CLASS_AVAILABLE_IOS
#define MB_CLASS_DEPRECATED_IOS PP_CLASS_DEPRECATED_IOS
#define MB_PROPERTY_DEPRECATED DEPRECATED_ATTRIBUTE
#define MB_ATTRIBUTE_DEPRECATED DEPRECATED_ATTRIBUTE

#endif /* MBMicroblinkDefines_h */
