//
//  PPUnitedArabEmiratesIDFrontRecognizerResult.h
//  MicroBlink
//
//  Created by Dino Gustin on 05/02/2018.
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of UAE ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPUnitedArabEmiratesIDFrontRecognizerResult : PPDetectorRecognizerResult

/**
 * The first name of the Colombian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The last name of the Colombian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The document number of the Colombian ID card.
 */
@property (nonatomic, readonly, nullable) NSString *idNumber;

@end
