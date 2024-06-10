// Created by Toni Krešo on 23.05.2024.
// Copyright (c) 2024 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#ifndef MBStrictnessLevel_h
#define MBStrictnessLevel_h

/**
 * MBStrictnessLevel is used to strictness level of filtering performed on images.
 */
typedef NS_ENUM(NSInteger, MBStrictnessLevel) {
    
    MBStrictnessLevelStrict = 0,
    MBStrictnessLevelNormal,
    MBStrictnessLevelRelaxed
    
};


#endif /* MBStrictnessLevel_h */
