//
//  StarbucksCardRecognizerSettings.m
//  Templating-Sample
//
//  Created by Jure Cular on 29/03/2017.
//  Copyright © 2017 Dino. All rights reserved.
//

#import "StarbucksCardRecognizerSettings.h"
static NSString * const CARD_NUMBER = @"CardNumber";
static NSString * const CARD_SECURITY_CODE = @"SecurityCode";
static NSString * const CARD_NUMBER_FIRST_TYPE = @"CardNumberFirstType";
static NSString * const CARD_SECURITY_CODE_FIRST_TYPE = @"SecurityCodeFirstType";
static NSString * const CARD_NUMBER_SECOND_TYPE = @"CardNumberSecondType";
static NSString * const CARD_SECURITY_CODE_SECOND_TYPE = @"SecurityCodeSecondType";

static NSString * const FIRST_TYPE = @"FirstType";
static NSString * const SECOND_TYPE = @"SecondType";

@interface StarbucksCardRecognizerSettings() <PPDocumentClassifier>

@property(strong, nonatomic) NSString *type;

@end

@implementation StarbucksCardRecognizerSettings

- (NSMutableSet *)uppercaseCharsWhitelist {
    
    // initialize new char whitelist
    NSMutableSet *charWhitelist = [[NSMutableSet alloc] init];
    
    // Add chars '0'-'9'
    for (int c = '0'; c <= '9'; c++) {
        [charWhitelist addObject:[PPOcrCharKey keyWithCode:c font:PP_OCR_FONT_ANY]];
    }
    return charWhitelist;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        NSMutableArray<PPDecodingInfo *> *firstCardDecodingInfoArray = [NSMutableArray array];
        NSMutableArray<PPDecodingInfo *> *secondCardDecodingInfoArray = [NSMutableArray array];
        
        NSMutableArray<PPDecodingInfo *> *classificationDecodingInfoArray = [NSMutableArray array];
        
        /** Setup card number decoding */
        [self setCardNumberWithFirstDecodingInfoArray:firstCardDecodingInfoArray andSecondCardDecodingInfoArray:secondCardDecodingInfoArray andClassificationDecodingInfoArray:classificationDecodingInfoArray];
        
        /** Setup security number decoding */
        [self setSecurityNumberWithFirstDecodingInfoArray:firstCardDecodingInfoArray
                           andSecondCardDecodingInfoArray:secondCardDecodingInfoArray
                       andClassificationDecodingInfoArray:classificationDecodingInfoArray];

        /**
         * Create ID card document specification. Document specification defines geometric/scanning properties of documents to be detected
         */
        PPDocumentSpecification *idSpec = [PPDocumentSpecification newFromPreset:PPDocumentPresetId1Card];
        
        /**
         * Set decoding infos as our classification decoding infos. One has location of document number on old id, other on new Id
         */
        [idSpec setDecodingInfo:classificationDecodingInfoArray];
        
        /**
         * Wrap Document specification in detector settings
         */
        PPDocumentDetectorSettings *detectorSettings = [[PPDocumentDetectorSettings alloc] initWithNumStableDetectionsThreshold:1];
        [detectorSettings setDocumentSpecifications:@[ idSpec ]];
        
        /**
         * Add created detector settings to recognizer
         */
        [self setDetectorSettings:detectorSettings];
        /**
         * Set this class as document classifier delegate
         */
        [self setDocumentClassifier:self];
        /**
         * Add decoding infos for classifier results. These infos and their parsers will only be processed if classifier outputs the
         * selected result
         */
        [self setDecodingInfoSet:firstCardDecodingInfoArray forClassifierResult:FIRST_TYPE];
        [self setDecodingInfoSet:secondCardDecodingInfoArray forClassifierResult:SECOND_TYPE];
    }
    return self;
}

#pragma mark - Decoding info

