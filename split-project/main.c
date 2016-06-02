#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <termios.h>
#include <sys/ioctl.h>

#include "prototype.h"

int main()
{
	srand(time(NULL));
	int field[N][N], emptyX, emptyY, score = 0;  //Main field
	unsigned char btn;
	
	while (1) {
		btn = getchar(); 
		moveBrick(field, btn, &emptyX, &emptyY, &score);
		printField(field, emptyX, emptyY, score);
		if (checkWin(*field, btn) == 1) {
			winCase(score);
			break;
		}
	}

	return 0;
}
