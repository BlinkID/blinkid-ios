//
//  PPiKadRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Dino on 28/09/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPBlinkOcrRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of iKad
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPiKadRecognizerResult : PPBlinkOcrRecognizerResult

/**
 * The name of the iKad owner.
 */
@property (nonatomic, readonly, nullable) NSString* name;

/**
 * The passport number of the iKad owner.
 */
@property (nonatomic, readonly, nullable) NSString* passportNumber;

/**
 * The nationality of the iKad owner.
 */
@property (nonatomic, readonly, nullable) NSString* nationality;

/**
 * The date of birth of iKad owner
 */
@property (nonatomic, readonly, nullable) NSString* dateOfBirth;

/**
 * The sex of the iKad owner
 */
@property (nonatomic, readonly, nullable) NSString* sex;

/**
 * The sector of the iKad owner
 */
@property (nonatomic, readonly, nullable) NSString* sector;

/**
 * The employer of the iKad owner
 */
@property (nonatomic, readonly, nullable) NSString* employer;

/**
 * The address of the iKad owner
 */
@property (nonatomic, readonly, nullable) NSString* address;

/**
 * The expiry date of the iKad
 */
@property (nonatomic, readonly, nullable) NSString* expiryDate;

@end
