//
//  PMDebugOcrOverlaySubview.m
//  PhotoMath
//
//  Created by Marko Mihovilić on 31/08/16.
//  Copyright © 2016 Photomath, Inc. All rights reserved.
//

#import "PPOcrOverlaySubview.h"
#import <CoreText/CoreText.h>

@interface PPOcrOverlaySubview ()

@property (nonatomic) NSArray<PPOcrChar *> *chars;
@property (nonatomic) CGAffineTransform perspective;
@property (nonatomic) UIInterfaceOrientation orientation;
@end

static const CGFloat kDebugOcrOverlayMaxAlpha = 1;

static const CGFloat kDebugOcrOverlayReferenceFontSize = 60;

static NSString *const kDebugOcrOverlayFontName = @"Helvetica";

@implementation PPOcrOverlaySubview

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        self.userInteractionEnabled = NO;
        self.backgroundColor = [UIColor clearColor];
        
        _foregroundColor = [UIColor purpleColor];
        _strokeColor = [UIColor cyanColor];
    }
    return self;
}

- (void)drawRect:(CGRect)rect {
    CGContextClearRect(UIGraphicsGetCurrentContext(), rect);
    
    // Setup a "normal" coordinate system where the origin is in the top-left corner
    CGContextTranslateCTM(UIGraphicsGetCurrentContext(), 0, self.bounds.size.height);
    CGContextScaleCTM(UIGraphicsGetCurrentContext(), 1, -1);
    
    CGContextSetStrokeColorWithColor(UIGraphicsGetCurrentContext(), [self.strokeColor CGColor]);
    CGContextSetLineWidth(UIGraphicsGetCurrentContext(), 1.0);
    
    CGAffineTransform matrix = CGAffineTransformIdentity;
    
    if (self.orientation == UIInterfaceOrientationLandscapeLeft) {
        matrix = CGAffineTransformMakeRotation(-M_PI / 2);
    } else if (self.orientation == UIInterfaceOrientationLandscapeRight) {
        matrix = CGAffineTransformMakeRotation(M_PI / 2);
    }
    
    CTFontRef font = CTFontCreateWithName((CFStringRef)kDebugOcrOverlayFontName, kDebugOcrOverlayReferenceFontSize, &matrix);
    
    for (PPOcrChar *c in self.chars) {
        
        CGRect rect = CGRectApplyAffineTransform(c.position.rect, self.perspective);
        
        // Correction for coordinate system
        rect = CGRectMake(rect.origin.x, self.bounds.size.height - rect.origin.y - rect.size.height, rect.size.width, rect.size.height);
        
        if (self.drawBoundingBox) {
            CGContextStrokeRect(UIGraphicsGetCurrentContext(), rect);
        }
        
        if (self.hideCharacters) {
            continue;
        }
        
        wchar_t bytes = c.value;
        
        CFStringRef str = CFStringCreateWithBytes(kCFAllocatorDefault, (const UInt8 *)&bytes, sizeof(bytes), kCFStringEncodingUTF32LE, NO);
        
        UniChar chr = CFStringGetCharacterAtIndex(str, 0);
        
        CFRelease(str);
        
        CGGlyph glf;
        
        CTFontGetGlyphsForCharacters(font, &chr, &glf, 1);
        
        CGRect frame;
        
        CTFontGetBoundingRectsForGlyphs(font, kCTFontOrientationDefault, &glf, &frame, 1);
        
        CGSize scale = CGSizeMake(rect.size.width / frame.size.width, rect.size.height / frame.size.height);
        
        if (self.preserveCharacterAspectRatio) {
            scale.width = scale.height = MIN(scale.width, scale.height);
        }
        
        
        CGContextSaveGState(UIGraphicsGetCurrentContext());
        
        NSInteger quality = [c quality];
        UIColor *color = nil;
        
        const CGFloat threshold = 70.f;
        
        if (quality <= threshold) {
            color = [self evaluateWithFraction:quality / threshold startValue:[UIColor redColor] endValue:[UIColor yellowColor]];
        } else {
            color = [self evaluateWithFraction:(quality - threshold) / (100.f - threshold) startValue:[UIColor yellowColor] endValue:[UIColor greenColor]];
        }
        
        CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), [color CGColor]);
        
        
        CGFloat offset = self.drawWithOffset ? 75 : 0;
        
        CGContextTranslateCTM(UIGraphicsGetCurrentContext(), CGRectGetMidX(rect), CGRectGetMidY(rect) - offset);
        CGContextScaleCTM(UIGraphicsGetCurrentContext(), scale.width, scale.height);
        
        CGPoint center = CGPointMake(-frame.origin.x - frame.size.width / 2, -frame.origin.y - frame.size.height / 2);
        
        CTFontDrawGlyphs(font, &glf, &center, 1, UIGraphicsGetCurrentContext());
        
        CGContextRestoreGState(UIGraphicsGetCurrentContext());
    }
    
    CFRelease(font);
}

- (UIColor *)evaluateWithFraction:(float)fraction startValue:(UIColor *)startValue endValue:(UIColor *)endValue {
    
    CGFloat startR, startG, startB, startA;
    [startValue getRed:&startR green:&startG blue:&startB alpha:&startA];
    
    CGFloat endR, endG, endB, endA;
    [endValue getRed:&endR green:&endG blue:&endB alpha:&endA];
    
    return [UIColor colorWithRed:(startR + fraction * (endR - startR))
                           green:(startG + fraction * (endG - startG))
                            blue:(startB + fraction * (endB - startB))
                           alpha:(startA + fraction * (endA - startA))];
}

- (NSArray<PPOcrChar *> *)getCharsFromLayout:(PPOcrLayout *)layout {
    NSMutableArray<PPOcrChar *> *arrayOfChars = [[NSMutableArray alloc] init];
    for (PPOcrBlock *block in layout.blocks) {
        for (PPOcrLine *line in block.lines) {
            for (PPOcrChar *c in line.chars) {
                [arrayOfChars addObject:c];
            }
        }
    }
    return arrayOfChars;
}

- (void)overlayDidObtainOcrLayout:(PPOcrLayout *)ocrLayout withIdentifier:(NSString *)identifier {
    if (self.hold) {
        return;
    }
    
    self.chars = [self getCharsFromLayout:ocrLayout];
    
    self.perspective = ocrLayout.transform;
    
    [self setNeedsDisplay];
}

- (void)setHold:(BOOL)hold {
    _hold = hold;
}

@end
