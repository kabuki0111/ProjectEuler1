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
std::vector<long> ProjectEuler::p2(){
    std::vector<long> testList;
    //long sumEvenFibonaci = 1;
    long sumFibonaci = 1;
    long afterOne = 1, afterTwo = 1;
    
    for ( long i = 0; i < 10; i++) {
        if(i > 1){
            sumFibonaci = afterOne + afterTwo;
            printf("test %lo　one %lo two %lo\n", sumFibonaci, afterOne, afterTwo);
            afterTwo = afterOne;
            afterOne = sumFibonaci;
            testList.push_back(sumFibonaci);
            
            //testList.push_back(sumFibonaci);
            
            //printf("boo %lo one　%lo two %lo\n", sumFibonaci, afterOne, afterTwo);
            /*
            if( sumFibonaci % 2 == 0 ){
                if( sumFibonaci < 4000000 ){
                    sumEvenFibonaci += sumFibonaci;
                    printf("even >>>> count  %lo sum %lo one %lo two %lo    ----> %lo\n", i, sumFibonaci, afterOne, afterTwo, sumEvenFibonaci );
                }else{
                    return 0;
                }
            }
            */
            //if(i){
            //afterTwo = afterOne;
            //afterOne = sumFibonaci;
            //}
            
            
        }
        
    }
    
    return testList;
}


unsigned long long ProjectEuler::fibonaci(unsigned long long targetFibonaciCount){
    long ansFibonaci = 0;
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