#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void winCase(int score)
{
	system("clear"); 
	printf("\nYou win!\nScore : %d\n", score - 1);

}

_Bool checkWin(int *f, unsigned char btn) {
	int i;
	if (*(f + 4 * 4 - 1) != 0) return 0;
	for (i = 0; i < 4 * 4 - 2; i++) {
		if ((*(f + i) > *(f + i + 1)) && (*(f + i + 1) != 0)) {
			return 0;
		}
	}
	if (btn == 'i') return 1;
	return 1;
}
