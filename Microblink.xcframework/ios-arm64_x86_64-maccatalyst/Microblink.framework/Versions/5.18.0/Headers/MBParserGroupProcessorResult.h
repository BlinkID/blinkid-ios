//
//  MBParserGroupProcessorResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 02/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBProcessorResult.h"
#import "MBOcrLayout.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A recognizer that can scan PDF417 2D barcodes.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBParserGroupProcessorResult : MBProcessorResult <NSCopying>

MB_INIT_UNAVAILABLE

@property (nonatomic, strong, readonly) MBOcrLayout *ocrLayout;

@end

NS_ASSUME_NONNULL_END
