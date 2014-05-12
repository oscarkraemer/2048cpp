#include "game.h"

void Game::startGame(int size)
{
	this->length= size;
	newBoard(this->length);

	bool gameEnd = false;
	PrintBoard();
	do
	{
		insertNewNumber();
		gameEnd = checkIfGameOver();
		string d = input();
		if (d == "quit")
		{
			gameEnd=true;
		}
		moveDirection(d);	//left worked
		PrintBoard();
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
				else if(direct=="up")
				{
					contin = executeMove(j,i,k,i);
				}

				else if(direct=="down")
				{
					contin = executeMove(legt-1-j, i, legt-1-k, i);
				}

				if(contin==false)
				{
					break;
				}
			}
		}
	}
}

//true==continue false==break
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

string Game::input()
{
	string toReturn = "false";
  	cout << "Press up, down, left, right or q for quit" << endl; 	// Output prompt 
  	do{
  		system("stty raw");   // Set terminal to raw mode 
  		char input = getchar();// Wait for single character 

  		//cout << "-->" << input << "<--int->" << int(input) <<endl;

  		if (input == 'q'){
  			toReturn = "quit";
  		}
  		//TODO: There should be a correct way to do this
  		if (int(input)== 27) // If possible arrow key
  		{
  			input = getchar();
  			input = getchar();
  			switch (int(input))
  			{
  				case 65:
  					toReturn = "up";
  					break;
  				case 66:
  					toReturn = "down";
  					break;
  				case 67:
  					toReturn = "right";
  					break;
  				case 68:
  					toReturn = "left";
  					break;

  			}

  		}
  	}while (toReturn=="false");
  
  	system("stty cooked"); // Reset terminal to normal "cooked" mode 
  	return toReturn;
}


