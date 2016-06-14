//
//  PPMicroBlinkDefines.h
//  BlinkIdFramework
//
//  Created by Jura on 04/01/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#ifndef PPMicroBlinkDefines_h
#define PPMicroBlinkDefines_h

/**
 * Define your macros for accessing localization tables.
 * If you don't have your definitions, our tables will be used
 * based on [[PPApp instance] language] property
 */

#ifndef MB_LOCALIZED_DEFAULT_STRING
    #define MB_LOCALIZED_DEFAULT_STRING(key) \
        ([NSString stringWithFormat: @"[[%@]]", key])
#endif

#ifndef MB_LOCALIZED
    // note - this might return nil if frameworkBundle is nil!
    #define MB_LOCALIZED(key) NSLocalizedStringWithDefaultValue(key, \
        [[PPApp instance] language], \
        [[PPApp instance] resourcesBundle], \
        MB_LOCALIZED_DEFAULT_STRING(key), \
        nil)
#endif

#ifndef MB_LOCALIZED_FORMAT
    // note - this might return nil if frameworkBundle is nil!
    #define MB_LOCALIZED_FORMAT(key,...) [NSString stringWithFormat:NSLocalizedStringWithDefaultValue(key, \
        [[PPApp instance] language], \
        [[PPApp instance] resourcesBundle], \
        MB_LOCALIZED_DEFAULT_STRING(key), \
        nil), \
        ##__VA_ARGS__]
#endif

#ifdef __cplusplus
#define PP_EXTERN       extern "C" __attribute__((visibility ("default")))
#else
#define PP_EXTERN       extern __attribute__((visibility ("default")))
#endif

#define PP_CLASS_AVAILABLE_IOS(_ios)                         NS_CLASS_AVAILABLE_IOS(_ios)
#define PP_CLASS_DEPRECATED_IOS(_iosIntro, _iosDep, ...)     NS_CLASS_DEPRECATED(NA, NA, _iosIntro, _iosDep, __VA_ARGS__)

#endif /* PPMicroBlinkDefines_h */
