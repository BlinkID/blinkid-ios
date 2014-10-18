//
//  PPUSDLScanningResult.h
//  BarcodeFramework
//
//  Created by Jura on 24/03/14.
//  Copyright (c) 2014 PhotoPay. All rights reserved.
//

#import "PPBaseResult.h"

#pragma mark - Keys for obtaining data on driver's licenses

#pragma mark - 1. Determining AAMVA Version

//==============================================================/
//=============== 1. DETERMINING AAMVA VERSION =================/
//==============================================================/

/**
 Mandatory on all AAMVA driver's license versions.
 
 Possible values "0", "1", "2", "3", "4", "5", "6", "7", "8", "Compact" and
 specifies the version level of the PDF417 bar code format.
 
 AAMVA Version Number: This is a value between "00" and "99" that
 specifies the version level of the PDF417 bar code format. Version "0" and "00"
 is reserved for bar codes printed to the specification of the American Association
 of Motor Vehicle Administrators (AAMVA) prior to the adoption of the AAMVA DL/ID-2000
 standard. All bar codes compliant with the AAMVA DL/ID-2000 standard are designated
 Version "01." All barcodes compliant with AAMVA Card Design Specification version
 1.0, dated 09-2003 shall be designated Version "02." All barcodes compliant with
 AAMVA Card Design Specification version 2.0, dated 03-2005 shall be designated
 Version "03." All barcodes compliant with AAMVA Card Design Standard version 1.0,
 dated 07-2009 shall be designated Version "04." All barcodes compliant with AAMVA
 Card Design Standard version 1.0, dated 07-2010 shall be designated Version "05."
 All barcodes compliant with AAMVA Card Design Standard version 1.0, dated 07- 2011
 shall be designated Version "06". All barcodes compliant with AAMVA Card Design
 Standard version 1.0, dated 06-2012 shall be designated Version "07". All barcodes
 compliant with this current AAMVA standard shall be designated "08". Should a need
 arise requiring major revision to the format, this field provides the means to
 accommodate additional revision. "Compact" when Compact encoding is used.
 */
extern const NSString* kPPAamvaVersionNumber;

#pragma mark - 2. Keys Existing on all barcode versions

//==============================================================/
//========= 2. KEYS EXISTING ON ALL BARCODE VERSIONS ===========/
//==============================================================/

#pragma mark - 2.1. Mandatory keys

/***************************************************************/
/*********************** MANDATORY KEYS ************************/
/***************************************************************/

#pragma mark - 2.1.1. Personal data

//======================= PERSONAL DATA ========================/

/**
 Mandatory on all barcode versions, including compact encoding.
 
 Family name of the cardholder. (Family name is sometimes also called "last name" or "surname.")
 Collect full name for record, print as many characters as possible on portrait side of DL/ID.
 */
extern const NSString* kPPCustomerFamilyName;

/**
 Mandatory on all barcode versions, including compact encoding.
 
 First name of the cardholder.
 */
extern const NSString* kPPCustomerFirstName;

/**
 Mandatory on all barcode versions, including compact encoding.
 
 Date on which the cardholder was born. (MMDDCCYY for U.S., CCYYMMDD for Canada)
 */
extern const NSString* kPPDateOfBirth;

/**
 Mandatory on all barcode versions, including compact encoding.
 
 Gender of the cardholder. 1 = male, 2 = female.
 */
extern const NSString* kPPSex;

/**
 Mandatory on AAMVA 01, 02, 03, 04, 05, 06, 07, 08 and Compact encoding
 
 Mandatory on all barcode versions, including compact encoding. (ANSI D-20 codes)
 
 Code   Description
 BLK    Black
 BLU    Blue
 BRO    Brown
 GRY    Gray
 GRN    Green
 HAZ    Hazel
 MAR    Maroon 
 PNK    Pink
 DIC    Dichromatic 
 UNK    Unknown
 */
extern const NSString* kPPEyeColor;

/**
 Mandatory on AAMVA 02, 03, 04, 05, 06, 07, 08 and Compact encoding. Optional on 01.
 
 See also kPPHeightIn, kPPHeightCm
 
 Height of cardholder.
 
 Inches (in): number of inches followed by " in" or " IN". Example. 6'1'' = "073 in"
 
 Centimeters (cm): number of centimeters followed by " cm" or " CM". Example. 181 centimeters = "181 cm"
 */
