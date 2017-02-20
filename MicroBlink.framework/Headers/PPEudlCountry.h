//
//  PPEudlCountry.h
//  BlinkIdFramework
//
//  Created by Dino on 11/04/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Enumeration of all supported countries in EUDL Recognizer
 */
typedef NS_ENUM(NSUInteger, PPEudlCountry) {

    /**
     * UK driver's licenses
     */
    PPEudlCountryUnitedKingdom,

    /**
     * German driver's licenses
     */
    PPEudlCountryGermany,

    /**
     * Austrian driver's licenses
     */
    PPEudlCountryAustria,

    /**
     * Any EU DL
     */
    PPEudlCountryAny,
};
