//
//  StarbucksCardRecognizerSettings.m
//  Templating-Sample
//
//  Created by Jure Cular on 29/03/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import "StarbucksCardRecognizerSettings.h"

#import "CardTypeFactory.h"
#import "TopCenterCardNumberType.h"
#import "TopLeftCardNumberType.h"
#import "BottomLeftCardNumberType.h"

/* String constants */

// Card number string key
static NSString *const kCardNumber = @"CardNumber";

// Security code string key
static NSString *const kSecurityCode = @"SecurityCode";

// Starbucks card number key
static NSString *const kStarbucksCardNumberKey = @"Starbucks card number";

// Starbucks security code key
static NSString *const kStarbucksSecurityCodeKey = @"Starbucks security code";

@interface StarbucksCardRecognizerSettings () <PPDocumentClassifier>

@property (strong, nonatomic) NSString *type;

@property (strong, nonatomic) NSArray<BaseCardType *> *cardDecodingInfos;

@property (strong, nonatomic) BaseCardType *scannedTypeCardDecodingInfo;

@end

@implementation StarbucksCardRecognizerSettings

#pragma mark - Lifecycle

- (instancetype)init {
    self = [super init];
    if (self) {
        NSMutableArray *cardDecodingInfo = [[NSMutableArray alloc] init];

        NSMutableDictionary *decodingInfoArrayDictionary = [[NSMutableDictionary alloc] init];
        NSMutableArray<PPDecodingInfo *> *classificationDecodingInfoArray = [NSMutableArray array];

        for (CardTypeEnum i = TopCenterCardNumberTypeEnum; i <= BottomLeftCardNumberTypeEnum; ++i) {
            NSMutableArray *securityCodeDecodingInfo = [NSMutableArray array];

            /** Setup security code decoding */
            BaseCardType *cardType = [CardTypeFactory createCardInfoForType:i];
            [cardDecodingInfo addObject:cardType];

            [securityCodeDecodingInfo addObject:cardType.securityCodeDecodingInfo];
            decodingInfoArrayDictionary[cardType.cardTypeKey] = securityCodeDecodingInfo;

            [self addOcrParser:cardType.securityCodeRegexParser name:kSecurityCode group:cardType.securityCodeKey];

            /** Setup card number decoding */
            [classificationDecodingInfoArray addObject:cardType.cardNumberDecodingInfo];
            [self addOcrParser:cardType.cardNumberRegexParser name:kCardNumber group:cardType.cardNumberKey];
        }

        self.cardDecodingInfos = cardDecodingInfo;

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

#pragma mark - Public

- (NSDictionary *)extractMessageFromResult:(PPBlinkOcrRecognizerResult *)result {
    NSMutableDictionary *resultsDictionary = [[NSMutableDictionary alloc] init];

    NSString *securityNumber = [result parsedResultForName:kSecurityCode parserGroup:[self.scannedTypeCardDecodingInfo securityCodeKey]];
    if (![securityNumber isEqualToString:@""]) {
        resultsDictionary[kStarbucksSecurityCodeKey] = securityNumber;
    }

    NSString *cardNumber = [result parsedResultForName:kCardNumber parserGroup:[self.scannedTypeCardDecodingInfo cardNumberKey]];
    if (![cardNumber isEqualToString:@""]) {
        resultsDictionary[kStarbucksCardNumberKey] = cardNumber;
    }

    return resultsDictionary;
}

#pragma mark - PPDocumentClassifier

- (NSString *)classifyDocumentFromResult:(PPTemplatingRecognizerResult *)result {
    for (BaseCardType *cardDecodingInfo in self.cardDecodingInfos) {
        NSString *cardNumber = [result parsedResultForName:kCardNumber parserGroup:cardDecodingInfo.cardNumberKey];
        if (cardNumber != nil && ![cardNumber isEqualToString:@""]) {
            // If result exists then we are dealing with first type card
            self.scannedTypeCardDecodingInfo = cardDecodingInfo;
            return cardDecodingInfo.cardTypeKey;
        }
    }
    return @"";
}

@end
