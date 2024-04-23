//
//  MBDocumentNumberAnonymizationSettings.h
//  BlinkID
//
//  Created by Tomislav Cvetkovic on 15.04.2024..
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBDocumentNumberAnonymizationSettings : NSObject

/** Defines how many digits at the beginning of the document number remain visible after anonymization. */
@property (nonatomic) NSInteger prefixDigitsVisible;

/** Defines how many digits at the end of the document number remain visible after anonymization. */
@property (nonatomic) NSInteger suffixDigitsVisible;

- (instancetype)initWithPrefixDigitsVisible:(NSInteger)prefixDigitsVisible suffixDigitsVisible:(NSInteger)suffixDigitsVisible;

@end

NS_ASSUME_NONNULL_END
