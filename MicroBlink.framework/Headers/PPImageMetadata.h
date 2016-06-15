//
//  PPImageMetadata.h
//  PhotoPayFramework
//
//  Created by Jura on 02/03/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import "PPMetadata.h"
#import <UIKit/UIKit.h>

/**
 * Type of returned image
 * By default no images are outputted and you can configure which ones will be outputted in PPMetadataSettings
 * You can get PPMetadataSettings object accessing metadataSettings property of PPSettings (when creating a coordinator for example)
 */
typedef NS_ENUM(NSUInteger, PPImageMetadataType) {
    
    /**
     * Outputs all images with successful detection. PPMetadataSettings property successfulFrame needs to be set to YES.
     */
    PPImageMetadataTypeSuccessfulFrame,
    
    /**
     * Outputs all dewarped images with successful detection. PPMetadataSettings property dewarpedImage needs to be set to YES.
     */
    PPImageMetadataTypeDewarpedImage,
    
    /**
     * Outputs all input images. PPMetadataSettings property currentFrame needs to be set to YES.
     */
    PPImageMetadataTypeCurrentFrame,
    
    
    
    /**
     * Debug images (and PPDebugMetadata) are only needed if you need to figure out what is not working as expected.
     */
    
    /**
     * Outputs all OCR input images. PPDebugMetadata property ocrInputFrame needs to be set to YES.
     */
    PPImageMetadataTypeDebugOcrInputFrame,
    
    /**
     * Outputs all detection input images. PPDebugMetadata property detectionFrame needs to be set to YES.
     */
    PPImageMetadataTypeDebugDetectionFrame,
    
    /**
     * Outputs all dewarped elements images. PPDebugMetadata property dewarpedElements needs to be set to YES.
     */
    PPImageMetadataTypeDebugDewrapedElements,
};

NS_ASSUME_NONNULL_BEGIN

/**
 * Class containing UIImage of detected, dewraped or input frame.
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPImageMetadata : PPMetadata

/**
 * Orientation with which contained UIImage was processed
 */
@property (nonatomic, assign, readonly) UIImageOrientation orientation;

/**
 * Type of image returned.
 */
@property (nonatomic, readonly) PPImageMetadataType imageType;

/**
 * Please use designated initializer.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Please use designated initializer.
 */
- (instancetype)initWithName:(NSString *)name NS_UNAVAILABLE;

/**
 * Creates new PPImageMetadata with desired parameters.
 */
- (instancetype)initWithName:(NSString *)name
                 orientation:(UIImageOrientation)orientation
                   imageType:(PPImageMetadataType)imageType NS_DESIGNATED_INITIALIZER;

/**
 * UIImage of returned PPImageMetadata.
 * This image is lazy loaded.
 */
- (UIImage *)image;

@end

NS_ASSUME_NONNULL_END