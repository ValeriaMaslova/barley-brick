#define N 4

void winCase(int score);
_Bool checkWin(int *f, unsigned char btn);

void moveBrick(int field[][N], unsigned char btn, int *x, int *y, int *score);

_Bool checkSolution(int field[][N]);
void initializeField(int field[][N]);
void shuffleField(int field[][N]);

void swap(int *a, int *b);
void printField(int field[][N], int x, int y, int score);
void findEmpty(int field[][N], int *x, int *y);
