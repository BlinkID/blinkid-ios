//
//  PPAustraliaDLBackRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 30/11/2017.
//

#import "PPDetectorRecognizerResult.h"

/**
 * Class representing values obtained when scanning back side of Australian DL
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPAustraliaDLBackRecognizerResult : PPDetectorRecognizerResult

/**
 * The last name of the Australian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *lastName;

/**
 * The licence number of the Australian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *licenceNumber;

/**
 * The address of the Australian DL owner.
 */
@property (nonatomic, readonly, nullable) NSString *address;

/**
 * The document date of expiry of the Australian DL in DD.MM.yyyy format.
 */
@property (nonatomic, readonly, nullable) NSString *rawDocumentDateOfExpiry;

/**
 * The document date of expiry of the Australian DL
 */
@property (nonatomic, readonly, nullable) NSDate *documentDateOfExpiry;

@end
