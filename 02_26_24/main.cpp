#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>

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
const int NUM_SUITS = 5;
const int NUM_RANKS = 14;

struct cardType
{
    suitType suit = DEFAULTS;
    rankType rank = DEFAULTR;
    bool used = false;
};
struct deckType
{
    cardType cards[DECK_SIZE];
    int next = -1;
    int remain = DECK_SIZE;
};
struct pileType
{
    cardType cards[DECK_SIZE];
    int topCard = -1;
};

std::string printCard(cardType theCard);
std::string printASCIICard(cardType theCard);
std::string printASCIIPiles(pileType piles[], int numPiles);
void setUpDeck(deckType &theDeck, pileType foundations[], int numFoundations);

// Lecture Activity Explain what is happening on lines 103, 160, 232, 233
// put your explaination in a document and submit to the activity

int main()
{
    cardType c;
    c.suit = HEART;
    c.rank = A;
    std::cout << printCard(c) << std::endl;
    std::cout << printASCIICard(c) << std::endl;
    cardType d;
    d = c;
    suitType mySuit;
    rankType myRank;

    return 0;
}

std::string printCard(cardType theCard)
{
    std::string output; // A♥,  ♥A, or Ace of ♥
    output = rankStr[theCard.rank] + suitStr[theCard.suit];
    return output;
}

std::string printASCIICard(cardType theCard)
{
    std::ostringstream output;
    if (theCard.rank != DEFAULTR && theCard.suit != DEFAULTS)
    {
        output << "┌─────────┐ " << std::endl;
        output << std::setfill(' ') << std::left;
        output << "│ " << std::setw(8);
        output << rankStr[theCard.rank];
        output << "│ " << std::endl;
        output << "│" << std::setw(9) << " "
               << "│ " << std::endl;
        output << std::right;
        output << "│" << std::setw(7);
        output << suitStr[theCard.suit];
        output << std::setw(4) << " "
               << "│ " << std::endl;
        output << "│" << std::setw(9) << " "
               << "│ " << std::endl;
        output << "│" << std::setw(8);
        output << rankStr[theCard.rank];
        output << " │ " << std::endl;
        output << "└─────────┘ " << std::endl;
    }
    else
    {
        output << "┌─────────┐" << std::endl;
        output << "│░░░░░░░░░│" << std::endl;
        output << "│░░░░░░░░░│" << std::endl;
        output << "│░░░░░░░░░│" << std::endl;
        output << "│░░░░░░░░░│" << std::endl;
        output << "│░░░░░░░░░│" << std::endl;
        output << "└─────────┘" << std::endl;
    }

    return output.str();
}

std::string printASCIIPiles(pileType piles[], int numPiles)
{
    std::ostringstream output;
    for (int i = 0; i < numPiles; i++)
    {
        output << "  ┌─────────┐  ";
    }
    output << std::endl
           << " ";
    for (int i = 0; i < numPiles; i++)
    {
        output << std::setfill(' ') << std::left;
        output << " │ " << std::setw(8);
        if (piles[i].topCard > -1)
        {
            output << rankStr[piles[i].cards[piles[i].topCard].rank];
        }
        else
        {
            output << " ";
        }
        output << "│   ";
    }
    output << std::endl;
    for (int i = 0; i < numPiles; i++)
    {
        output << "  │" << std::setw(9) << " "
               << "│  ";
    }
    output << std::endl;
    for (int i = 0; i < numPiles; i++)
    {
        output << std::right;
        output << "  │";
        if (piles[i].topCard > -1)
        {
            output << std::setw(7);
            output << suitStr[piles[i].cards[piles[i].topCard].suit];
        }
        else
        {
            output << std::setw(5);
            output << " ";
        }
        output << std::setw(4) << " "
               << "│  ";
    }
    output << std::endl;
    for (int i = 0; i < numPiles; i++)
    {
        output << "  │" << std::setw(9) << " "
               << "│  ";
    }
    output << std::endl;
    for (int i = 0; i < numPiles; i++)
    {
        output << "  │" << std::setw(8);
        if (piles[i].topCard > -1)
        {
            output << rankStr[piles[i].cards[piles[i].topCard].rank];
        }
        else
        {
            output << " ";
        }
        output << " │  ";
    }
    output << std::endl;

    for (int i = 0; i < numPiles; i++)
    {
        output << i + 1 << " └─────────┘  ";
    }
    output << std::endl;
    return output.str();
}

void setUpDeck(deckType &theDeck, pileType foundations[], int numFoundations)
{
    for (int i = 0; i < NUM_SUITS - 1; i++)
    {
        for (int j = 0; j < NUM_RANKS - 1; j++)
        {
            cardType newCard;
            newCard.suit = suits[i];
            newCard.rank = ranks[j];
            newCard.used = false;
            theDeck.cards[i * (NUM_RANKS - 1) + j] = newCard;
            foundations[i].cards[j].rank = ranks[((i + 1) * (j + 1) - 1) % 13];
        }
        foundations[i].topCard = -1;
    }
}
