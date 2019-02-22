//
//  MBDocumentVerifiactionSubview.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 28/05/2018.
//

#import "MBSubview.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MBDocumentVerificationSubviewDelegate;

MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBDocumentVerificationSubview : MBSubview

@property (nonatomic) UILabel *helpLabel;

@property (nonatomic) UIImageView *helpImageView;

- (void)animateHelp;

@property (nonatomic, weak) id<MBDocumentVerificationSubviewDelegate> documentVerificationSubviewDelegate;

@end

@protocol MBDocumentVerificationSubviewDelegate <NSObject>

- (void)documentVerificationSubviewDidFinishAnimation:(MBDocumentVerificationSubview *)documentVerificationSubview;

@end

NS_ASSUME_NONNULL_END
