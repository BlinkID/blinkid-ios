//
//  MBMicroblinkDefines.h
//  MicroblinkDev
//
//  Created by DoDo on 12/04/2018.
//

#ifndef MBMicroblinkDefines_h
#define MBMicroblinkDefines_h

#import "MBMicroblinkInitialization.h"
#import "AvailabilityMacros.h"

#if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
# define MB_FINAL __attribute__((objc_subclassing_restricted))
#else
# define MB_FINAL
#endif

#define MB_CLASS_AVAILABLE_IOS(_ios) NS_CLASS_AVAILABLE_IOS(_ios)
#define MB_CLASS_DEPRECATED_IOS(_iosIntro, _iosDep, ...) NS_CLASS_DEPRECATED(NA, NA, _iosIntro, _iosDep, __VA_ARGS__)
#define MB_PROPERTY_DEPRECATED DEPRECATED_ATTRIBUTE
#define MB_ATTRIBUTE_DEPRECATED DEPRECATED_ATTRIBUTE
#define MB_CLASS_DEPRECATED(message) __attribute__((deprecated(message)))

#define MB_IS_IPAD (([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPad))

#ifdef __cplusplus
#define MB_EXTERN extern "C" __attribute__((visibility("default")))
#else
#define MB_EXTERN extern __attribute__((visibility("default")))
#endif

typedef void(^MBBlock)(void);

#define MBASSERTE(condition, description)     \
     do {                                                           \
       NSAssert(condition, description);                            \
       if (!(condition)) {                                          \
         NSString *message = [NSString stringWithFormat:@"Assertion failed: (%s), %@, %s, file %s, line %d", #condition, description, __PRETTY_FUNCTION__, __FILE__, __LINE__]; \
         LOGE("%s", [message UTF8String]);                          \
       }                                                            \
     } while (0)


#ifdef MB_DISABLE_OBFUSCATION

#define MB_OBS_IF_COPY(x) if(x) {
#define MB_OBS_ELSE_COPY } else {

#else

#define MB_OBS_IF_COPY(x) { MB::Obfuscation::IfWrapper(( [=]()->bool{ return (x); })).setThen( [=]() -> void
#define MB_OBS_ELSE_COPY ).setElse( [=]() -> void

#endif // MB_DISABLE_OBFUSCATION

#define MB_OBFUSCATED(value) [NSString stringWithFormat:@"%s", OBFUSCATED(value)]

#endif /* MBMicroblinkDefines_h */