extern const NSString* kPPHeight;

/**
 Mandatory on all standard barcode versions. Not defined on Compact encoding, where you must use `kPPFullAddress`.
 
 Street portion of the cardholder address.
 The place where the registered driver of a vehicle (individual or corporation) may be contacted such as a house number, street address etc.
 */
extern const NSString* kPPAddressStreet;

/**
 Mandatory on all standard barcode versions. Not defined on Compact encoding, where you must use `kPPFullAddress`.
 
 City portion of the cardholder address.
 */
extern const NSString* kPPAddressCity;

/**
 Mandatory on all standard barcode versions. Not defined on Compact encoding, where you must use `kPPFullAddress`.
 
 State portion of the cardholder address.
 */
extern const NSString* kPPAddressJurisdictionCode;

/**
 Mandatory on all standard barcode versions. Not defined on Compact encoding, where you must use `kPPFullAddress`.
 
 Postal code portion of the cardholder address in the U.S. and Canada. If the
 trailing portion of the postal code in the U.S. is not known, zeros will be used
 to fill the trailing set of numbers up to nine (9) digits.
 */
extern const NSString* kPPAddressPostalCode;

#pragma mark - 2.1.2. License data

//======================== LICENSE DATA ========================/

/**
 Mandatory on all barcode versions, including compact encoding.
 
 Date on which the document was issued. (MMDDCCYY for U.S.,
 CCYYMMDD for Canada)
 */
extern const NSString* kPPDocumentIssueDate;

/**
 Mandatory on all barcode versions, including compact encoding.
 
 Date on which the driving and identification privileges granted by the document are
 no longer valid. (MMDDCCYY for U.S., CCYYMMDD for Canada)
 */
extern const NSString* kPPDocumentExpirationDate;

/**
 Mandatory on all standard barcode formats, optional on compact encoding.
 
 This number uniquely identifies the issuing jurisdiction and can
 be obtained by contacting the ISO Issuing Authority (AAMVA)
 */
extern const NSString* kPPIssuerIdentificationNumber;


/**
 Mandatory on all barcode versions, including compact encoding.
 
 Jurisdiction Version Number: This is a decimal value between 00 and 99 that
 specifies the jurisdiction version level of the PDF417 bar code format.
 Notwithstanding iterations of this standard, jurisdictions implement incremental
 changes to their bar codes, including new jurisdiction-specific data, compression
 algorithms for digitized images, digital signatures, or new truncation
 conventions used for names and addresses. Each change to the bar code format
 within each AAMVA version (above) must be noted, beginning with Jurisdiction
 Version 00.
 */
extern const NSString* kPPJurisdictionVersionNumber;

/**
 Mandatory on all standard barcode versions. Not defined on Compact encoding, which has no compatible field.
 
 Jurisdiction-specific vehicle class / group code, designating the type
 of vehicle the cardholder has privilege to drive.
 */
extern const NSString* kPPJurisdictionVehicleClass;

/**
 Mandatory on all standard barcode versions. Not defined on Compact encoding, which has no compatible field.
 
 Jurisdiction-specific codes that represent restrictions to driving
 privileges (such as airbrakes, automatic transmission, daylight only, etc.).
 */
extern const NSString* kPPJurisdictionRestrictionCodes;

/**
 Mandatory on all standard barcode versions. Not defined on Compact encoding, which has no compatible field.
 
 Jurisdiction-specific codes that represent additional privileges
 granted to the cardholder beyond the vehicle class (such as transportation of
 passengers, hazardous materials, operation of motorcycles, etc.).
 */
extern const NSString* kPPJurisdictionEndorsementCodes;

/**
 Mandatory on all barcode versions, including compact encoding.
 
 The number assigned or calculated by the issuing authority.
 */
extern const NSString* kPPCustomerIdNumber;

#pragma mark - 2.2. Optional keys

/***************************************************************/
/*********************** OPTIONAL KEYS *************************/
/***************************************************************/

#pragma mark - 2.2.1. Personal data

//======================= PERSONAL DATA ========================/

/**
 Optional on all barcode versions, including compact encoding.
 
 Bald, black, blonde, brown, gray, red/auburn, sandy, white, unknown. If the issuing
 jurisdiction wishes to abbreviate colors, the three-character codes provided in ANSI D20 must be
 used.
 
 Code   Description
 BAL    Bald
 BLK    Black
 BLN    Blond
 BRO    Brown
 GRY    Grey
 RED    Red/Auburn 
 SDY    Sandy
 WHI    White 
 UNK    Unknown
 */
