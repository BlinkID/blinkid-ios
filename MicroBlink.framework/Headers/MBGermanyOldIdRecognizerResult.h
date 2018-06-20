//
//  MBGermanyOldIdRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 22/05/2018.
//

#import "MBLegacyMRTDRecognizerResult.h"

#import "MBFullDocumentImageResult.h"
#import "MBSignatureImageResult.h"
#import "MBFaceImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning German Old ID
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBGermanyOldIdRecognizerResult : MBLegacyMRTDRecognizerResult<NSCopying, MBFullDocumentImageResult, MBSignatureImageResult, MBFaceImageResult>

MB_INIT_UNAVAILABLE

/**
 * The place of birth on the German ID
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

@end

NS_ASSUME_NONNULL_END
