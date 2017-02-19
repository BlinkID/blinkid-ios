//
//  ViewController.m
//  Templating-Sample
//
//  Created by Dino on 08/06/16.
//  Copyright © 2016 Dino. All rights reserved.
//

#import "ViewController.h"
@import MicroBlink;

@interface ViewController () <PPScanningDelegate, PPDocumentClassifier>

@end

@implementation ViewController

static NSString *ID_LAST_NAME = @"LastName";
static NSString *ID_FIRST_NAME = @"FirstName";
static NSString *ID_SEX_CITIZENSHIP_DOB = @"SexCitizenshipDob";
static NSString *ID_SEX = @"Sex";
static NSString *ID_CITIZENSHIP = @"Citizenship";
static NSString *ID_DATE_OF_BIRTH = @"DateOfBirth";
static NSString *ID_DOCUMENT_NUMBER = @"DocumentNumber";
static NSString *ID_DOCUMENT_NUMBER_OLD = @"DocumentNumberOld";
static NSString *ID_DOCUMENT_NUMBER_NEW = @"DocumentNumberNew";

static NSString *CLASS_OLD_ID = @"oldCroId";
static NSString *CLASS_NEW_ID = @"newCroId";

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/**
 * Method allocates and initializes the Scanning coordinator object.
 * Coordinator is initialized with settings for scanning
 * Modify this method to include only those recognizer settings you need. This will give you optimal performance
 *
 *  @param error Error object, if scanning isn't supported
 *
 *  @return initialized coordinator
 */