extern const NSString* kPPHairColor;

/**
 Optional on all barcode versions, including compact encoding.
 
 ame Suffix (If jurisdiction participates in systems requiring name suffix (PDPS, CDLIS, etc.), the suffix must be collected and displayed on the DL/ID).
 - JR (Junior)
 - SR (Senior)
 - 1ST or I (First)
 - 2ND or II (Second)
 - 3RD or III (Third)
 - 4TH or IV (Fourth)
 - 5TH or V (Fifth)
 - 6TH or VI (Sixth)
 - 7TH or VII (Seventh)
 - 8TH or VIII (Eighth)
 - 9TH or IX (Ninth).
 */
extern const NSString* kPPNameSuffix;

/**
 Optional on all standard barcode versions. Not defined on Compact encoding, where you must use `kPPFullAddress`.

 
 Second line of street portion of the cardholder address.
 */
extern const NSString* kPPAddressStreet2;

#pragma mark - 2.2.2. License data

//======================== LICENSE DATA ========================/

/**
 Optional on all barcode versions, mandatory on Compact Encoding
 
 Jurisdictions may define a subfile to contain jurisdiction-specific information.
 These subfiles are designated with the first character of “Z” and the second
 character is the first letter of the jurisdiction's name. For example, "ZC" would
 be the designator for a California or Colorado jurisdiction-defined subfile; "ZQ"
 would be the designator for a Quebec jurisdiction-defined subfile. In the case of
 a jurisdiction-defined subfile that has a first letter that could be more than
 one jurisdiction (e.g. California, Colorado, Connecticut) then other data, like
 the IIN or address, must be examined to determine the jurisdiction.
 */
extern const NSString* kPPIssuingJurisdiction;

/**
 Optional on all barcode versions, including compact encoding.
 
 Standard vehicle classification code(s) for cardholder. This data element is a
 placeholder for future efforts to standardize vehicle classifications.
 */
extern const NSString* kPPStandardVehicleClassification;

/**
 Optional on all standard barcode versions. Not defined on Compact encoding, which has no compatible field.
 
 Standard endorsement code(s) for cardholder. See codes in D20. This data element is a
 placeholder for future efforts to standardize endorsement codes.
 
 Code   Description
 H      Hazardous Material - This endorsement is required for the operation of any vehicle
 transporting hazardous materials requiring placarding, as defined by U.S.
 Department of Transportation regulations.
 L      Motorcycles – Including Mopeds/Motorized Bicycles.
 N      Tank - This endorsement is required for the operation of any vehicle transporting,
 as its primary cargo, any liquid or gaseous material within a tank attached to the vehicle.
 O      Other Jurisdiction Specific Endorsement(s) - This code indicates one or more
 additional jurisdiction assigned endorsements.
 P      Passenger - This endorsement is required for the operation of any vehicle used for
 transportation of sixteen or more occupants, including the driver.
 S      School Bus - This endorsement is required for the operation of a school bus. School bus means a
 CMV used to transport pre-primary, primary, or secondary school students from home to school,
 from school to home, or to and from school sponsored events. School bus does not include a
 bus used as common carrier (49 CRF 383.5).
 T      Doubles/Triples - This endorsement is required for the operation of any vehicle that would be
 referred to as a double or triple.
 X      Combined Tank/HAZ-MAT - This endorsement may be issued to any driver who qualifies for
 both the N and H endorsements.
 */
extern const NSString* kPPStandardEndorsementCode;

/**
 Optional on all standard barcode versions. Not defined on Compact encoding, which has no compatible field.
 
 Standard restriction code(s) for cardholder. See codes in D20. This data element is a placeholder
 for future efforts to standardize restriction codes.
 
 Code   Description
 B      Corrective Lenses
 C      Mechanical Devices (Special Brakes, Hand Controls, or Other Adaptive Devices)
 D      Prosthetic Aid
 E      Automatic Transmission
 F      Outside Mirror
 G      Limit to Daylight Only
 H      Limit to Employment
 I      Limited Other
 J      Other
 K      CDL Intrastate Only
 L      Vehicles without air brakes
 M      Except Class A bus
 N      Except Class A and Class B bus
 O      Except Tractor-Trailer
 V      Medical Variance Documentation Required
 W      Farm Waiver
 */
