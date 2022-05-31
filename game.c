#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Block.h"
#include "plateau.h"
#include "score.h"
#include <time.h>
#include "couleur.h"
#define LINE 10
#define COLUMN 10
#define LINE_B 4
#define COLUMN_B 4
void game_normal()
{
	int *nbP=NULL;
	nbP = malloc(sizeof(int));
	nbP[0] = 0;
	Joueur *tabPlayer= NULL;
	tabPlayer = malloc(sizeof(Joueur));
	tabPlayer= read_file(nbP);
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
        int column=choose_col(block, grid);
        unsigned long time_2=getTimeMicroSec();
       	unsigned long ecart = (time_2-time_1)/1000000;
        printf("You spend %ld second to choose your column \n", (time_2-time_1)/1000000);
        if (ecart>10)
        {
        	couleur("31");
        	printf("You spend too much time to choose  your column!\n");
			couleur("0");
        	column = rand()%9;
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
	leaderboard(tabPlayer,nbP);
}
void game_easy()
{
	int *nbP=NULL;
	nbP = malloc(sizeof(int));
	nbP[0] = 0;
	Joueur *tabPlayer= NULL;
	tabPlayer = malloc(sizeof(Joueur));
	tabPlayer= read_file(nbP);
	Joueur player = Gen_Player();
    char block[LINE_B][COLUMN_B];
    char grid[LINE_G][COLUMN_G];
	int colli;
    Generate(grid);
    do 
    {
		show_name(player);
        int column=choose_col(block, grid);
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
	leaderboard(tabPlayer, nbP);
}

void game_hard()
{
	Joueur player;
	player = Gen_Player();
	int *nbP=NULL;
	nbP = malloc(sizeof(int));
	nbP[0] = 0;
	Joueur *tabPlayer= NULL;
	tabPlayer = malloc(sizeof(Joueur));
	tabPlayer= read_file(nbP);
    char block[LINE_B][COLUMN_B];
    char grid[LINE_G][COLUMN_G];
    char username[50];
    Generate(grid);
	int colli;
    do 
    {
		unsigned long time_1=getTimeMicroSec();
    	show_name(player);
        int column=choose_col(block, grid);
        unsigned long time_2=getTimeMicroSec();
       	unsigned long ecart = (time_2-time_1)/1000000;
        printf("You spend %ld second to choose your column \n", (time_2-time_1)/1000000);
        if (ecart>5)
        {
			couleur("31");
        	printf("You spend too much time to choose  your column!\n");
			couleur("0");
        	column = rand()%9;
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
	leaderboard(tabPlayer, nbP+1);
}
