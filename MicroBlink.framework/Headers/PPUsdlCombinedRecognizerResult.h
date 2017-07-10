//
//  PPUsdlCombinedRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 19/06/2017.
//
//

#import "PPRecognizerResult.h"

#import "PPMicroBlinkDefines.h"

/**
 * Result of scanning with USDL Combined recognizer
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPUsdlCombinedRecognizerResult : PPRecognizerResult

/**
 * YES if Data from the front side is matching the data from the back side
 */
@property (nonatomic, readonly) BOOL matchingData;

/**
 * Contains signature which confirms that this data originates from the SDK
 */
@property (nonatomic, readonly, nullable) NSData *signature;

/**
 * Contains the version of the signature
 */
@property (nonatomic, readonly, nullable) NSString *signatureVersion;

/**
 * Byte buffer with face image
 */
@property (nonatomic, readonly, nullable) NSData *faceImage;

/**
 * Returns a string value for a given key.
 *
 *  @param key field key
 *
 *  @return value for a given key
 */
- (NSString *_Nullable)getField:(const NSString *_Nonnull)key;

/**
 * Returns all possible USDL keys with their descriptions.
 *
 *  @return NSDictionary with USDL key - description pairs
 */
+ (NSDictionary *_Nonnull)descriptionKeys;

/**
 * Returns all possible USDL keys ordered as in this header.
 *
 *  @return Array of all USDL keys ordered as in this header
 */
+ (NSArray<NSString *> *_Nonnull)orderedKeys;

@end
