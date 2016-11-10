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
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPEudlRecognizerResult : PPRecognizerResult

/**
 * First name of the owner of the DL card
 *
 *  @return owner first name
 */
- (NSString * _Nullable)ownerFirstName;

/**
 * Last name of the owner of the DL card
 *
 *  @return owner last name
 */
- (NSString * _Nullable)ownerLastName;

/**
 * Birth data of the owner
 *
 *  @return Birth data
 */
- (NSString * _Nullable)ownerBirthData;

/**
 * Issue date of the DL card
 *
 *  @return document issue date
 */
- (NSString * _Nullable)documentIssueDate;

/**
 * Expiry date of the DL card
 *
 *  @return document exipri date
 */
- (NSString * _Nullable)documentExpiryDate;

/**
 * Issuing authority of the document
 *
 *  @return issuing authority
 */
- (NSString * _Nullable)documentIssuingAuthority;

/**
 * Personal number
 *
 *  @return personal number
 */
- (NSString * _Nullable)personalNumber;

/**
 * Driver number
 *
 *  @return driver number
 */
- (NSString * _Nullable)driverNumber;

/**
 * Addres the owner of the DL card
 *
 *  @return address
 */
- (NSString * _Nullable)ownerAddress;

/**
 * Country of detected DL card
 *
 *  @return country
 */
- (PPEudlCountry)country;

@end
