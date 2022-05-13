#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Block.h"
#include "plateau.h"
#define LINE 10
#define COLUMN 10
#define LINE_B 4
#define COLUMN_B 4
void game()
{
    char block[LINE_B][COLUMN_B];
    char grid[LINE_G][COLUMN_G];
    Generate(grid);
    //show_grid(grid);
    for (int i =0; i <8; i++)    
    {
        int column=choose_col(block); 
        collision(grid,block, column-1);
        printf("\n");
        show_block(block);
        show_grid(grid);    
    }
}
