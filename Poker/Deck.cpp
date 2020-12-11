#include "Deck.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::ostream;
using std::vector;

const string Deck::RANKS[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
const string Deck::SUITS[4] = {"H","D","C","S"};

Deck::Deck() : size(0)
{
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Card t;
            t.setCard(RANKS[i] + SUITS[j]);
            cards.push_back(t);
            size++;
        }
    }

    shuffle();
}

Deck::~Deck() {}

void Deck::shuffle()
{
    size = MAX_SIZE;
    std::random_shuffle(&cards[0], &cards[MAX_SIZE-1]);
}

Card Deck::drawCard()
{
    if (size == 0)
    {
        std::cerr << "ERROR *** DECK EMPTY";
        Card card;
        return card;
    }

    size--;
    return cards[size];
}

ostream& operator<<(ostream &out, const Deck &aDeck)
{
    for (int i = aDeck.size-1; i >= 0; i--)
        out << aDeck.cards[i] << "\n";

    return out;
}