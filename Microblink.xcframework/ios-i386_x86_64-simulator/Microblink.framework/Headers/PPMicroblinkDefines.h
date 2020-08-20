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
