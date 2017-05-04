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

@property (strong, nonatomic) PPCoordinator *coordinator;

@property (copy, nonatomic) void (^didOutputResults)(NSArray<PPRecognizerResult *> *);

@property (strong, nonatomic) XCTestExpectation *expectation;

- (void)testImage:(NSString *)imageName ofType:(NSString *)imageType withDescription:(NSString *)description;

- (BOOL)checkStringValueInResult:(PPRecognizerResult *)result truth:(NSString *)truth key:(NSString *)key;

@end
