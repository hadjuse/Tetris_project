#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#define LINE 10
#define COLUMN 10
int main()
{
    char tab[LINE][COLUMN];
    Generate(tab);
    show_grid(tab);
    return 0;
}