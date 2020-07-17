//
//  MBCombinedRecognizerResult.h
//  MicroblinkDev
//
//  Created by DoDo on 17/05/2018.
//

#ifndef MBCombinedRecognizerResult_h
#define MBCombinedRecognizerResult_h

/**
* Result of the data matching algorithm for scanned parts/sides of the document.
**/
typedef NS_ENUM(NSInteger, MBDataMatchResult) {
    /** Data matching has not been performed. */
    MBDataMatchResultNotPerformed = 0,
    /** Data does not match. */
    MBDataMatchResultFailed,
    /** Data match. */
    MBDataMatchResultSuccess
};

@protocol MBCombinedRecognizerResult

@required

/**
 * Returns MBDataMatchResultSuccess if data from scanned parts/sides of the document match,
 * MBDataMatchResultFailed otherwise. For example if date of expiry is scanned from the front and back side
 * of the document and values do not match, this method will return MBDataMatchResultFailed. Result will
 * be MBDataMatchResultSuccess only if scanned values for all fields that are compared are the same.
 */
@property (nonatomic, readonly, assign) MBDataMatchResult documentDataMatch;

/**
 * Returns YES if recognizer has finished scanning first side and is now scanning back side,
 * NO if it's still scanning first side.
 */
@property (nonatomic, readonly, assign) BOOL scanningFirstSideDone;

@end

#endif /* MBCombinedRecognizerResult_h */
