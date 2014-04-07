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
    int maxCount = 100;
    std::vector<int> getFobonaci = euler.p2(maxCount);
    
    bool isTestFibonaci = euler.isTestFibonaci( getFobonaci[9], 55);
    
    if(isTestFibonaci){
        int sumEvent = 0;
        for(int i = 0; i < maxCount; i++ ){
            if(getFobonaci[i] % 2 == 0){
                sumEvent += getFobonaci[i];
            }
            //printf("%d %d\n", i, boo);
        }
        printf("sum %d\n", sumEvent);
    }
    
    
    return 0;
}