extern const NSString* kPPStandardRestrictionCode;

#pragma mark - 3. Keys existing on some barcode versions

//==============================================================/
//========== 3. KEYS EXISTING ON SOME BARCODE VERSIONS =========/
//==============================================================/

#pragma mark - 3.1. Mandatory keys

/***************************************************************/
/*********************** MANDATORY KEYS ************************/
/***************************************************************/

#pragma mark - 3.1.1. Personal data

//======================= PERSONAL DATA ========================/

/**
 Mandatory on AAMVA version 04, 05, 06, 07, 08, optional on 01. On other standards middle 
 name is included into value of kPPFirstName.
 
 Middle name(s) of the cardholder. In the case of multiple middle names they
 shall be separated by a comma ",".
 */
extern const NSString* kPPCustomerMiddleName;

/**
 Optional on 01.
 
 See also kPPHeight, kPPHeightCm
 
 Height of cardholder. (FT/IN)
 
 FEET (1st char); Inches (2nd and 3rd char).
 Ex. 509 = 5 ft., 9 in.
 */
extern const NSString* kPPHeightIn;

/**
 Optional on 01.
 
 See also kPPHeight, kPPHeightIn
 
 Height of cardholder in CENTIMETERS
 */
extern const NSString* kPPHeightCm;

/**
 Mandatory on AAMVA 01
 
 NAME of the individual holding the Driver License or ID as defined in
 ANSI D20 Data Dictionary. (Lastname,Firstname,MI, suffix if any)
 
 This field contains four portions, separated with the "," delimiter: Last Name (required)
 , (required)
 First Name (required)
 , (required if other name portions follow, otherwise optional)
 Middle Name(s) (optional)
 , (required if other name portions follow, otherwise optional)
 Suffix Code (optional)
 , (optional)
 */
extern const NSString* kPPCustomerFullName;

/**
 Mandatory on compact encoding.
 
 Cardholder address.
 */
extern const NSString* kPPFullAddress;

/**
 Mandatory on AAMVA 04, 05, 06, 07, 08 and Compact Encoding
 
 A code that indicates whether a field has been truncated (T), has not been
 truncated (N), or – unknown whether truncated (U).
 */
extern const NSString* kPPFamilyNameTruncation;

/**
 Mandatory on AAMVA 04, 05, 06, 07, 08 and Compact Encoding
 
 A code that indicates whether a field has been truncated (T), has not been
 truncated (N), or – unknown whether truncated (U).
 */
extern const NSString* kPPFirstNameTruncation;

/**
 Mandatory on AAMVA 04, 05, 06, 07, 08
 
 A code that indicates whether a field has been truncated (T), has not been
 truncated (N), or – unknown whether truncated (U).
 */
extern const NSString* kPPMiddleNameTruncation;

#pragma mark - 3.1.2. License data

//======================== LICENSE DATA ========================/

/**
 Mandatory on AAMVA 02, 03, 04, 05, 06, 07, 08 and Compact Encoding
 
 Country in which DL/ID is issued. U.S. = USA, Canada = CAN.
 */
extern const NSString* kPPCountryIdentification;

/**
 Mandatory on AAMVA 02, 03, 04, 05, 06, 07, 08 and Compact Encoding
 
 Number must uniquely identify a particular document issued to that customer
 from others that may have been issued in the past. This number may serve multiple
 purposes of document discrimination, audit information number, and/or inventory control.
 */
extern const NSString* kPPDocumentDiscriminator;

/**
 Mandatory on AAMVA versions 02 and 03.
 
 Federally established codes for vehicle categories, endorsements, and restrictions
 that are generally applicable to commercial motor vehicles. If the vehicle is not a
 commercial vehicle, "NONE" is to be entered.
 */
extern const NSString* kPPFederalCommercialVehicleCodes;

#pragma mark - 3.2. Optional keys

/***************************************************************/
/*********************** OPTIONAL KEYS *************************/
/***************************************************************/

#pragma mark - 3.2.1. Personal data

//======================= PERSONAL DATA ========================/

