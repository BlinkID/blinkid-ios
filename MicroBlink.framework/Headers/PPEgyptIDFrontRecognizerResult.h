//
//  PPEgyptIDFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 27/03/2018.
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Egypt ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPEgyptIDFrontRecognizerResult : PPDetectorRecognizerResult

/**
 * The National Number of the Egypt ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationalNumber;

/**
 * The document number of the Egypt ID.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

@end
