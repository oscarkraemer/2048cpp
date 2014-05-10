#include "game.h"
//using namespace std;
/**

Game::Game(): one("")
{
}
*/

/*
void game::calcDirect()
{
	one = 1;
    two = 2;	
    direction = one + two;
}

*/
/*
void Init()
{
	one=1;
}
*/
void Game::startGame()
{
	newBoard();
	bool gameEnd = false;
	do
	{
		PrintBoard();
		gameEnd = true;
	}
	while(gameEnd==false);
	
}

void Game::newBoard()
{

	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			this->board[i][j]=0;
		}
	}

	this->board[3][3] = 1337;

}

void Game::PrintBoard()
{
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			std::cout << "| " << this->board[i][j] << " " ;
		}
		std::cout << "|" << std::endl;

	}

}
