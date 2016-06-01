#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int N = 4;

void swap(int *a, int *b)
{
	int buff = *a;
	*a = *b;
	*b = buff;
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

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", field[i][j]);
		}
		printf("\n");
	}

	while (checkSolution(field) == 1) {
		shuffleField(field);
	}
}


int main()
{
	srand(time(NULL));
	int field[N][N];  //Main field
	initializeField(field);
	shuffleField(field);
	system("pause");
	return 0;
}
