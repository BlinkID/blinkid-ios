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
 * Returns the name of the iKad owner.
 * @return the name of the iKad owner.
 */
- (NSString * _Nullable)name;

/**
 * Returns the passport number of the iKad owner.
 * @return the passport number of the iKad owner.
 */
- (NSString * _Nullable)passportNumber;

/**
 * Returns nationality of the iKad owner.
 * @return nationality of the iKad owner
 */
- (NSString * _Nullable)nationality;

/**
 * Returns the date of birth of iKad owner
 * @return the date of birth of iKad owner
 */
- (NSString * _Nullable)dateOfBirth;

/**
 * Returns the sex of the iKad owner
 * @return the sex of the iKad owner
 */
- (NSString * _Nullable)sex;

/**
 * Returns the sector of the iKad owner
 * @return the sector of the iKad owner
 */
- (NSString * _Nullable)sector;

/**
 * Returns the employer of the iKad owner
 * @return the employer of the iKad owner
 */
- (NSString * _Nullable)employer;

/**
 * Returns the address of the iKad owner
 * @return the address of the iKad owner
 */
- (NSString * _Nullable)address;

/**
 * Returns the expiry date of the iKad
 * @return the expiry date of the iKad
 */
- (NSString * _Nullable)expiryDate;

@end
