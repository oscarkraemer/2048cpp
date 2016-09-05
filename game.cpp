#include "game.h"
#define SECRET_MESSAGE helloworld
int Game::startGame(int size, list<string>* history){
	this->length= size;
	newBoard(this->length);
	insertNewNumber();
	bool gameEnd = false;
	string message = "Press up, down, left, right or q for quit";
	do{
		insertNewNumber();
		if (checkIfGameOver() == true){
			break;
		}
		string oldString = uniqString();// This is used to check if a board move have been made.
		message = "Press up, down, left, right or q for quit";
		int d = NOT_SET;
		while (1){
			PrintBoard();
			d = input(message);
			if (d == QUIT){
				gameEnd=true;
				break;
			}
			moveDirection(d);	//left worked
			if (oldString != uniqString()){
				history->push_back(uniqString());
				break;
			}
			message = "You can't go there, try another button or q for quit";
		}
	}
	while(gameEnd==false);
	PrintBoard();
	return returnHighestNumber(); 
}

// Creates uniq number for the board state. There is probably a clearer way to do this
string Game::uniqString(){
	string code ="";
	for (int i=0; i<this->length; i++){
		for (int j=0; j<this->length; j++){
			code.append(to_string(this->board[i][j]));
			code.append("-");		
		}
	}
	return code;
}

void Game::newBoard(int size){
	board = new int*[size];
	for (int i=0; i<size; i++){
		board[i] = new int[size];
		for (int j=0; j<size; j++){
			this->board[i][j]=0;
		}
	}
}

int Game::returnRandomPlate(){
	//TODO: Create a better random
	srand(time(NULL));
	int num = rand() % 2 +1;
	num = pow( 2, num);
	return  num;
}

void Game::PrintBoard(){
	clearScreen();
	string head = "-";
	for (int i=0; i < this->length; i++){
		head.append("-----");
	}
	cout << head << endl;
	for (int i=0; i<this->length; i++){
		for (int j=0; j<this->length; j++){
			string colour = getColourString(this->board[i][j]);
			//You should check out this link for colourd output 
			// http://stackoverflow.com/questions/9158150/colored-output-in-c
			string s = to_string(this->board[i][j]);
			int slen = s.length();
			switch (slen){
				case 1:
					s = "  " + s + " ";
					break;
				case 2:
					s = " " + s + " ";
					break;
				case 3:
					s = s + " ";
					break;
			}
			if(this->board[i][j]==0){
				s="    ";
			}
			cout << "|" << colour << s << "\033[0m";
		}
		cout << "|" << endl;
	}
	cout << head << endl;
}

string Game::getColourString(int num){
	string colour;
	switch (num){
	case 2:
		colour="\033[31m";	//RED
		break;
	case 4:
		colour="\033[32m";	//GREEN
		break;
	case 8:
		colour="\033[33m";	//BLUE
		break;
	case 16:
		colour="\033[34m";	//PINK
		break;	
	case 32:
		colour="\033[35m";	//LIGHT BLUE
		break;
	case 64:
		colour="\033[36m";	//WHITE
		break;
	case 128:
		colour="\033[37m";
		break;
	case 256:
		colour="\033[31m";
		break;
	case 512:
		colour="\033[32m";
		break;
	case 1024:
		colour="\033[33m";
		break;
	case 2048:
		colour="\033[34m";
		break;
	default:
		colour="\033[37m";
		break;
	}
	return colour;
}


//TODO: Are there a for each element in an array?
void Game::insertNewNumber(){
	srand (time(NULL));
	int count = 0;
	for (int i=0; i<this->length; i++){
		for (int j=0; j<this->length; j++){
			if (this->board[i][j] == 0){
				count++;
			}
		}
	}
	count = rand() % count +1;
	//std::cout << count << std::endl;
	for (int i=0; i<this->length; i++){
		for (int j=0; j<this->length; j++){
			if (this->board[i][j] == 0){
				count--;
				if (count == 0){
					this->board[i][j] = returnRandomPlate();
				}
			}
		}
	}
}

bool Game::checkIfGameOver(){
	for (int i=0; i<this->length; i++){
		for (int j=0; j<this->length; j++){
			if (this->board[i][j]==0){
				return false;
			}
		}
	}
	for (int i=0; i<this->length; i++){
		for (int j=0; j<this->length-1; j++){
			if (this->board[i][j] == this->board[i][j+1]){
				return false;
			}else if (this->board[j][i] == this->board[j+1][i]){
				return false;
			}
		}
	}
	return true;
}

void Game::moveDirection(int direct){
	int legt = this->length;
	//Horizontal +1 ==left, -1 ==right, 0== doesn't move
	for(int i = 0; i < legt; i++){
		for (int j = 0; j < legt; j++){
			for (int k = j+1; k < legt; k++){
				bool contin =false;
				if(direct==LEFT){
					contin = executeMove(i,j,i,k);
				}else if(direct==RIGHT){
					contin = executeMove(i,legt-1-j,i,legt-1-k);
				}else if(direct==UP){
					contin = executeMove(j,i,k,i);
				}else if(direct==DOWN){
					contin = executeMove(legt-1-j, i, legt-1-k, i);
				}
				if(contin==false)
				break;
			}
		}
	}
}

//true==continue false==break
bool Game::executeMove(int start_x , int start_y, int check_x , int check_y){
	if (this->board[check_x][check_y] == 0) {
		return true;
	}else if (this->board[start_x][start_y]==this->board[check_x][check_y]){
		this->board[start_x][start_y] = 2*this->board[check_x][check_y];
		this->board[check_x][check_y] = 0;
		return false;
	}else if (this->board[start_x][start_y]==0){
		this->board[start_x][start_y] = this->board[check_x][check_y];
		this->board[check_x][check_y] = 0;
		return true;
	}else if (this->board[start_x][start_y] != this->board[check_x][check_y]) {
		return false;
	}
	return true;
}

int Game::input(string mess){
	int toReturn = NOT_SET;
  	cout << mess << endl; 	// Output prompt 
  	system("stty raw");   	// Set terminal to raw mode 
  	do{
  		char input = getchar();	// Wait for single character 
  		//cout << "-->" << input << "<--int->" << int(input) <<endl;
  		if (input == 'q'){
  			toReturn = QUIT;
  		}
  		//TODO: There should be a better way to do this
  		if (int(input)== 27){ 	// If possible arrow key
  			input = getchar();
  			input = getchar();
  			switch (int(input)){
			case 65:
				toReturn = UP;
				break;
			case 66:
				toReturn = DOWN;
				break;
			case 67:
				toReturn = RIGHT;
				break;
			case 68:
				toReturn = LEFT;
				break;
			}
		}
		if (input == 't'){
			system("stty cooked");
			PrintBoard();
			printf( "I'm Oscar, I wrote this code, don't tell anybody, sssh.\n");	
		  	system("stty raw");   	// Set terminal to raw mode 
		}
  	}while (toReturn==NOT_SET);

  	system("stty cooked"); 	// Reset terminal to normal "cooked" mode 
  	return toReturn;
}
bool Game::checkIfVictorius(){
	if (returnHighestNumber() >= WINNING_INT){
		return true;
	}else {
		return false;
	}
}
int Game::returnHighestNumber(){
	int highest = 0;
	for(int i = 0; i < this->length; i++){
		for (int j = 0; j < this->length; j++){
			if (this->board[i][j]>highest){
				highest = this->board[i][j];
			}
		}
	}
	return highest;
}

void Game::clearScreen()
{
	//I have no idea if this is a good way to do it. I added '\n' to the end to make sure the row start at the frame.
	printf("\n\033[2J\n");
}

