#define STANDARD_SIZE 4
#include "standard.h"
#include "game.h"
#include "getpage.h"
#include <stdio.h>
#include <list>

int main(int argc, char* argv[])
{
	std::cout << "Welcome to a 2048 clone written in C++" << std::endl;
	int size = STANDARD_SIZE;

	if (argc == 2 && isdigit(*argv[1])){
		size = atoi (argv[1]) ;
		// If the grid is less than 2x2 it crashes.
		if (size < 2){
			size = STANDARD_SIZE;
		}										 
	}
        list<string> history;
	Game g;
	int result = g.startGame(size, &history);
	if (result>=WINNING_INT){
		std::cout << "Victory!" << std::endl;
	}
	else{
		std::cout << "You are a looser!" << std::endl;
	}
	
	for ( list<string>::iterator i = history.begin(); i!= history.end(); ++i )
		std::cout << '\n' << *i;

	std::cout << '\n';


#ifdef ONLINE_ENABLED
// This is what makes the game post the result to a predefined URL. 
        Getpage p; 
        string value = to_string(result); // Convert result (int) 2048 => (string) "2048"
        string post = "points=";
	post.append(value);
	value = to_string(size);
        post.append("&size=");
	post.append(to_string(size));
        post.append( STANDARD_PREFIX ); // This could be removed or add support for something else. 
	char url[] = STANDARD_URL;
        string a = p.request_page(url , &post);
        std::cout << a << std::endl;
#endif
	return 0;
}
