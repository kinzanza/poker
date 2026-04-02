#ifndef TABLE_H
#define TABLE_H

#define MAX_PLAYERS 8

#include <raylib.h>
#include "player/player.h"
#include "player/card/card.h"

typedef struct{
    Player players[MAX_PLAYERS]; // Массив игроков за столом
    int playersCount; // Количсетво игроков в текущей партии
    
    Card street[5]; // Карты в центре стола (максимум 5)
    int communityCount; // Количество открытых карт на столе

    Deck deck; // Колода

    int pot; // Текущий банк
    int currentPlayer; // Кто ходит
    int dealerPosition; // Кто дилер
    int stage; // Префлоп, флоп, терн, ривер, шоудаун

    int currentBet; // Текущая ставка для колла
    int minRaise; // Минимальный рейз
} Table;

Table TableInit(Player players, int playersCount, int community, int minRaise, Texture2D atlas); // Инициализатор стола
void DealCards(Table* table);

#endif