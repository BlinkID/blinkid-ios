//
//  MBCryptoUploader.h
//  BlinkID-app
//
//  Created by Luka Zuanovic MB on 28/03/2017.
//  Copyright © 2017 Microblink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MBCryptoUploader : NSObject

/**
 Sets name of all encrypted data that will be uploaded henceforth.
 @warning This method must be invoked at least once or no data will ever be uploaded.

 @param dataName Name of the uploaded data. Cannot be nil nor empty.
 */
- (void)setDataNameForFutureUploads:(nonnull NSString *)dataName;

/**
 Method used to upload an encrypted image.
 This method will do nothing and return 0 should there be any exception while encrypting or uploading the data.

 @param image Image to encrytpt and upload.
 @param url where the image is uploaded
 @return Total size (approximate) of the uploaded data.
 */
- (NSUInteger)uploadImage:(nonnull UIImage *)image url:(nonnull NSString *)url;

/**
 Method used to upload an encrypted image, metadata and encrypted secret metadata.
 This method will do nothing and return 0 should there be any exception while encrypting or uploading the data.
 
 @param image Image to encrypt and upload.
 @param metadata Metadata to upload.
 @param secretMetadata Metadata to encrypt and upload.
 @param url where the image is uploaded
 @return Total size (approximate) of the uploaded data.
 */
- (NSUInteger)uploadImage:(nonnull UIImage *)image metadata:(nullable NSString *)metadata secretMetadata:(nullable NSString *)secretMetadata url:(nonnull NSString *)url;

/**
 Method used to upload an encrypted image, metadata, encrypted secret metadata and other data.
 This method will do nothing and return 0 should there be any exception while encrypting or uploading the data.

 @param image Image to encrypt and upload.
 @param metadata Metadata to upload.
 @param secretMetadata Metadata to encrypt and upload.
 @param data Data, in key value pairs, to upload.
 @param url where the image is uploaded
 @return Total size (approximate) of the uploaded data.
 */
- (NSUInteger)uploadImage:(nonnull UIImage *)image metadata:(nullable NSString *)metadata secretMetadata:(nullable NSString *)secretMetadata otherData:(nullable NSDictionary<NSString *, NSString *> *)data url:(nonnull NSString *)url;

- (NSUInteger)uploadData:(NSData *)data metadata:(NSString *)metadata secretMetadata:(NSString *)secretMetadata otherData:(NSDictionary<NSString *, NSString *> *)otherData fileType:(NSString *)fileType url:(nonnull NSString *)url;

NS_ASSUME_NONNULL_END

@end
