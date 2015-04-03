//
//  App.h
//  iphone-photopay
//
//  Created by Ja on 11/2/11.
//  Copyright (c) 2011 jcerovec@gmail.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef __OBJC__
#import <UIKit/UIKit.h>
#endif

/**
 * Define your macros for accessing localization tables.
 * If you don't have your definitions, our tables will be used 
 * based on [[PPApp instance] language] property
 */

#ifndef _
    #define _(s) NSLocalizedStringFromTable(s,[PPApp instance].language,s)
#endif

#ifndef __
    #define __(s,...) [NSString stringWithFormat:NSLocalizedStringFromTable(s,[PPApp instance].language,s),##__VA_ARGS__]
#endif

#define PP_IS_IPAD (([UIDevice currentDevice].userInterfaceIdiom==UIUserInterfaceIdiomPad))

/*
 *  System Versioning Preprocessor Macros
 */

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#define PP_NOTIFY(notificationKey, valueKey) \
    {   \
        NSDictionary* dict = [NSDictionary dictionaryWithObject:@(YES) forKey:valueKey]; \
        [[NSNotificationCenter defaultCenter] postNotificationName:notificationKey object:nil userInfo:dict]; \
    }

@interface PPApp : NSObject

@property (nonatomic, copy, setter=setLanguage:) NSString* language;
@property (nonatomic, assign) double animationDuration;
@property (nonatomic, assign) NSTimeInterval lastScanDuration;

/** Obtain the shared instance */
+ (PPApp *)instance;

- (NSBundle*)frameworkBundle;

/** Designated initializer */
- (id)init;

/** Sets the language used in PhotoPaySDK */
- (void)setLanguage:(NSString *)inLanguage;

/** Sets the language to default (i.e. language specified in the user's device settings */
- (void)setDefaultLanguage;

/** Pushes the UIApplication status bar style to a internally handled stack */
- (void)pushStatusBarStyle:(UIStatusBarStyle)statusBarStyle;

/** Returns the status bar style to the last saved value */
- (void)popStatusBarStyle;

/** Push the status bar hidden value */
- (void)pushStatusBarHidden:(BOOL)hidden;

/** pops the status bar hidden value */
- (void)popStatusBarHidden;

@end
