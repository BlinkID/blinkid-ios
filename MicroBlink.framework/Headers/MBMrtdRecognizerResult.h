//
//  MBMrtdDetectorRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 28/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroBlinkDefines.h"
#import "MBTemplatingRecognizerResult.h"
#import "MBMrzResult.h"
#import "MBFullDocumentImageResult.h"

@class MBOcrLayout;
@class MBImage;

NS_ASSUME_NONNULL_BEGIN

/**
 * Result of MBMrtdDetectorRecognizer
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMrtdRecognizerResult : MBTemplatingRecognizerResult<NSCopying, MBFullDocumentImageResult>

- (instancetype)init NS_UNAVAILABLE;

/**
 * Returns the Data extracted from the machine readable zone.
 */
@property (nonatomic, readonly, strong) MBMrzResult *mrzResult;

/**
 * Raw OCR layout from which the MRTD data was parsed.
 *
 * If allowUnparsedResults is used, you can use this property to implement
 * your custom MRTD parsing algorithm
 */
@property (nonatomic, readonly, nullable) MBOcrLayout *rawOcrLayout;

/**
 * Image of the Machine Readable Zone or nil if not available.
 */
@property (nonatomic, readonly, nullable) MBImage *mrzImage;

@end

NS_ASSUME_NONNULL_END
