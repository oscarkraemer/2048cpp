#define STANDARD_SIZE 4
#include "standard.h"
#include "game.h"
#include "getpage.h"
#include <stdio.h>
#include <list>
#include <string>
#include <unistd.h>
#include <sstream>
//using namespace std;

int help(){
	std::cout << 	" This is the help text: \n\n"
			" Possible options:\n\n"
			" -s <size> \tthe game field size <size>x<size>\n\n"
			" -n <name> \tyour name if you wnat it on the score board\n\n"
			" -u <URL> \tif the server is located somewhere else than what is set at compile\n\n"
			" -h \t\tShow this text\n\n"
			" -d \t\tShow when it is compiled and if online functionality is enabled\n\n"
			" -v \t\tVerbose mode\n\n"
			" -o \t\tOfline mode\n\n";
	return 0;
}

int main(int argc, char* argv[] ){

	const char* compile_date = DATE_VARIABLE;
	string url = STANDARD_URL;
	int size = STANDARD_SIZE;
	string name = "place_holder";
	int c; 
	bool verbose = false;
	bool testing = false;
	bool upload = true;
#ifdef ONLINE_ENABLED 
	const char* on = "Online is enabled";
#else
	const char* on = "Online is disabled";
#endif
	// Leson: you can't use '"' around a defined variable, need to modify makefile to send '"'	
	while ((c = getopt (argc, argv, "n:u:dhs:vto")) != -1){
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
			printf("It was compiled on this date: %s. %s\n", compile_date, on);	
			exit(0);
		case 'v':
			printf("It was compiled on this date: %s. %s\n", compile_date, on);
			printf("The new URL is: %s \n", url.c_str());
			printf("Name set: %s \n", name.c_str());
			printf("The new size is: %d \n", size);
			verbose = true;
			continue;
		case 't':
			testing = true;
			continue;
		case 'o':
			upload = false;
			continue;
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
	int result = 0;
	if (testing == false ) {
		result = g.startGame(size, &history);
	}
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
	if( upload ){
		if ( verbose ){
			printf("Sending...\n");
		}
		std::stringstream ss;
		ss << "name=" << name << "&points=" << result << "&size=" << size << "&version=" << compile_date << "&prefix=" << STANDARD_PREFIX ;
		string post = ss.str();
		Getpage p;
		string a = p.request_page(url.c_str() , &post);
		if (verbose ){
			std::cout << a << std::endl;
			printf("...Sent\n");
		}
	}
#endif
	return 0;
}

