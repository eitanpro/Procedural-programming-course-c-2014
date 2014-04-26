//
//  main.c
//  targil1
//
//  Created by Ronen Kondratovsky on 3/11/14.
//  Copyright (c) 2014 Ronen. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

int main(void) {
	int indices = 0, num = 0;
    
	if (scanf("%d", &num) != 1 ){
        fprintf(stderr,"not int enter \n");
		exit(3);
	}
    if(num<0){
        fprintf(stderr, "the number is nagative \n");
        exit(2);
    }
    if (scanf("%d", &indices) != 1 ){
        fprintf(stderr,"not int enter \n");
		exit(3);
	}
    if(indices<0){
        fprintf(stderr, "the number is nagative \n");

        exit(2);
    }
    
	printf("ltr:%d\n", createNumByIdx(num, indices));
	printf("rtl:%d\n", createNumByIdxRtl(num, indices));
	return EXIT_SUCCESS;
}

int createNumByIdx(int num, int indices) {
	return reateNumByIdxByOptions(num, indices, 0);
}
int createNumByIdxRtl(int num, int indices) {
	return reateNumByIdxByOptions(num, indices, 1);
}


