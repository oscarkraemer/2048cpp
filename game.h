//using namespace std;
#define NOT_SET 0
#define QUIT 1
#define LEFT 10
#define RIGHT 11
#define UP 12
#define DOWN 13
#define WINNING_INT 2048 //The default value could be 2048

#include <stdio.h>      // printf, NULL 
#include <iostream>
#include <stdlib.h>     // srand, rand 
#include <time.h>       // time 
#include <math.h> 	// Power and sqr
#include <string>	



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
		void moveDirection(int direct);
		bool executeMove(int start_x , int start_y, int check_x , int check_y);

		void PrintBoard();
		string getColourString(int num);
		void clearScreen();

		int returnRandomPlate();
		int input(string mess);
		bool checkIfVictorius();
		int returnHighestNumber();
		string uniqNumber();

	public:
		int startGame(int size);
};
