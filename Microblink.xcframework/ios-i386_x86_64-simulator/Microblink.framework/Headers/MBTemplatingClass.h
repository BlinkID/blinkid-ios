//
//  MBTemplatingClass.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 21/03/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkInitialization.h"
#import "MBMicroblinkDefines.h"

@protocol MBTemplatingClassifier;

@class MBProcessorGroup;

NS_ASSUME_NONNULL_BEGIN

/**
 * Class that represents a specific class of documents when used within Templating API.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBTemplatingClass : NSObject

MB_INIT

/**
 * Sets processor groups that will be executed before classification
 * @param processorGroups processor groups that will be executed before classification
 */
- (void)setClassificationProcessorGroups:(nonnull NSArray<__kindof MBProcessorGroup *> *)processorGroups;

/**
 * Returns the currently set array of classification processor groups.
 * @return the currently set array of classification processor groups.
 */
- (nullable NSArray<__kindof MBProcessorGroup *> *)getClassificationProcessorGroups;

/**
 * Sets processor groups that will be executed if MBTemplatingClassifier's classify returns YES.
 * @param processorGroups processor groups that will be executed after classification, if classification is positive
 */
- (void)setNonClassificationProcessorGroups:(nonnull NSArray<__kindof MBProcessorGroup *> *)processorGroups;

/**
 * Returns the currently set array of non-classification processor groups.
 * @return the currently set array of non-classification processor groups.
 */
- (nullable NSArray<__kindof MBProcessorGroup *> *)getNonClassificationProcessorGroups;

/**
 * Sets the classifier which will tell whether currently processed document belongs to this class.
 * If set to nil, existing classifier (if exists) will be cleared and non-classification
 * processor groups will not be executed.
 * @param templatingClassifier Classifier which will tell whether currently processed document belongs to this class.
 */
- (void)setTemplatingClassifier:(nullable id<MBTemplatingClassifier>)templatingClassifier;

@end

@protocol MBTemplatingClassifier <NSObject>
@required

- (BOOL)classify;
@end

NS_ASSUME_NONNULL_END

