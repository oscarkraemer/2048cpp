CPPFLAGS=-std=c++0x #-Wunused-comparison -lcurl
DATE_VARIABLE=$(shell date +'"%Y-%m-%dT%H:%M:%S"')
2048: main.o game.o getpage.o 
	g++ $(CPPFLAGS) game.o main.o getpage.o -o 2048 -lcurl
main.o: main.cpp standard.h 
	g++ $(CPPFLAGS) -DDATE_VARIABLE='$(DATE_VARIABLE)' -c main.cpp 
game.o: game.cpp game.h
	g++ $(CPPFLAGS) -c game.cpp
getpage.o: getpage.h getpage.cpp
	g++ $(CPPFLAGS) -c getpage.cpp
main_online.o: main.cpp standard.h
	g++ $(CPPFLAGS) -DONLINE_ENABLED -DDATE_VARIABLE='$(DATE_VARIABLE)' -c main.cpp -o main_online.o
online: main_online.o game.o getpage.o 
	g++ $(CPPFLAGS) main_online.o game.o getpage.o -o 2048 -lcurl
 
clean:
	rm *.o *.gch 2048a
