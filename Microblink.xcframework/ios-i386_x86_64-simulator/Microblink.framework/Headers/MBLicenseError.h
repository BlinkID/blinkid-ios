//
//  MBLicenseError.h
//  MicroblinkDev
//
//  Created by Mijo Gracanin on 23/09/2020.
//

#ifndef MBLicenseError_h
#define MBLicenseError_h

#import <Foundation/Foundation.h>

extern NSString * const MBLicenseErrorNotification;

typedef NS_ENUM(NSInteger, MBLicenseError) {
    MBLicenseErrorNetworkRequired,
    MBLicenseErrorUnableToDoRemoteLicenceCheck,
    MBLicenseErrorLicenseIsLocked,
    MBLicenseErrorLicenseCheckFailed
};

typedef void(^MBLicenseErrorBlock)(MBLicenseError licenseError);

#endif /* MBLicenseError_h */
