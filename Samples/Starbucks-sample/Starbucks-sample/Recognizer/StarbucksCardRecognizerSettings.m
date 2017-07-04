//
//  StarbucksCardRecognizerSettings.m
//  Templating-Sample
//
//  Created by Jure Cular on 29/03/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "StarbucksCardRecognizerSettings.h"

static NSString *const kCardNumber = @"CardNumber";
static NSString *const kSecurityCode = @"SecurityCode";

static NSString *const kCardNumberFirstType = @"CardNumberFirstType";
static NSString *const kCardNumberSecondType = @"CardNumberSecondType";
static NSString *const KCardNumberThirdType = @"CardNumberThirdType";

static NSString *const kSecurityCodeFirstType = @"SecurityCodeFirstType";
static NSString *const kSecurityCodeSecondType = @"SecurityCodeSecondType";
static NSString *const kSecurityCodeThirdType = @"SecurityCodeThirdType";

// Type of card with security code in the middle
static NSString *const kFirstType = @"FirstType";
// Type of card with security code in the upper right corner
static NSString *const kSecondType = @"SecondType";
// Type of card with security code in the lower right corner
static NSString *const kThirdType = @"ThirdType";

// Starbucks card number key
static NSString *const kStarbucksCardNumberKey = @"Starbucks card number";

// Starbucks security code key
static NSString *const kStarbucksSecurityCodeKey = @"Starbucks security code";

static NSString *const kSecurityCodeRegex = @"\\d{8}";

