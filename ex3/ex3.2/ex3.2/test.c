//
//  main.c
//  task3.2
//
//  Created by Ronen Kondratovsky on 4/26/14.
//  Copyright (c) 2014 Ronen. All rights reserved.
//

#include <stdio.h>
#include <math.h>
void intToBinnary(int num){
	int size = sizeof(int)* 8;
	unsigned long and = 1;
	int i=0;
	for (i = size - 1; i >= 0; i--) {
		and = powl(2, i);
		if ((num&and) != 0){
			printf("1");
		}
		else{
			;
			printf("0");
		}
	}
	printf("\n");
}

int rotl(int a, int n){
	int left = 1 << (sizeof(int)* 8 - 1), i;
	int number = a;
	for (i = 0; i<n; i++) {
		if (number&left){
			number = number << 1; number += 1;
		}
		else{
			number = number << 1;
		}
	}
	return number;
}
int stringToNum(char string[]){
	int result = 0;
	int temp = 0,i=0;
	for (i = 0; i<8; i++) {
		temp = string[i] & 0xb1111;
		temp = rotl(temp, (8 - i - 1) * 4);
		result += temp;
	}
	return result;
}
int main(int argc, const char * argv[])
{

	intToBinnary(124);
	intToBinnary(rotl(124, 26));
	intToBinnary(50);
	intToBinnary(stringToNum("12345678"));
	char c = getchar();
	return 0;
}

