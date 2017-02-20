//
//  PPDocumentClassifier.h
//  PhotoPayFramework
//
//  Created by Dino on 19/05/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPMicroBlinkDefines.h"
#import "PPTemplatingRecognizerResult.h"

/**
 * Protocol used for document classification in Templating API.
 * Classification is used when there are multiple types of document being detected (i.e. old and new version of ID, with differen location
 * of elements) *
 */
@protocol PPDocumentClassifier <NSObject>

/**
 * Method for classifying document from PPTemplatingRecognizerResult.
 * The returning NSStrings determines which further PPDecodingInfo objects will be used (if any) by returning their uniqueIds.
 */
- (NSString *)classifyDocumentFromResult:(PPTemplatingRecognizerResult *)result;

@end
