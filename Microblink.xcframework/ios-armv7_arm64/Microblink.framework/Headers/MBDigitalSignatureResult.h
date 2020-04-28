//
//  MBDigitalSignatureResult.h
//  MicroblinkDev
//
//  Created by DoDo on 17/05/2018.
//

#ifndef MBDigitalSignatureResult_h
#define MBDigitalSignatureResult_h

#import <Foundation/Foundation.h>

@protocol MBDigitalSignatureResult

@required

/**
 * Digital signature of the recognition result. Available only if enabled with `MBDigitalSignature signResult` property.
 */
@property (nonatomic, readonly, nullable) NSData* digitalSignature;

/**
 * Version of the digital signature. Available only if enabled with `MBDigitalSignature signResult` property.
 */
@property (nonatomic, readonly) NSUInteger digitalSignatureVersion;

@end

#endif /* MBDigitalSignatureResult_h */
