//
//  MBKuwaitIdBackRecognizerResult.h
//  MicroblinkDev
//
//  Created by juraskrlec on 30/08/2018.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"
#import "MBMrzResult.h"
#import "MBFullDocumentImageResult.h"
#import "MBEncodedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class representing values obtained when scanning back side of the Kuwait Id
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBKuwaitIdBackRecognizerResult : MBRecognizerResult<NSCopying, MBFullDocumentImageResult, MBEncodedFullDocumentImageResult>

MB_INIT_UNAVAILABLE
/**
 * The data extracted from the machine readable zone
 */
@property (nonatomic, readonly) MBMrzResult *mrzResult;

/**
 * The serial number of Kuwait ID
 */
@property (nonatomic, readonly) NSString *serialNo;

@end

NS_ASSUME_NONNULL_END
