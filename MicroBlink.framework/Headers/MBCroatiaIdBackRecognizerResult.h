//
//  MBCroatiaIdBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBCroatiaIdBackRecognizerResult_h
#define MBCroatiaIdBackRecognizerResult_h

#import "MBLegacyMRTDRecognizerResult.h"

#import "MBFullDocumentImageResult.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of Croatian ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCroatiaIdBackRecognizerResult : MBLegacyMRTDRecognizerResult<NSCopying, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The address of the Croatian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The issuing authority of Croatian ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The document date of issue of the Croatian ID in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDocumentDateOfIssue;

/**
 * The document date of issue of the Croatian ID.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * Check if date of expiry is permanent on the Croatian ID.
 */
@property (nonatomic, readonly) BOOL dateOfExpiryPermanent;


@end

NS_ASSUME_NONNULL_END

#endif /* MBCroatiaIdBackRecognizerResult_h */
