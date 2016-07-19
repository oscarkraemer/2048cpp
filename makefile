CPPFLAGS=-std=c++0x #-Wunused-comparison -lcurl
2048: main.o game.o getpage.o
	g++ $(CPPFLAGS) -lcurl game.o main.o getpage.o -o 2048
main.o: main.cpp standard.h
	g++ $(CPPFLAGS) -c main.cpp 
game.o: game.cpp game.h
	g++ $(CPPFLAGS) -c game.cpp
getpage.o: getpage.h getpage.cpp
	g++ $(CPPFLAGS) -lcurl -c getpage.cpp 
clean:
	rm *.o *.gch 2048a
