//
//  MBSingaporeIdBackRecognizer.h
//  MicroblinkDev
//
//  Created by dinogustin on 27/07/2018.
//

#import "MBRecognizer.h"
#import "MBSingaporeIdBackRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class for configuring Singapore Id Back Recognizer.
 *
 * Singapore Id Back recognizer is used for scanning back side of the Singapore Id.
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBSingaporeIdBackRecognizer : MBRecognizer <NSCopying, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Singapore Id Back
 */
@property (nonatomic, strong, readonly) MBSingaporeIdBackRecognizerResult *result;

/**
 * Defines if owner's address should be extracted from back side of the Singapore Id
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractAddress;

/**
 * Defines if owner's address change date should be extracted from back side of the Singapore Id
 *
 * Default: NO
 */
@property (nonatomic, assign) BOOL extractAddressChangeDate;

/**
 * Defines if owner's blood type should be extracted from back side of the Singapore Id
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractBloodGroup;

/**
 * Defines if owner's date of issue should be extracted from back side of the Singapore Id
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractDateOfIssue;

@end

NS_ASSUME_NONNULL_END
