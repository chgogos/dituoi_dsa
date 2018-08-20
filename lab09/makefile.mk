# makefile
CC=g++
CFLAGS=-Wall -std=c++11
EXECUTABLE=lab09_ex1

all: lab09_ex1 lab09_ex2

lab09_ex1: lab09_ex1.o binary_tree.o 
	$(CC) lab09_ex1.o binary_tree.o -o lab09_ex1

lab09_ex2: lab09_ex2.o bst.o
	$(CC) lab09_ex2.o bst.o -o lab09_ex2

%.o: %.cpp
	$(CC) -c $< $(CFLAGS)

clean: 
	rm *.o lab09_ex1 lab09_ex2
