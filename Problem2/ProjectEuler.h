//
//  ProjectEuler.h
//  Problem1
//
//  Created by T.S on 2014/04/04.
//  Copyright (c) 2014年 T.S. All rights reserved.
//

#ifndef __Problem1__ProjectEuler__
#define __Problem1__ProjectEuler__
//#ifdef __cplus
#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>

typedef long long int int_64;

class ProjectEuler{
public:
    //ProjectEular用
    int_64     p1(int_64);
    int_64     p2(int_64);
    int_64     p3(int_64);
    int_64     p4();
    int_64     p5(int_64);
    int_64     p6(int_64);
    int_64     p7(int_64);
    int_64     p8();
private:
    //ProjectEularのメソッドをサポートするメソッド用
    int_64  fibonaci(int_64);
    bool    p5MiniMultiple(int_64, int_64);
    int_64  p6SumSquare(int_64);
    int_64  p6SumNumberAll(int_64);
    bool    p7PrimeCheck(int_64);
    int_64  p8IntConvFromString(const char&);
    int_64  p8GetMaxNum(int_64*);
};

#endif /* defined(__Problem1__ProjectEuler__) */
