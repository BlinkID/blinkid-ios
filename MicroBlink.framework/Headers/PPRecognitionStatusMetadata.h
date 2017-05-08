//
//  PPRecognitionStatusMetadata.h
//  PhotoPayDev
//
//  Created by Jura on 19/04/2017.
//
//

#import "PPMetadata.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, PPRecognitionStatus) {
    PPRecognitionStatusSuccess = 0,
    PPRecognitionStatusGlare,
};

PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPRecognitionStatusMetadata : PPMetadata

@property (nonatomic, assign) PPRecognitionStatus status;

- (instancetype)initWithName:(NSString *)name NS_UNAVAILABLE;

- (instancetype)initWithStatus:(PPRecognitionStatus)status NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
