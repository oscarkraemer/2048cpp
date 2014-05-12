//using namespace std;
#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h> 		/* Power and sqr*/
#include <unistd.h>		/* Needed to make the random better*/
#include <string>		/* String parameter in movedirection*/

class Game
{
	int board [4][4] ;//= {0};
	
	private:
		int length;

		int direction;
		void newBoard(int size);

		bool checkIfGameOver();
		void insertNewNumber();

		void moveToRight();
		void moveToLeft();
		void moveDown();
		void moveUp();
		bool executeMove(int start_x , int start_y, int check_x , int check_y);
		void moveDirection(std::string direct);

		void PrintBoard();
		void GetDirection();
		int returnRandomPlate();

	public:
		void startGame(int size);

		//Game();
//		int one;
//		int two;	
//		int GetDirection() { return direction; }
//		void calcDirect();
};