//
//  MBAnonymizationMode.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 06/07/2020.
//

#ifndef MBAnonymizationMode_h
#define MBAnonymizationMode_h

/**
 * MBAnonymizationMode is used to define level of anonymization performed on recognizer result.
 */
typedef NS_ENUM(NSInteger, MBAnonymizationMode) {
    
    /**
     * Anonymization will not be performed.
     */
    MBAnonymizationModeNone = 0,
    
    /**
     * FullDocumentImage is anonymized with black boxes covering sensitive data.
     */
    MBAnonymizationModeImageOnly,
    
    /**
     * Result fields containing sensitive data are removed from result.
     */
    MBAnonymizationModeResultFieldsOnly,
    
    /**
     * This mode is combination of ImageOnly and ResultFieldsOnly modes.
     */
    MBAnonymizationModeFullResult
};


#endif /* MBAnonymizationMode_h */
