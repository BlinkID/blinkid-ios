//
//  PPMrtdCombinedRecognizerResult.h
//  MicroBlinkDev
//
//  Created by Jura Skrlec on 03/07/2017.
//
//

#import "PPRecognizerResult.h"
#import "PPMrtdDocumentType.h"

/**
 * Result of scanning with MRTD Combined recognizer
 */
PP_CLASS_AVAILABLE_IOS(6.0)
@interface PPMrtdCombinedRecognizerResult : PPRecognizerResult

/**
 * Boolean value which denotes that MRTD result is successfully parsed. When the result is parsed, all
 * properties below are present.
 *
 * If in the PPMrtdRecognizerSettings you specified allowUnparsedResults = YES, then it can happen that
 * MRTDRecognizerResult is not parsed. When this happens, this property will be equal to YES.
 *
 * In that case, you can use rawOcrResult property to obtain the raw result of the OCR process, so you can
 * implement MRTD parsing in your application.
 *
 *  @return YES if MRTD Recognizer result was successfully parsed and all the fields are extracted. NO otherwise.
 */
@property (nonatomic, readonly) BOOL isParsed;


/**
 *  MRTD document type of recognized document.
 */
@property (nonatomic, readonly) PPMrtdDocumentType documentType;

/**
 * Three-letter code which indicate the issuing State.
 * Three-letter codes are based on Alpha-3 codes for entities specified in
 * ISO 3166-1, with extensions for certain States.
 */
@property (nonatomic, readonly, nullable) NSString *issuer;

/**
 * Unique number of the document. Document number contains up to 9 characters.
 * Element does not exist on US Green Card. To see which document was scanned use documentType property.
 */
@property (nonatomic, readonly, nullable) NSString *documentNumber;

/**
 * The document code. Document code contains two characters. For MRTD the first character
 * shall be A, C or I. The second character shall be discretion of the issuing State or organization
 * except that V shall not be used, and C shall not be used after A except in the crew member
 * certificate. On machine-readable passports (MRP) first character shall be P to designate an MRP.
 * One additional letter may be used, at the discretion of the issuing State or organization,
 * to designate a particular MRP. If the second character position is not used for this purpose, it
 * shall be filled by the filter character <.
 */
@property (nonatomic, readonly, nullable) NSString *documentCode;

/**
 * Date of expiry of the document in format YYMMDD.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfExpiry;


/**
 * Date of expiry of the document.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfExpiry;

/**
 * Returns the primary indentifier. If there is more than one component, they are separated with space.
 *
 *  @return primary id of a card holder.
 */
@property (nonatomic, readonly, nullable) NSString *primaryId;

/**
 * Returns the secondary identifier. If there is more than one component, they are separated with space.
 *
 *  @return secondary id of a card holder
 */
@property (nonatomic, readonly, nullable) NSString *secondaryId;

/**
 * Holder's date of birth in format YYMMDD.
 */
@property (nonatomic, readonly, nullable) NSString *rawDateOfBirth;

/**
 * Holder's date of birth.
 */
@property (nonatomic, readonly, nullable) NSDate *dateOfBirth;

/**
 * Nationality of the holder represented by a three-letter code. Three-letter codes are based
 * on Alpha-3 codes for entities specified in ISO 3166-1, with extensions for certain States.
 */
@property (nonatomic, readonly, nullable) NSString *nationality;

/**
 * Sex of the card holder. Sex is specified by use of the single initial, capital
 * letter F for female, M for male or < for unspecified.
 */
@property (nonatomic, readonly, nullable) NSString *sex;

/**
 * First optional data. Returns nil or empty string if not available.
 * Element does not exist on US Green Card. To see which document was scanned use documentType property.
 */
@property (nonatomic, readonly, nullable) NSString *opt1;

/**
 * Second optional data. Returns nil or empty string if not available.
 * Element does not exist on Passports and Visas. To see which document was scanned use documentType property.
 */
@property (nonatomic, readonly, nullable) NSString *opt2;

/**
 * Alien number. Returns nil or empty string if not available.
 * Exists only on US Green Cards. To see which document was scanned use documentType property.
 */
@property (nonatomic, readonly, nullable) NSString *alienNumber;

/**
 * Application receipt number. Returns nil or empty string if not available.
 * Exists only on US Green Cards. To see which document was scanned use documentType property.
 */
@property (nonatomic, readonly, nullable) NSString *applicationReceiptNumber;

/**
 * Immigrant case number. Returns nil or empty string if not available.
 * Exists only on US Green Cards. To see which document was scanned use documentType property.
 */
@property (nonatomic, readonly, nullable) NSString *immigrantCaseNumber;

/**
 * The entire Machine Readable Zone text from ID. This text is usually used for parsing
 * other elements.
 */
@property (nonatomic, readonly, nullable) NSString *mrzText;

/**
 * YES if all check digits inside MRZ are correct, NO otherwise.
 * More specifically, YES if MRZ complies with ICAO Document 9303 standard, NO otherwise.
 */
@property (nonatomic, readonly) BOOL mrtdVerified;

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

@end
