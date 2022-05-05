// this is the file which contains all function about generate the grid
#ifndef __BLOCK__H__
#define __BLOCK__H__
#define LINE_B 4
#define COLUMN_B 4
#define LINE_G 10
#define COLUMN_G 10
void Gen_block(char block[LINE_B][COLUMN_B]);
void clean_Block(char block[LINE_B][COLUMN_B]);
void square(char block[LINE_B][COLUMN_B]);
void place_piece(char block[LINE_B][COLUMN_B], char grid[LINE_G][COLUMN_G], int column);
void show_block(char block[LINE_B][COLUMN_B]);
#endif