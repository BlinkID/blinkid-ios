//
//  MBJordanCombinedRecognizer.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBMicroblinkDefines.h"
#import "MBLegacyRecognizer.h"
#import "MBMicroblinkInitialization.h"
#import "MBJordanCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBFaceImage.h"

#import "MBDigitalSignature.h"

#import "MBEncodeFaceImage.h"
#import "MBEncodeFullDocumentImage.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Jordan ID Combined Recognizer.
 *
 * Jordan ID Combined recognizer is used for scanning both front and back side of Jordan ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBJordanCombinedRecognizer : MBLegacyRecognizer<NSCopying, MBCombinedRecognizer, MBGlareDetection, MBFullDocumentImage, MBFaceImage, MBEncodeFaceImage, MBEncodeFullDocumentImage, MBDigitalSignature>

MB_INIT

/**
 * Jordan ID Combined recognizer result
 */
@property (nonatomic, strong, readonly) MBJordanCombinedRecognizerResult* result;

/**
 * Defines if owner's name should be extracted from Jordan ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractName;

/**
 * Defines if owner's sex should be extracted from Jordan ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSex;

/**
 * Defines if owner's date of birth should be extracted from Jordan ID
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfBirth;

@end

NS_ASSUME_NONNULL_END
