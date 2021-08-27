//
//  MBDigitalSignature.h
//  MicroblinkDev
//
//  Created by DoDo on 17/05/2018.
//

#ifndef MBDigitalSignature_h
#define MBDigitalSignature_h

@protocol MBDigitalSignature

@required

/**
 * Whether or not recognition result should be signed.
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL signResult;

@end

#endif /* MBDigitalSignature_h */
