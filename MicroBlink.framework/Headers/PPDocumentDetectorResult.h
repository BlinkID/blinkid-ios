//
//  PPDocumentDetectorResult.h
//  BlinkIdFramework
//
//  Created by Jura on 11/01/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPQuadDetectorResult.h"

#import "PPDocumentSpecification.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Result of a document detector (used to detector various rectangular objects).
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPDocumentDetectorResult : PPQuadDetectorResult

/**
 * Aspect ratio of detected document.
 */
@property (nonatomic) CGFloat aspectRatio;

/**
 * Screen orientation used when detecting the document.
 */
@property (nonatomic) UIInterfaceOrientation screenOrientation;

@end

NS_ASSUME_NONNULL_END
