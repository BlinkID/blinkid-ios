//
//  PPDocumentDetectorSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 06/10/15.
//  Copyright © 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPDetectorSettings.h"

#import "PPDocumentSpecification.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings for document detector
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPDocumentDetectorSettings : PPDetectorSettings

/**
 * Defines how many times the same document should be detected before the detector
 * returns this document as a result of the deteciton
 *
 * Higher number means more reliable detection, but slower processing
 */
@property (nonatomic) NSUInteger numStableDetectionsThreshold;

/**
 * Designated initializer, creates the object with a given threshold for number of stable detections
 *
 *  @param threshold number of stable detections
 *
 *  @return initialized object
 */
- (instancetype)initWithNumStableDetectionsThreshold:(NSUInteger)threshold NS_DESIGNATED_INITIALIZER;

// Unavailable initializer
- (instancetype)initWithSettings:(DetectorSettingsImpl*)settings NS_UNAVAILABLE;

/**
 * Sets the document specifications. Document specifications describe the images that should be returned by
 * the detectior.
 *
 *  @param documentSpecifications document specifications
 */
- (void)setDocumentSpecifications:(NSArray<__kindof PPDocumentSpecification *> *)documentSpecifications;

@end

NS_ASSUME_NONNULL_END