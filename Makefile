all : game
main.o : main.c plateau.o block.o game.o couleur.o score.o
	gcc -c main.c -o main.o
plateau.o : plateau.c plateau.o
	gcc -c plateau.c -o plateau.o
block.o : Block.c Block.h
	gcc -c Block.c -o block.o
couleur.o : couleur.c couleur.h
score.o: score.c score.h
	gcc -c score.c -o score.o
game.o : game.c game.h
game : main.o plateau.o block.o game.o score.o couleur.o
	gcc plateau.o main.o block.o game.o couleur.o score.o -o game

clean :
	rm -f *.o
	rm game
    
