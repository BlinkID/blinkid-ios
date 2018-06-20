//
//  MBMicroblinkDefines.h
//  MicroBlinkDev
//
//  Created by DoDo on 12/04/2018.
//

#ifndef MBMicroblinkDefines_h
#define MBMicroblinkDefines_h

#import "PPMicroBlinkDefines.h"
#import "MBMicroBlinkInitialization.h"

#if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
# define MB_FINAL __attribute__((objc_subclassing_restricted))
#else
# define MB_FINAL
#endif

#define MB_CLASS_AVAILABLE_IOS PP_CLASS_AVAILABLE_IOS

#endif /* MBMicroblinkDefines_h */
