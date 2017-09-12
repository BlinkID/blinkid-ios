//
//  PPAustraliaDLFrontRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 06/09/2017.
//
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning front side of Australian DL
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPAustraliaDLFrontRecognizerResult : PPDetectorRecognizerResult

/**
 * The first name of the Australian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * The licence type of Australian DL.
 */
@property (nonatomic, readonly, nullable) NSString *licenceType;

/**
 * The licence number of the Australian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *licenceNumber;

/**
 * The address of the Australian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The date of birth of Australian DL owner in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * The date of birth of Australian DL owner
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * The document date of expiry of the Australian DL in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDocumentDateOfExpiry;

/**
 * The document date of expiry of the Australian DL
 */
@property (nonatomic, readonly, nullable) NSDate *documentDateOfExpiry;

@end
