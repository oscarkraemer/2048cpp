//using namespace std;
#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h> 		/* Power and sqr*/
#include <string>		/* String parameter in movedirection*/



using namespace std;

class Game
{
	int** board;
	
	private:

		int length; //There is probably a better way
		void newBoard(int size);

		bool checkIfGameOver(); //Is not finished
		void insertNewNumber();
		//Move direction and execute move works together
		void moveDirection(std::string direct);
		bool executeMove(int start_x , int start_y, int check_x , int check_y);

		void PrintBoard();
		string getColourString(int num);
		void clearScreen();

		int returnRandomPlate();
		string input(string mess);
		bool checkIfVictorius();
		string uniqNumber();

	public:
		bool startGame(int size);
};
