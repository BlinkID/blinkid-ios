//
//  PPEudlRecognizerResult.h
//  BlinkIDFramework
//
//  Created by Jura on 13/04/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerResult.h"
#import "PPEudlCountry.h"

/**
 * Class representing result of scanning of UK Driver's licenses
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPEudlRecognizerResult : PPRecognizerResult

/**
 * First name of the owner of the DL card
 */
@property (nonatomic, readonly, nullable) NSString *ownerFirstName;

/**
 * Last name of the owner of the DL card
 */
@property (nonatomic, readonly, nullable) NSString *ownerLastName;

/**
 * Birth data of the owner
 */
@property (nonatomic, readonly, nullable) NSString *ownerBirthData;

/**
 * Issue date of the DL card
 */
@property (nonatomic, readonly, nullable) NSString *documentIssueDate;

/**
 * Expiry date of the DL card
 */
@property (nonatomic, readonly, nullable) NSString *documentExpiryDate;

/**
 * Issuing authority of the document
 */
@property (nonatomic, readonly, nullable) NSString *documentIssuingAuthority;

/**
 * Personal number
 */
@property (nonatomic, readonly, nullable) NSString *personalNumber;

/**
 * Driver number
 */
@property (nonatomic, readonly, nullable) NSString *driverNumber;

/**
 * Addres the owner of the DL card
 */
@property (nonatomic, readonly, nullable) NSString *ownerAddress;

/**
 * Country of detected DL card
 */
@property (nonatomic, readonly) PPEudlCountry country;

@end
