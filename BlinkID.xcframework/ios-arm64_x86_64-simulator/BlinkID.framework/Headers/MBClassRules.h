// Created by Toni Krešo on 26.06.2024.. 
// Copyright (c) 2024 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#ifndef MBClassRules_h
#define MBClassRules_h

#import "MBCustomClassRules.h"

@protocol MBClassRules

@required

@property (nonatomic, readonly) NSArray<MBCustomClassRules *> *recognizerCustomClassRules;
- (void)recognizerAddClassRulesToCustomClassRules:(MBCustomClassRules *)customClassRules NS_SWIFT_NAME(recognizerAddClassRulesToCustomClassRules(_:));
- (void)recognizerRemoveClassRulesFromCustomClassRules:(MBCustomClassRules *)customClassRules NS_SWIFT_NAME(recognizerRemoveClassRulesFromCustomClassRules(_:));
- (void)recognizerRemoveAllClassRulesFromCustomClassRules;

@end


#endif /* MBClassRules_h */
