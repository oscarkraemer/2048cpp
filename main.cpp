#define STANDARD_SIZE 4
#include "standard.h"
#include "game.h"
#include "getpage.h"
#include <stdio.h>
#include <list>
#include <string>
#include <unistd.h>

//using namespace std;

int help(){
	std::cout << 	" This is the help text: \n\n"
			" Possible options:\n\n"
			" -s <size> \tthe game field size <size>x<size>\n\n"
			" -n <name> \tyour name if you wnat it on the score board\n\n"
			" -u <URL> \tif the server is located somewhere else than what is set at compile\n\n"
			" -h Show this text\n\n"
			" -d Show when it is compiled and if online functionality is enabled\n\n"
			" -v Verbose mode\n\n";
	return 0;
}


int main(int argc, char* argv[] )
{

	const char* s = DATE_VARIABLE;
	string url = STANDARD_URL;
	int size = STANDARD_SIZE;
	string name = "place_holder";
	int c; 
	bool verbose = false;
#ifdef ONLINE_ENABLED 
	const char* on = "Online is enabled";
#else
	const char* on = "Online is disabled";
#endif
	// Leson: you can't use '"' around a defined variable, need to modify makefile to send '"'	
	while ((c = getopt (argc, argv, "n:u:dhs:v")) != -1){
		switch (c)
		{
		case 's':
			size = atoi(optarg);
			continue;
		case 'n':
			name = string( optarg );
			continue;
		case 'u':
			url =  string( optarg );
			continue;
		case 'h':
			help();
			exit(0);
		case 'd':
			printf("It was compiled on this date: %s. %s\n", s, on);	
			exit(0);
		case 'v':
			printf("It was compiled on this date: %s. %s\n", s, on);
			printf("The new URL is: %s \n", url.c_str());
			printf("Name set: %s \n", name.c_str());
			printf("The new size is: %d \n", size);
			verbose = true;
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
	printf("Sending...");
        Getpage p; 
        string value = to_string(result); // Convert result (int) 2048 => (string) "2048"
        string post = "points=";
	post.append(value);
	value = to_string(size);
        post.append("&size=");
	post.append(to_string(size));
        post.append( STANDARD_PREFIX ); // This could be removed or add support for something else. 
	string a = p.request_page(url.c_str() , &post);
	if (verbose == true){
        	std::cout << a << std::endl;
	}
	printf("...Sent\n");
#endif
	return 0;
}

