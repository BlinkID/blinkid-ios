//
//  MBPdf417Recognizer.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 27/11/2017.
//

#import <Foundation/Foundation.h>

#import "MBMicroblinkDefines.h"
#import "MBRecognizer.h"
#import "MBPdf417RecognizerResult.h"
#import "MBMicroblinkInitialization.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A recognizer that can scan PDF417 2D barcodes.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBPdf417Recognizer : MBRecognizer<NSCopying>

MB_INIT

/**
 * PDF417 recognizer results
 */
@property (nonatomic, strong, readonly) MBPdf417RecognizerResult *result;

/**
 * Set this to YES to scan even barcode not compliant with standards
 * For example, malformed PDF417 barcodes which were incorrectly encoded
 *
 * Use only if necessary because it slows down the recognition process
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL scanUncertain;

/**
 * Set this to YES to scan barcodes which don't have quiet zone (white area) around it
 *
 * Use only if necessary because it slows down the recognition process
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL nullQuietZoneAllowed;

/**
 * Set this to YES to allow scanning barcodes with inverted intensities
 * (i.e. white barcodes on black background)
 *
 * NOTE: this options doubles the frame processing time
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL scanInverse;

@end

NS_ASSUME_NONNULL_END
