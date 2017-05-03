//
//  RecognizerTest.h
//  RecognizerTest
//
//  Created by Jure Cular on 10/04/2017.
//  Copyright © 2017 Dino. All rights reserved.
//
#import <XCTest/XCTest.h>
#import <MicroBlink/MicroBlink.h>

@interface RecognizerTest : XCTestCase <PPCoordinatorDelegate>

@property (nonatomic) PPCoordinator *coordinator;

@property (nonatomic, copy) void (^didOutputResults)(PPCoordinator *coordinator, NSArray<PPRecognizerResult *> *);

@property (nonatomic, copy) void (^didOutputMetadata)(PPCoordinator *coordinator, PPMetadata *);

@property (nonatomic) XCTestExpectation *expectation;

- (void)testImage:(NSString *)image ofType:(NSString *)imageType inDirectory:(NSString *)directory withDescription:(NSString *)description;

- (BOOL)checkStringValueInResult:(PPRecognizerResult *)result truth:(NSString *)truth key:(NSString *)key;

@end
