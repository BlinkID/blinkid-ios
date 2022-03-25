//
//  MBDocumentVerifiactionSubview.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 28/05/2018.
//

#import "MBSubview.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MBLegacyDocumentVerificationSubviewDelegate;

MB_CLASS_AVAILABLE_IOS(8.0) MB_CLASS_DEPRECATED("Use MBBlinkIdOverlayViewController.") MB_FINAL
@interface MBLegacyDocumentVerificationSubview : MBSubview

@property (nonatomic) UILabel *helpLabel;

@property (nonatomic) UIImageView *helpImageView;

- (void)animateHelp;

@property (nonatomic, weak) id<MBLegacyDocumentVerificationSubviewDelegate> documentVerificationSubviewDelegate;

@end

@protocol MBLegacyDocumentVerificationSubviewDelegate <NSObject>

- (void)documentVerificationSubviewDidFinishAnimation:(MBLegacyDocumentVerificationSubview *)documentVerificationSubview;

@end

NS_ASSUME_NONNULL_END
