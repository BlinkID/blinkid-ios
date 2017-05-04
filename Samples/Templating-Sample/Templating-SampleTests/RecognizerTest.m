//
//  RecognizerTest.m
//  RecognizerTest
//
//  Created by Jure Cular on 10/04/2017.
//  Copyright © 2017 Dino. All rights reserved.
//

#import "RecognizerTest.h"

@implementation RecognizerTest

- (void)setUp {
    [super setUp];

    if (_coordinator != nil) {
        return;
    }

    /** 1. Initialize the Scanning settings */

    // Initialize the scanner settings object. This initialize settings with all default values.
    PPSettings *settings = [[PPSettings alloc] init];

    /** 2. Setup the license key */

    // Visit www.microblink.com to get the license key for your app
    settings.licenseSettings.licenseKey = @"NO3UZBO3-ILSVEWSU-EUQFGUGO-NBIACSL5-SOVMSG6A-FOARUOIE-5IYFRLQ2-GFK4ND3X";

    /** 4. Initialize the Scanning Coordinator object */

    self.coordinator = [[PPCoordinator alloc] initWithSettings:settings delegate:self];
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];

    PPSettings *settings = self.coordinator.currentSettings;
    for (PPRecognizerSettings *recognizerSettings in settings.scanSettings.recognizerSettingsList) {
        [settings.scanSettings removeRecognizerSettings:recognizerSettings];
    }
}


#pragma mark - Testing

- (void)testImage:(NSString *)imageName ofType:(NSString *)imageType withDescription:(NSString *)description {

    NSString *fullImageName = [NSString stringWithFormat:@"%@.%@", imageName, imageType];

    NSString *imagePath = [[NSBundle bundleForClass:[self class]] pathForResource:imageName ofType:imageType];

    XCTAssertNotNil(imagePath, @"Image %@ doesn't exist", fullImageName);

    self.expectation = [self expectationWithDescription:description];

    PPImage *ppImage = [PPImage imageWithUIImage:[[UIImage alloc] initWithContentsOfFile:imagePath]];
    ppImage.orientation = PPProcessingOrientationUp;
    ppImage.cameraFrame = NO;

    XCTAssertNotNil(ppImage, @"Image %@ failed initialization", fullImageName);

    [self.coordinator processImage:ppImage];

    NSTimeInterval fullfilmentTimeout = 15.0;
    [self waitForExpectationsWithTimeout:fullfilmentTimeout handler:nil];
}

- (BOOL)checkStringValueInResult:(PPRecognizerResult *)result truth:(NSString *)truth key:(NSString *)key {
    XCTAssertEqualObjects(truth, [result getStringElementUsingGuessedEncoding:key], @"Key is %@", key);
}


#pragma mark - PPCoordinatorDeleaget

- (void)coordinator:(PPCoordinator *)coordinator didOutputResults:(NSArray<PPRecognizerResult *> *)results {

    if (self.didOutputResults) {
        self.didOutputResults(results);
    }
}

- (void)coordinator:(PPCoordinator *)coordinator invalidLicenseKeyWithError:(NSError *)error {
    XCTFail(@"Invalid license key!");
}

@end
