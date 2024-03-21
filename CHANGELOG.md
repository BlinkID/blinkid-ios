# Release notes

## 6.6.0

### What’s new:
- Data extraction improvements:
  - Added `Sponsor` and `BloodType` result fields to `BlinkIdMultiSideRecognizerResult`, `BlinkIdSingleSideRecognizerResult` and `VizResult`

- Upgraded to `YUV` Color Format:
  - We’ve upgraded our imaging to support the `YUV` color format (`kCVPixelFormatType_420YpCbCr8BiPlanarFullRange`), making it the default encoding scheme. 

#### Accessibility changes:
- Optimized Color Contrast by fine-tuning color contrasts across the app, enhancing readability for all users.
- Blurred content and translucent areas have been made mostly opaque, simplifying the UI and making it easier to navigate.
- A new icon for harsh light conditions has been added to the onboarding screen, aiding in better navigation and usability.

#### Deprecated functionality:
- `IdBarcodeRecognizer` is now marked as deprecated. We recommend transitioning to `BlinkIdMultiSideRecognizer`, which not only covers the functionality of `IdBarcodeRecognizer` but also offers additional features.

### Added support for 7 new documents:
- Australia - Polycarbonate Passport
- Indonesia - Polycarbonate Passport
- Mexico - Consular Voter ID
- Moldova - Polycarbonate Passport
- Pakistan - Proof Of Registration
- Panama - Polycarbonate Passport
- USA - West Virginia - ID Card

### Added support for 10 new documents in BETA:
- Brazil - Ceara - ID Card
- Brazil - Goias - ID Card
- Brazil - Sergipe - ID Card
- China - Exit Entry Permit
- China - Mainland Travel Permit Taiwan
- Colombia - Temporary Protection Permit
- India - DL
- India - Andhra Pradesh - DL
- India - Haryana - DL
- European Union - Health Insurance Card

### Added new version support for 37 already supported documents
- Australia - Queensland - DL
- Australia - Victoria - DL
- Australia - Western Australia - DL
- Bolivia - Minor's ID
- Brazil - Alien ID
- Estonia - DL
- Finland - Alien ID
- Guatemala - Paper Passport
- India - Paper Passport - New side type
- Malta - DL
- Mexico - Guanajuato - DL 
- Mexico - San Luis Potosi - DL
- New Zealand - Polycarbonate Passport
- Paraguay - ID Card
- Slovenia - Residence Permit
- USA - Green Card
- USA - Work Permit
- USA - Arizona - ID Card
- USA - Colorado - DL
- USA - Colorado - ID Card
- USA - District of Columbia - DL
- USA - District of Columbia - ID Card
- USA - Idaho - DL
- USA - Idaho - ID Card
- USA - Missouri - ID Card
- USA - Nebraska - ID Card
- USA - Nevada - ID Card
- USA - New York - ID Card
- USA - North Dakota - DL
- USA - Oklahoma - ID Card
- USA - Pennsylvania - ID Card
- USA - Utah - ID Card
- USA - Virginia - DL
- USA - Virginia - ID Card
- USA - West Virginia - DL
- USA - Wisconsin - DL
- USA - Wisconsin - ID Card

### Added new version support for 7 already supported documents in BETA:
- Australia - Queensland - Proof of Age Card
- Brazil - ID Card
- Ireland - Residence Permit
- Mexico - Consular ID
- Mexico - Residence Permit
- Mexico - Nayarit - DL
- USA - North Dakota - ID Card

### These documents are no longer BETA:
- Croatia - Residence Permit
- Moldova - Paper Passport

### Changes to the `BlinkIdSingleSideRecognizer` and `BlinkIdMultiSideRecognizer`:
- Expanded geographic support with new `Region` enum values:
  - `ANDHRA_PRADESH`
  - `CEARA`
  - `GOIAS`
  - `GUERRERO_ACAPULCO_DE_JUAREZ`
  - `HARYANA`
  - `SERGIPE`   

- Document recognition enhanced with new `Type` enum values:
  - `EXIT_ENTRY_PERMIT`
  - `MAINLAND_TRAVEL_PERMIT_TAIWAN`
  - `NBI_CLEARANCE`
  - `PROOF_OF_REGISTRATION`
  - `TEMPORARY_PROTECTION_PERMIT`

## 6.5.1

- Improved scanning of Bolivia IDs by addressing cases where the expiration date is covered by a signature, allowing the completion of the scanning process.

## 6.5.0

- Improved the document side detection for US driver licenses which reduces the possibility of capturing the wrong side of the document. Barcode is now mandatory for the document back side of the US driving licenses

## 6.4.0

### New features

- Added new result member `cardRotation` to `ImageAnalysisResult`
- New `CardOrientation` status - `NotAvailable`

- New `Region` enum values:
    - `DISTRITO_FEDERAL`
    - `MARANHAO`
    - `MATO_GROSSO`
    - `MINAS_GERAIS`
    - `PARA`
    - `PARANA`
    - `PERNAMBUCO`
    - `SANTA_CATARINA`
- New `Type` enum values:
    - `CONSULAR_VOTER_ID`
    - `TWIC_CARD`
    
### Bug Fixes

- Fixed the issue where the wrong missing field message was shown when the mandatory field was missing
- Minor bugfixes and improvements

### Added support for 8 new documents

- Bolivia - Paper Passport
- Brazil - Alien ID
- Brazil - Distrito Federal - Identity Card
- Brazil - Minas Gerais - Identity Card
- Cameroon - Polycarbonate Passport
- Costa Rica - Paper Passport
- UK - Proof of Age Card
- USA - Twic Card

### Added support for 14 new versions of already supported documents

- Brazil - Driver’s License
- Luxembourg - Identity Card
- North Macedonia - Identity Card
- Portugal - Driver’s License
- Slovakia - Identity Card
- Switzerland - Identity Card
- Switzerland - Driver’s License
- Turkey - Polycarbonate Passport
- Ukraine - Driver’s License
- USA - Arizona - Driver’s License
- USA - Arizona - Identity Card
- USA - Nebraska - Driver’s License
- USA - Pennsylvania - Identity Card
- USA - Virginia - Driver’s License

### Added support for 17 new documents in BETA

- Australia - Australian Capital Territory - Identity Card
- Australia - Queensland - Proof of Age Card
- Australia - Tasmania - Identity Card
- Australia - Western Australia - Identity Card
- Bahrain - Driver’s License
- Bahrain - Paper Passport
- Brazil - Maranhao - Identity Card
- Brazil - Mato Grosso - Identity Card
- Brazil - Para - Identity Card
- Brazil - Parana - Identity Card
- Brazil - Pernambuco - Identity Card
- Brazil - Santa Catarina - Identity Card
- Cameroon - Paper Passport
- Mexico - Quintana Roo, Benito Juarez - Driver’s License
- Mexico - Quintana Roo -Driver’s License
- Switzerland - Polycarbonate Passport
- UAE - Polycarbonate Passport

### Added support for 2 new versions of already supported documents in BETA

- Iceland - Paper Passport
- Mexico - Consular ID

## 6.3.0

### New features

- Changes to`StringResult`:
  - new properties:
    - `location` - location coordinates of the first detected result, priority `latin`, `arabic`, `cyrillic`
    - `side` - document side of the first detected result, priority `latin`, `arabic`, `cyrillic`
  - new methods:
    - `location(AlphabetType)` - location coordinates of every non-empty result are available
    - `side (AlphabetType)` - document side of every non-empty result is available

- Changes to `BlinkIdSingleSideRecognizerResult` and `BlinkIdMultiSideRecognizerResult`:
  - new properties:
    - `faceImageLocation`
    - `faceImageSide`

- added new items to enums:
  - Country:
    - SCHENGEN_AREA
  - Type:
    - IMMIGRANT_VISA

### Bugfixes
- Remove autofill on `Russian` passport `DateOfExpiry` when present on a document
- Improved scanning success rate and stability when using `BlinkIdMultiSideRecognizer`
- Fix crash with certain `RecognitionModeFilter` combinations
- Improve scanning experience with the new iPhone 15 Pro and iPhone 15 Pro Max devices

## 6.2.1

- Fixed the issue with reading the back side of the USA/Washington and USA/Vermont driving license documents.

## 6.2.0

### New features
- new and improved machine learning models for data extraction
- expanded support for arabic documents
- added isFilledByDomainKnowledge flag to Date and DateResult 
  - indicates that date is not extracted from image but filled based on our internal document knowledge
- added new setting additionalAnonymization 
  - enables custom anonymization for any field per country, region and type of document
- added new items to enums:
  - Region: 
    - NORTHWEST_TERRITORIES (added item to enum, no document support for NORTHWEST_TERRITORIES yet)
    - NUNAVUT (added item to enum, no document support for NUNAVUT yet)
    - PRINCE_EDWARD_ISLAND
  - Type:
    - ASYLUM_REQUEST
    - DRIVER_QUALIFICATION_CARD
    - PROVISIONAL_DL
    - REFUGEE_PASSPORT
    - SPECIAL_ID
    - UNIFORMED_SERVICES_ID
  - FieldType:
    - BloodType
    - Sponsor

### Added support for 9 new documents
- Belarus - ID Card
- Guyana - ID Card
- Jamaica - Paper Passport
- Myanmar - Paper Passport
- Palestine - Paper Passport
- Saint Kitts and Nevis - Driving License
- Syria - ID Card
- Trinidad and Tobago - Paper Passport
- USA - Uniformed Services ID Card

### Added support for 23 new documents in BETA
- Barbados - Driving License
- Belarus - Polycarbonate Passport
- Belarus - Residence Permit
- Belgium - Provisional Driving License
- Belgium - Special ID Card 
- Bulgaria - Alien ID Card
- Bulgaria - Residence Permit
- Canada - New Brunswick - ID Card
- Canada - Prince Edward Island - Driving License
- Estonia - Polycarbonate Passport
- Germany - Driver Qualification Card
- Guyana - Driving License
- Kuwait - Paper Passport
- Lebanon - Paper Passport
- Liechtenstein - Driving License 
- Malta - Paper Passport
- Malta - Polycarbonate Passport
- Moldova - Driving License
- Netherlands - Alien ID Card
- Oman - Paper Passport
- Peru - Alien ID Card
- Romania - Residence Permit
- UK - Asylum Request

### Added support for 28 new versions of already supported documents
- Canada - British Columbia - Public Services Card
- Canada - British Columbia - Driving License
- Cyprus - Residence Permit
- Denmark - Polycarbonate Passport
- Germany - ID Card
- Italy - ID Card
- Ireland - Passport Card
- Malta - ID Card
- Montenegro - ID Card
- Montenegro - Polycarbonate Passport
- North Macedonia - ID Card
- North Macedonia - Polycarbonate Passport
- Norway - Driving License
- Norway - Residence Permit
- Norway - Polycarbonate Passport
- Philippines - Driving License
- Sweden - Polycarbonate Refugee Passport
- Sweden - Social Security Card
- UAE - Resident ID Card
- UK - Proof of Age Card
- USA - Arkansas - ID Card
- USA - Colorado - ID Card
- USA - Idaho - ID Card
- USA - Illinois - ID Card
- USA - New York - Driving License
- USA - New York - ID card
- USA - Pennsylvania - Driving License
- USA - Washington - Driving License

### Added support for 3 new versions of already supported documents in BETA
- Denmark - Residence Permit
- Estonia - Residence Permit
- Latvia - Residence Permit

## 6.1.2

- Internal improvements

## 6.1.1

- Fix isExpired value in recognizer result

## 6.1.0
### New features
- new and improved machine learning models for data extraction
- further improved barcode scanning (parsing for non-standard US DLs)
- added anonymization for QR code on Dutch ID card
- anonymization of religion field on Malaysian documents

### Added support for 9 new documents:
- Australia - Victoria - Proof of Age Card
- Brazil - Rio de Janeiro - ID Card
- Liechtenstein - ID Card
- Luxembourg - Passport
- Mozambique - ID Card
- Norway - ID Card 
- Togo - ID Card
- USA - Wyoming - ID Card
- Zimbabwe - ID Card 

### Added support for 9 new documents in BETA:
- Barbados - ID Card 
- Belgium - Passport 
- Brazil - Rio Grande do Sul - ID Card 
- Ireland - Residence Permit 
- Japan - Residence Permit
- Lithuania - Residence Permit 
- Saint Lucia - ID Card 
- USA - New Hampshire - ID Card 
- USA - South Dakota - ID Card 

### Added support for 34 new versions of already supported documents: 
- Belgium - Resident ID Card
- Canada - Residence Permit
- Estonia - ID Card
- Finland - Alien ID Card
- Finland - ID Card
- Latvia - Alien ID Card
- Lithuania - ID Card 
- Luxembourg - ID Card
- Malta - Residence Permit
- Netherlands - ID Card
- Netherlands - Residence Permit 
- Poland - ID Card
- Sweden Residence Permit
- USA - Alabama - ID Card
- USA - Alaska - ID Card
- USA - Colorado - Driving License
- USA - Connecticut - ID Card
- USA - District of Colombia - Driving License
- USA - District of Colombia - ID Card
- USA - Iowa - ID Card
- USA - Kansas - ID Card
- USA - Louisiana - Driving License
- USA - Maine - Driving License
- USA - Maine - ID Card
- USA - Minnesota - ID Card
- USA - Mississippi - ID Card
- USA - Nevada - Driving License
- USA - New York - Driving License 
- USA - South Carolina - ID Card
- USA - South Dakota - Driving License 
- USA - Texas - ID Card 
- USA - Vermont - Driving License 
- USA - Washington - ID Card
- USA - Wisconsin - Driving License 

### Added support for 2 new versions of already supported documents in BETA:
- Poland - Residence Permit
- Portugal - Residence Permit

