#ifndef CARD_H
#define CARD_H

#include <raylib.h>

#define DECK_SIZE 54

// Перечисления для мастей и ранговg
typedef enum {
    SUIT_SPADES,   // Пики
    SUIT_HEARTS,   // Черви
    SUIT_CLUBS,    // Трефы
    SUIT_DIAMONDS, // Бубны
    SUIT_JOKER     // Джокер
} Suit;

typedef enum {
    RANK_TWO,
    RANK_THREE,
    RANK_FOUR,
    RANK_FIVE,
    RANK_SIX,
    RANK_SEVEN,
    RANK_EIGHT,
    RANK_NINE,
    RANK_TEN,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    RANK_JOKER
} Rank;

// Структура карты
typedef struct Card {
    Rectangle bounds;      // Позиция и размер на экране
    Texture2D texture;     // Текстура (если отдельная для каждой карты)
    Color tint;            // Цветовой оттенок
    float scale;           // Масштаб
    bool isSelected;       // Выбрана ли карта
    
    // Информация о карте
    Suit suit;             // Масть
    Rank rank;             // Достоинство
    bool isFaceUp;         // Открыта или рубашкой вверх
    Vector2 velocity;      // Скорость (для анимаций)
} Card;

// Структура контроллера карт (например, для руки игрока)
typedef struct CardController {
    Rectangle bounds;      // Область, где находятся карты
    struct Card** cards;   // Указатель на массив указателей на карты
    int cardCount;         // Количество карт
} CardController;

// Структура колоды
typedef struct Deck {
    struct Card cards[DECK_SIZE];  // Массив карт
    int cardCount;                  // Сколько карт сейчас в колоде
    Texture2D atlas;                // Общая текстура (атлас)
} Deck;

// Прототипы функций
void CardInit(struct Card* crd, Rectangle bounds, Texture2D texture, float scale);
void CardSelect(struct Card* crd);
void CardDraw(struct Card* crd);
void CardUpdate(struct Card* crd);

// Функции для работы с колодой
void DeckInit(struct Deck* deck, Texture2D atlas);
void DeckShuffle(struct Deck* deck);
void DeckSort(struct Deck* deck);

// Функции для контроллера
void CardControllerInit(struct CardController* controller, Rectangle bounds);
void CardControllerAddCard(struct CardController* controller, struct Card* card);
void CardControllerRemoveCard(struct CardController* controller, int index);

#endif