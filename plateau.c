//  this is file which contains every function that will be use on the file main.c
#include <stdio.h>
#include "plateau.h"

// This function will fill a bi-dimensionnal tab which will be use to containing blocks
//in the game
void Generate(char tab[LINE][COLUMN])
{
    for (int l = 0; l<LINE; l++)
    {
        for (int c = 0; c<COLUMN; c++)
        {
            tab[LINE][COLUMN] = ' ';
        }
    }
}
//This function show the grid during the whole game
void show_grid(char tab[LINE][COLUMN])
{
    printf("This is your grid:\n");
    // I made the 22th line in 1 line beause there is only one instruction
    for (int i=0; i<10; i++){printf(" %c", (char)65+i);}
    printf("\n");
    for (int l = 0; l<LINE; l++)
    {
        for (int c = 0; c<COLUMN; c++)
        {
            printf("|");
            printf("%c", tab[LINE][COLUMN]);
        }
        printf("|");
        printf("\n");
    }
}
