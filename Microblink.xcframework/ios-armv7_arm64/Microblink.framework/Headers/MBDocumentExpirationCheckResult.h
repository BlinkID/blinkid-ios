//
//  MBDocumentExpiredResult.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 07/07/2020.
//

#ifndef MBDocumentExpirationCheckResult_h
#define MBDocumentExpirationCheckResult_h

@protocol MBDocumentExpirationCheckResult

@required

/**
 * Checks whether the document has expired or not by comparing the current
 * time on the device with the date of expiry.
 *
 * @return YES if the document has expired, NO in following cases:
 * document does not expire (date of expiry is permanent)
 * date of expiry has passed
 * date of expiry is unknown and it is not permanent
*/
@property (nonatomic, readonly) BOOL expired NS_SWIFT_NAME(isExpired);

@end

#endif /* MBDocumentExpirationCheckResult_h */
