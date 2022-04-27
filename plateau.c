#include <stdio.h>
#include "plateau.h"
#define LINE 10
#define COLUMN 10
typedef struct Block
{
    int orientation;
};

typedef struct Game
{
    char plateau[COLUMN][LINE];
    Block block;
};

Game Generate()
{
    
}
