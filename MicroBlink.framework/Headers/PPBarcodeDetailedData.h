//
//  PPBarcodeDetailedData.h
//  Pdf417Framework
//
//  Created by Jura on 11/07/15.
//  Copyright (c) 2015 MicroBlink Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PPMicroBlinkDefines.h"

/**
 * Enumeration of barcode element types
 */
typedef NS_ENUM(NSInteger, PPBarcodeElementType) {

    /** barcode element is of type text and can be interpreted as string*/
    PPBarcodeElementTypeText,

    /** barcode element is arbitrary byte array */
    PPBarcodeElementTypeByte
};

/**
 * represents one raw element in barcode
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPBarcodeElement : NSObject

/** byte array contained in this barcode element */
@property (nonatomic, retain, readonly) NSData *elementBytes;

/** type of this element */
@property (nonatomic, assign, readonly) PPBarcodeElementType elementType;

/**
 Designated initializer shich sets byte array for specific barcode element type
 */
- (instancetype)initWithBytes:(NSData *)bytes
                         type:(PPBarcodeElementType)type;

@end

/**
 * represents the collection of barcode raw elements
 */
PP_CLASS_AVAILABLE_IOS(6.0) @interface PPBarcodeDetailedData : NSObject

/** array of barcode elements (PPBarcodeElement *) contained in barcode */
@property (nonatomic, retain, readonly) NSArray *barcodeElements;

/**
 Designated initializer which sets all barcode elements
 */
- (instancetype)initWithElements:(NSArray *)barcodeElements;

/**
 * Use this method to get all barcode data in one byte array.
 * This is useful if you know how to interpret barcode data
 * and don't want to bother with all barcode elements.
 */
- (NSData *)getAllData;

@end
