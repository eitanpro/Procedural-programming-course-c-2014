/*
 * reateNumByOptions.c

 *
 *  Created on: Mar 11, 2014
 *      Author: laurent
 */
#include <stdio.h>
#include "myHeader.h"
int reateNumByIdxByOptions(int num, int indices, int dir) {
	int scalar = 1;
	int curNum = 0;
	int results = 0;
	int size = getLength(indices);
    int i=0;
	for (i = 0; i < size; i++) {
		curNum = indices % 10;
		indices /= 10;
		results += getDigit(curNum, num, dir) * scalar;
		scalar *= 10;
	}
    
	return results;

}

