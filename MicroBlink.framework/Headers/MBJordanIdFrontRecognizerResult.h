//
//  MBJordanIdFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBFaceImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Jordan ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBJordanIdFrontRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFullDocumentImageResult, MBFaceImageResult>

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
 * The National Number of the Jordan ID.
 */
@property (nonatomic, readonly, nullable) NSString *nationalNumber;

@end

NS_ASSUME_NONNULL_END