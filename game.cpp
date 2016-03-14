#include "game.h"


void UpdateInfoPeaces(S_PLAYER *pawns, int *aTab, int side)
{
	int index, i;

	i = 1;
	for (index = 0; index < 32; ++index) {
		if (side == WHITE) {
			if (aTab[ConverTo100[MoveFiled[index]]] == wPAWN) {
				pawns->pieces[i] = ConverTo100[MoveFiled[index]];
				pawns->PiecesNumbers += i;
				++i;
			}
		}
		else if(side == BLACK){
			if (aTab[ConverTo100[MoveFiled[index]]] == bPAWN) {
				pawns->pieces[i] = ConverTo100[MoveFiled[index]];
				pawns->PiecesNumbers += i;
				++i;
			}
		}
	}
}

int GameEngine(void)
{
	S_GAME game;
	
	game.turn = WHITE;
	game.GameEnd = 0;
	game.player[WHITE].PiecesNumbers = 0;
	game.player[BLACK].PiecesNumbers = 0;

	ResetBoard(game.board);
	PrintBoard(game.board);
	UpdateInfoPeaces(&game.player[WHITE], game.board, WHITE);
	UpdateInfoPeaces(&game.player[BLACK], game.board, BLACK);


	while (game.GameEnd == 0) {

		
		game.GameEnd = 1;
	}


	return 1;
}
