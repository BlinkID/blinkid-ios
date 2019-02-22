//
//  MBMrtdCombinedRecognizerResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 13/06/2018.
//

#import "MBMicroblinkDefines.h"
#import "MBRecognizerResult.h"

#import "MBCombinedRecognizerResult.h"

#import "MBMrzResult.h"

#import "MBFaceImageResult.h"
#import "MBDigitalSignatureResult.h"
#import "MBCombinedFullDocumentImageResult.h"

#import "MBEncodedFaceImageResult.h"
#import "MBEncodedSignatureImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"
#import "MBEncodedMrzImageResult.h"

#import "MBDigitalSignatureResult.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning both front and back side of Croatian ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMrtdCombinedRecognizerResult : MBRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBFaceImageResult, MBCombinedFullDocumentImageResult, MBEncodedFaceImageResult, MBEncodedCombinedFullDocumentImageResult, MBDigitalSignatureResult>

MB_INIT_UNAVAILABLE

/**
 * Returns the Data extracted from the machine readable zone.
 */
@property (nonatomic, readonly, strong) MBMrzResult *mrzResult;

@end

NS_ASSUME_NONNULL_END
