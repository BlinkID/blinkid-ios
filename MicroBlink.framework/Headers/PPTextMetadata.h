//
//  PPTextMetadata.h
//  PhotoPayFramework
//
//  Created by Jura on 02/03/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPMetadata.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Type of the text metadata
 */
typedef NS_ENUM(NSUInteger, PPTextMetadataType){
    /** Regular text metadata */
    PPTextMetadataTypeTxt,
    /** XML formatter metadata */
    PPTextMetadataTypeXml,
    /** JSON formatted metadata */
    PPTextMetadataTypeJson,
};

/**
 * Textual type of Metadata returned by MicroBlink scanner.
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPTextMetadata : PPMetadata

/**
 * Actual text in the metadata.
 */
@property (nonatomic, strong) NSString* text;

/**
 * Type of the text metadata
 */
@property (nonatomic, assign) PPTextMetadataType type;

/**
 * Retuns an initialized PPTextMetadata object with given name and text value
 *
 * Default type is PPTextMetadataTypeTxt
 *
 *  @param name name (id) of the metadata
 *  @param text text value
 *
 *  @return Initialized PPTextMetadata object with given name and text value, with default type PPTextMetadataTypeTxt
 */
- (instancetype)initWithName:(NSString *)name
                        text:(NSString*)text;

/**
 * Retuns an initialized PPTextMetadata object with given name, text value and type
 *
 *  @param name name (id) of the metadata
 *  @param text text value
 *  @param type type of the metadata
 *
 *  @return Initialized PPTextMetadata object with given name, text value and type
 */
- (instancetype)initWithName:(NSString *)name
                        text:(NSString*)text
                        type:(PPTextMetadataType)type;

@end

NS_ASSUME_NONNULL_END