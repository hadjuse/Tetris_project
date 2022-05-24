//  this is file which contains every function that will be use on the file main.c
#include <stdio.h>
#include "plateau.h"
#include <stdlib.h>

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
    for (int i=0; i<10; i++){printf(" %c", (char)65+i);}
    printf("\n");
    //printf("\33[48;2;%d;%d;%d", rand()%256, rand()%256, rand()%256);
    for (int l = 0; l<LINE; l++)
    {
        for (int c = 0; c<COLUMN; c++)
        {
            printf("|");
            printf("%c", tab[l][c]);
        }
        printf("|");
        printf("\n");
    }
}
