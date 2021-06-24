//
//  MBMrzResult.h
//  MicroblinkDev
//
//  Created by DoDo on 02/05/2018.
//

#import "MBMicroblinkDefines.h"
#import "MBDateResult.h"

#import "MBAgeResult.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Supported MRTD document types
 */
typedef NS_ENUM(NSInteger, MBMrtdDocumentType) {
    MBMrtdTypeUnknown,

    /** Identity card */
    MBMrtdTypeIdentityCard,

    /** Passport */
    MBMrtdTypePassport,

    /** Visa */
    MBMrtdTypeVisa,

    /** US Green Card */
    MBMrtdTypeGreenCard,
    
    /** Malaysian PASS type IMM13P */
    MBMrtdTypeMysPassIMM13P,
    
    /** One liner ISO DL */
    MBMrtdTypeDl,
    
    /** China mainland travel permit */
    MBMrtdTypeInternalTravelDocument

};

MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBMrzResult : NSObject<MBAgeResult>

MB_INIT_UNAVAILABLE

/**
 * Returns the MRTD document type of recognized document.
 */
@property (nonatomic, assign, readonly) MBMrtdDocumentType documentType;

/**
 * Returns the primary indentifier. If there is more than one component, they are separated with space.
 */
@property (nonatomic, strong, readonly) NSString *primaryID;

/**
 * Returns the secondary identifier. If there is more than one component, they are separated with space.
 */
@property (nonatomic, strong, readonly) NSString *secondaryID;

/**
 * Returns three-letter or two-letter code which indicate the issuing State. Three-letter codes are based
 * on Aplha-3 codes for entities specified in ISO 3166-1, with extensions for certain States. Two-letter
 * codes are based on Aplha-2 codes for entities specified in ISO 3166-1, with extensions for certain States.
 */
@property (nonatomic, strong, readonly) NSString *issuer;

/**
 * Returns issuer name
*/
@property (nonatomic, strong, readonly) NSString *issuerName;

/**
 * Returns holder's date of birth
 */
@property (nonatomic, strong, readonly) MBDateResult *dateOfBirth;

/**
 * Returns document number. Document number contains up to 9 characters.
 * Element does not exist on US Green Card. To see which document was scanned use documentType.
 */
@property (nonatomic, strong, readonly) NSString *documentNumber;

/**
 * Returns nationality of the holder represented by a three-letter or two-letter code. Three-letter
 * codes are based on Alpha-3 codes for entities specified in ISO 3166-1, with extensions for certain
 * States. Two-letter codes are based on Aplha-2 codes for entities specified in ISO 3166-1, with
 * extensions for certain States.
 */
@property (nonatomic, strong, readonly) NSString *nationality;

/**
 * Returns gender of the card holder. Gender is specified by use of the single initial, capital letter F for female,
 * M for male or ; for unspecified.
 */
@property (nonatomic, strong, readonly) NSString *gender;

/**
 * Returns document code. Document code contains two characters. For MRTD the first character shall
 * be A, C or I. The second character shall be discretion of the issuing State or organization except
 * that V shall not be used, and `C` shall not be used after `A` except in the crew member certificate.
 * On machine-readable passports (MRP) first character shall be `P` to designate an MRP. One additional
 * letter may be used, at the discretion of the issuing State or organization, to designate a particular
 * MRP. If the second character position is not used for this purpose, it shall be filled by the filter
 * character ;.
 */
@property (nonatomic, strong, readonly) NSString *documentCode;

/**
 * Returns date of expiry
 */
@property (nonatomic, strong, readonly) MBDateResult *dateOfExpiry;

/**
 * Returns first optional data. Returns empty string if not available.
 * Element does not exist on US Green Card. To see which document was scanned use documentType.
 */
@property (nonatomic, strong, readonly) NSString *opt1;

/**
 * Returns second optional data. Returns empty string if not available.
 * Element does not exist on US Green Card. To see which document was scanned use documentType.
 */
@property (nonatomic, strong, readonly) NSString *opt2;

/**
 * Returns alien number. Returns empty string if not available.
 * Exists only on US Green Cards. To see which document was scanned use documentType.
 */
@property (nonatomic, strong, readonly) NSString *alienNumber;

/**
 * Returns application receipt number. Returns empty string if not available.
 * Exists only on US Green Cards. To see which document was scanned use documentType.
 */
@property (nonatomic, strong, readonly) NSString *applicationReceiptNumber;

/**
 * Returns immigrant case number. Returns empty string if not available.
 * Exists only on US Green Cards. To see which document was scanned use documentType.
 */
@property (nonatomic, strong, readonly) NSString *immigrantCaseNumber;

/**
 * Returns the entire Machine Readable Zone text from ID. This text is usually used for parsing
 * other elements.
 * NOTE: This string is available only if OCR result was parsed successfully.
 */
@property (nonatomic, strong, readonly) NSString *mrzText;

/**
 * Returns true if Machine Readable Zone has been parsed, false otherwise.
 */
@property (nonatomic, assign, readonly) BOOL isParsed;

/**
 * Returns true if all check digits inside MRZ are correct, false otherwise.
 */
@property (nonatomic, assign, readonly) BOOL isVerified;

/**
 * Sanitized field opt1
 */
@property (nonatomic, strong, readonly) NSString *sanitizedOpt1;

/**
 * Sanitized field opt2
 */
@property (nonatomic, strong, readonly) NSString *sanitizedOpt2;

/**
 * Sanitized field nationality
 */
@property (nonatomic, strong, readonly) NSString *sanitizedNationality;

/**
 * Sanitized field issuer
 */
@property (nonatomic, strong, readonly) NSString *sanitizedIssuer;

/**
 * Sanitized document code
 */
@property (nonatomic, strong, readonly) NSString *sanitizedDocumentCode;

/**
 * Sanitized document number
 */
@property (nonatomic, strong, readonly) NSString *sanitizedDocumentNumber;

/**
 * Returns name of nationality 
*/
@property (nonatomic, strong, readonly) NSString *nationalityName;

@end

NS_ASSUME_NONNULL_END
