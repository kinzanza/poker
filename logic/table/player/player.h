#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "card/card.h"

typedef struct
{
    Card hand[2]; // Рука игрока
    int chips; // Баланс игрока
} Player;

void PlayerInit(Player* plr, int chips){
    // Инициализатор игрока
    // 
    plr->chips = chips;
}

#endif