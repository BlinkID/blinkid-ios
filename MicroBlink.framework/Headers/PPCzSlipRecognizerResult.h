//
//  PPCzSlipRecognizerResult.h
//  PhotoPayFramework
//
//  Created by Dino on 21/07/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPPhotoPayRecognizerResult.h"

/**
 * Result of scanning of Czech payment slips
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPCzSlipRecognizerResult : PPPhotoPayRecognizerResult

/**
 * String representing account number
 */
@property (nonatomic, readonly, nonnull) NSString *accountNumber;

/**
 * String representing account prefix. Account prefix is not mandatory on payslips.
 */
@property (nonatomic, readonly, nonnull) NSString *accountPrefix;

/**
 * Bank code
 */
@property (nonatomic, readonly, nonnull) NSString *bankCode;

/**
 * Variable code of payment order
 */
@property (nonatomic, readonly, nonnull) NSString *variableSymbol;

/**
 * Specific code of payment order
 */
@property (nonatomic, readonly, nonnull) NSString *specificSymbol;

/**
 * Constant code of payment order
 */
@property (nonatomic, readonly, nonnull) NSString *constantSymbol;

@end
