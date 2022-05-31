#include <stdio.h>
#include <stdlib.h>
#include "Block.h"
#include "plateau.h"
#include "game.h"
#define LINE 10
#define COLUMN 10
#define LINE_B 4
#define COLUMN_B 4
//this file is the main execution of all programms.
int main()
{
    int choix;
    int booleen = 0;
    do 
   {
   		printf("Veuiller choisir votre difficulte\n");
        printf("(%c) Easy\n", (char) '1');
        printf("(%c) Normal\n", (char) '2');
        printf("(%c) Hard\n", (char) '3');
   		int boole = scanf("%d", &choix);
   		while (fgetc(stdin) != '\n'){};
   		if (boole == 1)
   		{
   			booleen = 1;
   		}																		
   }while ((booleen == 0) || (choix<1 || choix>4));
    printf("le choix de la difficulte est %d\n", choix);
    if(choix==1)
    {
        game_easy();
    }
    else if(choix==2)
    {
        game_normal();
    }
    else if(choix==3)
    {
        game_hard();
    }
    return 0;
}
