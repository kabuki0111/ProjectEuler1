//
//  main.cpp
//  Problem1
//
//  Created by Suzuki Takayuki on 2014/04/04.
//  Copyright (c) 2014年 T.S. All rights reserved.
//

#include "ProjectEuler.h"

int main(int argc, const char * argv[])
{
    ProjectEuler euler;
    int getNaturalNum = euler.p1( 1000 );
    if(getNaturalNum == 23){
        printf( "%d => okay!!\n", getNaturalNum);
    }else{
        printf( "%d => no!!\n", getNaturalNum);
    }
    return 0;
}

