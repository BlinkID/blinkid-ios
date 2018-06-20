//
//  MBMrtdDetectorRecognizer.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 28/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroBlinkDefines.h"
#import "MBTemplatingRecognizer.h"
#import "MBMrtdRecognizerResult.h"
#import "MBMicroBlinkInitialization.h"
#import "MBMrtdSpecification.h"
#import "MBGlareDetection.h"

#import "MBFullDocumentImage.h"


@protocol MBMrzFilter;

@class MBDetector;

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer that can recognizer Machine Readable Zone (MRZ) of the Machine Readable Travel Document (MRTD)
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBMrtdRecognizer : MBTemplatingRecognizer<NSCopying, MBFullDocumentImage, MBGlareDetection>

MB_INIT

/**
 * Detector recognizer results
 */
@property (nonatomic, strong, readonly) MBMrtdRecognizerResult *result;

/**
 * Whether returning of unparsed results is allowed
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL allowUnparsedResults;

/**
 * Whether returning of unverified results is allowed
 * Unverified result is result that is parsed, but check digits are incorrect.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL allowUnverifiedResults;

/**
 * Whether cropped image of the Machine Readable Zone should be available in result.
 * Note - enabling this feature will degrade performance
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL returnMrzImage;

/**
 * Desired DPI for MRZ and full document images (if saving of those is enabled)
 *
 * Default: 250
 */
@property (nonatomic, assign) NSUInteger saveImageDPI;

/**
 * Sets the mrtd specifications. Mrtd specifications describe the images that should be returned by
 * the detector. Setting nil or empty array will enable all possible specifications.
 *
 *  @param mrtdSpecifications mrtd specifications
 */
- (void)setMrtdSpecifications:(nullable NSArray<__kindof MBMrtdSpecification *> *)mrtdSpecifications;

/**
 * Get the mrtd specifications.
 */
@property (nonatomic, nullable, strong, readonly) NSArray<__kindof MBMrtdSpecification *> *mrtdSpecifications;

/**
 * Filter for MRTDs (Machine Readable Travel Documents) that is used to determine which documents
 * will be processed. If document is filtered out by this filter, its data cannot be returned as recognition result.
 */
- (void)setMrzFilter:(nullable id<MBMrzFilter>)mrzFilter;

@end

@protocol MBMrzFilter <NSObject>
@required
/**
 * Determines whether document should be processed or it is filtered out.
 * @return YES if the document with the given MRZ should be processed, NO if the document
 * should be filtered out.
 */
- (BOOL)mrzFilter;
@end

NS_ASSUME_NONNULL_END
