//
//  PPGermanIDFrontRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 22/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of German ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPGermanPassportRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * The surname of the German Passport owner.
 */
@property (nonatomic, readonly, nullable) NSString *surname;

/**
 * The name of the German Passport owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The nationality of the German Passport owner.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * The place of birth of the German Passport owner
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * Raw date of issue, as written on the passport
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfIssue;

/**
 * Date of issue in NSDate object
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * Issuing authority of the Passport
 */
@property (nonatomic, readonly, nullable) NSString *authority;

@end
