//
//  MBMicroblinkSDK.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 14/11/2017.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBCameraSettings.h"

NS_ASSUME_NONNULL_BEGIN
/**
 * Entry class for all Microblink SDKs - used for setting up license key and to add support for
 * optimisation of passing data.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBMicroblinkSDK : NSObject

+ (instancetype)sharedInstance;

/**
 * If YES, tooltip limited license key warning messages will appear on screen
 *
 * Default: YES.
 */
@property (nonatomic, assign) BOOL showLicenseKeyTimeLimitedWarning;

/**
 * Bundle in which the resources for the scanning process should be found. Usually, by default, this
 * is equal to Microblink.bundle located in Main app bundle.
 *
 * i.e, this is by default initialized to:
 *   [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"Microblink" ofType:@"bundle"];
 *
 */
@property (nonatomic, strong) NSBundle *resourcesBundle;

/**
 * Set license buffer and unlock the SDK. Application package will be used to validate the license.
 * @param licenseBuffer Byte array containing the license.
 */
- (void)setLicenseBuffer:(NSData * _Nonnull)licenseBuffer;

/**
 * Set license buffer and unlock the SDK. Also define licensee that will be used to validate the license.
 * This method can be used to unlock the SDK in library mode, i.e. when Microblink SDK is being
 * packaged inside 3rd party SDK. Unlocking Microblink SDK in library mode allows usage of
 * single license within multiple application packages.
 * @param licenseBuffer Byte array containing the license.
 * @param licensee Licensee to which license is given to.
 */
- (void)setLicenseBuffer:(NSData * _Nonnull)licenseBuffer andLicensee:(NSString * _Nonnull)licensee;

/**
 * Set license key and unlock the SDK. Application package will be used to validate the license.
 * @param base64LicenseKey License file encoded as base64 string.
 */
- (void)setLicenseKey:(NSString * _Nonnull)base64LicenseKey;

/**
 * Set license key and unlock the SDK. Also define licensee that will be used to validate the license.
 * This method can be used to unlock the SDK in library mode, i.e. when Microblink SDK is being
 * packaged inside 3rd party SDK. Unlocking Microblink SDK in library mode allows usage of
 * single license within multiple application packages.
 * @param base64LicenseKey Byte array containing the license.
 * @param licensee Licensee to which license is given to.
 */
- (void)setLicenseKey:(NSString * _Nonnull)base64LicenseKey andLicensee:(NSString * _Nonnull)licensee;

/**
 * Set the license file and unlock the SDK. Application package will be used to validate the license.
 * @param fileName The name of resource file contained in the directory specified by subdirectory. If you specify nil, the method returns the first resource file it finds with the specified extension in that directory.
 * @param extension The filename extension of the file (etc. txt). If you specify an empty string or nil, the extension is assumed not to exist and the file URL is the first file encountered that exactly matches name.
 * @param subdirectory The valid path of top-level directory in which file is located inside bundle (etc. licenseFiles/). If you specify an empty string or nil, root direcotry of bundle will be searched.
 * @param bundle NSBundle bundle required to access file.
 */
- (void)setLicenseResource:(NSString * _Nonnull)fileName withExtension:(NSString * _Nullable)extension inSubdirectory:(NSString * _Nullable)subdirectory forBundle:(NSBundle * _Nonnull)bundle;

/**
 * Set the license file and unlock the SDK. Also define licensee that will be used to validate the license.
 * This method can be used to unlock the SDK in library mode, i.e. when Microblink SDK is being
 * packaged inside 3rd party SDK. Unlocking Microblink SDK in library mode allows usage of
 * single license within multiple application packages.
 * @param fileName The name of resource file contained in the directory specified by subdirectory.
 * @param extension The filename extension of the file (etc. txt). If you specify an empty string or nil, the extension is assumed not to exist and the file URL is the first file encountered that exactly matches name.
 * @param subdirectory The valid path of top-level directory in which file is located inside bundle (etc. licenseFiles/). If you specify an empty string or nil, root direcotry of bundle will be searched.
 * @param bundle NSBundle bundle required to access file.
 * @param licensee Licensee to which license is given to.
 */
- (void)setLicenseResource:(NSString * _Nonnull)fileName withExtension:(NSString * _Nullable)extension inSubdirectory:(NSString * _Nullable)subdirectory forBundle:(NSBundle * _Nonnull)bundle andLicensee:(NSString *)licensee;

/**
 * Returns the string that contains the library build version
 *
 *  @return string that contains the library build version
 */
+ (NSString *)buildVersionString;

/**
 * This method returns true when scanning is unsupported on a specific device.
 * Error object contains description of the reason for that.
 *
 *  @param type The camera type you want to check for.
 *  @param error If scanning is not supported, when method this method returns, this parameter contains an NSError object that describes the
 * problem. If you are not interested in possible errors, pass in NULL.
 *
 *  @return YES if scanning is not supported, NO otherwise.
 */
+ (BOOL)isScanningUnsupportedForCameraType:(MBCameraType)type error:(NSError *_Nullable *_Nullable)error NS_SWIFT_NOTHROW;

@end

NS_ASSUME_NONNULL_END
