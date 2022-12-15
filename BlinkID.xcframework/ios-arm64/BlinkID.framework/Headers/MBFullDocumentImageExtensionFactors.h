//
//  MBFullDocumentImageExtensionFactors.h
//  MicroblinkDev
//
//  Created by Dino on 19/06/2018.
//

#import "MBImageExtensionFactors.h"

@protocol MBFullDocumentImageExtensionFactors

@required

/**
 * Image extension factors for full document image.
 *
 * @see MBImageExtensionFactors
 * Default: {0.0f, 0.0f, 0.0f, 0.0f}
 */
@property (nonatomic, assign) MBImageExtensionFactors fullDocumentImageExtensionFactors;

@end
