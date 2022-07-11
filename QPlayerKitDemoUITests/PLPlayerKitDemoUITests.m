//
//  QPlayerKitDemoUITests.m
//  QPlayerKitDemoUITests
//
//  Created by 何昊宇 on 2017/5/18.
//  Copyright © 2017年 Aaron. All rights reserved.
//

#import <XCTest/XCTest.h>

@interface QPlayerKitDemoUITests : XCTestCase

@end

@implementation QPlayerKitDemoUITests

- (void)setUp {
    [super setUp];
    
    // Put setup code here. This method is called before the invocation of each test method in the class.
    
    // In UI tests it is usually best to stop immediately when a failure occurs.
    self.continueAfterFailure = NO;
    // UI tests must launch the application that they test. Doing this in setup will make sure it happens for each test method.
    [[[XCUIApplication alloc] init] launch];
    
    // In UI tests it’s important to set the initial state - such as interface orientation - required for your tests before they run. The setUp method is a good place to do this.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    
    XCUIApplication *app = [[XCUIApplication alloc] init];
    [app.staticTexts[@"单 player 多 cell"] tap];
    
    sleep(5);
    XCUIElementQuery *tablesQuery = app.tables;
    [[[tablesQuery childrenMatchingType:XCUIElementTypeCell] elementBoundByIndex:1] tap];
    [[tablesQuery.cells containingType:XCUIElementTypeStaticText identifier:@"https://image01.bckid.com.cn/video/operation/1634881377059_94328132.OP.mp4"].element tap];
    [[[app.navigationBars[@"单 player 多 cell"] childrenMatchingType:XCUIElementTypeButton] elementBoundByIndex:0] tap];
    
    // Use recording to get started writing UI tests.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
}

@end