- (PPCameraCoordinator *)coordinatorWithError:(NSError **)error {

    /** 0. Check if scanning is supported */

    if ([PPCameraCoordinator isScanningUnsupportedForCameraType:PPCameraTypeBack error:error]) {
        return nil;
    }


    /** 1. Initialize the Scanning settings */

    // Initialize the scanner settings object. This initialize settings with all default values.
    PPSettings *settings = [[PPSettings alloc] init];

    // tell which metadata you want to receive. Metadata collection takes CPU time - so use it only if necessary!
    settings.metadataSettings.dewarpedImage = YES; // get dewarped image of ID documents


    /** 2. Setup the license key */

    // Visit www.microblink.com to get the license key for your app
    settings.licenseSettings.licenseKey = @"IT7ENADM-MJMB6M5R-K6FIAED5-YEMGIHG6-AVRYB2FL-P2SQ4A4R-WKVX4BLC-KMDNEMEK";
    // License key is valid temporarily until 2017-05-01


    /**********************************************************************************************************************/
    /**************  For Croatian ID sample images please check Croatian_ID_Images.xcassets in this project  **************/
    /**********************************************************************************************************************/


    /**
     * 3. Set up what is being scanned. See detailed guides for specific use cases.
     * Remove undesired recognizers (added below) for optimal performance.
     */
    {
        PPBlinkOcrRecognizerSettings *ocrSettings = [[PPBlinkOcrRecognizerSettings alloc] init];

        NSMutableArray<PPDecodingInfo *> *oldIdDecodingInfoArray = [NSMutableArray array];
        NSMutableArray<PPDecodingInfo *> *newIdDecodingInfoArray = [NSMutableArray array];

        NSMutableArray<PPDecodingInfo *> *classificationDecodingInfoArray = [NSMutableArray array];

        /** Setup first name decoding */
        {
            /** Pixel height of returned image */
            int dewarpHeight = 150;

            /**
             * For extracting first and last names, we will use regex parser with regular expression which
             * attempts to extract as many uppercase words as possible from single line.
             */
            PPRegexOcrParserFactory *firstNameParser = [[PPRegexOcrParserFactory alloc] initWithRegex:@"([A-ZŠĐŽČĆ]+ ?)+"];

            /**
             * tweak OCR engine options - allow only recognition of uppercase letters used in Croatia
             */
            PPOcrEngineOptions *options = [[PPOcrEngineOptions alloc] init];
            options.charWhitelist = [self uppercaseCharsWhitelist];
            [firstNameParser setOptions:options];

            /**
             * Add parser to recognizer settings
             */
            [ocrSettings addOcrParser:firstNameParser name:ID_FIRST_NAME group:ID_FIRST_NAME];

            /**
             * Locations of first name string on borth old and new ID cards
             */
            CGRect oldIdNameLocation = CGRectMake(0.282, 0.333, 0.306, 0.167);
            CGRect newIdNameLocation = CGRectMake(0.282, 0.389, 0.353, 0.167);

            /**
             * Add locations to list
             * Since we want to use selected parsers on these locations, uniqueId of decoding infos must be the same as parser group id.
             */
            [oldIdDecodingInfoArray
                addObject:[[PPDecodingInfo alloc] initWithLocation:oldIdNameLocation dewarpedHeight:dewarpHeight uniqueId:ID_FIRST_NAME]];
            [newIdDecodingInfoArray
                addObject:[[PPDecodingInfo alloc] initWithLocation:newIdNameLocation dewarpedHeight:dewarpHeight uniqueId:ID_FIRST_NAME]];
        }

        /** Setup last name decoding */
        {
            int dewarpHeight = 150;
            PPRegexOcrParserFactory *lastNameParser = [[PPRegexOcrParserFactory alloc] initWithRegex:@"([A-ZŠĐŽČĆ]+ ?)+"];

            PPOcrEngineOptions *options = [[PPOcrEngineOptions alloc] init];
            options.charWhitelist = [self uppercaseCharsWhitelist];
            [lastNameParser setOptions:options];

            [ocrSettings addOcrParser:lastNameParser name:ID_LAST_NAME group:ID_LAST_NAME];

            CGRect oldIdNameLocation = CGRectMake(0.271, 0.204, 0.318, 0.111);
            CGRect newIdNameLocation = CGRectMake(0.282, 0.204, 0.353, 0.167);
            [oldIdDecodingInfoArray
                addObject:[[PPDecodingInfo alloc] initWithLocation:oldIdNameLocation dewarpedHeight:dewarpHeight uniqueId:ID_LAST_NAME]];
            [newIdDecodingInfoArray
                addObject:[[PPDecodingInfo alloc] initWithLocation:newIdNameLocation dewarpedHeight:dewarpHeight uniqueId:ID_LAST_NAME]];
        }

        /** Setup sex, citizenship and date of birth */
        {
            /**
             * Since sex, citizenship and date of birth are located closely within eachother and their value formats are mutually exclusive,
             * We can use 1 Decoding info and parse the whole image with each parser to maximize performance. (this way we parser 1 image 3
             * times, instead of 3 images each once)
             */

            /** Setup sex parser */
            PPRegexOcrParserFactory *sexParser = [[PPRegexOcrParserFactory alloc] initWithRegex:@"[MŽ]/[MF]"];
            NSMutableSet *charWhitelist = [[NSMutableSet alloc] init];
            [charWhitelist addObject:[PPOcrCharKey keyWithCode:'M' font:PP_OCR_FONT_ANY]];
            [charWhitelist addObject:[PPOcrCharKey keyWithCode:'F' font:PP_OCR_FONT_ANY]];
            [charWhitelist addObject:[PPOcrCharKey keyWithCode:'/' font:PP_OCR_FONT_ANY]];
            [charWhitelist addObject:[PPOcrCharKey keyWithCode:0xC5 font:PP_OCR_FONT_ANY]];
            PPOcrEngineOptions *options = [[PPOcrEngineOptions alloc] init];
            options.charWhitelist = charWhitelist;
            [sexParser setOptions:options];

            [ocrSettings addOcrParser:sexParser name:ID_SEX group:ID_SEX_CITIZENSHIP_DOB];

            /** Setup citizenship parser */
            PPRegexOcrParserFactory *citizenshipParser = [[PPRegexOcrParserFactory alloc] initWithRegex:@"[A-Z]{3}"];
            options = [[PPOcrEngineOptions alloc] init];
            options.charWhitelist = [self uppercaseCharsWhitelist];
            [citizenshipParser setOptions:options];

            [ocrSettings addOcrParser:citizenshipParser name:ID_CITIZENSHIP group:ID_SEX_CITIZENSHIP_DOB];

            /** Setup date of birth */
            [ocrSettings addOcrParser:[[PPDateOcrParserFactory alloc] init] name:ID_DATE_OF_BIRTH group:ID_SEX_CITIZENSHIP_DOB];

            /**
             * To have multiple parsers on 1 decoding info we need to have them all in the same group. That group must have the same id
             * (group name) as decoding info uniqueId.
             */

            CGRect oldLocation = CGRectMake(0.412, 0.500, 0.259, 0.296);
            CGRect newLocation = CGRectMake(0.388, 0.500, 0.282, 0.296);

            [oldIdDecodingInfoArray
                addObject:[[PPDecodingInfo alloc] initWithLocation:oldLocation dewarpedHeight:300 uniqueId:ID_SEX_CITIZENSHIP_DOB]];
            [newIdDecodingInfoArray
                addObject:[[PPDecodingInfo alloc] initWithLocation:newLocation dewarpedHeight:300 uniqueId:ID_SEX_CITIZENSHIP_DOB]];
        }

        /** Setup document number */
        {
            /**
             * Since document number is located differently on old and new ID cards, we will use it as our classification.
             */

            [classificationDecodingInfoArray addObject:[[PPDecodingInfo alloc] initWithLocation:CGRectMake(0.047, 0.519, 0.224, 0.111)
                                                                                 dewarpedHeight:150
                                                                                       uniqueId:ID_DOCUMENT_NUMBER_OLD]];
            [classificationDecodingInfoArray addObject:[[PPDecodingInfo alloc] initWithLocation:CGRectMake(0.047, 0.685, 0.224, 0.111)
                                                                                 dewarpedHeight:150
                                                                                       uniqueId:ID_DOCUMENT_NUMBER_NEW]];

            PPRegexOcrParserFactory *documentNumberParser = [[PPRegexOcrParserFactory alloc] initWithRegex:@"\\d{9}"];

            NSMutableSet *charWhitelist = [[NSMutableSet alloc] init];
            // Add chars '0'-'9'
            for (int c = '0'; c <= '9'; c++) {
                [charWhitelist addObject:[PPOcrCharKey keyWithCode:c font:PP_OCR_FONT_ANY]];
            }
            PPOcrEngineOptions *options = [[PPOcrEngineOptions alloc] init];
            options.charWhitelist = charWhitelist;
            options.minimalLineHeight = 35;
            [documentNumberParser setOptions:options];

            [ocrSettings addOcrParser:documentNumberParser name:ID_DOCUMENT_NUMBER group:ID_DOCUMENT_NUMBER_NEW];
            [ocrSettings addOcrParser:documentNumberParser name:ID_DOCUMENT_NUMBER group:ID_DOCUMENT_NUMBER_OLD];
        }

        /**
         * Create ID card document specification. Document specification defines geometric/scanning properties of documents to be detected
         */
        PPDocumentSpecification *idSpec = [PPDocumentSpecification newFromPreset:PPDocumentPresetId1Card];

        /**
         * Set decoding infos as our classification decoding infos. One has location of document number on old id, other on new Id
         */
        [idSpec setDecodingInfo:classificationDecodingInfoArray];

        /**
         * Wrap Document specification in detector settings
         */
        PPDocumentDetectorSettings *detectorSettings = [[PPDocumentDetectorSettings alloc] initWithNumStableDetectionsThreshold:1];
        [detectorSettings setDocumentSpecifications:@[ idSpec ]];

        /**
         * Add created detector settings to recognizer
         */
        [ocrSettings setDetectorSettings:detectorSettings];
        /**
         * Set this class as document classifier delegate
         */
        [ocrSettings setDocumentClassifier:self];
        /**
         * Add decoding infos for classifier results. These infos and their parsers will only be processed if classifier outputs the
         * selected result
         */
        [ocrSettings setDecodingInfoSet:newIdDecodingInfoArray forClassifierResult:CLASS_NEW_ID];
        [ocrSettings setDecodingInfoSet:oldIdDecodingInfoArray forClassifierResult:CLASS_OLD_ID];

        [settings.scanSettings addRecognizerSettings:ocrSettings];
    }


    /** 4. Initialize the Scanning Coordinator object */

    PPCameraCoordinator *coordinator = [[PPCameraCoordinator alloc] initWithSettings:settings delegate:nil];

    return coordinator;
}

