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
std::vector<int> ProjectEuler::p2(int maxLoop){
    std::vector<int> testList;
    //long sumEvenFibonaci = 1;
    int sumFibonaci = 1;
    int afterOne = 1, afterTwo = 1;
    int maxLimitFibonaci = 4000000;
    
    for (int i = 0; i < maxLoop; i++) {
        if(i <= 1){
            testList.push_back(1);
        }else{
            sumFibonaci = afterOne + afterTwo;
            afterTwo = afterOne;
            afterOne = sumFibonaci;
            //testList.push_back(sumFibonaci);
            
            if(sumFibonaci < maxLimitFibonaci){
                testList.push_back(sumFibonaci);
            }else{
                return testList;
            }
            
        }
        
    }
    
    return testList;
}

long ProjectEuler::p3(long maxNumber){
    //std::vector<int> testList;
    //int hoge;
    /*
    for (int i = 0; i<maxNumber; i++) {
        hoge = 0;
        for (int j=2; j<i; j++) {
            if(i % j == 0){
                hoge = 1;
            }
        }
        if(hoge == 0){
            printf("i = %d \n ", i);
            testList.push_back(i);
        }
    }
    */
    
    long primeNum =2;
    long divisionNum = maxNumber;
    long hoge;
    while (divisionNum > 1) {
        if(divisionNum % primeNum == 0){
            divisionNum = divisionNum / primeNum;
            printf("primeNum = %ld   divisionNum = %ld\n", primeNum, divisionNum);
        }else{
            for (long i = 0; i <= divisionNum; i++) {
                hoge = 0;
                for (long j=2; j<i; j++) {
                    if(i % j == 0){
                        hoge = 1;
                    }
                }
                if (hoge == 0 && primeNum < i) {
                    //printf(">>>> %ld\n", hoge);
                    primeNum = i;
                    break;
                }
            }
            
        }
    }
    return 0;
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

//テストコード
bool ProjectEuler::isTestFibonaci(std::vector<int> targeteVector, int fibonaciNumber){
    for (int i= 0; i<targeteVector.size(); i++) {
        if(targeteVector[i]==fibonaciNumber){
            return true;
        }
    }
    return false;
}