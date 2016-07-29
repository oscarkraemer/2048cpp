#define STANDARD_SIZE 4
#include "standard.h"
#include "game.h"
#include "getpage.h"
#include <stdio.h>
#include <list>
#include <string>
#include <unistd.h>

//using namespace std;

int main(int argc, char* argv[] )
{

	string url = STANDARD_URL;
	int size = STANDARD_SIZE;
	string name = "place holder";
	int c; 
	while ((c = getopt (argc, argv, "tsnudh:")) != -1){
		switch (c)
		{
		case 't':
			printf("%s \n", optarg);
		case 's':
			size = atoi(optarg);
		case 'n':
			name = string( optarg );
			printf("n was pressed");
		case 'u':
			url = string(optarg);
			printf("u was pressed");
		case 'h':
			printf("this is help");
		case 'd':
		#ifdef ONLINE_ENABLED 
			const char* on = "Online is enabled";
		#else
			const char* on = "Online is disabled";
		#endif
 			// Leson: you can't use '"' around a defined variable, need to modify makefile to send '"'	
			const char* s = DATE_VARIABLE ;
			printf("It was compiled on this date: %s. %s\n", s, on);	
			exit(0);
		}
	}



	std::cout << "Welcome to a 2048 clone written in C++" << std::endl;

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
/* This is for printing out the log this should be considerd removing since it provides very little value
	
	for ( list<string>::iterator i = history.begin(); i!= history.end(); ++i )
		std::cout << '\n' << *i;
	std::cout << '\n';
*/

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
        string a = p.request_page(url.c_str() , &post);
        std::cout << a << std::endl;
#endif
	return 0;
}
