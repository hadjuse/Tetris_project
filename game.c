#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Block.h"
#include "plateau.h"
#include "score.h"
#include <time.h>
//#include <conio.h>
#define LINE 10
#define COLUMN 10
#define LINE_B 4
#define COLUMN_B 4
void game_normal()
{
	Joueur player;
	player = Gen_Player();
    char block[LINE_B][COLUMN_B];
    char grid[LINE_G][COLUMN_G];
    char username[50];
    Generate(grid);
	int colli;
    do 
    {
		unsigned long time_1=getTimeMicroSec();
    	show_name(player);
        int column=choose_col(block);
        unsigned long time_2=getTimeMicroSec();
       	unsigned long ecart = (time_2-time_1)/1000000;
        printf("You spend %ld second to choose your column \n", (time_2-time_1)/1000000);
        if (ecart>6)
        {
        	printf("You spend too much time to choose  your column!\n");
        	column = (rand()%9)+1;
		}
		colli = collision(grid,block, column);
        printf("\n");
        show_block(block);
		int compteur=0;
		for(int x=0; x<LINE_G; x++)
		{
			compteur = 0;
			for(int y=0; y<COLUMN_G; y++)
			{
				if (grid[x][y]=='@')
				{
					compteur++;
				}
			}
			if (compteur == 10)
			{
				player.score += compteur;
				for (int i=0; i<COLUMN_G; i++)
				{
					grid[x][i] = ' ';
				}
				for (int x_pos= x; x_pos>=0; x_pos--)
				{
					for (int y_pos = LINE_G; y_pos>=0; y_pos--)
					{
						if (grid[x_pos-1][y_pos] == '@')
						{
							grid[x_pos-1][y_pos] = ' ';
							grid[x_pos][y_pos] = '@' ;
						}
					}
				}
			}
			
		}
        //printf("\033[%sm",32);
        show_score(player);
        show_grid(grid);
    }while (!colli);
	render_score(player);
}
void game_easy()
{
	Joueur player;
	player = Gen_Player();
    char block[LINE_B][COLUMN_B];
    char grid[LINE_G][COLUMN_G];
	int colli;
    Generate(grid);
    do 
    {
    	show_name(player);
        int column=choose_col(block);
		colli = collision(grid,block, column);
        printf("\n");
        show_block(block);
		int compteur=0;
		for(int x=0; x<LINE_G; x++)
		{
			compteur = 0;
			for(int y=0; y<COLUMN_G; y++)
			{
				if (grid[x][y]=='@')
				{
					compteur++;
				}
			}
			if (compteur == 10)
			{
				player.score += compteur;
				for (int i=0; i<COLUMN_G; i++)
				{
					grid[x][i] = ' ';
				}
				for (int x_pos= x; x_pos>=0; x_pos--)
				{
					for (int y_pos = LINE_G; y_pos>=0; y_pos--)
					{
						if (grid[x_pos-1][y_pos] == '@')
						{
							grid[x_pos-1][y_pos] = ' ';
							grid[x_pos][y_pos] = '@' ;
						}
					}
				}
			}
			
		}
        //printf("\033[%sm",32);
        show_score(player);
        show_grid(grid);
    }while (!colli);
	render_score(player);
}
void game_hard()
{
	Joueur player;
	player = Gen_Player();
    char block[LINE_B][COLUMN_B];
    char grid[LINE_G][COLUMN_G];
    char username[50];
    Generate(grid);
	int colli;
    do 
    {
		unsigned long time_1=getTimeMicroSec();
    	show_name(player);
        int column=choose_col(block);
        unsigned long time_2=getTimeMicroSec();
       	unsigned long ecart = (time_2-time_1)/1000000;
        printf("You spend %ld second to choose your column \n", (time_2-time_1)/1000000);
        if (ecart>3)
        {
        	printf("You spend too much time to choose  your column!\n");
        	column = (rand()%9)+1;
		}
		colli = collision(grid,block, column);
        printf("\n");
        show_block(block);
		int compteur=0;
		for(int x=0; x<LINE_G; x++)
		{
			compteur = 0;
			for(int y=0; y<COLUMN_G; y++)
			{
				if (grid[x][y]=='@')
				{
					compteur++;
				}
			}
			if (compteur == 10)
			{
				player.score += compteur;
				for (int i=0; i<COLUMN_G; i++)
				{
					grid[x][i] = ' ';
				}
				for (int x_pos= x; x_pos>=0; x_pos--)
				{
					for (int y_pos = LINE_G; y_pos>=0; y_pos--)
					{
						if (grid[x_pos-1][y_pos] == '@')
						{
							grid[x_pos-1][y_pos] = ' ';
							grid[x_pos][y_pos] = '@' ;
						}
					}
				}
			}
			
		}
        show_score(player);
        show_grid(grid);
    }while (!colli);
	render_score(player);
}
void mystery_game()
{
	Joueur player;
	player = Gen_Player();
    char block[LINE_B][COLUMN_B];
    char grid[LINE_G][COLUMN_G];
    char username[50];
    Generate(grid);
	int colli = 0;
    //show_grid(grid);
    do 
    {
		//unsigned long time_1=getTimeMicroSec();
    	show_name(player);
        int column=choose_col(block);
		mystery_collision(grid,block, column);
        printf("\n");
        show_block(block);
		int compteur=0;
		for(int x=0; x<LINE_G; x++)
		{
			compteur = 0;
			for(int y=0; y<COLUMN_G; y++)
			{
				if (grid[x][y]=='@')
				{
					compteur++;
				}
			}
			if (compteur == 10)
			{
				player.score += compteur;
				for (int i=0; i<COLUMN_G; i++)
				{
					grid[x][i] = ' ';
				}
				for (int x_pos= x; x_pos>=0; x_pos--)
				{
					for (int y_pos = LINE_G; y_pos>=0; y_pos--)
					{
						if (grid[x_pos-1][y_pos] == '@')
						{
							grid[x_pos-1][y_pos] = ' ';
							grid[x_pos][y_pos] = '@' ;
						}
					}
				}
			}
			
		}
        //printf("\033[%sm",32);
        show_score(player);
        show_grid(grid);
    }while (colli);
	render_score(player);	
}	