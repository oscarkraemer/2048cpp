//using namespace std;
#include <iostream>

#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h> 		/* Power and sqr*/
#include <unistd.h>		/* Needed to make the random better*/
#include <string>		/* String parameter in movedirection*/
//#include <curses.h>
//#include <conio.h>
//#include <unistd.h>
//#include <termios.h>

using namespace std;

class Game
{
	int board [4][4] ;//= {0};
	
	private:
		int length;

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
	public:
		void startGame(int size);

		//Game();
//		int one;
//		int two;	
//		int GetDirection() { return direction; }
//		void calcDirect();
};