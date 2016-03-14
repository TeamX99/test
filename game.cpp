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
	PawnToMove[1] = -1;
}


void CheckBeating(S_GAME **game, int *PawnToMove)
{
	int index, i, j;
	
	for (index = 1; index < 13; ++index) {
		if ((*game)->player[(*game)->turn].pieces[index].postition == ConverTo100[MoveFiled[PawnToMove[0]]]) {
			i = index;
			break;
		}
	}

	if (PawnToMove[1] != -1) {	//First check beating
		for (index = 0; index < 4; ++index) {
			if ((*game)->turn == WHITE) {
				if ((*game)->board[(*game)->player[(*game)->turn].pieces[i].Neighbor[index]] == bPAWN) {
					for (j = 0; j < 4; ++j) {
						if ((*game)->player[(*game)->turn].pieces[i].Neighbor[index] + Direction[j] == ConverTo100[MoveFiled[PawnToMove[1]]]) {
							(*game)->board[(*game)->player[(*game)->turn].pieces[i].Neighbor[index]] = EMPTY;
							move((*game)->board, PawnToMove);
							PawnToMove[1] = -1;
							UpdateInfoPeaces(&(*game)->player[WHITE], (*game)->board, WHITE);
							UpdateInfoPeaces(&(*game)->player[BLACK], (*game)->board, BLACK);
							AllNeighbor(&(*game)->player[WHITE]);
							AllNeighbor(&(*game)->player[BLACK]);
							return;
						}
					}
				}
			}
			else if ((*game)->turn == BLACK) {
				if ((*game)->player[(*game)->turn].pieces[i].Neighbor[index] == wPAWN) {
					for (j = 0; j < 4; ++j) {
						if ((*game)->player[(*game)->turn].pieces[i].Neighbor[index] + Direction[j] == ConverTo100[MoveFiled[PawnToMove[1]]]) {
							(*game)->board[(*game)->player[(*game)->turn].pieces[i].Neighbor[index]] = EMPTY;
							move((*game)->board, PawnToMove);
							PawnToMove[1] = -1;
							UpdateInfoPeaces(&(*game)->player[WHITE], (*game)->board, WHITE);
							UpdateInfoPeaces(&(*game)->player[BLACK], (*game)->board, BLACK);
							AllNeighbor(&(*game)->player[WHITE]);
							AllNeighbor(&(*game)->player[BLACK]);
							return;
						}
					}
				}
			}
		}
	}
	else {
		return;
	}
}


void try_move(S_GAME *game, int *PawnToMove)
{
	int index, i;
	
	while (1) {
		if (game->board[ConverTo100[MoveFiled[PawnToMove[1]]]] != EMPTY) {
			printf("Invalid_1!\n");
			return;
		}

		if (((game->turn == WHITE) && (game->board[ConverTo100[MoveFiled[PawnToMove[0]]]] != wPAWN)) || ((game->turn == BLACK) && (game->board[ConverTo100[MoveFiled[PawnToMove[0]]]] != bPAWN))) {
			printf("Invalid_2!\n");
			return;
		}

		CheckBeating(&game, PawnToMove);

		i = ConverTo100[MoveFiled[PawnToMove[0]]] - ConverTo100[MoveFiled[PawnToMove[1]]];
		if ((((i == Direction[0]) || (i == Direction[1])) && (game->turn == BLACK)) || (((i == Direction[2]) || (i == Direction[3])) && (game->turn == WHITE))) {
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
		else {
			printf("Invalid!\n");
			return;
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
		GetHumanMove(PawnToMove);
		try_move(&game, PawnToMove);
		PrintBoard(game.board);
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
