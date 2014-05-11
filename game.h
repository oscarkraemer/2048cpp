//using namespace std;
#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h> 		/* Power and sqr*/
#include <unistd.h>		/* Needed to make the random better*/

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