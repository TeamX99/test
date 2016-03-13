#include "game.h"

void move()
{

}

int capture_possible()
{
	return 0;
}

int futher_capture_possible()
{
	return 0;
}

void try_to_make_move(int *PawnToMove, int &further_capture, S_GAME *game)
{

}


void GetHumanMove(int *PawnToMove)
{
	printf("Chose pawn: ");
	scanf("%d", &PawnToMove[0]);

	printf("Set destini positions: ");
	scanf("%d", &PawnToMove[1]);

	--PawnToMove[0];
	--PawnToMove[1];
}

void GetHumanMove(int *PawnToMove, int PawnOnBeating)
{
	PawnToMove[0] = PawnOnBeating;

	printf("Set destini positions: ");
	scanf("%d", &PawnToMove[1]);

	--PawnToMove[1];
}

int GameEngine(void)
{
	S_GAME game;
	
	ResetBoard(game.board);
	PrintBoard(game.board);

	return 1;
}