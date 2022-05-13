#include <stdio.h>
#include "Block.h"
#include "plateau.h"
#include <time.h>
#include <stdlib.h>
#define LINE_B 4
#define COLUMN_B 4
#define LINE_G 10
#define COLUMN_G 10
//il faut continuer le top.
int choose_col(char block[LINE_B][COLUMN_B])
{
    int column;
    int rand_b= Gen_block(block);
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
        else if ((rand_b==2) && (column > 7))
        {
            printf("Choisir une colonne entre 1 et 7\n");
            scanf("%d", &column);
        }
        else if ((rand_b==3) && (column > 8))
        {
            printf("Choisir une colonne entre 1 et 8\n");
            scanf("%d", &column);
        }
        else if ((rand_b==4) && (column > 8))
        {
            printf("Choisir une colonne entre 1 et 8\n");
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
    block[1][1]='@';
    block[2][1]='@';
    block[1][0]='@';
    block[2][0]='@';
}
//LINE and these orientations
void Line(char block[LINE_B][COLUMN_B])
{
    block[1][0]='@';
    block[1][1]='@';
    block[1][2]='@';
    block[1][3]='@';
} 
void Line_v(char block[LINE_B][COLUMN_B])
{
    block[0][0]='@';
    block[1][0]='@';
    block[2][0]='@';
    block[3][0]='@';
} 
//-------------------------------
//BLOCK T and these orientations
void piece_en_T(char block[LINE_B][COLUMN_B]){
    block[1][1]='@';
    block[1][0]='@';
    block[1][2]='@';
    block[2][1]='@';   
}
void piece_en_T_2(char block[LINE_B][COLUMN_B])
{
    block[0][1]='@';
    block[1][0]='@';
    block[1][1]='@';
    block[1][2]='@'; 
}
void piece_en_T_3(char block[LINE_B][COLUMN_B]){
    block[0][1]='@';
    block[1][1]='@';
    block[1][2]='@';
    block[2][1]='@';
}
void piece_en_T_4(char block[LINE_B][COLUMN_B]){
    block[0][1]='@';
    block[1][0]='@';
    block[1][1]='@';
    block[2][1]='@';
}
//---------------------
//BLOCK Z and these orientations
void piece_z(char block[LINE_B][COLUMN_B]){
    block[1][0]='@';
    block[1][1]='@';
    block[2][1]='@';
    block[2][2]='@';
}
void piece_z_2(char block[LINE_B][COLUMN_B]){
    block[0][2]='@';
    block[1][1]='@';
    block[1][2]='@';
    block[2][1]='@';
}
//------------------------------
///BLOCK S and these orientations
void piece_s(char block[LINE_B][COLUMN_B]){
    block[1][1]='@';
    block[1][2]='@';
    block[2][0]='@';
    block[2][1]='@';
}
void piece_s_2(char block[LINE_B][COLUMN_B]){
    block[0][1]='@';
    block[1][1]='@';
    block[1][2]='@';
    block[2][2]='@';
}
//-------------------------------------------------
//BLOCK L and these orientations
void piece_L(char block[LINE_B][COLUMN_B]){
    block[1][0]='@';
    block[1][1]='@';
    block[1][2]='@';
    block[2][0]='@';
}
void piece_L_2(char block[LINE_B][COLUMN_B]){
    block[0][1]='@';
    block[1][1]='@';
    block[2][1]='@';
    block[2][2]='@';
}
void piece_L_3(char block[LINE_B][COLUMN_B]){
    block[0][2]='@';
    block[1][0]='@';
    block[1][1]='@';
    block[1][2]='@';
}
void piece_L_4(char block[LINE_B][COLUMN_B]){
    block[0][0]='@';
    block[0][1]='@';
    block[1][1]='@';
    block[2][1]='@';
}
//--------------------------------------------------
// BLOCK J and these orientations
void piece_J(char block[LINE_B][COLUMN_B]){
    block[1][0]='@';
    block[1][1]='@';
    block[1][2]='@';
    block[2][2]='@';
}
void piece_J_2(char block[LINE_B][COLUMN_B]){
    block[0][1]='@';
    block[0][2]='@';
    block[1][1]='@';
    block[2][1]='@';
}
void piece_J_3(char block[LINE_B][COLUMN_B]){
    block[0][0]='@';
    block[1][0]='@';
    block[1][1]='@';
    block[1][2]='@';
}
void piece_J_4(char block[LINE_B][COLUMN_B]){
    block[0][1]='@';
    block[1][1]='@';
    block[2][0]='@';
    block[2][1]='@';
}
//------------------------------------------------
//This function generate new block
int Gen_block(char block[LINE_B][COLUMN_B])
{
    srand(time(NULL));
    int orientation;
    int random_block = (rand()%7)+1;
    if (random_block == 1)
    {
        clean_Block(block);
        square(block);
        printf("Le bloque qui arrive est un carré\n");
    }
    else if  (random_block ==2)
    {
        printf("Le bloque qui arrive est une line\n");
        printf("choisir l'orientation:\n");
        clean_Block(block);
        Line(block);
        printf("(%c)\n", (char) '1');
        show_block(block);
        clean_Block(block);
        Line_v(block);
        printf("(%c)\n", (char) '2');
        show_block(block);
        scanf("%d", &orientation);
        if (orientation == 1)
        {
            clean_Block(block);
            Line(block);
        }
        else
        {
            clean_Block(block);
            Line_v(block);
        }
    }
    else if  (random_block == 3)
    {
        printf("Le bloque qui arrive est un T\n");
        printf("choisir l'orientation:\n");
        clean_Block(block);
        piece_en_T(block);
        printf("(%c)\n", (char) '1');
        show_block(block);
        clean_Block(block);
        piece_en_T_2(block);
        printf("(%c)\n", (char) '2');
        show_block(block);
        clean_Block(block);
        piece_en_T_3(block);
        printf("(%c)\n", (char) '3');
        show_block(block);
        clean_Block(block);
        piece_en_T_4(block);
        printf("(%c)\n", (char) '4');
        show_block(block);
        scanf("%d", &orientation);
        if (orientation == 1)
        {
            clean_Block(block);
            piece_en_T(block);
        }
        else if (orientation == 2)
        {
            clean_Block(block);
            piece_en_T_2(block);
        }
        else if (orientation == 3)
        {
            clean_Block(block);
            piece_en_T_3(block);
        }
        else if (orientation == 4)
        {
            clean_Block(block);
            piece_en_T_4(block);
        }
    }
    else if  (random_block == 4)
    {
        printf("Le bloque qui arrive est un Z\n");
        printf("choisir l'orientation:\n");
        clean_Block(block);
        piece_z(block);
        printf("(%c)\n", (char) '1');
        show_block(block);
        clean_Block(block);
        piece_z_2(block);
        printf("(%c)\n", (char) '2');
        show_block(block);
        scanf("%d", &orientation);
        if (orientation == 1)
        {
            clean_Block(block);
            piece_z(block);
        }
        else
        {
            clean_Block(block);
            piece_z_2(block);
        }
    }
    else if(random_block == 5)
    {
        printf("Le bloque qui arrive est un s\n");
        printf("choisir l'orientation:\n");
        clean_Block(block);
        piece_s(block);
        printf("(%c)\n", (char) '1');
        show_block(block);
        clean_Block(block);
        piece_s_2(block);
        printf("(%c)\n", (char) '2');
        show_block(block);
        scanf("%d", &orientation);
        if (orientation == 1)
        {
            clean_Block(block);
            piece_s(block);
        }
        else
        {
            clean_Block(block);
            piece_s_2(block);
        }
    }
    else if(random_block == 6){
        printf("Le bloque qui arrive est une line\n");
        printf("choisir l'orientation:\n");
        clean_Block(block);
        piece_L(block);
        printf("(%c)\n", (char) '1');
        show_block(block);
        clean_Block(block);
        piece_L_2(block);
        printf("(%c)\n", (char) '2');
        show_block(block);
        clean_Block(block);
        piece_L_3(block);
        printf("(%c)\n", (char) '3');
        show_block(block);
        clean_Block(block);
        piece_L_4(block);
        printf("(%c)\n", (char) '4');
        show_block(block);
        scanf("%d", &orientation);
        if (orientation == 1)
        {
            clean_Block(block);
            piece_L(block);
        }
        else if (orientation == 2)
        {
            clean_Block(block);
            piece_L_2(block);
        }
        else if (orientation == 3)
        {
            clean_Block(block);
            piece_L_3(block);
        }
        else if (orientation == 4)
        {
            clean_Block(block);
            piece_L_4(block);
        }
    }
    else if(random_block == 7)
    {
        printf("Le bloque qui arrive est une line\n");
        printf("choisir l'orientation:\n");
        clean_Block(block);
        piece_J(block);
        printf("(%c)\n", (char) '1');
        show_block(block);
        clean_Block(block);
        piece_J_2(block);
        printf("(%c)\n", (char) '2');
        show_block(block);
        clean_Block(block);
        piece_J_3(block);
        printf("(%c)\n", (char) '3');
        show_block(block);
        clean_Block(block);
        piece_J_4(block);
        printf("(%c)", (char) '4');
        show_block(block);
        scanf("%d", &orientation);
        if (orientation == 1)
        {
            clean_Block(block);
            piece_J(block);
        }
        else if (orientation == 2)
        {
            clean_Block(block);
            piece_J_2(block);
        }
        else if (orientation == 3)
        {
            clean_Block(block);
            piece_J_3(block);
        }
        else if (orientation == 4)
        {
            clean_Block(block);
            piece_J_4(block);
        }
    }
    return random_block;
}
//show the block in the current turn
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

void collision(char grid[LINE_G][COLUMN_G],char block[LINE_B][COLUMN_B], int column)
{
	int x_ref, y_ref=1;
	y_ref += column;
	int move =0;
	//this boucle make the detection of if there is a '@' at the bottom with the reference's coords.
	for(x_ref = 1; x_ref<LINE_G;x_ref++)
	{
		move++;
		if (grid[x_ref+1][y_ref] == '@')
		{
			break;
		}
	}
	printf("%d", move);
	int x[4]={0};
	int y[4]={0};
	int i=0, j=0;
	for(int line=0;line<LINE_B-1;line++)
	{
		for(int column=0;column<COLUMN_B;column++)
		{
			if (block[line][column]=='@')
			{
				x[i]=line;
				y[j]=column;
				i++;
				j++;
			}
		}
	}
	printf("\n");
	for (int k = 0 ; k<4; k++)
	{
		x[k] += move;
		y[k] += column;
	}
	int boole = 1;
	int cpt;
	do
	{
		cpt = 0;
		for (int i = 0; i<4; i++)
		{
			if (grid[x[i]][y[i]] == ' ')
			{
				cpt++;
			}
			else
			{
				for (int iter = 0; iter<4; iter++)
				{
					x[iter]--;
				}
			}
		}
		if (cpt == 4)
		{
			boole = 0;
		} 
	}while (boole == 1);
	for (int k = 0 ; k<4; k++){printf("(%d, %d) ", x[k],y[k]);}
	for (int iter = 0; iter<4; iter++)
	{
		grid[x[iter]][y[iter]] = '@';
	}
}



