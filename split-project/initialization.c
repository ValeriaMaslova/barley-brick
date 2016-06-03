#include <stdio.h>
#include <time.h>
#include <stdlib.h>

_Bool checkSolution(int field[][4])
{
	int i, j, counter = 0;
	for (i = 0; i < 4 * 4; i++) {
		for (j = i + 1; j < 4 * 4; j++) {
			if ((field[i / 4][i%4] > field[j / 4][j%4]) && (field[i / 4][i%4] != 0) && (field[j / 4][j%4] != 0))
				counter++;
		}
		if (field[i / 4][i%4] == 0)
			counter += (i / 4) + 1;
	}

	if (counter % 2 == 0) {
		return 0;
	}
	return 1;
}


void initializeField(int field[][4])
{
	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			field[i][j] = i * 4 + j;
		}
	}
}


void shuffleField(int field[][4])
{
	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			int iRand = rand() % 4, jRand = rand() % 4;

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
