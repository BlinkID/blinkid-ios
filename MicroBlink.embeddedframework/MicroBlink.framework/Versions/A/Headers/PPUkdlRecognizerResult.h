//
//  PPUkdlRecognizerResult.h
//  BlinkIDFramework
//
//  Created by Jura on 13/04/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerResult.h"

/**
 * Class representing result of scanning of UK Driver's licenses
 */
@interface PPUkdlRecognizerResult : PPRecognizerResult

/**
 * First name of the owner of the DL card
 *
 *  @return owner first name
 */
- (NSString *)ownerFirstName;

/**
 * Last name of the owner of the DL card
 *
 *  @return owner last name
 */
- (NSString *)ownerLastName;

/**
 * Addres the owner of the DL card
 *
 *  @return address
 */
- (NSString *)ownerAdress;

/**
 * Birth data of the owner
 *
 *  @return Birth data
 */
- (NSString *)ownerBirthData;

/**
 * Issue date of the DL card
 *
 *  @return document issue date
 */
- (NSString *)documentIssueDate;

/**
 * Expiry date of the DL card
 *
 *  @return document exipri date
 */
- (NSString *)documentExpiryDate;

/**
 * Driver number
 *
 *  @return driver number
 */
- (NSString *)driverNumber;

@end
