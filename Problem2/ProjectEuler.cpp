//
//  ProjectEuler.cpp
//  Problem1
//
//  Created by T.S on 2014/04/04.
//  Copyright (c) 2014年 T.S. All rights reserved.
//

#include "ProjectEuler.h"

int ProjectEuler::p1(int maxNaturalNumber){
    int sumNaturalNumber = 0;
    for (int i = 1; i < maxNaturalNumber; i++) {
        if( i % 3 == 0 || i  % 5 == 0){
            sumNaturalNumber += i;
        }
    }
    return sumNaturalNumber;
}


//フィボナッチ数列
int ProjectEuler::p2(int maxFibonaciCount ){
    int sumFibonaci = 2;
    //int sumEvenFibonaci = 0;
    for (int i = 0; i < maxFibonaciCount; i++) {
        if(i <= 1 ){
            sumFibonaci = 1;
        }else{
            sumFibonaci = (i - 1) + i;
        }
        
        printf("count --> %d   %d\n", sumFibonaci, i );
    }
    return 0;
}