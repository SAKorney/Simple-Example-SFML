CC=g++
CLIB=-lsfml-graphics -lsfml-window -lsfml-system

all:
	$(CC) main.cpp Engine.cpp Shape.cpp $(CLIB)
