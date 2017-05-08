//
//  PPAusIDBackRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Dino on 30/06/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPMrtdRecognizerResult.h"

/**
 * Class representing values obtained when scanning back side of Austrian ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPAusIDBackRecognizerResult : PPMrtdRecognizerResult

/**
 * The issuing authority of the Austrian ID.
 */
@property (nonatomic, readonly, nullable) NSString *issuingAuthority;

/**
 * The place of birth of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *placeOfBirth;

/**
 * The principal residence of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *principalResidence;

/**
 * The height of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *height;

/**
 * The date of issue of the Austrian ID in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfIssue;

/**
 * The date of issue of the Austrian ID.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfIssue;

/**
 * The eye color of the Austrian ID owner.
 */
@property (nonatomic, readonly, nullable) NSString *eyeColor;

/**
 * The document number of the Austrian ID.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

@end
