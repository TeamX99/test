#include "board.h"

void ResetBoard(int *board)
{
	int index;
	
	for (index = 0; index < 100; ++index) {
		board[index] = BORDER;
	}

	for (index = 0; index < 64; ++index) {
		board[ConverTo100[index]] = BLOCKFIELD;
	}

	for (index = 0; index < 32; ++index) {
		board[ConverTo100[MoveFiled[index]]] = EMPTY;
	}

	for (index = 0; index < 12; ++index) {
		board[ConverTo100[MoveFiled[index]]] = bPAWN;
	}

	for (index = 20; index < 32; ++index) {
		board[ConverTo100[MoveFiled[index]]] = wPAWN;
	}
}


void PrintBoard(const int *board)
{
	int index;
	char pceChars[] = "- PqKk"; //EMPTY, wPAWN,  bPAWN, wKING, bKING

	printf("\n\nBoard:\n");
	for (index = 1; index <= 64; ++index) {
		if ((index % 8) == 0) {
			printf("%c", pceChars[board[ConverTo100[index - 1]]]);
			printf("\n");
		}
		else {
			printf("%c ", pceChars[board[ConverTo100[index - 1]]]);
		}
	}

	printf("\n");
}
