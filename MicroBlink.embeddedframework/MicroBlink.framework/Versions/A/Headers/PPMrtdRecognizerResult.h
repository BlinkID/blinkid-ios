//
//  PPMrtdRecognizerResult.h
//  MicroBlinkFramework
//
//  Created by Jura on 28/09/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerResult.h"

/**
 * Class representing common values obtained when scanning machine readable travel documents (MRTDs)
 */
@interface PPMrtdRecognizerResult : PPRecognizerResult

/**
 * Returns three-letter code which indicate the issuing State.
 * Three-letter codes are based on Alpha-3 codes for entities specified in 
 * ISO 3166-1, with extensions for certain States.
 *
 *  @return issuer code
 */
- (NSString *)issuer;

/**
 * Unique number of the document. Document number contains up to 9 characters.
 *
 *  @return documentNumber
 */
- (NSString *)documentNumber;

/**
 * Returns document code. Document code contains two characters. For MRTD the first character 
 * shall be A, C or I. The second character shall be discretion of the issuing State or organization
 * except that V shall not be used, and C shall not be used after A except in the crew member
 * certificate. On machine-readable passports (MRP) first character shall be P to designate an MRP.
 * One additional letter may be used, at the discretion of the issuing State or organization,
 * to designate a particular MRP. If the second character position is not used for this purpose, it
 * shall be filled by the filter character <.
 *
 *  @return documentCode
 */
- (NSString *)documentCode;

/**
 * Returns date of expiry of the document in format YYMMDD.
 *
 *  @return date of expiry
 */
- (NSString *)dateOfExpiry;

/**
 * Returns the primary indentifier. If there is more than one component, they are separated with space.
 *
 *  @return primary id of a card holder.
 */
- (NSString *)primaryId;

/**
 * Returns the secondary identifier. If there is more than one component, they are separated with space.
 *
 *  @return secondary id of a card holder
 */
- (NSString *)secondaryId;

/**
 * Returns holder's date of birth in format YYMMDD.
 *
 *  @return date of birth
 */
- (NSString *)dateOfBirth;

/**
 * Returns nationality of the holder represented by a three-letter code. Three-letter codes are based 
 * on Alpha-3 codes for entities specified in ISO 3166-1, with extensions for certain States.
 *
 *  @return nationality
 */
- (NSString *)nationality;

/**
 * Returns sex of the card holder. Sex is specified by use of the single initial, capital 
 * letter F for female, M for male or < for unspecified.
 *
 *  @return sex of the card holder
 */
- (NSString *)sex;

/**
 * Returns first optional data. 
 * Returns nil or empty string if not available.
 *
 *  @return optional data 1
 */
- (NSString *)opt1;

/**
 * Returns first optional data.
 * Returns nil or empty string if not available.
 *
 *  @return optional data 2
 */
- (NSString *)opt2;

@end
