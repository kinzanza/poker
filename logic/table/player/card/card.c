#include <raylib.h>
#include "card.h"


void CardInit(struct Card* crd, Rectangle bounds, Texture2D texture, float scale){
    crd->bounds = bounds;
    crd->texture = texture;
    crd->tint = WHITE;
    crd->scale = scale;
    crd->isSelected = false;
}

void CardDraw(struct Card* crd){
    DrawTextureEx(crd->texture, (Vector2){crd->bounds.x, crd->bounds.y}, 0, crd->scale, crd->tint);
}

void CardUpdate(struct Card* crd){
    CardDraw(crd);
}

void DeckInit(struct Deck* deck, Texture2D atlas){
    deck->atlas = atlas;
    deck->cardCount = DECK_SIZE;

    int cardIndex = 0;

    float cardWidth = 71.0f;
    float cardHeight = 96.0f;

    for (int suit = SUIT_SPADES; suit <= SUIT_DIAMONDS; suit++){
        for (int rank = RANK_TWO; rank <= RANK_ACE; rank++){
            Card* card = &deck->cards[cardIndex];

            Rectangle bounds = {
                rank * cardWidth,
                suit * cardHeight,
                cardWidth,
                cardHeight
            };

            CardInit(card, bounds, deck->atlas, 1.0f);

            card->suit = (Suit)suit;
            card->rank = (Rank)rank;
            card->isFaceUp = false;
            
            cardIndex++;
        }
    }

    for (int joker = 0; joker < 2; joker ++){
        Card* card = &deck->cards[cardIndex];

        Rectangle bounds = {
            (RANK_JOKER + 1) * cardWidth,
            4 * cardHeight,
            cardWidth,
            cardHeight
        };

            CardInit(card, bounds, deck->atlas, 1.0f);

            card->suit = SUIT_JOKER;
            card->rank = RANK_JOKER;
            card->isFaceUp = false;

            cardIndex++;
            
    }
}

void DeckShuffle(struct Deck* deck);
void DeckSort(struct Deck* deck);

