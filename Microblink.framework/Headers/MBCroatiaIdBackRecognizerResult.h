//
//  MBCroatiaIdBackRecognizerResult.h
//  MicroblinkDev
//
//  Created by DoDo on 16/04/2018.
//

#ifndef MBCroatiaIdBackRecognizerResult_h
#define MBCroatiaIdBackRecognizerResult_h

#import "MBRecognizerResult.h"
#import "MBDateResult.h"
#import "MBMrzResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of Croatian ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBCroatiaIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The residence of Croatian ID owner
 */
@property (nonatomic, readonly, nullable) NSString *residence;

/**
 * The issuer of Croatian ID
 */
@property (nonatomic, readonly, nullable) NSString *issuedBy;

/**
 * The date of issue of Croatian ID
 */
@property (nonatomic, readonly, nullable) MBDateResult *dateOfIssue;

/**
 * Determines if Croatian ID is issued for non resident
 */
@property (nonatomic, readonly) BOOL documentForNonResident;

/**
 * Determines if date of expiry of Croatian ID is permanent
 */
@property (nonatomic, readonly) BOOL dateOfExpiryPermanent;

/**
 * The data extracted from the machine readable zone
 */
@property (nonatomic, readonly) MBMrzResult *mrzResult;

@end

NS_ASSUME_NONNULL_END

#endif /* MBCroatiaIdBackRecognizerResult_h */
