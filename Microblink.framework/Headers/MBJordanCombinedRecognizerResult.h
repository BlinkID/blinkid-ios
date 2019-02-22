//
//  MBCroatiaCombinedRecognizerResult.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBCombinedRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBDigitalSignatureResult.h"
#import "MBCombinedFullDocumentImageResult.h"

#import "MBEncodedFaceImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning both front and back side of Czech ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBJordanCombinedRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBFaceImageResult, MBCombinedFullDocumentImageResult, MBDigitalSignatureResult, MBEncodedFaceImageResult, MBEncodedCombinedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The Name of the Jordan ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The Sex of the Jordan ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * The Date Of Birth of the Jordan ID owner.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The Document Number of the Jordan ID.
 */
@property (nonatomic, readonly, nullable) NSString *nationalNumber;

/**
 * The nationality of the Jordan ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The issuer of the Jordan ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuer;

/**
 * The Document Number of the Jordan ID.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The Date of expiry of the Jordan ID.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * YES if all check digits inside MRZ are correct, NO otherwise.
 * More specifically, YES if MRZ complies with ICAO Document 9303 standard, NO otherwise.
 */
@property (nonatomic, readonly) BOOL mrzVerified;

@end

NS_ASSUME_NONNULL_END
