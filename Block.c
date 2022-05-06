#include <stdio.h>
#include "Block.h"
#include "plateau.h"
#include <time.h>
#include <stdlib.h>
#define LINE_B 4
#define COLUMN_B 4
#define LINE_G 10
#define COLUMN_G 10
int choose_col()
{
    int column;
    printf("Choisir colonne entre 1 et 9\n");
    scanf("%d", &column);
    int bool =1;
    while (bool)
    {
        if (column>9)
        {
            printf("Choisir colonne entre 1 et 9\n");
            scanf("%d", &column);
        }
        else if (column<1)
        {
            printf("Choisir colonne entre 1 et 9\n");
        scanf("%d", &column);
        }
        else
        {
            bool = 0;
        }
    };
    return column;
}
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
//All BLock----------------------------------------
void square(char block[LINE_B][COLUMN_B])
{
    block[1][2]='@';
    block[2][2]='@';
    block[1][1]='@';
    block[2][1]='@';
}
void Line(char block[LINE_B][COLUMN_B])
{
    block[1][0]='@';
    block[1][1]='@';
    block[1][2]='@';
    block[1][3]='@';
} 
void piece_en_T(char block[LINE_B][COLUMN_B]){
    block[1][2]='@';
    block[1][1]='@';
    block[1][3]='@';
    block[2][2]='@';
    
}
void piece_z(char block[LINE_B][COLUMN_B]){
    block[1][1]='@';
    block[1][2]='@';
    block[2][2]='@';
    block[2][3]='@';
}
//------------------------------------------------
//This function generate new block
void Gen_block(char block[LINE_B][COLUMN_B])
{
    srand(time(NULL));
    int random_block = 3;
    if (random_block == 1)
    {
        clean_Block(block);
        square(block);
        printf("Le bloque qui arrive est un carré\n");
    }
    else if  (random_block ==2)
    {
        clean_Block(block);
        Line(block);
        printf("Le bloque qui arrive est une line\n");
    }
    else if  (random_block == 3)
    {
        clean_Block(block);
        piece_en_T(block);
        printf("Le bloque qui arrive est un T\n");
    }
    else if  (random_block == 4)
    {
        clean_Block(block);
        piece_z(block);
        printf("Le bloque qui arrive est un Z\n");
    }
}
//the function place_iece is the hardest because we need to calculate the future position
//of the piece that we want to put on the grid.
void place_piece(char block[LINE_B][COLUMN_B], char grid[LINE_G][COLUMN_G], int column)
{
    int pos_x[4]={0};
    int pos_y[4]={0};
    int i=0,j=0;
    // this double boucle save all the '@' positions in 2 list in order to be calculated after
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
        grid[x+8][y+column] = '@';
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