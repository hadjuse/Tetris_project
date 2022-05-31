// this is the file which contains all function about generate grid, block
// places block on the grid...
#ifndef __BLOCK__H__
#define __BLOCK__H__
#define LINE_B 4
#define COLUMN_B 4
#define LINE_G 10
#define COLUMN_G 10
#define LINE_O 4
#define COLUMN_O 18
//int choix_difficulte();
int Gen_block(char block[LINE_B][COLUMN_B], char grid[LINE_G][COLUMN_G]);
void clean_Block(char block[LINE_B][COLUMN_B]);
void clean_top_grid(char grid[LINE_G][COLUMN_G]);
void show_block(char block[LINE_B][COLUMN_B]);
int choose_col(char block[LINE_B][COLUMN_B],char grid[LINE_G][COLUMN_G]);
void out_range_right(int *x,int *y, int column);
unsigned long getTimeMicroSec();
int collision(char grid[LINE_G][COLUMN_G],char block[LINE_B][COLUMN_B], int column);
void show_orientation(char block[LINE_B][COLUMN_B],char orient[LINE_O][COLUMN_O], int decalage);
#endif
