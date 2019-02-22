//
//  PPOcrResultView.h
//  PhotoPayFramework
//
//  Created by Jura on 01/02/14.
//  Copyright (c) 2014 Microblink Ltd. All rights reserved.
//

#import "MBSubview.h"
#import "MBOcrLayoutSubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Overlay subview presenting status of OCR detection. OCR results are displayed as green characters over detected locations.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBOcrResultSubview : MBSubview <MBOcrLayoutSubview>

@end

NS_ASSUME_NONNULL_END
