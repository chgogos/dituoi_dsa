# makefile
CC=g++
CFLAGS=-Wall -std=c++11

all: binary_tree_ex1 bst_ex1 lab09_ex1

# binary tree
binary_tree_ex1: binary_tree_ex1.o binary_tree.o 
	$(CC) binary_tree_ex1.o binary_tree.o -o binary_tree_ex1

# binary search tree
bst_ex1: bst_ex1.o bst.o
	$(CC) bst_ex1.o bst.o -o bst_ex1

# example1
lab09_ex1: binary_tree.o lab09_ex1.o
	$(CC) binary_tree.o lab09_ex1.o -o lab09_ex1


%.o: %.cpp
	$(CC) -c $< $(CFLAGS)

clean: 
	rm *.o binary_tree_ex1 bst_ex1 lab09_ex1
