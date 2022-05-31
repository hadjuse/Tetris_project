#include <stdio.h>
#include "score.h"
#include "Block.h"
#include <time.h>
#include <stdlib.h>
#include "couleur.h"
#include <errno.h>
#include <string.h>
Joueur player;
Joueur Gen_Player()
{
	Joueur player;
	player.score = 0;
	printf("Plz type your username:\n");
	scanf("%s", player.username);
	return player;
}
void show_name(Joueur player)
{
	printf("%s ",player.username);
}

void show_score(Joueur player)
{
	couleur("33");
	printf("Voici votre score actuel: %d\n", player.score);
	couleur("0");
}
void render_score(Joueur player)
{
	FILE* fichier = NULL;
	fichier = fopen("score.txt", "a");
	if (fichier==NULL)
	{
		printf("Ouverture impossible\n");
		printf("code d'erreur	=%d \n", errno);
		printf("Message d'erreur = %s \n", strerror(errno));
		exit(1);
	}
	fprintf(fichier,"%s %d\n", player.username, player.score);
	fclose(fichier);
}
void tri(Joueur *tabPlayer, int *nbp)
{
	int tmp;	
	int index;
	for (int i=0; i < (*nbp-1); i++)
	{
		index = i;
	
		for (int j=i + 1; j < *nbp; j++)
		{
		if (tabPlayer[i].score <= tabPlayer[j].score)
			index = j;
		}
		if (index != i)
		{
			tmp = tabPlayer[i].score;
			tabPlayer[i].score = tabPlayer[index].score;
			tabPlayer[index].score = tmp;
		}
  	}
}
Joueur *read_file(int*nmbPlayer)
{
	Joueur *tab = NULL;
	FILE* fichier = NULL;
	fichier = fopen("score.txt", "r");
	int echangeur=0;
	if (fichier==NULL)
	{
		printf("Ouverture impossible\n");
		printf("code d'erreur	=%d \n", errno	);
		printf("Message d'erreur = %s \n", strerror(errno));
		exit(1);
	}
	char lignePlayer[1000];
	while (fgets(lignePlayer, 999, fichier) !=NULL)
	{
		*nmbPlayer = *nmbPlayer+1;
	}
	tab = malloc(*nmbPlayer * sizeof(Joueur));
	rewind(fichier);
	for(int i=0;i<=*nmbPlayer;i++)
	{
		fscanf(fichier, "%s", tab[i].username);
		fscanf(fichier, "%d", &tab[i].score);
	}
	fclose(fichier);
	tri(tab, nmbPlayer);
	return tab;
}

void leaderboard(Joueur *tabPlayer, int *nbp)
{
	FILE* fichier=NULL;
	fichier=fopen("leaderBoard.txt","w");
	fprintf(fichier,"Leaderboard\n");
	
	for (int i =0 ; i<*nbp; i++)
	{
		fprintf(fichier," %d° |[|USER/SCORE: %s / %d|]\n", i+1,tabPlayer[i].username,tabPlayer[i].score);
	}
	fclose(fichier);
}
