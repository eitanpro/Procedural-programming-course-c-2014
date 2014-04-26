/*
 * getDigit.c

 *
 *  Created on: Mar 10, 2014
 *      Author: laurent
 */
#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

//if from equlse 0 than read ltr else rtl
int getDigit(int index, int num, int from) {
	int maxIndex = getLength(num) - 1;
	if(index>maxIndex){
        fprintf(stderr, "index not correct \n");
		exit(1);
	}
	if (from == 1) {
		index = maxIndex - index;
	}
    int i=0;
	for ( i = 0; i < maxIndex - index; i++) {
		num = num / 10;
	}
	return num % 10;
}

