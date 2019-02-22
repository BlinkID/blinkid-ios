//
//  MBEudlCountry.h
//  Microblink
//
//  Created by Dino Gustin on 28/05/2018.
//

#import <Foundation/Foundation.h>

/**
 * Enumeration of all supported countries in EUDL Recognizer
 */
typedef NS_ENUM(NSUInteger, MBEudlCountry) {
    
    /**
     * UK driver's licenses
     */
    MBEudlCountryUnitedKingdom,
    
    /**
     * German driver's licenses
     */
    MBEudlCountryGermany,
    
    /**
     * Austrian driver's licenses
     */
    MBEudlCountryAustria,
    
    /**
     * Any EU DL
     */
    MBEudlCountryAny,
};
