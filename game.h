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
	int board [4][4] ;//= {0};
	
	private:

		int length; //There is probably a better way

		int direction;
		void newBoard(int size);

		bool checkIfGameOver(); //Is not finished
		void insertNewNumber();
		
		//Move direction and execute move works together
		void moveDirection(std::string direct);
		bool executeMove(int start_x , int start_y, int check_x , int check_y);
		

		void PrintBoard();
		string getColourString(int num);

		int returnRandomPlate();
		string input();
		bool checkIfVictorius();
	public:
		bool startGame(int size);
};