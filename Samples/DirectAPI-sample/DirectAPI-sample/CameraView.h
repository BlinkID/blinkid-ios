//
//  CameraVIew.h
//  DirectAPI-Sample
//
//  Created by Jura on 09/08/15.
//  Copyright © 2015 MicroBlink. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <AVFoundation/AVFoundation.h>

@interface CameraView : UIView

@property (nonatomic) AVCaptureSession *session;

@end
