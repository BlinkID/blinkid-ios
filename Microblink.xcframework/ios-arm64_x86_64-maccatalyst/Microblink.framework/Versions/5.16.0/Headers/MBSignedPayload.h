//
//  SignedPayload.h
//  BlinkShowcaseDev
//
//  Created by Mijo Gracanin on 24.01.2022..
//

#ifndef SignedPayload_h
#define SignedPayload_h

#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(11.0) MB_FINAL
@interface MBSignedPayload : NSObject

/**
 * Payload that will be signed.
 */
@property (nonatomic, readonly, nullable) NSString *payload;

/**
 * Digital signature of the payload.
 */
@property (nonatomic, readonly, nullable) NSString *signature;

/**
 * Version of the digital signature.
 */
@property (nonatomic, readonly, nullable) NSString *signatureVersion;

- (instancetype) initWithPayload:(NSString *)payload signature:(NSString *)signature signatureVersion:(NSString *)signatureVersion NS_DESIGNATED_INITIALIZER;

/**
 * Please use designated initializer.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* SignedPayload_h */
