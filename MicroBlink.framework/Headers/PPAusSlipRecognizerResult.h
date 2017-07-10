//
//  PPAusSlipResult.h
//  PhotoPayFramework
//
//  Created by Jura on 08/03/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPAusRecognizerResult.h"

/**
 * Class result of scanning Austrian payment slips
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPAusSlipRecognizerResult : PPAusRecognizerResult

/**
 * String representing special customer data (Kundendaten) on some slips. Used only on non-Sepa slips (other than 30 and 32 types)
 */
@property (nonatomic, readonly, nullable) NSString *customerData;

/**
 * String representing special contract account (Vertragskonto) on some slips. Used only on non-Sepa slips (other than 30 and 32 types)
 */
@property (nonatomic, readonly, nullable) NSString *contractAccount;

/**
 * String represengint special tax number (Steuernummer) - used in payslip type 10
 */
@property (nonatomic, readonly, nullable) NSString *taxNumber;

/**
 * DocumentType - type of the payslip (30, 32 for SEPA, 40, 42, 10 for non SEPA)
 *
 * 0 if doesn't exist
 */
@property (nonatomic, readonly) NSInteger documentType;

/**
 * Belegnummer - used to identify slip type
 */
@property (nonatomic, readonly, nullable) NSString *belegNummer;

/**
 * Prufziffer - for controlling reference number and amount on SEPA slips
 */
@property (nonatomic, readonly, nullable) NSString *prufziffer;

@end