- (NSMutableSet *)uppercaseCharsWhitelist {

    // initialize new char whitelist
    NSMutableSet *charWhitelist = [[NSMutableSet alloc] init];

    // Add chars 'A'-'Z'
    for (int c = 'A'; c <= 'Z'; c++) {
        [charWhitelist addObject:[PPOcrCharKey keyWithCode:c font:PP_OCR_FONT_ANY]];
    }
    return charWhitelist;
}

- (IBAction)didTapScan:(id)sender {

    /** Instantiate the scanning coordinator */
    NSError *error;
    PPCameraCoordinator *coordinator = [self coordinatorWithError:&error];

    /** If scanning isn't supported, present an error */
    if (coordinator == nil) {
        NSString *messageString = [error localizedDescription];
        [[[UIAlertView alloc] initWithTitle:@"Warning"
                                    message:messageString
                                   delegate:nil
                          cancelButtonTitle:@"OK"
                          otherButtonTitles:nil, nil] show];

        return;
    }

    /** Create new scanning view controller */
    UIViewController<PPScanningViewController> *scanningViewController =
        [PPViewControllerFactory cameraViewControllerWithDelegate:self coordinator:coordinator error:nil];

    // allow rotation if VC is displayed as a modal view controller
    scanningViewController.autorotate = YES;
    scanningViewController.supportedOrientations = UIInterfaceOrientationMaskAll;

    /** Present the scanning view controller. You can use other presentation methods as well (instead of presentViewController) */
    [self presentViewController:scanningViewController animated:YES completion:nil];
}

#pragma mark - PPScanDelegate

