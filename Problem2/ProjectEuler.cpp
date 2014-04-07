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
    int sumEvenFibonaci = 0;
    for (int i = 0; i < maxFibonaciCount; i++) {
        if (fibonaci(i) % 2 == 0 ) {
            printf( "even = %d %d\n", i, fibonaci(i) );
            sumEvenFibonaci += fibonaci(i);
        }
    }
    
    return sumEvenFibonaci;
}

int ProjectEuler::fibonaci(int targetFibonaciCount){
    int ansFibonaci = 0;
    switch (targetFibonaciCount) {
        case 0:
        case 1:
            return 1;
            break;
        default:
            ansFibonaci += fibonaci(targetFibonaciCount-1 ) + fibonaci(targetFibonaciCount-2);
            break;
    }
    return ansFibonaci;
}