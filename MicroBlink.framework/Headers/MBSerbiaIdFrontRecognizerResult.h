//
//  MBSerbiaIdFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Serbian ID
 */
MB_CLASS_DEPRECATED_IOS(1.0.0, 4.6.0, "Recognizer is deprecated")
@interface MBSerbiaIdFrontRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFaceImageResult, MBSignatureImageResult, MBFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
 * The issuing date of the Serbian ID.
 */
@property (nonatomic, readonly, nullable) NSDate *issuingDate;

/**
 * The valid until date of the Serbian ID.
 */
@property (nonatomic, readonly, nullable) NSDate *validUntil;

/**
 * The document number of Serbian ID owner
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

@end

NS_ASSUME_NONNULL_END