- (void)setCardNumberWithFirstDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)firstCardDecodingInfoArray
                 andSecondCardDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)secondCardDecodingInfoArray
             andClassificationDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)classificationDecodingInfoArray {
    
    int dewarpedHeight = 100;
    
    CGRect firstLocation = CGRectMake(0.3689f, 0.1480f, 0.4531f, 0.0561f);
    CGRect secondLocation = CGRectMake(0.2198f, 0.1732f, 0.4148f, 0.0736f);
    
    [firstCardDecodingInfoArray
     addObject:[[PPDecodingInfo alloc] initWithLocation:firstLocation
                                         dewarpedHeight:dewarpedHeight
                                               uniqueId:CARD_NUMBER_FIRST_TYPE]];
    [secondCardDecodingInfoArray
        addObject:[[PPDecodingInfo alloc] initWithLocation:secondLocation dewarpedHeight:dewarpedHeight uniqueId:CARD_NUMBER_SECOND_TYPE]];

    PPRegexOcrParserFactory *documentNumberParser = [[PPRegexOcrParserFactory alloc] initWithRegex:@"(\\d{4} ?){4}"];
    
    NSMutableSet *charWhitelist = [[NSMutableSet alloc] init];
    // Add chars '0'-'9'
    for (int c = '0'; c <= '9'; c++) {
        [charWhitelist addObject:[PPOcrCharKey keyWithCode:c font:PP_OCR_FONT_ANY]];
    }
    PPOcrEngineOptions *options = [[PPOcrEngineOptions alloc] init];
    options.charWhitelist = charWhitelist;
    options.minimalLineHeight = 30;
    [documentNumberParser setOptions:options];
    
    [self addOcrParser:documentNumberParser name:CARD_NUMBER group:CARD_NUMBER_FIRST_TYPE];
    [self addOcrParser:documentNumberParser name:CARD_NUMBER group:CARD_NUMBER_SECOND_TYPE];
}

- (void)setSecurityNumberWithFirstDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)firstCardDecodingInfoArray
                     andSecondCardDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)secondCardDecodingInfoArray
                 andClassificationDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)classificationDecodingInfoArray {
    
    int dewarpedHeight = 100;
    
    CGRect firstLocation = CGRectMake(0.5016f, 0.2194f, 0.1812f, 0.0612f);
    CGRect secondLocation = CGRectMake(0.7280f, 0.1732f, 0.1978f, 0.0736f);
    
    [classificationDecodingInfoArray addObject:[[PPDecodingInfo alloc] initWithLocation:firstLocation
                                                                         dewarpedHeight:dewarpedHeight
                                                                               uniqueId:CARD_SECURITY_CODE_FIRST_TYPE]];
    
    [classificationDecodingInfoArray addObject:[[PPDecodingInfo alloc] initWithLocation:secondLocation
                                                                            dewarpedHeight:dewarpedHeight
                                                                               uniqueId:CARD_SECURITY_CODE_SECOND_TYPE]];
    
    PPRegexOcrParserFactory *documentNumberParser = [[PPRegexOcrParserFactory alloc] initWithRegex:@"\\d{8}"];
    
    NSMutableSet *charWhitelist = [[NSMutableSet alloc] init];
    // Add chars '0'-'9'
    for (int c = '0'; c <= '9'; c++) {
        [charWhitelist addObject:[PPOcrCharKey keyWithCode:c font:PP_OCR_FONT_ANY]];
    }
    PPOcrEngineOptions *options = [[PPOcrEngineOptions alloc] init];
    options.charWhitelist = charWhitelist;
    options.minimalLineHeight = 30;
    [documentNumberParser setOptions:options];
    
    [self addOcrParser:documentNumberParser name:CARD_SECURITY_CODE group:CARD_SECURITY_CODE_FIRST_TYPE];
    [self addOcrParser:documentNumberParser name:CARD_SECURITY_CODE group:CARD_SECURITY_CODE_SECOND_TYPE];
}

- (NSString *)extractMessageFromResult:(PPBlinkOcrRecognizerResult *)result {
    NSString *message;
    message = @"SECURITY NUMBER: ";
    message = [message stringByAppendingString:[result parsedResultForName:CARD_SECURITY_CODE parserGroup:[CARD_SECURITY_CODE stringByAppendingString:_type]]];
    message = [[message stringByAppendingString:@" \nCARD NUMBER:"]
               stringByAppendingString:[result parsedResultForName:CARD_NUMBER parserGroup:[CARD_NUMBER stringByAppendingString:_type]]];
    return message;
}

#pragma mark - PPDocumentClassifier

- (NSString *)classifyDocumentFromResult:(PPTemplatingRecognizerResult *)result {
    /**
     * Get the result of parsing the location of document number on old ID.
     */
    _type = @"";
    NSString *documentNumber = [result parsedResultForName:CARD_SECURITY_CODE parserGroup:CARD_SECURITY_CODE_FIRST_TYPE];
    if (documentNumber != nil && ![documentNumber isEqualToString:@""]) {
        // If result exists then we are dealing with old ID
        _type = FIRST_TYPE;
    }
    /**
     * Get the result of parsing the location of document number on new ID.
     */
    documentNumber = [result parsedResultForName:CARD_SECURITY_CODE parserGroup:CARD_SECURITY_CODE_SECOND_TYPE];
    if (documentNumber != nil && ![documentNumber isEqualToString:@""]) {
        // If result exists then we are dealing with new ID
        _type = SECOND_TYPE;
    }
    /**
     * Document is detected but it doesnt contain document numbers on their expected locations
     */
    return _type;
}


@end
