//
//  MBDocumentSubview.h
//  MicroBlinkDev
//
//  Created by Jura on 03/02/2019.
//

#import "MBSubview.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Overlay subview presenting the document for scanning
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBRectDocumentSubview : MBSubview

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

@property (nonatomic) CGFloat widthToHightAspectRatio;

@property (nonatomic) NSString *titleText;

- (void)startScanLineAnimation;

- (void)stopScanLineAnimation;

- (void)startFlipAnimation;

@end

NS_ASSUME_NONNULL_END
