//
//  main.cpp
//  Problem2
//
//  Created by Suzuki Takayuki on 2014/04/07.
//  Copyright (c) 2014年 T.S. All rights reserved.
//

#include "ProjectEuler.h"


int main(int argc, const char * argv[])
{
    ProjectEuler euler;
    int maxCount = 100;
    std::vector<int> getFobonaci = euler.p2(maxCount);
    
    bool isTestFibonaci = euler.isTestFibonaci( getFobonaci, 3524578);
    
    if(isTestFibonaci){
        int sumEventFobonaci = 0;
        for(int i = 0; i < getFobonaci.size(); i++ ){
            if(getFobonaci[i] % 2 == 0){
                //printf("%d\n",getFobonaci[i]);
                sumEventFobonaci += getFobonaci[i];
            }
        }
        printf("sum %d\n", sumEventFobonaci);
    }else{
        printf("error program!!\n");
    }
    
    
    euler.p3(13195);
    
    return 0;
}


