// Created by Toni Krešo on 10.05.2023.. 
// Copyright (c) 2023 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#ifndef ClassAnonymization_h
#define ClassAnonymization_h

#import "MBClassAnonymizationSettings.h"

@protocol MBClassAnonymization

@required

@property (nonatomic, readonly) NSArray<MBClassAnonymizationSettings *> *recognizerAdditionalAnonymizationSettings;

- (NSArray<MBClassAnonymizationSettings *> *)recognizerAdditionalAnonymizationSettings;
- (void)recognizerAddClassToAdditionalAnonymization:(MBClassAnonymizationSettings *)additionalAnonymizationClass NS_SWIFT_NAME(recognizerAddClassToAdditionalAnonymization(_:));
- (void)recognizerRemoveClassFromAdditionalAnonymization:(MBClassAnonymizationSettings *)additionalAnonymizationClass NS_SWIFT_NAME(recognizerRemoveClassFromAdditionalAnonymization(_:));
- (void)recognizerRemoveAllClassesFromAdditionalAnonymization;

@end


#endif /* ClassAnonymization_h */
