//
//  MBDataMatchDetailedInfo.hpp
//  BlinkShowcaseDev
//
//  Created by Mijo Gracanin on 02.06.2022..
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBCombinedRecognizerResult.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(9.0)
@interface MBDataMatchDetailedInfo : NSObject

/**
 * Returns result of the data matching algorithm for scanned parts/sides of the document.
 * For example if date of expiry is scanned from the front and back side
 * of the document and values do not match, this method will return {@link DataMatchResult#Failed}.
 * Result will be {@link DataMatchResult#Success} only if scanned values for all fields that are
 * compared are the same. If data matching has not been performed, result will be
 * {@link DataMatchResult#NotPerformed}.
 *
 * @return result of the data matching algorithm for scanned parts/sides of the document.
 */
- (MBDataMatchResult) getDataMatchResult;

/**
 * The result of data match on date of birth field.
 *
 * @return result of the data matching algorithm for date of birth field.
 */
- (MBDataMatchResult) getDateOfBirth;

/**
 * The result of data match on date of expiry field.
 *
 * @return result of the data matching algorithm for date of expiry field.
 */
- (MBDataMatchResult) getDateOfExpiry;
/**
 * The result of data match on document number field.
 *
 * @return result of the data matching algorithm for document number field.
 */
- (MBDataMatchResult) getDocumentNumber;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
