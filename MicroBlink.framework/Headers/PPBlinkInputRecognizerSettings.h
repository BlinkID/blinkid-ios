//
//  PPBlinkInputRecognizerSettings.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 03/08/2017.
//
//

#import "PPSegmentRecognizerSettings.h"

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

/**
 * Base class for BlinkInput API and general OCR recognition.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPBlinkInputRecognizerSettings : PPSegmentRecognizerSettings

@end
