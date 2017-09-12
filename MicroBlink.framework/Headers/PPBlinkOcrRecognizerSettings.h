//
//  PPOcrRecognizerSettings.h
//  PhotoPayFramework
//
//  Created by Jura on 03/11/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPTemplatingRecognizerSettings.h"

#import "PPOcrParserFactory.h"

// Parser for raw text
#import "PPRawOcrParserFactory.h"

// Regex parser
#import "PPRegexOcrParserFactory.h"

// Generic Parsers
#import "PPDateOcrParserFactory.h"
#import "PPEmailOcrParserFactory.h"
#import "PPIbanOcrParserFactory.h"
#import "PPPriceOcrParserFactory.h"
#import "PPLicensePlatesParserFactory.h"
#import "PPVinOcrParserFactory.h"
#import "PPTopUpOcrParserFactory.h"

#import "PPDetectorSettings.h"
#import "PPDocumentClassifier.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class used for OCR or Templating API
 */
PP_CLASS_DEPRECATED_IOS(1_0, 5_10_0, "Use PPDetectorRecognizerSettings for templating API or PPBlinkInputRecognizerSettings for Segment scan")
@interface PPBlinkOcrRecognizerSettings : PPTemplatingRecognizerSettings

- (instancetype)init;

/**
 * Detector settings used in Templating API
 *
 * Default: nil
 */
@property (nonatomic) PPDetectorSettings *detectorSettings;

/**
 * With this enabled, Templating API documents will be processed twice: once regulary and second time flipped upside down.
 *
 * Default: NO
 */
@property (nonatomic) BOOL allowFlippedRecognition;

/**
 * Delegate for document classification.
 *
 * Default: nil
 */
@property (nonatomic) id<PPDocumentClassifier> documentClassifier;

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

@end

NS_ASSUME_NONNULL_END
