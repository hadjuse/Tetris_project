//  this is file which contains every function that will be use on the file main.c
#include <stdio.h>
#include "plateau.h"
#include <stdlib.h>
#include "couleur.h"

// This function will fill a bi-dimensionnal tab which will be use to containing blocks
//in the game
void Generate(char tab[LINE][COLUMN])
{
    for (int l = 0; l<LINE; l++)
    {
        for (int c = 0; c<COLUMN; c++)
        {
            tab[l][c] =' ';
        }
    }
}
//This function show the grid during the whole game
void show_grid(char tab[LINE][COLUMN])
{
    printf("This is your grid:\n");
    // I made the 23th line in 1 line beause there is only one instruction
    couleur("35");
    for (int i=0; i<10; i++){printf(" %c", (char)65+i);}
    couleur("0");
    printf("\n");
    for (int l = 0; l<LINE; l++)
    {
        printf("\33[48;2;%d;%d;%dm", 204, 255, 255);
        couleur("34");
        for (int c = 0; c<COLUMN; c++)
        {
            
            printf("|");
            //printf("\33[38;2;%d;%d;%dm", rand()%256, rand()%256, rand()%256);
            printf("%c", tab[l][c]);
            
        }
        printf("|");
        couleur("0");
        printf("\n");
    }
}