## 6.0.0
### New features:
#### Extracting ID data from Arabic and Cyrillic IDs
- When we say you can scan IDs across the globe, we really mean it. Our [list of supported](https://microblink.com/full-list-of-supported-identity-documents/) documents got richer now that we can scan IDs including Arabic and Cyrillic scripts. This fantastic new feature also covers multiscript IDs meaning that we extract data written in both Latin and Arabic data fields.

#### Better barcode scanning and data extraction

- We’ve improved scanning accuracy for all IDs that hold a PDF417 or other barcode types. This means that the error rate is now 20% lower, which brings even cleaner and more reliable data with every scan of an identity document. 

#### New user instructions that lead to successful scans
- More detailed instructions on how to scan identity documents, via an intro tutorial or tooltip during scanning, leading to improved success rates in ID scanning and data extraction.

#### In-depth error messaging for developers
- You asked, we listened! With v6, you’ll get more detailed error messages regarding end-user activity, to better understand if scans should be repeated or accepted.

#### Easier implementation
- Less code, less headaches! You can now implement basic Identity Document Scanning in a single line of code.


### What's new in the BlinkId(Combined) Recognizer?

- Renamed `BlinkIdRecognier` to **BlinkIdSingleSideRecognizer**
- Renamed `BlinkIdCombinedRecognizer` to **BlinkIdMultiSideRecognizer**
- We introduced new classes: `StringResult`, `DateResult`, and `Date` in order to support multiple alphabets. If a recognizer supports multiple alphabets, its result class (e.g., `BlinkIdMultiSideRecognizer.Result`) will return `StringResult` for results that previously returned `String`.
- Added new result properties of an `AdditionalProcessingInfo` type that provides information about `missingMandatoryFields`, `invalidCharacterFields`, and `extraPresentFields`
- Unified `DataMatchResult` and `DataMatchDetailedInfo` into a single structure `DataMatchResult` (removed `dataMatchDetailedInfo` result member)
- Added new result member `cardOrientation` to `ImageAnalysisResult` structure
- More info about transitioning to **BlinkID v6.0.0** can be found in [`Transition guide.md`](Transition guide.md) 

### Added support for 50 new versions of already supported documents:
- Mexico - Aguascalientes - Driving license
- Mexico - Baja California - Driving license 
- Mexico - Hidalgo - Driving license
- USA - Delaware - Driving license
- USA - Florida - ID card
- USA - Hawaii - Driving license
- USA - Kentucky - ID card
- USA - Maryland - ID card
- USA - Michigan - ID card
- USA - Mississippi - Driving license
- USA - Mississippi - ID card
- USA - Missouri - ID card
- USA - Ohio - ID card
- USA - Oklahoma - ID card
- USA - Rhode Island - Driving license 

### These documents are no longer BETA:
- Australia - New South Wales - ID card
- Australia - South Australia - Proof of Age Card 
- Belgium - Minors ID card
- Belgium - Passport
- Canada - Tribal ID card
- Canada - Weapon Permit
- Canada - British Columbia - Minors Public Services Card
- Ireland - Public Services Card
- Israel - ID card
- Ivory Coast - Driving License
- Lebanon - ID card
- Libya - Polycarbonate Passport 
- Mexico - Colima - Driving license
- Mexico - Michoacan - Driving license
- Mexico - Tamaulipas - Driving license 
- Mexico - Zacatecas - Driving license
- Myanmar - Driving license
- Panama - Temporary Residence Permit
- Slovenia - Residence Permit
- Trinidad and Tobago - Driving license
- USA - Passport
- USA - Maine - ID card

### Added support for 2 new ID types in BETA:
#### Latin America and the Caribbean
- Cuba - ID card
- Cayman Islands - Drivers License

### Already supported documents but now with option to enable extraction for new scripts
#### Arabic - 5 ID types
- Egypt - ID card
- Jordan - ID card
- UAE - ID card
- UAE - Passport
- UAE - Resident ID

#### Cyrillic - 10 ID types
- Bosnia and Herzegovina - ID card
- Bulgaria - Drivers License
- Bulgaria - ID card
- North Macedonia - Drivers License
- North Macedonia - ID card
- Serbia - ID card
- Ukraine - Drivers License
- Ukraine - ID card
- Ukraine - Residence Permit
- Ukraine - Temporary Residence Permit


## 5.20.1

- Fixed autofocus issues on iPhone 14 Pro and iPhone 14 Pro Max

## 5.20.0

### New feature:
- ML models with new architecture that result in further 8% decrease in error rate
​
### Support for 8 new document types:
#### Northern America
- USA - Polycarbonate Passport 
- USA - Nebraska - ID Card
- USA - New York - ID Card
- USA - Utah - ID Card
​
#### Latin America and the Caribbean
- Mexico - Polycarbonate Passport
- Brazil - Sao Paolo - ID Card
​
#### Europe 
- Austria - Residence Permit
​
#### Asia
- Philippines - ID Card
​
### Back side support added:
- Australia - South Australia - Driving license
​
### Added support for 29 new versions of already supported documents:
- Australia - Northern Territory - Proof of Age Card
- Belgium - Minors ID Card
- Belgium - Residence Permit
- Bolivia - ID Card
- Croatia - Residence Permit
- Cyprus - ID Card
- Czechia - ID card
- Czechia - Residence Permit
- Dominican Republic - Paper Passport
- Greece - Residence Permit
- Italy - Residence Permit
- Ivory Coast - Driving license
- Kuwait - Driving license
- Mexico - Jalisco - Driving license
- Mexico - Nuevo Leon - Driving license
- Peru - ID Card
- Poland - Driving license
- Slovenia - ID Card
- Sweden - ID Card
- Sweden - Polycarbonate Passport
- USA - Georgia - ID Card 
- USA - Iowa - ID Card
- USA - Kansas - Driving license
- USA - Maryland - ID Card
- USA - Nebraska - ID Card
- USA - New York - Driving license
- USA - New York - ID Card
- USA - Oklahoma - Driving license
- Vietnam - ID Card
​
### These documents are no longer BETA:
- Finland - Residence Permit
- Guatemala - Driving license
​
### Added support for 2 new ID types in BETA:
- Antigua and Barbuda - Driving license
- Mexico - Professional ID Card
​
### Changes to BlinkID(Combined) Recognizer
- ClassInfo:
    - Added to JSON serialization:
        - isoNumericCountryCode
        - isoAlpha2CountryCode
        - isoAlpha3CountryCode
​
- BarcodeData:
    - JSON serialization update: stringData member is now in base64 format
​
- Added new item to enums:
    - Region: 
        - Sao Paulo, when scanning Brazilian Driving licenses
​
- Fixed scanning for Argentina ID - there were confusions for Veteran ID, now we enabled successful extraction on Veteran ID as well

## 5.19.0
​
### What's new in the BlinkID(Combined) Recognizer?

### Support for atypical Vietnam passports
- Extract data from Vietnam Passports that have non-ICAO compliant MRZ fields. For example, when the filler arrow is facing the other way (>) instead of the standard way (<)
​
### Data anonymization
- We've added the option to not extract the religion field on all supported Malaysian documents (MyKad, MyKas, MyKid, MyPR, MyTentera)

### Setting up custom scanning overlay
- You will need to set the cameraFrame property of MBImage to `NO` when using still images (photos) for processing, or set cameraFrame to `YES` when using a video capture output.
- cameraFrame is set to 'YES' by default except when creating MBImage from UIImage when it is set to `NO`
​
### Bugfixes
- Resolved issues with RGB color overlay when extracting document image, which was present on some devices

## 5.18.0

### New feature:
- Updated machine learning models resulting in a 41% reduced error rate.
​
### Support for 16 new document types:
#### Northern America
- USA - Passport Card
- USA - District of Columbia - ID Card
- USA - Iowa - ID Card
- USA - Tennessee - ID Card
​
#### Latin America and the Caribbean
- Cuba - Paper Passport
- Dominican Republic - Paper Passport
- Panama - Residence Permit (front only)
- Peru - Paper Passport
​
#### Europe 
- Cyprus - Paper Passport
- Germany - Minors Passport
- UK - Proof of Age Card (front only)
- Ukraine - Residence Permit
- Ukraine - Temporary Residence Permit
​
#### The Middle East and Africa
- Qatar - Paper Passport
- UAE - Paper Passport
​
#### Oceania
- Australia - Northern Territory - Proof of Age Card
​
### Back side support added:
- Austria - ID Card
- Australia - South Australia - Driving license
- Australia - Tasmania - Driving license
- Canada - Quebec - Driving license
- Mexico - Quintana Roo Solidaridad - Driving license
- USA - Washington - Driving license
​
### Added support for 26 new versions of already supported documents:
- Afghanistan - ID Card
- Bahrain - ID Card
- Hungary - Residence Permit
- India - ID Card
- Mexico - Tabasco - Driving license
- New Zealand - Driving license (front only)
- The Philippines - Professional ID (front only)
- Slovakia - Residence Permit
- South Africa - ID Card
- Switzerland - Residence Permit
- UK - Driving license 
- USA - Colorado - Driving license 
- USA - Idaho - Driving license 
- USA - Kansas - ID Card 
- USA - Kentucky - Driving license 
- USA - Maine - Driving license 
- USA - Massachusetts - ID Card 
- USA - Nebraska - Driving license 
- USA - New Hampshire - Driving license 
- USA - New Jersey - ID Card 
- USA - New Mexico - ID Card 
- USA - North Carolina - ID Card 
- USA - Utah - Driving license 
- USA - Vermont Driving license 
- USA - West Virginia - Driving license 
​
### These documents are no longer BETA:
- Algeria - Paper Passport
- Slovakia - Residence Permit
- USA - Mississippi - ID Card
​
### Added support for 8 new ID types in BETA:
- Iceland - Paper Passport
- South Africa - ID Card (front only)
- Brazil - Consular Passport (beta)
- Quintana Roo Cozumel - Driving license 
- Canada - Social Security Card (front only)
- Canada - British Columbia - Minor Public Services Card
- USA - Maine - ID Card
- USA - North Dakota - ID Card
​
​
### Changes to BlinkID(Combined) Recognizer
- Added new enums:
	- Region: `QUINTANA_ROO_COZUMEL` 
	- Type: `CONSULAR_PASSPORT`, `MINORS_PASSPORT`, and `MINORS_PUBLIC_SERVICES_CARD` 

## 5.17.0
​
### Changes to BlinkID(Combined) Recognizer
- Introduced the expanded DataMatch functionality for the BlinkID with the new result member called `dataMatchDetailedInfo`
	- This result member will enable you to see for which field has been performed, or it did not, the DataMatch functionality. This is enabled for `dateOfBirth`, `documentNumber` and `dateOfExpiry`.
	- For example, if the date of expiry is scanned from the front and back side of the document and values do not match, this method will return DataMatchResult: Failed.
Result will be DataMatchResult: Success only if scanned values for all fields that are compared are the same. If data matching has not been performed, the result will be DataMatchResult: NotPerformed. This information is available for every of the three mentioned field values above.
​
- Fixed issues with scanning Argentina AlienID, where there were confusions with the regular ID. `ClassInfo` now correctly returns which ID type is present based on the barcode data.

## 5.16.1

### Fixes
- Bugfix for extracting data from the USA Minnesota DL barcode

## 5.16.0
### We've added new documents to our list of supported documents:

#### Europe
- Austria - ID Card (front only)
- Germany - ID Card

#### Latin America and the Caribbean
- Brazil - ID Card (beta)
- Colombia - ID Card (front only)
- Ecuador - ID Card

#### Mexico
- Baja California Sur - Driving Licence (beta)
- Ciudad De Mexico - Driving Licence (front only)
- Colima - Driving Licence (front only, beta)
- Michoacan - Driving Licence (beta)
- Nayarit - Driving Licence (beta)
- Quintana Roo Solidaridad - Driving Licence (front only)
- Tlaxcala - Driving Licence
- Veracruz - Driving Licence (beta)

#### Oceania
- Australia - Northern Territory (beta)

#### Asia
- Japan - My Number Card (front only)
- Singapore - Resident ID

#### Northern America
- USA - Missouri - ID Card
- USA - Nevada - Driving Licence
- USA - New York City - ID Card
- USA - Oklahoma - ID Card

#### Back side support added:
- Mexico - Chiapas - Driving License 

#### No longer BETA:
- Mexico - Baja California - Driving Licence
- Mexico - Chihuahua - Driving Licence
- Mexico - Coahuila - Driving Licence
- Mexico - Guanajuato - Driving Licence
- Mexico - Mexico - Driving Licence


### Changes to BlinkID(Combined) Recognizer

- Added the setting `saveCameraFrames` for saving camera frames with the default value being `false`.
	- New result members are also available here: `frontCameraFrame`, `backCameraFrame`, `barcodeCameraFrame`.
	- Memory consumption significantly increases if set to `true`.
- We've added new result members when scanning Australian Driving Licences: `vehicleClass`, `licenceType`, `effectiveDate` and `expiryDate`.
	- Result member are displayed under the `VehicleClassInfo` field; we can also extract data from multiple rows when this vehicle class info data is present on the document (e.g. multiple expiry dates for different vehicle classes).
- We've added new enum values:
	- Region: `QUINTANA_ROO`, `QUINTANA_ROO_SOLIDARIDAD`, `TLAXCALA` which are available when scanning Mexican Driving Licences.
	- Type: `MY_NUMBER_CARD` which is available when scanning Japanese My Number Card documents.
- We've added new result member `additionalOptionalAddressInformation` which gives additional address information about the document owner.
	- This result member can be present when scanning the Pakistani ID Card for the field `Country of Stay`.

### Removed recognizers
- We've removed recognizers: `GermanyDLBack Recognizer` and `SingaporeChangiEmployeeId Recognizer`.

	
#### Changes to IDBarcodeRecognizer
- For barcodes in countries: Argentina, Colombia, Nigeria, Panama, and South Africa, we now also extract data from the field `Sex` when it's populated with the character "X".

 
### Improvements
- We've added support for Brazil ID Card when the cardholder's face image is rotated for 90 degrees on the document.
	- We will return face image and document image + data from VIZ part present on the back side.
- BlinkIdCombinedRecognizer can return the full frame from the front side if `saveCameraFrames` is set to `true`, whereas before it returned the full frame only for the back side.

## 5.15.2

- Fixed exposure of `toSignedJson` method

## 5.15.1

### Visual identity update
- We’ve updated Microblink logo and colors

## 5.15.0

### Newly added versions of documents for already supported documents
We’ve added 24 new  documents to our list:

### Europe
- Belgium - Driving License (front only)
- Croatia - ID Card
- France - ID Card
- France - Residence Permit (beta)
- Spain - ID Card
- Switzerland - Residence Permit
- UK - Residence Permit

### Oceania
- Australia - Northern Territory - Driving License (front only, beta)

### Middle East and Africa
- UAE - ID Card
- UAE - Resident ID

### Northern America
- Honduras - ID Card (beta)
- USA - Colorado - ID Card 
- USA - Minnesota - Driving License
- USA - Nevada - Driving License
- USA - Oklahoma - Driving License
- USA - Wyoming - Driving License

### Changes to BlinkID(Combined) Recognizer

- No API changes

### Improvements
- `DataMatch` functionality is now enabled for single side documents (Passports)
	- Added a special case to support `DataMatch` for UAE ID Card and Resident ID Card documents for the field `personal_id_number`
- We can now extract `additional_personal_id_number` on Ecuador ID Card
- Improvements for reading NRIC number on Malaysian documents that have an asterisk (*) character present 
- Improved document detection and cropping of the document image
 
### Changes to USDLRecognizer
- No API Changes
- Fixed magneticStripeParser crashing
- Calling originalString on dates coming from USDLRecognizer will now return exact actual strings dates were parsed from instead of custom reformatted strings

### Changes to IDBarcodeRecognizer
- Added document type ArgentinaAlienID and parser for ArgentinaAlienID2012BarcodeParser

### Changes to MRTDRecognizer
- Added support for parsing Dominican Republic ID Card, Senegal ID Card and Ecuador ID Card
- Renamed MRTDDocTypeSmallIDPakistan to MRTDDocTypeSmallIDPakistanConsular
- Bugfixes for parsing:
	- Mexico Professional ID
	- Croatia Driving License

## 5.14.0
### Back side support added:
- Thailand - ID Card

### Changes to BlinkID(Combined) Recognizer
- Added new result members - `fathersName` and `mothersName` both in BlinkID and BlinkIDCombined Recognizers, as well as in VIZ result

### Improvements
- We can now extract `fathers_name` and `mothers_name` from Mexico Voter ID Card
- Australian Driving Licenses for New South Wales, Northern Territory, Queensland, Victoria and Western Australia now have the driver license unique card number field extracted as `document_additional_number`

### Changes to BarcodeRecognizer
- We’ve removed support for `aztec` and `dataMatrix` barcode formats from BarcodeRecognizer

### Changes to MRTDRecognizer
- Added `MRTD_TYPE_BORDER_CROSSING_CARD` to MRTD enum 

## 5.13.0
### New additions to our supported document list

We’ve added 61 new documents:

#### Europe
- Austria - Paper Passport
- Belarus - Paper Passport
- Belgium - Paper Passport (beta)
- Bulgaria - Paper Passport
- Estonia - Paper Passport
- France - Paper Passport (beta)
- Georgia - Paper Passport (beta)
- Germany - Paper Passport
- Greece - Paper Passport
- Hungary- Paper Passport
- Italy - Paper Passport (beta)
- Kosovo - Paper Passport
- Moldova - Paper Passport (beta)
- Poland - Paper Passport
- Portugal - Paper Passport
- Spain - Paper Passport
- Switzerland - Paper Passport
- UK - Paper Passport

#### Middle East and Africa
- Algeria - Paper Passport (beta)
- Egypt - Paper Passport (beta)
- Eswatini - Paper Passport
- Ghana - Paper Passport
- Iran - Paper Passport (beta)
- Iraq - Paper Passport (beta)
- Israel - Paper Passport (beta)
- Jordan - Paper Passport (beta)
- Kenya - Polycarbonate Passport
- Libya - Polycarbonate Passport (beta)
- Morocco - Paper Passport (beta)
- Nigeria - Paper Passport
- Nigeria - Polycarbonate Passport (beta)
- Qatar - ID Card (front only, beta)
- Saudi Arabia - Paper Passport
- Syria - Paper Passport
- Tanzania - ID Card (beta)
- Tanzania - Voter ID (front only, beta)
- Tunisia - Paper Passport
- Turkey - Paper Passport
- Zimbabwe - Paper Passport

#### Latin America and the Caribbean
- Argentina - Paper Passport
- Brazil - Paper Passport (beta)
- Guatemala - Paper Passport
- Haiti - Paper Passport
- Honduras - Paper Passport (beta)
- Mexico - Paper Passport (beta)
- Mexico - Nayarit - Driving Licence (beta)

#### Asia
- Bangladesh - Paper Passport
- China - Paper Passport (beta)
- India - Paper Passport
- Indonesia - Paper Passport
- Japan - Paper Passport
- Nepal - Paper Passport
- Pakistan - Paper Passport
- Philippines - Paper Passport
- South Korea - Paper Passport (beta)
- Sri Lanka - Paper Passport
- Uzbekistan - Paper Passport

#### Oceania
- Australia - Paper Passport

#### Northern America
- Canada - Paper Passport
- Canada - Weapon Permit (front only, beta)
- USA - Paper Passport (beta)

#### Back side support added:
- Greece - ID Card
- Burkina Faso - ID Card
- Democratic Republic of the Congo - Driving Licence
- Mexico - Veracruz - Driving Licence
- Canada - Citizenship Certificate

#### No longer BETA:
- Belarus - Driving Licence
- UK - Polycarbonate Passport
- Argentina - Alien ID
- Bahamas - Driving Licence
- Mexico - Durango - Driving Licence
- Venezuela - ID Card
- USA - Kansas - ID Card


### Changes to BlinkID(Combined) Recognizer
- We’ve renamed the Swaziland country to Eswatini in results and ClassInfo
- Improved result validation
    - `FieldIdentificationFailed` processing status is used to indicate if unexpected fields are present on the document. Those fields are then deleted from the result
- We are filling out COUNTRY and REGION fields in ClassInfo, without the field TYPE of document, when using BarcodeID mode for scanning documents where the Front side is not supported, and back side results are extracted from AAMVA compliant barcodes
    - This applies only if `ClassInfo` isn’t already prepopulated in some other way and when you’re not in `FullRecognition` mode

#### ImageCapture
- Added support for including or excluding groups of documents supported by the current license with the `captureModeFilter` setting
    - Scanning of documents with AAMVA compliant barcodes with BarcodeID mode
    - Scanning of all licensed documents in BlinkID FullRecognition mode


### Improvements
- We can now extract the date of birth from the document number on the South Korean identity card and from the personal identification number on the driving licence

### Anonymization
- We’ve added anonymization support for new documents:
    - Document number on Germany paper bio-data page Passport
    - Document number on South Korea Identity Card
    - Personal identification number on South Korea driving licence
    - Personal identification number on South Korea paper bio-data page Passport

### Fixes
- We've fixed the orientation of an image obtained via [captureHighResImage](http://blinkid.github.io/blinkid-ios/Protocols/MBRecognizerRunnerViewController.html#/c:objc(pl)MBRecognizerRunnerViewController(im)captureHighResImage:) 
- We've fixed minor UI/layout issues on phones with the notch

## 5.12.0
### We've added 15 new documents to our list of supported documents:

#### Europe
- North Macedonia - Polycarbonate Passport 

#### Middle East and Africa
- Botswana - ID Card
- Sudan - Polycarbonate Passport

#### Mexico
- Baja California Sur - Driving License (beta)
- Campeche - Driving License (beta)
- Colima - Driving License (beta)

#### Oceania
- Australia - Health Insurance Card (front only, beta)

#### Asia
- Azerbaijan - Polycarbonate Passport (beta)
- Tajikistan - Polycarbonate Passport (beta)

#### Northern America
- Canada - Citizenship Certificate (front only, beta)
- Canada - Ontario - Health Insurance Card (front only)
- Canada - Quebec - Health Insurance Card (front only, beta)
- USA - Military ID Card 
- USA - Rhode Island - ID Card
- USA - South Carolina - ID Card

#### Back side support added:
- Ireland - Passport Card
- Mexico - Puebla - Driving License 
- Singapore - S PASS 

#### No longer BETA:
- Finland - Polycarbonate Passport
- Ireland - Passport Card 
- Ireland - Polycarbonate Passport
- Kosovo - Driving License 
- Latvia - Polycarbonate Alien Passport
- Latvia - Polycarbonate Passport 
- Poland - Polycarbonate Passport 
- Cameroon - ID Card 
- Ghana - ID Card 
- Iraq - ID Card 
- Tanzania - Driving License
- Turkey - Polycarbonate Passport
- Uganda - Driving License
- Bolivia - Minors ID
- Chile - Driving License
- Ecuador - Driving License
- Haiti - Driving License
- India - Karnataka - Driving License
- India - Maharashtra - Driving License
- Pakistan - Punjab - Driving License
- USA - Global Entry Card
- USA - New Mexico - ID Card
- USA - Wisconsin - ID Card

### Changes to BlinkID(Combined) Recognizer

- We've added the parameter `maxAllowedMismatchesPerField` to settings. When this is set to a non-zero value, DataMatch will be successful as long as the number of mismatched characters doesn't exceed the specified value.
- We've added the parameter `allowUncertainFrontSideScan` to settings. When this parameter is set to true, the Recognizer will proceed scanning the back side of the document even if the front side scanning result `State` is `Uncertain`.
- We've enabled the return of image and back side data results, even when the `State` is `Uncertain`. Keep in mind that returned images, in this case, might be blurry or low quality.
    - This applies to all image types: full document image, face and signature image.
- We've added two separate fields for the processing status in the Recognizer Result: `frontProcessingStatus` and `backProcessingStatus`. They indicate the status of the last recognition process for each side.
 
### Improvements
- We added support for the Malaysian NRIC numbers that hold an asterisk (*) character.
- While using `FullRecognitionMode` for scanning unsupported Passports, we are now extracting `ClassInfo` from MRZ 
- Improved quality of fully cropped vertical images
- Better parsing of Bermuda Driving License AAMVA-compliant barcode dates
- Fix for correct calculation of check digit for Saudi Arabia ID Card MRZ
- We are splitting first and last name from the additional name information (e.g., Nom d’ usage, Epouse, Geb. etc.)  into two different results. The additional name info will be a part of the `name_additional_info` field. This applies to the following documents:

    - France
        - ID Card
        - Residence Permit
    - Germany    
        - ID Card
    - Luxembourg
        - ID Card
    - Netherlands
        - Driving License
        - Polycarbonate Passport
        
- We are removing title prefixes (e.g., Mrs., Mr., Ing., etc.) from `full_name`, `first_name` and `last_name` for these documents:
    - Austria
        - Driving License
        - ID Card
    - Czechia 
        - Driving License
    - Germany
        - ID Card
    - Thailand 
        - ID Card
    - UK 
        - Driving License


#### Anonymization
- We've added anonymization for new documents:
    - Document number on Germany Polycarbonate Passport
    - Document number on Hong Kong Polycarbonate Passport
    - Document number and personal ID number on Singapore Polycarbonate Passport


## 5.11.0

### Newly supported identity documents:

We’ve added 98 new documents:

#### Europe
- Albania - Driver Card (front only)
- Albania - Professional Driver License (front only)
- Belarus - Driver License (front only, beta)
- Belgium - Minors ID (beta)
- Czechia - Residence Permit
- Finland - Alien ID
- Finland - Residence Permit (beta)
- Georgia - Driver License (front only)
- Greece - Residence Permit
- Ireland - Passport Card (beta)
- Ireland - Public Services Card (beta)
- Kosovo - Driver License (front only, beta)
- Latvia - Alien ID
- Luxembourg - ID Card
- Moldova - ID Card (beta)
- North Macedonia - Driver License (front only)
- North Macedonia - ID Card
- Poland - Passport (beta)
- Slovenia - Residence Permit (beta)
- Spain - Alien ID
- UK - Passport (beta)

#### Middle East and Africa 
- Algeria - Driver License
- Burkina Faso - ID Card (front only)
- Cameroon - ID Card (beta)
- Democratic Republic Of The Congo - Driver License (front only, beta)
- Egypt - Driver License (beta)
- Ghana - ID Card (beta)
- Iraq - ID Card (beta)
- Ivory Coast - Driver License (front only, beta)
- Ivory Coast - ID Card
- Lebanon - ID Card (beta)
- Morocco - Driver License
- Mozambique - Driver License (front only, beta)
- Oman - Driver License (beta)
- Rwanda - ID Card (front only)
- Senegal - ID Card
- Tanzania - Driver License (front only, beta)
- Tunisia - Driver License (front only)
- Uganda - Driver License (front only, beta)

#### Latin America & the Caribbean
- Argentina - Alien ID (beta)
- Bahamas - ID Card (front only, beta)
- Bolivia - Minors ID (beta)
- Jamaica - Driver License
- Mexico - Residence Permit (beta)
- Mexico - Chiapas - Driver License (front only)
- Mexico - Coahuila - Driver License (beta)
- Mexico - Durango - Driver License(front only, beta)
- Mexico - Guerrero-cocula - Driver License (beta)
- Mexico - Guerrero-juchitan - Driver License (beta)
- Mexico - Guerrero-tepecoacuilco - Driver License (front only, beta)
- Mexico - Guerrero-tlacoapa - Driver License (front only, beta)
- Mexico - Hidalgo - Driver License
- Mexico - Mexico - Driver License (beta)
- Mexico - Morelos - Driver License (front only)
- Mexico - Oaxaca - Driver License
- Mexico - Puebla - Driver License (front only, beta)
- Mexico - San Luis Potosi - Driver License (front only)
- Mexico - Sinaloa - Driver License (front only, beta)
- Mexico - Sonora - Driver License (beta)
- Mexico - Tabasco - Driver License (beta)
- Mexico - Yucatan - Driver License (beta)
- Mexico - Zacatecas - Driver License (beta)
- Panama - Temporary Residence Permit (beta)
- Peru - Minors ID (beta)
- Trinidad And Tobago - Driver License (front only, beta)
- Trinidad And Tobago - ID Card

#### Oceania
- Australia - South Australia - Proof Of Age Card (front only, beta)

#### Asia
- Armenia - ID Card
- Bangladesh - Driver License (beta)
- Cambodia - Driver License (front only, beta)
- India - Gujarat - Driving Licence (front only, beta)
- India - Karnataka - Driving Licence (front only, beta)
- India - Kerala - Driving Licence (beta)
- India - Madhya Pradesh - Driving Licence (front only, beta)
- India - Maharashtra - Driving Licence (front only, beta)
- India - Punjab - Driving Licence (front only, beta)
- India - Tamil Nadu - Driving Licence (beta)
- Kyrgyzstan - ID Card
- Malaysia - Mypolis (beta)
- Malaysia - Refugee ID (front only)
- Myanmar - Driver License (beta)
- Pakistan - Punjab - Driving Licence (front only, beta)
- Sri Lanka - Driving Licence (front only)
- Thailand - Alien ID (front only)
- Thailand - Driver License (beta)
- Uzbekistan - Driver License (front only, beta)

#### Northern America
- Canada - Tribal ID (beta)
- Canada - Nova Scotia - ID Card (beta)
- Canada - Saskatchewan - ID Card (beta)
- USA - Border Crossing Card (front only)
- USA - Global Entry Card (beta)
- USA - Nexus Card (beta)
- USA - Veteran ID (front only)
- USA - Work Permit
- USA - Mississippi - ID Card (beta)
- USA - Montana - ID Card
- USA - New Mexico - ID Card (beta)
- USA - Wisconsin - ID Card (beta)

#### Back side support added:
- Hungary - Residence Permit
- Luxembourg - Residence Permit (no longer beta)
- Mauritius - ID Card
- Colombia - Alien ID (no longer beta)
- Mexico - Baja California - Driver License
- Mexico - Chihuahua - Driver License
- Mexico - Guanajuato - Driver License
- Mexico - Michoacan - Driver License
- Malaysia - MyKid
- Malaysia - MyPR

#### No longer beta:
- Albania - Passport
- Malta - Residence Permit
- Switzerland - Residence Permit
- Bolivia - Driver License
- Chile - Passport
- El Salvador - ID Card
- Peru - ID Card
- Singapore - S Pass (front only)

### Changes to the BlinkId(Combined)Recognizer
- You can now retrieve an image of the document owner along with cropped images of the document itself whenever you’re scanning an AAMVA-compliant ID: 

	- Using `BarcodeId` as a `RecognitionMode` lets you scan US driver licenses and IDs that BlinkID can’t read from the Visual Inspection Zone (VIZ) alone. Use it to extract:
		- A face image from the front side
		- Barcode data from the back side
		- Cropped document images of both sides
	- You can disable this `RecognitionMode` by setting `enableBarcodeId` to `false` in the `RecognitionModeFilter`.
- We've improved data extraction through the MRZ:
	- We now allow standard M/F values for gender on Mexican documents (along with localized H/M values)
- We're now converting dates to the Gregorian calendar for:
	- Taiwan documents with Republic of China (ROC) calendar dates
	- Saudi documents with Islamic calendar dates
- We're now auto-filling all ‘partial’ dates found on identity documents (showing year or month-year only):
	- Date of issue will be converted to the first day of the (first) month
		- E.g. '1999' will be converted to '01.01.1999.'
		- E.g. '03.1999.' will be converted to '01.03.1999.'
	- Date of expiry will be converted to the last day of the (last) month
		- E.g. '1999' will be converted to '31.12.1999.'
		- E.g. '03.1999.' will be converted to '31.03.1999.'

### Minor API changes:

- Renamed MicroblinkApp `instance` to `sharedInstance` (Objective C) / `shared` (Swift)

### Fixes

- We've fixed missing CFBundleVersion and CFBundleVersionShort from frameworks Info.plist
- We've fixed a crash when switching to the front camera

## 5.10.0

### New features:

* We have full support for Apple Silicon!

### Framework formats and architectures:

* Use `.xcframework` as we now have full Apple Silicon and Intel support.
* We are still supporting `fat binary .framework` format, but we’ve removed simulator slices from it.

### Carthage:

* Carthage still doesn't support `binary .xcframework`, so there is no support for simulator slices anymore.

### Improvements:

* **Newly supported identity documents**

    *   Saudi Arabia - DL (front)
    *   Saudi Arabia - Resident ID (front)

### Changes to the BlinkId(Combined)Recognizer:

*   We're now able to extract the additional address on Hungary Address Cards
*   We've improved data extraction through the MRZ:
    *   We now return the document type through `MBClassInfo`, regardless of the `MBRecognitionMode` you're using (`MrzId`, `MrzPassport` or `MrzVisa`). 
    *   This means you can now use `MBClassFilter` to filter these documents by their type.
    *   We now return the document number on Nigeria IDs complete with its check digit.
    *   We now support Italy Residence Permits with a *CR* document code.
*   We've extended the `ClassInfo` structure with new properties so you can filter documents by country more easily:
    *   Use `countryName`, `isoNumericCountryCode`, `isoAlpha2CountryCode` and `isoAlpha3CountryCode` to get the full country names or their representative codes defined by [ISO](https://en.wikipedia.org/wiki/List_of_ISO_3166_country_codes).
*   We've extended the `MBBarcodeResult` structure with `extendedElements` 
    *   You can find all data from AAMVA-compliant barcodes under their respective `MBBarcodeElementKey` in the `MBBarcodeElements` structure
    *   For a full list of keys please see `MBBarcodeElementKey` enum
*   We've added another `ProcessingStatus` called `AwaitingOtherSide`
    *   This status is triggered once BlinkID has finished with the first side of a document and expects the other side, too.
*   We're now able to extract the date of birth from the CURP field on Mexico Voter IDs
*   Direct API:
	*   We've added a new recognition mode for recognizing still images of documents that have already been cropped:
		*   Set the `scanCroppedDocumentImage` to true when you're feeding BlinkID images of documents that have already been cropped and don't require detection.
		*   Keep in mind that this setting won't work on document images that haven't been properly cropped.

### Changes to the IdBarcodeRecognizer:

* We've extended the results with `extendedElements` 
    *   You can find all data from AAMVA-compliant barcodes under their respective `MBBarcodeElementKey` in the `MBBarcodeElements` structure
    *   For a full list of keys please see `MBBarcodeElementKey` enum

## 5.9.0

### New features

- We’ve added a new feedback message to users, prompting them to keep a document fully visible in cases when they accidentally cover a part of it with their finger or an object:
	- It appears while scanning the document using `MBBlinkIdOverlayViewController`
	- It will display an error message "Keep the document fully visible".
	-  It is displayed only if you’re using `MBBlinkIdRecognizer` or `MBBlinkIdCombinedRecognizer` for scanning.
- We added `Carthage` support
	- For now, `Carthage` is supported for fat binaries, `.framework`. We will support `.xcframework` as soon `Carthage` is updated.
	- Please check out our guide for implementation
- We added `Swift Package Manager` support
	- Please check out our guide for implementation.

### Note on ARM Macs

- We are supporting `ARM64 Device` slice through our `.xcframework` format.
- We are still working on supporting the `ARM64 Simulator` slice for newly released ARM Macs. We will update our SDK with `ARM64 Simulator` support as soon as it’s out.

### iOS Version support change:

-  We are no longer supporting **iOS 8**.

### Cocapods support change:

- We are updating our Cocoapods with `.xcframework` format from now on. Please download [Cocoapods 1.10.0](https://github.com/CocoaPods/CocoaPods/releases/tag/1.10.0) or newer to use our SDK.

### Newly supported identity documents

- 53 documents added:

	- ALBANIA - DL (front)
	- BELGIUM - RESIDENCE PERMIT (front, back)
	- BOLIVIA - ID (front, back)
	- BOSNIA AND HERZEGOVINA - PASSPORT
	- CAMBODIA - PASSPORT
	- CANADA - RESIDENCE PERMIT (front, back)
	- CANADA - MANITOBA - ID (front)
	- CANADA - ONTARIO - HEALTH INSURANCE CARD (front)
	- CHILE - ALIEN ID (front, back)
	- CHINA - ID (front, back)
	- COLOMBIA - MINORS ID (front, back)
	- CYPRUS - RESIDENCE PERMIT (front, back)
	- CZECHIA - PASSPORT
	- GREECE - ID (front)
	- HAITI - ID (front, back)
	- ITALY - RESIDENCE PERMIT (front, back)
	- LATVIA - DL (front)
	- LATVIA - PASSPORT
	- LITHUANIA - PASSPORT
	- LUXEMBOURG - DL (front)
	- MONTENEGRO - DL (front)
	- MONTENEGRO - ID (front, back)
	- MONTENEGRO - PASSPORT
	- NETHERLANDS - RESIDENCE PERMIT (front, back)
	- NICARAGUA - ID (front, back)
	- NIGERIA - ID (front, back)
	- NORWAY - RESIDENCE PERMIT (front, back)
	- OMAN - RESIDENT ID (front, back)
	- PARAGUAY - DL (front, back)
	- PERU - DL (front, back)
	- PHILIPPINES - SOCIAL SECURITY CARD (front)
	- ROMANIA - PASSPORT
	- RUSSIA - PASSPORT
	- SERBIA - PASSPORT
	- SLOVAKIA - PASSPORT
	- SLOVENIA - PASSPORT
	- SOUTH KOREA - DL (front)
	- SPAIN - RESIDENCE PERMIT (front, back)
	- SWEDEN - RESIDENCE PERMIT (front, back)
	- THAILAND - PASSPORT
	- UKRAINE - DL (front)
	- UKRAINE - PASSPORT
	- USA - ARKANSAS - ID (front, back)
	- USA - CONNECTICUT - ID (front, back)
	- USA - GREEN CARD (front, back)
	- USA - MARYLAND - ID (front, back)
	- USA - MINNESOTA - ID (front, back)
	- USA - NEVADA - ID (front, back)
	- USA - NEW YORK CITY - ID (front, back)
	- USA - TEXAS - WEAPON PERMIT (front)
	- USA - VIRGINIA - ID (front, back)
	- VENEZUELA - DL (front)
	- VENEZUELA - PASSPORT

- Beta support added for 46 documents:
	- ALBANIA - PASSPORT
	- BAHAMAS - DL (front)
	- BERMUDA - DL (front)
	- BOLIVIA - DL (front)
	- CHILE - DL (front)
	- COLOMBIA - ALIEN ID (front)
	- DENMARK - RESIDENCE PERMIT (front, back)
	- DOMINICAN REPUBLIC - DL (front, back)
	- ECUADOR - DL (front)
	- EL SALVADOR - DL (front, back)
	- ESTONIA - RESIDENCE PERMIT (front, back)
	- GUATEMALA - DL (front, back)
	- HAITI - DL (front)
	- HONDURAS - DL (front, back)
	- HONDURAS - ID (front, back)
	- HUNGARY - ADDRESS CARD (front, back)
	- HUNGARY - RESIDENCE PERMIT (front)
	- ICELAND - DL (front)
	- ISRAEL - ID (front, back)
	- JAPAN - DL (front)
	- JORDAN - DL (front)
	- LATVIA - ALIEN PASSPORT
	- LATVIA - RESIDENCE PERMIT (front, back)
	- LUXEMBOURG - RESIDENCE PERMIT (front)
	- MALTA - RESIDENCE PERMIT (front, back)
	- MEXICO - BAJA CALIFORNIA - DL (front)
	- MEXICO - CHIHUAHUA - DL (front)
	- MEXICO - CIUDAD DE MEXICO - DL (front)
	- MEXICO - PROFESSIONAL DL (front)
	- MEXICO - GUANAJUATO - DL (front)
	- MEXICO - MICHOACAN - DL (front)
	- MEXICO - TAMAULIPAS - DL (front, back)
	- MEXICO - VERACRUZ - DL (front, back)
	- PHILIPPINES - TAX ID (front)
	- PHILIPPINES - VOTER ID (front)
	- POLAND - RESIDENCE PERMIT (front, back)
	- PORTUGAL - RESIDENCE PERMIT (front, back)
	- PUERTO RICO - VOTER ID (front)
	- SLOVAKIA - RESIDENCE PERMIT (front, back)
	- SOUTH KOREA - ID (front)
	- SWITZERLAND - RESIDENCE PERMIT (front, back)
	- TAIWAN - TEMPORARY RESIDENCE PERMIT (front)
	- TURKEY - RESIDENCE PERMIT (front)
	- USA - KANSAS - ID (front, back)
	- VENEZUELA - ID (front)
	- VIETNAM - DL (front)

- Added back side support for 7 documents:
	- ARGENTINA - ID
	- ECUADOR - ID
	- FINLAND - ID
	- NIGERIA - DL
	- QATAR - RESIDENCE PERMIT
	- URUGUAY - ID
	- USA - NEW YORK - DL

- 9 documents are no longer beta:
	- BRAZIL - DL
	- CANADA - ALBERTA - ID
	- MALAYSIA - MyKAS
	- MEXICO - NUEVO LEON - DL
	- PANAMA - DL
	- PORTUGAL - DL
	- SAUDI ARABIA - ID
	- SRI LANKA - ID
	- USA - IDAHO - ID

### New features and updates to the BlinkId(Combined)Recognizer

- We’re now able to read partial MRZ formats (2.5 lines), like the ones found on Switzerland and Liechtenstein DLs.
- We’ve added `**documentOptionalAdditionalNumber**` to the main part of the result, as well as front and back side VIZ results.
- We’ve expanded the set of possible recognizer states with `**StageValid**`. This state fixes `MBBlinkIdCombinedRecognizer` timeout issues, and enables better control of the Combined scanning pipeline. It activates when the first side of a document has been successfully scanned and scanning of the second side is required.

### Major API changes:

- We've added an error callback when setting license keys on `MBMicroblinkSDK`
	- You will be getting error callback containing the reason why you could not unlock the SDK - see `MBLicenseError`

### Minor API changes:

- Swift:
	- All `unsigned integers` are now `Int`

### Fixes

- We’ve fixed an uncommon bug where you’d get incomplete results upon scanning of the MRZ with the `allowUnparsed` setting enabled.
- We've fixed some camera session issues
- We are now handling camera session interruption

## 5.8.0

### New features:
* We added user feedback when turning on the flashlight on `MBBlinkIdOverlayViewcontroller`:
	* It prompts user to watch out for flashlight glare
	* It can be disabled by setting `showFlashlightWarning` property to NO/false on `MBBlinkIdOverlaySettings`
* We added `MBBlinkIdOverlayViewController` customization:
	* Set font, text color, corner radius and custom images
	* Use [`MBBlinkIdOverlayTheme`](https://blinkid.github.io/blinkid-ios/Classes/MBBlinkIdOverlayTheme.html)

### New additions to our supported documents list
#### Plastic page passports
We added support for scanning the visual inspection zone - VIZ includes everything except MRZ or barcode. Keep in mind that BlinkID scans and extracts data only from the VIZ that is on the first **plastic page** found in the passport list below:

* **Chile** Passport (BETA)
* **Colombia** Passport
* **Croatia** Passport
* **Denmark** Passport
* **Finland** Passport (BETA)
* **Germany** Passport
* **Hong Kong** Passport (BETA)
* **Ireland** Passport (BETA)
* **Malaysia** Passport
* **Netherlands** Passport
* **New Zealand** Passport
* **Norway** Passport
* **Singapore** Passport
* **South Africa** Passport
* **Sweden** Passport
* **Turkey** Passport (BETA)

If you need to scan the MRZ only, you can always set the "MRZ Passport" [recognition mode](https://blinkid.github.io/blinkid-ios/Classes/MBRecognitionModeFilter.html#/c:objc(cs)MBRecognitionModeFilter(py)enableMrzPassport).
​
#### Vertical US documents
* **California** ID
* **Illinois** ID
* **New York** ID
* **North Carolina** ID
* **Texas** ID


#### Other documents
* **Canada** Newfoundland and Labrador DL
* **Croatia** Residence Permit (BETA)
* **Guatemala** Consular ID
* **Malaysia** MyKAS (BETA)
* **Mexico** Jalisco DL / front side only
* **Mexico** Nuevo Leon DL (BETA)
* **Peru** ID (BETA)
* **Singapore** S Pass (BETA)
* **Uruguay** ID / front side only
* **USA** Missouri ID
* **USA** Texas ID

#### European DLs with a single line MRZ
BlinkID extracts data from driver’s licenses that contain single line MRZ:

* **Croatia** DL
* **Estonia** DL
* **France** DL
* **Ireland** DL
* **Netherlands** DL
* **Slovakia** DL

#### Back side supported on:
* **Azerbaijan** ID
* **Singapore** DL
* **Singapore** Employment Pass

#### No longer BETA
* **Slovakia** DL

### New features and updates in MBBlinkID(Combined)Recognizer
* We added `signatureImage` to the result. Extract signature image from the documents below:
	* Australia Victoria DL
	* Austria ID
	* Austria DL
	* Brunei Military ID
	* Colombia ID
	* Croatia ID (on 2013 and 2015 versions)
	* Cyrus ID
	* Czechia ID (on the 2012 version)
	* Germany ID (2010 version)
	* Germany DL (2013 version)
	* Indonesia ID
	* Ireland DL
	* Italy DL
	* Mexico Voter ID
	* New Zealand DL
	* Slovenia ID
	* Spain DL
	* Sweden DL
	* Switzerland ID
	* UAE ID
	* UAE Resident ID

* We enabled extraction of the **date of birth** from the **NRIC** from Malaysian documents:
	* MyKad
	* MyKas
	* MyKid
	* MyPR
	* MyTentera

* We added anonymization support for:
	* MRZ (OPT2 containing the ID number) on China Mainland Travel Permit Hong Kong
	* MRZ (Document number) on Germany Alien Passport
	* Document number, MRZ (Document number) on Germany ID
	* MRZ (Document number) on Germany Minors Passport
	* MRZ (Document number) on Germany Passport
	* Document number on Hong Kong ID
	* MRZ (Document number, OPT1 containing the passport or ID number) on Hong Kong Passport
	* Personal ID number on Netherlands DL
	* Personal ID number, MRZ (OPT1 containing the BSN) on Netherlands ID
	* MRZ (OPT1 containing the BSN) on Netherlands Passport
	* Document number on Singapore DL
	* Personal ID number on Singapore Employment Pass
	* Document number on Singapore FIN Card
	* Document number on Singapore ID
	* MRZ (Document number, OPT1 containing the NRIC) on Singapore Passport
	* Document number on Singapore Resident ID
	* Document number on Singapore S Pass
	* Personal ID number on Singapore Work Permit
	* MRZ (OPT1 containing the resident registration number) on South Korea Diplomatic Passport 
	* MRZ (OPT1 containing the resident registration number) on South Korea Passport
	* MRZ (OPT1 containing the resident registration number) on South Korea Residence Passport
	* MRZ (OPT1 containing the resident registration number) on South Korea Service Passport
	* MRZ (OPT1 containing the resident registration number) on South Korea Temporary Passport
* We improved MRZ data extraction on:
	* **Russia Passport**

### Other features and updates

* We added the field `middleName` to `MBBlinkID(Combined)Recognizer`, `MBIdBarcodeRecognizer` and `MBUsdl(Combined)Recognizer` results. This field is extracted from AAMVA standard compliant barcodes, whenever available.

### Deprecated recognizers
* We have deprecated following recognizers:
	* `MBDocumentFaceRecognizer`
	* `MBMrtdRecognizer`
		* **Use `MBBlinkIdRecognizer` instead**
	* `MBMrtdCombinedRecognizer`
	* `MBPassportRecognizer`
	* `MBVisaRecognizer`
		* **Use `MBBlinkIdRecognizer` or `MBBlinkIdCombinedRecongizer` instead**
	* `MBUsdlRecognizer`
		* **Use `MBIdBarcodeRecognizer` instead**

### Major API change:
* We added `errorCallback` on `MBMicroblinkSDK` methods which needs to be implemented for properly setting up the license key.

### Fixes
* We improved the data match logic for **Guatemala Consular ID** in `MBBlinkID(Combined)Recognizer`.
* We fixed race conditions and camera asserts that could sometimes cause crashes.
* We fixed camera reticle animation on `MBBlinkIdOverlayViewController` when user would go to the background.
* We fixed SDK localization that was broken when device language is set to Chinese Simplified.

## 5.7.1

### Major bug fix:

- This version fixes bug introduced in [v5.7.0](https://github.com/BlinkID/blinkid-ios/releases/tag/v5.7.0) which could cause SDK crash on `applicationDidBecomeActive` event.

### New features:

- We translated complete SDK to the following additional languages:: **Malay**, **Dutch**, **Hungarian**, **Indonesian**, **Arabic(UAE)**, **Romanian**, **Chinese traditional**, **Chinese simplified**, **Thai**, **Hewbrew** and **Vietnamese**.

### Improvements to existing features:

- We have improved parsing of **MRZ** formats deviating from the ISO/IEC 7501 standard:
	- Document discriminator was in place of the document number on driver licenses and IDs from:
		- **New York** 
		- **Michigan** 
		- **Canada**
	- Different check digit calculation for **Mexico** (Consular) ID
	- Recognition of the unofficial `XCT` country code for Northern **Cyprus** ID
	- Recognition of different country codes and check digit calculation on **China** Mainland Travel Permit for Hong Kong and Macao Residents
- We added **anonymization** support for:
	- MRZ on the Mainland Travel Permit for Hong Kong and Macao Residents
- We have made some changes to the **MBBlinkIdRecognizer** and **MBBlinkIdCombinedRecognizer**
	- You can now see `MBProcessingStatus` in the results to inspect potential processing errors, such as when barcode detection fails, a mandatory field is missing, etc. 
	- You can now also see a more detailed `MBImageAnalysisResult` showing you when: 
		- Face image is detected
		- MRZ is detected
		- Barcode is detected
	- We added a `MBRecognitionModeFilter` settings group. You can toggle flags on this object to control the recognition mode of the recognizer:
		- `enableMrzId` lets you scan MRZ on all identity documents except visas and passports.
		- `enableMrzVisa` lets you scan MRZ on visa documents.
		- `enableMrzPassport` lets you scan MRZ on passports.
		- `enablePhotoId` lets you scan photo IDs. Use it to enable or disable document and face image extraction on unsupported documents.
		- `enableFullRecognition` lets you scan all data from our [supported](https://github.com/BlinkID/blinkid-ios/blob/master/documentation/BlinkIDRecognizer.md) documents.
		- Your license key still controls which of the above recognition modes are allowed.
	- We have added a `MBRecognitionMode` result member describing which recognition mode was used to produce the results.
	-  We are now retrieving sex and nationality fields from the MRZ in cases where those two fields cannot be found in the document’s VIZ. Previously, we only used to do this for dates, name fields and document numbers. 
	- We are now preserving the original string (raw data) of the dates we couldn’t parse.
- We have improved the thresholds for card detection feedback messages ("move closer" and "move farther"). This will improve the UX when scanning in landscape mode as the document can now be closer to the camera.
- We added `disableMicroblinkLogging` method to `MBLogger` for easier implementation
	- This also enables disabling Microblink logging in Swift. 

### Minor API changes:

- We have made some changes to the **MBBlinkIdRecognizer** and **MBBlinkIdCombinedRecognizer**:
	- We renamed `MBDocumentImageMoireStatus` to `MBImageAnalysisDetectionStatus`.
	- We grouped the `conditions` member from the results with the `MBDriverLicenseDetailedInfo` structure.
- We renamed `MBRecogitionMode` to `MBRecognitionDebugMode` in `MBRecognizerCollection`.
- Swift:
	- We renamed all `sharedInstance` to `shared`.
	- All enums are now `Int`.

### Bug fixes:

- We added a `nullable` attribute to the `recognizerRunnerViewControllerWithOverlayViewController` to fix a force unwrapping issue in Swift that could occur if the camera is broken or not working.

## 5.7.0

### New features:

- We translated complete SDK to the following additional languages:: **Malay**, **Dutch**, **Hungarian**, **Indonesian**, **Arabic(UAE)**, **Romanian**, **Chinese traditional**, **Chinese simplified**, **Thai**, **Hewbrew** and **Vietnamese**.

### Improvements to existing features:

- We have improved parsing of **MRZ** formats deviating from the ISO/IEC 7501 standard:
	- Document discriminator was in place of the document number on driver licenses and IDs from:
		- **New York** 
		- **Michigan** 
		- **Canada**
	- Different check digit calculation for **Mexico** (Consular) ID
	- Recognition of the unofficial `XCT` country code for Northern **Cyprus** ID
	- Recognition of different country codes and check digit calculation on **China** Mainland Travel Permit for Hong Kong and Macao Residents
- We added **anonymization** support for:
	- MRZ on the Mainland Travel Permit for Hong Kong and Macao Residents
- We have made some changes to the **MBBlinkIdRecognizer** and **MBBlinkIdCombinedRecognizer**
	- You can now see `MBProcessingStatus` in the results to inspect potential processing errors, such as when barcode detection fails, a mandatory field is missing, etc. 
	- You can now also see a more detailed `MBImageAnalysisResult` showing you when: 
		- Face image is detected
		- MRZ is detected
		- Barcode is detected
	- We added a `MBRecognitionModeFilter` settings group. You can toggle flags on this object to control the recognition mode of the recognizer:
		- `enableMrzId` lets you scan MRZ on all identity documents except visas and passports.
		- `enableMrzVisa` lets you scan MRZ on visa documents.
		- `enableMrzPassport` lets you scan MRZ on passports.
		- `enablePhotoId` lets you scan photo IDs. Use it to enable or disable document and face image extraction on unsupported documents.
		- `enableFullRecognition` lets you scan all data from our [supported](https://github.com/BlinkID/blinkid-ios/blob/master/documentation/BlinkIDRecognizer.md) documents.
		- Your license key still controls which of the above recognition modes are allowed.
	- We have added a `MBRecognitionMode` result member describing which recognition mode was used to produce the results.
	-  We are now retrieving sex and nationality fields from the MRZ in cases where those two fields cannot be found in the document’s VIZ. Previously, we only used to do this for dates, name fields and document numbers. 
	- We are now preserving the original string (raw data) of the dates we couldn’t parse.
- We have improved the thresholds for card detection feedback messages ("move closer" and "move farther"). This will improve the UX when scanning in landscape mode as the document can now be closer to the camera.
- We added `disableMicroblinkLogging` method to `MBLogger` for easier implementation
	- This also enables disabling Microblink logging in Swift. 

### Minor API changes:

- We have made some changes to the **MBBlinkIdRecognizer** and **MBBlinkIdCombinedRecognizer**:
	- We renamed `MBDocumentImageMoireStatus` to `MBImageAnalysisDetectionStatus`.
	- We grouped the `conditions` member from the results with the `MBDriverLicenseDetailedInfo` structure.
- We renamed `MBRecogitionMode` to `MBRecognitionDebugMode` in `MBRecognizerCollection`.
- Swift:
	- We renamed all `sharedInstance` to `shared`.
	- All enums are now `Int`.

### Bug fixes:

- We added a `nullable` attribute to the `recognizerRunnerViewControllerWithOverlayViewController` to fix a force unwrapping issue in Swift that could occur if the camera is broken or not working.

## 5.6.0

### New features:

- We have translated complete SDK to following languages: **Croatian**, **Czech**, **English**, **French**, **German**, **Italian**, **Portuguese**, **Slovak**, and **Spanish**.

- In `MBBlinkIdCombinedRecognizer` and `MBBlinkIdRecognizer` we added:
    - Support for US documents with **vertical** orientations:
        - Alabama DL
        - Arizona DL
        - California DL
        - Colorado DL
        - Connecticut DL
        - Georgia DL
        - Illinois DL
        - Iowa DL
        - Kansas DL
        - Kentucky DL
        - Maryland DL
        - Massachusetts DL
        - Minnesota DL
        - Missouri DL
        - New Jersey DL
        - Ohio DL
        - Pennsylvania DL
        - South Carolina DL
        - Tennessee DL
        - Texas DL
        - Utah DL
        - Washington DL
        - Wisconsin DL
    - Support for **new document types**:
        - Croatia Health Insurance Card / front side / BETA
        - Ecuador ID / front side
        - El Salvador ID / BETA
        - Sri Lanka ID / BETA
    - No longer BETA:
        - Canada Nova Scotia DL
        - Canada Yukon DL
        - Norway DL
    - Back side support:
        - Kenya ID
    - **Result anonymization** - with this option enabled, results are not returned for protected fields on certain documents. The full document image will also have this data blacked out.
    	- Protected fields are:
         - Document number on Hong Kong ID
         - MRZ on Hong Kong passports
         - Personal ID number on Netherlands DL
         - Personal ID number and MRZ on Netherlands ID
         - MRZ on Netherlands passports
         - Document number on Singapore DL, ID, Fin Card, Resident ID
         - Personal ID number on Singapore Employment Pass
         - Document number and personal ID number on Singapore Work Permit
         - MRZ on Singapore passports
   		- By using `anonymizationMode` property, you can choose the `MBAnonymizationMode`: `ImageOnly`, `ResultFieldsOnly`, `FullResult` or `None`.
    	- `FullResult` anonymization (both images and data) is set by default.

- We added support for new **MRZ** formats:
    - Guatemala ID
    - Kenya ID

### Improvements to existing features:

- We updated `MBUsdlRecognizerResult` and `MBIdBarcodeRecognizer.Result` with additional address fields:
    - `street`, `postalCode`, `city` and `jurisdiction` 
- We added `expired` (in Swift `isExpired`) property to `MBBlinkIdRecognizerResult`, `MBBlinkIdCombinedRecognizerResult` and `MBIdBarcodeRecognizerResult`.
    - It compares the current time on the device with the date of expiry and checks whether the document has expired or not. 
- We made changes to the result structure of `MBBlinkIdCombinedRecognizer` and `MBBlinkIdRecognizer`:
    - Barcode data is now encapsulated in its own result structure: `MBBarcodeResult`.
    - Data from all OCR-ed fields, without MRZ data, is now encapsulated in a `MBVizResult` structure, representing the "Visual Inspection Zone" data. In `MBBlinkIdCombinedRecognizer`, front side data is available in its own structure (`frontVizResult`), back side data in its own (`backVizResult`), so you can now **access data from each side separately**.
    - The main part of the result, outside these structures, is filled according to these rules:
        - Document number is filled with data from the MRZ, if present.
        - Remaining data is then filled with barcode data.
        - Remaining data is filled from the back side's visual inspection zone (OCR data outside of MRZ).
        - Remaining data is filled from the front side's visual inspection zone.
        - Remaining data is filled with data from the MRZ.

### Minor API changes:

- We moved `MBBlinkIdRecognizerResult` members `colorStatus` and `moireStatus` to the result's `imageAnalysisResult` (`frontImageAnalysisResult` and `backImageAnalysisResult` in `MBBlinkIDCombinedRecognizerResult`).
- We moved all resources inside framework, we are not shipping `Microblink.bundle` anymore

### Bug fixes:

- We fixed US driver's license address extraction (Oregon, Mississippi, Rhode Island).
- We removed OpenGL entirely which was causing unexpected crashes.

## 5.5.0

### New features:

- In `MBBlinkIdCombinedRecognizer` and `MBBlinkIdRecognizer` we added:
	- Support for obtaining full document image for IDs with barcodes. Now you can capture document image and extract barcode data with a single scan.
	- Scanning & data extraction for  travel visas and passports.
	- Field validation - we validate if the results from certain fields match predefined character sets.
			- If validation fails, the recognizer's state is `MBRecognizerResultStateUncertain`.
			- Use `validateResultCharacters`to enable or disable validation.
	- Field anonymization for sensitive data.
			- Enable or disable whether certain sensitive data should be anonymized in full document image result.
			- Use `anonymizeImage` to enable or disable image anonymization.
	
	- Support for new document types:
		- Australia New South Wales - ID Card / Front only / BETA
		- Brazil - Driver License / BETA
		- Brunei - Military ID / BETA
		- Brunei - Residence Permit / BETA
		- Brunei - Temporary Residence Permit / BETA
		- Ghana - Driver License / Front only
		- Latvia - ID Card
		- Norway - Driving Licence / Front only / BETA
		- Oman - ID Card
		- Saudi Arabia - ID Card / BETA
		- Sweden - Social Security Card / Front only
		- USA - Social Security Card / BETA
		- Back side supported:
			- Malaysia - MyTentera

	- No longer BETA:
		- Australia Tasmania - Driving Licence
		- Canada British Columbia - ID Card
		- Germany - Residence Permit
		- Morocco - ID Card
		- Nigeria - Voter ID
		- Singapore - Work Permit
		- USA Alaska - ID Card
		- USA District Of Columbia - Driver License
		- USA Indiana - ID Card
		- USA Kentucky - ID Card
	
	- Barcode scanning on the following documents:
		- Argentina ID
		- Colombia ID
		- Nigeria Voter ID
		- South Africa ID

### Improvements for existing features:

- Improvements in `MBBlinkIdCombinedRecognizer` and `MBBlinkIdRecognizer`:
	- Documents discarded with the class filter are now reported as not supported
		-  `onDocumentSupportStatus` will be called if a documents is filtered out by the `classInfoFilter`.
	- For Malaysian MyKad we are now returning if a Moire pattern is present on the scanned document (detected or not detected).
		- use `documentImageMoireStatus` in `MBBlinkIdRecognizer`.
		- use `documentFrontImageMoireStatus` and `documentBackImageMoireStatus` in `MBBlinkIdCombinedRecognizer`.
- We added digital signature support to `MBPassportRecognizer`. 
- We updated `MBIdBarcodeRecognizerResult` with specific driving license info.
	- Use `restrictions`, `endorsements` and `vehicleClass`

### Bug fixes:

- Fixed check mark confirmation image and flip animation image appearing sometimes one over another on back side scanning on `MBBlinkIdOverlayViewController`
- Fixed immediately back side scanning on `MBBlinkIdOverlayViewController` which sometimes caused not getting full document back side image
 
## 5.4.1

### Bug fixes:

- Fixed returning of `MBType` on `MBClassInfo` object in `MBBlinkIdRecognizer` and `MBBlinkIdCombinedRecognizer`

## 5.4.0

### New features:

- Introducing support for new framework format - XCFramework:
	- it contains all the necessary device and simulator architecture slices
	- no neeed to remove simulator slices before distributing your app to the App Store as described [here](https://github.com/BlinkID/blinkid-ios#unsupported-architectures-when-submitting-app-to-app-store)
	- for now, only available from this repo, **not available on Cocoapods**
- We added age verification feature:
    - Now you can more easily obtain the age of the document owner in years and check whether it is above some age limit
	- available on `MBMrzResult`, `MBBlinkIdRecognizerResult`, `MBBlinkIdCombinedRecognizerResult`, `MBUsdlRecognizerResult`, `MBUsdlCombinedRecognizerResult` and `MBIdBarcodeRecognizerResult`
- Added presets for camera - Preset1080p, and 4K; Optimal always chooses the highest quality

### Improvements for existing features:

- We added support for new document types in `MBBlinkIdCombinedRecognizer` and `MBBlinkIdRecognizer`:
	- Australia - Australian Capital Territory - Driving Licence / front only
	- Australia - Northern Territory - Driving Licence / BETA
	- Australia - Tasmania - Driving Licence / front only / BETA
	- Canada - Alberta - ID Card / BETA
	- Canada - British Columbia - Driver License/Public Services Card (Combined) 
	- Canada - British Columbia - ID Card / BETA
	- Canada - British Columbia - Public Services Card
	- Canada - New Brunswick - Driving Licence
	- Canada - Nova Scotia - Driving Licence / BETA
	- Canada - Yukon - Driving Licence / BETA
	- Panama - Driving Licence / front only / BETA
	- Panama - ID Card / front only
	- Singapore - Work Permit / BETA
	- Taiwan - ID Card / front only / BETA
	- USA - Alabama - ID Card
	- USA - Alaska - ID Card / BETA
	- USA - District Of Columbia - Driver License / BETA
	- USA - Idaho - ID Card / BETA
	- USA - Indiana - ID Card / BETA
	- USA - Kentucky - ID Card / BETA
	- USA - Massachusetts - ID Card
	- USA - Oregon - ID Card
	- USA - Washington - ID Card
	- Back side supported:
		- Australia - Western Australia - Driving Licence
		- Mexico - Voter ID
		- Netherlands - Driving Licence

- Additional improvements in `BlinkIdCombinedRecognizer` and `BlinkIdRecognizer`:
    - When the back side of the document is not fully supported by the `MBBlinkIdCombinedRecognizer`, we will capture and return the back side image without performing data extraction. You can disable this behaviour by using `skipUnsupportedBack`.
    - We are now returning color status for the scanned document (black and white or color) in the following result fields:
        - `documentImageColorStatus` in `MBBlinkIdRecognizerResult`.
        - `documentFrontImageColorStatus` and `documentBackImageColorStatus` in `MBBlinkIdCombinedRecognizerResult`
    - We are now returning `ClassInfo` which holds the following information about the scanned document: `Country`, `Region`, and `Type` of the document. Use  `classInfo`
    - We introduced `ClassFilter` which determines whether a document should be processed or is filtered out, based on its `ClassInfo`. Use  `classFilter`
    - To improve the scanning performance, we added additional feedback for users that ensures a detected document is entirely inside the frame. When a document is too close to the edge of the camera frame, we will display an appropriate message to the user in `MBBlinkIdOverlayController`. You can configure the minimum distance from the edge of the frame by using the `paddingEdge` settings method

- Improvements in `MBBlinkIdOverlayViewController `:
    - When a document is too close to the edge of the camera frame, we display *`Move the document from the edge`* message.
    - We added better user instructions when barcodes are being scanned in `MBUsdlCombinedRecognizer`. We display *`Scan the barcode`* message.
- We are now delivering the complete list of open source dependencies used in the SDK. Please check the `open-source-software-used` directory
- We improved document detection with `MBDocumentCaptureRecognizer`

### Bug fixes:

- Fixed animation on back side scanning on `MBBlinkIdOverlayViewController` when recognizer is wrapped in `MBSuccessFrameGrabberRecognizer`
- Large memory consumption introduced in v5.3.0 is due to 4K video session on all 4K eligible iPhones; we introduced new camera presets 1080p and 4K, so to reduce your app memory consumption set camera preset on 1080p or 720p

## 5.3.0

### New features:

- We added a new recognizer specialized for scanning and parsing barcodes on various identity cards - `MBIdBarcodeRecognizer`.  Supported document types are:
    - AAMVA compliant (US DL, Canada DL, etc.)
    - Argentina ID and driver license
    - Panama ID
    - Colombia ID and driver license
    - South Africa ID
    - Nigeria Voter ID and driver license

- We added the option to disable Microblink logs in the console output. Use `MBLogger` class and conform to `MBLoggerDelegate` in `AppDelegate`. To disable logs, implement delegate method `- (void)log:(MBLogLevel)level format:(const char *)format arguments:(va_list)arguments`. Be careful with this option. We need full log outputs from the application for support purposes. In case of having problems with scanning certain items, undesired behavior on the specific device(s), crashes inside SDK or anything unmentioned, we will need a full log from your side. If you disable Microblink logging, you won't be able to provide us this information. Hence support might be limited.

### Improvements for existing features:

- We added new result fields in `MBMrzResult`, returned by all recognizers which scan MRZ (Machine Readable Zone):
    - `issuerName`
    - `nationalityName`
- Improvements in `MBBlinkIdCombinedRecognizer` and `MBBlinkIdRecognizer`:
    - new recognizer options: `allowUnparsedMrzResults` and `allowUnverifiedMrzResults`
    - new result field: `dateOfExpiryPermanent`
    - support for 14 new document types: `South Australia DL`, `Bosnia and Herzegovina DL`, `Canada Ontario ID`, `Costa Rica DL`, `Denmark DL`, `Estonia DL`, `Finland DL`, `Kenya ID`, `Lithuania DL`, `Malaysia MyPR`, `Malta DL`, `Mexico Consular ID`, `Nigeria Voter ID`, `Philippines Professional ID`
    - improved support for: `USA Hawaii DL`, `Colombia DL`, `Costa Rica ID`, `France ID`, `India ID`, `Kazakhstan ID`, `Kuwait Resident ID`, `Israel DL`, `Kuwait DL`, `Thailand ID`

### Bug fixes:

- Fixed `Torch` activation for all iOS versions
- Fixed OpenGL code which was fragile and sensitive to crashes if used from multiple threads

## 5.2.0

- Improvements in ID scanning performance:
    - **overall size impact on application reduced for almost 4MB** when BlinkID SDK v5.2 is used, relative to size impact of the previous v5.1

- Updates and additions:
    - added Canada Alberta DL support for `MBBlinkIdRecognizer` and `MBBlinkIdCombinedRecognizer`
    - enabled scanning back sides of 6 documents for `MBBlinkIdCombinedRecognizer`:
        - Czechia ID
        - Egypt ID
        - Germany ID
        - Italy ID
        - Pakistan Consular ID
        - Pakistan ID
    - enabled digital signing of `MBBlinkIdCombinedRecognizerResult`
    - enabled setting `MBMrzCombinedFilter` on `MBMrtdCombinedRecognizer`:
        - determines whether document should be processed or it is filtered out, based on its MRZ (Machine Readable Zone)
    - added property `localizedName` to `MBBlinkIdRecognizerResult` and `MBBlinkIdCombinedRecognizerResult` (CCC to chinese alphabet conversion for Hong Kong ID)
    - added setting `anonymizeNetherlandsMrz` on `MBPassportRecognizer`

- Bugfixes:
    - `MBBlinkIDCombinedRecognizer` - fixed issue when the front side of a document was accepted as a back side

## 5.1.1

- Bugfixes:
    - fixed memory leaks that could cause crashes in some cases

- Minor API changes:
    - `MBBlinkIdRecognizer` and `MBBlinkIdCombinedRecognizer`
        - methods `setDewarpedImageDelegate` and `setClassifierDelegate` are now properties `dewarpedImageDelegate` and `classifierDelegate`

## 5.1.0

- Updates and additions:
    - added 38 new documents for `MBBlinkIdRecognizer` and `MBBlinkIdCombinedRecognizer`
        - Algeria ID, Argentina DL, Australia Victoria DL, Australia Queensland DL, Australia Western Australia DL, Belgium Resident ID, Canada British Columbia DL, Canada Ontario DL, Canada Quebec DL, Cyprus ID, Czechia DL, Czechia ID, Egypt ID, Greece DL, India ID, India Pan Card, Israel DL, Malaysia MyKid, Malaysia MyTentera, Maldives ID, Morocco ID, Nigeria DL, Paraguay ID, Portugal DL, Puerto Rico DL, Qatar DL, Russia DL, Singapore Fin Card, Singapore Resident ID, Slovakia DL, Slovenia DL, South Africa DL, South Africa ID, Thailand ID, Tunisia ID, UAE DL, Uganda ID, Vietnam ID
    - details on each new document and the complete list of the supported documents is [here](https://github.com/BlinkID/blinkid-ios/blob/master/documentation/BlinkIDRecognizer.md)

- Improvements in ID scanning performance:
    - **reduced overall size impact on application for approximately 50%** when BlinkID SDK v5.1 is used, relative to size impact of the previous version (v5.0)
    - new fields in `MBMrzResult`:
        - `sanitizedDocumentCode`
        - `sanitizedDocumentNumber`
    - improved `MBBlinkIdRecognizer` and `MBBlinkIdCombinedRecognizer`:
        - introduced blur filter that discards blurred frames and prevents reading data from them, this option is enabled by default, it can be disabled by setting `allowBlurFilter` to `NO/false`

- Bugfixes:
    - fixed bug when scanning would not resume after doment sides would not match on `MBBlinkIdOverlayViewController`

## 5.0.2

- Updates and additions:
    - new options in `MBBlinkIdOverlaySettings`:
        - option to disable displaying of "Document Not Supported" dialog when `MBBlinkIdRecognizer` or `MBBlinkIdCombinedRecognizer` is used in combination with other recognizers - use method `showNotSupportedDialog`
        - option to configure back side scanning timeout - use `backSideScanningTimeout`

- Minor API changes:
    - methods `pauseScanning` and `resumeScanningAndResetState` in `MBRecognizerRunnerViewController` do not return anymore `BOOL`
        - use `isScanningPaused` to check if scanning is paused

- Bugfixes:
    - fixed issue where recognizer's result state would not be the same as recognizer's runner state after finished scanning
    - fixed issue when pressing immediately close button on overlay view controllers would freeze for couple of seconds SDK

## 5.0.1

- Updates and fixes:
    - Added missing option to remove Microblink branding on `MBBlinkIdOverlayViewController` - contact [help.microblink.com](help.microblink.com). 
    - Fixed turning on flashlight in our overlay view controllers on iOS 13.1.3 


## 5.0.0

### **BlinkID v5 Release Announcement**

We are very proud to announce BlinkID v5, the latest upgrade of our most popular product. BlinkID v5 is our first product powered entirely by machine learning.

#### Highlights in the BlinkID v5 Release

BlinkID v5 introduces improvements in the speed and accuracy of scanning and data extraction, and you will find:

- Best-in-class card detection.
- Automatic classification of different document types (no need to preselect the country or document type). 
- Innovative and seamless UX with real-time instructions for the users.
- Data matching – we match the expiry date, DOB, date of issue, and document number captured from the front side with the data from the barcode or MRZ on the back.

Besides the new features listed above, we have worked on the improved performance of several other document components:

- Scanning of all documents with MRZ (IDs, passports, travel visas), or PDF417 barcodes.
- Scanning and data extraction of the front side of US driver’s licenses and IDs (horizontal).
- Capturing cropped face image supported even on vertical documents, passports and travel visas.
- Capturing document image.

#### Integration improvements

One of the main benefits that BlinkID v5 will bring is scalability and faster support for new document types.

- The integration of the mobile SDK will be significantly easier and faster.
- Mobile SDK build size will be much smaller.

#### How to get started and plan your upgrade?

BlinkID v5 mobile SDK release is currently available for native platforms.

- It’s advisable to get familiar with the range of supported document types. We will keep adding support for new documents and regularly update [the list on Github](https://github.com/BlinkID/blinkid-ios/blob/master/documentation/BlinkIDRecognizer.md).
- If currently supported document types are not yet supported in BlinkID v5 please follow future releases.
- To upgrade to BlinkID v5, you will need to obtain a new license key specifically for the document types that you require.
- Already licensed production keys will continue to work as usual, until you decide to upgrade.
- What if you require document types supported in the previous version (and not yet added in BlinkID v5) and another document type supported in BlinkID v5? That’s manageable, and in that case, we will create a custom build for you.

We strongly recommend checking the [list of supported document types](https://github.com/BlinkID/blinkid-ios/blob/master/documentation/BlinkIDRecognizer.md) regularly. Please star and watch this repository, and take the time to test BlinkID v5 as much as possible.

Your opinion, especially on the performance and redesigned UX is very important for future developments. We would appreciate your feedback at blinkid@microblink.com.

### Major API changes:
    - removed all country specific recognizers
    - `MBBlinkIdRecognizer` and `MBBlinkIdCombinedRecognizer` are recognizers that classify and extract data from all country specific recognizers available in 4.x.x versions
    - available recognizers are:
        - `BlinkIdRecognizer`
        - `BlinkIdCombinedRecognizer`
        - `MBPassportRecognizer`
        - `MBVisaRecognizer`
        - `MBDocumentFaceRecognizer`
        - `MBMrtdRecognizer`
        - `MBMrtdCombinedRecognizer`
        - `MBUsdlRecognizer`
        - `MBUsdlCombinedRecognizer`
    - parsers and detectors are removed from this version onward
    - Templating API is no longer supported
    - `field by field` scanning feature is no longer supported
    - Swift Module has been renamed from `MicroBlink` to `Microblink`
        - this will cause Swift project to crash at compile time so please do `import Microblink` from now on

### New features:
    - updated `MBBlinkIdRecognizer` and `MBBlinkIdCombinedRecognizer` with new document types for different countries
        - you can check [list of supported document types](https://github.com/BlinkID/blinkid-ios/blob/master/documentation/BlinkIDRecognizer.md)

### Minor API changes:
    - in combined recognizers results, `documentDataMatch` value is now returned as `MBDataMatchResult` enum with three possible values: `NotPerformed`,  `Failed` and `Success`


## 4.11.0

- Updates and additions:
    - added support for reading front and back side of Belgium ID - use `MBBelgiumIdFrontRecognizer`, `MBBelgiumIdBackRecognizer` and `MBelgiumCombinedRecognizer`
    - added support for reading all visa documents containing Machine Readable Zone - use `MBVisaRecognizer`

- Improvements in ID scanning performance:
    - improved `MBMrtdRecognizer`: 
        - added support for documents with non-binary gender specification (symbol X)
    - improved `MBDocumentFaceRecognizer`:
        - improved scanning time (faster scan)
        - added support for vertical IDs
        - removed the `tryBothOrientations` option (improved scan in all directions is enabled by default)
    - improved scanning time (faster scan) for `MBPassportRecognizer`

## 4.10.0

- Updates and additions:
    - added `MBBlinkIdRecognizer` for scanning front side of ID cards and `MBBlinkIdCombinedRecognizer` for combined scanning of front and back side of ID cards
        - for now, these recognizers classify and extract data from **87** different classes of **United States driver's licenses** (front and back side)
        - in the upcoming releases, we are planning to add support for more document types from different countries
    - completely new UX for scanning ID cards with scan overlay view controller: `MBBlinkIdOverlayViewController`:
        -  best suited for scanning with `MBBlinkIdRecognizer` and `MBBlinkIdCombinedRecognizer`
        - other single side and combined document recognizers are also supported
- added support for reading back side of Nigerian Voter ID card - use `MBNigeriaVoterIdBackRecognizer`

- Improvements in ID scanning performance:
    - improved `MBRomaniaIdFrontRecognizer`
        - now extracts `CNP` number
    - improved `MBSloveniaIdFrontRecognizer` and `MBloveniaCombinedRecognizer`:
        - return boolean flag which indicates whether **date of expiry** is permanent - use `dateOfExpiryPermanent`
    - improved `MBGermanyPassportRecognizer`:
        - better passport classification
    - improved `MBColombiaIdFrontRecognizer`:
        - support for document number in format 1-3-3
    - improved `MBSlovakiaIdFrontRecognizer`:
        - support for German letters
    - Malaysia:
        - `MBMalaysiaMyTenteraFrontRecognizer` supports 6-digit army number
        - `MBMalaysiaIkadFrontRecognizer` - better extraction of the following fields (DeepOCR support): date of birth, sector, employer, address and date of expiry
    - United Arab Emirates:
        - glare detection is disabled by default for `MBUnitedArabEmiratesIdFrontRecognizer` and `MBUnitedArabEmiratesIdBackRecognizer` 
        - `MBUnitedArabEmiratesIdBackRecognizer` - optimized detection for black backgrounds

- Bugfixes:
    - fixed bug in `MBBlinkCardOverlayViewController` which caused memory issues

## 4.9.1

- Bugfixes:
    - fixed bug in `MBDocumentFaceRecognizer` which caused that DPI settings has not been applied to dewarped image

## 4.9.0

- Updates and additions:
    - added support for reading all passports with MRZ - use `MBPassportRecognizer`
    - added setting on `MBDocumentFaceRecognizer` for control over face image processor - use `tryBothOrientations`
    - added result property on `MBGermanyCombinedRecognizerResult` to get full mrz string result - use `rawMrzString`

- Improvements in ID scanning performance:
    - added support for reading commercial code in two rows for `MBHongKongIdFrontRecognizer`
    - added support for `MBHongKongIdFrontRecognizer` 2018 version
    - improved reading accuracy for the following recognizers (**DeepOCR** support):
        - `MBMalaysiaIKadFrontRecognizer`
    - improved scanning time of all Malaysian ID front recognizers: MyKad, MyKAS, MyPR, MyTentera

- Minor API changes:
    - `partialRecognitionTimeout` in `MBRecognizerCollection` default value has been changed to **0** which means no timeout will be reported in which partial scanning results will be returned to the user

- Bugfixes:
    - fixed issue with combining surnames in `MBGermanyCombinedRecognizer`'s logic
    - fixed a validation issue for the gender field in `MBSloveniaCombinedRecognizer`
    - fixed DPI options on images are now correctly applied to dewarped image results in `MBDocumentFaceRecognizer`

## 4.8.0

*Important notice on MRTD recognizer in the latest BlinkID SDK release (v 4.8.0.)*

Please note that we have significantly improved accuracy for MRZ/MRTD scanning because now we switched to the newest OCR technology based on machine learning.
To be more precise, we measured and compared existing vs. new MRTD scanning. The new OCR system based on machine learning achieves 99.9% accuracy on the character level, which results with a 50% reduction in the error rate in MRZ extraction.

In order to use new *MrtdRecognizer* or *MrtdCombinedRecognizer* or to continue using any additional *Recognizer for scanning any ID with the MRZ (machine readable zone)* within the latest BlinkID SDK update, you *must* have a new license key. Before updating to the SDK version 4.8.0, please contact your account manager or send an email to support@microblink.com to obtain the *new production license key*.

Important notes:
- The MRTD scanning with the older BlinkID SDK versions (v 4.7.0 and below) will continue to work without any problems - until you decide to update.
- If you upgrade to the SDK version 4.8.0 *without* a new license key scanning of MRTD/MRZ documents will *not* work.
- Contact us at support@microblink.com to obtain a new license key if you plan to update your app with the latest release.

For any questions, you might have, we stand at your service.

- Updates and additions:
    - added support for reading front side of Brunei Military ID - use `MBBruneiMilitaryIdFrontRecognizer`
    - added support for reading back side of Brunei Military ID - use `MBBruneiMilitaryIdBackRecognizer`

- Minor API changes:
    - all recognizers for Serbia have been removed from this version
    - fields that are *not* deprecated anymore:
        - Sweden DL - reference number
        - Ireland DL - driver number
        - Malaysia iKad - passport number
        - Hong Kong ID - commercial code
    - deprecated recocgnizer methods (they have been replaced with properties):
        - `MBUsdlRecognizerResult`:
            - `getField:(MBUsdlKeys)usdlKey`
            - `optionalElements`
    - added new recognizer properties:
        - `MBUsdlRecognizerResult`:
            - `firstName`
            - `lastName`
            - `fullName`
            - `address`
            - `dateOfBirth`
            - `dateOfIssue`
            - `dateOfExpiry`
            - `documentNumber`
            - `sex`
            - `restrictions`
            - `endorsements`
            - `vehicleClass`
        - `MBMrzResult`:
            - `sanitizedOpt1`
            - `sanitizedOpt2`
            - `sanitizedNationality`
            - `sanitizedIssuer`
    - renamed properties in `MBCzechiaCombinedRecognizerResult`:
        - `lastName` to `surname`
        - `firstName` to `givenNames`
        - `identityCardNumber` to `documentNumber`
        - `address` to `permanentStay`
        - `issuingAuthority` to `autohority`
        - `personalIdentificationNumber` to `personalNumber`
    - renamed properties in `MBGermanyCombinedRecognizerResult`:
        - `lastName` to `surname`
        - `firstName` to `givenNames`
        - `identityCardNumber` to `documentNumber`
        - `issuingAuthority` to `autohority`
        - `eyeColour` to `colourOfEyes`
    - renamed properties in `MBJordanCombinedRecognizerResult`:
        - `issuer` to `issuedBy`
    - renamed properties in `MBSlovakiaCombinedRecognizerResult`:
        - `identityCardNumber` to `documentNumber`
        - `issuingAuthority` to `issuedBy`
        - `personalIdentificationNumber` to `personalNumber`
    - renamed properties in `MBRomaniaIdFrontRecognizerResult`:
        - `lastName` to `surname`
        - `identityCardNumber` to `documentNumber`
        - `nonMrzNationality` to `nationality`
        - `nonMrzSex` to `sex`
        - `validFrom` to `dateOfIssue`
        - `validUntil` to `dateOfExpiry`
        - `cardNumber` is now part of `MrzResult` as `documentNumber`
    - renamed properties in `MBSloveniaCombinedRecognizerResult`:
        - `lastName` to `surname`
        - `firstName` to `givenNames`
        - `identityCardNumber` to `documentNumber`
        - `address` to `permanentStay`
        - `issuingAuthority` to `administrativeUnit`
        - `personalIdentificationNumber` to `pin`
        - `citizenship` to `nationality`
    - renamed properties in `MBSloveniaIdBackRecognizerResult`:
        - `issuingAuthority` to `administrativeUnit`
    - renamed properties in `MBPolandCombinedRecognizerResult`:
        - `issuer` to `issuedBy`
    - removed properties in `MBRomaniaIdFrontRecognizer`:
        - `idSeries`
        - `cnp`


## 4.7.0

- Updates and additions:
    - added support for reading front side of Brunei Temporary Residence Permit - use `MBBruneiTemporaryResidencePermitFrontRecognizer`
    - added support for reading back side of Brunei Temporary Residence Permit - use `MBBruneiTemporaryResidencePermitBackRecognizer`
    - added `MBBlinkCardOverlayViewController` to be used with BlinkCard recognizers

- Improvements in ID scanning performance:
    - improved reading accuracy for `MBSingaporeIdBackRecognizer` with stickers
    - enabled reading year-only dates of birth on *Kuwait IDs*
    - all recognizers now reset their results on shake, except Combined recognizers

- Minor API changes:
    - `MBPolandIdBackRecognizerResult` has property `mrzResult` containing the results
    - removed mrz image extraction from `MBMrtdRecognizer` and `mrzImage` property in `MBMrtdRecognizerResult`
    - removed mrz image extraction from `MBMrtdCombinedRecognizer` and `mrzImage` property in `MBMrtdCombinedRecognizerResult`
    - removed glare detection from `MBMrtdCombinedRecognizer`
    - `MBPaymentCardFrontRecognizer`, `MBPaymentCardBackRecognizer` and `MBPaymentCardCombinedRecognizer` have been replaced with `MBBlinkCardRecognizer`
    - `MBElitePaymentCardFrontRecognizer`, `MBElitePaymentCardBackRecognizer` and `MBElitePaymentCardCombinedRecognizer` have been replaced with `MBBlinkCardEliteRecognizer`

- Bugfixes:
    - `MBMrtdRecognizer` result state is now properly invalidated after detection fails
    - templating recognizers no longer execute callbacks with `valid` state once they are `valid` on every frame even if nothing is 'detected'

## 4.6.0

- Updates and additions
    - added support for reading front side of German Driver's License - use `MBGermanyDlFrontRecognizer`
    - added support for reading back side of Brunei ID - use `MBBruneiIdBackRecognizer`
    - added support for reading front side of Brunei Residence Permit - use `MBBruneiResidencePermitFrontRecognizer`
    - added support for reading back side of Brunei Residence Permit - use `MBBruneiResidencePermitBackRecognizer`
    - updated overlay view controllers with new icons for `close` and `torch` buttons
    - switched to using HTTPS in podspec for Cocoapods

- Improvements in ID scanning performance
    - improved reading accuracy for the following recognizers (**DeepOCR** support):
        - `MBMalaysiaMyKadBackRecognizer`

- Minor API changes
    - removed `sex` and `signatureImage` properties from `MBMalaysiaMyKadBackRecognizer`
    - renamed properties in `MBCroatiaCombinedRecognizerResult`:
        - `identityCardNumber` to `documentNumber`
        - `address` to `residence`
        - `issuingAuthority` to `issuedBy`
        - `personalIdentificationNumber` to `oib`
        - `nonResident` to `documentForNonResident`
    - removed `mrzImage` from `MBMrtdCombinedRecognizer` and `MBMrtdCombinedRecognizerResult`
    - renamed properties in `MBAustraliaDlFrontRecognizerResult`:
        - `name` to `fullName`
        - `dateOfExpiry` to `licenceExpiry`
    - renamed `eyeColour` to `colourOfEyes` in `MBGermanyIdBackRecognizerResult`
    - recognizers that are deprecated:
        - `MBSerbiaIdBackRecognizer` and `MBSerbiaIdBackRecognizerResult`
        - `MBSerbiaIdFrontRecognizer` and `MBSerbiaIdFrontRecognizerResult`
        - `MBSerbiaCombinedRecognizer` and `MBSerbiaCombinedRecognizerResult`
    - all properties that are deprecated for recognizers:
        - `MBHongKongIdFrontRecognizerResult`:
            - `commercialCode`
        - `MBIndonesiaIdFrontRecognizerResult`:
            - `bloodType`
            - `district`
            - `kelDesa`
            - `rt`
            - `rw`
        - `MBNewZealandDlFrontRecognizerResult`:
            - `donorIndicator`
            - `cardVersion`
        - `MBMalaysiaMyKadBackRecognizerResult`:
            - `extendedNric`
        - `MBMexicoVoterIdFrontRecognizerResult`:
            - `electorKey`
        - `MBIrelandDlFrontRecognizerResult`:
            - `driverNumber`
        - `MBSwedenDlFrontRecognizerResult`:
            - `referenceNumber`
        - `MBMalaysiaIkadFrontRecognizerResult`:
            - `passportNumber`    
        - `MBAustriaIdBackRecognizerResult`:
            - `principalResidence`
            - `height`
            - `eyeColour`
        - `MBAustriaPassportRecognizerResult`:
            - `height`
         - `MBGermanyIdBackRecognizerResult`:
            - `colourOfEyes`
            - `height`
        - `MBSwitzerlandIdBackRecognizerResult`:
            - `height`
        - `MBSwitzerlandPassportRecognizerResult`:
            - `height`
         - `MBSingaporeIdBackRecognizerResult`:
            - `bloodGroup`
        - `MBColombiaIdBackRecognizerResult`:
            - `bloodGroup`
        - `MBSwitzerlandPassportRecognizerResult`:
            - `height`
        - `MBPolandIdFrontRecognizerResult`:
            - `familyName`
            - `parentsGivenNames`
        - `MBMoroccoIdBackRecognizerResult`:
            - `fathersName`
            - `mothersName`
        - `MBRomaniaIdFrontRecognizerResult`:
            - `parentNames`

## 4.5.0

- Updates and additions
    - added support for reading front side of Brunei ID - use `MBBruneiIdFrontRecognizer`
    - added support for reading front and back side of Cyprus ID, issued after 2015.  - use `MBCyprusIdFrontRecognizer` and `MByprusIdBackRecognizer`
    - added support for reading front side of Malaysian MyKAS - use `MBMalaysiaMyKasFrontRecognizer`
    - added support for reading front side of Malaysian MyPR - use `MBMalaysiaMyPrFrontRecognizer`
    - enabled capturing high resolution camera frames:
        - When custom UI integration is performed, use `- (void)captureHighResImage:(MBCaptureHighResImage)highResoulutionImageCaptured` on `MBRecognizerRunnerViewController`
        - When using provided scan overlay view controllers, high resolution full camera frames taken at the moment of successful scan are returned if this option is enabled through `MBOverlaySettings`. Concrete `MBDocumentOverlaySettings` and `MBDocumentVerificationOverlaySettings` have property `captureHighResImage` to support this feature and new optional delegate on respective delegates

- Improvements in ID scanning performance
    - improved reading accuracy for the following recognizers (**DeepOCR** support):
        - `MBHongKongIdFrontRecognizer`
        - `MBMalaysiaMyKadFrontRecognizer`
        - `MBMalaysiaMyKadBackRecognizer`
        - `MBMalaysiaMyTenteraFrontRecognizer`
        - `MBMalaysiaDlFrontRecognizer`
        - `MBNewZealandDlFrontRecognizer`
    - improved `MBPaymentCard` recognizers:
        - better OCR and data extraction
        - added support for reading payment card numbers in 4x6x4 and 4x6x5 format
    - improveed UAE recognizers:
        - glare detection is enabled for all images returned from `MBUnitedArabEmiratesDlFrontRecognizer`, `MBUnitedArabEmiratesIdBackRecognizer` and `MBUnitedArabEmiratesIdFrontRecognizer` recognizers
    - improved `MBMrtdRecognizer`:
        - added option to set extension factors for full document image: use method `fullDocumentImageExtensionFactors`
        - added option to encode `fullDocumentImage` and `mrzImage` to JPEG and save them to `MBMrtdRecognizerResult`: use `encodeMrzImage` and `encodeFullDocumentImage` to enable encoding

- Minor API changes
    - renamed `MBIkadRecognizer` to `MBMalaysiaIkadFrontRecognizer` and  methods in recognizer and its `Result`:
        - `expiryDate` to `dateOfExpiry `
        - `sex ` to `gender`
    - renamed `MBMyKadFrontRecogniezer` to `MBMalaysiaMyKadFrontRecognizer` and  methods in recognizer and its `Result`:
        - `ownerFullName ` to `fullName`
        - `ownerAddress ` to `fullAddress`
        - `addressStreet ` to `street`
        - `ownerAddressZipCode ` to `zipcode`
        - `ownerAddressCity ` to `city `
        - `ownerAddressState ` to `ownerState`
        - `ownerBirthDate ` to `birthDate`
        - `ownerSex ` to `sex`
        - `ownerReligion ` to `religion`
        - `nricNumber ` to `nric`
    - `MBMalaysiaMyKadFrontRecognizer` does not extract `armyNumber` anymore, use `MBMalaysiaMyTenteraFrontRecognizer` for scanning `MyTentera`
    - `MBMrtdRecognizer`: 
        - method `saveImageDPI` which has been used to set DPI for full document and MRZ image is replaced with methods `fullDocumentImageDpi` and `mrzImageDpi`

    - renamed methods in `MBSwitzerlandIdBackRecognizer` and its `Result`: 
        - `nonMrzDateOfExpiry` to `dateOfExpiry`
        - `nonMrzSex` to `sex`
    - renamed methods in `MBSwitzerlandPassportRecognizer` and its `Result`:
        - `placeOfBirth` to `placeOfOrigin`
        - `nonMrzDateOfBirth` to `dateOfBirth`
        - `nonMrzDateOfExpiry` to `dateOfExpiry`
        - `nonMrzSex` to `sex`

- Bugfixes
    - MBDocumentFaceRecognizer now correctly applies DPI settings to returned face and full document images
    - fixed a crash which happened when scanning region was set before overlay view controller loaded, but after it was initialized
    - fixed missing `init` in `MBDotsResultSubview` for Swift


## 4.4.0

- Updates and additions
    - added support for reading back side of German Driver's License with B10 support - use `MBGermanyDlBackRecognizer`
    - added support for reading front side of Mexican Voter Id card - use `MBMexicoVoterIdFrontRecognizer`
    - added support for reading  ExpiresOn date on `MBCyprusIdBackRecognizer`
    - added support for image(s) anonymization on `MBPaymentCardFrontRecognizer`
        - use `anonymizeCardNumber` and `anonymizeOwner`
    - added support for image(s) anonymization on `MBPaymentCardBackRecognizer`
        - use `anonymizeCvv`
    - added support for image(s) anonymization on `MBPaymentCardCombinedRecognizer`
        - use `anonymizeCardNumber`, `anonymizeOwner` and `anonymizeCvv`
    - added support for image(s) anonymization on `MBElitePaymentCardFrontRecognizer`
        - use `anonymizeOwner`
    - added support for image(s) anonymization on `MBElitePaymentCardBackRecognizer`
        - use `anonymizeCvv` and `anonymizeCardNumber`
    - added support for image(s) anonymization on `MBElitePaymentCardCombinedRecognizer`
        - use `anonymizeCardNumber`, `anonymizeOwner` and `anonymizeCvv`
    - added support for full document image extension factors on `MBUsdlCombinedRecognizer`    

- Improvements in ID scanning performance
    - improved reading of Swiss front side ID cards
    - improved reading of German front side ID cards
    - improved `MBMalaysiaMyTenteraFrontRecognizer` with DeepOcr support
    - improved reading of Singapore front side Driver's Licenses with DeepOcr support
    - improved reading of Croatian front side ID cards
    - improved personal number extraction on Slovakian ID cards
    - improved reading of Indonesian front side ID cards with DeepOcr support
    - updated image return processor 
        - the processor now estimates detected (dewarped) document image quality and returns the best quality dewarped image from the best quality detection

- Minor API changes
    - renamed `MBMyTenteraRecognizer` to `MBMalaysiaMyTenteraFrontRecognizer`
    - renamed `MBMyTenteraRecognizerResult` to `MBMalaysiaMyTenteraFrontRecognizerResult` and properties
        - `nricNumber` to `nric`
        - `ownerAddress` to `fullAddress`
        - `ownerAddressCity` to `city`
        - `ownerAddressState` to `ownerState`
        - `ownerAddressZipCode` to `zipcode`
        - `ownerAddressStreet` to `street`
        - `ownerBirthDate` to `birthDate` and it is now of type `MBDateResult`
        - `ownerFullName` to `fullName`
        - `ownerReligion` to `religion`
        - `ownerSex` to `sex`
    - renamed properties in `MBGermanyIdFrontRecognizerResult`
        - `firstName` to `givenNames`
        - `lastName` to `surname`
        - `dateOfBirth` adn `dateOfExpiry` are now of type `MBDateResult`

- Bugfixes
    - fix memory issue while using current frame grabber
    - fix UI bug on `MBDocumentVerificationOverlayViewController` - now showing `Document scanning done` when scanning finish
    - all combined recognizers are not optional any more in Swift


## 4.3.0

- Updates and additions
    - Added support for reading front side of Ireland Driver's License  - use `MBIrelandDlFrontRecognizer`
    - Added support for reading front side of Colombia Driver's License - use `MBColombiaDlFrontRecognizer`
    - Added support for reading front side of Italy Driver's License - use `MBItalyDlFrontRecognizer`
    - Added standalone recognizer for reading front side of Austria Driver's License - use `MBAustriaDlFrontRecognizer`
    - Added support for reading front and back side of elite Payment / Debit cards - use `MBElitePaymentCardFrontRecognizer`, `MBElitePaymentCardBackRecognizer` and `MBElitePaymentCardCombinedRecognizer`

- Improvements in ID scanning performance
    - improved `MBMrtdCombinedRecognizer`:
        - added option to allow unparsed and unverified MRZ results - use `allowUnparsedResults` and `allowUnverifiedResults`
    - improved `MBMalaysiaDlFrontRecognizer`:
        - added support for reading Malaysia Dl for foreigners 
    - improved `MBUsdlRecogniezr`:
        - added support for reading dates on Nigerian Driver's licenses
    - added support for setting full document image extension factors for almost all ID document recognizers, they implement interface `MBFullDocumentImageExtensionFactors`
    - added support for setting the number of stable detections threshold on `MBDocumentFaceRecognizer` and recognizers which use it internally: `MBMrtdCombinedRecognizer` and `MBUsdlCombinedRecognizer` - use `numStableDetectionsThreshold`. This can help to avoid returning of blurry images.
    - improved `MBEudlRecognizer`:
        - better reading accuracy for UK Driver's license
    - moved these recognizers to DeepOCR engine (improved reading accuracy): `MBSingaporeIdFrontRecognizer`, `MBSingaporeIdBackRecognizer`, `MBCroatiaIdFrontRecognizer`,  `MBCroatiaIdBackRecognizer`
    - improved DeepOCR accuracy

- Minor API changes
    - renamed properties in `MBMalaysiaDlFrontRecognizerResult`:
        - `state` to `ownerState`
        - `zipCode` to `zipcode`
    - renamed properties in `MBIndonesiaIdFrontRecognizerResult`:
        - `validUntil` to `dateOfExpiry`
        - `validUntilPermanent` to `dateOfExpiryPermanent`
    - renamed property in `MBSingaporeIdFrontRecognizerResult`:
        - `bloodType` to `bloodGroup`
    - renamed property in `MBSingaporeCombinedRecognizerREsult`:
        - `bloodType` to `bloodGroup`

- Bugfixes
    - enabled wrapping of combined recogniezrs with `MBSuccessFrameGrabberRecognizer`
    - fixed bug in `MBEudlRecognizer` which caused that sometimes face image is not returned, even if the recognition was successful
    - updated overlay view controllers for iPhone X Series
    - various other bug fixes and improvements

## 4.2.0

- Updates and additions
    - Added support for reading front side of Spain Driver's License - use `MBSpainDlFrontRecognizer`
    - Added support for reading front side of UAE Driver's License - use `MBUnitedArabEmiratesDlFrontRecognizer`
    - Added support for reading front side of Cyprus ID card - use `MBCyprusIdFrontRecognizer`
    - Added support for reading back side of Cyprus ID card - use `MBCyprusIdBackRecognizer`
    - Added support for reading front side of Kuwait ID card - use `MBKuwaitIdFrontRecognizer`
    - Added support for reading back side of Kuwait ID card - use `MBKuwaitIdBackRecognizer`
    - Added support for reading front side of Payment Card - use `MBPaymentCardFrontRecognizer`
    - Added support for reading back side of Payment Card - use `MBPaymentCardBackRecognizer`
    - Added support for reading front and back side of Payment Card - use `MBPaymentCardCombinedRecognizer`
    - Added support for optional protocol method implementation in `MBDocumentVerificationOverlayViewControllerDelegate` - `documentVerificationOverlayViewControllerDidFinishScanningFirstSide:`

- Improvements in ID scanning performance
    - Added support for reading sticker with new address on back side of Singapore ID card with `MBSingaporeCombinedRecognizer`
    - Performance improvements

- Minor API changes
    - Renamed properties in `MBCroatiaIdBackRecognizerResult`:
        - `address` to `residence`
        - `documentForNonResident` to `isDocumentForNonResident`
        - `issuingAuthority` to `issuedBy`
        - MRZ fields are available through `MBMrzResult` which can be obtained by using property `mrzResult`
    - Renamed properties in `MBSingaporeIdFrontRecognizerResult`:
        - `cardNumber` to `identityCardNumber`
    - Renamed properties in `MBSingaporeCombinedRecognizerResult`:
        - `cardNumber` to `identityCardNumber`
        - `bloodGroup` to `bloodType`
    - `isScanningUnsupportedForCameraType:` is now class method of `MBMicroblinkSDK`    

- Bugfixes
    - Fixed bug where SDK crashed with exception when the user wanted to use custom resource bundle
    - Various other bug fixes and improvements

## 4.1.0

- Updates and additions
    - Added support for reading front side of Swiss Driver's License - use `MBSwitzerlandDlFrontRecognizer`
    - Added support for reading front side of Singapore Driver's License - use `MBSingaporeDlFrontRecognizer`
    - Added support for reading front side of Morocco ID card - use `MBMoroccoIdFrontRecognizer`
    - Added support for reading back side of Morocco ID card - use `MBMoroccoIdBackRecognizer`
    - Added support for reading Singapore Changi Employee ID card - use `MBSingaporeChangiEmployeeIdRecognizer`
    - Added support for reading residential status on front side of Hong Kong ID Card
    - Added support for reading partial dates on all MRTD documents
    - Added support for returning encoded images on all recognizers that support image return
    - Added support for checking if scanning is unsupported for camera type on `MBRecognizerRunnerViewController`
    - Added support for reading sticker with new address on back side of Singapore ID card
    - Added missing `oldNric` property on `MBMyKadBackRecognizerResult`
    - Removed manatee 

- Improvements in ID scanning performance
    - Improved reading of New Zealeand Driver's License
    - Better name and nationality extraction on `MBUnitedArabEmiratesIdFrontRecognizer`

- Minor API changes
    - `identityCardNumber` property has been renamed to `documentNumber` on `MBCroatiaIdFrontRecognizerResult`

## 4.0.1

- Bugfixes
    - Calling  `reconfigureRecognizers` before showing camera now correctly applies supplied recognizers
    - Fixed autorotation of overlays and `MBRecognizerRunnerViewController`
    - Fixed localization issues with some overlays
    - Fixed constraint errors on `MBDocumentVerificationOverlayViewController`
    
- Updates and additions
    - Added  `reconfigureRecognizers` method to `MBBaseOverlayViewController`, enabling it on all it's subclasses

## 4.0.0

- new API, which is not backward compatible. Please check [README](README.md) and updated demo applications for more information, but the gist of it is:
    - `PPScanningViewController` has been renamed to `MBRecognizerRunnerViewController` and `MBCoordinator` to `MBRecognizerRunner`
    - `PPBarcodeOverlayViewController` has been renamed to `MBBarcodeOverlayViewController`
    - previously internal `MBRecognizer` objects are not internal anymore - instead of having opaque `MBRecognizerSettings` and `MBRecognizerResult` objects, you now have stateful `MBRecognizer` object that contains its `MBResult` within and mutates it while performing recognition. For more information, see [README](README.md) and updated demo applications
    - introduced `MBFieldByFieldOverlayViewController` that can be used for easy integration of the _field-by-field scanning_ feature (previously known as _segment scan_)
    - introduced `MBDocumentVerificationController` that can be used for easy integration of _ID verification scanning_ feature (previously available only in [BlinkID AppStore app](https://itunes.apple.com/us/app/blinkid/id1258136557?mt=8)
    - introduced `MBProcessor` concept. For more information, check updated code samples, [README](README.md) and [this blog post](https://microblink.com/blog/major-change-of-the-api-and-in-the-license-key-formats)
- new licence format, which is not backward compatible. Full details are given in [README](README.md) and in updated applications, but the gist of it is:
    - licence can now be provided with either file, byte array or base64-encoded bytes

## 2.18.2

- Bugfixes
    - fixed `UnitedArabEmiratesIDBackRecognizer`:
        - enabled reading of UAE back side where MRZ starts with IR

## 2.18.1

- Bugfixes
    - `coordinatorDidDealloc` method in `PPCoordinatorDelegate` is now correctly called when all resources are released

## 2.18.0

- Updates and additions
    - Added support for reading front side of Swedish Driver's License- use `PPSwedenDLFrontRecognizerSettings`
    - Added ability to extend full document cropping zone on `PPGermanIDFrontRecognizerSettings`
    - Added support for CAN number extraction on German ID Front
    - Added support for iKAD MM55 ID's

- Improvements in ID scanning performance
    - Improved reading of document number on Hong Kong ID
    - Improvements when returning partial data in Document Face Recognizer
    - Improvements in USDL data parsing

## 2.17.3

- Bugfixes
    - Added support for nonstandard pdf417 barcodes  which wrongly encode number of data codewords

## 2.17.2

- Bugfixes
    - Fixed error where app upload to the store would be rejected because of missing bitcode

## 2.17.1

- Bugfixes
    - Fixed errors related to fetching document number from Egyptian ID
    - Fixed errors related to fetching validFrom and validUntil dates from Malaysian DL
    - Fixed errors related to returning and encoding face and full document images when using `PPJordanIDCombinedRecognizerSettings`
    - Fixed dateOfExpiry property type from `NSString` to `NSDate` on  `PPJordanIDCombinedRecognizerSettings`

## 2.17.0

- Updates and additions
    - added support for reading front and back side of Jordan ID - use `PPJordanIDFrontRecognizerSettings` and `PPJordanIDBackRecognizerSettings`
    - added Jordan Combined Recognizer - use `PPJordanIDCombinedRecognizerSettings`
    - added support for reading Egyptian ID Front - use `PPEgyptIDFrontRecognizerSettings`
    - added support for reading Malaysian DL Front - use `PPMalaysianDLFrontRecognizerSettings`
    - added support for reading Malaysian Passport IMM13P MRTD - be sure to set `allowSpecialCharacters` to `true` when creating `PPMrtdRecognizerSettings`
    
- Improvements in ID scanning performance
    - Improved reading Malaysian MyKad and MyTentera
    - Improved reading VINs
    - Improved parsing of USDL
    
- Bugfixes
    - fixed returning of face image when using `PPUnitedArabEmiratesIDFrontRecognizer`:
        - fixed face image position
    - fixed crash in `PPDocumentFaceRecognizer`
    - Fixed expiry date for magnetic stripe USDL subtype - using day of birth not last day of the month for license expiry day
    - Fixed rare crashes that sometimes happened when trying to fetch unparsed dates
    - fixed crashes that happened when trying to activate the torch while video input hasn't loaded

## 2.16.1

- Bugfixes
    - fixed incorrect setting of missing dates to current date in MRTD recognizers. If date is not present in MRTD, the corresponding getter will now return nil
    - fixed an error where disabling extraction of some elements on  `PPNewZealandDLFrontRecognizerSettings`  did not work correctly

## 2.16.0

- Updates and additions
	- added support for reading front side of Hong Kong ID - use `PPHongKongIDFrontRecognizerSettings`
	- added support for reading front and back side of Colombian ID - use `PPColombiaIDFrontRecognizerSettings` and `PPColombiaIDBackRecognizerSettings`
	- added support for reading front and back side of United Arab Emirates ID - use `PPUnitedArabEmiratesIDFrontRecognizerSettings` and `PPUnitedArabEmiratesIDBackRecognizerSettings`
	- added support for reading front side of New Zealand drivers license - use `PPNewZealandDLFrontRecognizerSettings`
	
- Improvements in ID scanning performance
	- Improved reading of Belgium ID BRZ OPT2 field
	- added support for reading Belgium MRZ with partial date of birth - `PPMrtdRecognizerSettings.allowUnverifiedResults` must be set to `true`
	- added support for reading Kenya MRZ - `PPMrtdRecognizerSettings.allowUnverifiedResults` must be set to `true`
	- improved `MyKadFrontSideRecognizer` and `MyTenteraRecognizer`:
		- better reading of name field
		- better reading of address field

- Bugfixes	
	- when setting DPI for full document image in concrete recognizer settings that has property `fullDocumentImageDPI`, exception is thrown if DPI value is not in the expected range `[100, 400]`
	- fixed a crash in Templating API caused by using a `MultiDetector` with `DetectorRecognizer`
        - fixed returning of face image when using `PPUnitedArabEmiratesIDFrontRecognizer`:
            - fixed face image position

## 2.15.0

- Updates and additions
    - added support for reading back side of Malaysian MyKad - use `PPMyKadBackRecognizerSettings` 
    - added support for reading Malaysian MyTentera documents - use `PPMyTenteraRecognizerSettings`
    - added support for reading Malaysian MyTentera documents with MyKad recognizer - use `PPMyKadFrontRecognizerSettings` and enable reading of army number 
    - added support for setting DPI for full document images returned by `PPMyKadFrontRecognizerSettings`, `PPMyKadBackRecognizerSettings`, `PPMyKadFrontRecognizerSettings` and `PPIKadRecognizerSettings`:
    - use `fullDocumentImageDPI` on the corresponding recognizer settings
    - added full support for iPhone X layout for all SDK's overlay views

- Minor API changes
    - renamed `PPMyKadRecognizerSettings` and `PPMyKadRecognizerResult` to `PPMyKadFrontRecognizerSettings` and `PPMyKadFrontRecognizerResult`

- Improvements in ID scanning performance
    - improved `PPAustraliaDLFrontRecognizer`:
        - improved reading of names and addresses
        - added support for reading first names with more words
    - improved `PPSingaporeIDFrontRecognizer`:
        - tuned ID card data extraction positions
    - improved Malaysian `IKadRecognizer`:
        - better reading of date of expiry and employer fields

- Bugfixes
    - fixed crash in `PPDocumentFaceRecognizer`
    - added missing document classifier property `documentClassifier` to `PPTemplatingRecognizerSettings`         

## 2.14.0

- Updates and additions
    - added support for reading back side of new Australian Driver's licence for state Victoria - use `PPAustraliaDLBackRecognizerSettings` and `PPAustraliaDLBackRecognizerResult`
    - added support for reading front side of Indonesian ID - use `PPIndonesianIDFrontRecognizerSettings` and `PPIndonesianIDFrontRecognizerSettings`
    - added support for Malaysian visa with document code TS - use `PPMrtdRecognizerSettings` and `PPMrtdRecognizerResult`
    - added support for setting DPI for full document images returned by `PPMrtdRecognizerSettings`, `PPAustraliaDLBackRecognizerSettings`, `PPAustraliaDLFrontRecognizerSettings` and `PPEudlRecognizerSettings`:
        - use `fullDocumentImageDPI` on the corresponding recognizer settings

- Minor API changes
    - removed `imageDPI` property on `PPTemplatingRecognizerSettings`        

- Improvements in ID scanning performance:
    - improved reading of Malaysian MyKad address        

## 2.13.0

- Updates and additions
    - added support for scanning front and back side of Polish ID - use `PPPolishIDFrontRecognizerSettings`, `PolishIDBackRecognizerSettings` and `PPPolishIDCombinedRecognizerSettings`
    - new document specification presets in `PPDocumentPreset` enum:  `PPDocumentPresetId1VerticalCard` and  `PPDocumentPresetId2VerticalCard` - use `[PPDocumentSpecification newFromPreset]` method to create document specification for detector
    - `PPEudlRecognizer` can return face image from the driver's license
    - warning for time limited license keys when using provided activities, custom UI integration or Direct API:
        - the goal is to prevent unintentional publishing of application to production with the demo license key that will expire
        - warning toast can be disabled by using `showLicenseKeyTimeLimitedWarning` property on `PPUiSettings`
    - added `PPMrtdSpecification` and method `setMrtdSpecifications` on `PPMrtdDetectorSettings`
        - setting `PPMrtdSpecification` on `PPMrtdDetectorSettings` will return results only for specified MRTD Documents
        - `PPMrtdSpecification` can be created using `PPMrtdPreset`: `PPMrtdPresetTd1, PPMrtdPresetTd2, PPMrtdPresetTd3`

- Minor API changes
    - `PPDocumentDetectorResult` does not contain information about screen orientation any more

- Improvements in ID scanning performance:
    - improved face detection in `DocumentFaceRecognizer`: stable detection is required to prevent returning of blurred images
    - improved reading of Malaysian `MyKad` documents:
    - improved reading and parsing of address fields: previously recognizer was unable to read some documents because of the expected address format
    - improved reading of Malaysian visas and work permits
    - better reading of dates on Australian Driver's Licence

## 2.12.0

- Updates and additions
    - Added Australian Driver Licence Recognizer `PPAustraliaDLFrontRecognizerResult` and `PPAustraliaDLFrontRecognizerSettings` for state Victoria
    - Added Swiss ID Back Recognizer `PPSwissIDBackRecognizerResult` and `PPSwissIDBackRecognizerSettings`
    - Added Swiss ID Front Recognizer `PPSwissIDFrontRecognizerResult` and `PPSwissIDFrontRecognizerSettings`
    - Added reading of mirrored QR codes
    - Added `PPMrzFilter` protocol and delegate `mrzFilter` on `PPMrtdRecognizerSettings`
        - Determines whether document should be processed or it is filtered out, based on its MRZ (Machine Readable Zone)
    - Introduced `GlareDetector` which is by default used in all recognizers whose settings implement `GlareDetectorOptions`:
        - When glare is detected, OCR will not be performed on the affected document position to prevent errors in the extracted data
        - If the glare detector is used and obtaining of glare metadata is enabled in `MetadataSettings`
        - Glare detector can be disabled by using `detectGlare` property on the recognizer settings
    - Added `PPQuadDetectorResultWithSize` which inherits existing `PPQuadDetectorResult`
        - It's subclasses are `PPDocumentDetectorResult` and `PPMrtdDetectorResult`
        - Returns information about physical size (height) in inches of the detected location when physical size is known

- Minor API changes
    - `PPBlinkOcrRecognizerResult` and `PPBlinkOcrRecognizerSettings` are now deprecated. Use `PPDetectorRecognizerResult` and `PPDetectorRecognizerSettings` for templating or `PPBlinkInputRecognizerResult` and `PPBlinkInputRecognizerSettings` for segment scan
    - removed option to scan 1D Code39 and Code128 barcodes on US Driver's licenses that contain those barcodes alongside PDF417 barcode

- Bugfixes:
    - Fixed crash which sometimes happened while scanning MRTD documents
    - Fixed returning valid data for MRZ based recognizers when not all fields outside MRZ have been scanned
    - Fixed crash in QR code which happened periodically in all recognizers
    - Fixed autorotation of overlay view controller 
    - Fixed scanning return result type of `PPDetectorRecognizerSettings` when initialized with `PPMrtdDetectorSettings` - returning `PPMrtdDetectorResult`

- Improvements in ID scanning performance:
    - Date parsing improvements
    - Better extraction of fields on back side of the Croatian ID card
    - Improved reading of issuing authority on Croatian ID back side
    - Improved USDLRecognizer - added support for new USDL standard

## 2.11.0

- Updates and additions
    - Added Austrian Passport Recognizer `PPAusPassportRecognizerResult` and `PPAusPassportRecognizerSettings`
    - Added Swiss Passport Recognizer `PPSwissPassportRecognizerResult` and `PPSwissPassportRecognizerSettings`
    - Added support for scanning MRZ on Mexican voters card
    - Added support for reading Croatian ID with permanent DateOfExpiry in `PPCroIDFrontRecognizerResult` and `PPCroIDCombinedRecognizerResult` with BOOL property `isDocumentDateOfExpiryPermanent`
    - Added combining data from MRZ and fields in Austrian passport through `PPAusIDCombinedRecognizerResult` and `PPAusIDCombinedRecognizerSettings`

- Bugfixes:
    - Fixed crash which sometimes happened while scanning MRTD documents

- Improvements in ID scanning performance:
    - Improved scanning of IKad addresses
    - Improved reading of Croatian ID Address field
    - Improved reading of Croatian ID IssuedBy field 

## 2.10.0

- Updates and additions:
    - Added Barcode Recognizer `PPBarcodeRecognizerResult` and `PPBarcodeRecognizerSettings`
    - Deprecated `PPAztecRecognizerResult` and `PPAztecRecognizerSettings`. Use Barcode Recognizer
    - Deprecated `PPBarDecoderRecognizerResult` and `PPBarDecoderRecognizerSettings`. Use Barcode Recognizer
    - Deprecated `PPZXingRecognizerResult` and `PPZXingRecognizerSettings`. Use Barcode Recognizer
    - Added creation of customized build of framework. If your final app size is too large, you can create a customised build of MicroBlink.framework and MicroBlink.bundle which will contain only features and resources that you really need. You can see detailed explanation at [Creating customized build of BlinkID SDK](https://github.com/BlinkID/blinkid-ios/wiki/Creating-customized-build)
    - Added US Driver's license Combined Recognizer `PPUsdlCombinedRecognizerResult` and `PPUsdlCombinedRecognizerSettings` 
    - Added Austrian ID Combined Recognizer `PPAusIDCombinedRecognizerResult` and `PPAusIDCombinedRecognizerSettings`
    - Added Czech ID Combined Recognizer `PPCzIDCombinedRecognizerResult` and `PPCzIDCombinedRecognizerSettings`
    - Added Serbian ID Combined Recognizer `PPSerbianIDCombinedRecognizerResult` and `PPSerbianIDCombinedRecognizerSettings`
    - Added Singapore ID Combined Recognizer `PPSingaporeIDCombinedRecognizerResult` and `PPSingaporeIDCombinedRecognizerSettings`
    - Added Slovakian ID Combined Recognizer `PPSlovakIDCombinedRecognizerResult` and `PPSlovakIDCombinedRecognizerSettings`
    - Added Slovenian ID Combined Recognizer `PPSlovenianIDCombinedRecognizerResult` and `PPSlovenianIDCombinedRecognizerSettings`
    - Added MRTD Combined Recognizer `PPMrtdCombinedRecognizerResult` and `PPMrtdCombinedRecognizerSettings`
    - Added VIN Recognizer `PPVinRecognizerResult` and `PPVinRecognizerSettings`
    - Added `nonMRZNationality` and `nonMRZSex` properties to Romanian ID Recognizer for getting sex and nationality outside MRZ
    - Added support for long addresses and employer names for iKad
    - `extractAddress` property in `PPSlovakIDBackRecognizerSettings` is now removed since previously wasn't used
    - Added `extractDocumentNumber` property in `PPSlovakIDFrontRecognizerSettings` for defining if issuing document number should be extracted from Slovakian ID 
    - Added to Slovakian ID Combined Settings options properties:
        - `extractSex`
        - `extractNationality`
        - `extractDateOfBirth`
        - `extractDateOfExpiry`
        - `extractDateOfIssue`
        - `extractIssuedBy`
        - `extractDocumentNumber`
        - `extractSurnameAtBirth`
        - `extractPlaceOfBirth`
        - `extractSpecialRemarks`

- Bugfixes:
    - Fixed reading positions of ID elements on Slovakian ID card
    - Fixed reading positions of ID elements on Singapore ID card

- Improvements in ID scanning performance:
    - Always read personal number field on front side of Slovakian ID card
    - Improved reading precision of address, place of birth, last name and issuing authority on Slovakian ID card
    - Improved reading of name and blood type on Singapore ID card
    - Improved reading of pdf417 barcodes having width:height bar aspect ratio less than 2:1

## 2.9.0

- Updates and additions:
    - Microblink.framework is now a dynamic framework. The change is introduced because of the following reasons:
        - isolation of code
        - smaller binary size - roughly 38%
    - Improved Screen shown when Camera permission is not granted:
        - fixed crash which happened on tap anywhere on screen
        - close button can now be removed (for example, if the scanning screen is inside `UINavigationController` instance)
        - Header is now public so you can instantiate that class if needed
    - Updated PPUiSettings with new features:
        - flag `showStatusBar` which you can use to show or hide status bar on camera screen 
        - flag `showCloseButton` which you can use to show or hide close button on camera screen. By default it's presented, but when inside `UINavigationController` it should be hidden
        - flat `showTorchButton` which you can use to show or hide torch button on camera screen.
    - Deprecated `PPHelpDisplayMode`. You should replace it with a custom logic for presenting help inside the application using the SDK.
    - Renamed internal extension method with namespace so that they don't interfere with third party libraries
    - Added standard tap to focus overlay subview in all default OverlayViewControllers. Also added it as a public header.
    - PPScanningViewController now has a simple method to turn on torch
    - Simplified `PPOcrLayout` class (removed properties which were not used)
    - Updated PPTopUpOcrParserFactory with new feature:
        - flag `returnCodeWithoutPrefix` which does not return *digits* prefix and # at the end of scanned ussd code
    - Updated PPMrtdRecognizerSettings with new feature:
        - flag `allowUnverifiedResults` which allow obtaining results with incorrect check digits

- Bugfixes:
    - Fixed case sensitivity in class & file naming
    - Fixed issue which sometimes caused scanning not to be started when the user is asked for camera permission (first run of the app)
    - Fixed rare crash which Camera paused label UI being updated on background thread
    - Fixed incorrect handling of camera mirror when using front facing camera
    - Fixed crash which sometimes happened when presenting help screens (if `PPHelpDisplayModeAlways` or `PPHelpDisplayModeFirstRun` were used)

 - Improvements in ID scanning performance:
     - added PPGermanIDCombinedRecognizer which enables reading of all data contained on German passports, old and new IDs 
     - Improvements in MRTD scanning:
        - WSA (World Goverment of World Citizens) added as valid country code when parsing MRZ 
    - Added option of encoding images of MRZ and full document in Machine readable travel documents and encoding of images in DocumentFaceRecognizer
    - Handling names containing dashes and extra long names inside combined recognizers     
    
## 2.8.0

- Improvements in iOS SDK: 
    - Reduced library size by more than 20%
    - Fixed case sensitivity in class & file naming
    - ID result classes which have Date fields now return both parsed `NSDate` and raw `NSString`
- Improvements in scanning:
    - TopUp scanning improvements
    - Restructured German ID recognizers into:
        - GermanIDFrontRecognizer, for scanning front side of the new German ID
        - GermanIDBackRecognizer, for scanning back side of the new German ID
        - GermanOldIDRecognizer, for scanning front side of the old German ID
        - GermanPassportRecognizer, for scanning front side of the German Passport
    - Splitting address on new German IDs to ZIP code, city, street and house number
    - Added name and surname dictionaries for the German ID front side recognizer which improves the scanning performance
    - MyKadRecognizer now knows how to split address to street, ZIP code, city and state
    - Improved CroIDCombinedRecognizer, which can scan both sides of the ID consecutively 
    - Added support for polish IBAN without PL prefix in PPIbanParser
    - Improvements in CroID scanning, use multiple scans to boost confidence
- Improvements in Samples:
    - Added MicroBlinkDynamic sample which packages our static library into a dynamic framework
    - Added libz to all samples to prevent linker errors (caused by slimming down the SDK)

## 2.7.1

- Fixed wrong Assertion which didn't allow usage of custom Resources bundle. 
- Fixed internal bug which caused crashes if `PPCoordinator applySettings` was called with the same Recognizer settings (this is a very rare use case)
- Added working license key in pdf417-sample for Aztec scanning

## 2.7.0

- Added Romanian ID Front recognizer for scanning Romanian IDs.
- Added SimCardRecognizer for scanning barcodes on Sim Cards
- Added AztecRecognizer with state of the art Aztec barcode reading. This can be used for scanning digital boarding passes, train tickets, and many more use cases.
- Added play success sound method to `PPScanningViewController` protocol
- Added designated initializers to all `PPOcrParserFactory` objects
- Added ID2 preset for creating DocumentSpecifications
- Improved getters for image names which are used to get Images of the ID documents
    - they are now static methods instead of instance properties
- Improved `MRTDRecognizer` with better support for Arab MRZ
- Improved TopUpParser
    - Added Generic parsing in TopUpOcrParser
- Updated `CroatianIDFrontSideRecognizer`: returning sex as written on front side of a document
- Fixed issue with Direct API which disabled processing
- Fixed issue with blurred camera display when `PPCoordinator` instance was reused between consecutive scanning sessions
- Fixed crashed which happened when multiple instances of `PPCoordinator` were used simultaneously (one being terminated and one starting recognition). This most commonly happened when after scanning session, a new view controller was pushed to a Navigation View Controller, when the user repeated the procedure a number of times (five or more).
- Updated sample apps:
    - Updated Detector-sample to use frame quality so that dewarped images are the sharpest
    - Updated BlinkID-sample and BlinkID-Swift-sample with easier obtaining of dewarped images
    - Updated DirectAPI-sample with support for OCR in all device orientations
    - Updated pdf417-sample with support for Aztec scanning
    - Added AutodetectID-sample which uses DocumentFace recognizer
- Internal switch to new build system using cmake. This allows faster deployments and easier updates in the future. 

## 2.6.0

- Added CroIDCombined recognizer which can scan both sides consecutively
- Added DocumentFace recognizer which can be used to get the image of the ID document which contains a face
- Added FaceDetector feature which can now be used in DetectorRecognizer.
- Added support for extracting place of birth on old German IDs
- Added property allowResultForEveryFrame in PPScanSettings which can be used when using Direct API to force calling didOutputResults: callback for every frame
- Added feature to enable frame quality estimation when using Direct API (by exposing property estimateFrameQuality)
- Added support for scanning IBAN from Georgia in IbanParser
- Added logging of the SDK name when the license key is invalid for easier troubleshooting
- Added Belgian account number check to IBAN parser
- Added scaling of the default viewfinder in ID scanning overlay view
- Added a property which you can use to set a custom location for resources. For example, if you would like to avoid using Microblink.bundle as resources bundle, you can set a different one in PPSettings object.
- Improved quality of German ID address recognition
- Updated - Singapore ID recognizer has now split in two recognizers - one for front and one for back side
- Fixed Date of Birth scanning issue in MyKad Recognizer
- Fixed MRTD returning payment data with verified = false when mrtdSettings.allowUnverified(false)
- Fixed bug in MRTD recognizer where mrtd image were not returned although scanning was successful
- Fixed crash when Single dispatch queue was used for processing
- Fixed frame quality issue in PPimageMetadata. Previously it was always nan if used after image getter.
- Fixed Torch button on default camera overlays. Previously it never changed state after it was turned on.
- Fixed help display mode "First run", which previously didn't work
- Fixed crash when the user tapped anywhere on the view controller presented when camera permission wasn't allowed
- Fixed warning message when language is set to something other than @en, @de and @fr and @cro
- Fixed crash on start in swift if custom UI was used to handle detector results
- Fixed a problem which caused internal recognizer state not to be reset when using the scanner for the second time with the same PPCoordinator instance
- Fixed ocrLayout getter in PPBlinkOcrRecognizer which previously returned nil
- Fixed an issue which caused camera settings to be reset each time PPCoordinator's applySettings method was called. This issue manifested, for example, by automatically turning off torch after successful scan in SegmentScan.
- Fixed redundant log warnings in setting language ("Trying to set language to nil, returning") and Camera manager ("Should not have been observing autofocus")

## 2.5.1

- Updated default overlay UI for ID scanning
- Fixed nullability annotations in result classes. Now, wherever the `nil`value is allowed, it means no data exists on the scanned document. If an empty string `@""` is returned, this means the field exist, but it's empty. 
- Croatian ID scanning now uses dictionary for issuing authority for higher accuracy
- Improved generic Amount and IBAN parsers

## 2.5.0
- US Driver's Licence:
    - fixed parsing of Virgin Islands DL
    - added support for Arkansas DL
    - added support for new South Carolina DL
- Malaysian ID:
    - added support for returning face image
    - fixed wrong parsing of birth date
    - added support for scanning Malaysian iKad documents
- `PPDateOcrParser` returns result as `NSDate` object and as original date `NSString`
- added methods `specificParsedResultForName:` and `specificParsedResultForName:parserGroup:` to `PPTemplatingRecognizerResult` (`PPBlinkOcrRecognizerResult `) which returns specific parser results, e.g. `NSDate` for `PPDateOcrParser`
- added support for scanning front and back side of Serbian ID cards
- improved IBAN parser
- `PPMrtdRecognizerResult` now returns date of expiry and date of birth as `NSDate` instead of `NSString`
- all recognizer results (classes that derive `PPRecognizerResult`) now have annotated nullability for their getters. Some of them used to assume non-null, while still returning `nil` sometimes. This has now been corrected and all getters are `_Nullable`

## 2.4.0

- iOS updates:
	- Aded Slovenian ID recognizer
	- Added parser for mobile coupons
	- Added frame quality property to PPImageMetadata
- iOS bugfixes:
	- Fixed issue where Templating API wasn't working as expected on some devices.

## 2.3.0

- iOS updates:
	- Added German ID recognizer
	- Added Slovakian ID recognizer
	- Improved performance of Croatian ID recognizer

## 2.2.1

- iOS fixes:
	- Fixed problems with string localizations
	
## 2.2.1

- iOS fixes:
	- CFBundleSUpportedPlatforms removed from Info.plist files
	- Applying affine transformation to `PPQuadrangle` now correctly assigns points.
	- When using both Direct API and `PPCameraCoordinator`, scanning results will now be correctly outputted to `PPCoordinatorDelegate` and `PPScanningDelegate` respectively
	- Fixed crashes related to camera permissions and added dummy view when camera permission is disabled
	- Fixed issues related to topLayoutGuide on iOS6
	- Improved performance of CroID recognizers
	- USDL elements can now be separated by \r
	- Improved performance of Date parser

## 2.2.0

- iOS updates:
	- Added recognizer for Singapore ID
	- Added recognizer for Austrian ID
	- Added recognizer for Czech ID
	
- iOS bugfixes:
	- PPOcrEngineOptions are now applyed correctly when set

## 2.1.0

- iOS updates:

	- Added option to mirror camera frames in 'PPCameraSettings'
	- Added VIN parser
	
- iOS bugfixes
	- Fixed deadlock when 'processImage:' is called from main thread

## 2.0.0

- BlinkID now includes BlinkOCR and all it's features

- iOS updates:

	- Implemented `PPCameraCoordinator`. `PPCameraCoordinator` assumes the role of `PPCoordinator` from previous versions while new `PPCoordinator` is used for Direct API (image processing without camera out management).
	- Increased speed of scanning for barcode type recognizers.
	- Implemented `PPImage`. When using Direct API you can wrap `UIImage` and `CMSampleBufferRef` into `PPImage` to ensure optimal performance.
	- Improved performance of Direct API. In addition, you can now use Direct API with your own camera management without any performance drawbacks.
	- Added method `isCameraPaused` to `PPScanningViewController`.
	- Added option to fllip input images upside down for processing with `cameraFlipped` property of `PPCameraSettings`.
	- Implemented `PPViewControllerFactory` for managing creation of `PPScanningViewController` objects.
	- `PPImageMetadata` now contains `PPImageMetadataType` property, which describes which image type was outputted.

- Implemented templating API

    - Templating API allows creation of custom document scanners, linking specific parsers to specific locations on detected documents
	
- iOS bugfixes:
	- New Direct API fixed possible deadlocks when sending large amounts of data

## 1.4.0

- iOS bugfixes:

    - Fixed possible deadlock in some cases when MRTD documents are scanned.
    - Fixed issue with OCR speed on arm7 devices when Accelerate framework was used.
    - Fixed incorrect returning of Address and License number in UKDL scanning.
    
- iOS updates:
    
    - PPOverlayViewController changed the way Overlay Subviews are added to the view hierarchy. Instead of calling `addOverlaySubview:` (which automatically added a view to view hierarachy), you now need to call `registerOverlaySubview:` (which registers subview for scanning events), and manually add subview to view hierarchy using `addSubview:` method. This change gives you more flexibility for adding views and managing autolayout and autoresizing masks.

    - Localization Macros MB_LOCALIZED and MB_LOCALIZED_FORMAT can now be overriden in your app to provide completely custom localization mechanisms.
    
    - Dramatically increased OCR engine initialization speed

    - Increased speed of scanning cancellation when Cancel button is pressed.
    
- ID scanning improvements

    - Added EUDL recognizer (replaced UKDL recognizer). EUDL is capable of automatically detecting various EU Drivers licenses. Currently it works only on German and UK DLs.
    - Fixed issue with 0 and O misclassifications in MRTD recognition
    - Added support for Austrian MRTD ID documents

- Internal changes:

    - Implementeded Templating API for easier implementation of new document types
    - Implemented Face detection
    - Implemented support for Eastern Arabic numeral characters

## 1.3.0

- Added better integration for Swift

    - Added Nullability Attributes
    - Added modulemap file
    - Added sample app in Swift
        
- Added recognizers for scanning barcodes

    - for scanning PDF417 barcodes, use PPPdf417Recognizer
    - for scanning Code128 and Code39 barcodes, use PPBarDecoderRecognizer
    - for scanning QR codes, and other barcode types, use PPZxingRecognizer
        
- Refactored `PPMetadataSettings` 

    - Added debug metadata settings for debugging payslip detection and image processing
    - `successfulScanFrame` renamed to `successfulFrame`
    - `currentVideoFrame` renamed to `currentFrame`
    
- Exposed `PPModernViewfinderOverlaySubview` overlay subview class in public headers. This enables you to more easily recreate default overlay UI in your custom Overlay view controllers.

- Added *Detector API*, a completely new feature which enables you to detect various document types on images. Detector API allows two types of document detections

    - MRTD detection (based on OCR line detection, for MRTD documents like passports, visas, ...)
    - Document Detection (based on edge detection, for ID cards, plastic cards, credit cards, ...)
    
- in `PPCoordinator`, renamed method `isScanningUnsupported:` to `isScanningUnsupportedForCameraType:error:`. This was introduced to provide more granularity in checking if scanning is supported.

- Fixed issues in obtaining images in scanning, most notably in MyKad scanning.

- Fixed issues with Direct API processing of UIImages in some orientations

- Fixed issues with scanning MRZ lines on arm7 devices.

## 1.2.0

- Added recognition of Malysian ID cards (MyKads). To use MyKad recognition initialize the scanning library using `PPMyKadRecognizerSettings`

- Improvements in UK drivers license recognition. BlinkID is now tested on many more UKDL samples and yields much higher recognition rate.

- Improvements in MRTD recognition. Errors such as '0' and 'O' confusions should no longer happen. Improved MRTD document detection algorithm, which now makes old "fixed" recognition redundant. Because of that, the feature to define `mrtdRoi` is now removed.

- Added feature to obtain cropped and trimmed image of the whole MRTD document.

- Fixed several issues in USDL parsing
        - implemented special cases for barcodes which don't have keys according to the AAMVA version written in the barcode
        - implemented heuristics for extraction of firstName, middleName, lastName, address, and other fields, if they can be determined based on the other fields.

- Bugfixes and tweaks in camera management code
        - fixed potential deadlock when multiple instances of `PPCoordinator` objects are instantiated.
        - exiting from the scanning when user presses "cancel" button is now faster

- Renamed `PPUkdlRecognizerResult`'s property `ownerAdress` to `ownerAddress` (fixed typo)

## 1.1.0

- `PPMrtdRecognizerSettings` now sets `detectMachineReadableZonePosition` to YES by default. This means MRZ detection will work by default, meaning you no longer need to position the ID card precisely inside the frame shown in the UI.

- Added full support for parsing MRTD documents according to [ICAO Document 9303](http://www.icao.int/Security/mrtd/pages/Document9303.aspx) standard)

- Added support for scanning VISAs, and Belgian ID documents.

- `PPMrtdRecognizerSettings` now has a new settings `allowUnparsedResults` (default: NO), which you can use to get raw OCR results of the MRZ text, even if BlinkID parsing didn't manage to parse the text (this can happen since MRZ isn't always formatted according to [ICAO Document 9303](http://www.icao.int/Security/mrtd/pages/Document9303.aspx) standard)

    - When YES, `MrtdRecognizerResult` will be returned with `isParsed` property set to NO, and with `rawOcrLayout` property set to the `PPOcrLayout` object which was the result of the OCR process.

    - You should be careful when this property is set to YES, since obtained `OcrLayout` can contain OCR errors (for example (0 <-> O, 2 <-> Z, etc.). If you set this to YES, then you need to perform your own parsing and error correction.

    - If you set this to YES, we suggest the following approach in your result callback
         - obtain mrtdResult
         - if [mrtdResult isParsed]
             - present result and return
        - else if mrtdResult can be parsed with your custom parsing algorithm
             - present your custom results and return
        - else continue scanning since MRTD result cannot be parsed at all

- Improved video frame quality detection: now only the sharpest and the most focused frames are being processed. This improves quality of the results, but at a slight expense of processing time

- Frame quality estimation can now be enabled using `PPScanSettings frameQualityEstimationMode` property:
    - when set to `PPFrameQualityEstimationModeOn`, frame quality estimation is always enabled
    - when set to `PPFrameQualityEstimationModeOff`, frame quality estimation is always disabled
    - when set to `PPFrameQualityEstimationModeDefault`, frame quality estimation is enabled internally, if the SDK determines it makes sense

- iOS 9 introduced new app multitasking features Split View and Slide Over. When the scanner is on screen and one of those features are used, iOS automatically pauses the Camera (this behaviour is default as of iOS 9 beta 5). This SDK version introduces new setting in `PPUISettings` class, called `cameraPausedView`, where you can define the `UIView` which is presented centered on screen when this happens.

- Known issue on iOS 9: if you use Autorotate overlay feature (`settings.uiSetttings.autorotateOverlay`), present `PPScanningViewController` as a modal view controller, and support Split View iOS 9 feature, then autorotation of camera overlays isn't correct. The best way is to opt-out of Split View feature, and wait for SDK fix when iOS 9 comes out of beta.

- `PPScanningViewController` methods `pauseScanning`, `isScanningPaused`, and `resumeScanningAndResetState:` should now be called only from Main thread, and they are effective immediately. E.g., if `pauseScanning` is called and there is a video frame being processed, result of processing of that frame will be discarded, if `resumeScanningAndResetState:` isn't called in the meantime.

- Added support for `PPCameraPresetPhoto` camera preset. Use this if you need the same zoom level as in iOS Camera app. The resolution for video feed when using this preset is the same as devices screen resolution.

## 1.0.1

- Added support for several new special cases of US Driver Licenses in USDL recognizer. 

- Disabled Bitcode in Sample apps so that they are buildable with XCode 7 (Bitcode support in the framework coming soon!)

- Added library dependencies in podspec without which the app after integration couldn't be built 

## 1.0.0

- Changes in Direct processing API
    - You are no longer required to call `PPCoordinator initializeRecognizers` and `PPCoordinator terminateRecognizers`.
    - Instead, `initializeRecognizers` is called lazily on first call of `processImage` method. 
    - `terminateRecognizers` is called automatically in `PPCoordinator` destructor 
    
- Added support for autorotation of `PPScanningViewController`. To support autorotation, use `PPScanningViewController`'s new properties `autorotate` and `supportedOrientations`

- Added `didOutputMetadata:` callback method to `PPOverlayViewControllers`

- Fixed bug which caused Overlay events to be called when direct API is used. Direct API now only reports events to `PPScanDelegate` instance.

- Fixed bug which caused image property of `PPImageMetadata` not take the image orientation into account

- `PPMetadataSettings` cleanup

- `PPApp` class no longer part of public API

## 0.9.6

- US passport scanning now has less confusions between characters 0 and O
- Fixes for French passport format
- Fixed timeout bug which manifested between consecutive scans

## 0.9.5

- Added Direct processing API

## 0.9.4

- Added support for defining region for scaninng in `PPMrtdRecognizerSettings`

- For example, with this code you can specify bottom 25% of the image will be used for MRZ scanning.

```objective-c
PPMrtdRecognizerSettings *mrtdSettings = [[PPMrtdRecognizerSettings alloc] init];
mrtdSettings.mrtdRoi = CGRectMake(0.0, 0.75, 1.0, 0.25);
[settings.scanSettings addRecognizerSettings:mrtdSettings];
```
        
        
## 0.9.3

- Added support for scanning UK Driver's license. To scan them, add PPUkdlRecognizerSettings to `settings.scanSettings`

```objective-c
[settings.scanSettings addRecognizerSettings:[[PPUkdlRecognizerSettings alloc] init]];
```

- To collect UKDL results, look for `PPUkdlRecognizerResult` object in `scanningViewController:didOutputResults:` callback

```objective-c
for (PPRecognizerResult *result in results) {
        if ([result isKindOfClass:[PPUkdlRecognizerResult class]]) {
                PPUkdlRecognizerResult* ukdlResult = (PPUkdlRecognizerResult*)result;
                [self processUkdlResult:ukdlResult scanningViewController:scanningViewController];
        }
}
```
        
- License key format is now changed. If you use license keys generated pior to this version, please contact us so we can generate you a new license key

- Methods and properties in `PPCoordinator` class which were not meant to be part of the public API are now hidden.

## 0.9.2

- Naming changes in API (see Transition guide)
	- `PPBaseResult` renamed to `PPRecognizerResult`
	- `PPBaseResult` subclasses renamed accordingly
	- `PPOcrResult` renamed to `PPOcrLayout`

- Each `PPRecognizerResult` now has implemented `description` method for easier debugging

- Fixed orientation handling for case when overlay autorotates.

- Scanning region is now a property of Scanning view controller, and overlay view controller now delegates to this property.

## 0.9.1

- API consolidation, Bugfixes and improvements

## 0.9.0

- Initial documentation added
	
## 0.6.0

- Initial USDL and MRZ scanning
