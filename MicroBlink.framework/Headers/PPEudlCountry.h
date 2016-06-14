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
     * Any EU DL
     */
    PPEudlCountryAny,
};

// Ignore unused method warning
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wall"

static NSString* eudlCountryToString(PPEudlCountry country) {
    switch (country) {
        case PPEudlCountryUnitedKingdom:
            return @"United Kingdom";
            break;
            
        case PPEudlCountryGermany:
            return @"Germany";
            break;
            
        default:
            return @"";
            break;
    }
}

#pragma clang diagnostic pop