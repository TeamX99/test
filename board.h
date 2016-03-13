#ifndef _BOARD_H
#define _BOARD_H

/*	INCLUDE	*/
#include "main.h"
//#include <allegro5\allegro.h>

/*	DEFINE	*/


enum { BORDER = -1, BLOCKFIELD, EMPTY, wPAWN, bPAWN };

/*	GLOBAL	*/
const int ConverTo100[64] = {
	11, 12, 13, 14, 15, 16, 17, 18,
	21, 22, 23, 24, 25, 26, 27, 28,
	31, 32, 33, 34, 35, 36, 37, 38,
	41, 42, 43, 44, 45, 46, 47, 48,
	51, 52, 53, 54, 55, 56, 57, 58,
	61, 62, 63, 64, 65, 66, 67, 68,
	71, 72, 73, 74, 75, 76, 77, 78,
	81, 82, 83, 84, 85, 86, 87, 88
};
//Array that include fileds numbers, where pawn can move
const int MoveFiled[32] = {
	1, 3, 5, 7,
	8, 10, 12, 14,
	17, 19, 21, 23,
	24, 26, 28, 30,
	33, 35, 37, 39,
	40, 42, 44, 46,
	49, 51, 53, 55,
	56, 58, 60, 62
};

/*	FUNCTIONS	*/
void ResetBoard(int *board);
void PrintBoard(const int *board);

#endif // _BOARD_H
