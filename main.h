#ifndef _MAIN_H
#define _MAIN_H

/*	INCLUDE	*/
#include <stdio.h>


#define King_MAX_Range 7	// Move and beat range of king
#define Pawn_MAX_Range 2	// Range of beating, move range is equal 1

typedef struct {
	int postion;
	int range;
}S_PIECE;

typedef struct {
	S_PIECE pieces[13];	//Start from 1 to 12
	int PiecesNumbers;
	int BlockedPawn;
}S_PLAYER;

typedef struct {
	int board[100];
	S_PLAYER player[2];
	int turn;
	int ComPlayer;	//computer player
	/*
	0 - computer play white
	1 - computer play black
	2 - no computer player
	*/
	int MoveCount[2];
	int FiftenKingMove; //When players (play only king) make 25 move without beating the we have draw
	int GameEnd;
	int LastPawnUsedPosition;	//Information about pawn, that made last move
}S_GAME;

#endif // !_MAIN_H
