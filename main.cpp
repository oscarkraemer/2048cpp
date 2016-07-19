#define STANDARD_SIZE 4
#define ONLINE_ENABLED true
#include "standard.h"
#include "game.h"
#include "getpage.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	std::cout << "Welcome to 2048 written in C++" << std::endl;
	int size = STANDARD_SIZE;

	if (argc == 2 && isdigit(*argv[1])){
		size = atoi (argv[1]) ;
		if (size < 2){
			size = STANDARD_SIZE;
		}										 
	}
	Game g;
	bool victory = g.startGame(size);
	if (victory==true){
		std::cout << "Victory!" << std::endl;
	}
	else{
		std::cout << "You are a looser!" << std::endl;
	}
        Getpage p;
        string post = "points=0&timestamp=zero";      
#ifdef ONLINE_ENABLED 
	char url[] = STANDARD_URL;
        string a = p.request_page(url , &post);
        std::cout << a << std::endl;
#endif
	return 0;
}
