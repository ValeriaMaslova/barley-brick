#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void moveBrick(int field[][4], unsigned char btn, int *x, int *y, int *score)  
{
	int cheatField[4][4], i, j, counter = 1;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			cheatField[i][j] = counter;
			counter++;
		}
	}
cheatField[3][3] = 15;
cheatField[3][2] = 0;


	switch (btn) {
	case 'a':
		if (*x < 4 - 1) {
			swap(&field[*y][*x], &field[*y][*x + 1]);
			*x = *x + 1;
			*score = *score + 1;
		}
		break;
	case 'd':
		if (*x > 0) {
			swap(&field[*y][*x], &field[*y][*x - 1]);
			*x = *x - 1;
			*score = *score + 1;
		}
		break;
	case 'w':
		if (*y < 4 - 1) {
			swap(&field[*y][*x], &field[*y + 1][*x]);
			*y = *y + 1;
			*score = *score + 1;
		}
		break;
	case 's':
		if (*y > 0) {
			swap(&field[*y][*x], &field[*y - 1][*x]);
			*y = *y - 1;
			*score = *score + 1;
		}
		break;
	case 'i':
		*x = 4 - 2;
		*y = 4 - 1;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				field[i][j] = cheatField[i][j];
			}
		}
		break;
	case 'q': case 27:
		exit(0);
		break;
	default:
		printf("\n\n");
		break;
	}
}
