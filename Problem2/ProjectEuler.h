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
    int p1(int);
    std::vector<long> p2();
private:
    unsigned long long fibonaci(unsigned long long);
};

#endif /* defined(__Problem1__ProjectEuler__) */
