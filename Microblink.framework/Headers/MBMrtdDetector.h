//
//  MBMrtdDetector.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 20/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBQuadWithSizeDetector.h"
#import "MBMrtdDetectorResult.h"
#import "MBMicroblinkInitialization.h"
#import "MBMrtdSpecification.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Detector that can perform detection of Machine Readable Travel Documents (MRTD).
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBMrtdDetector : MBQuadWithSizeDetector <NSCopying>

MB_INIT

/**
 * MRTD detector result
 */
@property (nonatomic, strong, readonly) MBMrtdDetectorResult *result;

/**
 * Defines whether full document will be detected. If set to false, result will contain
 * location of Machine Readable Zone only. If set to true, result will contain location
 * of entire document.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL detectFullDocument;

/**
 * Enable detection correction with card detector. When this option is enabled, after
 * MRTD detector has found the document, it will internally use MBDocumentDetector
 * to additionally correct document location estimated from detected MRZ location.
 * Note that although enabling this option will usually improve detection accuracy, it may
 * be possible that for some use cases accuracy will be lower.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL useCardDetector;

/**
 * Sets the mrtd specifications. Mrtd specifications describe the images that should be returned by
 * the detector.
 *
 *  @param mrtdSpecifications mrtd specifications
 */
- (void)setMrtdSpecifications:(NSArray<__kindof MBMrtdSpecification *> *)mrtdSpecifications;

@end

NS_ASSUME_NONNULL_END

