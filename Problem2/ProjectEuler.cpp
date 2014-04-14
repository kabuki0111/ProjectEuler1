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
    lli ansPrimeNaturalNum      = 0;
    lli countPrimeOrdinalNum    = 1;
    
    for(lli i_natuNum = 1; countPrimeOrdinalNum<=targetPrimeOrdinalNum; i_natuNum++){
        bool isPrimeFlag = false;
        isPrimeFlag = p7PrimeCheck(i_natuNum);
        if(isPrimeFlag){
            printf("count = %lld, number = %lld\n", countPrimeOrdinalNum, i_natuNum);
            ansPrimeNaturalNum = i_natuNum;
            countPrimeOrdinalNum++;
        }
    }
    return ansPrimeNaturalNum;
}

lli ProjectEuler::p8(){
    const std::string problemNumberStr(
        "73167176531330624919225119674426574742355349194934"
        "96983520312774506326239578318016984801869478851843"
        "85861560789112949495459501737958331952853208805511"
        "12540698747158523863050715693290963295227443043557"
        "66896648950445244523161731856403098711121722383113"
        "62229893423380308135336276614282806444486645238749"
        "30358907296290491560440772390713810515859307960866"
        "70172427121883998797908792274921901699720888093776"
        "65727333001053367881220235421809751254540594752243"
        "52584907711670556013604839586446706324415722155397"
        "53697817977846174064955149290862569321978468622482"
        "83972241375657056057490261407972968652414535100474"
        "82166370484403199890008895243450658541227588666881"
        "16427171479924442928230863465674813919123162824586"
        "17866458359124566529476545682848912883142607690042"
        "24219022671055626321111109370544217506941658960408"
        "07198403850962455444362981230987879927244284909188"
        "84580156166097919133875499200524063689912560717606"
        "05886116467109405077541002256983155200055935729725"
        "71636269561882670428252483600823257530420752963450");
    
    
    int     ansCommonTotalNum   = 0;
    int     ansTotalNum[4];
    char    memoGetNumChar[8];
    int     memoGetNumInt[8];
    int     maxTotalNum         =0;
    lli     castProblemSize = static_cast<lli>(problemNumberStr.size());
    for(lli i_numStr=0; i_numStr<castProblemSize; i_numStr+=8){
        
        for(lli j_memo=0; j_memo<8; j_memo++){
            memoGetNumChar[j_memo]  = problemNumberStr[i_numStr + j_memo];
            memoGetNumInt[j_memo]   = p8IntConvFromString(memoGetNumChar[j_memo]);
            printf("%d ", memoGetNumInt[j_memo]);
        }
        printf("\n");
        
        ansCommonTotalNum   = memoGetNumInt[3]  * memoGetNumInt[4];
        ansTotalNum[0]      = ansCommonTotalNum * memoGetNumInt[0] * memoGetNumInt[1] * memoGetNumInt[2];
        ansTotalNum[1]      = ansCommonTotalNum * memoGetNumInt[1] * memoGetNumInt[2] * memoGetNumInt[5];
        ansTotalNum[2]      = ansCommonTotalNum * memoGetNumInt[2] * memoGetNumInt[5] * memoGetNumInt[6];
        ansTotalNum[3]      = ansCommonTotalNum * memoGetNumInt[5] * memoGetNumInt[6] * memoGetNumInt[7];
        printf("common = %d\na = %d\nb = %d\nc = %d\nd = %d\n", ansCommonTotalNum, ansTotalNum[0], ansTotalNum[1], ansTotalNum[2], ansTotalNum[3]);
        
        p8GetMaxNum(ansTotalNum, maxTotalNum);
        printf("top total num = %d\n\n", maxTotalNum);
        
    }

    return 0;
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
    
    for(lli i_denom=3; i_denom<=targetNaturalNum/i_denom; i_denom+=2){
        if(targetNaturalNum % i_denom == 0){
            return false;
        }
    }
    
    return true;
}


//char型の数字からint型の数字に変換する処理
int ProjectEuler::p8IntConvFromString(const char& numChar){
    int ansNumInt = 0;
    switch(numChar){
        case '0':
            ansNumInt = 0;
            break;
        case '1':
            ansNumInt = 1;
            break;
        case '2':
            ansNumInt = 2;
            break;
        case '3':
            ansNumInt = 3;
            break;
        case '4':
            ansNumInt = 4;
            break;
        case '5':
            ansNumInt = 5;
            break;
        case '6':
            ansNumInt = 6;
            break;
        case '7':
            ansNumInt = 7;
            break;
        case '8':
            ansNumInt = 8;
            break;
        case '9':
            ansNumInt = 9;
            break;
    }
    return ansNumInt;
}

//配列に格納されている最大値を取得する関数
void ProjectEuler::p8GetMaxNum(int* arrayInt, int& topTotalNum){
    //int maxNum = 0;
    for(int i_array = 0; i_array<4; i_array++){
        if(topTotalNum < arrayInt[i_array]){
            topTotalNum = arrayInt[i_array];
        }
    }
}