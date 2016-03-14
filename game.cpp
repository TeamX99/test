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

void GetHumanMove(int *aTab)
{
	printf("Select pawn: ");
	scanf("%d", &aTab[0]);

	printf("Select destiny: ");
	scanf("%d", &aTab[1]);

	--aTab[0];
	--aTab[1];
}

void try_move(S_GAME *game, int *PawnToMove)
{
	int Neighbor[4];
	int CountIfBeating = 0;
	int index;
	
	if (PawnToMove[1] != EMPTY) {
		printf("Invalid!\n");
		return;
	}

	if (((game->turn == WHITE) && (PawnToMove[0] != wPAWN)) || ((game->turn == BLACK) && (PawnToMove[0] != bPAWN))) {
		printf("Invalid!\n");
		return;
	}

	index = 0;
	while (index < 4) {
		Neighbor[index] = ConverTo100[MoveFiled[PawnToMove[0] + Direction[index]]];
		index++;
	}

}

int GameEngine(void)
{
	S_GAME game;
	int PawnToMove[2];
	
	game.turn = WHITE;
	game.GameEnd = 0;
	game.player[WHITE].PiecesNumbers = 0;
	game.player[BLACK].PiecesNumbers = 0;

	ResetBoard(game.board);
	PrintBoard(game.board);
	UpdateInfoPeaces(&game.player[WHITE], game.board, WHITE);
	UpdateInfoPeaces(&game.player[BLACK], game.board, BLACK);


	while (game.GameEnd == 0) {

		GetHumanMove(PawnToMove);
		try_move(&game, PawnToMove);
		PrintBoard(game.board);
		GetHumanMove(PawnToMove);
		try_move(&game, PawnToMove);
		PrintBoard(game.board);
		
		game.GameEnd = 1;
	}


	return 1;
}
