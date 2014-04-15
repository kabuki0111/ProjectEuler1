//
//  ProjectEuler.cpp
//  Problem1
//
//  Created by T.S on 2014/04/04.
//  Copyright (c) 2014年 T.S. All rights reserved.
//

#include "ProjectEuler.h"

inline int_64 square(int_64 targetNum){return targetNum * targetNum;}


//Problem1の結果を算出する関数
int_64 ProjectEuler::p1(int_64 maxNaturalNumber){
    int_64 sumNaturalNumber = 0;
    for (int_64 i=1; i<maxNaturalNumber; i++) {
        if(i%3 == 0 || i%5 == 0){
            sumNaturalNumber += i;
        }
    }
    
    return sumNaturalNumber;
}

//Problem2のフィボナッチ数列
int_64 ProjectEuler::p2(int_64 maxLoop){
    std::vector<int_64> fibonacciNumList;
    int_64 sumFibonaci      = 1;
    int_64 prevOne          = 1;
    int_64 prevTwo          = 1;
    int_64 maxLimitFibonaci = 4000000;
    
    for (int_64 i_naturalNum=0; i_naturalNum<maxLoop; i_naturalNum++) {
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
    
    int_64 sumEventFobonaci = 0;
    for(int_64 j_fibonaci = 0; j_fibonaci < fibonacciNumList.size(); j_fibonaci++ ){
        if(fibonacciNumList[j_fibonaci] % 2 == 0){
            sumEventFobonaci += fibonacciNumList[j_fibonaci];
        }
    }
    printf("sum even fibonaci %lld\n", sumEventFobonaci);
    
    return sumEventFobonaci;
}

//Problem3の結果を算出する関数
int_64 ProjectEuler::p3(int_64 maxNumber){
    int_64  primeNum    = 2;
    int_64  divisionNum = maxNumber;
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
int_64 ProjectEuler::p4(){
    std::vector<int_64> sumList;
    for(int_64 i_left=100; i_left<=999; i_left++) {
        for(int_64 j_right=999; j_right>=100; j_right--){
            int_64          sum             = i_left * j_right;
            std::string     ansNumberStr    = std::to_string(sum);
            int_64          fullNumberSize  = static_cast<int_64>(ansNumberStr.size());
            int_64          count           = 0;
            
            if(fullNumberSize%2 != 0){
                count = 1;
            }
            
            int_64 halfNumbeSize = (fullNumberSize - count) / 2;
            
            bool isHoge = true;
            for(int_64 k_right=0; k_right<halfNumbeSize+count; k_right++){
                int_64 k_left = (fullNumberSize-1) - k_right;
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
    
    int_64 maxNumber = 0;
    for(int_64 i_list=0; i_list<(int_64)sumList.size(); i_list++){
        if(sumList[i_list] > maxNumber){
            maxNumber = sumList[i_list];
        }
    }
    printf("get!! %lld\n", maxNumber);
    
    return maxNumber;
}

//Problem5の結果を算出する関数
int_64 ProjectEuler::p5(int_64 maxDenomNum){
    bool    isStopWhile         = false;
    int_64  ansNaturalNumber    = maxDenomNum;
    
    while(!isStopWhile){
        printf("%lld  \n", ansNaturalNumber);
        ansNaturalNumber    += maxDenomNum;
        isStopWhile         =  p5MiniMultiple(ansNaturalNumber, maxDenomNum);
    }
    
    return ansNaturalNumber;
}

//Problem6の結果を算出する関数
int_64 ProjectEuler::p6(int_64 targetNum){
    int_64 sumAllNumber     = p6SumNumberAll(targetNum);
    int_64 ansProblemNumber = square(sumAllNumber) - p6SumSquare(targetNum);
    
    return ansProblemNumber;
}

//Problem7の結果を算出する関数
int_64 ProjectEuler::p7(int_64 targetPrimeOrdinalNum){
    int_64 ansPrimeNaturalNum      = 0;
    int_64 countPrimeOrdinalNum    = 1;
    
    for(int_64 i_natuNum = 1; countPrimeOrdinalNum<=targetPrimeOrdinalNum; i_natuNum++){
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

//Problem8の結果を出力する関数
int_64 ProjectEuler::p8(){
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
    
    int_64  ansGreatestTotalNum = 0;
    int_64  castProblemSize = static_cast<int_64>(problemNumberStr.size());
    for(int_64 i_numStr=0; i_numStr<castProblemSize; i_numStr+=4){
        char    memoNumChar[8];
        int_64  memoNumInt[8];
        
        for(int_64 j_memo=0; j_memo<8; j_memo++){
            memoNumChar[j_memo]  = problemNumberStr[i_numStr + j_memo];
            memoNumInt[j_memo]   = p8IntConvFromChar(memoNumChar[j_memo]);
            printf("%lld ", memoNumInt[j_memo]);
        }
        printf("\n");
        
        int_64  commonTotalNum   = 0;
        int_64  totalNum[4];
        commonTotalNum   = memoNumInt[3]  * memoNumInt[4];
        totalNum[0]      = commonTotalNum * memoNumInt[0] * memoNumInt[1] * memoNumInt[2];
        totalNum[1]      = commonTotalNum * memoNumInt[1] * memoNumInt[2] * memoNumInt[5];
        totalNum[2]      = commonTotalNum * memoNumInt[2] * memoNumInt[5] * memoNumInt[6];
        totalNum[3]      = commonTotalNum * memoNumInt[5] * memoNumInt[6] * memoNumInt[7];
        printf("common = %lld\na = %lld\nb = %lld\nc = %lld\nd = %lld\n", commonTotalNum, totalNum[0], totalNum[1], totalNum[2], totalNum[3]);
        
        int_64 maxTotalNum = p8GetMaxNum(totalNum);
        if(ansGreatestTotalNum < maxTotalNum){
            ansGreatestTotalNum = maxTotalNum;
        }
        printf("top total num = %lld\n\n", ansGreatestTotalNum);
    }

    return ansGreatestTotalNum;
}

//Problem9を回答する関数
int_64 ProjectEuler::p9(int_64 findSumPythagoNum){
    int_64 vertexA  = 0;
    int_64 vertexB  = 0;
    int_64 vertexC  = 0;
    for(int_64 i_naturalNum=1; i_naturalNum<findSumPythagoNum; i_naturalNum++){
        for(int_64 j_naturalNum=1; j_naturalNum<i_naturalNum; j_naturalNum++){
            
            int_64 oddNaturalNum = i_naturalNum - j_naturalNum;
            if(oddNaturalNum%2 != 0){
                vertexA    = square(i_naturalNum) - square(j_naturalNum);
                vertexB    = 2 * i_naturalNum * j_naturalNum;
                vertexC    = square(i_naturalNum) + square(j_naturalNum);
                
                int_64 sumPythagoreanAll = vertexA + vertexB + vertexC;
                if(sumPythagoreanAll == findSumPythagoNum){
                    
                    return vertexA * vertexB * vertexC;
                }
            }
        }
    }
    
    return 0;
}

//Problem10を回答する関数
int_64 ProjectEuler::p10(int_64 maxNaturalNum){
    std::vector<int_64> primeVector;
    for(int_64 i_naturalNum=2; i_naturalNum<=maxNaturalNum; i_naturalNum++){
        bool isPrime = p7PrimeCheck(i_naturalNum);
        if(isPrime){
            printf("%lld\n", i_naturalNum);
            primeVector.push_back(i_naturalNum);
        }
    }
    
    int_64 ansSumPrimeNumber = 0;
    for(int_64 k_primeVector=0; k_primeVector<primeVector.size(); k_primeVector++){
        ansSumPrimeNumber += primeVector[k_primeVector];
    }
    printf("%lld\n", ansSumPrimeNumber);
    
    return ansSumPrimeNumber;
}

//Problem11を回答するメソッド
int_64 ProjectEuler::p11(){
//    std::string problemNumStr(
//     "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08"
//     "49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00"
//     "81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65"
//     "52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91"
//     "22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80"
//     "24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50"
//     "32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70"
//     "67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21"
//     "24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72"
//     "21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95"
//     "78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92"
//     "16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57"
//     "86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58"
//     "19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40"
//     "04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66"
//     "88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69"
//     "04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36"
//     "20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16"
//     "20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54"
//     "01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48");
    
    int_64 problemNumInt[20][20] ={
        {8 , 2 , 22, 97, 38, 15, 0 , 40, 0 , 75, 4 , 5 , 7,  78, 52, 12, 50, 77, 91, 8 },
        {49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4 , 56, 62, 0 },
        {81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30,  3, 49, 13, 36, 65},
        {52, 70, 95, 23, 4 , 60, 11, 42, 69, 24, 68, 56, 1 , 32, 56, 71, 37, 2 , 36, 91},
        {22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
        {24, 47, 32, 60, 99, 3 , 45, 2 , 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
        {32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
        {67, 26, 20, 68, 2 , 62, 12, 20, 95, 63, 94, 39, 63, 8 , 40, 91, 66, 49, 94, 21},
        {24, 55, 58, 5 , 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
        {21, 36, 23, 9 , 75, 0 , 76, 44, 20, 45, 35, 14, 0 , 61, 33, 97, 34, 31, 33, 95},
        {78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3 , 80, 4 , 62, 16, 14, 9 , 53, 56, 92},
        {16, 39, 5 , 42, 96, 35, 31, 47, 55, 58, 88, 24, 0 , 17, 54, 24, 36, 29, 85, 57},
        {86, 56, 0 , 48, 35, 71, 89, 7 , 5 , 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
        {19, 80, 81, 68, 5 , 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4 , 89, 55, 40},
        {4 , 52, 8 , 83, 97, 35, 99, 16, 7 , 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
        {88, 36, 68, 87, 57, 62, 20, 72, 3 , 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
        {4 , 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8 , 46, 29, 32, 40, 62, 76, 36},
        {20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4 , 36, 16},
        {20, 73, 35, 29, 78, 31, 90, 1 , 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5 , 54},
        {1 , 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1 , 89, 19, 67, 48}
    };
    
    
    int_64 maxSumDiagonalNum = 0;
    int_64 right    = 0;
    int_64 left     = 0;
    for(int_64 i_width=0; i_width<17; i_width++){
        for(int_64 j_height=0; j_height<17; j_height++){
            right =
                problemNumInt[i_width][j_height] * problemNumInt[i_width+1][j_height+1] * problemNumInt[i_width+2][j_height+2] * problemNumInt[i_width+3][j_height+3];
            left =
                problemNumInt[i_width+3][j_height] * problemNumInt[i_width+2][j_height+1] * problemNumInt[i_width+1][j_height+2] * problemNumInt[i_width][j_height+3];
            printf("right = %lld\nleft  = %lld\n\n", right, left);
            
            if(right < left){
                if(left > maxSumDiagonalNum){
                    maxSumDiagonalNum = left;
                }
            }else{
                if(right > maxSumDiagonalNum){
                    maxSumDiagonalNum = right;
                }
            }
        }
        printf("\n");
    }
    printf("%lld\n", maxSumDiagonalNum);
    return 0;
}

/*ProjectEulerの処理をサポートする関数*/

//Problem2の試作関数
int_64 ProjectEuler::fibonaci(int_64 targetFibonaciCount){
    int ansFibonaci = 0;
    switch (targetFibonaciCount){
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
bool ProjectEuler::p5MiniMultiple(int_64 targetNumerator, int_64 maxDenomNum){
    bool isAnsFlag = true;
    for(int_64 i_Denominator=maxDenomNum; i_Denominator>0; i_Denominator--){
        if( targetNumerator%i_Denominator != 0){
            isAnsFlag = false;
            break;
        }
    }
    
    return isAnsFlag;
}

//Project 6 二乗の和
int_64 ProjectEuler::p6SumSquare(int_64 targetNum){
    if(targetNum != 0){
        return square(targetNum) + p6SumSquare(targetNum - 1);
    }
    
    return 0;
}

//Project 6 指定した値の合計値
int_64 ProjectEuler::p6SumNumberAll(int_64 targetNum){
    if(targetNum != 0){
        return targetNum + p6SumNumberAll(targetNum - 1);
    }
    
    return 0;
}

//指定した値が素数かどうかを判定する関数
bool ProjectEuler::p7PrimeCheck(int_64 targetNaturalNum){
    
    if(targetNaturalNum < 2){
        return false;
    }else if(targetNaturalNum == 2){
        return true;
    }if(targetNaturalNum % 2 == 0){
        return false;
    }
    
    for(int_64 i_denom=3; i_denom<=targetNaturalNum/i_denom; i_denom+=2){
        if(targetNaturalNum % i_denom == 0){
            return false;
        }
    }
    
    return true;
}


//char型の数字からint型の数字に変換する処理
int_64 ProjectEuler::p8IntConvFromChar(const char& numChar){
    int_64 ansNumInt = 0;
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
int_64 ProjectEuler::p8GetMaxNum(int_64* arrayInt){
    int_64 maxTotalNum = 0;
    for(int_64 i_array = 0; i_array<4; i_array++){
        if(maxTotalNum < arrayInt[i_array]){
            maxTotalNum = arrayInt[i_array];
        }
    }
    
    return maxTotalNum;
}