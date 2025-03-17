//
//  MBSampleBufferWrapper.h
//  DocumentVerification
//
//  Created by DoDo on 23.12.2024..
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A wrapper class for CMSampleBufferRef that provides proper memory management and ABI stability.
///
/// `MBSampleBufferWrapper` safely encapsulates a Core Media sample buffer, ensuring proper
/// reference counting and memory management while maintaining binary compatibility
/// across different Swift versions.
@interface MBSampleBufferWrapper : NSObject

@property (nonatomic) CMSampleBufferRef buffer;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithCMSampleBuffer:(CMSampleBufferRef) cmSampleBuffer;

@end

NS_ASSUME_NONNULL_END
