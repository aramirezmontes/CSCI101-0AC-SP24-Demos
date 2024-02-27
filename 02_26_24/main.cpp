#include <iostream>
#include <limits>
#include <string>

enum suitType
{
    DIAMOND,
    CLUB,
    HEART,
    SPADE,
    DEFAULTS
};
enum rankType
{
    A,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    J,
    Q,
    K,
    DEFAULTR
};

const rankType ranks[] = {A,
                          TWO,
                          THREE,
                          FOUR,
                          FIVE,
                          SIX,
                          SEVEN,
                          EIGHT,
                          NINE,
                          TEN,
                          J,
                          Q,
                          K,
                          DEFAULTR};
const suitType suits[] = {DIAMOND,
                          CLUB,
                          HEART,
                          SPADE,
                          DEFAULTS};
const std::string rankStr[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", " "};
const std::string suitStr[] = {"♦", "♣", "♥", "♠", " "};
const int DECK_SIZE = 52;
const int NUM_PILES = 4;

struct card
{
    suitType suit = DEFAULTS;
    rankType rank = DEFAULTR;
    bool used = false;
};

int main()
{
    card c;
    c.suit = HEART;
    c.rank = A;
    card d;
    d = c;
    suitType mySuit;
    rankType myRank;

    return 0;
}
