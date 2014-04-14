//
//  ProjectEuler.cpp
//  Problem1
//
//  Created by T.S on 2014/04/04.
//  Copyright (c) 2014年 T.S. All rights reserved.
//

#include "ProjectEuler.h"

inline lli square(lli targetNum){return targetNum * targetNum;}

//Problem1の結果を算出する関数
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
    
    for (lli i_naturalNum=0; i_naturalNum<maxLoop; i_naturalNum++) {
        if(i_naturalNum <= 1){
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

//Problem3の結果を算出する関数
lli ProjectEuler::p3(lli maxNumber){
    lli    primeNum    = 2;
    lli    divisionNum = maxNumber;
    bool    isPrimeNum;
    while (divisionNum > 1){
        if(divisionNum % primeNum == 0){
            divisionNum = divisionNum / primeNum;
            printf("primeNum = %lld   divisionNum = %lld\n", primeNum, divisionNum);
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

//Problem4の結果を算出する関数
lli ProjectEuler::p4(){
    std::vector<lli> sumList;
    for(lli i_left=100; i_left<=999; i_left++) {
        for(lli j_right=999; j_right>=100; j_right--){
            
            lli         sum             = i_left * j_right;
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
                printf("okay!! sum = %lld i = %lld j =%lld \n", sum, i_left, j_right);
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

//Problem5の結果を算出する関数
lli ProjectEuler::p5(lli maxDenomNum){
    bool    isStopWhile         = false;
    lli     ansNaturalNumber    = maxDenomNum;
    
    while(!isStopWhile){
        printf("%lld  \n", ansNaturalNumber);
        ansNaturalNumber += maxDenomNum;
        isStopWhile = p5MiniMultiple(ansNaturalNumber, maxDenomNum);
    }
    
    return ansNaturalNumber;
}

//Problem6の結果を算出する関数
lli ProjectEuler::p6(lli targetNum){
    lli sumAllNumber     = p6SumNumberAll(targetNum);
    lli ansProblemNumber = square(sumAllNumber) - p6SumSquare(targetNum);
    
    return ansProblemNumber;
}

//Problem7の結果を算出する関数
lli ProjectEuler::p7(lli targetPrimeOrdinalNum){
    lli checkNumber = 3;
    lli countPrime  = 3;
    
    while(countPrime <= targetPrimeOrdinalNum){
        checkNumber++;
        bool isPrimeFlag    = false;
        isPrimeFlag         = p7PrimeCheck(checkNumber);
        if(isPrimeFlag){
            printf("count = %lld, number = %lld\n", countPrime, checkNumber);
            countPrime++;
        }
    }
    return checkNumber;
}



/*ProjectEulerの処理をサポートする関数*/

//Problem2の試作関数
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

//Problem5に関連する関数
bool ProjectEuler::p5MiniMultiple(lli targetNumerator, lli maxDenomNum){
    bool isAnsFlag = true;
    for(lli i_Denominator=maxDenomNum; i_Denominator>0; i_Denominator--){
        if( targetNumerator%i_Denominator != 0){
            isAnsFlag = false;
            break;
        }
    }
    
    return isAnsFlag;
}

//Project 6 二乗の和
lli ProjectEuler::p6SumSquare(lli targetNum){
    if(targetNum != 0){
        return square(targetNum) + p6SumSquare(targetNum - 1);
    }
    
    return 0;
}

//Project 6 指定した値の合計値
lli ProjectEuler::p6SumNumberAll(lli targetNum){
    if(targetNum != 0){
        return targetNum + p6SumNumberAll(targetNum - 1);
    }
    
    return 0;
}

//指定した値が素数かどうかを判定する関数
bool ProjectEuler::p7PrimeCheck(lli targetNaturalNum){
    
    if(targetNaturalNum < 2){
        return false;
    }else if(targetNaturalNum == 2){
        return true;
    }if(targetNaturalNum % 2 == 0){
        return false;
    }
        
    for(lli i=3; i<=targetNaturalNum/i; i+=2){
        if(targetNaturalNum % i == 0){
            return false;
        }
    }
    return 1;

}