/**
 Optional on AAMVA 02, 03, 04, 05, 06, 07, 08 and Compact Encoding
 
 Codes for race or ethnicity of the cardholder, as defined in ANSI D20.
 
 Race:
 Code   Description
 AI     Alaskan or American Indian (Having Origins in Any of The Original Peoples of
 North America, and Maintaining Cultural Identification Through Tribal
 Affiliation of Community Recognition)
 AP     Asian or Pacific Islander (Having Origins in Any of the Original Peoples of
 the Far East, Southeast Asia, or Pacific Islands. This Includes China, India,
 Japan, Korea, the Philippines Islands, and Samoa)
 BK     Black (Having Origins in Any of the Black Racial Groups of Africa)
 W      White (Having Origins in Any of The Original Peoples of Europe, North Africa,
 or the Middle East)
 
 Ethnicity:
 Code   Description
 H      Hispanic Origin (A Person of Mexican, Puerto Rican, Cuban, Central or South
 American or Other Spanish Culture or Origin, Regardless of Race)
 O      Not of Hispanic Origin (Any Person Other Than Hispanic) 
 U      Unknown
 */
extern const NSString* kPPRaceEthnicity;

/**
 Optional on AAMVA 02, 03, 04, 05, 06, 07, 08 and Compact Encoding
 
 Country and municipality and/or state/province
 */
extern const NSString* kPPPlaceOfBirth;

/**
 Optional on AAMVA 02, 03, 04, 05, 06, 07, 08
 
 Indicates the approximate weight range of the cardholder:
 0 = up to 31 kg (up to 70 lbs)
 1 = 32 – 45 kg (71 – 100 lbs)
 2 = 46 - 59 kg (101 – 130 lbs)
 3 = 60 - 70 kg (131 – 160 lbs)
 4 = 71 - 86 kg (161 – 190 lbs)
 5 = 87 - 100 kg (191 – 220 lbs)
 6 = 101 - 113 kg (221 – 250 lbs)
 7 = 114 - 127 kg (251 – 280 lbs)
 8 = 128 – 145 kg (281 – 320 lbs)
 9 = 146+ kg (321+ lbs)
 */
extern const NSString* kPPWeightRange;

/**
 Optional on AAMVA 01, 04, 05, 06, 07, 08
 
 Cardholder weight in pounds Ex. 185 lb = "185"
 */
extern const NSString* kPPWeightPounds;

/**
 Optional on AAMVA 01, 04, 05, 06, 07, 08 and Compact Encoding
 
 Cardholder weight in kilograms Ex. 84 kg = "084"
 */
extern const NSString* kPPWeightKilograms;

/**
 Optional on AAMVA 01
 
 PREFIX to Driver Name. Freeform as defined by issuing jurisdiction.
 */
extern const NSString* kPPNamePrefix;

/**
 Optional on AAMVA version 01.
 
 Driver Residence Street Address 1.
 */
extern const NSString* kPPResidenceStreetAddress;

/**
 Optional on AAMVA version 01.
 
 Driver Residence Street Address 2.
 */
extern const NSString* kPPResidenceStreetAddress2;

/**
 Optional on AAMVA version 01.
 
 Driver Residence City
 */
extern const NSString* kPPResidenceCity;

/**
 Optional on AAMVA version 01.
 
 Driver Residence Jurisdiction Code.
 */
extern const NSString* kPPResidenceJurisdictionCode;

/**
 Optional on AAMVA version 01.
 
 Driver Residence Postal Code.
 */
extern const NSString* kPPResidencePostalCode;

/**
 Optional on AAMVA 05, 06, 07, 08
 
 Date on which the cardholder turns 18 years old. (MMDDCCYY for U.S., CCYYMMDD for Canada)
 */
extern const NSString* kPPUnder18;

/**
 Optional on AAMVA 05, 06, 07, 08
 
 Date on which the cardholder turns 19 years old. (MMDDCCYY for U.S., CCYYMMDD for Canada)
 */
extern const NSString* kPPUnder19;

/**
 Optional on AAMVA 05, 06, 07, 08
 
 Date on which the cardholder turns 21 years old. (MMDDCCYY for U.S., CCYYMMDD for Canada)
 */
extern const NSString* kPPUnder21;

/**
 Optional on AAMVA version 01.
 
 The number assigned to an individual by the Social Security Administration.
 */
extern const NSString* kPPSocialSecurityNumber;

/**
 Optional on AAMVA version 01.
 
 Driver "AKA" Social Security Number. FORMAT SAME AS DRIVER SOC SEC NUM. ALTERNATIVE NUMBERS(S) used as SS NUM.
 */
extern const NSString* kPPAKASocialSecurityNumber;

