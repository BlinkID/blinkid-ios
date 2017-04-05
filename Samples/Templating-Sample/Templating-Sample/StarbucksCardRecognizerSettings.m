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

- (NSMutableSet *)numberWhitelist {

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
    
    CGRect firstLocation = CGRectMake(0.3406f, 0.1303f, 0.5125f, 0.0977f);//0.2062f, 0.1278f, 0.6625f, 0.0927f);
    CGRect secondLocation = CGRectMake(0.2088f, 0.1688f, 0.5500f, 0.0866f);
    CGRect thirdLocation = CGRectMake(0.2000f, 0.6700f, 0.5000f, 0.0700f);

    [decodingInfoArrayDictionary[FIRST_TYPE]
        addObject:[[PPDecodingInfo alloc] initWithLocation:firstLocation dewarpedHeight:dewarpedHeight uniqueId:CARD_NUMBER_FIRST_TYPE]];
    [decodingInfoArrayDictionary[SECOND_TYPE]
     addObject:[[PPDecodingInfo alloc] initWithLocation:secondLocation dewarpedHeight:dewarpedHeight uniqueId:CARD_NUMBER_SECOND_TYPE]];
    [decodingInfoArrayDictionary[THIRD_TYPE]
     addObject:[[PPDecodingInfo alloc] initWithLocation:thirdLocation dewarpedHeight:dewarpedHeight uniqueId:CARD_NUMBER_THIRD_TYPE]];

    PPRegexOcrParserFactory *documentNumberParser = [[PPRegexOcrParserFactory alloc] initWithRegex:@"(\\d{4} ){3}(\\d{4})"];

    PPOcrEngineOptions *options = [[PPOcrEngineOptions alloc] init];
    options.charWhitelist = [self numberWhitelist];
    options.minimalLineHeight = 40;
    options.maximalLineHeight = 100;
    options.maxCharsExpected = 150;
    [documentNumberParser setOptions:options];

   
    
    [self addOcrParser:documentNumberParser name:CARD_NUMBER group:CARD_NUMBER_FIRST_TYPE];
    [self addOcrParser:documentNumberParser name:CARD_NUMBER group:CARD_NUMBER_SECOND_TYPE];
    [self addOcrParser:documentNumberParser name:CARD_NUMBER group:CARD_NUMBER_THIRD_TYPE];
}

- (void)setSecurityNumberWithClassificationDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)classificationDecodingInfoArray {

    int dewarpedHeight = 200;

    CGRect firstLocation = CGRectMake(0.4750f, 0.2180f, 0.2266f, 0.0800f);
    CGRect secondLocation = CGRectMake(0.7198f, 0.1602f, 0.2253f, 0.1082f);
    CGRect thirdLocation = CGRectMake(0.6950f, 0.6416f, 0.2625f, 0.0980f);

    [classificationDecodingInfoArray addObject:[[PPDecodingInfo alloc] initWithLocation:firstLocation
                                                                         dewarpedHeight:dewarpedHeight
                                                                               uniqueId:CARD_SECURITY_CODE_FIRST_TYPE]];

    [classificationDecodingInfoArray addObject:[[PPDecodingInfo alloc] initWithLocation:secondLocation
                                                                         dewarpedHeight:dewarpedHeight
                                                                               uniqueId:CARD_SECURITY_CODE_SECOND_TYPE]];
    
    [classificationDecodingInfoArray addObject:[[PPDecodingInfo alloc] initWithLocation:thirdLocation
                                                                         dewarpedHeight:dewarpedHeight
                                                                               uniqueId:CARD_SECURITY_CODE_THIRD_TYPE]];


    NSMutableSet *charWhiteList = [self numberWhitelist];
    
    for (int c = 'a'; c <= 'z'; c++) {
        [charWhiteList addObject:[PPOcrCharKey keyWithCode:c font:PP_OCR_FONT_ANY]];
    }
    
    PPRegexOcrParserFactory *firstLocationSecurityNumber = [self createSecurityNumberParserWithCharWhiteList:charWhiteList
                                                                                         andMinimalLineHeight:80
                                                                                         andMaximalLineHeight:150
                                                                                        andMaxCharsExpected:15];

    [self addOcrParser:firstLocationSecurityNumber name:CARD_SECURITY_CODE group:CARD_SECURITY_CODE_FIRST_TYPE];

    PPRegexOcrParserFactory *secondLocationSecurityNumber = [self createSecurityNumberParserWithCharWhiteList:charWhiteList
                                                                                         andMinimalLineHeight:60
                                                                                         andMaximalLineHeight:150
                                                                                          andMaxCharsExpected:35];

    [self addOcrParser:secondLocationSecurityNumber name:CARD_SECURITY_CODE group:CARD_SECURITY_CODE_SECOND_TYPE];

    PPRegexOcrParserFactory *thirdLocationSecurityNumber = [self createSecurityNumberParserWithCharWhiteList:charWhiteList
                                                                                        andMinimalLineHeight:70
                                                                                        andMaximalLineHeight:120
                                                                                         andMaxCharsExpected:25];

    [self addOcrParser:thirdLocationSecurityNumber name:CARD_SECURITY_CODE group:CARD_SECURITY_CODE_THIRD_TYPE];
}

#pragma mark - Parser creation

- (PPRegexOcrParserFactory *)createSecurityNumberParserWithCharWhiteList:(NSMutableSet *)charWhiteList
                                        andMinimalLineHeight:(NSUInteger)minimalLineHeight
                                        andMaximalLineHeight:(NSUInteger)maximalLineHeight
                                         andMaxCharsExpected:(NSUInteger)maxCharsExpected {
    PPRegexOcrParserFactory *securityNumberParser = [[PPRegexOcrParserFactory alloc] initWithRegex:@"\\d{8}"];
    
    PPOcrEngineOptions *engineOptions = [[PPOcrEngineOptions alloc] init];
    
    engineOptions.charWhitelist = charWhiteList;
    engineOptions.minimalLineHeight = minimalLineHeight;
    engineOptions.maximalLineHeight = maximalLineHeight;
    engineOptions.maxCharsExpected = maxCharsExpected;
    
    [securityNumberParser setOptions:engineOptions];

    return securityNumberParser;
}

#pragma mark - Message extraction

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
    
    NSString *securityNumber = [result parsedResultForName:CARD_SECURITY_CODE parserGroup:CARD_SECURITY_CODE_FIRST_TYPE];
    
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
    
    securityNumber =  [result parsedResultForName:CARD_SECURITY_CODE parserGroup:CARD_SECURITY_CODE_THIRD_TYPE];
    
    if (securityNumber != nil && ![securityNumber isEqualToString:@""] ){
        // If result exists then we are dealing with third type card
        _type = THIRD_TYPE;
        return _type;
    }
    
    return _type;
}


@end
