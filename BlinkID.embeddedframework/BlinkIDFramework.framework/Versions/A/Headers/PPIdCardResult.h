//
//  PPIdCardResult.h
//  PhotoPayFramework
//
//  Created by Jura on 28/09/14.
//  Copyright (c) 2014 MicroBlink Ltd. All rights reserved.
//

#import "PPBaseResult.h"

@interface PPIdCardResult : PPBaseResult

@property (nonatomic, strong) NSString* issuer;

@property (nonatomic, strong) NSString* documentNumber;

@property (nonatomic, strong) NSString* documentCode;

@property (nonatomic, strong) NSString* dateOfExpiry;

@property (nonatomic, strong) NSString* primaryId;

@property (nonatomic, strong) NSString* secondaryId;

@property (nonatomic, strong) NSString* dateOfBirth;

@property (nonatomic, strong) NSString* nationality;

@property (nonatomic, strong) NSString* sex;

@property (nonatomic, strong) NSString* opt1;

@property (nonatomic, strong) NSString* opt2;

@end
