#ifndef _MAIN_H
#define _MAIN_H

/*	INCLUDE	*/
#include <stdio.h>

enum { UP_LEFT, UP_RIGHT, D_RIGHT, D_LEFT };

const int MoveTab[4] = { -11, -9, 11, 9 };

typedef struct {
	int pieces[13];	//Start from 1 to 12
	int PiecesNumbers;
}S_PLAYER;

typedef struct {
	int board[100];
	S_PLAYER player[2];
	int turn;
	int GameEnd;
}S_GAME;

#endif // !_MAIN_H
