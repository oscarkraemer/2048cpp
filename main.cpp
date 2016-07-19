#define STANDARD_SIZE 4

#include "game.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	std::cout << "Welcome to 2048 written in C++" << std::endl;
	int size = STANDARD_SIZE;

	if (argc == 2 && isdigit(*argv[1])){
		size = atoi (argv[1]) ;
		if (size < 2){
			size = STANDARD_SIZE;
		}										 
	}
	Game g;
	bool victory = g.startGame(size);
	if (victory==true){
		std::cout << "Victory!" << std::endl;
	}
	else{
		std::cout << "You are a looser!" << std::endl;
	}
	return 0;
}
