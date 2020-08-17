//
//  MBRecognitionModeFilter.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 11/08/2020.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
* MBRecognitionModeFilter is used to enable/disable recognition of specific document groups.
* Setting is taken into account only if the right for that document is purchased.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBRecognitionModeFilter : NSObject <NSCopying>

MB_INIT

/**
 * Enable scanning of MRZ IDs. Setting is taken into account only if the mrz_id right is purchased.
 */
@property (nonatomic, assign) BOOL enableMrzId;

/**
 * Enable scanning of visa MRZ. Setting is taken into account only if the visa right is purchased.
 */
@property (nonatomic, assign) BOOL enableMrzVisa;

/**
 * Enable scanning of Passport MRZ. Setting is taken into account only if the passport right is purchased.
 */
@property (nonatomic, assign) BOOL enableMrzPassport;

/**
 * Enable scanning of Photo ID. Setting is taken into account only if the photo_id right is purchased.
 */
@property (nonatomic, assign) BOOL enablePhotoId;

/**
 * Enable full document recognition. Setting is taken into account only if the document right to scan that document is purchased.
 */
@property (nonatomic, assign) BOOL enableFullDocumentRecognition;

@end

NS_ASSUME_NONNULL_END
