# makefile example for lab08_ex2 (version 3)
CC=g++
CFLAGS=-Wall -std=c++11
EXECUTABLE=lab08_ex2

all: lab08_ex2

lab08_ex2: lab08_ex2.o graph.o dijkstra.o
	$(CC) lab08_ex2.o graph.o dijkstra.o -o $(EXECUTABLE)

%.o: %.cpp
	$(CC) -c $< $(CFLAGS)

clean: 
	rm *.o lab08_ex2
