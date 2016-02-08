//
//  PPMicroBlinkDefines.h
//  BlinkIdFramework
//
//  Created by Jura on 04/01/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#ifndef PPMicroBlinkDefines_h
#define PPMicroBlinkDefines_h

#ifdef __cplusplus
#define PP_EXTERN       extern "C" __attribute__((visibility ("default")))
#else
#define PP_EXTERN       extern __attribute__((visibility ("default")))
#endif

#define PP_CLASS_AVAILABLE_IOS(_ios)                         NS_CLASS_AVAILABLE_IOS(_ios)
#define PP_CLASS_DEPRECATED_IOS(_iosIntro, _iosDep, ...)     NS_CLASS_DEPRECATED(NA, NA, _iosIntro, _iosDep, __VA_ARGS__)

#endif /* PPMicroBlinkDefines_h */
