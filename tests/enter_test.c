#include "ctest.h"

const char RIGHT = 'a';
const char LEFT = 'd';
const char UP = 's';
const char DOWN = 'w';

CTEST(move_bricks_around, move_bricks)   //movement of bricks, hit the borders
{
  int field[4][4], x = 0, y = 0, score = 0;

  initializeField(field);

  const int EXP_X_RIGHT = 1;
  const int EXP_X_LEFT = 0;
  const int EXP_Y_DOWN = 1;
  const int EXP_Y_UP = 0;
                                            // At the beginning x = 0  y = 0
  moveBrick(field, RIGHT, &x, &y, &score);  //move right (x + 1)
  ASSERT_DBL_NEAR(EXP_X_RIGHT, x);

  moveBrick(field, LEFT, &x, &y, &score);  //move left (x - 1)
  ASSERT_DBL_NEAR(EXP_X_LEFT, x);

  moveBrick(field, DOWN, &x, &y, &score);  //move down (y + 1)
  ASSERT_DBL_NEAR(EXP_Y_DOWN, y);

  moveBrick(field, UP, &x, &y, &score);    //move up (y - 1)
  ASSERT_DBL_NEAR(EXP_Y_UP, y);
}

CTEST(move_bricks_on_border, move_bricks)
{
  int field[4][4], x = 0, y = 0, score = 0;

  initializeField(field);

  const int EXP_CORNER_X = 0;
  const int EXP_CORNER_Y = 0;

  moveBrick(field, UP, &x, &y, &score);    //hit upper border (y still the same)
  ASSERT_DBL_NEAR(EXP_CORNER_Y, y);

  moveBrick(field, LEFT, &x, &y, &score);  //hit left border (x still the same)
  ASSERT_DBL_NEAR(EXP_CORNER_X, x);

  x = 3;
  y = 3;

  const int EXP_CORNER_X_D = 3;
  const int EXP_CORNER_Y_D = 3;


  moveBrick(field, RIGHT, &x, &y, &score);  //hit right border (x still the same)
  ASSERT_DBL_NEAR(EXP_CORNER_X_D, x);

  moveBrick(field, LEFT, &x, &y, &score);  //hit bottom border (y still the same)
  ASSERT_DBL_NEAR(EXP_CORNER_Y_D, y);

}

CTEST(score_normal_move, score)
{
  int field[4][4], x = 1, y = 1, score = 0;
  initializeField(field);

  const int EXP_SCORE = 1;

  moveBrick(field, DOWN, &x, &y, &score);
  ASSERT_DBL_NEAR(EXP_SCORE, score);

  score = 0;

  moveBrick(field, RIGHT, &x, &y, &score);
  ASSERT_DBL_NEAR(EXP_SCORE, score);

  score = 0;

  moveBrick(field, UP, &x, &y, &score);
  ASSERT_DBL_NEAR(EXP_SCORE, score);

  score = 0;

  moveBrick(field, LEFT, &x, &y, &score);
  ASSERT_DBL_NEAR(EXP_SCORE, score);
}

CTEST(score_move_on_border, score)
{
  int field[4][4], x = 0, y = 0, score = 0;
  initializeField(field);

  const int EXP_SCORE_OB = 0;

  moveBrick(field, LEFT, &x, &y, &score);
  ASSERT_DBL_NEAR(EXP_SCORE_OB, score);

  moveBrick(field, UP, &x, &y, &score);
  ASSERT_DBL_NEAR(EXP_SCORE_OB, score);

  x = 3;
  y = 3;

  moveBrick(field, RIGHT, &x, &y, &score);
  ASSERT_DBL_NEAR(EXP_SCORE_OB, score);

  moveBrick(field, DOWN, &x, &y, &score);
  ASSERT_DBL_NEAR(EXP_SCORE_OB, score);
}