- (void)scanningViewControllerUnauthorizedCamera:(UIViewController<PPScanningViewController> *)scanningViewController {
    // Add any logic which handles UI when app user doesn't allow usage of the phone's camera
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController didFindError:(NSError *)error {
    // Can be ignored. See description of the method
}

- (void)scanningViewControllerDidClose:(UIViewController<PPScanningViewController> *)scanningViewController {

    // As scanning view controller is presented full screen and modally, dismiss it
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController didOutputResults:(NSArray *)results {

    /**
     * Here you process scanning results. Scanning results are given in the array of PPRecognizerResult objects.
     * Each member of results array will represent one result for a single processed image
     * Usually there will be only one result. Multiple results are possible when there are 2 or more detected objects on a single image
     * (i.e. pdf417 and QR code side by side)
     */

    // first, pause scanning until we process all the results
    [scanningViewController pauseScanning];

    NSString *message;
    NSString *title;

    // Collect data from the result
    for (PPRecognizerResult *result in results) {

        if ([result isKindOfClass:[PPBlinkOcrRecognizerResult class]]) {
            /** MRTD was detected */
            PPBlinkOcrRecognizerResult *ocrResult = (PPBlinkOcrRecognizerResult *)result;
            message = [ocrResult parsedResultForName:ID_SEX parserGroup:ID_SEX_CITIZENSHIP_DOB];
            message = [[message stringByAppendingString:@" "]
                stringByAppendingString:[ocrResult parsedResultForName:ID_CITIZENSHIP parserGroup:ID_SEX_CITIZENSHIP_DOB]];
            message = [[message stringByAppendingString:@" "]
                stringByAppendingString:[ocrResult parsedResultForName:ID_DATE_OF_BIRTH parserGroup:ID_SEX_CITIZENSHIP_DOB]];
            message = [[message stringByAppendingString:@" "]
                stringByAppendingString:[ocrResult parsedResultForName:ID_FIRST_NAME parserGroup:ID_FIRST_NAME]];
            title = [ocrResult parsedResultForName:ID_FIRST_NAME parserGroup:ID_FIRST_NAME];
        }
    };

    // present the alert view with scanned results
    UIAlertView *alertView =
        [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alertView show];
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanninvViewController
    didFinishDetectionWithResult:(PPDetectorResult *)result {
}

- (void)scanningViewController:(UIViewController<PPScanningViewController> *)scanningViewController
             didOutputMetadata:(PPMetadata *)metadata {

    // Check if metadata obtained is image. You can set what type of image is outputed by setting different properties of PPMetadataSettings
    // (currently, dewarpedImage is set at line 57)
    if ([metadata isKindOfClass:[PPImageMetadata class]]) {

        PPImageMetadata *imageMetadata = (PPImageMetadata *)metadata;

        if ([imageMetadata.name isEqualToString:@"EUDL"]) {
            UIImage *eudlImage = [imageMetadata image];
            NSLog(@"We have dewarped and trimmed image of the EUDL, with size (%@, %@)", @(eudlImage.size.width), @(eudlImage.size.height));
        } else if ([imageMetadata.name isEqualToString:@"MRTD"]) {
            UIImage *mrtdImage = [imageMetadata image];
            NSLog(@"We have dewarped and trimmed image of the Machine readable travel document, with size (%@, %@)",
                  @(mrtdImage.size.width), @(mrtdImage.size.height));
        } else if ([imageMetadata.name isEqualToString:@"MyKad"]) {
            UIImage *myKadImage = [imageMetadata image];
            NSLog(@"We have dewarped and trimmed image of the MyKad, with size (%@, %@)", @(myKadImage.size.width),
                  @(myKadImage.size.height));
        } else {
            UIImage *image = [imageMetadata image];
            NSLog(@"We have image %@ with size (%@, %@)", metadata.name, @(image.size.width), @(image.size.height));
        }
    }
}

// dismiss the scanning view controller when user presses OK.
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (NSString *)classifyDocumentFromResult:(PPTemplatingRecognizerResult *)result {
    /**
     * Get the result of parsing the location of document number on old ID.
     */
    NSString *documentNumber = [result parsedResultForName:ID_DOCUMENT_NUMBER parserGroup:ID_DOCUMENT_NUMBER_OLD];
    if (documentNumber != nil && ![documentNumber isEqualToString:@""]) {
        // If result exists then we are dealing with old ID
        return CLASS_OLD_ID;
    }
    /**
     * Get the result of parsing the location of document number on new ID.
     */
    documentNumber = [result parsedResultForName:ID_DOCUMENT_NUMBER parserGroup:ID_DOCUMENT_NUMBER_NEW];
    if (documentNumber != nil && ![documentNumber isEqualToString:@""]) {
        // If result exists then we are dealing with new ID
        return CLASS_NEW_ID;
    }
    /**
     * Document is detected but it doesnt contain document numbers on their expected locations
     */
    return @"";
}

@end
