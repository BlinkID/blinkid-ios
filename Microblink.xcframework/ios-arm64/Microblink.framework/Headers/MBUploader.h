
//
//  MBImageUploader.h
//  BlinkID-app
//
//  Created by Luka Zuanovic MB on 08/05/2017.
//  Copyright © 2017 Microblink. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"


typedef NS_ENUM(NSUInteger, MBUploadStatus) {
    MBUploadStatusSuccess,
    MBUploadStatusDisabled,
    MBUploadStatusFailLimitMobileData,
    MBUploadStatusFailLimitWifiData,
    MBUploadStatusFailNoInternet,
    MBUploadStatusFailNoData
};

MB_CLASS_AVAILABLE_IOS(11.0) MB_FINAL
@interface MBUploader : NSObject


/**
 Enables upload of data over wifi connection.

 Default: YES
 */
@property (nonatomic, getter=shouldUseWifiData) BOOL useWifiData;

/**
 Enables upload of data over mobile connection.

 Default: YES
 */
@property (nonatomic, getter=shouldUseMobileData) BOOL useMobileData;

/**
 Enables upload of images.

 Default: NO
 */
@property (nonatomic, getter=shouldUploadData) BOOL uploadData;

/**
 Adds parameter environment=dev to the request.

 Default: NO
 */
@property (nonatomic, getter=isDevEnvironment) BOOL devEnvironment;

/**
 Daily data upload limit using wifi, in bytes.

 Default: 50 << 20
 */
@property (nonatomic, readonly) NSUInteger dailyWifiDataLimit;

/**
 Daily data upload limit using mobile network, in bytes.

 Default: 10 << 20
 */
@property (nonatomic, readonly) NSUInteger dailyMobileDataLimit;

/**
 Singleton instance of MBImageUploader.

 @return instance of MBImageUploader.
 */
+ (nonnull instancetype)sharedInstance;

/**
 Method sets daily data limit for wifi and mobile data.

 Default: wifi = 50 << 20, mobile = 10 << 20.
 @param wifiLimit daily wifi data limit in bytes.
 @param mobileLimit daily mobile data limit in bytes.
 */
- (void)setDailyWifiDataLimit:(NSUInteger)wifiLimit dailyMobileDataLimit:(NSUInteger)mobileLimit;

/**
 Use this method to upload an image. Additional info, such as
 app version, app name, os version and such will be added internally.

 @param image that will be encrypted and uploaded.
 @param metadata that will be uploaded alongside image.
 @param secretMetadata that will be encrypted and uploaded alongside image.
 @param imageName name that will be used to save image on server.
 @param wifiLimitCallback callback method that will be invoked if wifi data transfer limit is reached.
 @param mobileDataLimitCallback callback method that will be invoked if mobile data transfer limit is reached.
 @param resultType type of image scanned
 @param url where the image is uploaded
 @return YES if upload was successful, otherwise NO
 */
- (MBUploadStatus)uploadImage:(nonnull UIImage *)image
metadata:(nullable NSString *)metadata
secretMetadata:(nullable NSString *)secretMetadata
imageName:(nonnull NSString *)imageName
wifiLimitReachedCallback:(nullable void (^)(void))wifiLimitCallback
mobileDataLimitReachedCallback:(nullable void (^)(void))mobileDataLimitCallback
resultType:(nonnull NSString *)resultType
url:(nonnull NSString *)url;

/**
 Use this method to upload data. Additional info, such as
 app version, app name, os version, userId and such will be added internally.

 @param data that will be encrypted and uploaded.
 @param metadata that will be uploaded alongside data.
 @param secretMetadata that will be encrypted and uploaded alongside data.
 @param dataName name that will be used to save data on server.
 @param wifiLimitCallback callback method that will be invoked if wifi data transfer limit is reached.
 @param mobileDataLimitCallback callback method that will be invoked if mobile data transfer limit is reached.
 @param fileType type of file that is uploaded
 @param url where the image is uploaded
 @return YES if upload was successful, otherwise NO
 */
- (MBUploadStatus)uploadData:(nonnull NSData *)data
metadata:(nullable NSString *)metadata
secretMetadata:(nullable NSString *)secretMetadata
wifiLimitReachedCallback:(nullable void (^)(void))wifiLimitCallback
mobileDataLimitReachedCallback:(nullable void (^)(void))mobileDataLimitCallback
dataName:(nonnull NSString *)dataName
fileType:(nonnull NSString *)fileType
url:(nonnull NSString *)url;
@end
