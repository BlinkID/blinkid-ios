//
//  PPOcrOverlaySubview.h
//  BlinkMoto-demo
//
//  Created by Jura Skrlec on 02/06/2017.
//  Copyright © 2017 MicroBlink. All rights reserved.
//

#import <MicroBlink/MicroBlink.h>

@interface PPOcrOverlaySubview : PPOverlaySubview

@property (nonatomic) UIColor *foregroundColor;
@property (nonatomic) UIColor *strokeColor;

/** Setting this to YES prevents ocr characters from being displayed */
@property (nonatomic) BOOL hideCharacters;

/** Setting this to YES prevents the characters from being distorted when fitted into the ocr returned rect */
@property (nonatomic) BOOL preserveCharacterAspectRatio;

/** Setting this to YES draws bounding boxes for ocr characters */
@property (nonatomic) BOOL drawBoundingBox;

/** Setting this to YES draws ocr characters with an Y offset (can be helpful if overlap prevets seeing the exact ocr char) */
@property (nonatomic) BOOL drawWithOffset;

/** Setting this to YES freezes the last result onscreen and successive results are ignored */
@property (nonatomic) BOOL hold;

@end
