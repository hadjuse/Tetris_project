#ifndef __SCORE__H__
#define __SCORE__H__
#define LINE_B 4
#define COLUMN_B 4
#define LINE_G 10
#define COLUMN_G 10
typedef struct
{
	char username[50];
	int score;
}Joueur;
Joueur Gen_Player();
void show_name();
void show_score(Joueur player);
void render_score(Joueur player);
void leaderboard(Joueur *read_file, int *nbp);
Joueur *read_file(int*nmbPlayer);
#endif