/*
 Optional on AAMVA version 01, 02
 
 Other name by which cardholder is known. ALTERNATIVE NAME(S) of the individual holding
 the Driver License or ID. FORMAT same as defined in ANSI D20 Data Dictionary.
 (Lastname,Firstname,MI, suffix if any.)
 
 The Name field contains four portions, separated with the "," delimiter: Last Name (required)
 , (required)
 First Name (required)
 , (required if other name portions follow, otherwise optional)
 Middle Name(s) (optional)
 , (required if other name portions follow, otherwise optional)
 Suffix Code (optional)
 , (optional)
 */
extern const NSString* kPPAKAFullName;

/**
 Optional on AAMVA 01, 03, 04, 05, 06, 07, 08 and Compact Encoding
 
 Other family name by which cardholder is known.
 */
extern const NSString* kPPAKAFamilyName;

/**
 Optional on AAMVA 01
 
 ALTERNATIVE MIDDLE NAME(s) or INITIALS of the individual holding the Driver License or ID.
 Hyphenated names acceptable, spaces between names acceptable, but no other
 use of special symbols
 */
extern const NSString* kPPAKAMiddleName;

/**
 Optional on AAMVA 01, 03, 04, 05, 06, 07, 08 and Compact Encoding
 
 Other given name by which cardholder is known
 */
extern const NSString* kPPAKAGivenName;

/**
 Optional on AAMVA 01
 
 ALTERNATIVE PREFIX to Driver Name. Freeform as defined by issuing jurisdiction.
 */
extern const NSString* kPPAKAPrefixName;

/**
 Optional on AAMVA 01, 03, 04, 05, 06, 07, 08 and Compact Encoding
 
 Other suffix by which cardholder is known.
 
 The Suffix Code Portion, if submitted, can contain only the Suffix Codes shown in the following table (e.g., Andrew Johnson, III = JOHNSON@ANDREW@@3RD):
 
 Suffix     Meaning or Synonym
 JR         Junior
 SR         Senior or Esquire 1ST First
 2ND        Second
 3RD        Third
 4TH        Fourth
 5TH        Fifth
 6TH        Sixth
 7TH        Seventh
 8TH        Eighth
 9TH        Ninth
 */
extern const NSString* kPPAKASuffixName;

/**
 Optional on AAMVA 06, 07, 08
 
 Field that indicates that the cardholder is an organ donor = "1".
 */
extern const NSString* kPPOrganDonor;

/**
 Optional on AAMVA 07, 08
 
 Field that indicates that the cardholder is a veteran = "1"
 */
extern const NSString* kPPVeteran;

/**
 Optional on AAMVA 01
 
 ALTERNATIVE DATES(S) given as date of birth.
 */
extern const NSString* kPPAKADateOfBirth;


/**
 Optional on compact encoding.
 
 Portrait image timestamp
 */
extern const NSString* kPPImageTimestamp;

/**
 Optional on compact encoding.
 
 Type of image
 */
extern const NSString* kPPImageType;

/**
 Optional on compact encoding.
 
 Portrait image
 */
extern const NSString* kPPPortraitImage;

/**
 Optional on compact encodings.
 
 BDB format owner
 */
extern const NSString* kPPBDBFormatOwner;

/**
 Optional on compact encodings.
 
 BDB format type
 */
extern const NSString* kPPBDBFormatType;

/**
 Optional on compact encodings.
 
 Biometric data block length
 */
extern const NSString* kPPBiometricDataLength;

/**
 Optional on compact encodings.
 
 Biometric data block
 */
extern const NSString* kPPBiometricData;

#pragma mark - 3.2.2. License data

//======================== LICENSE DATA ========================/

/**
 Optional on AAMVA 02, 03, 04, 05, 06, 07, 08 and Compact Encoding
 
 Text that explains the jurisdiction-specific code(s) for classifications
 of vehicles cardholder is authorized to drive.
 */
extern const NSString* kPPJurisdictionVehicleClassificationDescription;

/**
 Optional on AAMVA 02, 03, 04, 05, 06, 07, 08 and Compact Encoding
 
 Text that explains the jurisdiction-specific code(s) that indicates additional
 driving privileges granted to the cardholder beyond the vehicle class.
 */
extern const NSString* kPPJurisdictionEndorsmentCodeDescription;

/**
 Optional on AAMVA 02, 03, 04, 05, 06, 07, 08 and Compact Encoding
 
 Text describing the jurisdiction-specific restriction code(s) that curtail driving privileges.
 */
