#include "table.h"

Table TableInit(Player players, int playersCount, int community, int minRaise, Texture2D atlas){
    Table table = {
        .players = players,
        .playersCount = playersCount,
        .communityCount = community,
        .pot = 0,
        .currentPlayer = 0,
        .dealerPosition = 0,
        .stage = 0,
        .minRaise = minRaise,
        .currentBet = minRaise
    };

    DeckInit(&table.deck, atlas);

    for (int i = 0; i < playersCount; i++){


        for (int j = 0; j < 2; j++){
            CardInit(&table.players[i].hand[j],
                (Rectangle){0, 0, 71, 96},
                table.deck.atlas,
                1.0f);
            table.players[i].hand[i].isFaceUp = false;
        }
    }

    for (int i = 0; i < 5; i++){
        CardInit(&table.street[i],
            (Rectangle){0, 0, 71, 96},
            table.deck.atlas,
            1.0f);
        table.street[i].isFaceUp = false;
    }

    return table;
}

void DealCards(Table* table){
    DeckShuffle(&table->deck);

    for (int i = 0; i < table->playersCount; i++){
        for (int j = 0; j < 2; j++){
            Card topCard = table->deck.cards[--table->deck.cardCount];
            table->players[i].hand[j] = topCard;
            table->players[i].hand[j].isFaceUp = true;
        }
    }

    for (int i = 0; i < 5; i++){
        Card topCard = table->deck.cards[--table->deck.carCount];
        table->street[i] = topCard;
        table->street[i].isFaceUp = true;
    }
}