//using namespace std;
#include "game.h"
#include <iostream>

//Game * g = 0;
int main()
{
	std::cout << "Hello World!" << std::endl;
	//printf("hello World");
	
	//game *g = new game(); 
	
	/*
	game g;

	g.calcDirect();
	int two =g.one;
	std::cout << two << std::endl;
	
	*/

	Game g;
	g.startGame(4);
	std::cout << "victory" << std::endl;
	return 0;
}
