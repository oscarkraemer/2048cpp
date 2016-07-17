//using namespace std;
#include "game.h"
#include <iostream>

//Game * g = 0;
int main()
{
	std::cout << "Welcome to 2048 written in C++" << std::endl;
	Game g;
	bool victory = g.startGame(7);
	if (victory==true){
		std::cout << "Victory!" << std::endl;
	}
	else{
		std::cout << "You are a looser!" << std::endl;
	}
	return 0;
}
