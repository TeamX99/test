#include "game.h"

void AllNeighbor(S_PLAYER *pawns)
{
	int index;
	int i;

	for (index = 1; index < 13; ++index) {
		for (i = 0; i < 4; ++i) {
			pawns->pieces[index].Neighbor[i] = pawns->pieces[index].postition + Direction[i];
		}
	}
}


void UpdateInfoPeaces(S_PLAYER *pawns, int *aTab, int side)
{
	int index, i;

	i = 1;
	for (index = 0; index < 32; ++index) {
		if (side == WHITE) {
			if (aTab[ConverTo100[MoveFiled[index]]] == wPAWN) {
				pawns->pieces[i].postition = ConverTo100[MoveFiled[index]];
				pawns->PiecesNumbers += i;
				++i;
			}
		}
		else if(side == BLACK){
			if (aTab[ConverTo100[MoveFiled[index]]] == bPAWN) {
				pawns->pieces[i].postition = ConverTo100[MoveFiled[index]];
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
	getchar();

	printf("Select destiny: ");
	scanf("%d", &aTab[1]);
	getchar();

	--aTab[0];
	--aTab[1];
}


void move(int *board, int *PawnToMove)
{
	board[ConverTo100[MoveFiled[PawnToMove[1]]]] = board[ConverTo100[MoveFiled[PawnToMove[0]]]];
	board[ConverTo100[MoveFiled[PawnToMove[0]]]] = EMPTY;
}


void try_move(S_GAME *game, int *PawnToMove)
{
	int Neighbor[4];	//UP_LEFT, UP_RIGHT, D_RIGHT, D_LEFT
	int PossibleBeating[4] = { -1, -1, -1, -1 };
	int index, i;
	
	while (1) {
		if (game->board[ConverTo100[MoveFiled[PawnToMove[1]]]] != EMPTY) {
			printf("Invalid!\n");
			return;
		}

		if (((game->turn == WHITE) && (game->board[ConverTo100[MoveFiled[PawnToMove[0]]]] != wPAWN)) || ((game->turn == BLACK) && (game->board[ConverTo100[MoveFiled[PawnToMove[0]]]] != bPAWN))) {
			printf("Invalid!\n");
			return;
		}

		//beating if it is

		i = ConverTo100[MoveFiled[PawnToMove[0]]] - ConverTo100[MoveFiled[PawnToMove[1]]];
		index = 0;
		while (index < 4) {
			if ((i == Direction[index])) {
				move(game->board, PawnToMove);
				if (game->turn == WHITE) {
					UpdateInfoPeaces(&game->player[WHITE], game->board, game->turn);
					AllNeighbor(&game->player[game->turn]);
					game->turn = BLACK;
				}
				else {
					UpdateInfoPeaces(&game->player[BLACK], game->board, game->turn);
					AllNeighbor(&game->player[game->turn]);
					game->turn = WHITE;
				}
				return;
			}
			++index;
		}

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
	AllNeighbor(&game.player[WHITE]);
	AllNeighbor(&game.player[BLACK]);

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
