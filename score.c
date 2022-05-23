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
	printf("Voici votre score actuel: %d\n", player.score);
}
void render_score(Joueur player)
{
	FILE* fichier = NULL;
	fichier = fopen("score.txt", "a");
	if (fichier==NULL)
	{
		printf("Ouverture impossible\n");
		printf("code d'erreur	=%d \n", errno	);
		printf("Message d'erreur = %s \n", strerror(errno));
		exit(1);
	}
	fprintf(fichier,"Username :  %s ! Voici votre score : %d\n", player.username, player.score);
	fclose(fichier);
}
