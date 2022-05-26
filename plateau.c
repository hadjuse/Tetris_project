//  this is file which contains every function that will be use on the file main.c
#include <stdio.h>
#include "plateau.h"
#include <stdlib.h>
#include "couleur.h"
#include <time.h>
#include <string.h>
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
    for (int i=0; i<10; i++){printf(" %d", i);}
    couleur("0");
    printf("\n");
    for (int l = 0; l<LINE; l++)
    {
        printf("\33[48;2;%d;%d;%dm", 3,34, 76);
        for (int c = 0; c<COLUMN; c++)
        {
            if (l<10 && l>=6)
            {
                couleur("32");
                printf("|");
                printf("%c", tab[l][c]);
            }
            else if(l<6 && l>=2)
            {
                couleur("33");
                printf("|");
                printf("%c", tab[l][c]);
            }
            else
            {
                couleur("31");
                printf("|");
                printf("%c", tab[l][c]);
            }
        }
        printf("|");
        couleur("0");
        printf("\n");
    }
}
