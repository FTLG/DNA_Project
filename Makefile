# Author: Felixander Kery, George Perry, Max Mullen, Duncan Park
# E-mail: fkery@nd.edu, gperry@nd.edu, dpark6@nd.edu, mmullen5@nd.edu
# Date: 4/18/22
#
# This is the Makefile for the Final Project

# g++ is for the GCC compiler for C++
CC := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CXXFLAGS := -m64 -std=c++11 $(FLAGS)

# Folder Variables
INC := include
SRC := src
OBJ := objects
EXE := exe

# Make initialize - Create the objects and executables

initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)


# Run Compilation Command
# Command: make PC07

$(OBJ)/DNA.o: $(SRC)/DNA.cpp
	$(CC) $(CXXFLAGS) -c $(SRC)/DNA.cpp -o $@

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CXXFLAGS) -c $(SRC)/main.cpp -o $@

mainObjs :=  $(OBJ)/main.o $(OBJ)/DNA.o

main: $(initialize) $(mainObjs)
	$(CC) $(CXXFLAGS) -o $(EXE)/main $(mainObjs)
	

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
