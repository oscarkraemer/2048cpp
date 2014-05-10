//using namespace std;
#include <iostream>

class Game
{
	//const
	int board [4][4] ;//= {0};
	private:
		

		int direction;
		void newBoard();

		void checkIfGameOver();
		void insertNewNumber();

		void moveToRight();
		void moveToLeft();
		void moveDown();
		void moveUp();

		void PrintBoard();
		void GetDirection();

	public:
		void startGame();

		//Game();
//		int one;
//		int two;	
//		int GetDirection() { return direction; }
//		void calcDirect();
};