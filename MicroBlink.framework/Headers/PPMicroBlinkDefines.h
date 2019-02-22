//
//  PPMicroblinkDefines.h
//  BlinkIdFramework
//
//  Created by Jura on 04/01/16.
//  Copyright © 2016 Microblink Ltd. All rights reserved.
//

#ifndef PPMicroblinkDefines_h
#define PPMicroblinkDefines_h

/**
 * Define your macros for accessing localization tables.
 * If you don't have your definitions, our tables will be used
 * based on [[MBMicroblinkApp instance] language] property
 */

#ifndef MB_LOCALIZED_DEFAULT_STRING
#define MB_LOCALIZED_DEFAULT_STRING(key) ([NSString stringWithFormat:@"[[%@]]", key])
#endif

#ifndef MB_LOCALIZED
// note - this might return nil if frameworkBundle is nil!
#define MB_LOCALIZED(key)                                                                                   \
NSLocalizedStringWithDefaultValue(key, [[MBMicroblinkApp instance] language], [[MBMicroblinkApp instance] resourcesBundle], \
MB_LOCALIZED_DEFAULT_STRING(key), nil)
#endif

#ifndef MB_LOCALIZED_FORMAT
// note - this might return nil if frameworkBundle is nil!
#define MB_LOCALIZED_FORMAT(key, ...)                                                                                                  \
[NSString stringWithFormat:NSLocalizedStringWithDefaultValue(key, [[MBMicroblinkApp instance] language], [[MBMicroblinkApp instance] resourcesBundle], \
MB_LOCALIZED_DEFAULT_STRING(key), nil),                               \
##__VA_ARGS__]
#endif

#ifndef MB_LOCALIZED_PROPERTY_GETTER
// note - this might return nil if frameworkBundle is nil!
#define MB_LOCALIZED_PROPERTY_GETTER(propertyName, key) \
if (propertyName) {                                     \
return propertyName;                                    \
} else {                                                \
return MB_LOCALIZED(key);                               \
}
#endif

#ifdef __cplusplus
#define PP_EXTERN extern "C" __attribute__((visibility("default")))
#else
#define PP_EXTERN extern __attribute__((visibility("default")))
#endif

#define PP_CLASS_AVAILABLE_IOS(_ios) NS_CLASS_AVAILABLE_IOS(_ios)
#define PP_CLASS_DEPRECATED_IOS(_iosIntro, _iosDep, ...) NS_CLASS_DEPRECATED(NA, NA, _iosIntro, _iosDep, __VA_ARGS__)
#define PP_DEPRECATED_IOS(_iosIntro, _iosDep, ...) __attribute__((availability(ios,introduced=_iosIntro,deprecated=_iosDep,message="" __VA_ARGS__)))

#define PP_INIT_UNAVAILABLE - (instancetype)init NS_UNAVAILABLE;

#endif /* PPMicroblinkDefines_h */
