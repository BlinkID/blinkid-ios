//
//  PPDocumentDetectorResult.h
//  BlinkIdFramework
//
//  Created by Jura on 11/01/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPQuadDetectorResultWithSize.h"

#import "PPDocumentSpecification.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Result of a document detector (used to detector various rectangular objects).
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPDocumentDetectorResult : PPQuadDetectorResultWithSize

/**
 * Aspect ratio of detected document.
 */
@property (nonatomic) CGFloat aspectRatio;

@end

NS_ASSUME_NONNULL_END
