//
//  MBDocumentDetector.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 20/03/2018.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"
#import "MBQuadWithSizeDetector.h"
#import "MBDocumentDetectorResult.h"
#import "MBMicroblinkInitialization.h"
#import "MBDocumentSpecification.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Detector that can perform detection of card documents, cheques, papers, etc.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBDocumentDetector : MBQuadWithSizeDetector <NSCopying>

MB_INIT_UNAVAILABLE

/**
 * @param documentSpecifications Document specifications that describe documents that should be detected.
 */
- (instancetype)initWithDocumentSpecifications:(NSArray<__kindof MBDocumentSpecification *> *)documentSpecifications NS_DESIGNATED_INITIALIZER;

/**
 * Document detector result
 */
@property (nonatomic, strong, readonly) MBDocumentDetectorResult *result;

/**
 * Defines how many times the same document should be detected before the detector
 * returns this document as a result of the deteciton
 *
 * Higher number means more reliable detection, but slower processing
 */
@property (nonatomic, assign) NSUInteger numStableDetectionsThreshold;

/**
 * Document specifications describe the documents that should be detected with
 * document detector.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray<__kindof MBDocumentSpecification *> *documentSpecifications;

@end

NS_ASSUME_NONNULL_END
