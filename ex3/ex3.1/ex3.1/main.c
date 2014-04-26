//
//  main.c
//  task3.1
//
//  Created by Ronen Kondratovsky on 4/25/14.
//  Copyright (c) 2014 Ronen. All rights reserved.
//
#include <time.h>
#include <stdlib.h>
#include <stdio.h>1
#define WIDTH 20
#define HEIGHT 10
#define MaxGen 20
typedef enum { die, live } liveOrDie;
typedef liveOrDie liveOrDieBoard[HEIGHT][WIDTH];
typedef liveOrDieBoard Box[MaxGen];

void print(liveOrDieBoard, int, int );
int count_neighbors(liveOrDieBoard, int, int , int );
void step(Box, liveOrDieBoard, int, int);

void print(liveOrDieBoard board, int rows, int cols)
{
	int x, y;

	for (y = 0; y < rows; y++) {
		for (x = 0; x < cols; x++) {
			if (board[y][x] == live)
				printf("%d", live);
			else
				printf("%d", die);
		}
		printf("\n");
	}
	printf("\n");
}
int count_neighbors(liveOrDieBoard board, int rows, int y, int x)
{
	int i, j;
	int result = 0;
	for (i = -1; i <= 1; i++)
	if ((y + i >= 0) && (y + i < rows))
	for (j = -1; j <= 1; j++)
	if ((x + j >= 0) && (x + j < WIDTH))
	if ((i != 0) || (j != 0))
		result += board[y + i][x + j];
	return result;
}

void step(Box myBox, liveOrDieBoard board, int rows, int numberOfStep) {
	int x, y;
	int neighbors[HEIGHT][WIDTH];
	for (y = 0; y < rows; y++)
	for (x = 0; x < WIDTH; x++){
		neighbors[y][x] = count_neighbors(board, rows, y, x);
		myBox[numberOfStep][y][x] = board[y][x];

	}

	for (y = 0; y < rows; y++)
	for (x = 0; x < WIDTH; x++)
	if (board[y][x] == live) {
		if (neighbors[y][x] < 2)
			board[y][x] = die;
		else if (neighbors[y][x] > 3)
			board[y][x] = die;
		if (neighbors[y][x] == 3)
			board[y][x] = live;
	}

}

int main(int argc, const char * argv[])
{
	int userNumberOfstep=0, userHight=0, userWidth=0;
	if (scanf_s("%d", &userNumberOfstep) != 1 && userNumberOfstep>0){
		fprintf(stderr, "enter number\n");
		getchar();
			
		return 1;
	}
	if (scanf_s("%d", &userHight) != 1 && userWidth>0){
		fprintf(stderr, "enter number\n");
		getchar();
		return 2;
	}
	if (scanf_s("%d", &userWidth) != 1 && userWidth>0){
		fprintf(stderr, "enter number\n");
		getchar();
		return 3;
	}
	if (userNumberOfstep>MaxGen){
		userNumberOfstep = MaxGen;
	}
	if (userHight>HEIGHT)
	{
		userHight = HEIGHT;
	}
	if (userWidth>WIDTH) {
		userWidth = WIDTH;
	}
	int x, y;
	liveOrDieBoard board;
	for (y = 0; y < userHight; y++)
	for (x = 0; x < userWidth; x++)
	if (scanf_s("%d", &board[y][x]) != 1){
		if (board[y][x] != 1 || board[y][x] != 0)
			fprintf(stderr, "The file contains an error.\n");
		return 4;
	}

	Box myBox;
	int numberOfStep = 0;
	while (numberOfStep<userNumberOfstep) {

		step(myBox, board, HEIGHT, numberOfStep);
		print(myBox[numberOfStep], userHight, userWidth);
		numberOfStep++;
	}
	getchar();
	return 0;
}
