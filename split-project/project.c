#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int buff = *a;
	*a = *b;
	*b = buff;
}

void findEmpty(int field[][4], int *x, int *y)
{
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (field[i][j] == 0) {
				*y = i;
				*x = j;
			}
		}
	}
}
void printField(int field[][4], int x, int y, int score)
{
	int i, j;
	system("clear");   
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (field[i][j] != 0) {
				printf(" [%3d] ", field[i][j]);
			}
			else {
				printf(" [   ] ");
			}
		}
		printf("\n");
	}
	printf("\nScore: %d\n", score);
}
