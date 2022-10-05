//
//  MBException.h
//  Pdf417MobiDev
//
//  Created by Jura Skrlec on 07/02/2018.
//

#ifndef MBException_h
#define MBException_h

typedef NSString * MBExceptionName NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT MBExceptionName const MBIllegalModificationException;
FOUNDATION_EXPORT MBExceptionName const MBInvalidLicenseKeyException;
FOUNDATION_EXPORT MBExceptionName const MBInvalidLicenseeKeyException;
FOUNDATION_EXPORT MBExceptionName const MBInvalidLicenseResourceException;
FOUNDATION_EXPORT MBExceptionName const MBInvalidBundleException;
FOUNDATION_EXPORT MBExceptionName const MBMissingSettingsException;
FOUNDATION_EXPORT MBExceptionName const MBInvalidArgumentException;

#endif /* MBException_h */
