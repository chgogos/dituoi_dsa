CC=g++
CFLAGS=-std=c++11

all: lab08_ex2

lab08_ex2: lab08_ex2.o graph.o dijkstra.o
	$(CC) lab08_ex2.o graph.o dijkstra.o -o lab08_ex2

lab08_ex2.o: lab08_ex2.cpp
	$(CC) -c lab08_ex2.cpp $(CFLAGS)

graph.o: graph.cpp 
	$(CC) -c graph.cpp  $(CFLAGS)

dijkstra.o: dijkstra.cpp 
	$(CC) -c dijkstra.cpp  $(CFLAGS)

clean: 
	rm *.o lab08_ex2
