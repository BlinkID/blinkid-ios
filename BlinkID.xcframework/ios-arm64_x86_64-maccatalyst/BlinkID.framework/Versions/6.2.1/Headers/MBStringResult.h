//
//  MBStringResult.h
//  BlinkIDDev
//
// Copyright (c) 2022 Microblink Ltd. All rights reserved.
// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MBAlphabetType) {
    MBAlphabetTypeLatin,
    MBAlphabetTypeArabic,
    MBAlphabetTypeCyrillic
};

/**
 * Class for all obtaining original string per alphabet type
 */
MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBStringResult : NSObject

/**
 * @return the non-empty value, if such is present, with priority given to Latin alphabet.
 */
@property(nonatomic, readonly) NSString *value;

/**
 * @return value of the specified alphabet type.
 */
- (NSString *)valueForAlphabetType:(MBAlphabetType)alphabetType;

- (instancetype _Nonnull)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
