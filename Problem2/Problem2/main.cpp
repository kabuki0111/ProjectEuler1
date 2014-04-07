//
//  main.cpp
//  Problem2
//
//  Created by Suzuki Takayuki on 2014/04/07.
//  Copyright (c) 2014年 T.S. All rights reserved.
//

#include <limits.h>
#include "ProjectEuler.h"


int main(int argc, const char * argv[])
{
    ProjectEuler euler;
    std::vector<long> hoge = euler.p2();
    
    for(int i = 0; i < 10; i++ ){
        long boo= hoge[i];
        printf("%d\n", boo);
    }
    
    
    return 0;
}


