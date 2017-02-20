//
//  PPMRTDDocumentType.h
//  BlinkIdFramework
//
//  Created by Boris Trubic on 02/06/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Enumeration of supported MRTD document types
 */
typedef NS_ENUM(NSUInteger, PPMrtdDocumentType) {

    /**
     *  Unknown document type
     */
    PPMrtdTypeUnknown,

    /**
     *  Identity card
     */
    PPMrtdTypeIdentityCard,

    /**
     *  Passport
     */
    PPMrtdTypePassport,

    /**
     *  Visa
     */
    PPMrtdTypeVisa,

    /**
     *  US Green Card
     */
    PPMrtdTypeGreenCard
};

// Ignore unused method warning
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wall"

static NSString *mrtdDocumentTypeToString(PPMrtdDocumentType documentType) {
    switch (documentType) {
        case PPMrtdTypeIdentityCard:
            return @"Identity Card";
            break;

        case PPMrtdTypePassport:
            return @"Passport";
            break;

        case PPMrtdTypeVisa:
            return @"Visa";
            break;

        case PPMrtdTypeGreenCard:
            return @"Green Card";
            break;

        default:
            return @"";
            break;
    }
}

#pragma clang diagnostic pop
