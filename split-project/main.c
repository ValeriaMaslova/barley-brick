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
	
	struct termios stored_settings;
    	struct termios new_settings;
        tcgetattr(0,&stored_settings);
        new_settings = stored_settings;
        new_settings.c_lflag &= (~ICANON);
        new_settings.c_cc[VTIME] = 0;
        new_settings.c_cc[VMIN] = 1;
        tcsetattr(0,TCSANOW,&new_settings);

	initializeField(field);
	shuffleField(field);
	findEmpty(field, &emptyX, &emptyY);
	printField(field, emptyX, emptyY, score);

	while (1) {
		btn = getchar(); 
		moveBrick(field, btn, &emptyX, &emptyY, &score);
		printField(field, emptyX, emptyY, score);
		if (checkWin(*field, btn) == 1) {
			winCase(score);
			break;
		}
	}

	tcsetattr(0,TCSANOW,&stored_settings);

	return 0;
}
