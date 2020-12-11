#ifndef DECK_H
#define DECK_H

#include "Card.h"

#include <ostream>
#include <string>
#include <vector>
using std::ostream;
using std::string;
using std::vector;

class Deck
{
private:
    static const int MAX_SIZE = 52;
    static const string RANKS[13];
    static const string SUITS[4];

    int size;
    vector<Card> cards;

public:
    Deck();
    ~Deck();
    Card drawCard();
    void shuffle();
    int getDeckSize() const {return size;}
    friend ostream& operator<<(ostream&, const Deck&);
};

#endif