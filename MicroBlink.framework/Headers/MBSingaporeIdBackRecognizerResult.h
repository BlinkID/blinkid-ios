//
//  MBSingaporeIdBackRecognizerResult.h
//  MicroblinkDev
//
//  Created by dinogustin on 27/07/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of the Singapore Id
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSingaporeIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE


/**
 * The address of the back side of the Singapore Id owner.
 */
@property (nonatomic, readonly) NSString *address;

/**
 * The address Change Date of the back side of the Singapore Id owner.
 */
@property (nonatomic, readonly) MBDateResult *addressChangeDate;

/**
 * The blood Type of the back side of the Singapore Id owner.
 */
@property (nonatomic, readonly) NSString *bloodGroup MB_PROPERTY_DEPRECATED;

/**
 * The card Number of the back side of the Singapore Id owner.
 */
@property (nonatomic, readonly) NSString *cardNumber;

/**
 * The date Of Issue of the back side of the Singapore Id owner.
 */
@property (nonatomic, readonly) MBDateResult *dateOfIssue;

@end

NS_ASSUME_NONNULL_END
