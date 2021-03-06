#include <stdio.h>
#include "Block.h"
#include "plateau.h"
#include <time.h>
#include <stdlib.h>
#include "couleur.h"
#include <string.h>
#include <sys/time.h>
#define LINE_B 4
#define COLUMN_B 4
#define LINE_G 10
#define COLUMN_G 10
#define LINE_O 4
#define COLUMN_O 18
unsigned long getTimeMicroSec()//this function get the current time is microsec.
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (1000000 * tv.tv_sec) + tv.tv_usec;
}
int choose_col(char block[LINE_B][COLUMN_B],char grid[LINE_G][COLUMN_G])
{
   int column;
   int rand_block_and_orientation= Gen_block(block,grid);
   int booleen = 0;
   //This do while check if the scanf is a type of int or not and if the user type a number between 0-9.
   do 
   {
   		printf("Choose column btw 0 to 9\n");
   		int boole = scanf("%d", &column);
   		while (fgetc(stdin) != '\n'){};
   		if (boole == 1)
   		{
   			booleen = 1;
   		}																		
   }while ((booleen == 0) || (column<0 || column>9));
   return column;

}
void clean_Block(char block[LINE_B][COLUMN_B])// clean the global block which will be use for multiple function.
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
int read_int_orientation()
{
	int orientation;
	int booleen=0;
	do 
   {
   		printf("\nChoose an orientation btw 1 to 4\n");
   		int boole = scanf("%d", &orientation);
   		while (fgetc(stdin) != '\n'){};
   		if (boole == 1)
   		{
   			booleen = 1;
   		}
   																			
   }while ((booleen == 0) || (orientation<1 || orientation>4));
   return orientation;
}
int read_int_orientation_4()//This function check if the scanf is a type of int or not and if the user type a number between 1-4.
{
	int orientation;
	int booleen=0;
	do 
   {
   		printf("\nChoose an orientation btw 1 to 4\n");
   		int boole = scanf("%d", &orientation);
   		while (fgetc(stdin) != '\n'){};
   		if (boole == 1)
   		{
   			booleen = 1;
   		}
   																			
   }while ((booleen == 0) || (orientation<1 || orientation>4));
   return orientation;
}

int read_int_orientation_2()//This function check if the scanf is a type of int or not and if the user type a number between 1-2.
{
	int orientation;
	int booleen=0;
	do 
   {
   		printf("Choose an orientation btw 1 to 2\n");
   		int boole = scanf("%d", &orientation);
   		while (fgetc(stdin) != '\n'){};
   		if (boole == 1)
   		{
   			booleen = 1;
   		}
   																			
   }while ((booleen == 0) || (orientation<1 || orientation>2));
   return orientation;
}
//This function generate new block with random orientation
int Gen_block(char block[LINE_B][COLUMN_B],char grid[LINE_G][COLUMN_G])
{
	//Multiple Function is use to generate a block such as the shape's function.
    srand(time(NULL));
    int orientation;
    int random_block = (rand()%7)+1;
    if (random_block == 1)
    {
        clean_Block(block);
        square(block);
        printf("Le bloque qui arrive est un carr??\n");
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
        orientation=read_int_orientation_2();
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
        
        orientation=read_int_orientation_4();
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
        orientation = read_int_orientation_2();
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
        orientation = read_int_orientation_2();
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
        orientation=read_int_orientation_4();
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
        orientation=read_int_orientation_4();
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

int generer_bornes(int min, int max)// basic function which generate a random number between min and max.
{
    srand(time(NULL));
    return rand()%(max-min+1) + min;
}
//show the block in the current turn
void show_block(char block[LINE_B][COLUMN_B])
{
    int alea = generer_bornes(30, 37);
    char alea_c[2];
    int l,c;
    sprintf(alea_c,"%d", alea); // convert int -> char
    for (l = 0; l<LINE_B; l++) // double boucle wich show the current block
    {
        couleur(alea_c); // couleur is from couleur.h
        for (c = 0; c<COLUMN_B; c++)
        {
            printf("|");
            printf("%c", block[l][c]);
        }
        printf("|");
        couleur("0");
        printf("\n");
    }
}
//--------------------------------
void out_range_right(int *x,int *y, int column)//if the coords of a block is > 9 it will automatically adjust the coords in order that they will be in the grid 
{
	int min_abs=0;
    int abs[4] = {0};
    /* we have created 2 tab because we need to calculate 4 coords*/
    int back[4] = {0};
    for (int i =0; i<4; i++)
    {
        if (y[i]>9)
        {
            back[i]= y[i]-9;
        }
    }
    for (int j = 0; j<4; j++)
    {
        if (back[j]>min_abs && back[j] != 0)
        {
            min_abs = -back[j];
        }
    }
    for (int j = 0; j<4; j++)
    {
        y[j] += min_abs;
    }
}
//--------------------------------
//this function is the most important it's the collision
int collision(char grid[LINE_G][COLUMN_G],char block[LINE_B][COLUMN_B], int column)
/*The idea of the collision is that we put the piece at the bottom and
if there is another shape which is overlayed by the current piece that we want to place, 
so we decrease the X position of the piece that we want to place until that there is no shape under the piec that we want to place*/
{
	int x[4]={0};
	int y[4]={0};
	int i=0, j=0;
	//this double boucle take coords from the block and add +9 at the line in order to be at the bottom of the grid
	for(int line=0;line<LINE_B;line++)
	{
		for(int c=0;c<COLUMN_B;c++)
		{
			if (block[line][c]=='@')
			{
				x[i]=line;
				y[j]=c;
                x[i]+=9;
                y[j]+=(column);
				i++;
				j++;
			}
		}
	}
	out_range_right(x,y, column);//we adjust the piece in order to stay in the grid.
	int boole = 1;
    int over = 0;
	int counting;
    while (boole == 1)// this while loop detect if the current piece overlay another previous piece which was already on the grid
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
                    if (x[iter]<=0)
                    {
                        over = 1;
                        break;
                    }				
                }
			}
            if (over == 1 || counting == 4){boole = 0;}
		}
	};
	for (int iter = 0; iter<4; iter++)
	{
        if (over == 1)
        {
            couleur("31");
            printf("game over ! Tu seras dans le classement ?? la prochaine game !");
            couleur("0");
            break;
        }
		grid[x[iter]][y[iter]] = '@';
	}
    return over;
}


