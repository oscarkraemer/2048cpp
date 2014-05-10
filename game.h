//using namespace std;
#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Game
{
	int board [4][4] ;//= {0};
	
	private:
		int length;

		int direction;
		void newBoard();

		bool checkIfGameOver();
		void insertNewNumber();

		void moveToRight();
		void moveToLeft();
		void moveDown();
		void moveUp();

		void PrintBoard();
		void GetDirection();
		int returnRandomPlate();

	public:
		void startGame();

		//Game();
//		int one;
//		int two;	
//		int GetDirection() { return direction; }
//		void calcDirect();
};