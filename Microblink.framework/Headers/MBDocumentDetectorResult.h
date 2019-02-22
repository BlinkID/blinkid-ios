//
//  MBDocumentDetectorResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 20/03/2018.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"
#import "MBQuadWithSizeDetectorResult.h"
#import "MBDocumentSpecification.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Detector that can perform detection of card documents, cheques, papers, etc.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDocumentDetectorResult : MBQuadWithSizeDetectorResult <NSCopying>

MB_INIT_UNAVAILABLE

/**
 * Aspect ratio of detected document.
 */
@property (nonatomic, assign, readonly) CGFloat aspectRatio;

@end

NS_ASSUME_NONNULL_END
