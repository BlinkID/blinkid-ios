//
//  PPAusQrResult.h
//  PhotoPayFramework
//
//  Created by Jura on 08/03/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPAusRecognizerResult.h"

/**
 * Class representing common result of scanning Austrian payment QR codes, such as Stuzza codes.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPAusQrRecognizerResult : PPAusRecognizerResult

/**
 * Display data for payment description - usually found only on QR codes
 */
@property (nonatomic, readonly, nullable) NSString *displayData;

/**
 * Purpose code (Geschäftscode) - string that represents the purpose code read from QR code, if available
 */
@property (nonatomic, readonly, nullable) NSString *purposeCode;

@end
