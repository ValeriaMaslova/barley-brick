#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

const int N = 4;

void swap(int *a, int *b)
{
	int buff = *a;
	*a = *b;
	*b = buff;
}

void printField(int field[][N], int x, int y, int *score)
{
	int i, j;
	system("cls");             //System func
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (field[i][j] != 0) {
				printf(" [%3d] ", field[i][j]);
			}
			else {
				printf(" [   ] ");
			}
		}
		printf("\n");
	}
	*score = *score + 1;
//	printf("\nXY: %d   %d", x, y);
	printf("\nScore: %d", *score);
}


bool checkSolution(int field[][N])
{
	int i, j, counter = 0;
	for (i = 0; i < N * N; i++) {
		for (j = i + 1; j < N * N; j++) {
			if ((field[i / N][i%N] > field[j / N][j%N]) && (field[i / N][i%N] != 0) && (field[j / N][j%N] != 0))
				counter++;
		}
		if (field[i / N][i%N] == 0)
			counter += (i / N) + 1;
	}

	if (counter % 2 == 0) {
		return 0;
	}
	return 1;
}


void initializeField(int field[][N])
{
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			field[i][j] = i * 4 + j;
		}
	}
}


void shuffleField(int field[][N])
{
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			int iRand = rand() % N, jRand = rand() % N;

			if (iRand != i || jRand != j) {
				swap(&field[i][j], &field[iRand][jRand]);
			}
			else
				j--;
		}
	}

	while (checkSolution(field) == 1) {
		shuffleField(field);
	}
}

void findEmpty(int field[][N], int *x, int *y)
{
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (field[i][j] == 0) {
				*y = i;
				*x = j;
			}
		}
	}
}

void moveBrick(int field[][N], unsigned char btn, int *x, int *y)
{
	switch (btn) {
	case 'a':
		if (*x < N - 1) {
			swap(&field[*y][*x], &field[*y][*x + 1]);
			*x = *x + 1;
		}
		break;
	case 'd':
		if (*x > 0) {
			swap(&field[*y][*x], &field[*y][*x - 1]);
			*x = *x - 1;
		}
		break;
	case 'w':
		if (*y < N - 1) {
			swap(&field[*y][*x], &field[*y + 1][*x]);
			*y = *y + 1;
		}
		break;
	case 's':
		if (*y > 0) {
			swap(&field[*y][*x], &field[*y - 1][*x]);
			*y = *y - 1;
		}
		break;
	default:
		printf("\n\nSosi");
		break;
	}
}

int main()
{
	srand(time(NULL));
	int field[N][N], emptyX, emptyY, score = 0;  //Main field
	unsigned char btn;

	initializeField(field);
	shuffleField(field);
	findEmpty(field, &emptyX, &emptyY);
	printField(field, emptyX, emptyY, &score);
	while (true) {
		btn = getch();     //conio.h
		moveBrick(field, btn, &emptyX, &emptyY);
		printField(field, emptyX, emptyY, &score);
	}
	system("pause");
	return 0;
}
