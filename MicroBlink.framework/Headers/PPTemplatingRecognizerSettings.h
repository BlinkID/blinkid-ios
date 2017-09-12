//
//  PPTemplatingRecognizerSettings.h
//  PhotoPayFramework
//
//  Created by Dino on 18/05/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPSegmentRecognizerSettings.h"
#import "PPOcrParserFactory.h"
#import "PPDecodingInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for Templating API and general OCR recognition.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPTemplatingRecognizerSettings : PPSegmentRecognizerSettings

@property (nonatomic) BOOL allowUnparsedResults;

/**
 * Sets array of PPDecodingInfo to be used when PPDocumentClassifer outputs a selected result.
 *
 *  @see PPDocumentClassifier
 *
 *  @param decodingInfos    Decoding infos to be used when PPDocumentClassifier outputs selected result
 *  @param classifierResult Output from PPDocumentClassifer
 */
- (void)setDecodingInfoSet:(NSArray<PPDecodingInfo *> *)decodingInfos forClassifierResult:(NSString *)classifierResult;

/**
 * Removes all decoding infos for a given classifier result.
 *
 * @param classifierResult Removes all decoding infos linked to specified classifier result
 */
- (void)removeDecodingInfoSetForClassifierResult:(NSString *)classifierResult;

/**
 * Removes all present decoding info
 */
- (void)removeAllDecodingInfoSets;

/**
 * Defines if glare detection should be turned on/off for Templating Recognizer.
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL detectGlare;

/**
 * Set Image DPI that will return Image in DPI
 *
 * Default: 250.0
 */
@property (nonatomic, assign) CGFloat imageDPI;

@end

NS_ASSUME_NONNULL_END
