//
//  Problem2_Tests.m
//  Problem2 Tests
//
//  Created by T.S on 2014/04/12.
//  Copyright (c) 2014年 T.S. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "ProjectEuler.h"

@interface Problem2_Tests : XCTestCase

@end

@implementation Problem2_Tests

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample
{
    ProjectEuler *euler = new ProjectEuler;
    XCTAssertTrue(euler->p8() == 40824);
}

- (void)testProblem9
{
    //算出した値が正しく表示されているかを確認
    ProjectEuler *euler = new ProjectEuler;
    XCTAssertTrue(euler->p9(1000) == 31875000);
    NSLog(@"problem9 answer : %lld", euler->p9(1000));
}

- (void)testProblem10
{
    //算出した値が正しく表示されているかを確認
    ProjectEuler *euler = new ProjectEuler;
    XCTAssertTrue(euler->p10(2000000) == 142913828922);
}

@end
