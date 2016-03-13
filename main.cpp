#include "main.h"
#include "game.h"

int main()
{
	if (GameEngine() != 1) {
		fprintf(stderr, "Game engine falied!\n");
		return -1;
	}

	getchar();

	return 0;
}
