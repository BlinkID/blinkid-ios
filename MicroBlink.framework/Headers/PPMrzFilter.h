//
//  PPMrzFilter.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 28/08/2017.
//
//


#import "PPMicroBlinkDefines.h"
#import "PPMrtdRecognizerResult.h"

/**
 * Protocol used for mrz filtering.
 * Filtering is used for better filtering of different documet types
 */
@protocol PPMrzFilter <NSObject>

/**
 * Method for setting mrz filter from PPMrtdRecognizerResult.
 * The returning BOOL determines if scanned document is filtered correctly for that document.
 */
- (BOOL)mrzFilterForResult:(PPMrtdRecognizerResult *)result;

@end
