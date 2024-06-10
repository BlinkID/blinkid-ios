//
//  MBImageAnalysisResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 06/07/2020.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBDocumentImageColorStatus.h"
#import "MBImageAnalysisDetectionStatus.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MBCardOrientation) {
    MBCardOrientationHorizontal,
    MBCardOrientationVertical,
    MBCardOrientationNotAvailable
};

typedef NS_ENUM(NSInteger, MBRotation) {
    MBRotationZero,
    MBRotationClockwise90,
    MBRotationCounterClockwise90,
    MBRotationUpsideDown,
    MBRotationNone
};

MB_CLASS_AVAILABLE_IOS(13.0) MB_FINAL
@interface MBImageAnalysisResult : NSObject

MB_INIT_UNAVAILABLE

/**
 * Whether blur is detected on the image.
 */
@property (nonatomic, readonly, assign) BOOL blurDetected;

/**
 * Whether glare is detected on the image.
 */
@property (nonatomic, readonly, assign) BOOL glareDetected;

/**
 * The color status determined from scanned image.
 */
@property (nonatomic, readonly, assign) MBDocumentImageColorStatus documentImageColorStatus;

/**
 * The Moire pattern detection status determined from the scanned image.
 */
@property (nonatomic, readonly, assign) MBImageAnalysisDetectionStatus documentImageMoireStatus;

/**
 * Face detection status determined from the scanned image.
 */
@property (nonatomic, readonly, assign) MBImageAnalysisDetectionStatus faceDetectionStatus;

/**
 * Mrz detection status determined from the scanned image.
 */
@property (nonatomic, readonly, assign) MBImageAnalysisDetectionStatus mrzDetectionStatus;

/**
 * Barcode detection status determined from the scanned image.
 */
@property (nonatomic, readonly, assign) MBImageAnalysisDetectionStatus barcodeDetectionStatus;

/**
 * RealID detection status determined from the scanned image.
 */
@property (nonatomic, readonly, assign) MBImageAnalysisDetectionStatus realIDDetectionStatus;

/**
 * Orientation determined from the scanned image.
 */
@property (nonatomic, readonly, assign) MBCardOrientation cardOrientation;

/**
 * Orientation determined from the scanned image.
 */

@property (nonatomic, readonly, assign) MBRotation cardRotation;

@end

NS_ASSUME_NONNULL_END
