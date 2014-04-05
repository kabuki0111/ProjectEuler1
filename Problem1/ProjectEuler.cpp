//
//  ProjectEuler.cpp
//  Problem1
//
//  Created by Suzuki Takayuki on 2014/04/04.
//  Copyright (c) 2014年 T.S. All rights reserved.
//

#include "ProjectEuler.h"

int ProjectEuler::p1(int maxNaturalNumber){
    int sumNaturalNumber = 0;
    for (int i = 1; i < 10; i++) {
        if( i % 3 == 0){
            sumNaturalNumber += i;
        }else if( i  % 5 == 0) {
            sumNaturalNumber += i;
        }
    }
    return sumNaturalNumber;
}
