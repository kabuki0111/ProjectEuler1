//
//  ProjectEuler.h
//  Problem1
//
//  Created by Suzuki Takayuki on 2014/04/04.
//  Copyright (c) 2014年 T.S. All rights reserved.
//

#ifndef __Problem1__ProjectEuler__
#define __Problem1__ProjectEuler__
//#ifdef __cplus
#include <iostream>
#include <list>
#include <vector>

class ProjectEuler{
public:
    //テストコード用
    bool isTestFibonaci(std::vector<int>, int);
    bool isTestSameNumber( long, long);
    
    //ProjectEular用
    int p1(int);
    std::vector<int> p2(int);
    long p3(long);
    //ProjectEularのメソッドをサポートするメソッド用
private:
    int fibonaci(int);
};

#endif /* defined(__Problem1__ProjectEuler__) */
