//
//  MBBlinkIdOverlaySettings.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 03/06/2019.
//

#import "MBBaseOverlaySettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class containing parameters for BlinkId UI
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBBlinkIdOverlaySettings : MBBaseOverlaySettings

/**
 * If YES, MBBlinkIdCombinedRecognizer will check if sides do match when scanning is finished
 *
 * Default: YES
 */
@property(nonatomic, assign) BOOL requireDocumentSidesDataMatch;

/**
 * Defines whether Document Not Supported dialog will be displayed in UI. ni bnhju
 *
 * Default: YES
*/
@property(nonatomic, assign) BOOL showNotSupportedDialog;

/**
 * Option to configure back side scanning timeout.
 *
 * Default: 17.0
*/
@property(nonatomic, assign) NSTimeInterval backSideScanningTimeout;

/**
* Message that is shown while scanning first side of the document.
* Default: Scan the front side of a document
*/
@property(nonatomic, strong) NSString *firstSideInstructionsText;

/**
* Message that is shown after fornt side of the USDL document is scanned.
* Default: Scan the barcode
*/
@property(nonatomic, strong) NSString *scanBarcodeText;

/**
* Instructions to flip document, shown when scanning of the first side is done, before scanning the second
* side of the document.
* Default: Flip the card
*/
@property(nonatomic, strong) NSString *flipInstructions;

/**
* Instructions for the user to move the document closer.
* Default: Move closer
*/
@property(nonatomic, strong) NSString *errorMoveCloser;

/**
* Instructions for the user to move the document farther.
* Default: Move farther
*/
@property(nonatomic, strong) NSString *errorMoveFarther;

/**
* Instructions for the user to move the document from the edge.
* Default: Move the document from the edge
*/
@property(nonatomic, strong) NSString *errorDocumentTooCloseToEdge;

/**
* Title of the dialog, which is shown when scanned document sides are not from the same document.
* Default: Sides don't match
*/
@property(nonatomic, strong) NSString *sidesNotMatchingTitle;

/**
* Message inside dialog, which is shown when scanned document sides are not from the same document.
* Default: Please start the scanning process over.
*/
@property(nonatomic, strong) NSString *sidesNotMatchingMessage;

/**
* Title of the dialog, which is shown when scanned document sides are not from the same document.
* Default: Document not recognized
*/
@property(nonatomic, strong) NSString *unsupportedDocumentTitle;

/**
* Message inside dialog, which is shown when unsupported document is scanned.
* Default: Scan the front side of a supported document.
*/
@property(nonatomic, strong) NSString *unsupportedDocumentMessage;

/**
* Title of the dialog, which is shown on timeout when scanning is stuck on the back document side.
* Default: Scan unsuccessful
*/
@property(nonatomic, strong) NSString *recognitionTimeoutTitle;

/**
* Message inside dialog, which is shown on timeout when scanning is stuck on the back document side.
* Default: Unable to read the document. Please try again.
*/
@property(nonatomic, strong) NSString *recognitionTimeoutMessage;

/**
* Text of the "retry" button inside dialog, which is shown on timeout when scanning is stuck on the back
* document side.
* Default: Retry
*/
@property(nonatomic, strong) NSString *retryButtonText;

/**
 * Designated initializer. Initializes the object with default settings.
 *
 *  @return object initialized with default values.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
