//
//  MBProcessingStatus.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 10/08/2020.
//

#ifndef MBProcessingStatus_h
#define MBProcessingStatus_h

/**
* MBProcessingStatus enum defines status of the last recognition process.
*/
typedef NS_ENUM(NSInteger, MBProcessingStatus) {

    /** Recognition was successful. */
    MBProcessingStatusSuccess,

    /** Detection of the document failed. */
    MBProcessingStatusDetectionFailed,

    /** Preprocessing of the input image has failed. */
    MBProcessingStatusImagePreprocessingFailed,

    /** Recognizer has inconsistent results. */
    MBProcessingStatusStabilityTestFailed,

    /** Wrong side of the document has been scanned. */
    MBProcessingStatusScanningWrongSide,

    /** Identification of the fields present on the document has failed. */
    MBProcessingStatusFieldIdentificationFailed,

    /** Mandatory field for the specific document is missing. */
    MBProcessingStatusMandatoryFieldMissing,

    /** Result contains invalid characters in some of the fields. */
    MBProcessingStatusInvalidCharactersFound,

    /** Failed to return a requested image. */
    MBProcessingStatusImageReturnFailed,

    /** Reading or parsing of the barcode has failed. */
    MBProcessingStatusBarcodeRecognitionFailed,

    /** Parsing of the MRZ has failed. */
    MBProcessingStatusMrzParsingFailed,

    /** Document class has been filtered out. */
    MBProcessingStatusClassFiltered,

    /** Document currently not supported by the recognizer. */
    MBProcessingStatusUnsupportedClass,

    /** License for the detected document is missing. */
    MBProcessingStatusUnsupportedByLicense
};

#endif /* MBProcessingStatus_h */
