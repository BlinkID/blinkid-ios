//
//  CroIdRecognizerSettings.m
//  Templating-Sample
//
//  Created by Jure Cular on 29/03/2017.
//  Copyright © 2017 Dino. All rights reserved.
//

#import "CroIdRecognizerSettings.h"

static NSString * const ID_LAST_NAME = @"LastName";
static NSString * const ID_FIRST_NAME = @"FirstName";
static NSString * const ID_SEX_CITIZENSHIP_DOB = @"SexCitizenshipDob";
static NSString * const ID_SEX = @"Sex";
static NSString * const ID_CITIZENSHIP = @"Citizenship";
static NSString * const ID_DATE_OF_BIRTH = @"DateOfBirth";
static NSString * const ID_DOCUMENT_NUMBER = @"DocumentNumber";
static NSString * const ID_DOCUMENT_NUMBER_OLD = @"DocumentNumberOld";
static NSString * const ID_DOCUMENT_NUMBER_NEW = @"DocumentNumberNew";

static NSString * const CLASS_OLD_ID = @"oldCroId";
static NSString * const CLASS_NEW_ID = @"newCroId";

@interface CroIdRecognizerSettings() <PPDocumentClassifier>

@end

@implementation CroIdRecognizerSettings 

- (NSMutableSet *)uppercaseCharsWhitelist {
    
    // initialize new char whitelist
    NSMutableSet *charWhitelist = [[NSMutableSet alloc] init];
    
    // Add chars 'A'-'Z'
    for (int c = 'A'; c <= 'Z'; c++) {
        [charWhitelist addObject:[PPOcrCharKey keyWithCode:c font:PP_OCR_FONT_ANY]];
    }
    return charWhitelist;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        NSMutableArray<PPDecodingInfo *> *oldIdDecodingInfoArray = [NSMutableArray array];
        NSMutableArray<PPDecodingInfo *> *newIdDecodingInfoArray = [NSMutableArray array];
        
        NSMutableArray<PPDecodingInfo *> *classificationDecodingInfoArray = [NSMutableArray array];
        
        /** Setup first name decoding */
        [self setFirstNameDecodingWithOldDecodingInfoArray:oldIdDecodingInfoArray andNewOldDecodingInfoArray:newIdDecodingInfoArray];
        
        /** Setup last name decoding */
        [self setLastNameDecodingWithOldDecodingInfoArray:oldIdDecodingInfoArray andNewOldDecodingInfoArray:newIdDecodingInfoArray];
        /** Setup sex, citizenship and date of birth */
        [self setSexCitizesnhipAndDoBWithOldIdDecodingInfoArray:oldIdDecodingInfoArray andNewIdDecodingInfoArray:newIdDecodingInfoArray];
        /** Setup document number */
        [self setDocumentNumberWithOldIdDecodingInfoArray:oldIdDecodingInfoArray
                                andNewIdDecodingInfoArray:newIdDecodingInfoArray
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
        [self setDecodingInfoSet:newIdDecodingInfoArray forClassifierResult:CLASS_NEW_ID];
        [self setDecodingInfoSet:oldIdDecodingInfoArray forClassifierResult:CLASS_OLD_ID];
    }
    return self;
}

#pragma mark - Decoding info

- (void)setFirstNameDecodingWithOldDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)oldIdDecodingInfoArray
                         andNewOldDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)newIdDecodingInfoArray {
    /** Pixel height of returned image */
    int dewarpHeight = 150;
    
    /**
     * For extracting first and last names, we will use regex parser with regular expression which
     * attempts to extract as many uppercase words as possible from single line.
     */
    PPRegexOcrParserFactory *firstNameParser = [[PPRegexOcrParserFactory alloc] initWithRegex:@"([A-ZŠĐŽČĆ]+ ?)+"];
    
    /**
     * tweak OCR engine options - allow only recognition of uppercase letters used in Croatia
     */
    PPOcrEngineOptions *options = [[PPOcrEngineOptions alloc] init];
    options.charWhitelist = [self uppercaseCharsWhitelist];
    [firstNameParser setOptions:options];
    
    /**
     * Add parser to recognizer settings
     */
    [self addOcrParser:firstNameParser name:ID_FIRST_NAME group:ID_FIRST_NAME];
    
    /**
     * Locations of first name string on borth old and new ID cards
     */
    CGRect oldIdNameLocation = CGRectMake(0.282, 0.333, 0.306, 0.167);
    CGRect newIdNameLocation = CGRectMake(0.282, 0.389, 0.353, 0.167);
    
    /**
     * Add locations to list
     * Since we want to use selected parsers on these locations, uniqueId of decoding infos must be the same as parser group id.
     */
    [oldIdDecodingInfoArray
     addObject:[[PPDecodingInfo alloc] initWithLocation:oldIdNameLocation dewarpedHeight:dewarpHeight uniqueId:ID_FIRST_NAME]];
    [newIdDecodingInfoArray
     addObject:[[PPDecodingInfo alloc] initWithLocation:newIdNameLocation dewarpedHeight:dewarpHeight uniqueId:ID_FIRST_NAME]];
}

- (void)setLastNameDecodingWithOldDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)oldIdDecodingInfoArray
                        andNewOldDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)newIdDecodingInfoArray {
    int dewarpHeight = 150;
    PPRegexOcrParserFactory *lastNameParser = [[PPRegexOcrParserFactory alloc] initWithRegex:@"([A-ZŠĐŽČĆ]+ ?)+"];
    
    PPOcrEngineOptions *options = [[PPOcrEngineOptions alloc] init];
    options.charWhitelist = [self uppercaseCharsWhitelist];
    [lastNameParser setOptions:options];
    
    [self addOcrParser:lastNameParser name:ID_LAST_NAME group:ID_LAST_NAME];
    
    CGRect oldIdNameLocation = CGRectMake(0.271, 0.204, 0.318, 0.111);
    CGRect newIdNameLocation = CGRectMake(0.282, 0.204, 0.353, 0.167);
    [oldIdDecodingInfoArray
     addObject:[[PPDecodingInfo alloc] initWithLocation:oldIdNameLocation dewarpedHeight:dewarpHeight uniqueId:ID_LAST_NAME]];
    [newIdDecodingInfoArray addObject:[[PPDecodingInfo alloc] initWithLocation:newIdNameLocation dewarpedHeight:dewarpHeight uniqueId:ID_LAST_NAME]];
}

- (void)setSexCitizesnhipAndDoBWithOldIdDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)oldIdDecodingInfoArray
                                andNewIdDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)newIdDecodingInfoArray {
    /**
     * Since sex, citizenship and date of birth are located closely within eachother and their value formats are mutually exclusive,
     * We can use 1 Decoding info and parse the whole image with each parser to maximize performance. (this way we parser 1 image 3
     * times, instead of 3 images each once)
     */
    
    /** Setup sex parser */
    PPRegexOcrParserFactory *sexParser = [[PPRegexOcrParserFactory alloc] initWithRegex:@"[MŽ]/[MF]"];
    NSMutableSet *charWhitelist = [[NSMutableSet alloc] init];
    [charWhitelist addObject:[PPOcrCharKey keyWithCode:'M' font:PP_OCR_FONT_ANY]];
    [charWhitelist addObject:[PPOcrCharKey keyWithCode:'F' font:PP_OCR_FONT_ANY]];
    [charWhitelist addObject:[PPOcrCharKey keyWithCode:'/' font:PP_OCR_FONT_ANY]];
    [charWhitelist addObject:[PPOcrCharKey keyWithCode:0xC5 font:PP_OCR_FONT_ANY]];
    PPOcrEngineOptions *options = [[PPOcrEngineOptions alloc] init];
    options.charWhitelist = charWhitelist;
    [sexParser setOptions:options];
    
    [self addOcrParser:sexParser name:ID_SEX group:ID_SEX_CITIZENSHIP_DOB];
    
    /** Setup citizenship parser */
    PPRegexOcrParserFactory *citizenshipParser = [[PPRegexOcrParserFactory alloc] initWithRegex:@"[A-Z]{3}"];
    options = [[PPOcrEngineOptions alloc] init];
    options.charWhitelist = [self uppercaseCharsWhitelist];
    [citizenshipParser setOptions:options];
    
    [self addOcrParser:citizenshipParser name:ID_CITIZENSHIP group:ID_SEX_CITIZENSHIP_DOB];
    
    /** Setup date of birth */
    [self addOcrParser:[[PPDateOcrParserFactory alloc] init] name:ID_DATE_OF_BIRTH group:ID_SEX_CITIZENSHIP_DOB];
    
    /**
     * To have multiple parsers on 1 decoding info we need to have them all in the same group. That group must have the same id
     * (group name) as decoding info uniqueId.
     */
    
    CGRect oldLocation = CGRectMake(0.412, 0.500, 0.259, 0.296);
    CGRect newLocation = CGRectMake(0.388, 0.500, 0.282, 0.296);
    
    [oldIdDecodingInfoArray
     addObject:[[PPDecodingInfo alloc] initWithLocation:oldLocation dewarpedHeight:300 uniqueId:ID_SEX_CITIZENSHIP_DOB]];
    [newIdDecodingInfoArray
     addObject:[[PPDecodingInfo alloc] initWithLocation:newLocation dewarpedHeight:300 uniqueId:ID_SEX_CITIZENSHIP_DOB]];
    
}

- (void)setDocumentNumberWithOldIdDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)oldIdDecodingInfoArray
                          andNewIdDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)newIdDecodingInfoArray
                 andClassificationDecodingInfoArray:(NSMutableArray<PPDecodingInfo *> *)classificationDecodingInfoArray {
    /**
     * Since document number is located differently on old and new ID cards, we will use it as our classification.
     */
    
    [classificationDecodingInfoArray addObject:[[PPDecodingInfo alloc] initWithLocation:CGRectMake(0.047, 0.519, 0.224, 0.111)
                                                                         dewarpedHeight:150
                                                                               uniqueId:ID_DOCUMENT_NUMBER_OLD]];
    [classificationDecodingInfoArray addObject:[[PPDecodingInfo alloc] initWithLocation:CGRectMake(0.047, 0.685, 0.224, 0.111)
                                                                         dewarpedHeight:150
                                                                               uniqueId:ID_DOCUMENT_NUMBER_NEW]];
    
    PPRegexOcrParserFactory *documentNumberParser = [[PPRegexOcrParserFactory alloc] initWithRegex:@"\\d{9}"];
    
    NSMutableSet *charWhitelist = [[NSMutableSet alloc] init];
    // Add chars '0'-'9'
    for (int c = '0'; c <= '9'; c++) {
        [charWhitelist addObject:[PPOcrCharKey keyWithCode:c font:PP_OCR_FONT_ANY]];
    }
    PPOcrEngineOptions *options = [[PPOcrEngineOptions alloc] init];
    options.charWhitelist = charWhitelist;
    options.minimalLineHeight = 35;
    [documentNumberParser setOptions:options];
    
    [self addOcrParser:documentNumberParser name:ID_DOCUMENT_NUMBER group:ID_DOCUMENT_NUMBER_NEW];
    [self addOcrParser:documentNumberParser name:ID_DOCUMENT_NUMBER group:ID_DOCUMENT_NUMBER_OLD];
}

- (NSString *)extractMessageFromResult:(PPBlinkOcrRecognizerResult *)result {
    NSString *message;
    message = [result parsedResultForName:ID_SEX parserGroup:ID_SEX_CITIZENSHIP_DOB];
    message = [[message stringByAppendingString:@" "]
               stringByAppendingString:[result parsedResultForName:ID_CITIZENSHIP parserGroup:ID_SEX_CITIZENSHIP_DOB]];
    message = [[message stringByAppendingString:@" "]
               stringByAppendingString:[result parsedResultForName:ID_DATE_OF_BIRTH parserGroup:ID_SEX_CITIZENSHIP_DOB]];
    message = [[message stringByAppendingString:@" "]
               stringByAppendingString:[result parsedResultForName:ID_FIRST_NAME parserGroup:ID_FIRST_NAME]];
    return message;
}

#pragma mark - PPDocumentClassifier

- (NSString *)classifyDocumentFromResult:(PPTemplatingRecognizerResult *)result {
    /**
     * Get the result of parsing the location of document number on old ID.
     */
    NSString *documentNumber = [result parsedResultForName:ID_DOCUMENT_NUMBER parserGroup:ID_DOCUMENT_NUMBER_OLD];
    if (documentNumber != nil && ![documentNumber isEqualToString:@""]) {
        // If result exists then we are dealing with old ID
        return CLASS_OLD_ID;
    }
    /**
     * Get the result of parsing the location of document number on new ID.
     */
    documentNumber = [result parsedResultForName:ID_DOCUMENT_NUMBER parserGroup:ID_DOCUMENT_NUMBER_NEW];
    if (documentNumber != nil && ![documentNumber isEqualToString:@""]) {
        // If result exists then we are dealing with new ID
        return CLASS_NEW_ID;
    }
    /**
     * Document is detected but it doesnt contain document numbers on their expected locations
     */
    return @"";
}


@end
