//
//  PPLivenessRecognizerSettings.h
//  BlinkIdFramework
//
//  Created by Jura on 30/08/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#import "PPRecognizerSettings.h"

/**
 * Settings class for configuring Austrian Back ID Recognizer
 *
 * Austrian Back ID recognizer is used for scanning back side of Austrian ID.
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPLivenessRecognizerSettings : PPRecognizerSettings

/**
 * Name of the image sent to didOutputMetadata method of scanDelegate object that contains face.
 * This image will be sent to scan delegate during recognition process if receiving of dewarpedImage
 * in MetadataSettings is enabled.
 */
+ (NSString *)ID_FACE;

/**
 * Sets whether face image from ID card should be sent to didOutputMetadata method of scanDelegate object.
 * If you want to recieve this image, be sure to enable dewarpedImage in MetadataSettings.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL returnFacePhoto;

/**
 * Sets whether face photo should be encoded in the results.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL encodeFacePhoto;

/**
 * Defines action timeout. Timeout is defined as time interval (in milliseconds) in which each face action has to be finished.
 *
 * Default: 30000
 */
@property (nonatomic, assign) int numMsBeforeTimeout;


// init is unavailable
- (instancetype)init NS_UNAVAILABLE;

/**
 * Initializes liveness recognizer settings with a given license key file
 *
 * @param filename name of the license file
 * @return initialized instance
 */
- (instancetype)initWithLicenseKeyFile:(NSString *)filename NS_DESIGNATED_INITIALIZER;

/**
 * Initializes liveness recognizer settings with a given license key
 *
 * @param licenseKey key
 * @return initialized instance
 */
- (instancetype)initWithLicenseKey:(NSString *)licenseKey NS_DESIGNATED_INITIALIZER;

/**
 * Method sets the path for resources required for liveness recognition
 *
 * @param path path for the resources (for example, "Facial Features Tracker - High.cfg"
 */
- (void)setResourcePath:(NSString *)path;

@end
