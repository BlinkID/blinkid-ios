//
//  StarbucksCardRecognizerSettings.m
//  Templating-Sample
//
//  Created by Jure Cular on 29/03/2017.
//  Copyright © 2017 Dino. All rights reserved.
//

#import "StarbucksCardRecognizerSettings.h"

static NSString *const CARD_NUMBER = @"CardNumber";
static NSString *const CARD_SECURITY_CODE = @"SecurityCode";

static NSString *const CARD_NUMBER_FIRST_TYPE = @"CardNumberFirstType";
static NSString *const CARD_NUMBER_SECOND_TYPE = @"CardNumberSecondType";
static NSString *const CARD_NUMBER_THIRD_TYPE = @"CardNumberThirdType";

static NSString *const CARD_SECURITY_CODE_FIRST_TYPE = @"SecurityCodeFirstType";
static NSString *const CARD_SECURITY_CODE_SECOND_TYPE = @"SecurityCodeSecondType";
static NSString *const CARD_SECURITY_CODE_THIRD_TYPE = @"SecurityCodeThirdType";

static NSString *const FIRST_TYPE = @"FirstType";
static NSString *const SECOND_TYPE = @"SecondType";
static NSString *const THIRD_TYPE = @"ThirdType";

@interface StarbucksCardRecognizerSettings () <PPDocumentClassifier>

@property (strong, nonatomic) NSString *type;

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

        NSDictionary *decodingInfoArrayDictionary =
            @{FIRST_TYPE : [NSMutableArray array], SECOND_TYPE : [NSMutableArray array], THIRD_TYPE : [NSMutableArray array]};
        
        NSMutableArray<PPDecodingInfo *> *classificationDecodingInfoArray = [NSMutableArray array];

        /** Setup card number decoding */
        [self setCardNumberWithDictionaryOfDecodingInfoArray:decodingInfoArrayDictionary];
        
        /** Setup security number decoding */
        [self setSecurityNumberWithClassificationDecodingInfoArray:classificationDecodingInfoArray];

        /**
         * Create star bucks card document specification. Document specification defines geometric/scanning properties of documents to be detected
         */
        PPDocumentSpecification *idSpec = [PPDocumentSpecification newFromPreset:PPDocumentPresetId1Card];

        /**
         * Set decoding infos as our classification decoding infos. Each type of card has different location of security number
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
        
        for (NSString *key in decodingInfoArrayDictionary) {
            [self setDecodingInfoSet:decodingInfoArrayDictionary[key] forClassifierResult:key];
        }
    }
    return self;
}

#pragma mark - Decoding info

- (void)setCardNumberWithDictionaryOfDecodingInfoArray:(NSDictionary *)decodingInfoArrayDictionary {

    int dewarpedHeight = 100;
    
    CGRect firstLocation = CGRectMake(0.2328f, 0.1253f, 0.5953f, 0.0927f);
    CGRect secondLocation = CGRectMake(0.2088f, 0.1688f, 0.5500f, 0.0866f);
    CGRect thirdLocation = CGRectMake(0.2225f, 0.6554f, 0.4812f, 0.0871f);

    [decodingInfoArrayDictionary[FIRST_TYPE]
        addObject:[[PPDecodingInfo alloc] initWithLocation:firstLocation dewarpedHeight:dewarpedHeight uniqueId:CARD_NUMBER_FIRST_TYPE]];
    [decodingInfoArrayDictionary[SECOND_TYPE]
     addObject:[[PPDecodingInfo alloc] initWithLocation:secondLocation dewarpedHeight:dewarpedHeight uniqueId:CARD_NUMBER_SECOND_TYPE]];
    [decodingInfoArrayDictionary[THIRD_TYPE]
     addObject:[[PPDecodingInfo alloc] initWithLocation:thirdLocation dewarpedHeight:dewarpedHeight uniqueId:CARD_NUMBER_THIRD_TYPE]];

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
    [self addOcrParser:documentNumberParser name:CARD_NUMBER group:CARD_NUMBER_THIRD_TYPE];
}

- (void)setSecurityNumberWithClassificationDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)classificationDecodingInfoArray {

    int dewarpedHeight = 100;

    CGRect firstLocation = CGRectMake(0.4953f, 0.2180f, 0.2266f, 0.0677f);
    CGRect secondLocation = CGRectMake(0.7198f, 0.1602f, 0.2253f, 0.1082f);
    CGRect thirdLocation = CGRectMake(0.7238f, 0.6436f, 0.2338f, 0.0851f);

    [classificationDecodingInfoArray addObject:[[PPDecodingInfo alloc] initWithLocation:firstLocation
                                                                         dewarpedHeight:dewarpedHeight
                                                                               uniqueId:CARD_SECURITY_CODE_FIRST_TYPE]];

    [classificationDecodingInfoArray addObject:[[PPDecodingInfo alloc] initWithLocation:secondLocation
                                                                         dewarpedHeight:dewarpedHeight
                                                                               uniqueId:CARD_SECURITY_CODE_SECOND_TYPE]];
    
    [classificationDecodingInfoArray addObject:[[PPDecodingInfo alloc] initWithLocation:thirdLocation
                                                                         dewarpedHeight:dewarpedHeight
                                                                               uniqueId:CARD_SECURITY_CODE_THIRD_TYPE]];

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
    [self addOcrParser:documentNumberParser name:CARD_SECURITY_CODE group:CARD_SECURITY_CODE_THIRD_TYPE];
}

- (NSString *)extractMessageFromResult:(PPBlinkOcrRecognizerResult *)result {
    NSString *message;
    message = @"SECURITY NUMBER: ";
    message = [message stringByAppendingString:[result parsedResultForName:CARD_SECURITY_CODE
                                                               parserGroup:[CARD_SECURITY_CODE stringByAppendingString:_type]]];
    message = [[message stringByAppendingString:@" \nCARD NUMBER:"]
        stringByAppendingString:[result parsedResultForName:CARD_NUMBER parserGroup:[CARD_NUMBER stringByAppendingString:_type]]];
    return message;
}

#pragma mark - PPDocumentClassifier

- (NSString *)classifyDocumentFromResult:(PPTemplatingRecognizerResult *)result {
    _type = @"";
    NSString *securityNumber =  [result parsedResultForName:CARD_SECURITY_CODE parserGroup:CARD_SECURITY_CODE_THIRD_TYPE];
    
    if (securityNumber != nil && ![securityNumber isEqualToString:@""] ){
        // If result exists then we are dealing with third type card
        _type = THIRD_TYPE;
        return _type;
    }
    
    securityNumber = [result parsedResultForName:CARD_SECURITY_CODE parserGroup:CARD_SECURITY_CODE_FIRST_TYPE];
    
    if (securityNumber != nil && ![securityNumber isEqualToString:@""] ){
        // If result exists then we are dealing with second type card
        _type = FIRST_TYPE;
        return _type;
    }
    
    securityNumber = [result parsedResultForName:CARD_SECURITY_CODE parserGroup:CARD_SECURITY_CODE_SECOND_TYPE];

    if (securityNumber != nil && ![securityNumber isEqualToString:@""] ){
        // If result exists then we are dealing with first type card
        _type = SECOND_TYPE;
        return _type;
    }
    
    return _type;
}


@end
