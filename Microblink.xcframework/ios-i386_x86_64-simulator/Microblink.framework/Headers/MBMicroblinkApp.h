//
//  App.h
//  iphone-photopay
//
//  Created by Ja on 11/2/11.
//  Copyright (c) 2011 jcerovec@gmail.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

#ifdef __OBJC__
#import <UIKit/UIKit.h>
#endif

#define PP_IS_IPAD (([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPad))

/*
 *  System Versioning Preprocessor Macros
 */

#define SYSTEM_VERSION_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v) \
    ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v) \
    ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#define PP_NOTIFY(notificationKey, valueKey)                                                                  \
    {                                                                                                         \
        NSDictionary *dict = [NSDictionary dictionaryWithObject:@(YES) forKey:valueKey];                      \
        [[NSNotificationCenter defaultCenter] postNotificationName:notificationKey object:nil userInfo:dict]; \
    }

MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMicroblinkApp : NSObject

@property (nonatomic) NSString *language;

/** Bundle with resources used in framework */
@property (nonatomic) NSBundle *resourcesBundle;

/** Custom bundle for overriding resourcesBundle */
@property (nonatomic) NSBundle *customResourcesBundle;

/** Localization file in main bundle used for overrideing framework's localizations */
@property (nonatomic) NSString *customLocalizationFileName;

/** Obtain the shared instance */
@property (class, readonly) MBMicroblinkApp *instance;

/** Designated initializer */
- (id)init;

/** Sets the language used in PhotoPaySDK */
- (void)setLanguage:(NSString *)language;

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

/** Sets the key that the help was shown to true */
- (void)setHelpShown:(BOOL)value;

/** Returns true if the help was already shown */
- (BOOL)isHelpShown;

/**
 * Returns the default resources bundle. If it doesn't exist, it will be nil.
 */
+ (NSBundle *)getDefaultResourcesBundle;

@end


// MARK: - Localization

static inline NSString * MB_LOCALIZED_DEFAULT_STRING(NSString *key) {
    return ([NSString stringWithFormat:@"[[%@]]", key]);
}

static inline NSString * MB_LOCALIZED(NSString *key) {
    NSString *localizationFileName = MBMicroblinkApp.instance.customLocalizationFileName;
    if (localizationFileName) {
        NSString *overridenStringFromCustomLocalizationFile = NSLocalizedStringWithDefaultValue(key, localizationFileName, [NSBundle mainBundle], @"", @"");

        if (![overridenStringFromCustomLocalizationFile isEqualToString:key]) {
            return overridenStringFromCustomLocalizationFile;
        }
    }

    NSString *overridenStringFromCustomBundle = NSLocalizedStringWithDefaultValue(key,
                                                                                  MBMicroblinkApp.instance.language,
                                                                                  MBMicroblinkApp.instance.customResourcesBundle,
                                                                                  @"",
                                                                                  @"");
    if ( overridenStringFromCustomBundle != nil && ![overridenStringFromCustomBundle isEqualToString:key]) {
        return overridenStringFromCustomBundle;
    }

    return NSLocalizedStringWithDefaultValue(key,
                                             MBMicroblinkApp.instance.language,
                                             [[MBMicroblinkApp instance] resourcesBundle],
                                             MB_LOCALIZED_DEFAULT_STRING(key), nil);
}
