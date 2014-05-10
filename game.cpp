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
		gameEnd = checkIfGameOver();

		insertNewNumber();
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
	//TODO: Fix length so it is dynamic
	this->length = 4;

	insertNewNumber();
	insertNewNumber();
	insertNewNumber();
}

int Game::returnRandomPlate()
{
	//TODO return a Number by the rules of the game
	return  2;
}

void Game::PrintBoard()
{
	for (int i=0; i<this->length; i++)
	{
		for (int j=0; j<this->length; j++)
		{
			std::cout << "| " << this->board[i][j] << " " ;
		}
		std::cout << "|" << std::endl;

	}
	std::cout << "--------------------------------" << std::endl;


}

void Game::insertNewNumber()
{
	srand (time(NULL));
	int count = 0;
	for (int i=0; i<this->length; i++)
	{
		for (int j=0; j<this->length; j++)
		{

			if (this->board[i][j] == 0)
			{
				count++;
			}
		}
	}

	count = rand() % count +1;
	//std::cout << count << std::endl;

	for (int i=0; i<this->length; i++)
	{
		for (int j=0; j<this->length; j++)
		{
			if (this->board[i][j] == 0)
			{
				count--;
				if (count == 0)
				{
					this->board[i][j] = returnRandomPlate();
				}
			}
		}
	}
}

bool Game::checkIfGameOver()
{
	int count = 0;
	for (int i=0; i<this->length; i++)
	{
		for (int j=0; j<this->length; j++)
		{

			if (this->board[i][j] == 0)
			{
				count++;
			}
		}
	}
	if (count == (this->length*this->length))
	{
		return true;
	}
	return false;
}





