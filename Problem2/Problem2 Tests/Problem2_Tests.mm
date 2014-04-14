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
//    XCTAssertTrue(euler->p2(100)            == 4613732  );
//    XCTAssertTrue(euler->p3(600851475143)   == 6857     );
//    XCTAssertTrue(euler->p4()               == 906609   );
//    XCTAssertTrue(euler->p5(20)             == 232792560);
//    XCTAssertTrue(euler->p6(100)            == 25164150 );
//    XCTAssertTrue(euler->p7(10001)          == 104743   );
    XCTAssertTrue(euler->p8()               == 40824    );
}

@end
