//
//  PPColombiaIDFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Dino Gustin on 30/01/2018.
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Colombian ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPColombiaIDFrontRecognizerResult : PPDetectorRecognizerResult

/**
 * The first name of the Colombian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *firstName;

/**
 * The last name of the Colombian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The document number of the Colombian ID card.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

@end
