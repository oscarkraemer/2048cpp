CPPFLAGS=-std=c++0x
2048a: main.o game.o
	g++ $(CPPFLAGS) game.o main.o -o 2048a
main.o: main.cpp
	g++ $(CPPFLAGS) -c main.cpp 
game.o: game.cpp game.h
	g++ $(CPPFLAGS) -c game.h game.cpp
clean:
	rm *.o *.gch 2048a
