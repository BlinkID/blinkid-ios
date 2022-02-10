//
//  MBDocumentVerificationInstructionsSubview.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 29/05/2018.
//

#import "MBSubview.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(8.0) MB_CLASS_DEPRECATED("Use MBBlinkIdOverlayViewController.") MB_FINAL
@interface MBLegacyDocumentVerificationInstructionsSubview : MBSubview

@property (nonatomic) UILabel *instructionsLabel;

@property (nonatomic) UIImageView *instructionsImageView;

@end

NS_ASSUME_NONNULL_END
