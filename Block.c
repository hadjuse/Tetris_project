#include <stdio.h>
#include "Block.h"
#include "plateau.h"
#include <time.h>
#include <stdlib.h>
#include "couleur.h"
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <curses.h>
#define LINE_B 4
#define COLUMN_B 4
#define LINE_G 10
#define COLUMN_G 10
int choose_col(char block[LINE_B][COLUMN_B])
{
   int column;
   int rand_block_and_orientation= Gen_block(block);
   int booleen = 0;
   do 
   {
   		printf("Choose column btw 1 to 9\n");
   		int boole = scanf("%d", &column);
   		while (fgetc(stdin) != '\n'){};
   		if (boole == 1)
   		{
   			booleen = 1;
   		}
   																			
   }while ((booleen == 0) || (column<1 || column>9));
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
    block[0][0]='@';
    block[1][0]='@';
    block[0][1]='@';
    block[1][1]='@';
}
//LINE and these orientations
void Line(char block[LINE_B][COLUMN_B])
{
    block[0][0]='@';
    block[0][1]='@';
    block[0][2]='@';
    block[0][3]='@';
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
    block[0][1]='@';
    block[0][0]='@';
    block[0][2]='@';
    block[1][1]='@';   
}
void piece_en_T_2(char block[LINE_B][COLUMN_B])
{
    block[0][0]='@';
    block[1][0]='@';
    block[2][0]='@';
    block[1][1]='@'; 
}
void piece_en_T_3(char block[LINE_B][COLUMN_B]){
    block[0][1]='@';
    block[1][0]='@';
    block[1][1]='@';
    block[1][2]='@';
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
    block[0][0]='@';
    block[0][1]='@';
    block[1][1]='@';
    block[1][2]='@';
}
void piece_z_2(char block[LINE_B][COLUMN_B]){
    block[0][1]='@';
    block[1][0]='@';
    block[1][1]='@';
    block[2][0]='@';
}
//------------------------------
///BLOCK S and these orientations
void piece_s(char block[LINE_B][COLUMN_B]){
    block[1][0]='@';
    block[1][1]='@';
    block[0][1]='@';
    block[0][2]='@';
}
void piece_s_2(char block[LINE_B][COLUMN_B]){
    block[0][0]='@';
    block[1][0]='@';
    block[1][1]='@';
    block[2][1]='@';
}
//-------------------------------------------------
//BLOCK L and these orientations
void piece_L(char block[LINE_B][COLUMN_B]){
    block[0][0]='@';
    block[0][1]='@';
    block[0][2]='@';
    block[1][0]='@';
}
void piece_L_2(char block[LINE_B][COLUMN_B]){
    block[0][0]='@';
    block[1][0]='@';
    block[2][0]='@';
    block[2][1]='@';
}
void piece_L_3(char block[LINE_B][COLUMN_B]){
    block[1][0]='@';
    block[1][1]='@';
    block[1][2]='@';
    block[0][2]='@';
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
    block[0][0]='@';
    block[0][1]='@';
    block[0][2]='@';
    block[1][2]='@';
}
void piece_J_2(char block[LINE_B][COLUMN_B]){
    block[0][0]='@';
    block[0][1]='@';
    block[1][0]='@';
    block[2][0]='@';
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
    block[2][1]='@';
    block[2][0]='@';
}
//------------------------------------------------
//This function generate new block
int Gen_block(char block[LINE_B][COLUMN_B])
{
    srand(time(NULL));
    int orientation;
    int random_block = (rand()%7)+1;
    //int random_block = 3;
    if (random_block == 1)
    {
        clean_Block(block);
        square(block);
        printf("Le bloque qui arrive est un carré\n");
		show_block(block);
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
        return orientation;
    }
    else if(random_block == 6){
        printf("Le bloque qui arrive est un L\n");
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
        printf("Le bloque qui arrive est un J\n");
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
        printf("(%c)\n", (char) '4');
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
    return orientation;
}
//show the block in the current turn
void show_block(char block[LINE_B][COLUMN_B])
{
    for (int l = 0; l<LINE_B; l++)
    {
        for (int c = 0; c<COLUMN_B; c++)
        {
            printf("|");
            textcolor((rand()%15)+1);
            cprintf("%c", block[l][c]);
        }
        printf("|");
        printf("\n");
    }
}
//------------------------------------------------
void out_range_right(int *x,int *y, int column)
{
    
    int back_left[4]={0};
    int max=0;
    //Test the collision for the extrem right
    for (int i = 0; i<4; i++)
    {
        if (y[i]>column)
        {
            back_left[i] = y[i]-column;
        }
    }
    for (int j = 0; j<4; j++)
    {
        if (max<back_left[j])
        {
            max = back_left[j];
        }
    }
    for (int k = 0; k<4; k++)
    {
        y[k] -= max;
    }
}
//--------------------------------
void out_range_left(int *x,int *y, int column)
{
	int max_abs=0;
    int abs[4] = {0};
    for (int i =0; i<4; i++)
    {
        if (y[i]<0)
        {
            abs[i]=-y[i];
        }
    }
    for (int j = 0; j<4; j++)
    {
        if (max_abs<=abs[j])
        {
            max_abs = abs[j];
        }
    }
    for (int k = 0; k<4; k++)
    {
        y[k] += max_abs;
    }   
    
}
//--------------------------------
//------------------------------------------------
//this function is the most important it's the collision
void collision(char grid[LINE_G][COLUMN_G],char block[LINE_B][COLUMN_B], int column)
{
	int x[4]={0};
	int y[4]={0};
	int i=0, j=0;
	for(int line=0;line<LINE_B;line++)
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
	for (int i =0; i<4; i++)
	{
		x[i]+=9;
		y[i]+=column;
	}
	out_range_right(x,y, column);
    out_range_left(x,y, column);
	int boole = 1;
	int counting;
    while (boole == 1)
	{
		counting = 0;
		for (int i = 0; i<4; i++)
		{
			if (grid[x[i]][y[i]] == ' ')
			{
				counting++;
			}
			else
			{
				for (int iter = 0; iter<4; iter++)
				{
					x[iter]--;
				}
			}
            if (counting == 4)
		    {   
			    boole = 0;
		    } 
		}
		
	};
	for (int iter = 0; iter<4; iter++)
	{
		grid[x[iter]][y[iter]] = '@';
	}
}

/*int choix_difficulte()
{
    int choix;
    printf("Veuiller choisir la difficulte");
    printf("(%c) Normal", (char) '1');
    printf("(%c) Difficile", (char) '2');
    scanf("%d",choix);
    if (choix==1)
    {
        choix=1;
    }
    else if(choix==2)
    {
        choix=2;
    }
    return choix;
}
*/

/*int chronometre_clem(int choix_difficulte)
{
    int compteur1=10;
    int compteur2=5;
    int boole=1;
    if(choix_difficulte==1)
    {
         for(int i=compteur1;i>=0;i--)
        {
            Sleep(3000);
            compteur1--;
            printf("compteur: %d")
            if(compteur1==0)
            {
                printf("Game Over");
                boole=0;
                break;
                return boole;
            }
        }
    }
    if(choix_difficulte==2)
    {
        for(int j=compteur2;j>=0;j--)
        {
            sleep(3000);
            compteur2--;
            printf("compteur: %d;")
            if(compteur2==0)
            {
                printf("Game Over");
                boole=0;
                break;
                return boole;
            }
        }
    }
}*/
