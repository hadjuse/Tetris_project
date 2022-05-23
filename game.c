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
int game_over(char grid [LINE][COLUMN])
{
	int boole=0;
	for(int i=0;i<1;i++)
	{
		for(int j=0;j<COLUMN;j++)
		{
			if (grid[i][j]=='@')
			{
				printf("Game over");
				boole=1;
			}
		}
	}
	return boole;
}
void game()
{
	Joueur player;
	player = Gen_Player();
    char block[LINE_B][COLUMN_B];
    char grid[LINE_G][COLUMN_G];
    char username[50];
    Generate(grid);
    //show_grid(grid);
    do 
    {
		int choix_difficulte();
    	show_name(player);
        int column=choose_col(block);
        collision(grid,block, column);
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
    }while ((!game_over(grid)) || (chronometre_clem!=1));
	render_score(player);
}