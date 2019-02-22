//
//  Microblink.h
//  MicroblinkFramework
//
//  Created by Dino Gustin on 06/06/18.
//  Copyright (c) 2012 Microblink Ltd. All rights reserved.
//

#import "MBBarcodeEntities.h"

/** MRTD Detector*/
#import "MBMrtdDetector.h"
#import "MBMrtdDetectorResult.h"

#import "MBDocumentDetector.h"
#import "MBDocumentDetectorResult.h"

/** BlinkInput */
#import "MBBlinkInputRecognizer.h"
#import "MBBlinkInputRecognizerResult.h"

// Parsers
// Vin
#import "MBVinParser.h"
#import "MBVinParserResult.h"

// TopUp
#import "MBTopUpParser.h"
#import "MBTopUpParserResult.h"

// Email
#import "MBEmailParser.h"
#import "MBEmailParserResult.h"

// License plates
#import "MBLicensePlatesParser.h"
#import "MBLicensePlatesParserResult.h"

// Amount
#import "MBAmountParser.h"
#import "MBAmountParserResult.h"

// IBAN
#import "MBIbanParser.h"
#import "MBIbanParserResult.h"

// Date
#import "MBDateParser.h"
#import "MBDateParserResult.h"

// VIN
#import "MBVinRecognizer.h"
#import "MBVinRecognizerResult.h"

// Raw
#import "MBRawParser.h"
#import "MBRawParserResult.h"

// Regex
#import "MBRegexParser.h"
#import "MBRegexParserResult.h"

// Dewarp policies
// Fixed policy
#import "MBFixedDewarpPolicy.h"

// DPI Based policy
#import "MBDPIBasedDewarpPolicy.h"

// No Up Scaling policy
#import "MBNoUpScalingDewarpPolicy.h"

// Engine options
#import "MBDeepOcrEngineOptions.h"
#import "MBOcrEngineOptions.h"

// Processor group
#import "MBProcessorGroup.h"

// Templating class
#import "MBTemplatingClass.h"

// Detector recognizer
#import "MBDetectorRecognizer.h"
#import "MBDetectorRecognizerResult.h"

// Processors
// Parser group
#import "MBParserGroupProcessor.h"
#import "MBParserGroupProcessorResult.h"

// Image return
#import "MBImageReturnProcessor.h"
#import "MBImageReturnProcessorResult.h"

// Native result
#import "MBNativeResult.h"
#import "MBDateResult.h"
