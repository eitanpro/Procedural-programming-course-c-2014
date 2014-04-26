/*
 * getLength.c
 *
 *  Created on: Mar 10, 2014
 *      Author: laurent
 */
#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

int getLength(int num) {
	int counter = 0;
	do {
		num = num / 10;
		counter++;
	} while (num > 0);
	return counter;
}
