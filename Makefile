all : game
main.o : main.c plateau.h block.h
	gcc -c main.c -o main.o
plateau.o : plateau.c plateau.o
	gcc -c plateau.c -o plateau.o
block.o : block.c block.o
	gcc -c block.c -o block.o
game : main.o plateau.o block.o
	gcc plateau.o main.o block.o -o game

clean :
	rm -f *.o
	rm game
    