static NSString *const kCardNumberRegex = @"(\\d{4} ){3}(\\d{4})";

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
            @{kFirstType : [NSMutableArray array], kSecondType : [NSMutableArray array], kThirdType : [NSMutableArray array]};

        NSMutableArray<PPDecodingInfo *> *classificationDecodingInfoArray = [NSMutableArray array];

        /** Setup security code decoding */
        [self setSecurityCodeWithDictionaryOfDecodingInfoArray:decodingInfoArrayDictionary];

        /** Setup card number decoding */
        [self setCardNumberWithClassificationDecodingInfoArray:classificationDecodingInfoArray];

        /**
         * Create starbucks card document specification. Document specification defines geometric/scanning properties of documents to be
         * detected
         */
        PPDocumentSpecification *idSpec = [PPDocumentSpecification newFromPreset:PPDocumentPresetId1Card];

        /**
         * Set decoding infos as our classification decoding infos. Each type of card has different location of card number
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

- (void)setSecurityCodeWithDictionaryOfDecodingInfoArray:(NSDictionary *)decodingInfoArrayDictionary {
    int dewarpedHeight = 200;

    // location of security number for every type of card
    CGRect firstLocation = CGRectMake(0.7198f, 0.1602f, 0.2253f, 0.1082f);
    CGRect secondLocation = CGRectMake(0.4750f, 0.2180f, 0.2266f, 0.0800f);
    CGRect thirdLocation = CGRectMake(0.6950f, 0.6416f, 0.2625f, 0.0980f);

    [decodingInfoArrayDictionary[kFirstType]
        addObject:[[PPDecodingInfo alloc] initWithLocation:firstLocation dewarpedHeight:dewarpedHeight uniqueId:kSecurityCodeFirstType]];
    [decodingInfoArrayDictionary[kSecondType]
        addObject:[[PPDecodingInfo alloc] initWithLocation:secondLocation dewarpedHeight:dewarpedHeight uniqueId:kSecurityCodeSecondType]];
    [decodingInfoArrayDictionary[kThirdType]
        addObject:[[PPDecodingInfo alloc] initWithLocation:thirdLocation dewarpedHeight:dewarpedHeight uniqueId:kSecurityCodeThirdType]];


    NSMutableSet *charWhiteList = [self numberWhitelist];

    PPRegexOcrParserFactory *firstLocationSecurityNumber = [self createParserWithCharWhiteList:charWhiteList
                                                                          andMinimalLineHeight:60
                                                                          andMaximalLineHeight:150
                                                                           andMaxCharsExpected:25
                                                                                      andRegex:kSecurityCodeRegex];

    [self addOcrParser:firstLocationSecurityNumber name:kSecurityCode group:kSecurityCodeFirstType];

    PPRegexOcrParserFactory *secondLocationSecurityNumber = [self createParserWithCharWhiteList:charWhiteList
                                                                           andMinimalLineHeight:80
                                                                           andMaximalLineHeight:150
                                                                            andMaxCharsExpected:15
                                                                                       andRegex:kSecurityCodeRegex];

    [self addOcrParser:secondLocationSecurityNumber name:kSecurityCode group:kSecurityCodeSecondType];

    PPRegexOcrParserFactory *thirdLocationSecurityNumber = [self createParserWithCharWhiteList:charWhiteList
                                                                          andMinimalLineHeight:70
                                                                          andMaximalLineHeight:120
                                                                           andMaxCharsExpected:35
                                                                                      andRegex:kSecurityCodeRegex];

    [self addOcrParser:thirdLocationSecurityNumber name:kSecurityCode group:kSecurityCodeThirdType];
}

- (void)setCardNumberWithClassificationDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)classificationDecodingInfoArray {
    int dewarpedHeight = 100;

    // location of card number for every type of card
    CGRect firstLocation = CGRectMake(0.2088f, 0.1688f, 0.5500f, 0.0866f);
    CGRect secondLocation = CGRectMake(0.3406f, 0.1303f, 0.5125f, 0.0977f);
    CGRect thirdLocation = CGRectMake(0.2000f, 0.6700f, 0.5000f, 0.0700f);
    [classificationDecodingInfoArray
        addObject:[[PPDecodingInfo alloc] initWithLocation:firstLocation dewarpedHeight:dewarpedHeight uniqueId:kCardNumberFirstType]];

    [classificationDecodingInfoArray
        addObject:[[PPDecodingInfo alloc] initWithLocation:secondLocation dewarpedHeight:dewarpedHeight uniqueId:kCardNumberSecondType]];

    [classificationDecodingInfoArray
        addObject:[[PPDecodingInfo alloc] initWithLocation:thirdLocation dewarpedHeight:dewarpedHeight uniqueId:KCardNumberThirdType]];

    NSMutableSet *charWhiteList = [self numberWhitelist];

    for (int c = 'a'; c <= 'z'; c++) {
        [charWhiteList addObject:[PPOcrCharKey keyWithCode:c font:PP_OCR_FONT_ANY]];
    }

    PPRegexOcrParserFactory *firstLocationCardNumber = [self createParserWithCharWhiteList:charWhiteList
                                                                      andMinimalLineHeight:50
                                                                      andMaximalLineHeight:100
                                                                       andMaxCharsExpected:150
                                                                                  andRegex:kCardNumberRegex];

    [self addOcrParser:firstLocationCardNumber name:kCardNumber group:kCardNumberFirstType];

    PPRegexOcrParserFactory *secondLocationCardNumber = [self createParserWithCharWhiteList:charWhiteList
                                                                       andMinimalLineHeight:50
                                                                       andMaximalLineHeight:100
                                                                        andMaxCharsExpected:150
                                                                                   andRegex:kCardNumberRegex];

    [self addOcrParser:secondLocationCardNumber name:kCardNumber group:kCardNumberSecondType];

    PPRegexOcrParserFactory *thirdLocationCardNumber = [self createParserWithCharWhiteList:charWhiteList
                                                                      andMinimalLineHeight:50
                                                                      andMaximalLineHeight:100
                                                                       andMaxCharsExpected:150
                                                                                  andRegex:kCardNumberRegex];

    [self addOcrParser:firstLocationCardNumber name:kCardNumber group:kCardNumberFirstType];
    [self addOcrParser:secondLocationCardNumber name:kCardNumber group:kCardNumberSecondType];
    [self addOcrParser:thirdLocationCardNumber name:kCardNumber group:KCardNumberThirdType];
}

#pragma mark - Parser creation

- (PPRegexOcrParserFactory *)createParserWithCharWhiteList:(NSMutableSet *)charWhiteList
                                      andMinimalLineHeight:(NSUInteger)minimalLineHeight
                                      andMaximalLineHeight:(NSUInteger)maximalLineHeight
                                       andMaxCharsExpected:(NSUInteger)maxCharsExpected
                                                  andRegex:(NSString *)regex {
    PPRegexOcrParserFactory *parser = [[PPRegexOcrParserFactory alloc] initWithRegex:regex];

    parser.startsWithWhitespace = YES;
    parser.endsWithWhitespace = YES;

    PPOcrEngineOptions *engineOptions = [[PPOcrEngineOptions alloc] init];

    engineOptions.charWhitelist = charWhiteList;
    engineOptions.minimalLineHeight = minimalLineHeight;
    engineOptions.maximalLineHeight = maximalLineHeight;
    engineOptions.maxCharsExpected = maxCharsExpected;
    engineOptions.colorDropoutEnabled = NO;

    [parser setOptions:engineOptions];

    return parser;
}

#pragma mark - Message extraction

- (NSDictionary *)extractMessageFromResult:(PPBlinkOcrRecognizerResult *)result {
    NSMutableDictionary *resultsDictionary = [[NSMutableDictionary alloc] init];

    NSString *securityNumber = [result parsedResultForName:kSecurityCode parserGroup:[kSecurityCode stringByAppendingString:self.type]];
    if (![securityNumber isEqualToString:@""]) {
        [resultsDictionary setObject:securityNumber forKey:kStarbucksSecurityCodeKey];
    }
    NSString *cardNumber = [result parsedResultForName:kCardNumber parserGroup:[kCardNumber stringByAppendingString:self.type]];
    if (![cardNumber isEqualToString:@""]) {
        [resultsDictionary setObject:cardNumber forKey:kStarbucksCardNumberKey];
    }
    return resultsDictionary;
}

#pragma mark - PPDocumentClassifier

- (NSString *)classifyDocumentFromResult:(PPTemplatingRecognizerResult *)result {
    self.type = @"";

    NSString *cardNumber = [result parsedResultForName:kCardNumber parserGroup:kCardNumberFirstType];

    if (cardNumber != nil && ![cardNumber isEqualToString:@""]) {
        // If result exists then we are dealing with first type card
        self.type = kFirstType;
        return self.type;
    }

    cardNumber = [result parsedResultForName:kCardNumber parserGroup:kCardNumberSecondType];

    if (cardNumber != nil && ![cardNumber isEqualToString:@""]) {
        // If result exists then we are dealing with second type card
        self.type = kSecondType;
        return self.type;
    }


    cardNumber = [result parsedResultForName:kCardNumber parserGroup:KCardNumberThirdType];

    if (cardNumber != nil && ![cardNumber isEqualToString:@""]) {
        // If result exists then we are dealing with third type card
        self.type = kThirdType;
        return self.type;
    }

    return self.type;
}


@end
