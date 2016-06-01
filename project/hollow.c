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

void winCase(int score)
{
	system("cls");                         //System
	printf("You win!\nScore : %d", score - 1);

}

bool checkWin(int *f, unsigned char btn) {
	int i;
	if (*(f + N * N - 1) != 0) return 0;
	for (i = 0; i < N * N - 2; i++) {
		printf("\n%d ", *(f + i));
		if ((*(f + i) > *(f + i + 1)) && (*(f + i + 1) != 0)) {
			return 0;
		}
	}
	if (btn == 'i') return 1;
	return 1;
}

void moveBrick(int field[][N], unsigned char btn, int *x, int *y)  //Rename to smth like work with keyboard
{
	int cheatField[N][N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 15 }, i, j;
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
	case 'i':
		*x = N - 2;
		*y = N - 1;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				field[i][j] = cheatField[i][j];
			}
		}
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
		if (checkWin(*field, btn) == 1) {
			winCase(score);
			break;
		}
	}


	system("pause");
	return 0;
}
