# makefile example for lab08_ex2 (version 1)

lab08_ex2: lab08_ex2.o graph.o dijkstra.o
	g++ lab08_ex2.o graph.o dijkstra.o -o lab08_ex2

lab08_ex2.o: lab08_ex2.cpp
	g++ -c lab08_ex2.cpp -std=c++11

graph.o: graph.cpp 
	g++ -c graph.cpp -std=c++11

dijkstra.o: dijkstra.cpp 
	g++ -c dijkstra.cpp -std=c++11