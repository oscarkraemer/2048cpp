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
void Game::startGame(int size)
{
	this->length= size;
	newBoard(this->length);

	bool gameEnd = false;
	do
	{
		PrintBoard();
		gameEnd = checkIfGameOver();

		insertNewNumber();
		moveDirection("left");	//left worked

	}
	while(gameEnd==false);
}

void Game::newBoard(int size)
{

	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			this->board[i][j]=0;
		}
	}

	//This is not necessary anymore
	//std::cout << sqrt(sizeof(this->board)/sizeof(int))<< std::endl;
	//this->length = sqrt(sizeof(this->board)/sizeof(int));

	insertNewNumber();
	insertNewNumber();
	insertNewNumber();
}

int Game::returnRandomPlate()
{
	//TODO: Create a better random
	usleep(500000);
	srand (time(NULL));
	int num = rand() % 2 +1;
	num = pow( 2, num);
	return  num;
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
/*
void Game::executeMove(int horizontal, int verticle)
{
	int h_start = 0;
	int v_start = 0;

	if (horizontal == -1)
	{
		h_start = this->length - 1;

	}
	if (verticle == -1)
	{
		v_start = this->length - 1;
	}

	for (int i = 0; i < this->length; i++)
	{
		this->board[h_start][v_start] = this->board[h_start+horizontal][v_start+verticle];
	}
}
*/

void Game::moveToLeft()
{
	int legt = this->length;

	//Horizontal +1 ==left, -1 ==right, 0== doesn't move


	for(int i = 0; i < legt; i++)
	{
		for (int j = 0; j < legt; j++)
		{
			for (int k = j+1; k < legt; k++)
			{
				if (this->board[i][k] == 0)
				{
					continue;
				}
				else if (this->board[i][j]==this->board[i][k])
				{
					this->board[i][j] = 2*this->board[i][j];
					this->board[i][k] = 0;
					break;
				}
				else if (this->board[i][j]==0)
				{
					this->board[i][j] = this->board[i][k];
					this->board[i][k] = 0;
					break;
				}
				else if (this->board[i][j] != this->board[i][k])
				{
					break;
				}
			}
		}
	}
}
void Game::moveDirection(std::string direct)
{
	int legt = this->length;

	//Horizontal +1 ==left, -1 ==right, 0== doesn't move
	for(int i = 0; i < legt; i++)
	{
		for (int j = 0; j < legt; j++)
		{
			for (int k = j+1; k < legt; k++)
			{
				bool contin =false;
				if(direct=="left")
				{
					contin = executeMove(i,j,i,k);
				}
				else if(direct=="right")
				{
					contin = executeMove(i,legt-1-j,i,legt-1-k);
				}
				else if(direct=="down")
				{
					contin = executeMove(j,i,j,k);
				}

				else if(direct=="up")
				{
					contin = executeMove(legt-1-j, i, legt-1-k, i);
				}

				/*
				switch (direct)
				{
					case 'down':
						contin = executeMove(j,i,j,k); //Down
						break;
					case 'left':
						contin = executeMove(i,j,i,k); //Left
						break;
					case 'right':
						contin = executeMove(i,legt-j,i,legt-k)
						break;
					case 'up' :
						contin = executeMove(legt-j, i, legt-k, i);
						break;
				}
				*/
				if(contin==false)
				{
					break;
				}
			}
		}
	}
}

//false==continue true==break
bool Game::executeMove(int start_x , int start_y, int check_x , int check_y)
{

	if (this->board[check_x][check_y] == 0)
	{
		return true;
	}
	else if (this->board[start_x][start_y]==this->board[check_x][check_y])
	{
		this->board[start_x][start_y] = 2*this->board[check_x][check_y];
		this->board[check_x][check_y] = 0;
		return false;
	}
	else if (this->board[start_x][start_y]==0)
	{
		this->board[start_x][start_y] = this->board[check_x][check_y];
		this->board[check_x][check_y] = 0;
		return false;
	}
	else if (this->board[start_x][start_y] != this->board[check_x][check_y])
	{
		return false;
	}
	return true;
}


