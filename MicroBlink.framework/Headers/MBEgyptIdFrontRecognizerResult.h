//
//  MBEgyptIdFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyRecognizerResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBFaceImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning front side of Egypt ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBEgyptIdFrontRecognizerResult : MBLegacyRecognizerResult<NSCopying, MBFullDocumentImageResult, MBFaceImageResult>

MB_INIT_UNAVAILABLE

/**
 * The National Number of the Egypt ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationalNumber;

/**
 * The document number of the Egypt ID.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

@end

NS_ASSUME_NONNULL_END