extern const NSString* kPPJurisdictionRestrictionCodeDescription;

/**
 Optional on AAMVA 02, 03, 04, 05, 06, 07, 08
 
 A string of letters and/or numbers that is affixed to the raw materials (card stock,
 laminate, etc.) used in producing driver licenses and ID cards. (DHS recommended field)
 */
extern const NSString* kPPInventoryControlNumber;

/**
 Optional on AAMVA 04, 05, 06, 07, 08 and Compact Encoding
 
 DHS required field that indicates date of the most recent version change or
 modification to the visible format of the DL/ID (MMDDCCYY for U.S., CCYYMMDD for Canada)
 */
extern const NSString* kPPCardRevisionDate;

/**
 Optional on AAMVA 04, 05, 06, 07, 08 and Compact Encoding
 
 DHS required field that indicates that the cardholder has temporary lawful status = "1".
 */
extern const NSString* kPPLimitedDurationDocument;

/**
 Optional on AAMVA version 01.
 
 Issue Timestamp. A string used by some jurisdictions to validate the document against their data base.
 */
extern const NSString* kPPIssueTimestamp;

/**
 Optional on AAMVA version 01.
 
 Driver Permit Expiration Date. CCYYMMDD; Date permit expires.
 */
extern const NSString* kPPPermitExpirationDate;

/**
 Optional on AAMVA version 01.
 
 Type of permit.
 */
extern const NSString* kPPPermitIdentifier;

/**
 Optional on AAMVA version 01.
 
 Driver Permit Issue Date. CCYYMMDD; Date permit was issued.
 */
extern const NSString* kPPPermitIssueDate;

/**
 Optional on AAMVA version 01.
 
 Number of duplicate cards issued for a license or ID if any.
 */
extern const NSString* kPPNumberOfDuplicates;

/**
 Optional on AAMVA 02, 03, 04, 05, 06, 07, 08 and Compact Encoding
 
 A string of letters and/or numbers that identifies when, where, and by whom a driver
 license/ID card was made. If audit information is not used on the card or the MRT, it
 must be included in the driver record.
 */
extern const NSString* kPPAuditInformation;

/**
 Optional on AAMVA 04, 05, 06, 07, 08 and Compact Encoding
 
 DHS required field that indicates compliance: "M" = materially compliant;
 "F" = fully compliant; and, "N" = non-compliant.
 */
extern const NSString* kPPComplianceType;

/**
 Optional on AAMVA 04, 05, 06, 07, 08 and Compact Encoding
 
 Date on which the hazardous material endorsement granted by the document is
 no longer valid. (MMDDCCYY for U.S., CCYYMMDD for Canada)
 */
extern const NSString* kPPHAZMATExpirationDate;

/**
 Optional on AAMVA version 01.
 
 Medical Indicator/Codes.
 STATE SPECIFIC. Freeform; Standard "TBD"
 */
extern const NSString* kPPMedicalIndicator;

/**
 Optional on AAMVA version 01.
 
 Non-Resident Indicator. "Y". Used by some jurisdictions to indicate holder of the document is a non-resident.
 */
extern const NSString* kPPNonResident;

/**
 Optional on AAMVA version 01.
 
 A number or alphanumeric string used by some jurisdictions to identify a "customer" across multiple data bases.
 */
extern const NSString* kPPUniqueCustomerId;

/**
 Optional on compact encoding.
 
 Document discriminator.
 */
extern const NSString* kPPDataDiscriminator;

#pragma mark - 4. Keys for accessing raw barcode results

//==============================================================/
//====== 4. KEYS FOR ACCESSING RAW BARCODE RESULTS =============/
//==============================================================/

/**
 Raw pdf417 result 
 */
extern const NSString* kPPPdf417;

/**
 Raw code128 result
 */
extern const NSString* kPPCode128;

/**
 Raw code39 result
 */
extern const NSString* kPPCode39;

#pragma mark - PPUSDLScanningResult implementation

@interface PPUSDLResult : PPBaseResult

/**
 USDL fields
 */
@property (nonatomic, strong) NSDictionary* fields;

/**
 Designated initializer
 */
- (id)initWithFields:(NSDictionary*)fields;

/**
 Dictionary with all keys mapped to internal string values 
 
 For internal use only.
 */
+ (NSDictionary*)allKeys;

@end
