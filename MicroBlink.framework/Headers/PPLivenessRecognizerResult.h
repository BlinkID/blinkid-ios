//
//  PPLivenessRecognizerResult.h
//  BlinkIdFramework
//
//  Created by Jura on 30/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerResult.h"

/**
 * Class representing values obtained when scanning back side of Austrian ID
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPLivenessRecognizerResult : PPRecognizerResult

/**
 * Boolean value which denotes Liveness recognizer determined that the person in front of the camera is alive.
 *
 * @return YES if Liveness Recognizer result determined that the person in front of the camera is alive. NO otherwise.
 */
@property (nonatomic, readonly) BOOL alive;

/**
 * Contains signature which confirms that this data originates from the SDK
 */
@property (nonatomic, readonly, nullable) NSData *signature;

/**
 * Contains the version of the signature
 */
@property (nonatomic, readonly, nullable) NSString *signatureVersion;

/**
 * Byte buffer with face image
 */
@property (nonatomic, readonly, nullable) NSData *faceImage;

@end
