#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "card/card.h"

typedef struct
{
    Card hand[2];
    int chips;
} Player;


#endif