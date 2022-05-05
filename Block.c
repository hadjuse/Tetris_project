#include <stdio.h>
#include "Block.h"
#include "plateau.h"
#define LINE_B 4
#define COLUMN_B 4
#define LINE_G 10
#define COLUMN_G 10
void clean_Block(char block[LINE_B][COLUMN_B])
{
    for (int l = 0; l<LINE_B; l++)
    {
        for (int c = 0; c<COLUMN_B; c++)
        {
            block[l][c] = ' ';
        }
    }
}

void square(char block[LINE_B][COLUMN_B])
{
    block[1][2]='@';
    block[2][2]='@';
    block[1][1]='@';
    block[2][1]='@';
}
void Gen_block(char block[LINE_B][COLUMN_B])
{
    int random_block = 1;
    if (random_block == 1);
    {
        clean_Block(block);
        square(block);
    }
}
//the function place_iece is the hardest because we need to calculate the future position
//of the piece that we want to put on the grid.
void place_piece(char block[LINE_B][COLUMN_B], char grid[LINE_G][COLUMN_G], int column)
{
    int pos_x[4]={0};
    int pos_y[4]={0};
    int i=0,j=0;
    // this double boucle save all the '@' positions in 2 list in order to be calculated
    for (int line=0; line<LINE_B; line++)    
    {
        for (int column=0; column<COLUMN_B; column++)
        {
            if (block[line][column] == '@')
            {
                pos_x[i]=line-1;
                i++;
                pos_y[j]=column-1;
                j++;
            }
        }
    }
    // this boucle place the piece on the grid.
    for (int j = 0; j < 4; j++)
    {
        int x = pos_x[j];
        int y = pos_y[j];
        grid[x][y+column] = '@';  //ici si tu modifies grid[9-x] cela commencera du bas.
    }
}
void show_block(char block[LINE_B][COLUMN_B])
{
    for (int l = 0; l<LINE_B; l++)
    {
        for (int c = 0; c<COLUMN_B; c++)
        {
            printf("|");
            printf("%c", block[l][c]);
        }
        printf("|");
        printf("\n");
    }
}
