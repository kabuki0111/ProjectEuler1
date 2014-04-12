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
    for (int i=1; i<maxNaturalNumber; i++) {
        if(i%3 == 0 || i%5 == 0){
            sumNaturalNumber += i;
        }
    }
    return sumNaturalNumber;
}


//Problem2のフィボナッチ数列
lli ProjectEuler::p2(lli maxLoop){
    std::vector<lli> fibonacciNumList;
    lli sumFibonaci = 1;
    lli prevOne     = 1;
    lli prevTwo     = 1;
    lli maxLimitFibonaci = 4000000;
    
    for (lli i_naturalnum=0; i_naturalnum<maxLoop; i_naturalnum++) {
        if(i_naturalnum <= 1){
            fibonacciNumList.push_back(1);
        }else{
            sumFibonaci = prevOne + prevTwo;
            prevTwo     = prevOne;
            prevOne     = sumFibonaci;
            
            if(sumFibonaci < maxLimitFibonaci){
                fibonacciNumList.push_back(sumFibonaci);
            }else{
                break;
            }
        }
    }
    
    lli sumEventFobonaci = 0;
    for(lli i_fibonaci = 0; i_fibonaci < fibonacciNumList.size(); i_fibonaci++ ){
        if(fibonacciNumList[i_fibonaci] % 2 == 0){
            sumEventFobonaci += fibonacciNumList[i_fibonaci];
        }
    }
    printf("sum even fibonaci %lld\n", sumEventFobonaci);
    
    return sumEventFobonaci;
}

//Problem3
long ProjectEuler::p3(long maxNumber){
    long    primeNum    = 2;
    long    divisionNum = maxNumber;
    bool    isPrimeNum;
    while (divisionNum > 1){
        if(divisionNum % primeNum == 0){
            divisionNum = divisionNum / primeNum;
            printf("primeNum = %ld   divisionNum = %ld\n", primeNum, divisionNum);
        }else{
            for (long i=0; i<=divisionNum; i++) {
                isPrimeNum = true;
                for (long j=2; j<i; j++) {
                    if(i % j == 0){
                        isPrimeNum = false;
                    }
                }
                if (isPrimeNum && primeNum < i) {
                    primeNum = i;
                    break;
                }
            }
        }
    }
    return primeNum;
}

//Problem4
lli ProjectEuler::p4(){
    std::vector<lli> sumList;
    for(lli i_right=100; i_right<=999; i_right++) {
        for(lli j_left=999; j_left>=100; j_left--){
            
            lli         sum             = i_right * j_left;
            std::string ansNumberStr    = std::to_string(sum);
            lli         fullNumberSize  = (lli)ansNumberStr.size();
            lli         count           = 0;
            
            
            if(fullNumberSize%2 != 0){
                count = 1;
            }
            
            lli halfNumbeSize = (fullNumberSize - count) / 2;
            bool isHoge = true;
            
            for(lli k_right=0; k_right<halfNumbeSize+count; k_right++){
                lli k_left = (fullNumberSize-1) - k_right;
                if(ansNumberStr[k_right] != ansNumberStr[k_left]){
                    isHoge = false;
                }
            }
            
            
            if(isHoge){
                printf("okay!! sum = %lld i = %lld j =%lld \n", sum, i_right, j_left);
                sumList.push_back(sum);
            }
        }
    }
    
    lli maxNumber = 0;
    for(lli i_list=0; i_list<(lli)sumList.size(); i_list++){
        if(sumList[i_list] > maxNumber){
            maxNumber = sumList[i_list];
        }
    }
    printf("get!! %lld\n", maxNumber);
    return maxNumber;
}

//ProjectEulerの処理をサポートするメソッド
int ProjectEuler::fibonaci(int targetFibonaciCount){
    int ansFibonaci = 0;
    switch (targetFibonaciCount) {
        case 0:
        case 1:
            return 1;
            break;
        default:
            ansFibonaci += fibonaci(targetFibonaciCount - 1) + fibonaci(targetFibonaciCount - 2);
            break;
    }
    return ansFibonaci;
}


//テストコード
bool ProjectEuler::isTestFibonaci(std::vector<int> targeteVector, int fibonaciNumber){
    for (int i=0; i<targeteVector.size(); i++) {
        if(targeteVector[i] == fibonaciNumber){
            return true;
        }
    }
    return false;
}

bool ProjectEuler::isTestSameNumber(long targetNumber, long ansNumber){
    if(targetNumber == ansNumber){
        return true;
    }
    return false;
}
