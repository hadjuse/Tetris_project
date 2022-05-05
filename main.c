#include <stdio.h>
#include <stdlib.h>
#include "Block.h"
#include "plateau.h"
#define LINE 10
#define COLUMN 10
#define LINE_B 4
#define COLUMN_B 4
//this file is the main execution of all programms.
int main()
{
    char block[LINE_B][COLUMN_B];
    char grid[LINE][COLUMN];
    Generate(grid);
    //show_grid(grid);
    Gen_block(block);
    int column;
    printf("Choisir colonne entre 1 et 10\n");
    scanf("%d", &column);
    place_piece(block,grid, column-1);
    printf("\n");
    show_block(block);
    show_grid(grid);
    return 0;
}